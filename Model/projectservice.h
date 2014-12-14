/**************************************************************************
**   File: projectservice.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECTSERVICE_H
#define PROJECTSERVICE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProjectService  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProjectService();
	ProjectService(int ProjectID,int ServiceID,QString CreatedOn,QString EditedOn);	int ProjectServiceID;
	int ProjectID;
	int ServiceID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProjectService* get();
	ProjectService* get(const QModelIndex &index);
	static ProjectService* Get(int id);
	static ProjectService* Get(QString name);
	static QList<ProjectService*> GetAll();
	static QList<ProjectService*> Search(QString keyword);
	static QList<ProjectService*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProjectService*> projectservices);
	static int GetIndex(QString title);
	static ProjectService* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProjectService(int ProjectServiceID,int ProjectID,int ServiceID,QString CreatedOn,QString EditedOn);	static ProjectService* p_instance;
	bool setProjectID(int ProjectServiceID, const QString &ProjectID);
	bool setServiceID(int ProjectServiceID, const QString &ServiceID);
	bool setCreatedOn(int ProjectServiceID, const QString &CreatedOn);
	bool setEditedOn(int ProjectServiceID, const QString &EditedOn);

};
#endif
