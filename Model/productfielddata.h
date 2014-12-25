/**************************************************************************
**   File: productfielddata.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PRODUCTFIELDDATA_H
#define PRODUCTFIELDDATA_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProductFieldData  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProductFieldData();
	ProductFieldData(int ProductID,int ProductFieldID,QString Value,QString CreatedOn,QString EditedOn);	int ProductFieldDataID;
	int ProductID;
	int ProductFieldID;
	QString Value;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProductFieldData* get();
	ProductFieldData* get(const QModelIndex &index);
	static ProductFieldData* Get(int id);
	static ProductFieldData* Get(QString name);
	static QList<ProductFieldData*> GetAll();
	static QList<ProductFieldData*> Search(QString keyword);
	static QList<ProductFieldData*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProductFieldData*> productfielddatas);
	static int GetIndex(QString title);
	static ProductFieldData* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProductFieldData(int ProductFieldDataID,int ProductID,int ProductFieldID,QString Value,QString CreatedOn,QString EditedOn);	static ProductFieldData* p_instance;
	bool setProductID(int ProductFieldDataID, const QString &ProductID);
	bool setProductFieldID(int ProductFieldDataID, const QString &ProductFieldID);
	bool setValue(int ProductFieldDataID, const QString &Value);
	bool setCreatedOn(int ProductFieldDataID, const QString &CreatedOn);
	bool setEditedOn(int ProductFieldDataID, const QString &EditedOn);

};
#endif
