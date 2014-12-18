/**************************************************************************
**   File: invoicefreeline.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICEFREELINE_H
#define INVOICEFREELINE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceFreeline  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceFreeline();
	InvoiceFreeline(QString Description,int InvoiceID,double Price,int TaxID,double Amount,QString CreatedOn,QString EditedOn);	int InvoiceFreelineID;
	QString Description;
	int InvoiceID;
	double Price;
	int TaxID;
	double Amount;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	InvoiceFreeline* get();
	InvoiceFreeline* get(const QModelIndex &index);
	static InvoiceFreeline* Get(int id);
	static InvoiceFreeline* Get(QString name);
	static QList<InvoiceFreeline*> GetAll();
	static QList<InvoiceFreeline*> Search(QString keyword);
	static QList<InvoiceFreeline*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<InvoiceFreeline*> invoicefreelines);
	static int GetIndex(QString title);
	static InvoiceFreeline* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceFreeline(int InvoiceFreelineID,QString Description,int InvoiceID,double Price,int TaxID,double Amount,QString CreatedOn,QString EditedOn);	static InvoiceFreeline* p_instance;
	bool setDescription(int InvoiceFreelineID, const QString &Description);
	bool setInvoiceID(int InvoiceFreelineID, const QString &InvoiceID);
	bool setPrice(int InvoiceFreelineID, const QString &Price);
	bool setTaxID(int InvoiceFreelineID, const QString &TaxID);
	bool setAmount(int InvoiceFreelineID, const QString &Amount);
	bool setCreatedOn(int InvoiceFreelineID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceFreelineID, const QString &EditedOn);

};
#endif
