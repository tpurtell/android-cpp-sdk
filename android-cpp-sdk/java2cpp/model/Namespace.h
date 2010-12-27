#ifndef JAVA2CPP_MODEL_NAMESPACE_H
#define JAVA2CPP_MODEL_NAMESPACE_H

#include "Entity.h"

namespace model {

	class Namespace
		: public Entity
	{
		friend class Entity;

		template <typename Args>
		Namespace(shared_ptr<Entity> const &p, Args const &args)
			: Entity(p, args)
		{
		}

	public:

		~Namespace();
		
		Entity::eKind			get_kind() const;

		std::string				get_java_class_name() const;
		std::string				get_java_class_path() const;
		std::string				get_cxx_class_name() const;

		shared_ptr<Namespace>	get_parent_namespace() const;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_NAMESPACE_H