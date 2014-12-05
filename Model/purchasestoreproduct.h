/**************************************************************************
**   File: purchasestoreproduct.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
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
	PurchaseStoreProduct(QString Title,int StoreID,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn);	int PurchaseStoreProductID;
	QString Title;
	int StoreID;
	int PurchaseID;
	int ContactID;
	int ProductID;
	double Amount;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	PurchaseStoreProduct* get();
	PurchaseStoreProduct* get(const QModelIndex &index);
	static PurchaseStoreProduct* Get(int id);
	static PurchaseStoreProduct* Get(QString name);
	static QList<PurchaseStoreProduct*> GetAll();
	static QList<PurchaseStoreProduct*> Search(QString keyword);
	static QList<PurchaseStoreProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static PurchaseStoreProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	PurchaseStoreProduct(int PurchaseStoreProductID,QString Title,int StoreID,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn);	static PurchaseStoreProduct* p_instance;
	bool setTitle(int PurchaseStoreProductID, const QString &Title);
	bool setStoreID(int PurchaseStoreProductID, const QString &StoreID);
	bool setPurchaseID(int PurchaseStoreProductID, const QString &PurchaseID);
	bool setContactID(int PurchaseStoreProductID, const QString &ContactID);
	bool setProductID(int PurchaseStoreProductID, const QString &ProductID);
	bool setAmount(int PurchaseStoreProductID, const QString &Amount);
	bool setCreatedOn(int PurchaseStoreProductID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseStoreProductID, const QString &EditedOn);

};
#endif
