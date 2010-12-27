#ifndef J2CPP_GLOBAL_REF_HPP
#define J2CPP_GLOBAL_REF_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/jobject_global_ref.hpp>

namespace j2cpp {

	template < typename T > class local_ref;

	template < typename ObjType >
	class global_ref
	{
	public:
		typedef ObjType object_type;
		typedef jobject_global_ref<jobject> ref_type;

		template <typename T> friend class local_ref;

		global_ref(jobject obj)
		: m_ref(obj)
		, m_obj(m_ref.get_jtype())
		{
		}

		global_ref(object_type const &o)
		: m_ref(o.get_jtype())
		, m_obj(m_ref.get_jtype())
		{
		}

		global_ref(global_ref const &that)
		: m_ref(that.m_ref)
		, m_obj(m_ref.get_jtype())
		{
		}

		global_ref(local_ref<object_type> const &that)
		: m_ref(that.m_ref)
		, m_obj(m_ref.get_jtype())
		{
		}

		object_type* operator->() const
		{
			return &m_obj;
		}

		jobject get_jtype() const { return m_obj.get_jtype(); }

	private:
		ref_type			m_ref;
		mutable object_type	m_obj;

	};
} //namespace j2cpp

#endif //J2CPP_GLOBAL_REF_HPP
