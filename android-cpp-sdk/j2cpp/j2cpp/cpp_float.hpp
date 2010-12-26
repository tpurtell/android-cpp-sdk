#ifndef J2CPP_FLOAT_HPP
#define J2CPP_FLOAT_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_float
	{
	public:
		cpp_float(): m_value(0.0) {}
		cpp_float(jfloat v): m_value(v) {}
		operator jfloat () const { return m_value; }
		jfloat get_jtype() const { return m_value; }

		jfloat m_value;
	};

} //namespace j2cpp


#endif //J2CPP_FLOAT_HPP
