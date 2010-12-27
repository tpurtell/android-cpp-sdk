#include "Precompile.h"
#include "Entity.h"

namespace model {

	Entity::~Entity()
	{
	}

	shared_ptr<Entity> Entity::get_handle() const
	{
		return const_cast<Entity*>(this)->shared_from_this();
	}

	shared_ptr<Entity> Entity::get_parent() const
	{
		return m_parent.lock();
	}

	std::string const& Entity::get_name() const
	{
		return m_name;
	}

	shared_ptr<Entity> Entity::find_entity(std::string const &ep)
	{
		iterator_range<std::string::const_iterator> firstDot=algorithm::find_first(ep,".");

		std::string strName(
			ep.begin(),
			firstDot.empty()?ep.end():firstDot.begin()
		);

		children_t::index<name_tag>::type &children_by_name=m_children.get<name_tag>();
		children_t::index<name_tag>::type::const_iterator itChild=children_by_name.find(strName);

		if(itChild!=children_by_name.end())
		{
			if(firstDot.empty())
				return *itChild;
			return (*itChild)->find_entity(std::string(firstDot.end(),ep.end()));
		}
		return shared_ptr<Entity>();
	}
	
	shared_ptr<Entity const> Entity::find_entity(std::string const &ep) const
	{
		return const_cast<Entity*>(this)->find_entity(ep);
	}

	std::size_t Entity::get_child_count() const
	{
		return m_children.size();
	}


	shared_ptr<Entity> Entity::get_child(std::size_t idx) const
	{
		BOOST_ASSERT(idx>=0 && idx<m_children.size());
		return m_children[idx];
	}

	std::size_t Entity::get_child_pos(shared_ptr<Entity> const &child) const
	{
		children_t::index<identity_tag>::type const &children_by_identity=m_children.get<identity_tag>();
		children_t::index<identity_tag>::type::const_iterator itChild=children_by_identity.find(child);
		if(itChild!=children_by_identity.end())
			return m_children.project<order_tag>(itChild)-m_children.begin();
		return 0;
	}

	std::size_t Entity::get_pos() const
	{
		if(shared_ptr<Entity> pParent=get_parent())
			return pParent->get_child_pos(const_cast<Entity*>(this)->shared_from_this());
		return 0;
	}

	iterator_range<Entity::children_by_kind_t::const_iterator> Entity::get_children_of_kind(eKind k) const
	{
		return make_iterator_range(
			m_children.get<kind_tag>().lower_bound(k),
			m_children.get<kind_tag>().upper_bound(k)
		);
	}
		
} //namespace model