#ifndef J2CPP_ENVIRONMENT_HPP
#define J2CPP_ENVIRONMENT_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class environment
	{
		environment()
		: m_jvm(0)
		, m_ctscler(0)
		{
		}

	public:
		typedef bool (*curr_thread_set_cler)();
		
		static environment& get()
		{
			static environment _instance;
			return _instance;
		}

		bool init(JavaVM *jvm, curr_thread_set_cler ctscler=0)
		{
			if(m_jvm) return true;
			m_jvm=jvm;
			m_ctscler=ctscler;
			return m_jvm?true:false;
		}

		JNIEnv*	get_jenv()
		{
			if(!m_jvm)
				return 0;
			JNIEnv *jenv(0);
			if(JNI_OK!=m_jvm->GetEnv((void **)&jenv, JNI_VERSION_1_6))
				return 0;
			return jenv;
		}

		bool attach_current_thread()
		{
			if(!m_jvm)
				return false;

			JNIEnv *jenv(0);
			if(JNI_OK!=m_jvm->AttachCurrentThread(&jenv,0))
				return false;

			if(!jenv)
				return false;
			
			if(m_ctscler && !m_ctscler())
				return false;

			return true;
		}

		bool detach_current_thread()
		{
			if(!m_jvm)
				return false;
			return (JNI_OK==m_jvm->DetachCurrentThread());
		}

	private:
		JavaVM *m_jvm;
		curr_thread_set_cler m_ctscler;
	};

} //namespace j2cpp

#endif //J2CPP_ENVIRONMENT_HPP
