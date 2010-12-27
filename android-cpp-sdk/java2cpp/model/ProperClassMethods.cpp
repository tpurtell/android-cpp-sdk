#include "Precompile.h"
#include "ProperClassMethods.h"
#include "Type.h"

namespace model {

	ProperClassMethods::proper_method::proper_method(shared_ptr<Method> const &m)
		: m_method(m)
		, m_proper_name(m_method->get_name())
	{
	}

	std::string ProperClassMethods::proper_method::signature() const
	{
		std::string strSignature;
		if(m_method->test_access_flag(ClassMember::kStatic))
			strSignature+="S";
		else
			strSignature+="M";

		strSignature+=m_proper_name;
		strSignature+="(";
		BOOST_FOREACH(shared_ptr<Type> argType, m_method->get_argument_types())
			strSignature+=argType->get_java_signature();
		strSignature+=")";
		return strSignature;
	}

	ProperClassMethods::ProperClassMethods(shared_ptr<Class> const &clazz)
	{
		for(std::size_t m=0;m<clazz->get_methods_count();++m)
		{
			proper_method pm(clazz->get_method(m));
			if(!m_methods.push_back(pm).second)
			{
				std::size_t n(1);
				do
				{
					format fmtName("%1%_%2%");
					fmtName % clazz->get_method(m)->get_name();
					fmtName % n++;
					pm.m_proper_name=fmtName.str();
				}
				while(!m_methods.push_back(pm).second);
			}
		}
	}

	std::size_t ProperClassMethods::get_methods_count() const
	{
		return m_methods.size();
	}
	
	ProperClassMethods::proper_method ProperClassMethods::get_method(std::size_t idx) const
	{
		return m_methods[idx];
	}

} //namespace model