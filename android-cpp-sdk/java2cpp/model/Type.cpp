#include "Precompile.h"
#include "Type.h"

namespace model {
	Type::Type()
	{
	}

	Type::~Type()
	{
	}

	shared_ptr<Class> Type::get_class() const
	{
		return shared_ptr<Class>();
	}

	bool Type::is_void() const
	{
		return false;
	}

	bool Type::is_fqc() const
	{
		return false;
	}

	NDimArrayType::NDimArrayType()
	{
	}

	NDimArrayType::~NDimArrayType()
	{
	}

	bool NDimArrayType::is_intrinsic() const
	{
		return false;
	}

	bool NDimArrayType::is_array() const
	{
		return true;
	}



} //namespace model