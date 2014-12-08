/**************************************************************************
**   File: project.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECT_H
#define PROJECT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Project  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Project();
	Project(QString Title,QString CreatedOn,QString EditedOn);	int ProjectID;
	QString Title;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	Project* get();
	Project* get(const QModelIndex &index);
	static Project* Get(int id);
	static Project* Get(QString name);
	static QList<Project*> GetAll();
	static QList<Project*> Search(QString keyword);
	static QList<Project*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Project* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Project(int ProjectID,QString Title,QString CreatedOn,QString EditedOn);	static Project* p_instance;
	bool setTitle(int ProjectID, const QString &Title);
	bool setCreatedOn(int ProjectID, const QString &CreatedOn);
	bool setEditedOn(int ProjectID, const QString &EditedOn);

};
#endif
