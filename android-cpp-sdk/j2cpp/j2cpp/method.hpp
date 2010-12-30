#ifndef J2CPP_METHOD_HPP
#define J2CPP_METHOD_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/environment.hpp>
#include <j2cpp/jni_call_traits.hpp>
#include <j2cpp/get_method_id.hpp>

namespace j2cpp {

	template < typename Type >
	struct method { };
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type
	>
	typename jni_call_traits<Type>::return_type call_method(jobject jobj)
	{
		return method<Type>::call(jobj, get_method_id<Class,Name,Signature, false>(), 0);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0
	>
	typename jni_call_traits<Type>::return_type call_method(jobject jobj, A0 a0)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0))
		};
		return method<Type>::call(jobj, get_method_id<Class,Name,Signature, false>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1
	>
	typename jni_call_traits<Type>::return_type call_method(jobject jobj, A0 a0, A1 a1)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1))
		};
		return method<Type>::call(jobj, get_method_id<Class,Name,Signature, false>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2
	>
	typename jni_call_traits<Type>::return_type call_method(jobject jobj, A0 a0, A1 a1, A2 a2)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1)),
			jni_value(jni_argument_cast(a2))
		};
		return method<Type>::call(jobj, get_method_id<Class,Name,Signature, false>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2, typename A3
	>
	typename jni_call_traits<Type>::return_type call_method(jobject jobj, A0 a0, A1 a1, A2 a2, A3 a3)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1)),
			jni_value(jni_argument_cast(a2)),
			jni_value(jni_argument_cast(a3))
		};
		return method<Type>::call(jobj, get_method_id<Class,Name,Signature, false>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2, typename A3, typename A4
	>
	typename jni_call_traits<Type>::return_type call_method(jobject jobj, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1)),
			jni_value(jni_argument_cast(a2)),
			jni_value(jni_argument_cast(a3)),
			jni_value(jni_argument_cast(a4))
		};
		return method<Type>::call(jobj, get_method_id<Class,Name,Signature, false>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
	>
	typename jni_call_traits<Type>::return_type call_method(jobject jobj, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1)),
			jni_value(jni_argument_cast(a2)),
			jni_value(jni_argument_cast(a3)),
			jni_value(jni_argument_cast(a4)),
			jni_value(jni_argument_cast(a5))
		};
		return method<Type>::call(jobj, get_method_id<Class,Name,Signature, false>(), args);
	}

	template < typename ObjectType >
	struct method< local_ref<ObjectType> >
	{
		static inline
		typename jni_call_traits< local_ref<ObjectType> >::return_type
		call(jobject jobj, jmethodID m, jvalue *args)
		{
			return typename jni_call_traits< local_ref<ObjectType> >::return_type(
				environment::get().get_jenv()->CallObjectMethodA(jobj,m,args)
			);
		}
	};

	template < >
	struct method< jboolean >
	{
		static inline
		jboolean call(jobject jobj, jmethodID m, jvalue *args)
		{
			return environment::get().get_jenv()->CallBooleanMethodA(jobj,m,args);
		}
	};

	template < >
	struct method< jchar >
	{
		static inline
		jchar call(jobject jobj, jmethodID m, jvalue *args)
		{
			return environment::get().get_jenv()->CallCharMethodA(jobj,m,args);
		}
	};

	template < >
	struct method< jshort >
	{
		static inline
		jshort call(jobject jobj, jmethodID m, jvalue *args)
		{
			return environment::get().get_jenv()->CallShortMethodA(jobj,m,args);
		}
	};

	template < >
	struct method< jint >
	{
		static inline
		jint call(jobject jobj, jmethodID m, jvalue *args)
		{
			return environment::get().get_jenv()->CallIntMethodA(jobj,m,args);
		}
	};

	template < >
	struct method< jlong >
	{
		static inline
		jlong call(jobject jobj, jmethodID m, jvalue *args)
		{
			return environment::get().get_jenv()->CallLongMethodA(jobj,m,args);
		}
	};

	template < >
	struct method< jfloat >
	{
		static inline
		jfloat call(jobject jobj, jmethodID m, jvalue *args)
		{
			return environment::get().get_jenv()->CallFloatMethodA(jobj,m,args);
		}
	};

	template < >
	struct method< jdouble >
	{
		static inline
		jdouble call(jobject jobj, jmethodID m, jvalue *args)
		{
			return environment::get().get_jenv()->CallDoubleMethodA(jobj,m,args);
		}
	};

	template < >
	struct method< void >
	{
		static inline
		void call(jobject jobj, jmethodID m, jvalue *args)
		{
			environment::get().get_jenv()->CallVoidMethodA(jobj,m,args);
		}
	};

} //namespace j2cpp

#endif //J2CPP_METHOD_HPP
