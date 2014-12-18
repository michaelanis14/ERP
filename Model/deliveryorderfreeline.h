/**************************************************************************
**   File: deliveryorderfreeline.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef DELIVERYORDERFREELINE_H
#define DELIVERYORDERFREELINE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class DeliveryOrderFreeline  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	DeliveryOrderFreeline();
	DeliveryOrderFreeline(int DeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	int DeliveryOrderFreelineID;
	int DeliveryOrderID;
	QString Description;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	DeliveryOrderFreeline* get();
	DeliveryOrderFreeline* get(const QModelIndex &index);
	static DeliveryOrderFreeline* Get(int id);
	static DeliveryOrderFreeline* Get(QString name);
	static QList<DeliveryOrderFreeline*> GetAll();
	static QList<DeliveryOrderFreeline*> Search(QString keyword);
	static QList<DeliveryOrderFreeline*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<DeliveryOrderFreeline*> deliveryorderfreelines);
	static int GetIndex(QString title);
	static DeliveryOrderFreeline* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	DeliveryOrderFreeline(int DeliveryOrderFreelineID,int DeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	static DeliveryOrderFreeline* p_instance;
	bool setDeliveryOrderID(int DeliveryOrderFreelineID, const QString &DeliveryOrderID);
	bool setDescription(int DeliveryOrderFreelineID, const QString &Description);
	bool setAmount(int DeliveryOrderFreelineID, const QString &Amount);
	bool setPrice(int DeliveryOrderFreelineID, const QString &Price);
	bool setCreatedOn(int DeliveryOrderFreelineID, const QString &CreatedOn);
	bool setEditedOn(int DeliveryOrderFreelineID, const QString &EditedOn);

};
#endif
