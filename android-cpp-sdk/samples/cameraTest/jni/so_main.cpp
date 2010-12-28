#include <j2cpp/j2cpp.hpp>
#include <android/app/Activity.hpp>
#include <android/opengl/GLSurfaceView.hpp>
#include <javax/microedition/khronos/opengles/GL10.hpp>
#include <android/hardware/Camera.hpp>
#include <android/graphics/PixelFormat.hpp>
#define J2CPP_INCLUDE_IMPLEMENTATION
#include <android/app/Activity.hpp>
#include <android/opengl/GLSurfaceView.hpp>
#include <javax/microedition/khronos/opengles/GL10.hpp>
#include <android/hardware/Camera.hpp>
#include <android/graphics/PixelFormat.hpp>

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	if(!j2cpp::environment::get().init(vm))
		return JNI_ERR;
	return JNI_VERSION_1_6;
}
