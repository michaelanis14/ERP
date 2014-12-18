/**************************************************************************
**   File: store.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef STORE_H
#define STORE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Store  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Store();
	Store(QString Name,QString Address,QString PostalCode,QString City,int CountryID,QString CreatedOn,QString EditedOn);	int StoreID;
	QString Name;
	QString Address;
	QString PostalCode;
	QString City;
	int CountryID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Store* get();
	Store* get(const QModelIndex &index);
	static Store* Get(int id);
	static Store* Get(QString name);
	static QList<Store*> GetAll();
	static QList<Store*> Search(QString keyword);
	static QList<Store*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Store*> stores);
	static int GetIndex(QString title);
	static Store* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Store(int StoreID,QString Name,QString Address,QString PostalCode,QString City,int CountryID,QString CreatedOn,QString EditedOn);	static Store* p_instance;
	bool setName(int StoreID, const QString &Name);
	bool setAddress(int StoreID, const QString &Address);
	bool setPostalCode(int StoreID, const QString &PostalCode);
	bool setCity(int StoreID, const QString &City);
	bool setCountryID(int StoreID, const QString &CountryID);
	bool setCreatedOn(int StoreID, const QString &CreatedOn);
	bool setEditedOn(int StoreID, const QString &EditedOn);

};
#endif
