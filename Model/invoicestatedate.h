/**************************************************************************
**   File: invoicestatedate.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICESTATEDATE_H
#define INVOICESTATEDATE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceStateDate  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceStateDate();
	InvoiceStateDate(int InvoiceID,int InvoiceStateID,QString Date,QString CreatedOn,QString EditedOn);	int InvoiceStateDateID;
	int InvoiceID;
	int InvoiceStateID;
	QString Date;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	InvoiceStateDate* get();
	InvoiceStateDate* get(const QModelIndex &index);
	static InvoiceStateDate* Get(int id);
	static InvoiceStateDate* Get(QString name);
	static QList<InvoiceStateDate*> GetAll();
	static QList<InvoiceStateDate*> Search(QString keyword);
	static QList<InvoiceStateDate*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<InvoiceStateDate*> invoicestatedates);
	static int GetIndex(QString title);
	static InvoiceStateDate* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceStateDate(int InvoiceStateDateID,int InvoiceID,int InvoiceStateID,QString Date,QString CreatedOn,QString EditedOn);	static InvoiceStateDate* p_instance;
	bool setInvoiceID(int InvoiceStateDateID, const QString &InvoiceID);
	bool setInvoiceStateID(int InvoiceStateDateID, const QString &InvoiceStateID);
	bool setDate(int InvoiceStateDateID, const QString &Date);
	bool setCreatedOn(int InvoiceStateDateID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceStateDateID, const QString &EditedOn);

};
#endif
