/**************************************************************************
**   File: returndeliveryorderstoreproduct.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef RETURNDELIVERYORDERSTOREPRODUCT_H
#define RETURNDELIVERYORDERSTOREPRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ReturnDeliveryOrderStoreProduct  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ReturnDeliveryOrderStoreProduct();
	ReturnDeliveryOrderStoreProduct(int ReturnDeliveryOrderID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int ReturnDeliveryOrderStoreProductID;
	int ReturnDeliveryOrderID;
	int StoreID;
	int ProductID;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ReturnDeliveryOrderStoreProduct* get();
	ReturnDeliveryOrderStoreProduct* get(const QModelIndex &index);
	static ReturnDeliveryOrderStoreProduct* Get(int id);
	static ReturnDeliveryOrderStoreProduct* Get(QString name);
	static QList<ReturnDeliveryOrderStoreProduct*> GetAll();
	static QList<ReturnDeliveryOrderStoreProduct*> Search(QString keyword);
	static QList<ReturnDeliveryOrderStoreProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ReturnDeliveryOrderStoreProduct*> returndeliveryorderstoreproducts);
	static int GetIndex(QString title);
	static ReturnDeliveryOrderStoreProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ReturnDeliveryOrderStoreProduct(int ReturnDeliveryOrderStoreProductID,int ReturnDeliveryOrderID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static ReturnDeliveryOrderStoreProduct* p_instance;
	bool setReturnDeliveryOrderID(int ReturnDeliveryOrderStoreProductID, const QString &ReturnDeliveryOrderID);
	bool setStoreID(int ReturnDeliveryOrderStoreProductID, const QString &StoreID);
	bool setProductID(int ReturnDeliveryOrderStoreProductID, const QString &ProductID);
	bool setAmount(int ReturnDeliveryOrderStoreProductID, const QString &Amount);
	bool setPrice(int ReturnDeliveryOrderStoreProductID, const QString &Price);
	bool setCreatedOn(int ReturnDeliveryOrderStoreProductID, const QString &CreatedOn);
	bool setEditedOn(int ReturnDeliveryOrderStoreProductID, const QString &EditedOn);

};
#endif
