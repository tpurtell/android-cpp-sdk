#ifndef JAVA2CPP_CXX_GENERATE_PAGE_H
#define JAVA2CPP_CXX_GENERATE_PAGE_H

#include "ui_CXXGeneratePage.h"

namespace model {
	class Namespace;
} //namespace model

class CXXGeneratePage
	: public QWizardPage
	, protected Ui::CXXGeneratePage
{
	Q_OBJECT
public:
	CXXGeneratePage(shared_ptr<model::Namespace> const &rns, QWidget *parent=0);
	~CXXGeneratePage();

protected:
	bool					isComplete() const;
	void					setWorkAmmount(std::size_t wa);
	void					setWorkComplete(std::size_t wa);

protected slots:
	void					onBrowseDir();
	void					onGenerate();



private:
	bool							m_Done;
	filesystem::path				m_FSDirPath;
	shared_ptr<model::Namespace>	m_RootNS;
};

#endif //JAVA2CPP_CHOOSE_JAR_PAGE_H