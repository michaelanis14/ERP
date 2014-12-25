/**************************************************************************
**   File: invoice.h
**   Created on: Fri Dec 19 22:39:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICE_H
#define INVOICE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "invoicestoreproduct.h"
#include "invoiceservice.h"
#include "invoicedeliveryorderfreeline.h"
#include "invoicefreeline.h"

class Invoice  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Invoice();
	Invoice(int Serial,int InvoiceSerialID,int ContactID,int ProjectID,QDate Date,int InvoicePeriodID,int InvoiceYearID,QDate DueDate,double discount,double Allowance,QString Header,QString Footer,QString Note,QString CreatedOn,QString EditedOn);	int InvoiceID;
	int Serial;
	int InvoiceSerialID;
	int ContactID;
	int ProjectID;
	QDate Date;
	int InvoicePeriodID;
	int InvoiceYearID;
	QDate DueDate;
	double discount;
	double Allowance;
	QString Header;
	QString Footer;
	QString Note;
	QList<InvoiceStoreProduct*> invoicestoreproducts;
	QList<InvoiceService*> invoiceservices;
	QList<InvoiceDeliveryOrderFreeline*> invoicedeliveryorderfreelines;
	QList<InvoiceFreeline*> invoicefreelines;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Invoice* get();
	Invoice* get(const QModelIndex &index);
	static Invoice* Get(int id);
	static Invoice* Get(QString name);
	static QList<Invoice*> GetAll();
	static QList<Invoice*> Search(QString keyword);
	static QList<Invoice*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Invoice*> invoices);
	static int GetIndex(QString title);
	static Invoice* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Invoice(int InvoiceID,int Serial,int InvoiceSerialID,int ContactID,int ProjectID,QDate Date,int InvoicePeriodID,int InvoiceYearID,QDate DueDate,double discount,double Allowance,QString Header,QString Footer,QString Note,QString CreatedOn,QString EditedOn);	static Invoice* p_instance;
	bool setSerial(int InvoiceID, const QString &Serial);
	bool setInvoiceSerialID(int InvoiceID, const QString &InvoiceSerialID);
	bool setContactID(int InvoiceID, const QString &ContactID);
	bool setProjectID(int InvoiceID, const QString &ProjectID);
	bool setDate(int InvoiceID, const QString &Date);
	bool setInvoicePeriodID(int InvoiceID, const QString &InvoicePeriodID);
	bool setInvoiceYearID(int InvoiceID, const QString &InvoiceYearID);
	bool setDueDate(int InvoiceID, const QString &DueDate);
	bool setdiscount(int InvoiceID, const QString &discount);
	bool setAllowance(int InvoiceID, const QString &Allowance);
	bool setHeader(int InvoiceID, const QString &Header);
	bool setFooter(int InvoiceID, const QString &Footer);
	bool setNote(int InvoiceID, const QString &Note);
	bool setCreatedOn(int InvoiceID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceID, const QString &EditedOn);

};
#endif
