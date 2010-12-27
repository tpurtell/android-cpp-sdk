#include "Precompile.h"
#include "Class.h"
#include "ClassMember.h"

namespace model {

	ClassMember::ClassMember(shared_ptr<Class> const &c, std::string const &n)
		: m_class(c)
		, m_name(n)
		, m_access_flags(kAccessFlagsSize)
	{
	}

	ClassMember::~ClassMember()
	{
	}

	std::string const& ClassMember::get_name() const
	{
		return m_name;
	}

	shared_ptr<Class> ClassMember::get_class() const
	{
		return m_class.lock();
	}

	std::string	ClassMember::get_display_name() const
	{
		return m_name;
	}
	
	

	bool ClassMember::test_access_flag(eAccessFlags flag) const
	{
		return m_access_flags.test(flag);
	}

	void ClassMember::set_access_flag(eAccessFlags flag, bool s)
	{
		m_access_flags.set(flag,s);
	}

} //namespace model
