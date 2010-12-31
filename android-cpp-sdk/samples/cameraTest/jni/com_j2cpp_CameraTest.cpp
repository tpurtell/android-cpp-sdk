#include <j2cpp/j2cpp.hpp>
#include "com_j2cpp_CameraTest.h"
#include <android/graphics/PixelFormat.hpp>
#include <java/util/List.hpp>
#include <java/util/ListIterator.hpp>
#include <java/lang/Integer.hpp>
#include "CameraTest.h"

#include <GLES/gl.h>

using namespace j2cpp;

void convertNV16ToRGB(jbyte *pY, jbyte *pUV, int srcWidth, int srcHeight, jbyte *pRGB, int dstWidth, int dstHeight);

int power_of_two(int value)
{
	int retValue(1);
	while(value) { retValue<<=1; value>>=1; }
	return retValue;
}

void Java_com_j2cpp_CameraTest_handleOnResume(JNIEnv *env, jobject cameraTest)
{
	using namespace android::graphics;
	using namespace android::hardware;


	CameraTest cameraTestActivity(cameraTest);
	local_ref<Camera> pCamera=cameraTestActivity.m_Camera;
	if(!pCamera)
	{
		pCamera=Camera::open();
		if(pCamera)
		{
			cameraTestActivity.m_Camera=pCamera;
			local_ref<Camera::Parameters> pCameraParameters=pCamera->getParameters();


			int previewFormat=pCameraParameters->getPreviewFormat();
			local_ref<PixelFormat> previewPixelFormat=PixelFormat();
			PixelFormat::getPixelFormatInfo(previewFormat, previewPixelFormat);
			int previewBytesPerPixel=previewPixelFormat->bytesPerPixel;
			local_ref<Camera::Size> previewSize=pCameraParameters->getPreviewSize();
			int textureWidth=power_of_two(previewSize->width);
			int textureHeight=power_of_two(previewSize->height);
			cameraTestActivity.m_TextureWidth=textureWidth;
			cameraTestActivity.m_TextureHeight=textureHeight;
			local_ref< array<jbyte, 1> > textureBuffer=array<jbyte, 1>(3*textureWidth*textureHeight);
			cameraTestActivity.m_TextureBuffer=textureBuffer;
			pCamera->setPreviewCallback(cameraTestActivity);
			pCamera->startPreview();
		}
	}
}

void Java_com_j2cpp_CameraTest_handleOnPause(JNIEnv *env, jobject cameraTest)
{
}

void Java_com_j2cpp_CameraTest_handleOnDrawFrame(JNIEnv *env, jobject cameraTest, jobject gl)
{
	using namespace android::hardware;
	static const int one=0x10000;

	CameraTest cameraTestActivity(cameraTest);

	int verticesBuffer[]=
	{
		-one,	-one,	0,
		one,	-one,	0,
		one,	one,	0,
		-one,	-one,	0,
		one,	one,	0,
		-one,	one,	0
	};

	int verticesUVBuffer[]=
	{
		0,		one,
		one,	one,
		one,	0,
		0,		one,
		one,	0,
		0,		0
	};

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDisable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glDisable(GL_BLEND);

	glEnableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, cameraTestActivity.m_TexId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	if(cameraTestActivity.m_TexIsDirty)
	{
		local_ref< array<jbyte, 1> > textureBuffer=cameraTestActivity.m_TextureBuffer;
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, cameraTestActivity.m_TextureWidth, cameraTestActivity.m_TextureHeight, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer->data());
		cameraTestActivity.m_TexIsDirty=JNI_FALSE;
	}

	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatex(0, 0, -one*5);
	glColor4x(one, one, one, one);

	glVertexPointer(3, GL_FIXED, 0, verticesBuffer);
	glTexCoordPointer(2, GL_FIXED, 0, verticesUVBuffer);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glFlush();
}

void Java_com_j2cpp_CameraTest_handleOnSurfaceChanged(JNIEnv *env, jobject cameraTest, jobject gl, jint width, jint height)
{
	static const jint one=0x10000;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrthox(-one,one,-one,one,one,one*10);
}

void Java_com_j2cpp_CameraTest_handleOnSurfaceCreated(JNIEnv *env, jobject cameraTest, jobject gl, jobject config)
{
	static const jint one=0x10000;

	CameraTest cameraTestActivity(cameraTest);
	glClearColorx(one,0,0,one);

	GLuint genTex;
	glGenTextures(1, &genTex);
	cameraTestActivity.m_TexId=genTex;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, genTex);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	local_ref< array<jbyte, 1> > textureBuffer=cameraTestActivity.m_TextureBuffer;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, cameraTestActivity.m_TextureWidth, cameraTestActivity.m_TextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer->data());
}

void Java_com_j2cpp_CameraTest_handleOnPreviewFrame(JNIEnv *env, jobject cameraTest, jbyteArray data, jobject camera)
{
	using namespace android::graphics;
	using namespace android::hardware;

	CameraTest cameraTestActivity(cameraTest);
	Camera theCamera(camera);

	array<jbyte, 1> previewData(data);
	local_ref< array<jbyte, 1> > textureBuffer=cameraTestActivity.m_TextureBuffer;

	jsize previewSize=previewData.length();

	local_ref<Camera::Parameters> pCameraParameters=theCamera.getParameters();
	int previewFormat=pCameraParameters->getPreviewFormat();
	local_ref<PixelFormat> previewPixelFormat=PixelFormat();
	PixelFormat::getPixelFormatInfo(previewFormat, previewPixelFormat);
	int previewBytesPerPixel=previewPixelFormat->bytesPerPixel;
	local_ref<Camera::Size> previewFrameSize=pCameraParameters->getPreviewSize();

	int previewWidth=previewFrameSize->width;
	int previewHeight=previewFrameSize->height;

	int textureWidth=cameraTestActivity.m_TextureWidth;
	int textureHeight=cameraTestActivity.m_TextureHeight;

	convertNV16ToRGB(previewData.data(), previewData.data()+previewWidth*previewHeight, previewWidth, previewHeight, textureBuffer->data(), textureWidth, textureHeight);

	cameraTestActivity.m_TexIsDirty=JNI_TRUE;
}

#define min_(a,b) (a<b?a:b)
#define max_(a,b) (a>b?a:b)


void convertNV16ToRGB(jbyte *pY, jbyte *pUV, int srcWidth, int srcHeight, jbyte *pRGB, int dstWidth, int dstHeight)
{
	unsigned char *puY=reinterpret_cast<unsigned char *>(pY);
	unsigned char *puUV=reinterpret_cast<unsigned char *>(pUV);

	for(int i=0;i<srcHeight;i++)
	{
		for(int j=0;j<srcWidth;j++)
		{
			int nY=*(puY+i*srcWidth+j);
			int nV=*(puUV+(i/2)*srcWidth+2*(j/2));
			int nU=*(puUV+(i/2)*srcWidth+2*(j/2)+1);

			nY-=16;
			nU-=128;
			nV-=128;

			if(nY<0) nY = 0;

			int nB=(int)(1192*nY+2066*nU);
			int nG=(int)(1192*nY-833*nV-400*nU);
			int nR=(int)(1192*nY+1634*nV);

			nR=min_(262143,max_(0,nR));
			nG=min_(262143,max_(0,nG));
			nB=min_(262143,max_(0,nB));


			nR>>=10; nR&=0xff;
			nG>>=10; nG&=0xff;
			nB>>=10; nB&=0xff;

			pRGB[i*dstWidth*3+j*3+0]=nR;
			pRGB[i*dstWidth*3+j*3+1]=nG;
			pRGB[i*dstWidth*3+j*3+2]=nB;
		}
	}
}
