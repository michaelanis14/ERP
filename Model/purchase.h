/**************************************************************************
**   File: purchase.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PURCHASE_H
#define PURCHASE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "purchasestoreproduct.h"
#include "purchasefreeline.h"

class Purchase  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Purchase();
	Purchase(int PurchaseSerialID,QDate CreationDate,QDate DeliveryDate,QString CreatedOn,QString EditedOn);	int PurchaseID;
	int PurchaseSerialID;
	QDate CreationDate;
	QDate DeliveryDate;
	QList<PurchaseStoreProduct*> purchasestoreproducts;
	QList<PurchaseFreeLine*> purchasefreelines;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Purchase* get();
	Purchase* get(const QModelIndex &index);
	static Purchase* Get(int id);
	static Purchase* Get(QString name);
	static QList<Purchase*> GetAll();
	static QList<Purchase*> Search(QString keyword);
	static QList<Purchase*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Purchase*> purchases);
	static int GetIndex(QString title);
	static Purchase* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Purchase(int PurchaseID,int PurchaseSerialID,QDate CreationDate,QDate DeliveryDate,QString CreatedOn,QString EditedOn);	static Purchase* p_instance;
	bool setPurchaseSerialID(int PurchaseID, const QString &PurchaseSerialID);
	bool setCreationDate(int PurchaseID, const QString &CreationDate);
	bool setDeliveryDate(int PurchaseID, const QString &DeliveryDate);
	bool setCreatedOn(int PurchaseID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseID, const QString &EditedOn);

};
#endif
