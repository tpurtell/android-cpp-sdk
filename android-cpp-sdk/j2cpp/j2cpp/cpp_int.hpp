#ifndef J2CPP_CPP_INT_HPP
#define J2CPP_CPP_INT_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_int
	{
	public:
		cpp_int(): m_value(0) {}
		cpp_int(jint v): m_value(v) {}
		operator jint () const { return m_value; }
		jint get_jtype() const { return m_value; }

		jint m_value;
	};
	
} //namespace j2cpp

#endif //J2CPP_CPP_INT_HPP
