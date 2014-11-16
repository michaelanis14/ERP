/**************************************************************************
**   File: bankaccount.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "bankaccount.h"
#include "erpmodel.h"

BankAccount::BankAccount()
 : QSqlRelationalTableModel(){

this->BankAccountID = 0 ;
this->Name = " ";
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
this->CreatedOn = " ";
this->EditedOn = " ";
this->setTable("BankAccount");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(9, QSqlRelation("Currency", "CurrencyID", "Description"));
this->setRelation(10, QSqlRelation("Contact", "ContactID", "Name"));
this->setRelation(11, QSqlRelation("Country", "CountryID", "Name"));
}
BankAccount::BankAccount(int BankAccountID,QString Name,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->BankAccountID = BankAccountID ;
this->Name = Name ;
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
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

BankAccount::BankAccount(QString Name,QString BankAddress,QString BankCode,QString AccountName,QString AccountNumber,QString IBAN,QString BIC,QString ZipCode,int CurrencyID,int ContactID,int CountryID,QString BankCountryCode,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->BankAccountID = 0 ;
this->Name = Name ;
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
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool BankAccount::Init()
{

QString table = "BankAccount";
QString query =
"(BankAccountID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (BankAccountID),"
"Name VARCHAR(40) NOT NULL, "
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
"BankCountryCode VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
BankAccount* BankAccount::p_instance = 0;
BankAccount* BankAccount::GetInstance() {
	if (p_instance == 0) {
		p_instance = new BankAccount();
		BankAccount::GetAll();
	}
return p_instance;
}
bool BankAccount::save() {
if(BankAccountID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString(); 
	this->EditedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO BankAccount (Name,BankAddress,BankCode,AccountName,AccountNumber,IBAN,BIC,ZipCode,CurrencyID,ContactID,CountryID,BankCountryCode,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->BankAddress)+"','"+QString(this->BankCode)+"','"+QString(this->AccountName)+"','"+QString(this->AccountNumber)+"','"+QString(this->IBAN)+"','"+QString(this->BIC)+"','"+QString(this->ZipCode)+"','"+QString::number(this->CurrencyID)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->CountryID)+"','"+QString(this->BankCountryCode)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE BankAccount SET ""Name = '"+QString(this->Name)+"','"+"BankAddress = '"+QString(this->BankAddress)+"','"+"BankCode = '"+QString(this->BankCode)+"','"+"AccountName = '"+QString(this->AccountName)+"','"+"AccountNumber = '"+QString(this->AccountNumber)+"','"+"IBAN = '"+QString(this->IBAN)+"','"+"BIC = '"+QString(this->BIC)+"','"+"ZipCode = '"+QString(this->ZipCode)+"','"+"CurrencyID = '"+QString::number(this->CurrencyID)+"','"+"ContactID = '"+QString::number(this->ContactID)+"','"+"CountryID = '"+QString::number(this->CountryID)+"','"+"BankCountryCode = '"+QString(this->BankCountryCode)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE BankAccountID ='"+QString::number(this->BankAccountID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  BankAccountID FROM BankAccount WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->BankAccountID = query.value(0).toInt();	
 } 
 }
return true;
}

bool BankAccount::remove() {
if(BankAccountID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM BankAccount WHERE BankAccountID ="+QString::number(this->BankAccountID)+""));
return true;
 }
return false;
}

BankAccount* BankAccount::get() {
if(BankAccountID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM BankAccount"
"WHERE BankAccountID ='"+QString::number(this->BankAccountID)+"'"));
while (query.next()) {
return new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString());
 }

}
return new BankAccount();
 }

QList<BankAccount*> BankAccount::GetAll() {
	BankAccount::GetInstance()->bankaccounts.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount"));
	while (query.next()) {
		BankAccount::GetInstance()->bankaccounts.append(new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString()));
	}
	return BankAccount::GetInstance()->bankaccounts;
}

BankAccount* BankAccount::Get(int id) {
BankAccount* bankaccount = new BankAccount();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM BankAccount WHERE BankAccountID = '"+QString::number(id)+"'"));
while (query.next()) {
bankaccount = new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString());
 }

}
return bankaccount;
}

BankAccount* BankAccount::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new BankAccount();
}

BankAccount* BankAccount::Get(QString name) {
BankAccount* bankaccount = new BankAccount();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount WHERE Name = '"+name+"'"));
while (query.next()) {
bankaccount = new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString());

 }

}
return bankaccount;
 }

QList<BankAccount*> BankAccount::Search(QString keyword) {
QList<BankAccount*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR BankAddress LIKE '%"+keyword+"%'"
"OR BankCode LIKE '%"+keyword+"%'"
"OR AccountName LIKE '%"+keyword+"%'"
"OR AccountNumber LIKE '%"+keyword+"%'"
"OR IBAN LIKE '%"+keyword+"%'"
"OR BIC LIKE '%"+keyword+"%'"
"OR ZipCode LIKE '%"+keyword+"%'"
"OR BankCountryCode LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString()));
 }

}
return list;
 }

QList<QString> BankAccount::GetStringList() {
	QList<QString> list;
	int count =BankAccount::GetInstance()->bankaccounts.count();
	if( count < 2){
		BankAccount::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.append(BankAccount::GetInstance()->bankaccounts[i]->Name);
	}
	return list;
}

QHash<int,QString> BankAccount::GetHashList() {
	QHash<int,QString> list;
	int count =BankAccount::GetInstance()->bankaccounts.count();
	if( count < 2){
		BankAccount::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(BankAccount::GetInstance()->bankaccounts[i]->BankAccountID,BankAccount::GetInstance()->bankaccounts[i]->Name);
	}
	return list;
}

int BankAccount::GetIndex(QString name) {
	int count =BankAccount::GetInstance()->bankaccounts.count();
	if( count < 2){
		BankAccount::GetAll();
	}
	for(int i = 0; i < count; i++){
		if(BankAccount::GetInstance()->bankaccounts[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<BankAccount*> BankAccount::QuerySelect(QString select) {
QList<BankAccount*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM BankAccount WHERE "+select+"" ));
while (query.next()) {
list.append(new BankAccount(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString()));
 }

}
return list;
 }

Qt::ItemFlags BankAccount::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 14)
flags |= Qt::ItemIsEditable;
return flags;
}

bool BankAccount::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setBankAddress(id, value.toString());
else if (index.column() == 3)
ok = setBankCode(id, value.toString());
else if (index.column() == 4)
ok = setAccountName(id, value.toString());
else if (index.column() == 5)
ok = setAccountNumber(id, value.toString());
else if (index.column() == 6)
ok = setIBAN(id, value.toString());
else if (index.column() == 7)
ok = setBIC(id, value.toString());
else if (index.column() == 8)
ok = setZipCode(id, value.toString());
else if (index.column() == 9)
ok = setCurrencyID(id, value.toString());
else if (index.column() == 10)
ok = setContactID(id, value.toString());
else if (index.column() == 11)
ok = setCountryID(id, value.toString());
else if (index.column() == 12)
ok = setBankCountryCode(id, value.toString());
else if (index.column() == 13)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 14)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool BankAccount::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->BankAccountID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void BankAccount::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() BankAccount!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Bank Address"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Bank Code"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Account Name"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Account Number"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("I B A N"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("B I C"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Zip Code"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Currency"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Country"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Bank Country Code"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool BankAccount::setName(int BankAccountID, const QString &Name) {
QSqlQuery query;
query.prepare("update BankAccount set Name = ? where BankAccountID = ?");
query.addBindValue(Name);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setBankAddress(int BankAccountID, const QString &BankAddress) {
QSqlQuery query;
query.prepare("update BankAccount set BankAddress = ? where BankAccountID = ?");
query.addBindValue(BankAddress);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setBankCode(int BankAccountID, const QString &BankCode) {
QSqlQuery query;
query.prepare("update BankAccount set BankCode = ? where BankAccountID = ?");
query.addBindValue(BankCode);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setAccountName(int BankAccountID, const QString &AccountName) {
QSqlQuery query;
query.prepare("update BankAccount set AccountName = ? where BankAccountID = ?");
query.addBindValue(AccountName);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setAccountNumber(int BankAccountID, const QString &AccountNumber) {
QSqlQuery query;
query.prepare("update BankAccount set AccountNumber = ? where BankAccountID = ?");
query.addBindValue(AccountNumber);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setIBAN(int BankAccountID, const QString &IBAN) {
QSqlQuery query;
query.prepare("update BankAccount set IBAN = ? where BankAccountID = ?");
query.addBindValue(IBAN);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setBIC(int BankAccountID, const QString &BIC) {
QSqlQuery query;
query.prepare("update BankAccount set BIC = ? where BankAccountID = ?");
query.addBindValue(BIC);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setZipCode(int BankAccountID, const QString &ZipCode) {
QSqlQuery query;
query.prepare("update BankAccount set ZipCode = ? where BankAccountID = ?");
query.addBindValue(ZipCode);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setCurrencyID(int BankAccountID, const QString &CurrencyID) {
QSqlQuery query;
query.prepare("update BankAccount set CurrencyID = ? where BankAccountID = ?");
query.addBindValue(CurrencyID);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setContactID(int BankAccountID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update BankAccount set ContactID = ? where BankAccountID = ?");
query.addBindValue(ContactID);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setCountryID(int BankAccountID, const QString &CountryID) {
QSqlQuery query;
query.prepare("update BankAccount set CountryID = ? where BankAccountID = ?");
query.addBindValue(CountryID);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setBankCountryCode(int BankAccountID, const QString &BankCountryCode) {
QSqlQuery query;
query.prepare("update BankAccount set BankCountryCode = ? where BankAccountID = ?");
query.addBindValue(BankCountryCode);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setCreatedOn(int BankAccountID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update BankAccount set CreatedOn = ? where BankAccountID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool BankAccount::setEditedOn(int BankAccountID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update BankAccount set EditedOn = ? where BankAccountID = ?");
query.addBindValue(EditedOn);
query.addBindValue(BankAccountID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

