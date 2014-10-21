/**************************************************************************
**   File: bankaccount.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
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
	BankAccount(QString Name,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode);	int BankAccountID;
	QString Name;
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
	QList<BankAccount*> bankaccounts;
	static bool init();
	bool save();
	bool remove();
	BankAccount* get();
	static BankAccount* get(int id);
	static BankAccount* get(QString name);
	static QList<BankAccount*> getAll();
	static QList<BankAccount*> search(QString keyword);
	static QList<BankAccount*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static BankAccount* GetInstance();

private:
	BankAccount(int BankAccountID,QString Name,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode);
	static BankAccount* p_instance;

};
#endif
