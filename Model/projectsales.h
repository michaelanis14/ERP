/**************************************************************************
**   File: projectsales.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECTSALES_H
#define PROJECTSALES_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProjectSales  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProjectSales();
	ProjectSales(int ProjectID,int ContactID,QString CreatedOn,QString EditedOn);	int ProjectSalesID;
	int ProjectID;
	int ContactID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProjectSales* get();
	ProjectSales* get(const QModelIndex &index);
	static ProjectSales* Get(int id);
	static ProjectSales* Get(QString name);
	static QList<ProjectSales*> GetAll();
	static QList<ProjectSales*> Search(QString keyword);
	static QList<ProjectSales*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProjectSales*> projectsaless);
	static int GetIndex(QString title);
	static ProjectSales* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProjectSales(int ProjectSalesID,int ProjectID,int ContactID,QString CreatedOn,QString EditedOn);	static ProjectSales* p_instance;
	bool setProjectID(int ProjectSalesID, const QString &ProjectID);
	bool setContactID(int ProjectSalesID, const QString &ContactID);
	bool setCreatedOn(int ProjectSalesID, const QString &CreatedOn);
	bool setEditedOn(int ProjectSalesID, const QString &EditedOn);

};
#endif
