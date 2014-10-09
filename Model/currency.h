/**************************************************************************
**   File: currency.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
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
	Currency(QString Description);
	static bool init();
	bool save();
	bool remove();
	Currency* get();
	static Currency* get(int id);
	static Currency* get(QString name);
	static QList<Currency*> getAll();
	static QList<Currency*> search(QString keyword);
	static QList<Currency*> select(QString select);
private:
	Currency(int CurrencyID,QString Description);
	int CurrencyID;
	QString Description;
};
#endif
