/**************************************************************************
**   File: contact.cpp
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contact.h"
#include "erpmodel.h"

Contact::Contact()
{

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
}
Contact::Contact(int ContactID,QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn){
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

Contact::Contact(QString PersonalSalutation,QString Salutation,QString Name,QString LastName,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int ContactNumber,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,bool Active,int EmployeeID,QString PhoneNum,QString PhoneNum2,QString Fax,QString Mobile,QString Email,QString Email2,QString webSite,QString TaxNumber,QString CreatedOn,QString EditedOn){
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

bool Contact::init()
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
		Contact::getAll();
	}
return p_instance;
}
bool Contact::save() {
if(ContactID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Contact (PersonalSalutation,Salutation,Name,LastName,BirthdateOrDateOfFoundation,ContactTypeID,ContactClassID,ContactNumber,Address,PostalCode,City,CountryID,ContactStatusID,Active,EmployeeID,PhoneNum,PhoneNum2,Fax,Mobile,Email,Email2,webSite,TaxNumber,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->PersonalSalutation)+"','"+QString(this->Salutation)+"','"+QString(this->Name)+"','"+QString(this->LastName)+"','"+QString(this->BirthdateOrDateOfFoundation)+"','"+QString::number(this->ContactTypeID)+"','"+QString::number(this->ContactClassID)+"','"+QString::number(this->ContactNumber)+"','"+QString(this->Address)+"','"+QString(this->PostalCode)+"','"+QString(this->City)+"','"+QString::number(this->CountryID)+"','"+QString::number(this->ContactStatusID)+"','"+QString::number(this->Active)+"','"+QString::number(this->EmployeeID)+"','"+QString(this->PhoneNum)+"','"+QString(this->PhoneNum2)+"','"+QString(this->Fax)+"','"+QString(this->Mobile)+"','"+QString(this->Email)+"','"+QString(this->Email2)+"','"+QString(this->webSite)+"','"+QString(this->TaxNumber)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Contact SET ""PersonalSalutation = '"+QString(this->PersonalSalutation)+"','"+"Salutation = '"+QString(this->Salutation)+"','"+"Name = '"+QString(this->Name)+"','"+"LastName = '"+QString(this->LastName)+"','"+"BirthdateOrDateOfFoundation = '"+QString(this->BirthdateOrDateOfFoundation)+"','"+"ContactTypeID = '"+QString::number(this->ContactTypeID)+"','"+"ContactClassID = '"+QString::number(this->ContactClassID)+"','"+"ContactNumber = '"+QString::number(this->ContactNumber)+"','"+"Address = '"+QString(this->Address)+"','"+"PostalCode = '"+QString(this->PostalCode)+"','"+"City = '"+QString(this->City)+"','"+"CountryID = '"+QString::number(this->CountryID)+"','"+"ContactStatusID = '"+QString::number(this->ContactStatusID)+"','"+"Active = '"+QString::number(this->Active)+"','"+"EmployeeID = '"+QString::number(this->EmployeeID)+"','"+"PhoneNum = '"+QString(this->PhoneNum)+"','"+"PhoneNum2 = '"+QString(this->PhoneNum2)+"','"+"Fax = '"+QString(this->Fax)+"','"+"Mobile = '"+QString(this->Mobile)+"','"+"Email = '"+QString(this->Email)+"','"+"Email2 = '"+QString(this->Email2)+"','"+"webSite = '"+QString(this->webSite)+"','"+"TaxNumber = '"+QString(this->TaxNumber)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactID ='"+QString::number(this->ContactID)+"'");
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
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString());
 }

}
return new Contact();
 }

QList<Contact*> Contact::getAll() {
	Contact::GetInstance()->contacts.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"));
	while (query.next()) {
		Contact::GetInstance()->contacts.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString()));
	}
	return Contact::GetInstance()->contacts;
}

Contact* Contact::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Contact"
"WHERE ContactID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString());
 }

}
return new Contact();
 }

Contact* Contact::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"
"WHERE Name = '"+name+"'"));
while (query.next()) {
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString());
 }

}
return new Contact();
 }

QList<Contact*> Contact::search(QString keyword) {
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
		Contact::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Contact::GetInstance()->contacts[i]->Name);
	}
	return list;
}

int Contact::GetIndex(QString name) {
	int count =Contact::GetInstance()->contacts.count();
	if( count < 2){
		Contact::getAll();
	}
	for(int i = 0; i < count; i++){
		if(Contact::GetInstance()->contacts[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Contact*> Contact::select(QString select) {
QList<Contact*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString(),query.value(20).toString(),query.value(21).toString(),query.value(22).toString(),query.value(23).toString(),query.value(24).toString(),query.value(25).toString()));
 }

}
return list;
 }
