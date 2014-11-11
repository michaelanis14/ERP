/**************************************************************************
**   File: bankaccount.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class BankAccount  : public QSqlRelationalTableModel
{
	Q_OBJECT
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
	static QList<BankAccount*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static BankAccount* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	BankAccount(int BankAccountID,QString Name,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode);	static BankAccount* p_instance;
	bool setName(int BankAccountID, const QString &name);
	bool setBankAddress(int BankAccountID, const QString &bankaddress);
	bool setBankCode(int BankAccountID, const QString &bankcode);
	bool setAccountName(int BankAccountID, const QString &accountname);
	bool setAccountNumber(int BankAccountID, const QString &accountnumber);
	bool setIBAN(int BankAccountID, const QString &iban);
	bool setBIC(int BankAccountID, const QString &bic);
	bool setZipCode(int BankAccountID, const QString &zipcode);
	bool setCurrencyID(int BankAccountID, const QString &currencyid);
	bool setContactID(int BankAccountID, const QString &contactid);
	bool setCountryID(int BankAccountID, const QString &countryid);
	bool setBankCountryCode(int BankAccountID, const QString &bankcountrycode);

};
#endif
