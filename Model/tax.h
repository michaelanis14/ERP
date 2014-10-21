/**************************************************************************
**   File: tax.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
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
	Tax(double Ratio,QString Description);	int TaxID;
	double Ratio;
	QString Description;
	QList<Tax*> taxs;
	static bool init();
	bool save();
	bool remove();
	Tax* get();
	static Tax* get(int id);
	static Tax* get(QString name);
	static QList<Tax*> getAll();
	static QList<Tax*> search(QString keyword);
	static QList<Tax*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Tax* GetInstance();

private:
	Tax(int TaxID,double Ratio,QString Description);
	static Tax* p_instance;

};
#endif
