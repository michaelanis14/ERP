/**************************************************************************
**   File: returnpurchasefreeline.h
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef RETURNPURCHASEFREELINE_H
#define RETURNPURCHASEFREELINE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ReturnPurchaseFreeLine  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ReturnPurchaseFreeLine();
	ReturnPurchaseFreeLine(int ReturnPurchaseID,QString Description,int ContactID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int ReturnPurchaseFreeLineID;
	int ReturnPurchaseID;
	QString Description;
	int ContactID;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ReturnPurchaseFreeLine* get();
	ReturnPurchaseFreeLine* get(const QModelIndex &index);
	static ReturnPurchaseFreeLine* Get(int id);
	static ReturnPurchaseFreeLine* Get(QString name);
	static QList<ReturnPurchaseFreeLine*> GetAll();
	static QList<ReturnPurchaseFreeLine*> Search(QString keyword);
	static QList<ReturnPurchaseFreeLine*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ReturnPurchaseFreeLine*> returnpurchasefreelines);
	static int GetIndex(QString title);
	static ReturnPurchaseFreeLine* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ReturnPurchaseFreeLine(int ReturnPurchaseFreeLineID,int ReturnPurchaseID,QString Description,int ContactID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static ReturnPurchaseFreeLine* p_instance;
	bool setReturnPurchaseID(int ReturnPurchaseFreeLineID, const QString &ReturnPurchaseID);
	bool setDescription(int ReturnPurchaseFreeLineID, const QString &Description);
	bool setContactID(int ReturnPurchaseFreeLineID, const QString &ContactID);
	bool setAmount(int ReturnPurchaseFreeLineID, const QString &Amount);
	bool setPrice(int ReturnPurchaseFreeLineID, const QString &Price);
	bool setCreatedOn(int ReturnPurchaseFreeLineID, const QString &CreatedOn);
	bool setEditedOn(int ReturnPurchaseFreeLineID, const QString &EditedOn);

};
#endif
