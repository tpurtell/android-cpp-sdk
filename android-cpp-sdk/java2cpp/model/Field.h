#ifndef JAVA2CPP_MODEL_FIELD_H
#define JAVA2CPP_MODEL_FIELD_H

#include "ClassMember.h"

namespace model {

	class Type;
	class Class;

	class Field
		: public ClassMember
	{
		friend class Class;
		Field(shared_ptr<Class> const &c, std::string const &n);
	public:
		~Field();
		
		void				set_type(shared_ptr<Type> const &t);
		shared_ptr<Type>	get_type() const;
		std::string			get_java_signature() const;

	private:
		shared_ptr<Type>	m_type;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_FIELD_H