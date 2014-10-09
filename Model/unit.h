/**************************************************************************
**   File: unit.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef UNIT_H
#define UNIT_H

#include <QtGui>

class Unit
{
public:
	Unit();
	Unit(QString Description);
	static bool init();
	bool save();
	bool remove();
	Unit* get();
	static Unit* get(int id);
	static Unit* get(QString name);
	static QList<Unit*> getAll();
	static QList<Unit*> search(QString keyword);
	static QList<Unit*> select(QString select);
private:
	Unit(int UnitID,QString Description);
	int UnitID;
	QString Description;
};
#endif
