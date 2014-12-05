/**************************************************************************
**   File: invoiceyear.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef INVOICEYEAR_H
#define INVOICEYEAR_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class InvoiceYear  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	InvoiceYear();
	InvoiceYear(QString Description,QString CreatedOn,QString EditedOn);	int InvoiceYearID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	InvoiceYear* get();
	InvoiceYear* get(const QModelIndex &index);
	static InvoiceYear* Get(int id);
	static InvoiceYear* Get(QString name);
	static QList<InvoiceYear*> GetAll();
	static QList<InvoiceYear*> Search(QString keyword);
	static QList<InvoiceYear*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static InvoiceYear* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	InvoiceYear(int InvoiceYearID,QString Description,QString CreatedOn,QString EditedOn);	static InvoiceYear* p_instance;
	bool setDescription(int InvoiceYearID, const QString &Description);
	bool setCreatedOn(int InvoiceYearID, const QString &CreatedOn);
	bool setEditedOn(int InvoiceYearID, const QString &EditedOn);

};
#endif
