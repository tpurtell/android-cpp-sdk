/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: org.apache.http.HttpMessage
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ORG_APACHE_HTTP_HTTPMESSAGE_HPP_DECL
#define J2CPP_ORG_APACHE_HTTP_HTTPMESSAGE_HPP_DECL


namespace j2cpp { namespace org { namespace apache { namespace http { class HeaderIterator; } } } }
namespace j2cpp { namespace org { namespace apache { namespace http { class ProtocolVersion; } } } }
namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace java { namespace lang { class Object; } } }
namespace j2cpp { namespace org { namespace apache { namespace http { class Header; } } } }
namespace j2cpp { namespace org { namespace apache { namespace http { namespace params { class HttpParams; } } } } }


#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <org/apache/http/Header.hpp>
#include <org/apache/http/HeaderIterator.hpp>
#include <org/apache/http/ProtocolVersion.hpp>
#include <org/apache/http/params/HttpParams.hpp>


namespace j2cpp {

namespace org { namespace apache { namespace http {

	class HttpMessage;
	class HttpMessage
		: public object<HttpMessage>
	{
	public:

		J2CPP_DECLARE_CLASS

		J2CPP_DECLARE_METHOD(0)
		J2CPP_DECLARE_METHOD(1)
		J2CPP_DECLARE_METHOD(2)
		J2CPP_DECLARE_METHOD(3)
		J2CPP_DECLARE_METHOD(4)
		J2CPP_DECLARE_METHOD(5)
		J2CPP_DECLARE_METHOD(6)
		J2CPP_DECLARE_METHOD(7)
		J2CPP_DECLARE_METHOD(8)
		J2CPP_DECLARE_METHOD(9)
		J2CPP_DECLARE_METHOD(10)
		J2CPP_DECLARE_METHOD(11)
		J2CPP_DECLARE_METHOD(12)
		J2CPP_DECLARE_METHOD(13)
		J2CPP_DECLARE_METHOD(14)
		J2CPP_DECLARE_METHOD(15)
		J2CPP_DECLARE_METHOD(16)

		explicit HttpMessage(jobject jobj)
		: object<HttpMessage>(jobj)
		{
		}

		operator local_ref<java::lang::Object>() const;


		local_ref< org::apache::http::ProtocolVersion > getProtocolVersion();
		jboolean containsHeader(local_ref< java::lang::String >  const&);
		local_ref< array< local_ref< org::apache::http::Header >, 1> > getHeaders(local_ref< java::lang::String >  const&);
		local_ref< org::apache::http::Header > getFirstHeader(local_ref< java::lang::String >  const&);
		local_ref< org::apache::http::Header > getLastHeader(local_ref< java::lang::String >  const&);
		local_ref< array< local_ref< org::apache::http::Header >, 1> > getAllHeaders();
		void addHeader(local_ref< org::apache::http::Header >  const&);
		void addHeader(local_ref< java::lang::String >  const&, local_ref< java::lang::String >  const&);
		void setHeader(local_ref< org::apache::http::Header >  const&);
		void setHeader(local_ref< java::lang::String >  const&, local_ref< java::lang::String >  const&);
		void setHeaders(local_ref< array< local_ref< org::apache::http::Header >, 1> >  const&);
		void removeHeader(local_ref< org::apache::http::Header >  const&);
		void removeHeaders(local_ref< java::lang::String >  const&);
		local_ref< org::apache::http::HeaderIterator > headerIterator();
		local_ref< org::apache::http::HeaderIterator > headerIterator(local_ref< java::lang::String >  const&);
		local_ref< org::apache::http::params::HttpParams > getParams();
		void setParams(local_ref< org::apache::http::params::HttpParams >  const&);
	}; //class HttpMessage

} //namespace http
} //namespace apache
} //namespace org

} //namespace j2cpp

#endif //J2CPP_ORG_APACHE_HTTP_HTTPMESSAGE_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ORG_APACHE_HTTP_HTTPMESSAGE_HPP_IMPL
#define J2CPP_ORG_APACHE_HTTP_HTTPMESSAGE_HPP_IMPL

namespace j2cpp {



org::apache::http::HttpMessage::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}

local_ref< org::apache::http::ProtocolVersion > org::apache::http::HttpMessage::getProtocolVersion()
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(0),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(0), 
		local_ref< org::apache::http::ProtocolVersion >
	>(get_jobject());
}

jboolean org::apache::http::HttpMessage::containsHeader(local_ref< java::lang::String > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(1),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(1), 
		jboolean
	>(get_jobject(), a0);
}

local_ref< array< local_ref< org::apache::http::Header >, 1> > org::apache::http::HttpMessage::getHeaders(local_ref< java::lang::String > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(2),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(2), 
		local_ref< array< local_ref< org::apache::http::Header >, 1> >
	>(get_jobject(), a0);
}

local_ref< org::apache::http::Header > org::apache::http::HttpMessage::getFirstHeader(local_ref< java::lang::String > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(3),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(3), 
		local_ref< org::apache::http::Header >
	>(get_jobject(), a0);
}

local_ref< org::apache::http::Header > org::apache::http::HttpMessage::getLastHeader(local_ref< java::lang::String > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(4),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(4), 
		local_ref< org::apache::http::Header >
	>(get_jobject(), a0);
}

local_ref< array< local_ref< org::apache::http::Header >, 1> > org::apache::http::HttpMessage::getAllHeaders()
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(5),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(5), 
		local_ref< array< local_ref< org::apache::http::Header >, 1> >
	>(get_jobject());
}

void org::apache::http::HttpMessage::addHeader(local_ref< org::apache::http::Header > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(6),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(6), 
		void
	>(get_jobject(), a0);
}

void org::apache::http::HttpMessage::addHeader(local_ref< java::lang::String > const &a0, local_ref< java::lang::String > const &a1)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(7),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(7), 
		void
	>(get_jobject(), a0, a1);
}

void org::apache::http::HttpMessage::setHeader(local_ref< org::apache::http::Header > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(8),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(8), 
		void
	>(get_jobject(), a0);
}

void org::apache::http::HttpMessage::setHeader(local_ref< java::lang::String > const &a0, local_ref< java::lang::String > const &a1)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(9),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(9), 
		void
	>(get_jobject(), a0, a1);
}

void org::apache::http::HttpMessage::setHeaders(local_ref< array< local_ref< org::apache::http::Header >, 1> > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(10),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(10), 
		void
	>(get_jobject(), a0);
}

void org::apache::http::HttpMessage::removeHeader(local_ref< org::apache::http::Header > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(11),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(11), 
		void
	>(get_jobject(), a0);
}

void org::apache::http::HttpMessage::removeHeaders(local_ref< java::lang::String > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(12),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(12), 
		void
	>(get_jobject(), a0);
}

local_ref< org::apache::http::HeaderIterator > org::apache::http::HttpMessage::headerIterator()
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(13),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(13), 
		local_ref< org::apache::http::HeaderIterator >
	>(get_jobject());
}

local_ref< org::apache::http::HeaderIterator > org::apache::http::HttpMessage::headerIterator(local_ref< java::lang::String > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(14),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(14), 
		local_ref< org::apache::http::HeaderIterator >
	>(get_jobject(), a0);
}

local_ref< org::apache::http::params::HttpParams > org::apache::http::HttpMessage::getParams()
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(15),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(15), 
		local_ref< org::apache::http::params::HttpParams >
	>(get_jobject());
}

void org::apache::http::HttpMessage::setParams(local_ref< org::apache::http::params::HttpParams > const &a0)
{
	return call_method<
		org::apache::http::HttpMessage::J2CPP_CLASS_NAME,
		org::apache::http::HttpMessage::J2CPP_METHOD_NAME(16),
		org::apache::http::HttpMessage::J2CPP_METHOD_SIGNATURE(16), 
		void
	>(get_jobject(), a0);
}


J2CPP_DEFINE_CLASS(org::apache::http::HttpMessage,"org/apache/http/HttpMessage")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,0,"getProtocolVersion","()Lorg/apache/http/ProtocolVersion;")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,1,"containsHeader","(Ljava/lang/String;)Z")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,2,"getHeaders","(Ljava/lang/String;)[org.apache.http.Header")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,3,"getFirstHeader","(Ljava/lang/String;)Lorg/apache/http/Header;")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,4,"getLastHeader","(Ljava/lang/String;)Lorg/apache/http/Header;")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,5,"getAllHeaders","()[org.apache.http.Header")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,6,"addHeader","(Lorg/apache/http/Header;)V")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,7,"addHeader","(Ljava/lang/String;Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,8,"setHeader","(Lorg/apache/http/Header;)V")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,9,"setHeader","(Ljava/lang/String;Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,10,"setHeaders","([org.apache.http.Header)V")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,11,"removeHeader","(Lorg/apache/http/Header;)V")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,12,"removeHeaders","(Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,13,"headerIterator","()Lorg/apache/http/HeaderIterator;")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,14,"headerIterator","(Ljava/lang/String;)Lorg/apache/http/HeaderIterator;")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,15,"getParams","()Lorg/apache/http/params/HttpParams;")
J2CPP_DEFINE_METHOD(org::apache::http::HttpMessage,16,"setParams","(Lorg/apache/http/params/HttpParams;)V")

} //namespace j2cpp

#endif //J2CPP_ORG_APACHE_HTTP_HTTPMESSAGE_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
