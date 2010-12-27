/*================================================================================
  code generated by: java2cpp
  class: android.os.HandlerThread
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ANDROID_OS_HANDLERTHREAD_HPP_DECL
#define J2CPP_ANDROID_OS_HANDLERTHREAD_HPP_DECL


namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace android { namespace os { class Looper; } } }


#include <android/os/Looper.hpp>
#include <java/lang/String.hpp>


namespace j2cpp {

namespace android { namespace os {

	class HandlerThread;
	class HandlerThread
		: public cpp_object<HandlerThread>
	{
	public:

		J2CPP_DECLARE_CLASS

		J2CPP_DECLARE_METHOD(0)
		J2CPP_DECLARE_METHOD(1)
		J2CPP_DECLARE_METHOD(2)
		J2CPP_DECLARE_METHOD(3)
		J2CPP_DECLARE_METHOD(4)
		J2CPP_DECLARE_METHOD(5)
		J2CPP_DECLARE_METHOD(6)

		HandlerThread(jobject jobj)
		: cpp_object<HandlerThread>(jobj)
		{
		}

		void run();
		local_ref< android::os::Looper > getLooper();
		cpp_boolean quit();
		cpp_int getThreadId();
	}; //class HandlerThread

} //namespace os
} //namespace android


} //namespace j2cpp

#endif //J2CPP_ANDROID_OS_HANDLERTHREAD_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ANDROID_OS_HANDLERTHREAD_HPP_IMPL
#define J2CPP_ANDROID_OS_HANDLERTHREAD_HPP_IMPL

namespace j2cpp {


template <>
local_ref< android::os::HandlerThread > create< android::os::HandlerThread>(local_ref< java::lang::String > const &a0)
{
	return local_ref< android::os::HandlerThread >(
		environment::get().get_jenv()->NewObject(
			get_class<android::os::HandlerThread::J2CPP_CLASS_NAME>(),
			get_method_id<android::os::HandlerThread::J2CPP_CLASS_NAME, android::os::HandlerThread::J2CPP_METHOD_NAME(0), android::os::HandlerThread::J2CPP_METHOD_SIGNATURE(0), false>(),
			a0.get_jtype()
		)
	);
}

template <>
local_ref< android::os::HandlerThread > create< android::os::HandlerThread>(local_ref< java::lang::String > const &a0, cpp_int const &a1)
{
	return local_ref< android::os::HandlerThread >(
		environment::get().get_jenv()->NewObject(
			get_class<android::os::HandlerThread::J2CPP_CLASS_NAME>(),
			get_method_id<android::os::HandlerThread::J2CPP_CLASS_NAME, android::os::HandlerThread::J2CPP_METHOD_NAME(1), android::os::HandlerThread::J2CPP_METHOD_SIGNATURE(1), false>(),
			a0.get_jtype(), a1.get_jtype()
		)
	);
}


void android::os::HandlerThread::run()
{
	return void(
		environment::get().get_jenv()->CallVoidMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(3), J2CPP_METHOD_SIGNATURE(3), false>()
		)
	);
}

local_ref< android::os::Looper > android::os::HandlerThread::getLooper()
{
	return local_ref< android::os::Looper >(
		environment::get().get_jenv()->CallObjectMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(4), J2CPP_METHOD_SIGNATURE(4), false>()
		)
	);
}

cpp_boolean android::os::HandlerThread::quit()
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(5), J2CPP_METHOD_SIGNATURE(5), false>()
		)
	);
}

cpp_int android::os::HandlerThread::getThreadId()
{
	return cpp_int(
		environment::get().get_jenv()->CallIntMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(6), J2CPP_METHOD_SIGNATURE(6), false>()
		)
	);
}


J2CPP_DEFINE_CLASS(android::os::HandlerThread,"android/os/HandlerThread")
J2CPP_DEFINE_METHOD(android::os::HandlerThread,0,"<init>","(Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(android::os::HandlerThread,1,"<init>","(Ljava/lang/String;I)V")
J2CPP_DEFINE_METHOD(android::os::HandlerThread,2,"onLooperPrepared","()V")
J2CPP_DEFINE_METHOD(android::os::HandlerThread,3,"run","()V")
J2CPP_DEFINE_METHOD(android::os::HandlerThread,4,"getLooper","()Landroid/os/Looper;")
J2CPP_DEFINE_METHOD(android::os::HandlerThread,5,"quit","()Z")
J2CPP_DEFINE_METHOD(android::os::HandlerThread,6,"getThreadId","()I")

} //namespace j2cpp

#endif //J2CPP_ANDROID_OS_HANDLERTHREAD_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION