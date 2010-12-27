#ifndef JAVA2CPP_JAVA_CLASS_SCANNER_H
#define JAVA2CPP_JAVA_CLASS_SCANNER_H

namespace model {

	class Class;
	class Namespace;

} //namespace model

namespace {
	template <typename Iterator>
	struct jclass_method_parser;
}

class JavaClassScanner
{
	template <typename Iterator>
	friend struct jclass_method_parser;

public:
	JavaClassScanner(shared_ptr<model::Namespace> const &rns, shared_ptr<model::Class> const &c, shared_ptr<char> const &cd);
	~JavaClassScanner();
	
	bool							scan();

private:
	shared_ptr<model::Namespace>	m_RootNS;
	shared_ptr<model::Class>		m_Class;
	shared_ptr<char>				m_ClassData;
};

#endif //JAVA2CPP_JAVA_CLASS_SCANNER_H