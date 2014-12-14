/**************************************************************************
**   File: contactpersontelephone.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTPERSONTELEPHONE_H
#define CONTACTPERSONTELEPHONE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactPersonTelephone  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactPersonTelephone();
	ContactPersonTelephone(QString Description,int Number,int ContactPersonID,QString CreatedOn,QString EditedOn);	int ContactPersonTelephoneID;
	QString Description;
	int Number;
	int ContactPersonID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactPersonTelephone* get();
	ContactPersonTelephone* get(const QModelIndex &index);
	static ContactPersonTelephone* Get(int id);
	static ContactPersonTelephone* Get(QString name);
	static QList<ContactPersonTelephone*> GetAll();
	static QList<ContactPersonTelephone*> Search(QString keyword);
	static QList<ContactPersonTelephone*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactPersonTelephone*> contactpersontelephones);
	static int GetIndex(QString title);
	static ContactPersonTelephone* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactPersonTelephone(int ContactPersonTelephoneID,QString Description,int Number,int ContactPersonID,QString CreatedOn,QString EditedOn);	static ContactPersonTelephone* p_instance;
	bool setDescription(int ContactPersonTelephoneID, const QString &Description);
	bool setNumber(int ContactPersonTelephoneID, const QString &Number);
	bool setContactPersonID(int ContactPersonTelephoneID, const QString &ContactPersonID);
	bool setCreatedOn(int ContactPersonTelephoneID, const QString &CreatedOn);
	bool setEditedOn(int ContactPersonTelephoneID, const QString &EditedOn);

};
#endif
