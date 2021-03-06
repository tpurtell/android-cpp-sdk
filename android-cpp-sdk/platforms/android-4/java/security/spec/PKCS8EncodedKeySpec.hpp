/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: java.security.spec.PKCS8EncodedKeySpec
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_SECURITY_SPEC_PKCS8ENCODEDKEYSPEC_HPP_DECL
#define J2CPP_JAVA_SECURITY_SPEC_PKCS8ENCODEDKEYSPEC_HPP_DECL


namespace j2cpp { namespace java { namespace security { namespace spec { class KeySpec; } } } }
namespace j2cpp { namespace java { namespace security { namespace spec { class EncodedKeySpec; } } } }
namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace java { namespace lang { class Object; } } }


#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/security/spec/EncodedKeySpec.hpp>
#include <java/security/spec/KeySpec.hpp>


namespace j2cpp {

namespace java { namespace security { namespace spec {

	class PKCS8EncodedKeySpec;
	class PKCS8EncodedKeySpec
		: public object<PKCS8EncodedKeySpec>
	{
	public:

		J2CPP_DECLARE_CLASS

		J2CPP_DECLARE_METHOD(0)
		J2CPP_DECLARE_METHOD(1)
		J2CPP_DECLARE_METHOD(2)

		explicit PKCS8EncodedKeySpec(jobject jobj)
		: object<PKCS8EncodedKeySpec>(jobj)
		{
		}

		operator local_ref<java::security::spec::KeySpec>() const;
		operator local_ref<java::security::spec::EncodedKeySpec>() const;
		operator local_ref<java::lang::Object>() const;


		PKCS8EncodedKeySpec(local_ref< array<jbyte,1> > const&);
		local_ref< array<jbyte,1> > getEncoded();
		local_ref< java::lang::String > getFormat();
	}; //class PKCS8EncodedKeySpec

} //namespace spec
} //namespace security
} //namespace java

} //namespace j2cpp

#endif //J2CPP_JAVA_SECURITY_SPEC_PKCS8ENCODEDKEYSPEC_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_SECURITY_SPEC_PKCS8ENCODEDKEYSPEC_HPP_IMPL
#define J2CPP_JAVA_SECURITY_SPEC_PKCS8ENCODEDKEYSPEC_HPP_IMPL

namespace j2cpp {



java::security::spec::PKCS8EncodedKeySpec::operator local_ref<java::security::spec::KeySpec>() const
{
	return local_ref<java::security::spec::KeySpec>(get_jobject());
}

java::security::spec::PKCS8EncodedKeySpec::operator local_ref<java::security::spec::EncodedKeySpec>() const
{
	return local_ref<java::security::spec::EncodedKeySpec>(get_jobject());
}

java::security::spec::PKCS8EncodedKeySpec::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}


java::security::spec::PKCS8EncodedKeySpec::PKCS8EncodedKeySpec(local_ref< array<jbyte,1> > const &a0)
: object<java::security::spec::PKCS8EncodedKeySpec>(
	call_new_object<
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_CLASS_NAME,
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_METHOD_NAME(0),
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_METHOD_SIGNATURE(0)
	>(a0)
)
{
}


local_ref< array<jbyte,1> > java::security::spec::PKCS8EncodedKeySpec::getEncoded()
{
	return call_method<
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_CLASS_NAME,
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_METHOD_NAME(1),
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_METHOD_SIGNATURE(1), 
		local_ref< array<jbyte,1> >
	>(get_jobject());
}

local_ref< java::lang::String > java::security::spec::PKCS8EncodedKeySpec::getFormat()
{
	return call_method<
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_CLASS_NAME,
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_METHOD_NAME(2),
		java::security::spec::PKCS8EncodedKeySpec::J2CPP_METHOD_SIGNATURE(2), 
		local_ref< java::lang::String >
	>(get_jobject());
}


J2CPP_DEFINE_CLASS(java::security::spec::PKCS8EncodedKeySpec,"java/security/spec/PKCS8EncodedKeySpec")
J2CPP_DEFINE_METHOD(java::security::spec::PKCS8EncodedKeySpec,0,"<init>","([B)V")
J2CPP_DEFINE_METHOD(java::security::spec::PKCS8EncodedKeySpec,1,"getEncoded","()[B")
J2CPP_DEFINE_METHOD(java::security::spec::PKCS8EncodedKeySpec,2,"getFormat","()Ljava/lang/String;")

} //namespace j2cpp

#endif //J2CPP_JAVA_SECURITY_SPEC_PKCS8ENCODEDKEYSPEC_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
