/**************************************************************************
**   File: invoicestate.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICESTATE_H
#define INVOICESTATE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceState  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceState();
	InvoiceState(QString Description,QString CreatedOn,QString EditedOn);	int InvoiceStateID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	InvoiceState* get();
	InvoiceState* get(const QModelIndex &index);
	static InvoiceState* Get(int id);
	static InvoiceState* Get(QString name);
	static QList<InvoiceState*> GetAll();
	static QList<InvoiceState*> Search(QString keyword);
	static QList<InvoiceState*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<InvoiceState*> invoicestates);
	static int GetIndex(QString title);
	static InvoiceState* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceState(int InvoiceStateID,QString Description,QString CreatedOn,QString EditedOn);	static InvoiceState* p_instance;
	bool setDescription(int InvoiceStateID, const QString &Description);
	bool setCreatedOn(int InvoiceStateID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceStateID, const QString &EditedOn);

};
#endif
