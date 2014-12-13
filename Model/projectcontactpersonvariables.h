/**************************************************************************
**   File: projectcontactpersonvariables.h
**   Created on: Wed Dec 10 20:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECTCONTACTPERSONVARIABLES_H
#define PROJECTCONTACTPERSONVARIABLES_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class projectcontactpersonvariables  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	projectcontactpersonvariables();
	projectcontactpersonvariables(int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn);	int ProjectContactPersonID;
	int ProjectID;
	int ContactPersonID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	projectcontactpersonvariables* get();
	projectcontactpersonvariables* get(const QModelIndex &index);
	static projectcontactpersonvariables* Get(int id);
	static projectcontactpersonvariables* Get(QString name);
	static QList<projectcontactpersonvariables*> GetAll();
	static QList<projectcontactpersonvariables*> Search(QString keyword);
	static QList<projectcontactpersonvariables*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<projectcontactpersonvariables*> projectcontactpersonvariabless);
	static int GetIndex(QString title);
	static projectcontactpersonvariables* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	projectcontactpersonvariables(int ProjectContactPersonID,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn);	static projectcontactpersonvariables* p_instance;
	bool setProjectID(int ProjectContactPersonID, const QString &ProjectID);
	bool setContactPersonID(int ProjectContactPersonID, const QString &ContactPersonID);
	bool setCreatedOn(int ProjectContactPersonID, const QString &CreatedOn);
	bool setEditedOn(int ProjectContactPersonID, const QString &EditedOn);

};
#endif
