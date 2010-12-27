#ifndef JAVA2CPP_JAVA2CPP_H
#define JAVA2CPP_JAVA2CPP_H

#include "ui_Java2Cpp.h"

namespace model {
	class Namespace;
	class Class;
} //namespace model

class DocumentsView;
class ClassView;


class Java2Cpp
	: public QDialog
	, protected Ui::Java2Cpp
{
	Q_OBJECT
public:
	Java2Cpp(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Java2Cpp();

protected slots:
	void							onImportJarPackage();
	void							onGenerateCPP();
	void							onShowSourceCode(shared_ptr<model::Class> sc);
	void							onCloseTab(int index);

private:
	QMenuBar						*m_MenuBar;
	QMenu							*m_FileMenu;
	QAction							*m_FileNew;
	QAction							*m_FileOpen;
	QAction							*m_FileSave;
	QAction							*m_FileClose;
	QAction							*m_FileImportJar;
	QAction							*m_GenerateCPP;
	
	QSplitter						*m_Splitter;
	ClassView						*m_ClassView;
	DocumentsView					*m_DocumentsView;
	shared_ptr<model::Namespace>	m_RootNS;
};

#endif //JAVA2CPP_JAVA2CPP_H
