/**************************************************************************
**   File: currency.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CURRENCY_H
#define CURRENCY_H

#include <QtGui>

class Currency
{
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
	static QList<Currency*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Currency* GetInstance();

private:
	Currency(int CurrencyID,QString Description);
	static Currency* p_instance;

};
#endif
