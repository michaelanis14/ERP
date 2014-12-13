/**************************************************************************
**   File: projectstatus.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECTSTATUS_H
#define PROJECTSTATUS_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProjectStatus  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProjectStatus();
	ProjectStatus(QString Description,QString CreatedOn,QString EditedOn);	int ProjectStatusID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProjectStatus* get();
	ProjectStatus* get(const QModelIndex &index);
	static ProjectStatus* Get(int id);
	static ProjectStatus* Get(QString name);
	static QList<ProjectStatus*> GetAll();
	static QList<ProjectStatus*> Search(QString keyword);
	static QList<ProjectStatus*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProjectStatus*> projectstatuss);
	static int GetIndex(QString title);
	static ProjectStatus* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProjectStatus(int ProjectStatusID,QString Description,QString CreatedOn,QString EditedOn);	static ProjectStatus* p_instance;
	bool setDescription(int ProjectStatusID, const QString &Description);
	bool setCreatedOn(int ProjectStatusID, const QString &CreatedOn);
	bool setEditedOn(int ProjectStatusID, const QString &EditedOn);

};
#endif
