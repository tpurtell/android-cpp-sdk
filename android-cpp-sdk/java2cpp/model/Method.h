#ifndef JAVA2CPP_MODEL_METHOD_H
#define JAVA2CPP_MODEL_METHOD_H

#include "ClassMember.h"

namespace model {

	class Type;
	class Class;

	class Method
		: public ClassMember
	{
		friend class Class;
		Method(shared_ptr<Class> const &c, std::string const &n);
	public:
		typedef std::vector< shared_ptr<Type> > argument_types_t;
		~Method();

		argument_types_t const&	get_argument_types() const;
		void					set_argument_types(argument_types_t const &args);

		shared_ptr<Type>		get_return_type() const;
		void					set_return_type(shared_ptr<Type> const &ret);

		bool					is_constructor() const;
		std::string				get_display_name() const;
		std::string				get_java_signature() const;
	
	private:
		argument_types_t	m_argument_types;
		shared_ptr<Type>	m_return_type;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_METHOD_H
