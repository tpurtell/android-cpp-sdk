#ifndef JAVA2CPP_DOCUMENTS_VIEW_H
#define JAVA2CPP_DOCUMENTS_VIEW_H

class DocumentsView
	: public QTabWidget
{
	Q_OBJECT
public:
	DocumentsView(QWidget *parent=0);
	~DocumentsView();
};

#endif //JAVA2CPP_DOCUMENTS_VIEW_H