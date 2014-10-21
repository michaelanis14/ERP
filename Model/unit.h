/**************************************************************************
**   File: unit.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
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
	Unit(QString Description);	int UnitID;
	QString Description;
	QList<Unit*> units;
	static bool init();
	bool save();
	bool remove();
	Unit* get();
	static Unit* get(int id);
	static Unit* get(QString name);
	static QList<Unit*> getAll();
	static QList<Unit*> search(QString keyword);
	static QList<Unit*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Unit* GetInstance();

private:
	Unit(int UnitID,QString Description);
	static Unit* p_instance;

};
#endif
