/**************************************************************************
**   File: contact.h
**   Created on: Tue Nov 04 17:16:43 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACT_H
#define CONTACT_H

#include <QSqlRelationalTableModel>
#include <QtGui>
#include "bankaccount.h"

class Contact  : public QSqlRelationalTableModel
{
	Q_OBJECT
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
	static QList<Contact*> querySelect(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Contact* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Contact(int ContactID,QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn);	static Contact* p_instance;
	bool setPersonalSalutation(int ContactID, const QString &personalsalutation);
	bool setSalutation(int ContactID, const QString &salutation);
	bool setName(int ContactID, const QString &name);
	bool setLastName(int ContactID, const QString &lastname);
	bool setBirthdateOrDateOfFoundation(int ContactID, const QString &birthdateordateoffoundation);
	bool setContactTypeID(int ContactID, const QString &contacttypeid);
	bool setContactClassID(int ContactID, const QString &contactclassid);
	bool setContactNumber(int ContactID, const QString &contactnumber);
	bool setAddress(int ContactID, const QString &address);
	bool setPostalCode(int ContactID, const QString &postalcode);
	bool setCity(int ContactID, const QString &city);
	bool setCountryID(int ContactID, const QString &countryid);
	bool setContactStatusID(int ContactID, const QString &contactstatusid);
	bool setActive(int ContactID, const QString &active);
	bool setEmployeeID(int ContactID, const QString &employeeid);
	bool setPhoneNum(int ContactID, const QString &phonenum);
	bool setPhoneNum2(int ContactID, const QString &phonenum2);
	bool setFax(int ContactID, const QString &fax);
	bool setMobile(int ContactID, const QString &mobile);
	bool setEmail(int ContactID, const QString &email);
	bool setEmail2(int ContactID, const QString &email2);
	bool setwebSite(int ContactID, const QString &website);
	bool setTaxNumber(int ContactID, const QString &taxnumber);
	bool setCreatedOn(int ContactID, const QString &createdon);
	bool setEditedOn(int ContactID, const QString &editedon);

};
#endif
