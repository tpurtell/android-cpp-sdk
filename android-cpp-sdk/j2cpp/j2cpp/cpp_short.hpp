#ifndef J2CPP_CPP_SHORT_HPP
#define J2CPP_CPP_SHORT_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_short
	{
	public:
		cpp_short(): m_value(0) {}
		cpp_short(jshort v): m_value(v) {}
		operator jshort () const { return m_value; }
		jshort get_jtype() const { return m_value; }

		jshort m_value;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_SHORT_HPP
