/**************************************************************************
**   File: bankaccount.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "bankaccount.h"
#include "erpmodel.h"

BankAccount::BankAccount()
{

this->BankAccountID = 0 ;
this->BankName = " ";
this->BankAddress = " ";
this->BankCode = " ";
this->AccountName = " ";
this->AccountNumber = " ";
this->IBAN = " ";
this->BIC = " ";
this->ZipCode = " ";
this->CurrencyID = 0 ;
this->ContactID = 0 ;
this->CountryID = 0 ;
this->BankCountryCode = " ";
}
BankAccount::BankAccount(int BankAccountID,QString BankName,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode){
this->BankAccountID = BankAccountID ;
this->BankName = BankName ;
this->BankAddress = BankAddress ;
this->BankCode = BankCode ;
this->AccountName = AccountName ;
this->AccountNumber = AccountNumber ;
this->IBAN = IBAN ;
this->BIC = BIC ;
this->ZipCode = ZipCode ;
this->CurrencyID = CurrencyID ;
this->ContactID = ContactID ;
this->CountryID = CountryID ;
this->BankCountryCode = BankCountryCode ;
}

BankAccount::BankAccount(QString BankName,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode){
this->BankName = BankName ;
this->BankAddress = BankAddress ;
this->BankCode = BankCode ;
this->AccountName = AccountName ;
this->AccountNumber = AccountNumber ;
this->IBAN = IBAN ;
this->BIC = BIC ;
this->ZipCode = ZipCode ;
this->CurrencyID = CurrencyID ;
this->ContactID = ContactID ;
this->CountryID = CountryID ;
this->BankCountryCode = BankCountryCode ;
}

bool BankAccount::init()
{

QString table = "BankAccount";
QString query =
"(BankAccountID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (BankAccountID),"
"BankName VARCHAR(40) NOT NULL, "
"BankAddress VARCHAR(40) NOT NULL, "
"BankCode VARCHAR(40) NOT NULL, "
"AccountName VARCHAR(40) NOT NULL, "
"AccountNumber VARCHAR(40) NOT NULL, "
"IBAN VARCHAR(40) NOT NULL, "
"BIC VARCHAR(40) NOT NULL, "
"ZipCode VARCHAR(40) NOT NULL, "
"CurrencyID INT NOT NULL, "
"FOREIGN KEY (CurrencyID) REFERENCES Currency(CurrencyID),"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID),"
"CountryID INT NOT NULL, "
"FOREIGN KEY (CountryID) REFERENCES Country(CountryID),"
"BankCountryCode VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool BankAccount::save() {
if(BankAccountID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO BankAccount (BankName,BankAddress,BankCode,AccountName,AccountNumber,IBAN,BIC,ZipCode,CurrencyID,ContactID,CountryID,BankCountryCode)"
"VALUES ('" +QString(this->BankName)+"','"+QString(this->BankAddress)+"','"+QString(this->BankCode)+"','"+QString(this->AccountName)+"','"+QString(this->AccountNumber)+"','"+QString(this->IBAN)+"','"+QString(this->BIC)+"','"+QString(this->ZipCode)+"','"+QString::number(this->CurrencyID)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->CountryID)+"','"+QString(this->BankCountryCode)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE BankAccount SET ""BankName = '"+QString(this->BankName)+"','"+"BankAddress = '"+QString(this->BankAddress)+"','"+"BankCode = '"+QString(this->BankCode)+"','"+"AccountName = '"+QString(this->AccountName)+"','"+"AccountNumber = '"+QString(this->AccountNumber)+"','"+"IBAN = '"+QString(this->IBAN)+"','"+"BIC = '"+QString(this->BIC)+"','"+"ZipCode = '"+QString(this->ZipCode)+"','"+"CurrencyID = '"+QString::number(this->CurrencyID)+"','"+"ContactID = '"+QString::number(this->ContactID)+"','"+"CountryID = '"+QString::number(this->CountryID)+"','"+"BankCountryCode = '"+QString(this->BankCountryCode)+"' WHERE BankAccountID ='"+QString::number(this->BankAccountID)+"'");
 }
return true;
}

bool BankAccount::remove() {
if(BankAccountID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM BankAccount"
"WHERE BankAccountID ='"+QString::number(this->BankAccountID)+"'"));
return true;
 }
return false;
}

BankAccount* BankAccount::get() {
if(BankAccountID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM BankAccount"
"WHERE BankAccountID ='"+QString::number(this->BankAccountID)+"'"));
while (query.next()) {
return new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString());
 }

}
return new BankAccount();
 }

QList<BankAccount*> BankAccount::getAll() {
QList<BankAccount*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount"));
while (query.next()) {
list.append(new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString()));
}
return list;
 }

BankAccount* BankAccount::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM BankAccount"
"WHERE BankAccountID = '"+QString::number(id)+"'"));
while (query.next()) {
return new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString());
 }

}
return new BankAccount();
 }

BankAccount* BankAccount::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount"
"WHERE BankName = '"+name+"'"));
while (query.next()) {
return new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString());
 }

}
return new BankAccount();
 }

QList<BankAccount*> BankAccount::search(QString keyword) {
QList<BankAccount*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount"
"WHERE" 
"BankName LIKE '%"+keyword+"%'"
"OR BankAddress LIKE '%"+keyword+"%'"
"OR BankCode LIKE '%"+keyword+"%'"
"OR AccountName LIKE '%"+keyword+"%'"
"OR AccountNumber LIKE '%"+keyword+"%'"
"OR IBAN LIKE '%"+keyword+"%'"
"OR BIC LIKE '%"+keyword+"%'"
"OR ZipCode LIKE '%"+keyword+"%'"
"OR BankCountryCode LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString()));
 }

}
return list;
 }

QList<BankAccount*> BankAccount::select(QString select) {
QList<BankAccount*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString()));
 }

}
return list;
 }
