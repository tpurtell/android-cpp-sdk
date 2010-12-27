/*================================================================================
  code generated by: java2cpp
  class: java.nio.channels.SocketChannel
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_NIO_CHANNELS_SOCKETCHANNEL_HPP_DECL
#define J2CPP_JAVA_NIO_CHANNELS_SOCKETCHANNEL_HPP_DECL


namespace j2cpp { namespace java { namespace net { class Socket; } } }
namespace j2cpp { namespace java { namespace net { class SocketAddress; } } }
namespace j2cpp { namespace java { namespace nio { class ByteBuffer; } } }


#include <java/net/Socket.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>


namespace j2cpp {

namespace java { namespace nio { namespace channels {

	class SocketChannel;
	class SocketChannel
		: public cpp_object<SocketChannel>
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

		SocketChannel(jobject jobj)
		: cpp_object<SocketChannel>(jobj)
		{
		}

		static local_ref< java::nio::channels::SocketChannel > open();
		static local_ref< java::nio::channels::SocketChannel > open(local_ref< java::net::SocketAddress > const&);
		cpp_int validOps();
		local_ref< java::net::Socket > socket();
		cpp_boolean isConnected();
		cpp_boolean isConnectionPending();
		cpp_boolean connect(local_ref< java::net::SocketAddress > const&);
		cpp_boolean finishConnect();
		cpp_int read(local_ref< java::nio::ByteBuffer > const&);
		cpp_long read(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const&, cpp_int const&, cpp_int const&);
		cpp_long read(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const&);
		cpp_int write(local_ref< java::nio::ByteBuffer > const&);
		cpp_long write(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const&, cpp_int const&, cpp_int const&);
		cpp_long write(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const&);
	}; //class SocketChannel

} //namespace channels
} //namespace nio
} //namespace java


} //namespace j2cpp

#endif //J2CPP_JAVA_NIO_CHANNELS_SOCKETCHANNEL_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_NIO_CHANNELS_SOCKETCHANNEL_HPP_IMPL
#define J2CPP_JAVA_NIO_CHANNELS_SOCKETCHANNEL_HPP_IMPL

namespace j2cpp {


template <>
local_ref< java::nio::channels::SocketChannel > create< java::nio::channels::SocketChannel>(local_ref< java::nio::channels::spi::SelectorProvider > const &a0)
{
	return local_ref< java::nio::channels::SocketChannel >(
		environment::get().get_jenv()->NewObject(
			get_class<java::nio::channels::SocketChannel::J2CPP_CLASS_NAME>(),
			get_method_id<java::nio::channels::SocketChannel::J2CPP_CLASS_NAME, java::nio::channels::SocketChannel::J2CPP_METHOD_NAME(0), java::nio::channels::SocketChannel::J2CPP_METHOD_SIGNATURE(0), false>(),
			a0.get_jtype()
		)
	);
}

local_ref< java::nio::channels::SocketChannel > java::nio::channels::SocketChannel::open()
{
	return local_ref< java::nio::channels::SocketChannel >(
		environment::get().get_jenv()->CallStaticObjectMethod(
			get_class<J2CPP_CLASS_NAME>(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(1), J2CPP_METHOD_SIGNATURE(1), true>()
		)
	);
}

local_ref< java::nio::channels::SocketChannel > java::nio::channels::SocketChannel::open(local_ref< java::net::SocketAddress > const &a0)
{
	return local_ref< java::nio::channels::SocketChannel >(
		environment::get().get_jenv()->CallStaticObjectMethod(
			get_class<J2CPP_CLASS_NAME>(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(2), J2CPP_METHOD_SIGNATURE(2), true>(),
			a0.get_jtype()
		)
	);
}

cpp_int java::nio::channels::SocketChannel::validOps()
{
	return cpp_int(
		environment::get().get_jenv()->CallIntMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(3), J2CPP_METHOD_SIGNATURE(3), false>()
		)
	);
}

local_ref< java::net::Socket > java::nio::channels::SocketChannel::socket()
{
	return local_ref< java::net::Socket >(
		environment::get().get_jenv()->CallObjectMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(4), J2CPP_METHOD_SIGNATURE(4), false>()
		)
	);
}

cpp_boolean java::nio::channels::SocketChannel::isConnected()
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(5), J2CPP_METHOD_SIGNATURE(5), false>()
		)
	);
}

cpp_boolean java::nio::channels::SocketChannel::isConnectionPending()
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(6), J2CPP_METHOD_SIGNATURE(6), false>()
		)
	);
}

cpp_boolean java::nio::channels::SocketChannel::connect(local_ref< java::net::SocketAddress > const &a0)
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(7), J2CPP_METHOD_SIGNATURE(7), false>(),
			a0.get_jtype()
		)
	);
}

cpp_boolean java::nio::channels::SocketChannel::finishConnect()
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(8), J2CPP_METHOD_SIGNATURE(8), false>()
		)
	);
}

cpp_int java::nio::channels::SocketChannel::read(local_ref< java::nio::ByteBuffer > const &a0)
{
	return cpp_int(
		environment::get().get_jenv()->CallIntMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(9), J2CPP_METHOD_SIGNATURE(9), false>(),
			a0.get_jtype()
		)
	);
}

cpp_long java::nio::channels::SocketChannel::read(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const &a0, cpp_int const &a1, cpp_int const &a2)
{
	return cpp_long(
		environment::get().get_jenv()->CallLongMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(10), J2CPP_METHOD_SIGNATURE(10), false>(),
			a0.get_jtype(), a1.get_jtype(), a2.get_jtype()
		)
	);
}

cpp_long java::nio::channels::SocketChannel::read(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const &a0)
{
	return cpp_long(
		environment::get().get_jenv()->CallLongMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(11), J2CPP_METHOD_SIGNATURE(11), false>(),
			a0.get_jtype()
		)
	);
}

cpp_int java::nio::channels::SocketChannel::write(local_ref< java::nio::ByteBuffer > const &a0)
{
	return cpp_int(
		environment::get().get_jenv()->CallIntMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(12), J2CPP_METHOD_SIGNATURE(12), false>(),
			a0.get_jtype()
		)
	);
}

cpp_long java::nio::channels::SocketChannel::write(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const &a0, cpp_int const &a1, cpp_int const &a2)
{
	return cpp_long(
		environment::get().get_jenv()->CallLongMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(13), J2CPP_METHOD_SIGNATURE(13), false>(),
			a0.get_jtype(), a1.get_jtype(), a2.get_jtype()
		)
	);
}

cpp_long java::nio::channels::SocketChannel::write(local_ref< cpp_object_array<java::nio::ByteBuffer, 1> > const &a0)
{
	return cpp_long(
		environment::get().get_jenv()->CallLongMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(14), J2CPP_METHOD_SIGNATURE(14), false>(),
			a0.get_jtype()
		)
	);
}


J2CPP_DEFINE_CLASS(java::nio::channels::SocketChannel,"java/nio/channels/SocketChannel")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,0,"<init>","(Ljava/nio/channels/spi/SelectorProvider;)V")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,1,"open","()Ljava/nio/channels/SocketChannel;")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,2,"open","(Ljava/net/SocketAddress;)Ljava/nio/channels/SocketChannel;")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,3,"validOps","()I")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,4,"socket","()Ljava/net/Socket;")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,5,"isConnected","()Z")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,6,"isConnectionPending","()Z")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,7,"connect","(Ljava/net/SocketAddress;)Z")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,8,"finishConnect","()Z")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,9,"read","(Ljava/nio/ByteBuffer;)I")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,10,"read","([java.nio.ByteBufferII)J")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,11,"read","([java.nio.ByteBuffer)J")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,12,"write","(Ljava/nio/ByteBuffer;)I")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,13,"write","([java.nio.ByteBufferII)J")
J2CPP_DEFINE_METHOD(java::nio::channels::SocketChannel,14,"write","([java.nio.ByteBuffer)J")

} //namespace j2cpp

#endif //J2CPP_JAVA_NIO_CHANNELS_SOCKETCHANNEL_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION