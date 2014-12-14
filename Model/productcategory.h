/**************************************************************************
**   File: productcategory.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PRODUCTCATEGORY_H
#define PRODUCTCATEGORY_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProductCategory  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProductCategory();
	ProductCategory(QString Description,QString CreatedOn,QString EditedOn);	int ProductCategoryID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProductCategory* get();
	ProductCategory* get(const QModelIndex &index);
	static ProductCategory* Get(int id);
	static ProductCategory* Get(QString name);
	static QList<ProductCategory*> GetAll();
	static QList<ProductCategory*> Search(QString keyword);
	static QList<ProductCategory*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProductCategory*> productcategorys);
	static int GetIndex(QString title);
	static ProductCategory* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProductCategory(int ProductCategoryID,QString Description,QString CreatedOn,QString EditedOn);	static ProductCategory* p_instance;
	bool setDescription(int ProductCategoryID, const QString &Description);
	bool setCreatedOn(int ProductCategoryID, const QString &CreatedOn);
	bool setEditedOn(int ProductCategoryID, const QString &EditedOn);

};
#endif
