#ifndef J2CPP_CPP_DOUBLE_HPP
#define J2CPP_CPP_DOUBLE_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_double
	{
	public:
		cpp_double(): m_value(0.0) {}
		cpp_double(jdouble v): m_value(v) {}
		operator jdouble () const { return m_value; }
		jdouble get_jtype() const { return m_value; }

	protected:
		jdouble m_value;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_DOUBLE_HPP
