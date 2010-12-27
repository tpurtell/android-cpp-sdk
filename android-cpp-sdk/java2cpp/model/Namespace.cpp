#include "Precompile.h"
#include "Namespace.h"

namespace model {

	Namespace::~Namespace()
	{
	}

	Entity::eKind Namespace::get_kind() const
	{
		return Entity::kNamespace;
	}

	std::string Namespace::get_java_class_name() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			shared_ptr<Namespace> parentNamespace(parentEntity, detail::dynamic_cast_tag());
			BOOST_ASSERT(parentNamespace);
			std::string strParentNSName(parentNamespace->get_java_class_name());
			return strParentNSName.empty()?m_name:strParentNSName+"."+m_name;
		}
		return m_name;
	}

	std::string Namespace::get_java_class_path() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			shared_ptr<Namespace> parentNamespace(parentEntity, detail::dynamic_cast_tag());
			BOOST_ASSERT(parentNamespace);
			std::string strParentNSPath(parentNamespace->get_java_class_path());
			return strParentNSPath.empty()?m_name:strParentNSPath+"/"+m_name;
		}
		return m_name;
	}

	std::string	Namespace::get_cxx_class_name() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			shared_ptr<Namespace> parentNamespace(parentEntity, detail::dynamic_cast_tag());
			BOOST_ASSERT(parentNamespace);
			std::string strParentFQNSName(parentNamespace->get_cxx_class_name());
			return strParentFQNSName.empty()?m_name:strParentFQNSName+"::"+m_name;
		}
		return m_name;		
	}

	shared_ptr<Namespace> Namespace::get_parent_namespace() const
	{
		return shared_ptr<Namespace>(get_parent(), detail::dynamic_cast_tag());
	}

} //namespace model
