/**************************************************************************
**   File: currency.h
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CURRENCY_H
#define CURRENCY_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Currency  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Currency();
	Currency(QString Description,QString CreatedOn,QString EditedOn);	int CurrencyID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	QList<Currency*> currencys;
	static bool Init();
	bool save();
	bool remove();
	Currency* get();
	Currency* get(const QModelIndex &index);
	static Currency* Get(int id);
	static Currency* Get(QString name);
	static QList<Currency*> GetAll();
	static QList<Currency*> Search(QString keyword);
	static QList<Currency*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Currency* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Currency(int CurrencyID,QString Description,QString CreatedOn,QString EditedOn);	static Currency* p_instance;
	bool setDescription(int CurrencyID, const QString &description);
	bool setCreatedOn(int CurrencyID, const QString &createdon);
	bool setEditedOn(int CurrencyID, const QString &editedon);

};
#endif
