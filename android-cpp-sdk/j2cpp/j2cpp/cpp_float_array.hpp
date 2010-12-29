#ifndef J2CPP_CPP_FLOAT_ARRAY_HPP
#define J2CPP_CPP_FLOAT_ARRAY_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	template <int Dim>
	class cpp_float_array
	{

	};

	template <>
	class cpp_float_array<1>
	: public cpp_object< cpp_float_array<1> >
	{
	public:
		typedef cpp_object< cpp_float_array<1> > base_type;

		explicit cpp_float_array(jobject obj)
		: base_type(obj)
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=environment::get().get_jenv()->GetFloatArrayElements(
				get_jfloat_array(),&m_is_copy
			);
		}

		cpp_float_array(jsize s)
		: base_type(environment::get().get_jenv()->NewFloatArray(s))
		, m_is_copy(JNI_FALSE)
		, m_data(0)
		{
			m_data=environment::get().get_jenv()->GetFloatArrayElements(
				get_jfloat_array(),&m_is_copy
			);
		}

		~cpp_float_array()
		{
			environment::get().get_jenv()->ReleaseFloatArrayElements(
				get_jfloat_array(), m_data, 0
			);
		}

		jfloat* data()
		{
			return m_data;
		}

		jfloatArray get_jfloat_array() const
		{
			return reinterpret_cast<jfloatArray>(get_jtype());
		}

		jsize length() const
		{
			return environment::get().get_jenv()->GetArrayLength(
				get_jfloat_array()
			);
		}

		void set(jsize start, jsize len, jfloat const *data)
		{
			environment::get().get_jenv()->SetFloatArrayRegion(
				get_jfloat_array(), start, len, data
			);
		}

		void get(jsize start, jsize len, jfloat *data)
		{
			environment::get().get_jenv()->GetFloatArrayRegion(
				get_jfloat_array(), start, len, data
			);
		}

		jfloat& operator [](jsize idx)
		{
			return m_data[idx];
		}

	private:
		jboolean	m_is_copy;
		jfloat		*m_data;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_FLOAT_ARRAY_HPP
