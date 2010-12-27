#ifndef JAVA2CPP_CLASS_TREE_MODEL_H
#define JAVA2CPP_CLASS_TREE_MODEL_H

namespace model {
	class Namespace;
	class Class;
} //namespace model

class ClassTreeModel
	: public QAbstractItemModel
{
	Q_OBJECT
public:
	ClassTreeModel(QObject *parent=0);
	~ClassTreeModel();

	void									setRootNamespace(shared_ptr<model::Namespace> const &rootNS);
	shared_ptr<model::Namespace> const&		getRootNamespace() const;

	shared_ptr<model::Class>				getClass(const QModelIndex &mi) const;


protected:
	QVariant			data(const QModelIndex &index, int role) const;
	Qt::ItemFlags		flags(const QModelIndex &index) const;
	QVariant			headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const;
	QModelIndex			index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	QModelIndex			parent(const QModelIndex &child) const;
	int					rowCount(const QModelIndex &parent = QModelIndex()) const;
	int					columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
	shared_ptr<model::Namespace>	m_pRootNS;
};

#endif //JAVA2CPP_CLASS_TREE_MODEL_H