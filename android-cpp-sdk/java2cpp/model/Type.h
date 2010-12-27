#ifndef JAVACPP_MODEL_TYPE_H
#define JAVACPP_MODEL_TYPE_H

namespace model {

	class Class;

	class Type
		: public enable_shared_from_this2<Type>
		, protected noncopyable
	{
	public:
		
		Type();
		virtual ~Type();
		virtual bool				is_intrinsic() const = 0;
		virtual bool				is_array() const = 0;
		virtual bool				is_fqc() const;
		virtual std::string			get_java_type() const = 0;
		virtual shared_ptr<Class>	get_class() const;
		virtual std::string			get_cxx_type() const = 0;
		virtual std::string			get_java_signature() const = 0;
		virtual bool				is_void() const;
		virtual std::string			get_jni_call_type() const = 0;
	};

	class NDimArrayType
		: public Type
	{
	public:
		NDimArrayType();
		virtual ~NDimArrayType();
		
		bool						is_intrinsic() const;
		bool						is_array() const;
		
		virtual std::size_t			get_num_dimensions() const = 0;
		virtual shared_ptr<Type>	get_element_type() const = 0;
	};

} //namespace model


#endif //JAVACPP_MODEL_TYPE_H