/**************************************************************************
**   File: contact.cpp
**   Created on: Sun Nov 16 16:19:25 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contact.h"
#include "erpmodel.h"

Contact::Contact()
 : QSqlRelationalTableModel(){

this->ContactID = 0 ;
this->PersonalSalutation = " ";
this->Salutation = " ";
this->Name = " ";
this->LastName = " ";
this->BirthdateOrDateOfFoundation = " ";
this->ContactTypeID = 0 ;
this->ContactClassID = 0 ;
this->ContactNumber = 0 ;
this->Address = " ";
this->PostalCode = " ";
this->City = " ";
this->CountryID = 0 ;
this->ContactStatusID = 0 ;
this->Active = 0 ;
this->EmployeeID = 0 ;
this->PhoneNum = " ";
this->PhoneNum2 = " ";
this->Fax = " ";
this->Mobile = " ";
this->Email = " ";
this->Email2 = " ";
this->webSite = " ";
this->TaxNumber = " ";
this->CreatedOn = " ";
this->EditedOn = " ";
this->setTable("Contact");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(6, QSqlRelation("ContactType", "ContactTypeID", "Description"));
this->setRelation(7, QSqlRelation("ContactClass", "ContactClassID", "Description"));
this->setRelation(12, QSqlRelation("Country", "CountryID", "Name"));
this->setRelation(13, QSqlRelation("ContactStatus", "ContactStatusID", "Description"));
this->setRelation(15, QSqlRelation("Employee", "EmployeeID", "Name"));
}
Contact::Contact(int ContactID,QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactID = ContactID ;
this->PersonalSalutation = PersonalSalutation ;
this->Salutation = Salutation ;
this->Name = Name ;
this->LastName = LastName ;
this->BirthdateOrDateOfFoundation = BirthdateOrDateOfFoundation ;
this->ContactTypeID = ContactTypeID ;
this->ContactClassID = ContactClassID ;
this->ContactNumber = ContactNumber ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->ContactStatusID = ContactStatusID ;
this->Active = Active ;
this->EmployeeID = EmployeeID ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Fax = Fax ;
this->Mobile = Mobile ;
this->Email = Email ;
this->Email2 = Email2 ;
this->webSite = webSite ;
this->TaxNumber = TaxNumber ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Contact::Contact(QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactID = 0 ;
this->PersonalSalutation = PersonalSalutation ;
this->Salutation = Salutation ;
this->Name = Name ;
this->LastName = LastName ;
this->BirthdateOrDateOfFoundation = BirthdateOrDateOfFoundation ;
this->ContactTypeID = ContactTypeID ;
this->ContactClassID = ContactClassID ;
this->ContactNumber = ContactNumber ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->ContactStatusID = ContactStatusID ;
this->Active = Active ;
this->EmployeeID = EmployeeID ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Fax = Fax ;
this->Mobile = Mobile ;
this->Email = Email ;
this->Email2 = Email2 ;
this->webSite = webSite ;
this->TaxNumber = TaxNumber ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Contact::Init()
{

QString table = "Contact";
QString query =
"(ContactID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactID),"
"PersonalSalutation VARCHAR(40) NOT NULL, "
"Salutation VARCHAR(40) NOT NULL, "
"Name VARCHAR(40) NOT NULL, "
"LastName VARCHAR(40) NOT NULL, "
"BirthdateOrDateOfFoundation VARCHAR(40) NOT NULL, "
"ContactTypeID INT NOT NULL, "
"FOREIGN KEY (ContactTypeID) REFERENCES ContactType(ContactTypeID),"
"ContactClassID INT NOT NULL, "
"FOREIGN KEY (ContactClassID) REFERENCES ContactClass(ContactClassID),"
"ContactNumber INT NOT NULL, "
"Address VARCHAR(40) NOT NULL, "
"PostalCode VARCHAR(40) NOT NULL, "
"City VARCHAR(40) NOT NULL, "
"CountryID INT NOT NULL, "
"FOREIGN KEY (CountryID) REFERENCES Country(CountryID),"
"ContactStatusID INT NOT NULL, "
"FOREIGN KEY (ContactStatusID) REFERENCES ContactStatus(ContactStatusID),"
"Active VARCHAR(1) NOT NULL, "
"EmployeeID INT NOT NULL, "
"FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID),"
"PhoneNum VARCHAR(40) NOT NULL, "
"PhoneNum2 VARCHAR(40) NOT NULL, "
"Fax VARCHAR(40) NOT NULL, "
"Mobile VARCHAR(40) NOT NULL, "
"Email VARCHAR(40) NOT NULL, "
"Email2 VARCHAR(40) NOT NULL, "
"webSite VARCHAR(40) NOT NULL, "
"TaxNumber VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Contact* Contact::p_instance = 0;
Contact* Contact::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Contact();
		Contact::GetAll();
	}
return p_instance;
}
bool Contact::save() {
if(ContactID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString(); 
	this->EditedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Contact (PersonalSalutation,Salutation,Name,LastName,BirthdateOrDateOfFoundation,ContactTypeID,ContactClassID,ContactNumber,Address,PostalCode,City,CountryID,ContactStatusID,Active,EmployeeID,PhoneNum,PhoneNum2,Fax,Mobile,Email,Email2,webSite,TaxNumber,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->PersonalSalutation)+"','"+QString(this->Salutation)+"','"+QString(this->Name)+"','"+QString(this->LastName)+"','"+QString(this->BirthdateOrDateOfFoundation)+"','"+QString::number(this->ContactTypeID)+"','"+QString::number(this->ContactClassID)+"','"+QString::number(this->ContactNumber)+"','"+QString(this->Address)+"','"+QString(this->PostalCode)+"','"+QString(this->City)+"','"+QString::number(this->CountryID)+"','"+QString::number(this->ContactStatusID)+"','"+QString::number(this->Active)+"','"+QString::number(this->EmployeeID)+"','"+QString(this->PhoneNum)+"','"+QString(this->PhoneNum2)+"','"+QString(this->Fax)+"','"+QString(this->Mobile)+"','"+QString(this->Email)+"','"+QString(this->Email2)+"','"+QString(this->webSite)+"','"+QString(this->TaxNumber)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Contact SET ""PersonalSalutation = '"+QString(this->PersonalSalutation)+"','"+"Salutation = '"+QString(this->Salutation)+"','"+"Name = '"+QString(this->Name)+"','"+"LastName = '"+QString(this->LastName)+"','"+"BirthdateOrDateOfFoundation = '"+QString(this->BirthdateOrDateOfFoundation)+"','"+"ContactTypeID = '"+QString::number(this->ContactTypeID)+"','"+"ContactClassID = '"+QString::number(this->ContactClassID)+"','"+"ContactNumber = '"+QString::number(this->ContactNumber)+"','"+"Address = '"+QString(this->Address)+"','"+"PostalCode = '"+QString(this->PostalCode)+"','"+"City = '"+QString(this->City)+"','"+"CountryID = '"+QString::number(this->CountryID)+"','"+"ContactStatusID = '"+QString::number(this->ContactStatusID)+"','"+"Active = '"+QString::number(this->Active)+"','"+"EmployeeID = '"+QString::number(this->EmployeeID)+"','"+"PhoneNum = '"+QString(this->PhoneNum)+"','"+"PhoneNum2 = '"+QString(this->PhoneNum2)+"','"+"Fax = '"+QString(this->Fax)+"','"+"Mobile = '"+QString(this->Mobile)+"','"+"Email = '"+QString(this->Email)+"','"+"Email2 = '"+QString(this->Email2)+"','"+"webSite = '"+QString(this->webSite)+"','"+"TaxNumber = '"+QString(this->TaxNumber)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactID ='"+QString::number(this->ContactID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactID FROM Contact WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Contact::remove() {
if(ContactID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Contact WHERE ContactID ="+QString::number(this->ContactID)+""));
return true;
 }
return false;
}

Contact* Contact::get() {
if(ContactID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Contact"
"WHERE ContactID ='"+QString::number(this->ContactID)+"'"));
while (query.next()) {
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString());
 }

}
return new Contact();
 }

QList<Contact*> Contact::GetAll() {
	Contact::GetInstance()->contacts.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"));
	while (query.next()) {
		Contact::GetInstance()->contacts.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString()));
	}
	return Contact::GetInstance()->contacts;
}

Contact* Contact::Get(int id) {
Contact* contact = new Contact();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Contact WHERE ContactID = '"+QString::number(id)+"'"));
while (query.next()) {
contact = new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString());
 }
contact->bankaccounts = BankAccount::QuerySelect("ContactID = " + QString::number(id));

}
return contact;
}

Contact* Contact::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Contact();
}

Contact* Contact::Get(QString name) {
Contact* contact = new Contact();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact WHERE Name = '"+name+"'"));
while (query.next()) {
contact = new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString());

 }
contact->bankaccounts = BankAccount::QuerySelect("ContactID = " +QString::number(contact->ContactID));

}
return contact;
 }

QList<Contact*> Contact::Search(QString keyword) {
QList<Contact*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"
"WHERE" 
"PersonalSalutation LIKE '%"+keyword+"%'"
"OR Salutation LIKE '%"+keyword+"%'"
"OR Name LIKE '%"+keyword+"%'"
"OR LastName LIKE '%"+keyword+"%'"
"OR BirthdateOrDateOfFoundation LIKE '%"+keyword+"%'"
"OR Address LIKE '%"+keyword+"%'"
"OR PostalCode LIKE '%"+keyword+"%'"
"OR City LIKE '%"+keyword+"%'"
"OR PhoneNum LIKE '%"+keyword+"%'"
"OR PhoneNum2 LIKE '%"+keyword+"%'"
"OR Fax LIKE '%"+keyword+"%'"
"OR Mobile LIKE '%"+keyword+"%'"
"OR Email LIKE '%"+keyword+"%'"
"OR Email2 LIKE '%"+keyword+"%'"
"OR webSite LIKE '%"+keyword+"%'"
"OR TaxNumber LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString()));
 }

}
return list;
 }

QList<QString> Contact::GetStringList() {
	QList<QString> list;
	int count =Contact::GetInstance()->contacts.count();
	if( count < 2){
		Contact::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Contact::GetInstance()->contacts[i]->Name);
	}
	return list;
}

QHash<int,QString> Contact::GetHashList() {
	QHash<int,QString> list;
	int count =Contact::GetInstance()->contacts.count();
	if( count < 2){
		Contact::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(Contact::GetInstance()->contacts[i]->ContactID,Contact::GetInstance()->contacts[i]->Name);
	}
	return list;
}

int Contact::GetIndex(QString name) {
	int count =Contact::GetInstance()->contacts.count();
	if( count < 2){
		Contact::GetAll();
	}
	for(int i = 0; i < count; i++){
		if(Contact::GetInstance()->contacts[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Contact*> Contact::QuerySelect(QString select) {
QList<Contact*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact WHERE "+select+"" ));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString()));
 }

}
return list;
 }

Qt::ItemFlags Contact::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 14 || index.column() == 15 || index.column() == 16 || index.column() == 17 || index.column() == 18 || index.column() == 19 || index.column() == 20 || index.column() == 21 || index.column() == 22 || index.column() == 23 || index.column() == 25 || index.column() == 26)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Contact::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setPersonalSalutation(id, value.toString());
else if (index.column() == 2)
ok = setSalutation(id, value.toString());
else if (index.column() == 3)
ok = setName(id, value.toString());
else if (index.column() == 4)
ok = setLastName(id, value.toString());
else if (index.column() == 5)
ok = setBirthdateOrDateOfFoundation(id, value.toString());
else if (index.column() == 6)
ok = setContactTypeID(id, value.toString());
else if (index.column() == 7)
ok = setContactClassID(id, value.toString());
else if (index.column() == 8)
ok = setContactNumber(id, value.toString());
else if (index.column() == 9)
ok = setAddress(id, value.toString());
else if (index.column() == 10)
ok = setPostalCode(id, value.toString());
else if (index.column() == 11)
ok = setCity(id, value.toString());
else if (index.column() == 12)
ok = setCountryID(id, value.toString());
else if (index.column() == 13)
ok = setContactStatusID(id, value.toString());
else if (index.column() == 14)
ok = setActive(id, value.toString());
else if (index.column() == 15)
ok = setEmployeeID(id, value.toString());
else if (index.column() == 16)
ok = setPhoneNum(id, value.toString());
else if (index.column() == 17)
ok = setPhoneNum2(id, value.toString());
else if (index.column() == 18)
ok = setFax(id, value.toString());
else if (index.column() == 19)
ok = setMobile(id, value.toString());
else if (index.column() == 20)
ok = setEmail(id, value.toString());
else if (index.column() == 21)
ok = setEmail2(id, value.toString());
else if (index.column() == 22)
ok = setwebSite(id, value.toString());
else if (index.column() == 23)
ok = setTaxNumber(id, value.toString());
else if (index.column() == 25)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 26)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Contact::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Contact::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Contact!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Personal Salutation"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Salutation"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Last Name"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Birthdate Or Date Of Foundation"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Contact Type"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Contact Class"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Contact Number"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Address"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Postal Code"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("City"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Country"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Contact Status"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Active"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Employee"));
this->setHeaderData(16, Qt::Horizontal, QObject::tr("Phone Num"));
this->setHeaderData(17, Qt::Horizontal, QObject::tr("Phone Num2"));
this->setHeaderData(18, Qt::Horizontal, QObject::tr("Fax"));
this->setHeaderData(19, Qt::Horizontal, QObject::tr("Mobile"));
this->setHeaderData(20, Qt::Horizontal, QObject::tr("Email"));
this->setHeaderData(21, Qt::Horizontal, QObject::tr("Email2"));
this->setHeaderData(22, Qt::Horizontal, QObject::tr("webSite"));
this->setHeaderData(23, Qt::Horizontal, QObject::tr("Tax Number"));
this->setHeaderData(25, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(26, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Contact::setPersonalSalutation(int ContactID, const QString &PersonalSalutation) {
QSqlQuery query;
query.prepare("update Contact set PersonalSalutation = ? where ContactID = ?");
query.addBindValue(PersonalSalutation);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setSalutation(int ContactID, const QString &Salutation) {
QSqlQuery query;
query.prepare("update Contact set Salutation = ? where ContactID = ?");
query.addBindValue(Salutation);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setName(int ContactID, const QString &Name) {
QSqlQuery query;
query.prepare("update Contact set Name = ? where ContactID = ?");
query.addBindValue(Name);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setLastName(int ContactID, const QString &LastName) {
QSqlQuery query;
query.prepare("update Contact set LastName = ? where ContactID = ?");
query.addBindValue(LastName);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setBirthdateOrDateOfFoundation(int ContactID, const QString &BirthdateOrDateOfFoundation) {
QSqlQuery query;
query.prepare("update Contact set BirthdateOrDateOfFoundation = ? where ContactID = ?");
query.addBindValue(BirthdateOrDateOfFoundation);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setContactTypeID(int ContactID, const QString &ContactTypeID) {
QSqlQuery query;
query.prepare("update Contact set ContactTypeID = ? where ContactID = ?");
query.addBindValue(ContactTypeID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setContactClassID(int ContactID, const QString &ContactClassID) {
QSqlQuery query;
query.prepare("update Contact set ContactClassID = ? where ContactID = ?");
query.addBindValue(ContactClassID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setContactNumber(int ContactID, const QString &ContactNumber) {
QSqlQuery query;
query.prepare("update Contact set ContactNumber = ? where ContactID = ?");
query.addBindValue(ContactNumber);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setAddress(int ContactID, const QString &Address) {
QSqlQuery query;
query.prepare("update Contact set Address = ? where ContactID = ?");
query.addBindValue(Address);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setPostalCode(int ContactID, const QString &PostalCode) {
QSqlQuery query;
query.prepare("update Contact set PostalCode = ? where ContactID = ?");
query.addBindValue(PostalCode);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setCity(int ContactID, const QString &City) {
QSqlQuery query;
query.prepare("update Contact set City = ? where ContactID = ?");
query.addBindValue(City);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setCountryID(int ContactID, const QString &CountryID) {
QSqlQuery query;
query.prepare("update Contact set CountryID = ? where ContactID = ?");
query.addBindValue(CountryID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setContactStatusID(int ContactID, const QString &ContactStatusID) {
QSqlQuery query;
query.prepare("update Contact set ContactStatusID = ? where ContactID = ?");
query.addBindValue(ContactStatusID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setActive(int ContactID, const QString &Active) {
QSqlQuery query;
query.prepare("update Contact set Active = ? where ContactID = ?");
query.addBindValue(Active);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setEmployeeID(int ContactID, const QString &EmployeeID) {
QSqlQuery query;
query.prepare("update Contact set EmployeeID = ? where ContactID = ?");
query.addBindValue(EmployeeID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setPhoneNum(int ContactID, const QString &PhoneNum) {
QSqlQuery query;
query.prepare("update Contact set PhoneNum = ? where ContactID = ?");
query.addBindValue(PhoneNum);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setPhoneNum2(int ContactID, const QString &PhoneNum2) {
QSqlQuery query;
query.prepare("update Contact set PhoneNum2 = ? where ContactID = ?");
query.addBindValue(PhoneNum2);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setFax(int ContactID, const QString &Fax) {
QSqlQuery query;
query.prepare("update Contact set Fax = ? where ContactID = ?");
query.addBindValue(Fax);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setMobile(int ContactID, const QString &Mobile) {
QSqlQuery query;
query.prepare("update Contact set Mobile = ? where ContactID = ?");
query.addBindValue(Mobile);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setEmail(int ContactID, const QString &Email) {
QSqlQuery query;
query.prepare("update Contact set Email = ? where ContactID = ?");
query.addBindValue(Email);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setEmail2(int ContactID, const QString &Email2) {
QSqlQuery query;
query.prepare("update Contact set Email2 = ? where ContactID = ?");
query.addBindValue(Email2);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setwebSite(int ContactID, const QString &webSite) {
QSqlQuery query;
query.prepare("update Contact set webSite = ? where ContactID = ?");
query.addBindValue(webSite);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setTaxNumber(int ContactID, const QString &TaxNumber) {
QSqlQuery query;
query.prepare("update Contact set TaxNumber = ? where ContactID = ?");
query.addBindValue(TaxNumber);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setCreatedOn(int ContactID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Contact set CreatedOn = ? where ContactID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setEditedOn(int ContactID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Contact set EditedOn = ? where ContactID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

