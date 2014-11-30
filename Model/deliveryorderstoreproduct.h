/**************************************************************************
**   File: deliveryorderstoreproduct.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef DELIVERYORDERSTOREPRODUCT_H
#define DELIVERYORDERSTOREPRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class DeliveryOrderStoreProduct  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	DeliveryOrderStoreProduct();
	DeliveryOrderStoreProduct(QString Title,int DeliveryOrderID,int StoreID,int ProductID,double Amount,QString CreatedOn,QString EditedOn);	int DeliveryOrderStoreProductID;
	QString Title;
	int DeliveryOrderID;
	int StoreID;
	int ProductID;
	double Amount;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	DeliveryOrderStoreProduct* get();
	DeliveryOrderStoreProduct* get(const QModelIndex &index);
	static DeliveryOrderStoreProduct* Get(int id);
	static DeliveryOrderStoreProduct* Get(QString name);
	static QList<DeliveryOrderStoreProduct*> GetAll();
	static QList<DeliveryOrderStoreProduct*> Search(QString keyword);
	static QList<DeliveryOrderStoreProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static DeliveryOrderStoreProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	DeliveryOrderStoreProduct(int DeliveryOrderStoreProductID,QString Title,int DeliveryOrderID,int StoreID,int ProductID,double Amount,QString CreatedOn,QString EditedOn);	static DeliveryOrderStoreProduct* p_instance;
	bool setTitle(int DeliveryOrderStoreProductID, const QString &Title);
	bool setDeliveryOrderID(int DeliveryOrderStoreProductID, const QString &DeliveryOrderID);
	bool setStoreID(int DeliveryOrderStoreProductID, const QString &StoreID);
	bool setProductID(int DeliveryOrderStoreProductID, const QString &ProductID);
	bool setAmount(int DeliveryOrderStoreProductID, const QString &Amount);
	bool setCreatedOn(int DeliveryOrderStoreProductID, const QString &CreatedOn);
	bool setEditedOn(int DeliveryOrderStoreProductID, const QString &EditedOn);

};
#endif
