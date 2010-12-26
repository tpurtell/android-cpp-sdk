#ifndef J2CPP_CPP_LONG_HPP
#define J2CPP_CPP_LONG_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_long
	{
	public:
		cpp_long(): m_value(0) {}
		cpp_long(jlong v): m_value(v) {}
		operator jlong () const { return m_value; }
		jlong get_jtype() const { return m_value; }

		jlong m_value;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_LONG_HPP
