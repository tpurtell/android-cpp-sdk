/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: org.w3c.dom.DOMError
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ORG_W3C_DOM_DOMERROR_HPP_DECL
#define J2CPP_ORG_W3C_DOM_DOMERROR_HPP_DECL


namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace java { namespace lang { class Object; } } }
namespace j2cpp { namespace org { namespace w3c { namespace dom { class DOMLocator; } } } }


#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <org/w3c/dom/DOMLocator.hpp>


namespace j2cpp {

namespace org { namespace w3c { namespace dom {

	class DOMError;
	class DOMError
		: public object<DOMError>
	{
	public:

		J2CPP_DECLARE_CLASS

		J2CPP_DECLARE_METHOD(0)
		J2CPP_DECLARE_METHOD(1)
		J2CPP_DECLARE_METHOD(2)
		J2CPP_DECLARE_METHOD(3)
		J2CPP_DECLARE_METHOD(4)
		J2CPP_DECLARE_METHOD(5)
		J2CPP_DECLARE_FIELD(0)
		J2CPP_DECLARE_FIELD(1)
		J2CPP_DECLARE_FIELD(2)

		explicit DOMError(jobject jobj)
		: object<DOMError>(jobj)
		{
		}

		operator local_ref<java::lang::Object>() const;


		jshort getSeverity();
		local_ref< java::lang::String > getMessage();
		local_ref< java::lang::String > getType();
		local_ref< java::lang::Object > getRelatedException();
		local_ref< java::lang::Object > getRelatedData();
		local_ref< org::w3c::dom::DOMLocator > getLocation();

		static static_field< J2CPP_CLASS_NAME, J2CPP_FIELD_NAME(0), J2CPP_FIELD_SIGNATURE(0), jshort > SEVERITY_WARNING;
		static static_field< J2CPP_CLASS_NAME, J2CPP_FIELD_NAME(1), J2CPP_FIELD_SIGNATURE(1), jshort > SEVERITY_ERROR;
		static static_field< J2CPP_CLASS_NAME, J2CPP_FIELD_NAME(2), J2CPP_FIELD_SIGNATURE(2), jshort > SEVERITY_FATAL_ERROR;
	}; //class DOMError

} //namespace dom
} //namespace w3c
} //namespace org

} //namespace j2cpp

#endif //J2CPP_ORG_W3C_DOM_DOMERROR_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ORG_W3C_DOM_DOMERROR_HPP_IMPL
#define J2CPP_ORG_W3C_DOM_DOMERROR_HPP_IMPL

namespace j2cpp {



org::w3c::dom::DOMError::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}

jshort org::w3c::dom::DOMError::getSeverity()
{
	return call_method<
		org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
		org::w3c::dom::DOMError::J2CPP_METHOD_NAME(0),
		org::w3c::dom::DOMError::J2CPP_METHOD_SIGNATURE(0), 
		jshort
	>(get_jobject());
}

local_ref< java::lang::String > org::w3c::dom::DOMError::getMessage()
{
	return call_method<
		org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
		org::w3c::dom::DOMError::J2CPP_METHOD_NAME(1),
		org::w3c::dom::DOMError::J2CPP_METHOD_SIGNATURE(1), 
		local_ref< java::lang::String >
	>(get_jobject());
}

local_ref< java::lang::String > org::w3c::dom::DOMError::getType()
{
	return call_method<
		org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
		org::w3c::dom::DOMError::J2CPP_METHOD_NAME(2),
		org::w3c::dom::DOMError::J2CPP_METHOD_SIGNATURE(2), 
		local_ref< java::lang::String >
	>(get_jobject());
}

local_ref< java::lang::Object > org::w3c::dom::DOMError::getRelatedException()
{
	return call_method<
		org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
		org::w3c::dom::DOMError::J2CPP_METHOD_NAME(3),
		org::w3c::dom::DOMError::J2CPP_METHOD_SIGNATURE(3), 
		local_ref< java::lang::Object >
	>(get_jobject());
}

local_ref< java::lang::Object > org::w3c::dom::DOMError::getRelatedData()
{
	return call_method<
		org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
		org::w3c::dom::DOMError::J2CPP_METHOD_NAME(4),
		org::w3c::dom::DOMError::J2CPP_METHOD_SIGNATURE(4), 
		local_ref< java::lang::Object >
	>(get_jobject());
}

local_ref< org::w3c::dom::DOMLocator > org::w3c::dom::DOMError::getLocation()
{
	return call_method<
		org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
		org::w3c::dom::DOMError::J2CPP_METHOD_NAME(5),
		org::w3c::dom::DOMError::J2CPP_METHOD_SIGNATURE(5), 
		local_ref< org::w3c::dom::DOMLocator >
	>(get_jobject());
}


static_field<
	org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
	org::w3c::dom::DOMError::J2CPP_FIELD_NAME(0),
	org::w3c::dom::DOMError::J2CPP_FIELD_SIGNATURE(0),
	jshort
> org::w3c::dom::DOMError::SEVERITY_WARNING;

static_field<
	org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
	org::w3c::dom::DOMError::J2CPP_FIELD_NAME(1),
	org::w3c::dom::DOMError::J2CPP_FIELD_SIGNATURE(1),
	jshort
> org::w3c::dom::DOMError::SEVERITY_ERROR;

static_field<
	org::w3c::dom::DOMError::J2CPP_CLASS_NAME,
	org::w3c::dom::DOMError::J2CPP_FIELD_NAME(2),
	org::w3c::dom::DOMError::J2CPP_FIELD_SIGNATURE(2),
	jshort
> org::w3c::dom::DOMError::SEVERITY_FATAL_ERROR;


J2CPP_DEFINE_CLASS(org::w3c::dom::DOMError,"org/w3c/dom/DOMError")
J2CPP_DEFINE_METHOD(org::w3c::dom::DOMError,0,"getSeverity","()S")
J2CPP_DEFINE_METHOD(org::w3c::dom::DOMError,1,"getMessage","()Ljava/lang/String;")
J2CPP_DEFINE_METHOD(org::w3c::dom::DOMError,2,"getType","()Ljava/lang/String;")
J2CPP_DEFINE_METHOD(org::w3c::dom::DOMError,3,"getRelatedException","()Ljava/lang/Object;")
J2CPP_DEFINE_METHOD(org::w3c::dom::DOMError,4,"getRelatedData","()Ljava/lang/Object;")
J2CPP_DEFINE_METHOD(org::w3c::dom::DOMError,5,"getLocation","()Lorg/w3c/dom/DOMLocator;")
J2CPP_DEFINE_FIELD(org::w3c::dom::DOMError,0,"SEVERITY_WARNING","S")
J2CPP_DEFINE_FIELD(org::w3c::dom::DOMError,1,"SEVERITY_ERROR","S")
J2CPP_DEFINE_FIELD(org::w3c::dom::DOMError,2,"SEVERITY_FATAL_ERROR","S")

} //namespace j2cpp

#endif //J2CPP_ORG_W3C_DOM_DOMERROR_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
