/**************************************************************************
**   File: contactperson.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTPERSON_H
#define CONTACTPERSON_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "contactpersontelephone.h"
#include "contactpersonemail.h"
#include "projectcontactperson.h"

class ContactPerson  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactPerson();
	ContactPerson(QString Title,int ContactID,QString Name,QString LastName,QString Position,QString Birthdate,int Number,QString CreatedOn,QString EditedOn);	int ContactPersonID;
	QString Title;
	int ContactID;
	QString Name;
	QString LastName;
	QString Position;
	QString Birthdate;
	int Number;
	QList<ContactPersonTelephone*> contactpersontelephones;
	QList<ContactPersonEmail*> contactpersonemails;
	QList<ProjectContactPerson*> projectcontactpersons;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactPerson* get();
	ContactPerson* get(const QModelIndex &index);
	static ContactPerson* Get(int id);
	static ContactPerson* Get(QString name);
	static QList<ContactPerson*> GetAll();
	static QList<ContactPerson*> Search(QString keyword);
	static QList<ContactPerson*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactPerson*> contactpersons);
	static int GetIndex(QString title);
	static ContactPerson* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactPerson(int ContactPersonID,QString Title,int ContactID,QString Name,QString LastName,QString Position,QString Birthdate,int Number,QString CreatedOn,QString EditedOn);	static ContactPerson* p_instance;
	bool setTitle(int ContactPersonID, const QString &Title);
	bool setContactID(int ContactPersonID, const QString &ContactID);
	bool setName(int ContactPersonID, const QString &Name);
	bool setLastName(int ContactPersonID, const QString &LastName);
	bool setPosition(int ContactPersonID, const QString &Position);
	bool setBirthdate(int ContactPersonID, const QString &Birthdate);
	bool setNumber(int ContactPersonID, const QString &Number);
	bool setCreatedOn(int ContactPersonID, const QString &CreatedOn);
	bool setEditedOn(int ContactPersonID, const QString &EditedOn);

};
#endif
