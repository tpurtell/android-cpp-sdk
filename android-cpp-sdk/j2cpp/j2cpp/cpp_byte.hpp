#ifndef J2CPP_CPP_BYTE_HPP
#define J2CPP_CPP_BYTE_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_byte
	{
	public:
		cpp_byte(): m_value(0) {}
		cpp_byte(jbyte v): m_value(v) {}
		operator jbyte () const { return m_value; }
		jbyte get_jtype() const { return m_value; }

	protected:
		jbyte m_value;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_BYTE_HPP
