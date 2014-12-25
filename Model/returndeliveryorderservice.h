/**************************************************************************
**   File: returndeliveryorderservice.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef RETURNDELIVERYORDERSERVICE_H
#define RETURNDELIVERYORDERSERVICE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ReturnDeliveryOrderService  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ReturnDeliveryOrderService();
	ReturnDeliveryOrderService(int ReturnDeliveryOrderID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int ReturnDeliveryOrderServiceID;
	int ReturnDeliveryOrderID;
	int ServiceID;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ReturnDeliveryOrderService* get();
	ReturnDeliveryOrderService* get(const QModelIndex &index);
	static ReturnDeliveryOrderService* Get(int id);
	static ReturnDeliveryOrderService* Get(QString name);
	static QList<ReturnDeliveryOrderService*> GetAll();
	static QList<ReturnDeliveryOrderService*> Search(QString keyword);
	static QList<ReturnDeliveryOrderService*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ReturnDeliveryOrderService*> returndeliveryorderservices);
	static int GetIndex(QString title);
	static ReturnDeliveryOrderService* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ReturnDeliveryOrderService(int ReturnDeliveryOrderServiceID,int ReturnDeliveryOrderID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static ReturnDeliveryOrderService* p_instance;
	bool setReturnDeliveryOrderID(int ReturnDeliveryOrderServiceID, const QString &ReturnDeliveryOrderID);
	bool setServiceID(int ReturnDeliveryOrderServiceID, const QString &ServiceID);
	bool setAmount(int ReturnDeliveryOrderServiceID, const QString &Amount);
	bool setPrice(int ReturnDeliveryOrderServiceID, const QString &Price);
	bool setCreatedOn(int ReturnDeliveryOrderServiceID, const QString &CreatedOn);
	bool setEditedOn(int ReturnDeliveryOrderServiceID, const QString &EditedOn);

};
#endif
