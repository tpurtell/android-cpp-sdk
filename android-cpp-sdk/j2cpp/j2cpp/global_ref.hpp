#ifndef J2CPP_GLOBAL_REF_HPP
#define J2CPP_GLOBAL_REF_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/detail/atomic_count.hpp>
#include <j2cpp/detail/swap.hpp>

namespace j2cpp {

	template < typename T > class local_ref;

	template < typename ObjType >
	class global_ref
	{
	public:
		template < typename T > friend class local_ref;

		typedef ObjType					object_type;
		typedef detail::atomic_count	count_type;

		explicit global_ref(jobject jobj)
		: m_px(0)
		, m_pn(0)
		{
			if(jobject gref=(jobj?
				environment::get().get_jenv()->NewGlobalRef(jobj):0)
			)
			{
				m_px=new object_type(gref);
				m_pn=new count_type(1);
			}
		}

		~global_ref()
		{
			if(--*m_pn==0)
			{
				if(m_px && m_px->get_jobject())
					environment::get().get_jenv()->DeleteGlobalRef(m_px->get_jobject());

				delete m_px;
				delete m_pn;
			}
		}

		global_ref(object_type const &obj)
		: m_px(0)
		, m_pn(0)
		{
			if(jobject gref=(obj.get_jobject()?
				environment::get().get_jenv()->NewGlobalRef(obj.get_jobject()):0)
			)
			{
				m_px=new object_type(gref);
				m_pn=new count_type(1);
			}
		}

		global_ref(global_ref const &that)
		: m_px(that.m_px)
		, m_pn(that.m_pn)
		{
			++*m_pn;
		}

		global_ref(local_ref<object_type> const &lref)
		: m_px(0)
		, m_pn(0)
		{
			if(jobject gref=(lref.get_jobject()?
				environment::get().get_jenv()->NewGlobalRef(lref.get_jobject()):0)
			)
			{
				m_px=new object_type(gref);
				m_pn=new count_type(1);
			}
		}

		object_type* operator->() const
		{
			return m_px;
		}

		jobject get_jobject() const
		{
			return (m_px?m_px->get_jobject():0);
		}

	private:
		object_type	*m_px;
		count_type	*m_pn;
	};

} //namespace j2cpp

#endif //J2CPP_GLOBAL_REF_HPP
