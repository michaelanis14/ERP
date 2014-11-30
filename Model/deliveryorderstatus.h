/**************************************************************************
**   File: deliveryorderstatus.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef DELIVERYORDERSTATUS_H
#define DELIVERYORDERSTATUS_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class DeliveryOrderStatus  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	DeliveryOrderStatus();
	DeliveryOrderStatus(QString Description,QString CreatedOn,QString EditedOn);	int DeliveryOrderStatusID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	DeliveryOrderStatus* get();
	DeliveryOrderStatus* get(const QModelIndex &index);
	static DeliveryOrderStatus* Get(int id);
	static DeliveryOrderStatus* Get(QString name);
	static QList<DeliveryOrderStatus*> GetAll();
	static QList<DeliveryOrderStatus*> Search(QString keyword);
	static QList<DeliveryOrderStatus*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static DeliveryOrderStatus* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	DeliveryOrderStatus(int DeliveryOrderStatusID,QString Description,QString CreatedOn,QString EditedOn);	static DeliveryOrderStatus* p_instance;
	bool setDescription(int DeliveryOrderStatusID, const QString &Description);
	bool setCreatedOn(int DeliveryOrderStatusID, const QString &CreatedOn);
	bool setEditedOn(int DeliveryOrderStatusID, const QString &EditedOn);

};
#endif
