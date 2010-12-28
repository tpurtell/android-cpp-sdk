#ifndef J2CPP_ENVIRONMENT_HPP
#define J2CPP_ENVIRONMENT_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class environment
	{
		environment()
		: m_jvm(0)
		{
		}

	public:

		static environment& get()
		{
			static environment _instance;
			return _instance;
		}

		bool init(JavaVM *jvm)
		{
			if(m_jvm) return true;
			m_jvm=jvm;
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

	private:
		JavaVM	*m_jvm;
	};

} //namespace j2cpp

#endif //J2CPP_ENVIRONMENT_HPP
