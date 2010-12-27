#ifndef JAVA2CPP_CLASS_TREE_VIEW_H
#define JAVA2CPP_CLASS_TREE_VIEW_H

namespace model {
	class Class;
} //namespace model

class ClassTreeView
	: public QTreeView
{
	Q_OBJECT
public:
	ClassTreeView(QWidget *parent=0);
	~ClassTreeView();

signals:
	void			classSelected(shared_ptr<model::Class> selClass);

protected:
	void			selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:

};

#endif //JAVA2CPP_CLASS_TREE_VIEW_H
