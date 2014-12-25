/**************************************************************************
**   File: invoicedeliveryorderfreeline.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICEDELIVERYORDERFREELINE_H
#define INVOICEDELIVERYORDERFREELINE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceDeliveryOrderFreeline  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceDeliveryOrderFreeline();
	InvoiceDeliveryOrderFreeline(int InvoiceID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	int InvoiceDeliveryOrderFreelineID;
	int InvoiceID;
	QString Description;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	InvoiceDeliveryOrderFreeline* get();
	InvoiceDeliveryOrderFreeline* get(const QModelIndex &index);
	static InvoiceDeliveryOrderFreeline* Get(int id);
	static InvoiceDeliveryOrderFreeline* Get(QString name);
	static QList<InvoiceDeliveryOrderFreeline*> GetAll();
	static QList<InvoiceDeliveryOrderFreeline*> Search(QString keyword);
	static QList<InvoiceDeliveryOrderFreeline*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<InvoiceDeliveryOrderFreeline*> invoicedeliveryorderfreelines);
	static int GetIndex(QString title);
	static InvoiceDeliveryOrderFreeline* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceDeliveryOrderFreeline(int InvoiceDeliveryOrderFreelineID,int InvoiceID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn);	static InvoiceDeliveryOrderFreeline* p_instance;
	bool setInvoiceID(int InvoiceDeliveryOrderFreelineID, const QString &InvoiceID);
	bool setDescription(int InvoiceDeliveryOrderFreelineID, const QString &Description);
	bool setAmount(int InvoiceDeliveryOrderFreelineID, const QString &Amount);
	bool setPrice(int InvoiceDeliveryOrderFreelineID, const QString &Price);
	bool setCreatedOn(int InvoiceDeliveryOrderFreelineID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceDeliveryOrderFreelineID, const QString &EditedOn);

};
#endif
