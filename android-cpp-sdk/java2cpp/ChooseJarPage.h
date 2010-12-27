#ifndef JAVA2CPP_CHOOSE_JAR_PAGE_H
#define JAVA2CPP_CHOOSE_JAR_PAGE_H

#include "ui_ChooseJarPage.h"

namespace model {
	class Namespace;
} //namespace model

class ChooseJarPage
	: public QWizardPage
	, protected Ui::ChooseJarPage
{
	Q_OBJECT
public:
	ChooseJarPage(QWidget *parent=0);
	~ChooseJarPage();

protected:
	bool					isComplete() const;
	void					setWorkAmmount(std::size_t wa);
	void					setWorkComplete(std::size_t wa);

protected slots:
	void					onBrowseJar();

signals:
	void					jarImported(shared_ptr<model::Namespace> rootNS);

private:
	QFileInfo						m_JarPath;
	shared_ptr<model::Namespace>	m_ImportedJar;


};

#endif //JAVA2CPP_CHOOSE_JAR_PAGE_H