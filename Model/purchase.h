/**************************************************************************
**   File: purchase.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PURCHASE_H
#define PURCHASE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "purchaseproduct.h"

class Purchase  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Purchase();
	Purchase(QString Title,int StoreID,QString CreationDate,QString DeliveryDate,QString CreatedOn,QString EditedOn);	int PurchaseID;
	QString Title;
	int StoreID;
	QString CreationDate;
	QString DeliveryDate;
	QList<PurchaseProduct*> purchaseproducts;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	Purchase* get();
	Purchase* get(const QModelIndex &index);
	static Purchase* Get(int id);
	static Purchase* Get(QString name);
	static QList<Purchase*> GetAll();
	static QList<Purchase*> Search(QString keyword);
	static QList<Purchase*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Purchase* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Purchase(int PurchaseID,QString Title,int StoreID,QString CreationDate,QString DeliveryDate,QString CreatedOn,QString EditedOn);	static Purchase* p_instance;
	bool setTitle(int PurchaseID, const QString &Title);
	bool setStoreID(int PurchaseID, const QString &StoreID);
	bool setCreationDate(int PurchaseID, const QString &CreationDate);
	bool setDeliveryDate(int PurchaseID, const QString &DeliveryDate);
	bool setCreatedOn(int PurchaseID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseID, const QString &EditedOn);

};
#endif
