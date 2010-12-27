#ifndef JAVA2CPP_CLASS_MEMBERS_VIEW_H
#define JAVA2CPP_CLASS_MEMBERS_VIEW_H

class ClassMembersView
	: public QListView
{
	Q_OBJECT
public:
	ClassMembersView(QWidget *parent=0);
	~ClassMembersView();
};

#endif //JAVA2CPP_CLASS_MEMBERS_VIEW_H