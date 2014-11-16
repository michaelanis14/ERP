/**************************************************************************
**   File: country.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
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
	Country(QString Name,QString CreatedOn,QString EditedOn);	int CountryID;
	QString Name;
	QString CreatedOn;
	QString EditedOn;
	QList<Country*> countrys;
	static bool Init();
	bool save();
	bool remove();
	Country* get();
	Country* get(const QModelIndex &index);
	static Country* Get(int id);
	static Country* Get(QString name);
	static QList<Country*> GetAll();
	static QList<Country*> Search(QString keyword);
	static QList<Country*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Country* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Country(int CountryID,QString Name,QString CreatedOn,QString EditedOn);	static Country* p_instance;
	bool setName(int CountryID, const QString &name);
	bool setCreatedOn(int CountryID, const QString &createdon);
	bool setEditedOn(int CountryID, const QString &editedon);

};
#endif
