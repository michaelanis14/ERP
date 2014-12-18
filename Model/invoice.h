/**************************************************************************
**   File: invoice.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICE_H
#define INVOICE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "invoicestatedate.h"
#include "invoicefreeline.h"
#include "payment.h"

class Invoice  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Invoice();
	Invoice(int InvoiceSerialID,QDate CreationDate,QDate EndDate,int InvoicePeriodID,int InvoiceYearID,int ProjectID,QDate DueDate,double discount,double Allowance,QString Header,QString Footer,QString CreatedOn,QString EditedOn);	int InvoiceID;
	int InvoiceSerialID;
	QDate CreationDate;
	QDate EndDate;
	int InvoicePeriodID;
	int InvoiceYearID;
	int ProjectID;
	QDate DueDate;
	double discount;
	double Allowance;
	QList<InvoiceStateDate*> invoicestatedates;
	QList<InvoiceFreeline*> invoicefreelines;
	QList<Payment*> payments;
	QString Header;
	QString Footer;
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
	Invoice(int InvoiceID,int InvoiceSerialID,QDate CreationDate,QDate EndDate,int InvoicePeriodID,int InvoiceYearID,int ProjectID,QDate DueDate,double discount,double Allowance,QString Header,QString Footer,QString CreatedOn,QString EditedOn);	static Invoice* p_instance;
	bool setInvoiceSerialID(int InvoiceID, const QString &InvoiceSerialID);
	bool setCreationDate(int InvoiceID, const QString &CreationDate);
	bool setEndDate(int InvoiceID, const QString &EndDate);
	bool setInvoicePeriodID(int InvoiceID, const QString &InvoicePeriodID);
	bool setInvoiceYearID(int InvoiceID, const QString &InvoiceYearID);
	bool setProjectID(int InvoiceID, const QString &ProjectID);
	bool setDueDate(int InvoiceID, const QString &DueDate);
	bool setdiscount(int InvoiceID, const QString &discount);
	bool setAllowance(int InvoiceID, const QString &Allowance);
	bool setHeader(int InvoiceID, const QString &Header);
	bool setFooter(int InvoiceID, const QString &Footer);
	bool setCreatedOn(int InvoiceID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceID, const QString &EditedOn);

};
#endif
