#include <j2cpp/j2cpp.hpp>
#include "com_j2cpp_CameraTest.h"
#include <javax/microedition/khronos/opengles/GL10.hpp>

using namespace j2cpp;

void Java_com_j2cpp_CameraTest_handleOnResume(JNIEnv *env, jobject cameraTest)
{

}

void Java_com_j2cpp_CameraTest_handleOnPause(JNIEnv *env, jobject cameraTest)
{

}

void Java_com_j2cpp_CameraTest_handleOnDrawFrame(JNIEnv *env, jobject cameraTest, jobject gl)
{
	javax::microedition::khronos::opengles::GL10 gl10(gl);
	gl10.glClearColor(0.0,1.0,0.0,1.0);
	gl10.glClear(javax::microedition::khronos::opengles::GL10::GL_COLOR_BUFFER_BIT);
}

void Java_com_j2cpp_CameraTest_handleOnSurfaceChanged(JNIEnv *env, jobject cameraTest, jobject gl, jint width, jint height)
{

}

void Java_com_j2cpp_CameraTest_handleOnSurfaceCreated(JNIEnv *env, jobject cameraTest, jobject gl, jobject config)
{

}
