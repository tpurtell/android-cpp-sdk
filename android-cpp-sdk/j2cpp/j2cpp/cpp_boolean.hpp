#ifndef J2CPP_CPP_BOOLEAN_HPP
#define J2CPP_CPP_BOOLEAN_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class cpp_boolean
	{
	public:
		cpp_boolean(): m_value(JNI_FALSE) {}
		cpp_boolean(jboolean v): m_value(v) {}
		operator jboolean () const { return m_value; }
		jboolean get_jtype() const { return m_value; }

	protected:
		jboolean m_value;
	};

} //namespace j2cpp

#endif //J2CPP_CPP_BOOLEAN_HPP
