/**************************************************************************
**   File: contactperson.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTPERSON_H
#define CONTACTPERSON_H

#include <QtGui>

class ContactPerson
{
public:
	ContactPerson();
	ContactPerson(QString PersonalSalut,QString TitlePrefix,QString FirstName,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int CreatedBy_UserID,int EditedBy_UserID,int ContactID,QString CreatedOn,QString EditedOn);
	static bool init();
	bool save();
	bool remove();
	ContactPerson* get();
	static ContactPerson* get(int id);
	static ContactPerson* get(QString name);
	static QList<ContactPerson*> getAll();
	static QList<ContactPerson*> search(QString keyword);
	static QList<ContactPerson*> select(QString select);
private:
	ContactPerson(int ContactPersonID,QString PersonalSalut,QString TitlePrefix,QString FirstName,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int CreatedBy_UserID,int EditedBy_UserID,int ContactID,QString CreatedOn,QString EditedOn);
	int ContactPersonID;
	QString PersonalSalut;
	QString TitlePrefix;
	QString FirstName;
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
	int CreatedBy_UserID;
	int EditedBy_UserID;
	int ContactID;
	QString CreatedOn;
	QString EditedOn;
};
#endif
