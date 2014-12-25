/**************************************************************************
**   File: deliveryorderservice.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef DELIVERYORDERSERVICE_H
#define DELIVERYORDERSERVICE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class DeliveryOrderService  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	DeliveryOrderService();
	DeliveryOrderService(int DeliveryOrderID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int DeliveryOrderServiceID;
	int DeliveryOrderID;
	int ServiceID;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	DeliveryOrderService* get();
	DeliveryOrderService* get(const QModelIndex &index);
	static DeliveryOrderService* Get(int id);
	static DeliveryOrderService* Get(QString name);
	static QList<DeliveryOrderService*> GetAll();
	static QList<DeliveryOrderService*> Search(QString keyword);
	static QList<DeliveryOrderService*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<DeliveryOrderService*> deliveryorderservices);
	static int GetIndex(QString title);
	static DeliveryOrderService* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	DeliveryOrderService(int DeliveryOrderServiceID,int DeliveryOrderID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static DeliveryOrderService* p_instance;
	bool setDeliveryOrderID(int DeliveryOrderServiceID, const QString &DeliveryOrderID);
	bool setServiceID(int DeliveryOrderServiceID, const QString &ServiceID);
	bool setAmount(int DeliveryOrderServiceID, const QString &Amount);
	bool setPrice(int DeliveryOrderServiceID, const QString &Price);
	bool setCreatedOn(int DeliveryOrderServiceID, const QString &CreatedOn);
	bool setEditedOn(int DeliveryOrderServiceID, const QString &EditedOn);

};
#endif
