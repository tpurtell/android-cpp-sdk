#ifndef J2CPP_CPP_INT_ARRAY_HPP
#define J2CPP_CPP_INT_ARRAY_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	template <int Dim>
	class cpp_int_array
	{

	};

	template <>
	class cpp_int_array<1>
	: public cpp_object< cpp_int_array<1> >
	{
	public:
		typedef cpp_object< cpp_int_array<1> > base_type;

		explicit cpp_int_array(jobject obj)
		: base_type(obj)
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=environment::get().get_jenv()->GetIntArrayElements(
				get_jint_array(),&m_is_copy
			);
		}

		cpp_int_array(jsize s)
		: base_type(environment::get().get_jenv()->NewIntArray(s))
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=environment::get().get_jenv()->GetIntArrayElements(
					get_jint_array(),&m_is_copy
			);
		}

		~cpp_int_array()
		{
			environment::get().get_jenv()->ReleaseIntArrayElements(
				get_jint_array(), m_data, 0
			);
		}

		jint* data()
		{
			return m_data;
		}

		jintArray get_jint_array() const
		{
			return reinterpret_cast<jintArray>(get_jtype());
		}

		jsize length() const
		{
			return environment::get().get_jenv()->GetArrayLength(
				get_jint_array()
			);
		}

		void set(jsize start, jsize len, jint const *data)
		{
			environment::get().get_jenv()->SetIntArrayRegion(
				get_jint_array(), start, len, data
			);
		}

		void get(jsize start, jsize len, jint *data)
		{
			environment::get().get_jenv()->GetIntArrayRegion(
				get_jint_array(), start, len, data
			);
		}

		jint& operator [](jsize idx)
		{
			return m_data[idx];
		}

	private:
		jboolean	m_is_copy;
		jint		*m_data;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_INT_ARRAY_HPP
