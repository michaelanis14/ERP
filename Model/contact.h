/**************************************************************************
**   File: contact.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACT_H
#define CONTACT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>
#include "contacttelephone.h"
#include "contactemail.h"
#include "bankaccount.h"
#include "contactfielddata.h"

class Contact  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Contact();
	Contact(QString Salutation,QString Name,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int Number,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,int EmployeeID,QString Website,QString TaxNumber,QString CreatedOn,QString EditedOn);	int ContactID;
	QString Salutation;
	QString Name;
	QString BirthdateOrDateOfFoundation;
	int ContactTypeID;
	int ContactClassID;
	int Number;
	QString Address;
	QString PostalCode;
	QString City;
	int CountryID;
	int ContactStatusID;
	int EmployeeID;
	QString Website;
	QString TaxNumber;
	QList<ContactTelephone*> contacttelephones;
	QList<ContactEmail*> contactemails;
	QList<BankAccount*> bankaccounts;
	QList<ContactFieldData*> contactfielddatas;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	Contact* get();
	Contact* get(const QModelIndex &index);
	static Contact* Get(int id);
	static Contact* Get(QString name);
	static QList<Contact*> GetAll();
	static QList<Contact*> Search(QString keyword);
	static QList<Contact*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Contact* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Contact(int ContactID,QString Salutation,QString Name,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int Number,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,int EmployeeID,QString Website,QString TaxNumber,QString CreatedOn,QString EditedOn);	static Contact* p_instance;
	bool setSalutation(int ContactID, const QString &Salutation);
	bool setName(int ContactID, const QString &Name);
	bool setBirthdateOrDateOfFoundation(int ContactID, const QString &BirthdateOrDateOfFoundation);
	bool setContactTypeID(int ContactID, const QString &ContactTypeID);
	bool setContactClassID(int ContactID, const QString &ContactClassID);
	bool setNumber(int ContactID, const QString &Number);
	bool setAddress(int ContactID, const QString &Address);
	bool setPostalCode(int ContactID, const QString &PostalCode);
	bool setCity(int ContactID, const QString &City);
	bool setCountryID(int ContactID, const QString &CountryID);
	bool setContactStatusID(int ContactID, const QString &ContactStatusID);
	bool setEmployeeID(int ContactID, const QString &EmployeeID);
	bool setWebsite(int ContactID, const QString &Website);
	bool setTaxNumber(int ContactID, const QString &TaxNumber);
	bool setCreatedOn(int ContactID, const QString &CreatedOn);
	bool setEditedOn(int ContactID, const QString &EditedOn);

};
#endif
