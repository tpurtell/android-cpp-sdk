#include "Precompile.h"
#include "Field.h"
#include "Class.h"
#include "Type.h"

namespace model {

	Field::Field(shared_ptr<Class> const &c, std::string const &n)
		: ClassMember(c,n)
	{
	}
	
	Field::~Field()
	{
	}

	void Field::set_type(shared_ptr<Type> const &t)
	{
		m_type=t;
	}

	shared_ptr<Type> Field::get_type() const
	{
		return m_type;
	}

	std::string Field::get_java_signature() const
	{
		return m_type->get_java_signature();
	}

} //namespace model
