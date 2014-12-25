/**************************************************************************
**   File: project.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECT_H
#define PROJECT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "projectsales.h"
#include "task.h"
#include "projectcontactperson.h"
#include "projectservice.h"
#include "projectfile.h"

class Project  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Project();
	Project(QString Title,int ProjectStatusID,int ContactID,QDate StartDate,QDate EndDate,bool WillBeInvoiced,QString Note,QString CreatedOn,QString EditedOn);	int ProjectID;
	QString Title;
	int ProjectStatusID;
	int ContactID;
	QDate StartDate;
	QDate EndDate;
	bool WillBeInvoiced;
	QString Note;
	QList<ProjectSales*> projectsaless;
	QList<Task*> tasks;
	QList<ProjectContactPerson*> projectcontactpersons;
	QList<ProjectService*> projectservices;
	QList<ProjectFile*> projectfiles;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Project* get();
	Project* get(const QModelIndex &index);
	static Project* Get(int id);
	static Project* Get(QString name);
	static QList<Project*> GetAll();
	static QList<Project*> Search(QString keyword);
	static QList<Project*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Project*> projects);
	static int GetIndex(QString title);
	static Project* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Project(int ProjectID,QString Title,int ProjectStatusID,int ContactID,QDate StartDate,QDate EndDate,bool WillBeInvoiced,QString Note,QString CreatedOn,QString EditedOn);	static Project* p_instance;
	bool setTitle(int ProjectID, const QString &Title);
	bool setProjectStatusID(int ProjectID, const QString &ProjectStatusID);
	bool setContactID(int ProjectID, const QString &ContactID);
	bool setStartDate(int ProjectID, const QString &StartDate);
	bool setEndDate(int ProjectID, const QString &EndDate);
	bool setWillBeInvoiced(int ProjectID, const QString &WillBeInvoiced);
	bool setNote(int ProjectID, const QString &Note);
	bool setCreatedOn(int ProjectID, const QString &CreatedOn);
	bool setEditedOn(int ProjectID, const QString &EditedOn);

};
#endif
