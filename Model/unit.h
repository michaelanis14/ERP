/**************************************************************************
**   File: unit.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
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
	Unit(QString Description,QString CreatedOn,QString EditedOn);	int UnitID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	Unit* get();
	Unit* get(const QModelIndex &index);
	static Unit* Get(int id);
	static Unit* Get(QString name);
	static QList<Unit*> GetAll();
	static QList<Unit*> Search(QString keyword);
	static QList<Unit*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Unit* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Unit(int UnitID,QString Description,QString CreatedOn,QString EditedOn);	static Unit* p_instance;
	bool setDescription(int UnitID, const QString &Description);
	bool setCreatedOn(int UnitID, const QString &CreatedOn);
	bool setEditedOn(int UnitID, const QString &EditedOn);

};
#endif
