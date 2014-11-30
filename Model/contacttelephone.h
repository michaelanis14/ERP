/**************************************************************************
**   File: contacttelephone.h
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTTELEPHONE_H
#define CONTACTTELEPHONE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactTelephone  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactTelephone();
	ContactTelephone(QString Description,int Number,int ContactID,QString CreatedOn,QString EditedOn);	int ContactTelephoneID;
	QString Description;
	int Number;
	int ContactID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	ContactTelephone* get();
	ContactTelephone* get(const QModelIndex &index);
	static ContactTelephone* Get(int id);
	static ContactTelephone* Get(QString name);
	static QList<ContactTelephone*> GetAll();
	static QList<ContactTelephone*> Search(QString keyword);
	static QList<ContactTelephone*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactTelephone* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactTelephone(int ContactTelephoneID,QString Description,int Number,int ContactID,QString CreatedOn,QString EditedOn);	static ContactTelephone* p_instance;
	bool setDescription(int ContactTelephoneID, const QString &Description);
	bool setNumber(int ContactTelephoneID, const QString &Number);
	bool setContactID(int ContactTelephoneID, const QString &ContactID);
	bool setCreatedOn(int ContactTelephoneID, const QString &CreatedOn);
	bool setEditedOn(int ContactTelephoneID, const QString &EditedOn);

};
#endif
