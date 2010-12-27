#include "Precompile.h"
#include "Method.h"
#include "Class.h"
#include "Type.h"

namespace model {

	Method::Method(shared_ptr<Class> const &c, std::string const &n)
		: ClassMember(c,n)
	{
	}

	Method::~Method()
	{
	}

	Method::argument_types_t const&	Method::get_argument_types() const
	{
		return m_argument_types;
	}

	void Method::set_argument_types(argument_types_t const &args)
	{
		m_argument_types=args;
	}

	shared_ptr<Type> Method::get_return_type() const
	{
		return m_return_type;
	}

	void Method::set_return_type(shared_ptr<Type> const &ret)
	{
		m_return_type=ret;
	}

	bool Method::is_constructor() const
	{
		return ClassMember::get_name()=="<init>" || ClassMember::get_name()=="<clinit>";
	}

	std::string Method::get_display_name() const
	{
		std::string strArgs;
		for(std::size_t a=0;a<m_argument_types.size();++a)
		{
			if(a) strArgs+=", ";
			strArgs+=m_argument_types[a]->get_java_type();
		}
		return ((ClassMember::get_display_name()=="<init>" || ClassMember::get_display_name()=="<clinit>")?
					get_class()->get_name():
					ClassMember::get_display_name())+"("+strArgs+")";
	}

	std::string Method::get_java_signature() const
	{
		std::string methodSignature;
		methodSignature+="(";
		BOOST_FOREACH(shared_ptr<Type> argType, m_argument_types)
			methodSignature+=argType->get_java_signature();
		methodSignature+=")";
		methodSignature+=m_return_type->get_java_signature();
		return methodSignature;
	}

} //namespace model
