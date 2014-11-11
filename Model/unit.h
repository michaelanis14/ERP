/**************************************************************************
**   File: unit.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef UNIT_H
#define UNIT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Unit  : public QSqlRelationalTableModel
{
	Q_OBJECT
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
	static QList<Unit*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Unit* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Unit(int UnitID,QString Description);	static Unit* p_instance;
	bool setDescription(int UnitID, const QString &description);

};
#endif
