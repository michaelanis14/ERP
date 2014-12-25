/**************************************************************************
**   File: bankaccount.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
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
	BankAccount(QString Name,int CountryID,QString BankCode,QString BankAddress,QString AccountNumber,QString AccountOwner,QString IBAN,QString BIC,int CurrencyID,int ContactID,QString CreatedOn,QString EditedOn);	int BankAccountID;
	QString Name;
	int CountryID;
	QString BankCode;
	QString BankAddress;
	QString AccountNumber;
	QString AccountOwner;
	QString IBAN;
	QString BIC;
	int CurrencyID;
	int ContactID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	BankAccount* get();
	BankAccount* get(const QModelIndex &index);
	static BankAccount* Get(int id);
	static BankAccount* Get(QString name);
	static QList<BankAccount*> GetAll();
	static QList<BankAccount*> Search(QString keyword);
	static QList<BankAccount*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<BankAccount*> bankaccounts);
	static int GetIndex(QString title);
	static BankAccount* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	BankAccount(int BankAccountID,QString Name,int CountryID,QString BankCode,QString BankAddress,QString AccountNumber,QString AccountOwner,QString IBAN,QString BIC,int CurrencyID,int ContactID,QString CreatedOn,QString EditedOn);	static BankAccount* p_instance;
	bool setName(int BankAccountID, const QString &Name);
	bool setCountryID(int BankAccountID, const QString &CountryID);
	bool setBankCode(int BankAccountID, const QString &BankCode);
	bool setBankAddress(int BankAccountID, const QString &BankAddress);
	bool setAccountNumber(int BankAccountID, const QString &AccountNumber);
	bool setAccountOwner(int BankAccountID, const QString &AccountOwner);
	bool setIBAN(int BankAccountID, const QString &IBAN);
	bool setBIC(int BankAccountID, const QString &BIC);
	bool setCurrencyID(int BankAccountID, const QString &CurrencyID);
	bool setContactID(int BankAccountID, const QString &ContactID);
	bool setCreatedOn(int BankAccountID, const QString &CreatedOn);
	bool setEditedOn(int BankAccountID, const QString &EditedOn);

};
#endif
