/**************************************************************************
**   File: purchasefreeline.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PURCHASEFREELINE_H
#define PURCHASEFREELINE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class PurchaseFreeLine  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	PurchaseFreeLine();
	PurchaseFreeLine(int PurchaseID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	int PurchaseFreeLineID;
	int PurchaseID;
	QString Description;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	PurchaseFreeLine* get();
	PurchaseFreeLine* get(const QModelIndex &index);
	static PurchaseFreeLine* Get(int id);
	static PurchaseFreeLine* Get(QString name);
	static QList<PurchaseFreeLine*> GetAll();
	static QList<PurchaseFreeLine*> Search(QString keyword);
	static QList<PurchaseFreeLine*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static PurchaseFreeLine* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	PurchaseFreeLine(int PurchaseFreeLineID,int PurchaseID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	static PurchaseFreeLine* p_instance;
	bool setPurchaseID(int PurchaseFreeLineID, const QString &PurchaseID);
	bool setDescription(int PurchaseFreeLineID, const QString &Description);
	bool setAmount(int PurchaseFreeLineID, const QString &Amount);
	bool setPrice(int PurchaseFreeLineID, const QString &Price);
	bool setCreatedOn(int PurchaseFreeLineID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseFreeLineID, const QString &EditedOn);

};
#endif
