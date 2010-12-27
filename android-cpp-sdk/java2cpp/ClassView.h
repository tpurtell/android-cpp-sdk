#ifndef JAVA2CPP_CLASS_VIEW_H
#define JAVA2CPP_CLASS_VIEW_H

#include "ui_ClassView.h"

namespace model {
	class Namespace;
	class Class;
} //namespace model

class ClassTreeView;
class ClassMembersView;
class ClassTreeModel;
class ClassMembersModel;

class ClassView
	: public QWidget
	, protected Ui::ClassView
{
	Q_OBJECT
public:
	ClassView(QWidget *parent=0);
	~ClassView();

	void							setRootNamespace(shared_ptr<model::Namespace> const &rns);
	shared_ptr<model::Namespace> 	getRootNamespace() const;

signals:
	void							classDoubleClicked(shared_ptr<model::Class> selClass);

protected slots:
	void							onDoubleClicked(const QModelIndex &mi);
	

private:
	QSplitter			*m_Splitter;
	ClassTreeModel		*m_ClassTreeModel;
	ClassTreeView		*m_ClassTreeView;
	ClassMembersModel	*m_ClassMembersModel;
	ClassMembersView	*m_ClassMembersView;
};

#endif //JAVA2CPP_CLASS_VIEW_H