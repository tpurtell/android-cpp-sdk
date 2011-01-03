#ifndef JAVA2CPP_CPP_CODE_GENERATOR_H
#define JAVA2CPP_CPP_CODE_GENERATOR_H

namespace model {

	class Namespace;
	class Class;
	class Entity;

} //namespace model

BOOST_PARAMETER_KEYWORD(tag, cpp_cmnt_eq_width)
BOOST_PARAMETER_KEYWORD(tag, cpp_generator)

class CPPCodeGenerator
{
protected:
	static std::size_t				s_default_comment_eq_width;
	static std::string				s_default_generator;

public:
	
	CPPCodeGenerator(shared_ptr<model::Namespace> const &rns, shared_ptr<model::Class> const &c);

	
	template <typename Args>
	CPPCodeGenerator(shared_ptr<model::Namespace> const &rns, shared_ptr<model::Class> const &c, Args const &args)
		: m_RootNS(rns)
		, m_Class(c)
		, m_comment_eq_width(args[cpp_cmnt_eq_width] | s_default_comment_eq_width)
		, m_generator(args[cpp_generator] | s_default_generator)
	{
	}

	~CPPCodeGenerator();

	std::ostream&					operator()(std::ostream &os) const;

protected:
	void							collect_class_dependencies(shared_ptr<model::Entity> entity, std::set< shared_ptr<model::Class> > &dependencies) const;
	void							collect_class_bases(shared_ptr<model::Class> const &clazz, std::set< shared_ptr<model::Class> > &dependencies) const;
	std::string						transform_method_name(std::string const &original) const;


	std::ostream&					indent(std::ostream &os, std::size_t n) const;
	std::ostream&					begin_comment(std::ostream &os) const;
	std::ostream&					end_comment(std::ostream &os) const;
	std::ostream&					write_header(std::ostream &os) const;
	std::ostream&					write_class(std::ostream &os, std::size_t indent_pos, shared_ptr<model::Class> const &clazz) const;
	std::ostream&					write_class_creators(std::ostream &os, shared_ptr<model::Class> const &clazz) const;
	std::ostream&					write_class_definitions(std::ostream &os, shared_ptr<model::Class> const &clazz) const;
	

private:
	shared_ptr<model::Namespace>	m_RootNS;
	shared_ptr<model::Class>		m_Class;

	std::size_t						m_comment_eq_width;
	std::string						m_generator;
};

#endif //JAVA2CPP_CPP_CODE_GENERATOR_H