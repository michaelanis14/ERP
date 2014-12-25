/**************************************************************************
**   File: invoicestoreproduct.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICESTOREPRODUCT_H
#define INVOICESTOREPRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceStoreProduct  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceStoreProduct();
	InvoiceStoreProduct(int InvoiceID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int InvoiceStoreProductID;
	int InvoiceID;
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
	InvoiceStoreProduct* get();
	InvoiceStoreProduct* get(const QModelIndex &index);
	static InvoiceStoreProduct* Get(int id);
	static InvoiceStoreProduct* Get(QString name);
	static QList<InvoiceStoreProduct*> GetAll();
	static QList<InvoiceStoreProduct*> Search(QString keyword);
	static QList<InvoiceStoreProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<InvoiceStoreProduct*> invoicestoreproducts);
	static int GetIndex(QString title);
	static InvoiceStoreProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceStoreProduct(int InvoiceStoreProductID,int InvoiceID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static InvoiceStoreProduct* p_instance;
	bool setInvoiceID(int InvoiceStoreProductID, const QString &InvoiceID);
	bool setStoreID(int InvoiceStoreProductID, const QString &StoreID);
	bool setProductID(int InvoiceStoreProductID, const QString &ProductID);
	bool setAmount(int InvoiceStoreProductID, const QString &Amount);
	bool setPrice(int InvoiceStoreProductID, const QString &Price);
	bool setCreatedOn(int InvoiceStoreProductID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceStoreProductID, const QString &EditedOn);

};
#endif
