#ifndef J2CPP_CPP_BYTE_ARRAY_HPP
#define J2CPP_CPP_BYTE_ARRAY_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/environment.hpp>
#include <j2cpp/local_ref.hpp>

namespace j2cpp {

	template <int Dim>
	class cpp_byte_array
	{

	};

	template <>
	class cpp_byte_array<1>
	: public cpp_object< cpp_byte_array<1> >
	{
	public:
		typedef cpp_object< cpp_byte_array<1> > base_type;
		explicit cpp_byte_array(jobject obj)
		: base_type(obj)
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=environment::get().get_jenv()->GetByteArrayElements(
				get_jbyte_array(),&m_is_copy
			);
		}

		cpp_byte_array(jsize s)
		: base_type(environment::get().get_jenv()->NewByteArray(s))
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=environment::get().get_jenv()->GetByteArrayElements(
				get_jbyte_array(),&m_is_copy
			);
		}

		~cpp_byte_array()
		{
			environment::get().get_jenv()->ReleaseByteArrayElements(
				get_jbyte_array(), m_data, 0
			);
		}

		jbyte* data()
		{
			return m_data;
		}

		jbyteArray get_jbyte_array() const
		{
			return reinterpret_cast<jbyteArray>(get_jtype());
		}

		jsize length() const
		{
			return environment::get().get_jenv()->GetArrayLength(
				get_jbyte_array()
			);
		}

		void set(jsize start, jsize len, jbyte const *data)
		{
			environment::get().get_jenv()->SetByteArrayRegion(
				get_jbyte_array(), start, len, data
			);
		}

		void get(jsize start, jsize len, jbyte *data)
		{
			environment::get().get_jenv()->GetByteArrayRegion(
				get_jbyte_array(), start, len, data
			);
		}

		jbyte& operator [](jsize idx)
		{
			return m_data[idx];
		}

	private:
		jboolean	m_is_copy;
		jbyte		*m_data;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_BYTE_ARRAY_HPP
