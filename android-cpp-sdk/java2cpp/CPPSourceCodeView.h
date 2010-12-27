#ifndef JAVA2CPP_CPP_SOURCE_CODE_VIEW_H
#define JAVA2CPP_CPP_SOURCE_CODE_VIEW_H

class CPPCodeGenerator;

class CPPSourceCodeView
	: public QTextEdit
{
	Q_OBJECT
public:
	CPPSourceCodeView(shared_ptr<CPPCodeGenerator> const &cg, QWidget *parent=0);
	~CPPSourceCodeView();
private:
	shared_ptr<CPPCodeGenerator>	m_CodeGen;
};

#endif //JAVA2CPP_CPP_SOURCE_CODE_VIEW_H