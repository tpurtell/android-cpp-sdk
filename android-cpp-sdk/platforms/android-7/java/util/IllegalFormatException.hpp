/*================================================================================
  code generated by: java2cpp
  class: java.util.IllegalFormatException
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_UTIL_ILLEGALFORMATEXCEPTION_HPP_DECL
#define J2CPP_JAVA_UTIL_ILLEGALFORMATEXCEPTION_HPP_DECL






namespace j2cpp {

namespace java { namespace util {

	class IllegalFormatException;
	class IllegalFormatException
		: public cpp_object<IllegalFormatException>
	{
	public:

		J2CPP_DECLARE_CLASS

		J2CPP_DECLARE_METHOD(0)

		IllegalFormatException(jobject jobj)
		: cpp_object<IllegalFormatException>(jobj)
		{
		}

	}; //class IllegalFormatException

} //namespace util
} //namespace java


} //namespace j2cpp

#endif //J2CPP_JAVA_UTIL_ILLEGALFORMATEXCEPTION_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_UTIL_ILLEGALFORMATEXCEPTION_HPP_IMPL
#define J2CPP_JAVA_UTIL_ILLEGALFORMATEXCEPTION_HPP_IMPL

namespace j2cpp {


template <>
local_ref< java::util::IllegalFormatException > create< java::util::IllegalFormatException>()
{
	return local_ref< java::util::IllegalFormatException >(
		environment::get().get_jenv()->NewObject(
			get_class<java::util::IllegalFormatException::J2CPP_CLASS_NAME>(),
			get_method_id<java::util::IllegalFormatException::J2CPP_CLASS_NAME, java::util::IllegalFormatException::J2CPP_METHOD_NAME(0), java::util::IllegalFormatException::J2CPP_METHOD_SIGNATURE(0), false>()
		)
	);
}


J2CPP_DEFINE_CLASS(java::util::IllegalFormatException,"java/util/IllegalFormatException")
J2CPP_DEFINE_METHOD(java::util::IllegalFormatException,0,"<init>","()V")

} //namespace j2cpp

#endif //J2CPP_JAVA_UTIL_ILLEGALFORMATEXCEPTION_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION