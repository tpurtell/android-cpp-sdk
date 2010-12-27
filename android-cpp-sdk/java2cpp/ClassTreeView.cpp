#include "Precompile.h"
#include "ClassTreeView.h"
#include "ClassTreeModel.h"

ClassTreeView::ClassTreeView(QWidget *parent)
: QTreeView(parent)
{
	setExpandsOnDoubleClick(false);
	setAlternatingRowColors(false);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setSelectionBehavior(QAbstractItemView::SelectRows);
}

ClassTreeView::~ClassTreeView()
{
}

void ClassTreeView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
	QTreeView::selectionChanged(selected,deselected);
	emit classSelected(shared_ptr<model::Class>());
	if(!selected.indexes().isEmpty())
	{
		if(ClassTreeModel *pClassTreeModel=dynamic_cast<ClassTreeModel*>(model()))
		{
			if(shared_ptr<model::Class> pClass=pClassTreeModel->getClass(selected.indexes().first()))
				emit classSelected(pClass);
		}
	}
}
