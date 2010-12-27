#ifndef JAVA2CPP_CLASS_MEMBERS_MODEL_H
#define JAVA2CPP_CLASS_MEMBERS_MODEL_H

namespace model {
	class Class;
} //namespace model

class ClassMembersModel
	: public QAbstractListModel 
{
	Q_OBJECT
public:
	ClassMembersModel(QObject *parent=0);
	~ClassMembersModel();

public slots:
	void								setClass(shared_ptr<model::Class> c);

public:
	shared_ptr<model::Class> 			getClass() const;

protected:
	QVariant							data(const QModelIndex &index, int role) const;
	QVariant							headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const;
	int									rowCount(const QModelIndex &parent = QModelIndex()) const;

private:
	shared_ptr<model::Class>	m_pClass;
};

#endif //JAVA2CPP_CLASS_MEMBERS_MODEL_H