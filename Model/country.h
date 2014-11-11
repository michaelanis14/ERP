/**************************************************************************
**   File: country.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef COUNTRY_H
#define COUNTRY_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Country  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Country();
	Country(QString Name);	int CountryID;
	QString Name;
	QList<Country*> countrys;
	static bool init();
	bool save();
	bool remove();
	Country* get();
	static Country* get(int id);
	static Country* get(QString name);
	static QList<Country*> getAll();
	static QList<Country*> search(QString keyword);
	static QList<Country*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Country* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Country(int CountryID,QString Name);	static Country* p_instance;
	bool setName(int CountryID, const QString &name);

};
#endif
