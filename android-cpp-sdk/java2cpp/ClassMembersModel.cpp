#include "Precompile.h"
#include "ClassMembersModel.h"
#include "model/Class.h"

ClassMembersModel::ClassMembersModel(QObject *parent/* =0 */)
: QAbstractListModel(parent)
{
}

ClassMembersModel::~ClassMembersModel()
{
}

void ClassMembersModel::setClass(shared_ptr<model::Class> c)
{
	beginResetModel();
	m_pClass=c;
	reset();
	endResetModel();
}

shared_ptr<model::Class> ClassMembersModel::getClass() const
{
	return m_pClass;
}

QVariant ClassMembersModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();

	BOOST_ASSERT(m_pClass);

	shared_ptr<model::Method> pClassMethod=
		index.row()<m_pClass->get_methods_count()?
		m_pClass->get_method(index.row()):
		shared_ptr<model::Method>();
	
	shared_ptr<model::Field> pClassField=
		index.row()<m_pClass->get_methods_count()?
		shared_ptr<model::Field>():
		m_pClass->get_field(index.row()-m_pClass->get_methods_count());

	shared_ptr<model::ClassMember> pClassMember=
		pClassMethod?
			shared_ptr<model::ClassMember>(pClassMethod):
			shared_ptr<model::ClassMember>(pClassField);

	BOOST_ASSERT(pClassMember);

	
	if(role==Qt::DisplayRole)
	{
		switch(index.column())
		{
		case 0:
			return QString(pClassMember->get_display_name().c_str());
		}
	}
	else
	if(role==Qt::DecorationRole)
	{
		switch(index.column())
		{
		case 0:
			{
				if(pClassMethod)
					return QIcon(":/icons/method.ico");
				else
				if(pClassField)
					return QIcon(":/icons/field.ico");
			}
			break;
		}
	}
	return QVariant();

}

int ClassMembersModel::rowCount(const QModelIndex &parent) const
{
	if(m_pClass)
		return m_pClass->get_methods_count() + m_pClass->get_fields_count();
	return 0;
}

QVariant ClassMembersModel::headerData(int section, Qt::Orientation orientation,int role /* = Qt::DisplayRole */) const
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
