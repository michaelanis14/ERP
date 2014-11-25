/**************************************************************************
**   File: contactperson.h
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTPERSON_H
#define CONTACTPERSON_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactPerson  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactPerson();
	ContactPerson(QString PersonalSalut,QString TitlePrefix,QString Name,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int ContactID,QString CreatedOn,QString EditedOn);	int ContactPersonID;
	QString PersonalSalut;
	QString TitlePrefix;
	QString Name;
	QString LastName;
	QString Position;
	QString Birthdate;
	int ContactPersoneNumber;
	QString Email;
	QString PhoneNum;
	QString PhoneNum2;
	QString Mobile;
	QString Fax;
	bool active;
	int ContactID;
	QString CreatedOn;
	QString EditedOn;
	QList<ContactPerson*> contactpersons;
	static bool Init();
	bool save();
	bool remove();
	ContactPerson* get();
	ContactPerson* get(const QModelIndex &index);
	static ContactPerson* Get(int id);
	static ContactPerson* Get(QString name);
	static QList<ContactPerson*> GetAll();
	static QList<ContactPerson*> Search(QString keyword);
	static QList<ContactPerson*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactPerson* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactPerson(int ContactPersonID,QString PersonalSalut,QString TitlePrefix,QString Name,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int ContactID,QString CreatedOn,QString EditedOn);	static ContactPerson* p_instance;
	bool setPersonalSalut(int ContactPersonID, const QString &personalsalut);
	bool setTitlePrefix(int ContactPersonID, const QString &titleprefix);
	bool setName(int ContactPersonID, const QString &name);
	bool setLastName(int ContactPersonID, const QString &lastname);
	bool setPosition(int ContactPersonID, const QString &position);
	bool setBirthdate(int ContactPersonID, const QString &birthdate);
	bool setContactPersoneNumber(int ContactPersonID, const QString &contactpersonenumber);
	bool setEmail(int ContactPersonID, const QString &email);
	bool setPhoneNum(int ContactPersonID, const QString &phonenum);
	bool setPhoneNum2(int ContactPersonID, const QString &phonenum2);
	bool setMobile(int ContactPersonID, const QString &mobile);
	bool setFax(int ContactPersonID, const QString &fax);
	bool setactive(int ContactPersonID, const QString &active);
	bool setContactID(int ContactPersonID, const QString &contactid);
	bool setCreatedOn(int ContactPersonID, const QString &createdon);
	bool setEditedOn(int ContactPersonID, const QString &editedon);

};
#endif
