/**************************************************************************
**   File: currency.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
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
	Currency(QString Description);	int CurrencyID;
	QString Description;
	QList<Currency*> currencys;
	static bool init();
	bool save();
	bool remove();
	Currency* get();
	static Currency* get(int id);
	static Currency* get(QString name);
	static QList<Currency*> getAll();
	static QList<Currency*> search(QString keyword);
	static QList<Currency*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Currency* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Currency(int CurrencyID,QString Description);	static Currency* p_instance;
	bool setDescription(int CurrencyID, const QString &description);

};
#endif
