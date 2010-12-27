#include "Precompile.h"
#include "CXXGeneratePage.h"
#include "CPPCodeWriter.h"

CXXGeneratePage::CXXGeneratePage(shared_ptr<model::Namespace> const &rns, QWidget *parent)
: QWizardPage(parent)
, m_Done(false)
, m_RootNS(rns)
{
	setupUi(this);
	connect(m_DirChoose, SIGNAL(clicked()), SLOT(onBrowseDir()));
}

CXXGeneratePage::~CXXGeneratePage()
{
}

bool CXXGeneratePage::isComplete() const
{
	return m_Done;
}

void CXXGeneratePage::setWorkAmmount(std::size_t wa)
{
	m_ImportProgress->setRange(0, wa);
	qApp->processEvents(QEventLoop::AllEvents, 100);
}

void CXXGeneratePage::setWorkComplete(std::size_t wa)
{
	m_ImportProgress->setValue(wa);
	qApp->processEvents(QEventLoop::AllEvents, 100);
}

void CXXGeneratePage::onBrowseDir()
{
	m_FSDirPath=filesystem::path(
		QFileDialog::getExistingDirectory(this, tr("Choose a folder to generate code in:")).toStdString()
	);
	
	m_DirPath->setText(m_FSDirPath.native_file_string().c_str());
		
	CPPCodeWriter cppCodeWriter(m_RootNS,m_FSDirPath);
	cppCodeWriter.workAmmount().connect(bind(&CXXGeneratePage::setWorkAmmount, this, _1));
	cppCodeWriter.workProgress().connect(bind(&CXXGeneratePage::setWorkComplete, this, _1));

	cppCodeWriter();

	m_Done=true;
	emit completeChanged();
}