/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: java.nio.CharBuffer
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_NIO_CHARBUFFER_HPP_DECL
#define J2CPP_JAVA_NIO_CHARBUFFER_HPP_DECL


namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace java { namespace lang { class CharSequence; } } }
namespace j2cpp { namespace java { namespace lang { class Readable; } } }
namespace j2cpp { namespace java { namespace lang { class Comparable; } } }
namespace j2cpp { namespace java { namespace lang { class Appendable; } } }
namespace j2cpp { namespace java { namespace lang { class Object; } } }
namespace j2cpp { namespace java { namespace nio { class Buffer; } } }
namespace j2cpp { namespace java { namespace nio { class ByteOrder; } } }


#include <java/lang/Appendable.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Readable.hpp>
#include <java/lang/String.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteOrder.hpp>


namespace j2cpp {

namespace java { namespace nio {

	class CharBuffer;
	class CharBuffer
		: public object<CharBuffer>
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
		J2CPP_DECLARE_METHOD(17)
		J2CPP_DECLARE_METHOD(18)
		J2CPP_DECLARE_METHOD(19)
		J2CPP_DECLARE_METHOD(20)
		J2CPP_DECLARE_METHOD(21)
		J2CPP_DECLARE_METHOD(22)
		J2CPP_DECLARE_METHOD(23)
		J2CPP_DECLARE_METHOD(24)
		J2CPP_DECLARE_METHOD(25)
		J2CPP_DECLARE_METHOD(26)
		J2CPP_DECLARE_METHOD(27)
		J2CPP_DECLARE_METHOD(28)
		J2CPP_DECLARE_METHOD(29)
		J2CPP_DECLARE_METHOD(30)
		J2CPP_DECLARE_METHOD(31)
		J2CPP_DECLARE_METHOD(32)
		J2CPP_DECLARE_METHOD(33)
		J2CPP_DECLARE_METHOD(34)
		J2CPP_DECLARE_METHOD(35)
		J2CPP_DECLARE_METHOD(36)
		J2CPP_DECLARE_METHOD(37)
		J2CPP_DECLARE_METHOD(38)
		J2CPP_DECLARE_METHOD(39)
		J2CPP_DECLARE_METHOD(40)
		J2CPP_DECLARE_METHOD(41)

		explicit CharBuffer(jobject jobj)
		: object<CharBuffer>(jobj)
		{
		}

		operator local_ref<java::lang::CharSequence>() const;
		operator local_ref<java::lang::Readable>() const;
		operator local_ref<java::lang::Comparable>() const;
		operator local_ref<java::lang::Appendable>() const;
		operator local_ref<java::lang::Object>() const;
		operator local_ref<java::nio::Buffer>() const;


		static local_ref< java::nio::CharBuffer > allocate(jint);
		static local_ref< java::nio::CharBuffer > wrap(local_ref< array<jchar,1> >  const&);
		static local_ref< java::nio::CharBuffer > wrap(local_ref< array<jchar,1> >  const&, jint, jint);
		static local_ref< java::nio::CharBuffer > wrap(local_ref< java::lang::CharSequence >  const&);
		static local_ref< java::nio::CharBuffer > wrap(local_ref< java::lang::CharSequence >  const&, jint, jint);
		local_ref< array<jchar,1> > array_();
		jint arrayOffset();
		local_ref< java::nio::CharBuffer > asReadOnlyBuffer();
		jchar charAt(jint);
		local_ref< java::nio::CharBuffer > compact();
		jint compareTo(local_ref< java::nio::CharBuffer >  const&);
		local_ref< java::nio::CharBuffer > duplicate();
		jboolean equals(local_ref< java::lang::Object >  const&);
		jchar get();
		local_ref< java::nio::CharBuffer > get(local_ref< array<jchar,1> >  const&);
		local_ref< java::nio::CharBuffer > get(local_ref< array<jchar,1> >  const&, jint, jint);
		jchar get(jint);
		jboolean hasArray();
		jint hashCode();
		jboolean isDirect();
		jint length();
		local_ref< java::nio::ByteOrder > order();
		local_ref< java::nio::CharBuffer > put(jchar);
		local_ref< java::nio::CharBuffer > put(local_ref< array<jchar,1> >  const&);
		local_ref< java::nio::CharBuffer > put(local_ref< array<jchar,1> >  const&, jint, jint);
		local_ref< java::nio::CharBuffer > put(local_ref< java::nio::CharBuffer >  const&);
		local_ref< java::nio::CharBuffer > put(jint, jchar);
		local_ref< java::nio::CharBuffer > put(local_ref< java::lang::String >  const&);
		local_ref< java::nio::CharBuffer > put(local_ref< java::lang::String >  const&, jint, jint);
		local_ref< java::nio::CharBuffer > slice();
		local_ref< java::lang::CharSequence > subSequence(jint, jint);
		local_ref< java::lang::String > toString();
		local_ref< java::nio::CharBuffer > append(jchar);
		local_ref< java::nio::CharBuffer > append(local_ref< java::lang::CharSequence >  const&);
		local_ref< java::nio::CharBuffer > append(local_ref< java::lang::CharSequence >  const&, jint, jint);
		jint read(local_ref< java::nio::CharBuffer >  const&);
		local_ref< java::lang::Object > array_1();
		jint compareTo(local_ref< java::lang::Object >  const&);
		local_ref< java::lang::Appendable > append_1(local_ref< java::lang::CharSequence >  const&, jint, jint);
		local_ref< java::lang::Appendable > append_1(local_ref< java::lang::CharSequence >  const&);
		local_ref< java::lang::Appendable > append_1(jchar);
	}; //class CharBuffer

} //namespace nio
} //namespace java

} //namespace j2cpp

#endif //J2CPP_JAVA_NIO_CHARBUFFER_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_NIO_CHARBUFFER_HPP_IMPL
#define J2CPP_JAVA_NIO_CHARBUFFER_HPP_IMPL

namespace j2cpp {



java::nio::CharBuffer::operator local_ref<java::lang::CharSequence>() const
{
	return local_ref<java::lang::CharSequence>(get_jobject());
}

java::nio::CharBuffer::operator local_ref<java::lang::Readable>() const
{
	return local_ref<java::lang::Readable>(get_jobject());
}

java::nio::CharBuffer::operator local_ref<java::lang::Comparable>() const
{
	return local_ref<java::lang::Comparable>(get_jobject());
}

java::nio::CharBuffer::operator local_ref<java::lang::Appendable>() const
{
	return local_ref<java::lang::Appendable>(get_jobject());
}

java::nio::CharBuffer::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}

java::nio::CharBuffer::operator local_ref<java::nio::Buffer>() const
{
	return local_ref<java::nio::Buffer>(get_jobject());
}


local_ref< java::nio::CharBuffer > java::nio::CharBuffer::allocate(jint a0)
{
	return call_static_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(1),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(1), 
		local_ref< java::nio::CharBuffer >
	>(a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::wrap(local_ref< array<jchar,1> > const &a0)
{
	return call_static_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(2),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(2), 
		local_ref< java::nio::CharBuffer >
	>(a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::wrap(local_ref< array<jchar,1> > const &a0, jint a1, jint a2)
{
	return call_static_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(3),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(3), 
		local_ref< java::nio::CharBuffer >
	>(a0, a1, a2);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::wrap(local_ref< java::lang::CharSequence > const &a0)
{
	return call_static_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(4),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(4), 
		local_ref< java::nio::CharBuffer >
	>(a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::wrap(local_ref< java::lang::CharSequence > const &a0, jint a1, jint a2)
{
	return call_static_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(5),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(5), 
		local_ref< java::nio::CharBuffer >
	>(a0, a1, a2);
}

local_ref< array<jchar,1> > java::nio::CharBuffer::array_()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(6),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(6), 
		local_ref< array<jchar,1> >
	>(get_jobject());
}

jint java::nio::CharBuffer::arrayOffset()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(7),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(7), 
		jint
	>(get_jobject());
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::asReadOnlyBuffer()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(8),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(8), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject());
}

jchar java::nio::CharBuffer::charAt(jint a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(9),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(9), 
		jchar
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::compact()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(10),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(10), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject());
}

jint java::nio::CharBuffer::compareTo(local_ref< java::nio::CharBuffer > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(11),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(11), 
		jint
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::duplicate()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(12),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(12), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject());
}

jboolean java::nio::CharBuffer::equals(local_ref< java::lang::Object > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(13),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(13), 
		jboolean
	>(get_jobject(), a0);
}

jchar java::nio::CharBuffer::get()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(14),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(14), 
		jchar
	>(get_jobject());
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::get(local_ref< array<jchar,1> > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(15),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(15), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::get(local_ref< array<jchar,1> > const &a0, jint a1, jint a2)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(16),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(16), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0, a1, a2);
}

jchar java::nio::CharBuffer::get(jint a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(17),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(17), 
		jchar
	>(get_jobject(), a0);
}

jboolean java::nio::CharBuffer::hasArray()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(18),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(18), 
		jboolean
	>(get_jobject());
}

jint java::nio::CharBuffer::hashCode()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(19),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(19), 
		jint
	>(get_jobject());
}

jboolean java::nio::CharBuffer::isDirect()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(20),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(20), 
		jboolean
	>(get_jobject());
}

jint java::nio::CharBuffer::length()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(21),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(21), 
		jint
	>(get_jobject());
}

local_ref< java::nio::ByteOrder > java::nio::CharBuffer::order()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(22),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(22), 
		local_ref< java::nio::ByteOrder >
	>(get_jobject());
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::put(jchar a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(23),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(23), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::put(local_ref< array<jchar,1> > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(24),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(24), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::put(local_ref< array<jchar,1> > const &a0, jint a1, jint a2)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(25),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(25), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0, a1, a2);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::put(local_ref< java::nio::CharBuffer > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(26),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(26), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::put(jint a0, jchar a1)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(27),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(27), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0, a1);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::put(local_ref< java::lang::String > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(28),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(28), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::put(local_ref< java::lang::String > const &a0, jint a1, jint a2)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(29),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(29), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0, a1, a2);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::slice()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(30),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(30), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject());
}

local_ref< java::lang::CharSequence > java::nio::CharBuffer::subSequence(jint a0, jint a1)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(31),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(31), 
		local_ref< java::lang::CharSequence >
	>(get_jobject(), a0, a1);
}

local_ref< java::lang::String > java::nio::CharBuffer::toString()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(32),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(32), 
		local_ref< java::lang::String >
	>(get_jobject());
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::append(jchar a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(33),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(33), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::append(local_ref< java::lang::CharSequence > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(34),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(34), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0);
}

local_ref< java::nio::CharBuffer > java::nio::CharBuffer::append(local_ref< java::lang::CharSequence > const &a0, jint a1, jint a2)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(35),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(35), 
		local_ref< java::nio::CharBuffer >
	>(get_jobject(), a0, a1, a2);
}

jint java::nio::CharBuffer::read(local_ref< java::nio::CharBuffer > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(36),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(36), 
		jint
	>(get_jobject(), a0);
}

local_ref< java::lang::Object > java::nio::CharBuffer::array_1()
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(37),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(37), 
		local_ref< java::lang::Object >
	>(get_jobject());
}

jint java::nio::CharBuffer::compareTo(local_ref< java::lang::Object > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(38),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(38), 
		jint
	>(get_jobject(), a0);
}

local_ref< java::lang::Appendable > java::nio::CharBuffer::append_1(local_ref< java::lang::CharSequence > const &a0, jint a1, jint a2)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(39),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(39), 
		local_ref< java::lang::Appendable >
	>(get_jobject(), a0, a1, a2);
}

local_ref< java::lang::Appendable > java::nio::CharBuffer::append_1(local_ref< java::lang::CharSequence > const &a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(40),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(40), 
		local_ref< java::lang::Appendable >
	>(get_jobject(), a0);
}

local_ref< java::lang::Appendable > java::nio::CharBuffer::append_1(jchar a0)
{
	return call_method<
		java::nio::CharBuffer::J2CPP_CLASS_NAME,
		java::nio::CharBuffer::J2CPP_METHOD_NAME(41),
		java::nio::CharBuffer::J2CPP_METHOD_SIGNATURE(41), 
		local_ref< java::lang::Appendable >
	>(get_jobject(), a0);
}


J2CPP_DEFINE_CLASS(java::nio::CharBuffer,"java/nio/CharBuffer")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,0,"<init>","()V")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,1,"allocate","(I)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,2,"wrap","([C)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,3,"wrap","([CII)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,4,"wrap","(Ljava/lang/CharSequence;)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,5,"wrap","(Ljava/lang/CharSequence;II)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,6,"array","()[C")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,7,"arrayOffset","()I")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,8,"asReadOnlyBuffer","()Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,9,"charAt","(I)C")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,10,"compact","()Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,11,"compareTo","(Ljava/nio/CharBuffer;)I")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,12,"duplicate","()Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,13,"equals","(Ljava/lang/Object;)Z")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,14,"get","()C")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,15,"get","([C)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,16,"get","([CII)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,17,"get","(I)C")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,18,"hasArray","()Z")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,19,"hashCode","()I")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,20,"isDirect","()Z")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,21,"length","()I")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,22,"order","()Ljava/nio/ByteOrder;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,23,"put","(C)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,24,"put","([C)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,25,"put","([CII)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,26,"put","(Ljava/nio/CharBuffer;)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,27,"put","(IC)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,28,"put","(Ljava/lang/String;)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,29,"put","(Ljava/lang/String;II)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,30,"slice","()Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,31,"subSequence","(II)Ljava/lang/CharSequence;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,32,"toString","()Ljava/lang/String;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,33,"append","(C)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,34,"append","(Ljava/lang/CharSequence;)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,35,"append","(Ljava/lang/CharSequence;II)Ljava/nio/CharBuffer;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,36,"read","(Ljava/nio/CharBuffer;)I")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,37,"array","()Ljava/lang/Object;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,38,"compareTo","(Ljava/lang/Object;)I")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,39,"append","(Ljava/lang/CharSequence;II)Ljava/lang/Appendable;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,40,"append","(Ljava/lang/CharSequence;)Ljava/lang/Appendable;")
J2CPP_DEFINE_METHOD(java::nio::CharBuffer,41,"append","(C)Ljava/lang/Appendable;")

} //namespace j2cpp

#endif //J2CPP_JAVA_NIO_CHARBUFFER_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
