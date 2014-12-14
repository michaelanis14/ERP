/**************************************************************************
**   File: projectproduct.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECTPRODUCT_H
#define PROJECTPRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProjectProduct  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProjectProduct();
	ProjectProduct(int ProjectID,int ProductID,QString CreatedOn,QString EditedOn);	int ProjectProductID;
	int ProjectID;
	int ProductID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProjectProduct* get();
	ProjectProduct* get(const QModelIndex &index);
	static ProjectProduct* Get(int id);
	static ProjectProduct* Get(QString name);
	static QList<ProjectProduct*> GetAll();
	static QList<ProjectProduct*> Search(QString keyword);
	static QList<ProjectProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProjectProduct*> projectproducts);
	static int GetIndex(QString title);
	static ProjectProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProjectProduct(int ProjectProductID,int ProjectID,int ProductID,QString CreatedOn,QString EditedOn);	static ProjectProduct* p_instance;
	bool setProjectID(int ProjectProductID, const QString &ProjectID);
	bool setProductID(int ProjectProductID, const QString &ProductID);
	bool setCreatedOn(int ProjectProductID, const QString &CreatedOn);
	bool setEditedOn(int ProjectProductID, const QString &EditedOn);

};
#endif
