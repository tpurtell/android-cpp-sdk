#include "Precompile.h"
#include "CPPSourceCodeView.h"
#include "CPPCodeGenerator.h"

CPPSourceCodeView::CPPSourceCodeView(shared_ptr<CPPCodeGenerator> const &cg, QWidget *parent)
: QTextEdit(parent)
, m_CodeGen(cg)
{
	setTabStopWidth(24);
	std::ostringstream oss;
	cg->operator ()(oss);
	setPlainText(oss.str().c_str());
}

CPPSourceCodeView::~CPPSourceCodeView()
{

}