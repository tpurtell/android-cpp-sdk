#ifndef J2CPP_CPP_CHAR_HPP
#define J2CPP_CPP_CHAR_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_char
	{
	public:
		cpp_char(): m_value(0) {}
		cpp_char(jchar v): m_value(v) {}
		operator jchar () const { return m_value; }
		jchar get_jtype() const { return m_value; }

	protected:
		jchar m_value;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_CHAR_HPP
