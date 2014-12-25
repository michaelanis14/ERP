/**************************************************************************
**   File: invoiceservice.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICESERVICE_H
#define INVOICESERVICE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceService  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceService();
	InvoiceService(int InvoiceID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn);	int InvoiceServiceID;
	int InvoiceID;
	int ServiceID;
	double Amount;
	double Price;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	InvoiceService* get();
	InvoiceService* get(const QModelIndex &index);
	static InvoiceService* Get(int id);
	static InvoiceService* Get(QString name);
	static QList<InvoiceService*> GetAll();
	static QList<InvoiceService*> Search(QString keyword);
	static QList<InvoiceService*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<InvoiceService*> invoiceservices);
	static int GetIndex(QString title);
	static InvoiceService* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceService(int InvoiceServiceID,int InvoiceID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn);	static InvoiceService* p_instance;
	bool setInvoiceID(int InvoiceServiceID, const QString &InvoiceID);
	bool setServiceID(int InvoiceServiceID, const QString &ServiceID);
	bool setAmount(int InvoiceServiceID, const QString &Amount);
	bool setPrice(int InvoiceServiceID, const QString &Price);
	bool setCreatedOn(int InvoiceServiceID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceServiceID, const QString &EditedOn);

};
#endif
