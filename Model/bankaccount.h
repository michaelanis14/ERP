/**************************************************************************
**   File: bankaccount.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QtGui>

class BankAccount
{
public:
	BankAccount();
	BankAccount(QString BankName,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode);
	static bool init();
	bool save();
	bool remove();
	BankAccount* get();
	static BankAccount* get(int id);
	static BankAccount* get(QString name);
	static QList<BankAccount*> getAll();
	static QList<BankAccount*> search(QString keyword);
	static QList<BankAccount*> select(QString select);
private:
	BankAccount(int BankAccountID,QString BankName,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode);
	int BankAccountID;
	QString BankName;
	QString BankAddress;
	QString BankCode;
	QString AccountName;
	QString AccountNumber;
	QString IBAN;
	QString BIC;
	QString ZipCode;
	int CurrencyID;
	int ContactID;
	int CountryID;
	QString BankCountryCode;
};
#endif
