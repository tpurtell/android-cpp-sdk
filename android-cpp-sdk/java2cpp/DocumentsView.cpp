#include "Precompile.h"
#include "DocumentsView.h"

DocumentsView::DocumentsView(QWidget *parent/* =0 */)
: QTabWidget(parent)
{
	setTabsClosable(true);
}

DocumentsView::~DocumentsView()
{
}