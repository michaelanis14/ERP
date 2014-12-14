/**************************************************************************
**   File: task.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef TASK_H
#define TASK_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Task  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Task();
	Task(QString Note,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn);	int TaskID;
	QString Note;
	int ProjectID;
	int ContactPersonID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Task* get();
	Task* get(const QModelIndex &index);
	static Task* Get(int id);
	static Task* Get(QString name);
	static QList<Task*> GetAll();
	static QList<Task*> Search(QString keyword);
	static QList<Task*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Task*> tasks);
	static int GetIndex(QString title);
	static Task* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Task(int TaskID,QString Note,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn);	static Task* p_instance;
	bool setNote(int TaskID, const QString &Note);
	bool setProjectID(int TaskID, const QString &ProjectID);
	bool setContactPersonID(int TaskID, const QString &ContactPersonID);
	bool setCreatedOn(int TaskID, const QString &CreatedOn);
	bool setEditedOn(int TaskID, const QString &EditedOn);

};
#endif
