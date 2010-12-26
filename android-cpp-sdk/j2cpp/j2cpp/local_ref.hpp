#ifndef J2CPP_LOCAL_REF_HPP
#define J2CPP_LOCAL_REF_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/jobject_local_ref.hpp>

namespace j2cpp {

	template < typename T > class global_ref;

	template < typename ObjType >
	class local_ref
	{
	public:
		typedef ObjType object_type;
		typedef jobject_local_ref<jobject> ref_type;

		template < typename T > friend class global_ref;

		local_ref(jobject obj)
		: m_ref(obj)
		, m_obj(m_ref)
		{
		}

		explicit local_ref(local_ref const &that)
		: m_ref(that.m_ref)
		, m_obj(m_ref)
		{
		}

		explicit local_ref(global_ref<object_type> const &that)
		: m_ref(that.m_ref)
		, m_obj(m_ref)
		{
		}

		object_type* operator->() const
		{
			return &m_obj;
		}

		operator jobject () const { return m_obj; }
		jobject get_jtype() const { return m_obj; }

	private:
		ref_type			m_ref;
		mutable object_type	m_obj;
	};
} //namespace j2cpp

#endif //J2CPP_LOCAL_REF_HPP
