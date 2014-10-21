/**************************************************************************
**   File: contact.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACT_H
#define CONTACT_H

#include <QtGui>
#include "bankaccount.h"

class Contact
{
public:
	Contact();
	Contact(QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn);	int ContactID;
	QString PersonalSalutation;
	QString Salutation;
	QString Name;
	QString LastName;
	QString BirthdateOrDateOfFoundation;
	int ContactTypeID;
	int ContactClassID;
	int ContactNumber;
	QString Address;
	QString PostalCode;
	QString City;
	int CountryID;
	int ContactStatusID;
	bool Active;
	int EmployeeID;
	QString PhoneNum;
	QString PhoneNum2;
	QString Fax;
	QString Mobile;
	QString Email;
	QString Email2;
	QString webSite;
	QString TaxNumber;
	QList<BankAccount*> bankaccounts;
	QString CreatedOn;
	QString EditedOn;
	QList<Contact*> contacts;
	static bool init();
	bool save();
	bool remove();
	Contact* get();
	static Contact* get(int id);
	static Contact* get(QString name);
	static QList<Contact*> getAll();
	static QList<Contact*> search(QString keyword);
	static QList<Contact*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Contact* GetInstance();

private:
	Contact(int ContactID,QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn);
	static Contact* p_instance;

};
#endif
