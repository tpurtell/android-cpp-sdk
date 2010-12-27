#include <j2cpp/j2cpp.hpp>
#include <java/lang/String.hpp>
#include <java/lang/Math.hpp>
#include <android/widget/TextView.hpp>
#define J2CPP_INCLUDE_IMPLEMENTATION
#include <java/lang/String.hpp>
#include <java/lang/Math.hpp>
#include <android/widget/TextView.hpp>


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv *jniEnv(0);
	if(JNI_OK!=vm->GetEnv((void **)&jniEnv, JNI_VERSION_1_6))
		return JNI_ERR;

	if(!jniEnv)
		return JNI_ERR;

	if(!j2cpp::environment::get().init(jniEnv))
		return JNI_ERR;


	return JNI_VERSION_1_6;
}
