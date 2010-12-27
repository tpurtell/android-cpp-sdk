#ifndef JAVA2CPP_MODEL_FQCLASS_TYPE_H
#define JAVA2CPP_MODEL_FQCLASS_TYPE_H

#include "Type.h"
#include "Class.h"

namespace model {

	class FQClassType
		: public Type
	{
	public:
		FQClassType(shared_ptr<Class> const &c);
		~FQClassType();

		bool					is_intrinsic() const;
		bool					is_array() const;
		bool					is_fqc() const;
		
		shared_ptr<Class>		get_class() const;

		std::string				get_java_type() const;
		std::string				get_cxx_type() const;
		std::string				get_java_signature() const;
		std::string				get_jni_call_type() const;

	private:
		weak_ptr<Class>			m_class;
	};

	class FQClassNDimArrayType
		: public NDimArrayType
	{
	public:
		FQClassNDimArrayType(shared_ptr<FQClassType> const &fqcet, std::size_t nd);
		~FQClassNDimArrayType();

		bool					is_intrinsic() const;
		bool					is_array() const;
		std::size_t				get_num_dimensions() const;
		shared_ptr<Type>		get_element_type() const;

		std::string				get_java_type() const;
		std::string				get_cxx_type() const;
		std::string				get_java_signature() const;
		std::string				get_jni_call_type() const;

	private:
		shared_ptr<FQClassType>	m_fqclass_element_type;
		std::size_t				m_num_dimensions;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_FQCLASS_TYPE_H