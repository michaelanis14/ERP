/**************************************************************************
**   File: contact.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACT_H
#define CONTACT_H

#include <QtGui>

class Contact
{
public:
	Contact();
	Contact(QString Name,QString PersonalSalut,QString TitlePrefix,QString CO,QString Birthdate,int ContactTypeID,int ContactStatusID,int ContactClassID,int ContactNumber,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString Address,QString PostalCode,QString City,int CountryID,bool Active,int EmployeeID,QString CreatedOn,QString EditedOn);
	static bool init();
	bool save();
	bool remove();
	Contact* get();
	static Contact* get(int id);
	static Contact* get(QString name);
	static QList<Contact*> getAll();
	static QList<Contact*> search(QString keyword);
	static QList<Contact*> select(QString select);
private:
	Contact(int ContactID,QString Name,QString PersonalSalut,QString TitlePrefix,QString CO,QString Birthdate,int ContactTypeID,int ContactStatusID,int ContactClassID,int ContactNumber,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString Address,QString PostalCode,QString City,int CountryID,bool Active,int EmployeeID,QString CreatedOn,QString EditedOn);
	int ContactID;
	QString Name;
	QString PersonalSalut;
	QString TitlePrefix;
	QString CO;
	QString Birthdate;
	int ContactTypeID;
	int ContactStatusID;
	int ContactClassID;
	int ContactNumber;
	QString PhoneNum;
	QString PhoneNum2;
	QString Fax;
	QString Mobile;
	QString Email;
	QString Email2;
	QString webSite;
	QString TaxNumber;
	QString Address;
	QString PostalCode;
	QString City;
	int CountryID;
	bool Active;
	int EmployeeID;
	QString CreatedOn;
	QString EditedOn;
};
#endif
