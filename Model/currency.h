/**************************************************************************
**   File: currency.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
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
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Currency* get();
	Currency* get(const QModelIndex &index);
	static Currency* Get(int id);
	static Currency* Get(QString name);
	static QList<Currency*> GetAll();
	static QList<Currency*> Search(QString keyword);
	static QList<Currency*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Currency*> currencys);
	static int GetIndex(QString title);
	static Currency* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Currency(int CurrencyID,QString Description,QString CreatedOn,QString EditedOn);	static Currency* p_instance;
	bool setDescription(int CurrencyID, const QString &Description);
	bool setCreatedOn(int CurrencyID, const QString &CreatedOn);
	bool setEditedOn(int CurrencyID, const QString &EditedOn);

};
#endif
