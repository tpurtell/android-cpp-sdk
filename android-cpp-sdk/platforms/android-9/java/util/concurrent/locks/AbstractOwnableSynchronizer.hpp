/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: java.util.concurrent.locks.AbstractOwnableSynchronizer
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_UTIL_CONCURRENT_LOCKS_ABSTRACTOWNABLESYNCHRONIZER_HPP_DECL
#define J2CPP_JAVA_UTIL_CONCURRENT_LOCKS_ABSTRACTOWNABLESYNCHRONIZER_HPP_DECL


namespace j2cpp { namespace java { namespace lang { class Object; } } }
namespace j2cpp { namespace java { namespace io { class Serializable; } } }


#include <java/io/Serializable.hpp>
#include <java/lang/Object.hpp>


namespace j2cpp {

namespace java { namespace util { namespace concurrent { namespace locks {

	class AbstractOwnableSynchronizer;
	class AbstractOwnableSynchronizer
		: public object<AbstractOwnableSynchronizer>
	{
	public:

		J2CPP_DECLARE_CLASS

		J2CPP_DECLARE_METHOD(0)
		J2CPP_DECLARE_METHOD(1)
		J2CPP_DECLARE_METHOD(2)

		explicit AbstractOwnableSynchronizer(jobject jobj)
		: object<AbstractOwnableSynchronizer>(jobj)
		{
		}

		operator local_ref<java::lang::Object>() const;
		operator local_ref<java::io::Serializable>() const;


	}; //class AbstractOwnableSynchronizer

} //namespace locks
} //namespace concurrent
} //namespace util
} //namespace java

} //namespace j2cpp

#endif //J2CPP_JAVA_UTIL_CONCURRENT_LOCKS_ABSTRACTOWNABLESYNCHRONIZER_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_UTIL_CONCURRENT_LOCKS_ABSTRACTOWNABLESYNCHRONIZER_HPP_IMPL
#define J2CPP_JAVA_UTIL_CONCURRENT_LOCKS_ABSTRACTOWNABLESYNCHRONIZER_HPP_IMPL

namespace j2cpp {



java::util::concurrent::locks::AbstractOwnableSynchronizer::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}

java::util::concurrent::locks::AbstractOwnableSynchronizer::operator local_ref<java::io::Serializable>() const
{
	return local_ref<java::io::Serializable>(get_jobject());
}





J2CPP_DEFINE_CLASS(java::util::concurrent::locks::AbstractOwnableSynchronizer,"java/util/concurrent/locks/AbstractOwnableSynchronizer")
J2CPP_DEFINE_METHOD(java::util::concurrent::locks::AbstractOwnableSynchronizer,0,"<init>","()V")
J2CPP_DEFINE_METHOD(java::util::concurrent::locks::AbstractOwnableSynchronizer,1,"setExclusiveOwnerThread","(Ljava/lang/Thread;)V")
J2CPP_DEFINE_METHOD(java::util::concurrent::locks::AbstractOwnableSynchronizer,2,"getExclusiveOwnerThread","()Ljava/lang/Thread;")

} //namespace j2cpp

#endif //J2CPP_JAVA_UTIL_CONCURRENT_LOCKS_ABSTRACTOWNABLESYNCHRONIZER_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
