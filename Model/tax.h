/**************************************************************************
**   File: tax.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef TAX_H
#define TAX_H

#include <QtGui>

class Tax
{
public:
	Tax();
	Tax(double Ratio,QString Description);
	static bool init();
	bool save();
	bool remove();
	Tax* get();
	static Tax* get(int id);
	static Tax* get(QString name);
	static QList<Tax*> getAll();
	static QList<Tax*> search(QString keyword);
	static QList<Tax*> select(QString select);
private:
	Tax(int TaxID,double Ratio,QString Description);
	int TaxID;
	double Ratio;
	QString Description;
};
#endif
