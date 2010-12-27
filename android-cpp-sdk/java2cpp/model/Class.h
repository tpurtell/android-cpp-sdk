#ifndef JAVA2CPP_MODEL_CLASS_H
#define JAVA2CPP_MODEL_CLASS_H

#include "Entity.h"
#include "Method.h"
#include "Field.h"

namespace model {

	class Namespace;
	class Class
		: public Entity
	{
		friend class Entity;

		template <typename Args>
		Class(shared_ptr<Entity> const &p, Args const &args)
			: Entity(p, args)
		{
		}
	
	public:
		~Class();

		Entity::eKind				get_kind() const;
		
		std::string					get_java_class_name() const;
		std::string					get_java_class_path() const;
		std::string					get_java_signature() const;
		std::string					get_cxx_class_name() const;
		std::string					get_cxx_include_path() const;
		

		bool						is_nested() const;
		shared_ptr<Class>			get_parent_class() const;
		shared_ptr<Class>			get_top_parent_class() const;
		shared_ptr<Namespace>		get_namespace() const;
		
		shared_ptr<Method>			add_method(std::string const &n);
		std::size_t					get_methods_count() const;
		shared_ptr<Method>			get_method(std::size_t m) const;

		shared_ptr<Field>			add_field(std::string const &n);
		std::size_t					get_fields_count() const;
		shared_ptr<Field>			get_field(std::size_t f) const;
		

		typedef multi_index_container
		<
			shared_ptr<Method>,
			multi_index::indexed_by
			<
				multi_index::random_access
				<
					multi_index::tag<order_tag>
				>,
				multi_index::hashed_unique
				<
					multi_index::tag<identity_tag>,
					multi_index::identity< shared_ptr<Method> >
				>,
				multi_index::ordered_non_unique
				<
					multi_index::tag<name_tag>,
					BOOST_MULTI_INDEX_CONST_MEM_FUN(ClassMember, std::string const&, get_name)
				>
			>
		> methods_t;

		typedef multi_index_container
		<
			shared_ptr<Field>,
			multi_index::indexed_by
			<
				multi_index::random_access
				<
					multi_index::tag<order_tag>
				>,
				multi_index::hashed_unique
				<
					multi_index::tag<identity_tag>,
					multi_index::identity< shared_ptr<Field> >
				>,
				multi_index::hashed_unique
				<
					multi_index::tag<name_tag>,
					BOOST_MULTI_INDEX_CONST_MEM_FUN(ClassMember, std::string const&, get_name)
				>
			>
		> fields_t;

	private:
		methods_t	m_methods;
		fields_t	m_fields;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_CLASS_H