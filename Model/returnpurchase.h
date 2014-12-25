/**************************************************************************
**   File: returnpurchase.h
**   Created on: Thu Dec 18 23:40:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef RETURNPURCHASE_H
#define RETURNPURCHASE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "returnpurchasestoreproduct.h"
#include "returnpurchasefreeline.h"

class ReturnPurchase  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ReturnPurchase();
	ReturnPurchase(int PurchaseID,QDate Date,QString CreatedOn,QString EditedOn);	int ReturnPurchaseID;
	int PurchaseID;
	QDate Date;
	QList<ReturnPurchaseStoreProduct*> returnpurchasestoreproducts;
	QList<ReturnPurchaseFreeLine*> returnpurchasefreelines;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ReturnPurchase* get();
	ReturnPurchase* get(const QModelIndex &index);
	static ReturnPurchase* Get(int id);
	static ReturnPurchase* Get(QString name);
	static QList<ReturnPurchase*> GetAll();
	static QList<ReturnPurchase*> Search(QString keyword);
	static QList<ReturnPurchase*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ReturnPurchase*> returnpurchases);
	static int GetIndex(QString title);
	static ReturnPurchase* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ReturnPurchase(int ReturnPurchaseID,int PurchaseID,QDate Date,QString CreatedOn,QString EditedOn);	static ReturnPurchase* p_instance;
	bool setPurchaseID(int ReturnPurchaseID, const QString &PurchaseID);
	bool setDate(int ReturnPurchaseID, const QString &Date);
	bool setCreatedOn(int ReturnPurchaseID, const QString &CreatedOn);
	bool setEditedOn(int ReturnPurchaseID, const QString &EditedOn);

};
#endif
