#ifndef J2CPP_CPP_OBJECT_ARRAY_H
#define J2CPP_CPP_OBJECT_ARRAY_H

#include <j2cpp/config.hpp>

namespace j2cpp {

	template < typename Object, int Dim >
	class cpp_object_array
	: public cpp_object< cpp_object_array<Object, Dim> >
	{
	public:
		typedef cpp_object< cpp_object_array<Object, Dim> > base_type;
		cpp_object_array(jobject jobj): base_type(jobj) {}
	};

} //namespace j2cpp

#endif //J2CPP_CPP_OBJECT_ARRAY_H
