#ifndef JAVA2CPP_MODEL_PROPER_CLASS_METHODS_H
#define JAVA2CPP_MODEL_PROPER_CLASS_METHODS_H

#include "Class.h"

namespace model {
	
	class ProperClassMethods
	{
	public:

		struct order_tag {};
		struct signature_tag {};

		struct proper_method
		{
			proper_method(shared_ptr<Method> const &m);

			std::string signature() const;

			shared_ptr<Method> m_method;
			std::string m_proper_name;
		};

		typedef multi_index_container
		<
			proper_method,
			multi_index::indexed_by
			<
				multi_index::random_access
				<
					multi_index::tag<order_tag>
				>,
				multi_index::hashed_unique
				<
					multi_index::tag<signature_tag>,
					BOOST_MULTI_INDEX_CONST_MEM_FUN(proper_method, std::string, signature)
				>
			>
		> methods_t;

		ProperClassMethods(shared_ptr<Class> const &clazz);

		std::size_t		get_methods_count() const;
		proper_method	get_method(std::size_t idx) const;

	private:
		methods_t		m_methods;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_PROPER_CLASS_METHODS_H