/*================================================================================
  code generated by: java2cpp
  class: java.util.PriorityQueue
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_UTIL_PRIORITYQUEUE_HPP_DECL
#define J2CPP_JAVA_UTIL_PRIORITYQUEUE_HPP_DECL


namespace j2cpp { namespace java { namespace lang { class Object; } } }
namespace j2cpp { namespace java { namespace util { class Comparator; } } }
namespace j2cpp { namespace java { namespace util { class SortedSet; } } }
namespace j2cpp { namespace java { namespace util { class Iterator; } } }
namespace j2cpp { namespace java { namespace util { class Collection; } } }


#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Comparator.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/SortedSet.hpp>


namespace j2cpp {

namespace java { namespace util {

	class PriorityQueue;
	class PriorityQueue
		: public cpp_object<PriorityQueue>
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

		PriorityQueue(jobject jobj)
		: cpp_object<PriorityQueue>(jobj)
		{
		}

		local_ref< java::util::Iterator > iterator();
		cpp_int size();
		void clear();
		cpp_boolean offer(local_ref< java::lang::Object > const&);
		local_ref< java::lang::Object > poll();
		local_ref< java::lang::Object > peek();
		local_ref< java::util::Comparator > comparator();
		cpp_boolean remove(local_ref< java::lang::Object > const&);
		cpp_boolean add(local_ref< java::lang::Object > const&);
	}; //class PriorityQueue

} //namespace util
} //namespace java


} //namespace j2cpp

#endif //J2CPP_JAVA_UTIL_PRIORITYQUEUE_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JAVA_UTIL_PRIORITYQUEUE_HPP_IMPL
#define J2CPP_JAVA_UTIL_PRIORITYQUEUE_HPP_IMPL

namespace j2cpp {


template <>
local_ref< java::util::PriorityQueue > create< java::util::PriorityQueue>()
{
	return local_ref< java::util::PriorityQueue >(
		environment::get().get_jenv()->NewObject(
			get_class<java::util::PriorityQueue::J2CPP_CLASS_NAME>(),
			get_method_id<java::util::PriorityQueue::J2CPP_CLASS_NAME, java::util::PriorityQueue::J2CPP_METHOD_NAME(0), java::util::PriorityQueue::J2CPP_METHOD_SIGNATURE(0), false>()
		)
	);
}

template <>
local_ref< java::util::PriorityQueue > create< java::util::PriorityQueue>(cpp_int const &a0)
{
	return local_ref< java::util::PriorityQueue >(
		environment::get().get_jenv()->NewObject(
			get_class<java::util::PriorityQueue::J2CPP_CLASS_NAME>(),
			get_method_id<java::util::PriorityQueue::J2CPP_CLASS_NAME, java::util::PriorityQueue::J2CPP_METHOD_NAME(1), java::util::PriorityQueue::J2CPP_METHOD_SIGNATURE(1), false>(),
			a0.get_jtype()
		)
	);
}

template <>
local_ref< java::util::PriorityQueue > create< java::util::PriorityQueue>(cpp_int const &a0, local_ref< java::util::Comparator > const &a1)
{
	return local_ref< java::util::PriorityQueue >(
		environment::get().get_jenv()->NewObject(
			get_class<java::util::PriorityQueue::J2CPP_CLASS_NAME>(),
			get_method_id<java::util::PriorityQueue::J2CPP_CLASS_NAME, java::util::PriorityQueue::J2CPP_METHOD_NAME(2), java::util::PriorityQueue::J2CPP_METHOD_SIGNATURE(2), false>(),
			a0.get_jtype(), a1.get_jtype()
		)
	);
}

template <>
local_ref< java::util::PriorityQueue > create< java::util::PriorityQueue>(local_ref< java::util::Collection > const &a0)
{
	return local_ref< java::util::PriorityQueue >(
		environment::get().get_jenv()->NewObject(
			get_class<java::util::PriorityQueue::J2CPP_CLASS_NAME>(),
			get_method_id<java::util::PriorityQueue::J2CPP_CLASS_NAME, java::util::PriorityQueue::J2CPP_METHOD_NAME(3), java::util::PriorityQueue::J2CPP_METHOD_SIGNATURE(3), false>(),
			a0.get_jtype()
		)
	);
}

template <>
local_ref< java::util::PriorityQueue > create< java::util::PriorityQueue>(local_ref< java::util::PriorityQueue > const &a0)
{
	return local_ref< java::util::PriorityQueue >(
		environment::get().get_jenv()->NewObject(
			get_class<java::util::PriorityQueue::J2CPP_CLASS_NAME>(),
			get_method_id<java::util::PriorityQueue::J2CPP_CLASS_NAME, java::util::PriorityQueue::J2CPP_METHOD_NAME(4), java::util::PriorityQueue::J2CPP_METHOD_SIGNATURE(4), false>(),
			a0.get_jtype()
		)
	);
}

template <>
local_ref< java::util::PriorityQueue > create< java::util::PriorityQueue>(local_ref< java::util::SortedSet > const &a0)
{
	return local_ref< java::util::PriorityQueue >(
		environment::get().get_jenv()->NewObject(
			get_class<java::util::PriorityQueue::J2CPP_CLASS_NAME>(),
			get_method_id<java::util::PriorityQueue::J2CPP_CLASS_NAME, java::util::PriorityQueue::J2CPP_METHOD_NAME(5), java::util::PriorityQueue::J2CPP_METHOD_SIGNATURE(5), false>(),
			a0.get_jtype()
		)
	);
}

local_ref< java::util::Iterator > java::util::PriorityQueue::iterator()
{
	return local_ref< java::util::Iterator >(
		environment::get().get_jenv()->CallObjectMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(6), J2CPP_METHOD_SIGNATURE(6), false>()
		)
	);
}

cpp_int java::util::PriorityQueue::size()
{
	return cpp_int(
		environment::get().get_jenv()->CallIntMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(7), J2CPP_METHOD_SIGNATURE(7), false>()
		)
	);
}

void java::util::PriorityQueue::clear()
{
	return void(
		environment::get().get_jenv()->CallVoidMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(8), J2CPP_METHOD_SIGNATURE(8), false>()
		)
	);
}

cpp_boolean java::util::PriorityQueue::offer(local_ref< java::lang::Object > const &a0)
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(9), J2CPP_METHOD_SIGNATURE(9), false>(),
			a0.get_jtype()
		)
	);
}

local_ref< java::lang::Object > java::util::PriorityQueue::poll()
{
	return local_ref< java::lang::Object >(
		environment::get().get_jenv()->CallObjectMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(10), J2CPP_METHOD_SIGNATURE(10), false>()
		)
	);
}

local_ref< java::lang::Object > java::util::PriorityQueue::peek()
{
	return local_ref< java::lang::Object >(
		environment::get().get_jenv()->CallObjectMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(11), J2CPP_METHOD_SIGNATURE(11), false>()
		)
	);
}

local_ref< java::util::Comparator > java::util::PriorityQueue::comparator()
{
	return local_ref< java::util::Comparator >(
		environment::get().get_jenv()->CallObjectMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(12), J2CPP_METHOD_SIGNATURE(12), false>()
		)
	);
}

cpp_boolean java::util::PriorityQueue::remove(local_ref< java::lang::Object > const &a0)
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(13), J2CPP_METHOD_SIGNATURE(13), false>(),
			a0.get_jtype()
		)
	);
}

cpp_boolean java::util::PriorityQueue::add(local_ref< java::lang::Object > const &a0)
{
	return cpp_boolean(
		environment::get().get_jenv()->CallBooleanMethod(
			get_jtype(),
			get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(14), J2CPP_METHOD_SIGNATURE(14), false>(),
			a0.get_jtype()
		)
	);
}


J2CPP_DEFINE_CLASS(java::util::PriorityQueue,"java/util/PriorityQueue")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,0,"<init>","()V")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,1,"<init>","(I)V")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,2,"<init>","(ILjava/util/Comparator;)V")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,3,"<init>","(Ljava/util/Collection;)V")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,4,"<init>","(Ljava/util/PriorityQueue;)V")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,5,"<init>","(Ljava/util/SortedSet;)V")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,6,"iterator","()Ljava/util/Iterator;")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,7,"size","()I")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,8,"clear","()V")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,9,"offer","(Ljava/lang/Object;)Z")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,10,"poll","()Ljava/lang/Object;")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,11,"peek","()Ljava/lang/Object;")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,12,"comparator","()Ljava/util/Comparator;")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,13,"remove","(Ljava/lang/Object;)Z")
J2CPP_DEFINE_METHOD(java::util::PriorityQueue,14,"add","(Ljava/lang/Object;)Z")

} //namespace j2cpp

#endif //J2CPP_JAVA_UTIL_PRIORITYQUEUE_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION