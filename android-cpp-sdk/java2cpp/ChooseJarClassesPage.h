#ifndef JAVA2CPP_CHOOSE_JAR_CLASSES_PAGE_H
#define JAVA2CPP_CHOOSE_JAR_CLASSES_PAGE_H

namespace model {
	class Namespace;
} //namespace model

class ClassTreeModel;

#include "ui_ChooseJarClassesPage.h"

class ChooseJarClassesPage
	: public QWizardPage
	, protected Ui::ChooseJarClassesPage
{
	Q_OBJECT
public:
	ChooseJarClassesPage(QWidget *parent=0);
	~ChooseJarClassesPage();

	shared_ptr<model::Namespace>	getImportedJar() const;

public slots:
	void							setRootNamespace(shared_ptr<model::Namespace> rootNS);

private:
	shared_ptr<model::Namespace>	m_ImportedJar;
};

#endif //JAVA2CPP_CHOOSE_JAR_CLASSES_PAGE_H
