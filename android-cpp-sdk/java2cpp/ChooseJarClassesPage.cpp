#include "Precompile.h"
#include "ChooseJarClassesPage.h"
#include "model/Namespace.h"
#include "ClassTreeModel.h"

ChooseJarClassesPage::ChooseJarClassesPage(QWidget *parent)
: QWizardPage(parent)
{
	setupUi(this);
}

ChooseJarClassesPage::~ChooseJarClassesPage()
{
}

shared_ptr<model::Namespace> ChooseJarClassesPage::getImportedJar() const
{
	return m_ImportedJar;
}

void ChooseJarClassesPage::setRootNamespace(shared_ptr<model::Namespace> rootNS)
{
	m_ImportedJar=rootNS;
	m_ClassView->setRootNamespace(m_ImportedJar);
}