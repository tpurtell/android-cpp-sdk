#include "Precompile.h"
#include "ClassView.h"
#include "ClassTreeView.h"
#include "ClassMembersView.h"
#include "ClassTreeModel.h"
#include "ClassMembersModel.h"


ClassView::ClassView(QWidget *parent)
: QWidget(parent)
{
	setupUi(this);
	
	m_Splitter=new QSplitter(Qt::Vertical, 0);
	m_Layout->addWidget(m_Splitter);
	

	m_ClassTreeModel=new ClassTreeModel(this);
	m_ClassTreeView=new ClassTreeView();
	m_ClassTreeView->setModel(m_ClassTreeModel);
	m_Splitter->addWidget(m_ClassTreeView);
	
	m_ClassMembersModel=new ClassMembersModel(this);
	m_ClassMembersView=new ClassMembersView();
	m_ClassMembersView->setModel(m_ClassMembersModel);
	m_Splitter->addWidget(m_ClassMembersView);

	connect(m_ClassTreeView, SIGNAL(classSelected(shared_ptr<model::Class>)), m_ClassMembersModel, SLOT(setClass(shared_ptr<model::Class>)));
	connect(m_ClassTreeView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onDoubleClicked(const QModelIndex&)));
}

ClassView::~ClassView()
{
}

void ClassView::setRootNamespace(shared_ptr<model::Namespace> const &rns)
{
	m_ClassTreeModel->setRootNamespace(rns);
}


shared_ptr<model::Namespace> ClassView::getRootNamespace() const
{
	return m_ClassTreeModel->getRootNamespace();
}

void ClassView::onDoubleClicked(const QModelIndex &mi)
{
	if(shared_ptr<model::Class> pClass=m_ClassTreeModel->getClass(mi))
		emit classDoubleClicked(pClass);
}
