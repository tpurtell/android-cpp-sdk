#include <j2cpp/j2cpp.hpp>
#include <j2cpp/raw_environment.hpp>

#include <java/lang/String.hpp>
#include <java/lang/Math.hpp>
#include <android/widget/TextView.hpp>
#define J2CPP_INCLUDE_IMPLEMENTATION
#include <java/lang/String.hpp>
#include <java/lang/Math.hpp>
#include <android/widget/TextView.hpp>


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	j2cpp::shared_ptr<j2cpp::raw_environment> raw_env(new j2cpp::raw_environment(vm));
	if(j2cpp::environment::init(raw_env))
		return JNI_VERSION_1_4;

	return JNI_ERR;
}
