/**************************************************************************
**   File: returnpurchasestoreproduct.h
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef RETURNPURCHASESTOREPRODUCT_H
#define RETURNPURCHASESTOREPRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ReturnPurchaseStoreProduct  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ReturnPurchaseStoreProduct();
	ReturnPurchaseStoreProduct(int StoreID,int ReturnPurchaseID,int ContactID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int ReturnPurchaseStoreProductID;
	int StoreID;
	int ReturnPurchaseID;
	int ContactID;
	int ProductID;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ReturnPurchaseStoreProduct* get();
	ReturnPurchaseStoreProduct* get(const QModelIndex &index);
	static ReturnPurchaseStoreProduct* Get(int id);
	static ReturnPurchaseStoreProduct* Get(QString name);
	static QList<ReturnPurchaseStoreProduct*> GetAll();
	static QList<ReturnPurchaseStoreProduct*> Search(QString keyword);
	static QList<ReturnPurchaseStoreProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ReturnPurchaseStoreProduct*> returnpurchasestoreproducts);
	static int GetIndex(QString title);
	static ReturnPurchaseStoreProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ReturnPurchaseStoreProduct(int ReturnPurchaseStoreProductID,int StoreID,int ReturnPurchaseID,int ContactID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static ReturnPurchaseStoreProduct* p_instance;
	bool setStoreID(int ReturnPurchaseStoreProductID, const QString &StoreID);
	bool setReturnPurchaseID(int ReturnPurchaseStoreProductID, const QString &ReturnPurchaseID);
	bool setContactID(int ReturnPurchaseStoreProductID, const QString &ContactID);
	bool setProductID(int ReturnPurchaseStoreProductID, const QString &ProductID);
	bool setAmount(int ReturnPurchaseStoreProductID, const QString &Amount);
	bool setPrice(int ReturnPurchaseStoreProductID, const QString &Price);
	bool setCreatedOn(int ReturnPurchaseStoreProductID, const QString &CreatedOn);
	bool setEditedOn(int ReturnPurchaseStoreProductID, const QString &EditedOn);

};
#endif
