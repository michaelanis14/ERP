/**************************************************************************
**   File: returndeliveryorder.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef RETURNDELIVERYORDER_H
#define RETURNDELIVERYORDER_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "returndeliveryorderstoreproduct.h"
#include "returndeliveryorderservice.h"
#include "returndeliveryorderfreeline.h"

class ReturnDeliveryOrder  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ReturnDeliveryOrder();
	ReturnDeliveryOrder(int Serial,int DeliveryOrderID,QDate Date,QString Note,QString CreatedOn,QString EditedOn);	int ReturnDeliveryOrderID;
	int Serial;
	int DeliveryOrderID;
	QDate Date;
	QString Note;
	QList<ReturnDeliveryOrderStoreProduct*> returndeliveryorderstoreproducts;
	QList<ReturnDeliveryOrderService*> returndeliveryorderservices;
	QList<ReturnDeliveryOrderFreeline*> returndeliveryorderfreelines;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ReturnDeliveryOrder* get();
	ReturnDeliveryOrder* get(const QModelIndex &index);
	static ReturnDeliveryOrder* Get(int id);
	static ReturnDeliveryOrder* Get(QString name);
	static QList<ReturnDeliveryOrder*> GetAll();
	static QList<ReturnDeliveryOrder*> Search(QString keyword);
	static QList<ReturnDeliveryOrder*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ReturnDeliveryOrder*> returndeliveryorders);
	static int GetIndex(QString title);
	static ReturnDeliveryOrder* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ReturnDeliveryOrder(int ReturnDeliveryOrderID,int Serial,int DeliveryOrderID,QDate Date,QString Note,QString CreatedOn,QString EditedOn);	static ReturnDeliveryOrder* p_instance;
	bool setSerial(int ReturnDeliveryOrderID, const QString &Serial);
	bool setDeliveryOrderID(int ReturnDeliveryOrderID, const QString &DeliveryOrderID);
	bool setDate(int ReturnDeliveryOrderID, const QString &Date);
	bool setNote(int ReturnDeliveryOrderID, const QString &Note);
	bool setCreatedOn(int ReturnDeliveryOrderID, const QString &CreatedOn);
	bool setEditedOn(int ReturnDeliveryOrderID, const QString &EditedOn);

};
#endif
