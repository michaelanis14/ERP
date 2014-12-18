/**************************************************************************
**   File: purchaseserial.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PURCHASESERIAL_H
#define PURCHASESERIAL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class PurchaseSerial  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	PurchaseSerial();
	PurchaseSerial(QString Title,int Serial,QString CreatedOn,QString EditedOn);	int PurchaseSerialID;
	QString Title;
	int Serial;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	PurchaseSerial* get();
	PurchaseSerial* get(const QModelIndex &index);
	static PurchaseSerial* Get(int id);
	static PurchaseSerial* Get(QString name);
	static QList<PurchaseSerial*> GetAll();
	static QList<PurchaseSerial*> Search(QString keyword);
	static QList<PurchaseSerial*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<PurchaseSerial*> purchaseserials);
	static int GetIndex(QString title);
	static PurchaseSerial* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	PurchaseSerial(int PurchaseSerialID,QString Title,int Serial,QString CreatedOn,QString EditedOn);	static PurchaseSerial* p_instance;
	bool setTitle(int PurchaseSerialID, const QString &Title);
	bool setSerial(int PurchaseSerialID, const QString &Serial);
	bool setCreatedOn(int PurchaseSerialID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseSerialID, const QString &EditedOn);

};
#endif
