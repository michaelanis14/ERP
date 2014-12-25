/**************************************************************************
**   File: deliveryorderserial.h
**   Created on: Fri Dec 19 13:01:03 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef DELIVERYORDERSERIAL_H
#define DELIVERYORDERSERIAL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class DeliveryOrderSerial  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	DeliveryOrderSerial();
	DeliveryOrderSerial(QString Title,int Serial,QString CreatedOn,QString EditedOn);	int DeliveryOrderSerialID;
	QString Title;
	int Serial;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	DeliveryOrderSerial* get();
	DeliveryOrderSerial* get(const QModelIndex &index);
	static DeliveryOrderSerial* Get(int id);
	static DeliveryOrderSerial* Get(QString name);
	static QList<DeliveryOrderSerial*> GetAll();
	static QList<DeliveryOrderSerial*> Search(QString keyword);
	static QList<DeliveryOrderSerial*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<DeliveryOrderSerial*> deliveryorderserials);
	static int GetIndex(QString title);
	static DeliveryOrderSerial* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	DeliveryOrderSerial(int DeliveryOrderSerialID,QString Title,int Serial,QString CreatedOn,QString EditedOn);	static DeliveryOrderSerial* p_instance;
	bool setTitle(int DeliveryOrderSerialID, const QString &Title);
	bool setSerial(int DeliveryOrderSerialID, const QString &Serial);
	bool setCreatedOn(int DeliveryOrderSerialID, const QString &CreatedOn);
	bool setEditedOn(int DeliveryOrderSerialID, const QString &EditedOn);

};
#endif
