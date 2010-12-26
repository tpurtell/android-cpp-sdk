#ifndef J2CPP_CPP_LONG_ARRAY_HPP
#define J2CPP_CPP_LONG_ARRAY_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	template <int Dim>
	class cpp_long_array
	: public cpp_object< cpp_long_array<Dim> >
	{
	public:
		typedef cpp_object< cpp_long_array<Dim> > base_type;
		cpp_long_array(jobject obj): base_type(obj) {}
	};

} //namespace j2cpp

#endif //J2CPP_CPP_LONG_ARRAY_HPP
