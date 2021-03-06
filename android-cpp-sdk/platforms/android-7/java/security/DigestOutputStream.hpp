/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: java.security.DigestOutputStream
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_SECURITY_DIGESTOUTPUTSTREAM_HPP_DECL
#define J2CPP_JAVA_SECURITY_DIGESTOUTPUTSTREAM_HPP_DECL


namespace j2cpp { namespace java { namespace io { class Flushable; } } }
namespace j2cpp { namespace java { namespace io { class Closeable; } } }
namespace j2cpp { namespace java { namespace io { class FilterOutputStream; } } }
namespace j2cpp { namespace java { namespace io { class OutputStream; } } }
namespace j2cpp { namespace java { namespace lang { class Object; } } }
namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace java { namespace security { class MessageDigest; } } }


#include <java/io/Closeable.hpp>
#include <java/io/FilterOutputStream.hpp>
#include <java/io/Flushable.hpp>
#include <java/io/OutputStream.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/security/MessageDigest.hpp>


namespace j2cpp {

namespace java { namespace security {

	class DigestOutputStream;
	class DigestOutputStream
		: public object<DigestOutputStream>
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
		J2CPP_DECLARE_FIELD(0)

		explicit DigestOutputStream(jobject jobj)
		: object<DigestOutputStream>(jobj)
		{
		}

		operator local_ref<java::io::Flushable>() const;
		operator local_ref<java::io::Closeable>() const;
		operator local_ref<java::io::FilterOutputStream>() const;
		operator local_ref<java::io::OutputStream>() const;
		operator local_ref<java::lang::Object>() const;


		DigestOutputStream(local_ref< java::io::OutputStream > const&, local_ref< java::security::MessageDigest > const&);
		local_ref< java::security::MessageDigest > getMessageDigest();
		void setMessageDigest(local_ref< java::security::MessageDigest >  const&);
		void write(jint);
		void write(local_ref< array<jbyte,1> >  const&, jint, jint);
		void on(jboolean);
		local_ref< java::lang::String > toString();

	}; //class DigestOutputStream

} //namespace security
} //namespace java

} //namespace j2cpp

#endif //J2CPP_JAVA_SECURITY_DIGESTOUTPUTSTREAM_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_SECURITY_DIGESTOUTPUTSTREAM_HPP_IMPL
#define J2CPP_JAVA_SECURITY_DIGESTOUTPUTSTREAM_HPP_IMPL

namespace j2cpp {



java::security::DigestOutputStream::operator local_ref<java::io::Flushable>() const
{
	return local_ref<java::io::Flushable>(get_jobject());
}

java::security::DigestOutputStream::operator local_ref<java::io::Closeable>() const
{
	return local_ref<java::io::Closeable>(get_jobject());
}

java::security::DigestOutputStream::operator local_ref<java::io::FilterOutputStream>() const
{
	return local_ref<java::io::FilterOutputStream>(get_jobject());
}

java::security::DigestOutputStream::operator local_ref<java::io::OutputStream>() const
{
	return local_ref<java::io::OutputStream>(get_jobject());
}

java::security::DigestOutputStream::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}


java::security::DigestOutputStream::DigestOutputStream(local_ref< java::io::OutputStream > const &a0, local_ref< java::security::MessageDigest > const &a1)
: object<java::security::DigestOutputStream>(
	call_new_object<
		java::security::DigestOutputStream::J2CPP_CLASS_NAME,
		java::security::DigestOutputStream::J2CPP_METHOD_NAME(0),
		java::security::DigestOutputStream::J2CPP_METHOD_SIGNATURE(0)
	>(a0, a1)
)
{
}


local_ref< java::security::MessageDigest > java::security::DigestOutputStream::getMessageDigest()
{
	return call_method<
		java::security::DigestOutputStream::J2CPP_CLASS_NAME,
		java::security::DigestOutputStream::J2CPP_METHOD_NAME(1),
		java::security::DigestOutputStream::J2CPP_METHOD_SIGNATURE(1), 
		local_ref< java::security::MessageDigest >
	>(get_jobject());
}

void java::security::DigestOutputStream::setMessageDigest(local_ref< java::security::MessageDigest > const &a0)
{
	return call_method<
		java::security::DigestOutputStream::J2CPP_CLASS_NAME,
		java::security::DigestOutputStream::J2CPP_METHOD_NAME(2),
		java::security::DigestOutputStream::J2CPP_METHOD_SIGNATURE(2), 
		void
	>(get_jobject(), a0);
}

void java::security::DigestOutputStream::write(jint a0)
{
	return call_method<
		java::security::DigestOutputStream::J2CPP_CLASS_NAME,
		java::security::DigestOutputStream::J2CPP_METHOD_NAME(3),
		java::security::DigestOutputStream::J2CPP_METHOD_SIGNATURE(3), 
		void
	>(get_jobject(), a0);
}

void java::security::DigestOutputStream::write(local_ref< array<jbyte,1> > const &a0, jint a1, jint a2)
{
	return call_method<
		java::security::DigestOutputStream::J2CPP_CLASS_NAME,
		java::security::DigestOutputStream::J2CPP_METHOD_NAME(4),
		java::security::DigestOutputStream::J2CPP_METHOD_SIGNATURE(4), 
		void
	>(get_jobject(), a0, a1, a2);
}

void java::security::DigestOutputStream::on(jboolean a0)
{
	return call_method<
		java::security::DigestOutputStream::J2CPP_CLASS_NAME,
		java::security::DigestOutputStream::J2CPP_METHOD_NAME(5),
		java::security::DigestOutputStream::J2CPP_METHOD_SIGNATURE(5), 
		void
	>(get_jobject(), a0);
}

local_ref< java::lang::String > java::security::DigestOutputStream::toString()
{
	return call_method<
		java::security::DigestOutputStream::J2CPP_CLASS_NAME,
		java::security::DigestOutputStream::J2CPP_METHOD_NAME(6),
		java::security::DigestOutputStream::J2CPP_METHOD_SIGNATURE(6), 
		local_ref< java::lang::String >
	>(get_jobject());
}



J2CPP_DEFINE_CLASS(java::security::DigestOutputStream,"java/security/DigestOutputStream")
J2CPP_DEFINE_METHOD(java::security::DigestOutputStream,0,"<init>","(Ljava/io/OutputStream;Ljava/security/MessageDigest;)V")
J2CPP_DEFINE_METHOD(java::security::DigestOutputStream,1,"getMessageDigest","()Ljava/security/MessageDigest;")
J2CPP_DEFINE_METHOD(java::security::DigestOutputStream,2,"setMessageDigest","(Ljava/security/MessageDigest;)V")
J2CPP_DEFINE_METHOD(java::security::DigestOutputStream,3,"write","(I)V")
J2CPP_DEFINE_METHOD(java::security::DigestOutputStream,4,"write","([BII)V")
J2CPP_DEFINE_METHOD(java::security::DigestOutputStream,5,"on","(Z)V")
J2CPP_DEFINE_METHOD(java::security::DigestOutputStream,6,"toString","()Ljava/lang/String;")
J2CPP_DEFINE_FIELD(java::security::DigestOutputStream,0,"digest","Ljava/security/MessageDigest;")

} //namespace j2cpp

#endif //J2CPP_JAVA_SECURITY_DIGESTOUTPUTSTREAM_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
