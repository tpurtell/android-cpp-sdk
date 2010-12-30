#include "Precompile.h"
#include "IntrinsicTypes.h"

namespace model {

	IntrinsicType::IntrinsicType()
		: Type()
	{
	}

	IntrinsicType::~IntrinsicType()
	{
	}

	bool IntrinsicType::is_intrinsic() const
	{
		return true;
	}

	bool IntrinsicType::is_array() const
	{
		return false;
	}

	Byte::Byte()
		: IntrinsicType()
	{
	}

	Byte::~Byte()
	{
	}

	std::string Byte::get_java_type() const
	{
		return std::string("byte");
	}

	std::string	Byte::get_cxx_type() const
	{
		return std::string("jbyte");
	}
	
	std::string	Byte::get_java_signature() const
	{
		return std::string("B");
	}

	std::string Byte::get_jni_call_type() const
	{
		return std::string("Byte");
	}
	
	Char::Char()
		: IntrinsicType()
	{
	}

	Char::~Char()
	{
	}

	std::string Char::get_java_type() const
	{
		return std::string("char");
	}

	std::string	Char::get_cxx_type() const
	{
		return std::string("jchar");
	}

	std::string	Char::get_java_signature() const
	{
		return std::string("C");
	}

	std::string Char::get_jni_call_type() const
	{
		return std::string("Char");
	}

	Double::Double()
		: IntrinsicType()
	{
	}

	Double::~Double()
	{
	}

	std::string Double::get_java_type() const
	{
		return std::string("double");
	}

	std::string	Double::get_cxx_type() const
	{
		return std::string("jdouble");
	}

	std::string	Double::get_java_signature() const
	{
		return std::string("D");
	}

	std::string Double::get_jni_call_type() const
	{
		return std::string("Double");
	}

	Float::Float()
		: IntrinsicType()
	{
	}

	Float::~Float()
	{
	}

	std::string Float::get_java_type() const
	{
		return std::string("float");
	}

	std::string	Float::get_cxx_type() const
	{
		return std::string("jfloat");
	}

	std::string	Float::get_java_signature() const
	{
		return std::string("F");
	}

	std::string Float::get_jni_call_type() const
	{
		return std::string("Float");
	}

	Int::Int()
		: IntrinsicType()
	{
	}

	Int::~Int()
	{
	}

	std::string Int::get_java_type() const
	{
		return std::string("int");
	}

	std::string	Int::get_cxx_type() const
	{
		return std::string("jint");
	}

	std::string	Int::get_java_signature() const
	{
		return std::string("I");
	}

	std::string Int::get_jni_call_type() const
	{
		return std::string("Int");
	}
	
	Long::Long()
		: IntrinsicType()
	{
	}

	Long::~Long()
	{
	}

	std::string Long::get_java_type() const
	{
		return std::string("long");
	}

	std::string	Long::get_cxx_type() const
	{
		return std::string("jlong");
	}

	std::string	Long::get_java_signature() const
	{
		return std::string("J");
	}

	std::string Long::get_jni_call_type() const
	{
		return std::string("Long");
	}

	Short::Short()
		: IntrinsicType()
	{
	}

	Short::~Short()
	{
	}

	std::string Short::get_java_type() const
	{
		return std::string("short");
	}

	std::string	Short::get_cxx_type() const
	{
		return std::string("jshort");
	}

	std::string	Short::get_java_signature() const
	{
		return std::string("S");
	}

	std::string Short::get_jni_call_type() const
	{
		return std::string("Short");
	}

	Void::Void()
		: IntrinsicType()
	{
	}

	Void::~Void()
	{
	}

	std::string Void::get_java_type() const
	{
		return std::string("void");
	}

	std::string	Void::get_cxx_type() const
	{
		return std::string("void");
	}

	std::string	Void::get_java_signature() const
	{
		return std::string("V");
	}

	std::string Void::get_jni_call_type() const
	{
		return std::string("Void");
	}

	bool Void::is_void() const
	{
		return true;
	}

	Boolean::Boolean()
		: IntrinsicType()
	{
	}

	Boolean::~Boolean()
	{
	}

	std::string Boolean::get_java_type() const
	{
		return std::string("boolean");
	}

	std::string	Boolean::get_cxx_type() const
	{
		return std::string("jboolean");
	}

	std::string	Boolean::get_java_signature() const
	{
		return std::string("Z");
	}

	std::string Boolean::get_jni_call_type() const
	{
		return std::string("Boolean");
	}

} //namespace model