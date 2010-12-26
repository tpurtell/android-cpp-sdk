#ifndef J2CPP_CPP_BOOLEAN_ARRAY_HPP
#define J2CPP_CPP_BOOLEAN_ARRAY_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/environment.hpp>

namespace j2cpp {

	template <int Dim>
	class cpp_boolean_array
	: public cpp_object< cpp_boolean_array<Dim> >
	{
	public:
		cpp_boolean_array(jobject obj)
		: cpp_object< cpp_boolean_array<Dim> >(obj)
		{
		}
	};

} //namespace j2cpp

#endif //J2CPP_CPP_BOOLEAN_ARRAY_HPP
