#ifndef J2CPP_ARRAY_HPP
#define J2CPP_ARRAY_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/environment.hpp>
#include <j2cpp/object.hpp>
#include <j2cpp/local_ref.hpp>

namespace j2cpp {

	template < typename Type, int Dim > 
	class array
	{
	};
	
	
	template < typename Type >
	struct array_access
	{
	};
	
	template < typename ValueType > 
	class array<ValueType, 1>
	: public object< array<ValueType, 1> >
	{
	public:
		typedef ValueType 						value_type;
		typedef object< array<value_type,1> >	base_type;
		
		explicit array(jobject obj)
		: base_type(obj)
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=array_access<value_type>::get_array_elements(
				base_type::get_jobject(), m_is_copy
			);
		}
		
		array(jsize s)
		: base_type(array_access<value_type>::new_array(s))
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=array_access<value_type>::get_array_elements(
				base_type::get_jobject(), m_is_copy
			);
		}
		
		template < typename SomeValueType, jsize S >
		array(SomeValueType(&arr)[S])
		: base_type(array_access<value_type>::new_array(S*sizeof(SomeValueType)))
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=array_access<value_type>::get_array_elements(
				base_type::get_jobject(), m_is_copy
			);
			memcpy(m_data,arr,S*sizeof(SomeValueType));
		}
		
		~array()
		{
			array_access<value_type>::release_array_elements(
				base_type::get_jobject(), m_data, 0
			);
		}
		
		value_type* data()
		{
			return m_data;
		}
		
		jsize length() const
		{
			return array_access<value_type>::get_array_length(
				base_type::get_jobject()
			);
		}
		
		jsize size() const
		{
			return array_access<value_type>::get_array_size(
				base_type::get_jobject()
			);
		}

	private:
		jboolean	m_is_copy;
		value_type	*m_data;
	};
	
	
	template < typename ValueType > 
	class array< local_ref<ValueType>, 1>
	: public object< array< local_ref<ValueType>, 1> >
	{
	public:
		typedef local_ref<ValueType> 						value_type;
		typedef object< array< local_ref<ValueType>, 1> >	base_type;
		
		explicit array(jobject obj)
		: base_type(obj)
		{
		}
	};
	
	template <>
	struct array_access<jboolean>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jboolean);
		}

		static inline jboolean* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetBooleanArrayElements(
				reinterpret_cast<jbooleanArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewBooleanArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jboolean *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseBooleanArrayElements(
				reinterpret_cast<jbooleanArray>(jobj), data, mode
			);
		}
	};
	
	
	template <>
	struct array_access<jbyte>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jbyte);
		}

		static inline jbyte* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetByteArrayElements(
				reinterpret_cast<jbyteArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewByteArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jbyte *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseByteArrayElements(
				reinterpret_cast<jbyteArray>(jobj), data, mode
			);
		}
	};
	
	template <>
	struct array_access<jchar>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jchar);
		}

		static inline jchar* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetCharArrayElements(
				reinterpret_cast<jcharArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewCharArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jchar *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseCharArrayElements(
				reinterpret_cast<jcharArray>(jobj), data, mode
			);
		}
	};
	
	template <>
	struct array_access<jshort>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jshort);
		}

		static inline jshort* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetShortArrayElements(
				reinterpret_cast<jshortArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewShortArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jshort *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseShortArrayElements(
				reinterpret_cast<jshortArray>(jobj), data, mode
			);
		}
	};
	
	
	template <>
	struct array_access<jint>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jshort);
		}

		static inline jint* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetIntArrayElements(
				reinterpret_cast<jintArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewIntArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jint *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseIntArrayElements(
				reinterpret_cast<jintArray>(jobj), data, mode
			);
		}
	};
	
	
	template <>
	struct array_access<jlong>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jlong);
		}

		static inline jlong* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetLongArrayElements(
				reinterpret_cast<jlongArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewLongArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jlong *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseLongArrayElements(
				reinterpret_cast<jlongArray>(jobj), data, mode
			);
		}
	};
	
	template <>
	struct array_access<jfloat>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jfloat);
		}

		static inline jfloat* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetFloatArrayElements(
				reinterpret_cast<jfloatArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewFloatArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jfloat *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseFloatArrayElements(
				reinterpret_cast<jfloatArray>(jobj), data, mode
			);
		}
	};
	
	template <>
	struct array_access<jdouble>
	{
		static inline jsize get_array_length(jobject jobj)
		{
			return environment::get().get_jenv()->GetArrayLength(
				reinterpret_cast<jarray>(jobj)
			);
		}

		static inline jsize get_array_size(jobject jobj)
		{
			return get_array_length(jobj)*sizeof(jdouble);
		}

		static inline jdouble* get_array_elements(jobject jobj, jboolean &is_copy)
		{
			return environment::get().get_jenv()->GetDoubleArrayElements(
				reinterpret_cast<jdoubleArray>(jobj), &is_copy
			);
		}
		
		static inline jobject new_array(jsize s)
		{
			return environment::get().get_jenv()->NewDoubleArray(s);
		}
		
		static inline void release_array_elements(jobject jobj, jdouble *data, jint mode)
		{
			environment::get().get_jenv()->ReleaseDoubleArrayElements(
				reinterpret_cast<jdoubleArray>(jobj), data, mode
			);
		}
	};

} //namespace j2cpp

#endif //J2CPP_ARRAY_HPP
