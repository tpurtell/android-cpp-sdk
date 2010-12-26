#ifndef J2CPP_ENVIRONMENT_HPP
#define J2CPP_ENVIRONMENT_HPP

#include <j2cpp/config.hpp>

namespace j2cpp {

	class environment
	{
		environment()
		: m_jenv(0)
		{
		}

	public:

		static environment& get()
		{
			static environment _instance;
			return _instance;
		}

		bool init(JNIEnv *jenv)
		{
			if(m_jenv) return true;
			m_jenv=jenv;
			return m_jenv?true:false;
		}

		JNIEnv*	get_jenv()
		{
			return m_jenv;
		}

	private:
		JNIEnv	*m_jenv;
	};

} //namespace j2cpp

#endif //J2CPP_ENVIRONMENT_HPP
