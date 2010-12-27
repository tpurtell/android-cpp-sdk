#ifndef JAVA2CPP_MODEL_ENTITY_H
#define JAVA2CPP_MODEL_ENTITY_H

namespace model {

	BOOST_PARAMETER_KEYWORD(tag, name)

	class Entity
		: public enable_shared_from_this2<Entity>
		, protected noncopyable
	{
	public:
		typedef enum
		{
			kNamespace,
			kClass
		} eKind;
	
	protected:
		
		template <typename Args>
		Entity(shared_ptr<Entity> const &p, Args const &args)
			: m_parent(p)
			, m_name(args[name])
		{
		}

	public:
		virtual ~Entity();

		template <typename EntityType, typename Args>
		static shared_ptr<EntityType>	create(Args const &args)
		{
			return shared_ptr<EntityType>(new EntityType(shared_ptr<Entity>(), args));
		}

		shared_ptr<Entity>			get_handle() const;


		shared_ptr<Entity>			get_parent() const;
		std::string const&			get_name() const;
		virtual eKind				get_kind() const = 0;

		template<typename EntityType, typename Args>
		shared_ptr<EntityType>		add_entity(Args const &args)
		{
			shared_ptr<EntityType> childEntity(new EntityType(shared_from_this(), args));
			return m_children.push_back(shared_ptr<Entity>(childEntity)).second?
				childEntity:shared_ptr<EntityType>();
		}

		shared_ptr<Entity>			find_entity(std::string const &ep);
		shared_ptr<Entity const>	find_entity(std::string const &ep) const;

		std::size_t					get_child_count() const;
		shared_ptr<Entity>			get_child(std::size_t idx) const;
		std::size_t					get_child_pos(shared_ptr<Entity> const &child) const;
		std::size_t					get_pos() const;

		virtual std::string			get_java_class_name() const = 0;
		virtual std::string			get_java_class_path() const = 0;
		virtual std::string			get_cxx_class_name() const = 0;



		template <typename Visitor>
		void visit(Visitor visitor)
		{
			visitor(shared_from_this());
			BOOST_FOREACH(shared_ptr<Entity> child, m_children) child->visit(visitor);
		}

		struct kind_extractor
		{
			typedef eKind result_type;
			eKind operator()(shared_ptr<Entity> const &e) const { return e->get_kind(); }
		};

		struct order_tag {};
		struct identity_tag {};
		struct name_tag {};
		struct kind_tag {};

		typedef multi_index_container
		<
			shared_ptr<Entity>,
			multi_index::indexed_by
			<
				multi_index::random_access
				<
					multi_index::tag<order_tag>
				>,
				multi_index::hashed_unique
				<
					multi_index::tag<identity_tag>,
					multi_index::identity< shared_ptr<Entity> >
				>,
				multi_index::hashed_unique
				<
					multi_index::tag<name_tag>,
					BOOST_MULTI_INDEX_CONST_MEM_FUN(Entity, std::string const&, get_name)
				>,
				multi_index::ordered_non_unique
				<
					multi_index::tag<kind_tag>,
					kind_extractor
				>
			>
		> children_t;

		typedef children_t::index<kind_tag>::type	children_by_kind_t;
				
		
		iterator_range<children_by_kind_t::const_iterator> get_children_of_kind(eKind k) const;
		
	protected:
		weak_ptr<Entity>		m_parent;
		std::string				m_name;
		children_t				m_children;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_ENTITY_H
