#include "Precompile.h"
#include "ChooseJarPage.h"
#include "JarScanner.h"


ChooseJarPage::ChooseJarPage(QWidget *parent)
: QWizardPage(parent)
{
	setupUi(this);
	connect(m_jarChoose, SIGNAL(clicked()), SLOT(onBrowseJar()));
}

ChooseJarPage::~ChooseJarPage()
{
}

bool ChooseJarPage::isComplete() const
{
	return m_JarPath.exists();
}

void ChooseJarPage::setWorkAmmount(std::size_t wa)
{
	m_ImportProgress->setRange(0, wa);
	qApp->processEvents(QEventLoop::AllEvents, 100);
}

void ChooseJarPage::setWorkComplete(std::size_t wa)
{
	m_ImportProgress->setValue(wa);
	qApp->processEvents(QEventLoop::AllEvents, 100);
}

void ChooseJarPage::onBrowseJar()
{
	m_JarPath=QFileInfo(QFileDialog::getOpenFileName(this, tr("Open jar file"), ".", tr("java package files(*.jar)")));
	
	if(m_JarPath.exists())
	{
		m_jarPath->setText(m_JarPath.absoluteFilePath());

		JarScanner jarScanner(m_JarPath);
		jarScanner.workAmmount().connect(bind(&ChooseJarPage::setWorkAmmount, this, _1));
		jarScanner.workProgress().connect(bind(&ChooseJarPage::setWorkComplete, this, _1));

		m_ImportedJar=jarScanner();

		emit jarImported(m_ImportedJar);

		emit completeChanged();
	}
}