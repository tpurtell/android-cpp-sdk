#ifndef J2CPP_STATIC_METHOD_HPP
#define J2CPP_STATIC_METHOD_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/environment.hpp>
#include <j2cpp/jni_call_traits.hpp>
#include <j2cpp/get_method_id.hpp>
#include <j2cpp/get_class.hpp>

namespace j2cpp {

	template < typename Type >
	struct static_method { };

	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type
	>
	typename jni_call_traits<Type>::return_type call_static_method()
	{
		return static_method<Type>::call(get_class<Class>(), get_method_id<Class,Name,Signature, true>(), 0);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0
	>
	typename jni_call_traits<Type>::return_type call_static_method(A0 a0)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0))
		};
		return static_method<Type>::call(get_class<Class>(), get_method_id<Class,Name,Signature, true>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1 
	>
	typename jni_call_traits<Type>::return_type call_static_method(A0 a0, A1 a1)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1))
		};
		return static_method<Type>::call(get_class<Class>(), get_method_id<Class,Name,Signature, true>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2 
	>
	typename jni_call_traits<Type>::return_type call_static_method(A0 a0, A1 a1, A2 a2)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1)),
			jni_value(jni_argument_cast(a2))
		};
		return static_method<Type>::call(get_class<Class>(), get_method_id<Class,Name,Signature, true>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2, typename A3 
	>
	typename jni_call_traits<Type>::return_type call_static_method(A0 a0, A1 a1, A2 a2, A3 a3)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1)),
			jni_value(jni_argument_cast(a2)),
			jni_value(jni_argument_cast(a3))
		};
		return static_method<Type>::call(get_class<Class>(), get_method_id<Class,Name,Signature, true>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2, typename A3, typename A4 
	>
	typename jni_call_traits<Type>::return_type call_static_method(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4)
	{
		jvalue args[]=
		{
			jni_value(jni_argument_cast(a0)),
			jni_value(jni_argument_cast(a1)),
			jni_value(jni_argument_cast(a2)),
			jni_value(jni_argument_cast(a3)),
			jni_value(jni_argument_cast(a4))
		};
		return static_method<Type>::call(get_class<Class>(), get_method_id<Class,Name,Signature, true>(), args);
	}
	
	template
	<
		const char *Class, const char *Name, const char *Signature, typename Type,
		typename A0, typename A1, typename A2, typename A3, typename A4, typename A5 
	>
	typename jni_call_traits<Type>::return_type call_static_method(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
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
		return static_method<Type>::call(get_class<Class>(), get_method_id<Class,Name,Signature, true>(), args);
	}

	template < typename ObjectType >
	struct static_method< local_ref<ObjectType> >
	{
		static inline
		typename jni_call_traits< local_ref<ObjectType> >::return_type
		call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return typename jni_call_traits< local_ref<ObjectType> >::return_type(
				environment::get().get_jenv()->CallStaticObjectMethodA(jclazz,sm,args)
			);
		}
	};

	template < >
	struct static_method< jboolean >
	{
		static inline
		jboolean call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return environment::get().get_jenv()->CallStaticBooleanMethodA(jclazz,sm,args);
		}
	};

	template < >
	struct static_method< jchar >
	{
		static inline
		jchar call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return environment::get().get_jenv()->CallStaticCharMethodA(jclazz,sm,args);
		}
	};

	template < >
	struct static_method< jshort >
	{
		static inline
		jshort call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return environment::get().get_jenv()->CallStaticShortMethodA(jclazz,sm,args);
		}
	};

	template < >
	struct static_method< jint >
	{
		static inline
		jint call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return environment::get().get_jenv()->CallStaticIntMethodA(jclazz,sm,args);
		}
	};

	template < >
	struct static_method< jlong >
	{
		static inline
		jlong call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return environment::get().get_jenv()->CallStaticLongMethodA(jclazz,sm,args);
		}
	};

	template < >
	struct static_method< jfloat >
	{
		static inline
		jfloat call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return environment::get().get_jenv()->CallStaticFloatMethodA(jclazz,sm,args);
		}
	};

	template < >
	struct static_method< jdouble >
	{
		static inline
		jdouble call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			return environment::get().get_jenv()->CallStaticDoubleMethodA(jclazz,sm,args);
		}
	};

	template < >
	struct static_method< void >
	{
		static inline
		void call(jclass jclazz, jmethodID sm, jvalue *args)
		{
			environment::get().get_jenv()->CallStaticDoubleMethodA(jclazz,sm,args);
		}
	};


} //namespace j2cpp


#endif //J2CPP_STATIC_METHOD_HPP
