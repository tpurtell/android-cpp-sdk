#include "Precompile.h"
#include "FQClassType.h"

namespace model {

	FQClassType::FQClassType(shared_ptr<Class> const &c)
		: Type()
		, m_class(c)
	{
	}

	FQClassType::~FQClassType()
	{
	}

	bool FQClassType::is_intrinsic() const
	{
		return false;
	}

	bool FQClassType::is_array() const
	{
		return false;
	}

	bool FQClassType::is_fqc() const
	{
		return true;
	}

	shared_ptr<Class> FQClassType::get_class() const
	{
		return m_class.lock();
	}

	std::string FQClassType::get_java_type() const
	{
		return get_class()->get_java_class_name();
	}

	std::string FQClassType::get_cxx_type() const
	{
		return get_class()->get_cxx_class_name();
	}

	std::string FQClassType::get_java_signature() const
	{
		return std::string("L")+get_class()->get_java_signature()+";";
	}

	std::string FQClassType::get_jni_call_type() const
	{
		return std::string("Object");
	}

	FQClassNDimArrayType::FQClassNDimArrayType(shared_ptr<FQClassType> const &fqcet, std::size_t nd)
		: NDimArrayType()
		, m_fqclass_element_type(fqcet)
		, m_num_dimensions(nd)
	{
	}

	FQClassNDimArrayType::~FQClassNDimArrayType()
	{
	}

	bool FQClassNDimArrayType::is_intrinsic() const
	{
		return false;
	}

	bool FQClassNDimArrayType::is_array() const
	{
		return true;
	}

	shared_ptr<Type> FQClassNDimArrayType::get_element_type() const
	{
		return m_fqclass_element_type;
	}

	std::size_t FQClassNDimArrayType::get_num_dimensions() const
	{
		return m_num_dimensions;
	}

	std::string FQClassNDimArrayType::get_java_type() const
	{
		std::string java_type(m_fqclass_element_type->get_java_type());
		for(std::size_t d=0;d<m_num_dimensions;++d)
			java_type+="[]";
		return java_type;
	}

	std::string FQClassNDimArrayType::get_cxx_type() const
	{
		format fmtArray("array< local_ref< %1% >, %2%>");
		fmtArray % m_fqclass_element_type->get_cxx_type();
		fmtArray % m_num_dimensions;
		return fmtArray.str();
	}

	std::string FQClassNDimArrayType::get_java_signature() const
	{
		std::string java_signature;
		for(std::size_t d=0;d<m_num_dimensions;++d)
			java_signature+="[";
		java_signature+=m_fqclass_element_type->get_java_type();
		return java_signature;
	}

	std::string FQClassNDimArrayType::get_jni_call_type() const
	{
		return std::string("Object");
	}


} //namespace model