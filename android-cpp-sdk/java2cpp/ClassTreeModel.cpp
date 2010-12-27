#include "Precompile.h"
#include "ClassTreeModel.h"
#include "model/Namespace.h"
#include "model/Class.h"


ClassTreeModel::ClassTreeModel(QObject *parent)
: QAbstractItemModel(parent)
{
}

ClassTreeModel::~ClassTreeModel()
{
}

void ClassTreeModel::setRootNamespace(shared_ptr<model::Namespace> const &rootNS)
{
	beginResetModel();
	m_pRootNS=rootNS;
	reset();
	endResetModel();
}

shared_ptr<model::Namespace> const& ClassTreeModel::getRootNamespace() const
{
	return m_pRootNS;
}

shared_ptr<model::Class> ClassTreeModel::getClass(QModelIndex const &mi) const
{
	if(model::Entity *entityItem=reinterpret_cast<model::Entity*>(mi.internalPointer()))
		if(shared_ptr<model::Class> pClass=shared_ptr<model::Class>(entityItem->get_handle(),detail::dynamic_cast_tag()))
			return pClass;
	return shared_ptr<model::Class>();
}

QVariant ClassTreeModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();

	model::Entity *entityItem=reinterpret_cast<model::Entity*>(index.internalPointer());
	BOOST_ASSERT(entityItem);

	if(role==Qt::DisplayRole)
	{
		switch(index.column())
		{
		case 0:
			return QString(entityItem->get_name().c_str());
		}
	}
	else
	if(role==Qt::DecorationRole)
	{
		switch(index.column())
		{
		case 0:
			{
				switch(entityItem->get_kind())
				{
				case model::Entity::kNamespace:
					return QIcon(":/icons/namespace.ico");
				case model::Entity::kClass:
					return QIcon(":/icons/class.ico");
				//case model::Entity::kMethod:
				//	return QIcon(":/icons/method.ico");
				//case model::Entity::kField:
				//	return QIcon(":/icons/field.ico");

				}
			}
			break;
		}
	}
	return QVariant();
}

Qt::ItemFlags ClassTreeModel::flags(const QModelIndex &index) const
{
	if(!index.isValid())
		return 0;
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
}

QVariant ClassTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(orientation==Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch(section)
		{
		case 0:
			return tr("Name");
		}
	}
	return QVariant();
}

QModelIndex ClassTreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if(!hasIndex(row, column, parent))
		return QModelIndex();
	
	model::Entity *parentEntity(0);

	if(!parent.isValid())
		parentEntity=m_pRootNS.get();
	else
		parentEntity=reinterpret_cast<model::Entity*>(parent.internalPointer());

	BOOST_ASSERT(parentEntity);

	model::Entity *childEntity=parentEntity->get_child(row).get();
	if (childEntity)
		return createIndex(row, column, childEntity);
	return QModelIndex();
}

QModelIndex ClassTreeModel::parent(const QModelIndex &child) const
{
	if(!child.isValid())
		return QModelIndex();

	model::Entity *childEntity=reinterpret_cast<model::Entity*>(child.internalPointer());
	model::Entity *parentEntity=childEntity->get_parent().get();
	
	if(!parentEntity || parentEntity==m_pRootNS.get())
		return QModelIndex();

	return createIndex(parentEntity->get_pos(), 0, parentEntity);
}

int	ClassTreeModel::rowCount(const QModelIndex &parent) const
{
	if(!m_pRootNS)
		return 0;

	if(parent.column()>0)
		return 0;
		
	model::Entity *parentEntity(0);
	
	if(!parent.isValid())
		parentEntity=m_pRootNS.get();
	else
		parentEntity=reinterpret_cast<model::Entity*>(parent.internalPointer());

	BOOST_ASSERT(parentEntity);
	
	return parentEntity->get_child_count();
}

int ClassTreeModel::columnCount(const QModelIndex &parent) const
{
	return 1;
}