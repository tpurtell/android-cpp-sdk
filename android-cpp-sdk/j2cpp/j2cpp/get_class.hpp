#ifndef J2CPP_GET_CLASS_HPP
#define J2CPP_GET_CLASS_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/environment.hpp>
#include <j2cpp/jobject_global_ref.hpp>

namespace j2cpp {

	template < const char *ClassName >
	static jclass get_class()
	{
		static jobject_global_ref<jclass> clazz(environment::get().get_jenv()->FindClass(ClassName));
		return clazz;
	}

} //namespace j2cpp

#endif //J2CPP_GET_CLASS_HPP
