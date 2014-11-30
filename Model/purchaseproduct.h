/**************************************************************************
**   File: purchaseproduct.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PURCHASEPRODUCT_H
#define PURCHASEPRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class PurchaseProduct  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	PurchaseProduct();
	PurchaseProduct(QString Title,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn);	int PurchaseProductID;
	QString Title;
	int PurchaseID;
	int ContactID;
	int ProductID;
	double Amount;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	PurchaseProduct* get();
	PurchaseProduct* get(const QModelIndex &index);
	static PurchaseProduct* Get(int id);
	static PurchaseProduct* Get(QString name);
	static QList<PurchaseProduct*> GetAll();
	static QList<PurchaseProduct*> Search(QString keyword);
	static QList<PurchaseProduct*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static PurchaseProduct* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	PurchaseProduct(int PurchaseProductID,QString Title,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn);	static PurchaseProduct* p_instance;
	bool setTitle(int PurchaseProductID, const QString &Title);
	bool setPurchaseID(int PurchaseProductID, const QString &PurchaseID);
	bool setContactID(int PurchaseProductID, const QString &ContactID);
	bool setProductID(int PurchaseProductID, const QString &ProductID);
	bool setAmount(int PurchaseProductID, const QString &Amount);
	bool setCreatedOn(int PurchaseProductID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseProductID, const QString &EditedOn);

};
#endif
