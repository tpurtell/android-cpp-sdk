#include "Precompile.h"
#include "Class.h"
#include "Namespace.h"

namespace model {

	Class::~Class()
	{
	}

	Entity::eKind Class::get_kind() const
	{
		return Entity::kClass;
	}

	std::string Class::get_java_class_name() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			if(shared_ptr<Namespace> classNamespace=shared_ptr<Namespace>(parentEntity, detail::dynamic_cast_tag()))
			{
				std::string strClassNamespaceName(classNamespace->get_java_class_name());
				return strClassNamespaceName.empty()?m_name:strClassNamespaceName+"."+m_name;
			}
			else
			if(shared_ptr<Class> parentClass=shared_ptr<Class>(parentEntity, detail::dynamic_cast_tag()))
				return parentClass->get_java_class_name()+"."+m_name;
			
			BOOST_ASSERT(false);
		}
		return m_name;
	}

	std::string Class::get_java_class_path() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			if(shared_ptr<Namespace> classNamespace=shared_ptr<Namespace>(parentEntity, detail::dynamic_cast_tag()))
			{
				std::string strClassNamespacePath(classNamespace->get_java_class_path());
				return strClassNamespacePath.empty()?m_name:strClassNamespacePath+"/"+m_name;
			}
			else
			if(shared_ptr<Class> parentClass=shared_ptr<Class>(parentEntity, detail::dynamic_cast_tag()))
				return parentClass->get_java_class_path()+"$"+m_name;
			BOOST_ASSERT(false);
		}
		return m_name;
	}

	std::string Class::get_cxx_class_name() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			if(shared_ptr<Namespace> classNamespace=shared_ptr<Namespace>(parentEntity, detail::dynamic_cast_tag()))
			{
				std::string strClassFQNamespaceName(classNamespace->get_cxx_class_name());
				return strClassFQNamespaceName.empty()?m_name:strClassFQNamespaceName+"::"+m_name;
			}
			else
			if(shared_ptr<Class> parentClass=shared_ptr<Class>(parentEntity, detail::dynamic_cast_tag()))
				return parentClass->get_cxx_class_name()+"_::"+m_name;
			BOOST_ASSERT(false);
		}
		return m_name;
	}

	std::string Class::get_cxx_include_path() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			if(shared_ptr<Namespace> classNamespace=shared_ptr<Namespace>(parentEntity, detail::dynamic_cast_tag()))
			{
				std::string strClassFQNamespacePath(classNamespace->get_java_class_path());
				return strClassFQNamespacePath.empty()?m_name:strClassFQNamespacePath+"/"+m_name;
			}
			else
			if(shared_ptr<Class> parentClass=shared_ptr<Class>(parentEntity, detail::dynamic_cast_tag()))
				return parentClass->get_cxx_include_path();
			BOOST_ASSERT(false);
		}
		return m_name;
	}

	std::string Class::get_java_signature() const
	{
		if(shared_ptr<Entity> parentEntity=get_parent())
		{
			if(shared_ptr<Namespace> classNamespace=shared_ptr<Namespace>(parentEntity, detail::dynamic_cast_tag()))
			{
				std::string strClassNamespaceName(classNamespace->get_java_class_path());
				return strClassNamespaceName.empty()?m_name:strClassNamespaceName+"/"+m_name;
			}
			else
			if(shared_ptr<Class> parentClass=shared_ptr<Class>(parentEntity, detail::dynamic_cast_tag()))
				return parentClass->get_java_signature()+"$"+m_name;
			BOOST_ASSERT(false);
		}
		return m_name;
	}

	void Class::set_super(shared_ptr<Class> const &s)
	{
		m_super=s;
	}

	shared_ptr<Class> Class::get_super() const
	{
		return m_super;	
	}

	void Class::add_interface(shared_ptr<Class> const &i)
	{
		m_interfaces.push_back(i);
	}

	std::size_t Class::get_interfaces_count() const
	{
		return 	m_interfaces.size();
	}
	
	shared_ptr<Class> Class::get_interface(std::size_t i) const
	{
		return m_interfaces[i];	
	}

	bool Class::is_nested() const
	{
		return shared_ptr<Class>(get_parent(),detail::dynamic_cast_tag())?true:false;
	}

	shared_ptr<Class> Class::get_parent_class() const
	{
		return shared_ptr<Class>(get_parent(),detail::dynamic_cast_tag());
	}

	shared_ptr<Class> Class::get_top_parent_class() const
	{
		if(shared_ptr<Class> topParent=get_parent_class())
		{
			while(shared_ptr<Class> parentsParent=topParent->get_parent_class())
				topParent=parentsParent;
			return topParent;
		}
		return shared_ptr<Class>();
	}
	
	shared_ptr<Namespace> Class::get_namespace() const
	{
		return shared_ptr<Namespace>(get_parent(),detail::dynamic_cast_tag());
	}


	shared_ptr<Method> Class::add_method(std::string const &n)
	{
		shared_ptr<Method> newMethod(
			new Method(
				shared_ptr<Class>(shared_from_this(), detail::dynamic_cast_tag()),
				n
			)
		);
		return m_methods.push_back(newMethod).second?
			newMethod:shared_ptr<Method>();
	}

	std::size_t Class::get_methods_count() const
	{
		return m_methods.size();
	}
	
	shared_ptr<Method> Class::get_method(std::size_t m) const
	{
		return m_methods[m];
	}

	shared_ptr<Field> Class::add_field(std::string const &n)
	{
		shared_ptr<Field> newField(
			new Field(
				shared_ptr<Class>(shared_from_this(), detail::dynamic_cast_tag()),
				n
			)
		);
		return m_fields.push_back(newField).second?
			newField:shared_ptr<Field>();
	}

	std::size_t Class::get_fields_count() const
	{
		return m_fields.size();
	}

	shared_ptr<Field> Class::get_field(std::size_t f) const
	{
		return m_fields[f];
	}

} //namespace model
