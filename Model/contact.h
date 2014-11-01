/**************************************************************************
**   File: contact.h
**   Created on: Thu Oct 30 11:58:54 EET 2014
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
	static QList<Contact*> selectt(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Contact* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);
private:
	Contact(int ContactID,QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn);
	static Contact* p_instance;

	bool setFirstName(int personId, const QString &firstName);
	bool setLastName(int personId, const QString &lastName);

};
#endif
