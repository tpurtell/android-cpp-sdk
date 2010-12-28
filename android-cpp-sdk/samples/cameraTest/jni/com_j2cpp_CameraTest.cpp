#include <j2cpp/j2cpp.hpp>
#include "com_j2cpp_CameraTest.h"
#include <javax/microedition/khronos/opengles/GL10.hpp>
#include <android/graphics/PixelFormat.hpp>
#include "CameraTest.h"

using namespace j2cpp;

void convertNV16ToRGB(jbyte *pY, jbyte *pUV, int width, int height, jbyte *pRGB);


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
			cpp_int previewFormat=pCameraParameters->getPreviewFormat();
			local_ref<PixelFormat> previewPixelFormat=PixelFormat();
			PixelFormat::getPixelFormatInfo(previewFormat, previewPixelFormat);
			cpp_int previewBytesPerPixel=previewPixelFormat->bytesPerPixel;
			local_ref<Camera::Size> previewSize=pCameraParameters->getPreviewSize();
			cameraTestActivity.m_PreviewSize=previewSize;
			int bufferSize=3*cpp_int(previewSize->width).get_jtype()*cpp_int(previewSize->height).get_jtype();
			local_ref< cpp_byte_array<1> > previewBuffer=cpp_byte_array<1>(2*bufferSize);
			cameraTestActivity.m_Buffer=previewBuffer;
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
	using namespace javax::microedition::khronos::opengles;
	using namespace android::hardware;

	GL10 gl10(gl); CameraTest cameraTestActivity(cameraTest);
	gl10.glClear(GL10::GL_COLOR_BUFFER_BIT);

	local_ref<Camera::Size> previewSize=cameraTestActivity.m_PreviewSize;


	gl10.glBindTexture(GL10::GL_TEXTURE_2D, cameraTestActivity.m_TexId);
	gl10.glPixelStorex(GL10::GL_UNPACK_ALIGNMENT, 1);
	gl10.glTexImage2D(GL10::GL_TEXTURE_2D, 0, internalFormat(), previewSize->width, previewSize->height, 0, format(), type(), data());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void Java_com_j2cpp_CameraTest_handleOnSurfaceChanged(JNIEnv *env, jobject cameraTest, jobject gl, jint width, jint height)
{
	using namespace javax::microedition::khronos::opengles;
	GL10 gl10(gl);
	gl10.glViewport(0, 0, width, height);

	gl10.glMatrixMode(GL10::GL_PROJECTION);
	gl10.glLoadIdentity();
	gl10.glOrthof(-1.0f,1.0f,-1.0f,1.0f,1.0f,10.0f);
}

void Java_com_j2cpp_CameraTest_handleOnSurfaceCreated(JNIEnv *env, jobject cameraTest, jobject gl, jobject config)
{
	using namespace javax::microedition::khronos::opengles;

	GL10 gl10(gl); CameraTest cameraTestActivity(cameraTest);
	gl10.glClearColor(0.2,0.2,0.2,1.0);

	local_ref< cpp_int_array<1> > genTex(jsize(1));

	gl10.glGenTextures(1, genTex, 0);

	cameraTestActivity.m_TexId=genTex->data()[0];

	gl10.glBindTexture(GL10::GL_TEXTURE_2D, cameraTestActivity.m_TexId);
	gl10.glPixelStorei(GL10::GL_UNPACK_ALIGNMENT, 1);
	gl10.glTexParameterx(GL10::GL_TEXTURE_2D, GL10::GL_TEXTURE_WRAP_S, GL10::GL_REPEAT);
	gl10.glTexParameterx(GL10::GL_TEXTURE_2D, GL10::GL_TEXTURE_WRAP_T, GL10::GL_REPEAT);
	gl10.glTexParameterx(GL10::GL_TEXTURE_2D, GL10::GL_TEXTURE_MAG_FILTER, GL10::GL_LINEAR);
	gl10.glTexParameterx(GL10::GL_TEXTURE_2D, GL10::GL_TEXTURE_MIN_FILTER, GL10::GL_LINEAR);
}

void Java_com_j2cpp_CameraTest_handleOnPreviewFrame(JNIEnv *env, jobject cameraTest, jbyteArray data, jobject camera)
{
	using namespace android::graphics;
	using namespace android::hardware;

	CameraTest cameraTestActivity(cameraTest);
	Camera theCamera(camera);

	cpp_byte_array<1> previewData(data);
	local_ref< cpp_byte_array<1> > buffer=cameraTestActivity.m_Buffer;

	jsize previewSize=previewData.length();
	jsize bufferSize=buffer->length();
	local_ref<Camera::Parameters> pCameraParameters=theCamera.getParameters();
	cpp_int previewFormat=pCameraParameters->getPreviewFormat();
	local_ref<PixelFormat> previewPixelFormat=PixelFormat();
	PixelFormat::getPixelFormatInfo(previewFormat, previewPixelFormat);
	cpp_int previewBytesPerPixel=previewPixelFormat->bytesPerPixel;
	local_ref<Camera::Size> previewFrameSize=pCameraParameters->getPreviewSize();
	int width=cpp_int(previewFrameSize->width).get_jtype();
	int height=cpp_int(previewFrameSize->height).get_jtype();

	convertNV16ToRGB(previewData.data(), previewData.data()+width*height,width,height,buffer->data());


	//__android_log_print(ANDROID_LOG_FATAL, J2CPP_NAME, "Java_com_j2cpp_CameraTest_handleOnPreviewFrame: size=(%d,%d), bytesPerPixel=%d, data.length()=%d",
	//		cpp_int(previewFrameSize->width).get_jtype(),
	//		cpp_int(previewFrameSize->height).get_jtype(),
	//		previewBytesPerPixel.get_jtype(),
	//		previewSize
	//);
}

#define min_(a,b) (a<b?a:b)
#define max_(a,b) (a>b?a:b)


void convertNV16ToRGB(jbyte *pY, jbyte *pUV, int width, int height, jbyte *pRGB)
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			int nY=*(pY+i*width+j);
			int nV=*(pUV+(i/2)*width+2*(j/2));
			int nU=*(pUV+(i/2)*width+2*(j/2)+1);

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

			*pRGB++=(unsigned char)nR;
			*pRGB++=(unsigned char)nG;
			*pRGB++=(unsigned char)nB;
		}
	}
}
