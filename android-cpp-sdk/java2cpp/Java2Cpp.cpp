#include "Precompile.h"
#include "Java2Cpp.h"
#include "DocumentsView.h"
#include "ClassView.h"
#include "ChooseJarPage.h"
#include "ChooseJarClassesPage.h"
#include "CXXGeneratePage.h"
#include "CPPSourceCodeView.h"
#include "CPPCodeGenerator.h"
#include "model/Class.h"



Java2Cpp::Java2Cpp(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	setupUi(this);

	m_MenuBar=new QMenuBar(this);
	m_FileMenu=new QMenu(tr("File"));
	m_FileNew=m_FileMenu->addAction(tr("New"));
	m_FileOpen=m_FileMenu->addAction(tr("Open"));
	m_FileSave=m_FileMenu->addAction(tr("Save"));
	m_FileClose=m_FileMenu->addAction(tr("Close"));
	m_FileImportJar=m_FileMenu->addAction(tr("Import JAR"));
	m_GenerateCPP=m_FileMenu->addAction(tr("Generate C++"));

	m_Layout->insertWidget(0,m_MenuBar);
	m_MenuBar->addMenu(m_FileMenu);

	m_Splitter=new QSplitter(Qt::Horizontal,0);
	m_Splitter->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	m_ClassView=new ClassView();
	m_Splitter->addWidget(m_ClassView);
	m_DocumentsView=new DocumentsView();
	m_Splitter->addWidget(m_DocumentsView);
	m_MainLayout->insertWidget(0,m_Splitter);
	m_Splitter->setStretchFactor(0,0);
	m_Splitter->setStretchFactor(1,1);

	connect(m_ClassView, SIGNAL(classDoubleClicked(shared_ptr<model::Class>)), SLOT(onShowSourceCode(shared_ptr<model::Class>)));
	connect(m_DocumentsView, SIGNAL(tabCloseRequested(int)), SLOT(onCloseTab(int)));
	connect(m_FileImportJar, SIGNAL(triggered()), SLOT(onImportJarPackage()));
	connect(m_GenerateCPP, SIGNAL(triggered()), SLOT(onGenerateCPP()));
	connect(m_AcceptReject, SIGNAL(accepted()), SLOT(accept()));
	connect(m_AcceptReject, SIGNAL(rejected()), SLOT(reject()));
}

Java2Cpp::~Java2Cpp()
{

}

void Java2Cpp::onImportJarPackage()
{
	QWizard importJarWizard(this);
	ChooseJarPage *chooseJarPage=new ChooseJarPage();
	ChooseJarClassesPage *chooseJarClassesPage=new ChooseJarClassesPage();
	connect(chooseJarPage, SIGNAL(jarImported(shared_ptr<model::Namespace>)), chooseJarClassesPage, SLOT(setRootNamespace(shared_ptr<model::Namespace>)));
	
	importJarWizard.addPage(chooseJarPage);
	importJarWizard.addPage(chooseJarClassesPage);

	importJarWizard.setWindowTitle(tr("Import classes from jar package :"));
	if(importJarWizard.exec())
	{
		m_RootNS=chooseJarClassesPage->getImportedJar();
		m_ClassView->setRootNamespace(m_RootNS);
	}
}

void Java2Cpp::onGenerateCPP()
{
	QWizard generateCXXWizard(this);
	CXXGeneratePage *cxxGeneratePage=new CXXGeneratePage(m_RootNS);
	generateCXXWizard.addPage(cxxGeneratePage);
	generateCXXWizard.setWindowTitle(tr("Generate c++ code :"));
	generateCXXWizard.exec();
}

void  Java2Cpp::onShowSourceCode(shared_ptr<model::Class> sc)
{
	if(shared_ptr<model::Class> pTopParent=sc->get_top_parent_class())
		sc=pTopParent;


	m_DocumentsView->setCurrentIndex(
		m_DocumentsView->addTab(
			new CPPSourceCodeView(
				shared_ptr<CPPCodeGenerator>(new CPPCodeGenerator(m_RootNS,sc))
			),
			QString(sc->get_java_class_name().c_str())
		)
	);
}

void Java2Cpp::onCloseTab(int index)
{
	m_DocumentsView->removeTab(index);
}