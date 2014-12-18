/**************************************************************************
**   File: invoiceserial.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICESERIAL_H
#define INVOICESERIAL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceSerial  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceSerial();
	InvoiceSerial(QString Title,int Serial,QString CreatedOn,QString EditedOn);	int InvoiceSerialID;
	QString Title;
	int Serial;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	InvoiceSerial* get();
	InvoiceSerial* get(const QModelIndex &index);
	static InvoiceSerial* Get(int id);
	static InvoiceSerial* Get(QString name);
	static QList<InvoiceSerial*> GetAll();
	static QList<InvoiceSerial*> Search(QString keyword);
	static QList<InvoiceSerial*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<InvoiceSerial*> invoiceserials);
	static int GetIndex(QString title);
	static InvoiceSerial* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceSerial(int InvoiceSerialID,QString Title,int Serial,QString CreatedOn,QString EditedOn);	static InvoiceSerial* p_instance;
	bool setTitle(int InvoiceSerialID, const QString &Title);
	bool setSerial(int InvoiceSerialID, const QString &Serial);
	bool setCreatedOn(int InvoiceSerialID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceSerialID, const QString &EditedOn);

};
#endif
