/**************************************************************************
**   File: purchasestoreproduct.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PURCHASESTOREPRODUCT_H
#define PURCHASESTOREPRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class PurchaseStoreProduct  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	PurchaseStoreProduct();
	PurchaseStoreProduct(int StoreID,int PurchaseID,int ContactID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int PurchaseStoreProductID;
	int StoreID;
	int PurchaseID;
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
	PurchaseStoreProduct* get();
	PurchaseStoreProduct* get(const QModelIndex &index);
	static PurchaseStoreProduct* Get(int id);
	static PurchaseStoreProduct* Get(QString name);
	static QList<PurchaseStoreProduct*> GetAll();
	static QList<PurchaseStoreProduct*> Search(QString keyword);
	static QList<PurchaseStoreProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<PurchaseStoreProduct*> purchasestoreproducts);
	static int GetIndex(QString title);
	static PurchaseStoreProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	PurchaseStoreProduct(int PurchaseStoreProductID,int StoreID,int PurchaseID,int ContactID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static PurchaseStoreProduct* p_instance;
	bool setStoreID(int PurchaseStoreProductID, const QString &StoreID);
	bool setPurchaseID(int PurchaseStoreProductID, const QString &PurchaseID);
	bool setContactID(int PurchaseStoreProductID, const QString &ContactID);
	bool setProductID(int PurchaseStoreProductID, const QString &ProductID);
	bool setAmount(int PurchaseStoreProductID, const QString &Amount);
	bool setPrice(int PurchaseStoreProductID, const QString &Price);
	bool setCreatedOn(int PurchaseStoreProductID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseStoreProductID, const QString &EditedOn);

};
#endif
