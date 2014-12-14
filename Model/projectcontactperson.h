/**************************************************************************
**   File: projectcontactperson.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECTCONTACTPERSON_H
#define PROJECTCONTACTPERSON_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProjectContactPerson  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProjectContactPerson();
	ProjectContactPerson(int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn);	int ProjectContactPersonID;
	int ProjectID;
	int ContactPersonID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProjectContactPerson* get();
	ProjectContactPerson* get(const QModelIndex &index);
	static ProjectContactPerson* Get(int id);
	static ProjectContactPerson* Get(QString name);
	static QList<ProjectContactPerson*> GetAll();
	static QList<ProjectContactPerson*> Search(QString keyword);
	static QList<ProjectContactPerson*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProjectContactPerson*> projectcontactpersons);
	static int GetIndex(QString title);
	static ProjectContactPerson* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProjectContactPerson(int ProjectContactPersonID,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn);	static ProjectContactPerson* p_instance;
	bool setProjectID(int ProjectContactPersonID, const QString &ProjectID);
	bool setContactPersonID(int ProjectContactPersonID, const QString &ContactPersonID);
	bool setCreatedOn(int ProjectContactPersonID, const QString &CreatedOn);
	bool setEditedOn(int ProjectContactPersonID, const QString &EditedOn);

};
#endif
