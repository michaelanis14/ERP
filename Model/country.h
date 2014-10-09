/**************************************************************************
**   File: country.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef COUNTRY_H
#define COUNTRY_H

#include <QtGui>

class Country
{
public:
	Country();
	Country(QString Name);
	static bool init();
	bool save();
	bool remove();
	Country* get();
	static Country* get(int id);
	static Country* get(QString name);
	static QList<Country*> getAll();
	static QList<Country*> search(QString keyword);
	static QList<Country*> select(QString select);
private:
	Country(int CountryID,QString Name);
	int CountryID;
	QString Name;
};
#endif
