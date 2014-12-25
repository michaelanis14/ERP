/**************************************************************************
**   File: returndeliveryorderfreeline.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef RETURNDELIVERYORDERFREELINE_H
#define RETURNDELIVERYORDERFREELINE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ReturnDeliveryOrderFreeline  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ReturnDeliveryOrderFreeline();
	ReturnDeliveryOrderFreeline(int ReturnDeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	int ReturnDeliveryOrderFreelineID;
	int ReturnDeliveryOrderID;
	QString Description;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ReturnDeliveryOrderFreeline* get();
	ReturnDeliveryOrderFreeline* get(const QModelIndex &index);
	static ReturnDeliveryOrderFreeline* Get(int id);
	static ReturnDeliveryOrderFreeline* Get(QString name);
	static QList<ReturnDeliveryOrderFreeline*> GetAll();
	static QList<ReturnDeliveryOrderFreeline*> Search(QString keyword);
	static QList<ReturnDeliveryOrderFreeline*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ReturnDeliveryOrderFreeline*> returndeliveryorderfreelines);
	static int GetIndex(QString title);
	static ReturnDeliveryOrderFreeline* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ReturnDeliveryOrderFreeline(int ReturnDeliveryOrderFreelineID,int ReturnDeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	static ReturnDeliveryOrderFreeline* p_instance;
	bool setReturnDeliveryOrderID(int ReturnDeliveryOrderFreelineID, const QString &ReturnDeliveryOrderID);
	bool setDescription(int ReturnDeliveryOrderFreelineID, const QString &Description);
	bool setAmount(int ReturnDeliveryOrderFreelineID, const QString &Amount);
	bool setPrice(int ReturnDeliveryOrderFreelineID, const QString &Price);
	bool setCreatedOn(int ReturnDeliveryOrderFreelineID, const QString &CreatedOn);
	bool setEditedOn(int ReturnDeliveryOrderFreelineID, const QString &EditedOn);

};
#endif
