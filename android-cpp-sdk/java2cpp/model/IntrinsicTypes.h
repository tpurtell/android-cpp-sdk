#ifndef JAVA2CPP_MODEL_INTRINSIC_TYPES_H
#define JAVA2CPP_MODEL_INTRINSIC_TYPES_H

#include "Type.h"

namespace model {

	class IntrinsicType
		: public Type
	{
	public:
		IntrinsicType();
		virtual ~IntrinsicType();

		bool		is_intrinsic() const;
		bool		is_array() const;
	};

	class Byte
		: public IntrinsicType
	{
	public:
		Byte();
		~Byte();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	class Char
		: public IntrinsicType
	{
	public:
		Char();
		~Char();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	class Double
		: public IntrinsicType
	{
	public:
		Double();
		~Double();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	class Float
		: public IntrinsicType
	{
	public:
		Float();
		~Float();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	class Int
		: public IntrinsicType
	{
	public:
		Int();
		~Int();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	class Long
		: public IntrinsicType
	{
	public:
		Long();
		~Long();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	class Short
		: public IntrinsicType
	{
	public:
		Short();
		~Short();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	class Void
		: public IntrinsicType
	{
	public:
		Void();
		~Void();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
		bool			is_void() const;
	};

	class Boolean
		: public IntrinsicType
	{
	public:
		Boolean();
		~Boolean();

		std::string		get_java_type() const;
		std::string		get_cxx_type() const;
		std::string		get_java_signature() const;
		std::string		get_jni_call_type() const;
	};

	typedef enum
	{
		kByte,
		kChar,
		kDouble,
		kFloat,
		kInt,
		kLong,
		kShort,
		kVoid,
		kBoolean
	} eIntrinsicType;

	template <eIntrinsicType>
	struct IntrinsicTypeTraits
	{
	};

	template<>
	struct IntrinsicTypeTraits<kByte>
	{
		typedef Byte ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kChar>
	{
		typedef Char ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kDouble>
	{
		typedef Double ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kFloat>
	{
		typedef Float ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kInt>
	{
		typedef Int ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kLong>
	{
		typedef Long ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kShort>
	{
		typedef Short ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kVoid>
	{
		typedef Void ValueType;
	};

	template<>
	struct IntrinsicTypeTraits<kBoolean>
	{
		typedef Boolean ValueType;
	};

	template <eIntrinsicType IT>
	class IntrinsicNDimArrayType
		: public NDimArrayType
	{
		typedef typename IntrinsicTypeTraits<IT>::ValueType IType;
	public:
		IntrinsicNDimArrayType(shared_ptr<IType> const &it, std::size_t nd)
			: NDimArrayType()
			, m_intrinsic_type(it)
			, m_num_dimensions(nd)
		{
		}

		~IntrinsicNDimArrayType()
		{
		}
		
		std::size_t get_num_dimensions() const
		{
			return m_num_dimensions;
		}

		shared_ptr<Type> get_element_type() const
		{
			return m_intrinsic_type;
		}

		std::string get_java_type() const
		{
			std::string java_type(m_intrinsic_type->get_java_type());
			for(std::size_t d=0;d<m_num_dimensions;++d)
				java_type+="[]";
			return java_type;
		}
		
		std::string	get_cxx_type() const
		{
			format fmtArray("cpp_%1%_array<%2%>");
			fmtArray % m_intrinsic_type->get_java_type();
			fmtArray % m_num_dimensions;
			return fmtArray.str();
		}

		std::string get_java_signature() const
		{
			std::string java_signature;
			for(std::size_t d=0;d<m_num_dimensions;++d)
				java_signature+="[";
			java_signature+=m_intrinsic_type->get_java_signature();
			return java_signature;
		}

		std::string		get_jni_call_type() const
		{
			return std::string("Object");
		}

	private:
		shared_ptr<IType>	m_intrinsic_type;
		std::size_t			m_num_dimensions;
	};
	
} //namespace model

#endif //JAVA2CPP_MODEL_INTRINSIC_TYPES_H