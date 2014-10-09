/**************************************************************************
**   File: contact.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contact.h"
#include "erpmodel.h"

Contact::Contact()
{

this->ContactID = 0 ;
this->Name = " ";
this->PersonalSalut = " ";
this->TitlePrefix = " ";
this->CO = " ";
this->Birthdate = " ";
this->ContactTypeID = 0 ;
this->ContactStatusID = 0 ;
this->ContactClassID = 0 ;
this->ContactNumber = 0 ;
this->PhoneNum = " ";
this->PhoneNum2 = " ";
this->Fax = " ";
this->Mobile = " ";
this->Email = " ";
this->Email2 = " ";
this->webSite = " ";
this->TaxNumber = " ";
this->Address = " ";
this->PostalCode = " ";
this->City = " ";
this->CountryID = 0 ;
this->Active = 0 ;
this->EmployeeID = 0 ;
this->CreatedOn = " ";
this->EditedOn = " ";
}
Contact::Contact(int ContactID,QString Name,QString PersonalSalut,QString TitlePrefix,QString CO,QString Birthdate,int ContactTypeID,int ContactStatusID,int ContactClassID,int ContactNumber,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString Address,QString PostalCode,QString City,int CountryID,bool Active,int EmployeeID,QString CreatedOn,QString EditedOn){
this->ContactID = ContactID ;
this->Name = Name ;
this->PersonalSalut = PersonalSalut ;
this->TitlePrefix = TitlePrefix ;
this->CO = CO ;
this->Birthdate = Birthdate ;
this->ContactTypeID = ContactTypeID ;
this->ContactStatusID = ContactStatusID ;
this->ContactClassID = ContactClassID ;
this->ContactNumber = ContactNumber ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Fax = Fax ;
this->Mobile = Mobile ;
this->Email = Email ;
this->Email2 = Email2 ;
this->webSite = webSite ;
this->TaxNumber = TaxNumber ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->Active = Active ;
this->EmployeeID = EmployeeID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Contact::Contact(QString Name,QString PersonalSalut,QString TitlePrefix,QString CO,QString Birthdate,int ContactTypeID,int ContactStatusID,int ContactClassID,int ContactNumber,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString Address,QString PostalCode,QString City,int CountryID,bool Active,int EmployeeID,QString CreatedOn,QString EditedOn){
this->Name = Name ;
this->PersonalSalut = PersonalSalut ;
this->TitlePrefix = TitlePrefix ;
this->CO = CO ;
this->Birthdate = Birthdate ;
this->ContactTypeID = ContactTypeID ;
this->ContactStatusID = ContactStatusID ;
this->ContactClassID = ContactClassID ;
this->ContactNumber = ContactNumber ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Fax = Fax ;
this->Mobile = Mobile ;
this->Email = Email ;
this->Email2 = Email2 ;
this->webSite = webSite ;
this->TaxNumber = TaxNumber ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->Active = Active ;
this->EmployeeID = EmployeeID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Contact::init()
{

QString table = "Contact";
QString query =
"(ContactID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactID),"
"Name VARCHAR(40) NOT NULL, "
"PersonalSalut VARCHAR(40) NOT NULL, "
"TitlePrefix VARCHAR(40) NOT NULL, "
"CO VARCHAR(40) NOT NULL, "
"Birthdate VARCHAR(40) NOT NULL, "
"ContactTypeID INT NOT NULL, "
"FOREIGN KEY (ContactTypeID) REFERENCES ContactType(ContactTypeID),"
"ContactStatusID INT NOT NULL, "
"FOREIGN KEY (ContactStatusID) REFERENCES ContactStatus(ContactStatusID),"
"ContactClassID INT NOT NULL, "
"FOREIGN KEY (ContactClassID) REFERENCES ContactClass(ContactClassID),"
"ContactNumber INT NOT NULL, "
"PhoneNum VARCHAR(40) NOT NULL, "
"PhoneNum2 VARCHAR(40) NOT NULL, "
"Fax VARCHAR(40) NOT NULL, "
"Mobile VARCHAR(40) NOT NULL, "
"Email VARCHAR(40) NOT NULL, "
"Email2 VARCHAR(40) NOT NULL, "
"webSite VARCHAR(40) NOT NULL, "
"TaxNumber VARCHAR(40) NOT NULL, "
"Address VARCHAR(40) NOT NULL, "
"PostalCode VARCHAR(40) NOT NULL, "
"City VARCHAR(40) NOT NULL, "
"CountryID INT NOT NULL, "
"FOREIGN KEY (CountryID) REFERENCES Country(CountryID),"
"Active VARCHAR(1) NOT NULL, "
"EmployeeID INT NOT NULL, "
"FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool Contact::save() {
if(ContactID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Contact (Name,PersonalSalut,TitlePrefix,CO,Birthdate,ContactTypeID,ContactStatusID,ContactClassID,ContactNumber,PhoneNum,PhoneNum2,Fax,Mobile,Email,Email2,webSite,TaxNumber,Address,PostalCode,City,CountryID,Active,EmployeeID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->PersonalSalut)+"','"+QString(this->TitlePrefix)+"','"+QString(this->CO)+"','"+QString(this->Birthdate)+"','"+QString::number(this->ContactTypeID)+"','"+QString::number(this->ContactStatusID)+"','"+QString::number(this->ContactClassID)+"','"+QString::number(this->ContactNumber)+"','"+QString(this->PhoneNum)+"','"+QString(this->PhoneNum2)+"','"+QString(this->Fax)+"','"+QString(this->Mobile)+"','"+QString(this->Email)+"','"+QString(this->Email2)+"','"+QString(this->webSite)+"','"+QString(this->TaxNumber)+"','"+QString(this->Address)+"','"+QString(this->PostalCode)+"','"+QString(this->City)+"','"+QString::number(this->CountryID)+"','"+QString::number(this->Active)+"','"+QString::number(this->EmployeeID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Contact SET ""Name = '"+QString(this->Name)+"','"+"PersonalSalut = '"+QString(this->PersonalSalut)+"','"+"TitlePrefix = '"+QString(this->TitlePrefix)+"','"+"CO = '"+QString(this->CO)+"','"+"Birthdate = '"+QString(this->Birthdate)+"','"+"ContactTypeID = '"+QString::number(this->ContactTypeID)+"','"+"ContactStatusID = '"+QString::number(this->ContactStatusID)+"','"+"ContactClassID = '"+QString::number(this->ContactClassID)+"','"+"ContactNumber = '"+QString::number(this->ContactNumber)+"','"+"PhoneNum = '"+QString(this->PhoneNum)+"','"+"PhoneNum2 = '"+QString(this->PhoneNum2)+"','"+"Fax = '"+QString(this->Fax)+"','"+"Mobile = '"+QString(this->Mobile)+"','"+"Email = '"+QString(this->Email)+"','"+"Email2 = '"+QString(this->Email2)+"','"+"webSite = '"+QString(this->webSite)+"','"+"TaxNumber = '"+QString(this->TaxNumber)+"','"+"Address = '"+QString(this->Address)+"','"+"PostalCode = '"+QString(this->PostalCode)+"','"+"City = '"+QString(this->City)+"','"+"CountryID = '"+QString::number(this->CountryID)+"','"+"Active = '"+QString::number(this->Active)+"','"+"EmployeeID = '"+QString::number(this->EmployeeID)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactID ='"+QString::number(this->ContactID)+"'");
 }
return true;
}

bool Contact::remove() {
if(ContactID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Contact"
"WHERE ContactID ='"+QString::number(this->ContactID)+"'"));
return true;
 }
return false;
}

Contact* Contact::get() {
if(ContactID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Contact"
"WHERE ContactID ='"+QString::number(this->ContactID)+"'"));
while (query.next()) {
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toString(),query.value(25).toString());
 }

}
return new Contact();
 }

QList<Contact*> Contact::getAll() {
QList<Contact*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toString(),query.value(25).toString()));
}
return list;
 }

Contact* Contact::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Contact"
"WHERE ContactID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toString(),query.value(25).toString());
 }

}
return new Contact();
 }

Contact* Contact::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"
"WHERE Name = '"+name+"'"));
while (query.next()) {
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toString(),query.value(25).toString());
 }

}
return new Contact();
 }

QList<Contact*> Contact::search(QString keyword) {
QList<Contact*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR PersonalSalut LIKE '%"+keyword+"%'"
"OR TitlePrefix LIKE '%"+keyword+"%'"
"OR CO LIKE '%"+keyword+"%'"
"OR Birthdate LIKE '%"+keyword+"%'"
"OR PhoneNum LIKE '%"+keyword+"%'"
"OR PhoneNum2 LIKE '%"+keyword+"%'"
"OR Fax LIKE '%"+keyword+"%'"
"OR Mobile LIKE '%"+keyword+"%'"
"OR Email LIKE '%"+keyword+"%'"
"OR Email2 LIKE '%"+keyword+"%'"
"OR webSite LIKE '%"+keyword+"%'"
"OR TaxNumber LIKE '%"+keyword+"%'"
"OR Address LIKE '%"+keyword+"%'"
"OR PostalCode LIKE '%"+keyword+"%'"
"OR City LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toString(),query.value(25).toString()));
 }

}
return list;
 }

QList<Contact*> Contact::select(QString select) {
QList<Contact*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toString(),query.value(25).toString()));
 }

}
return list;
 }
