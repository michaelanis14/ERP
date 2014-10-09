/**************************************************************************
**   File: contactperson.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactperson.h"
#include "erpmodel.h"

ContactPerson::ContactPerson()
{

this->ContactPersonID = 0 ;
this->PersonalSalut = " ";
this->TitlePrefix = " ";
this->FirstName = " ";
this->LastName = " ";
this->Position = " ";
this->Birthdate = " ";
this->ContactPersoneNumber = 0 ;
this->Email = " ";
this->PhoneNum = " ";
this->PhoneNum2 = " ";
this->Mobile = " ";
this->Fax = " ";
this->active = 0 ;
this->CreatedBy_UserID = 0 ;
this->EditedBy_UserID = 0 ;
this->ContactID = 0 ;
this->CreatedOn = " ";
this->EditedOn = " ";
}
ContactPerson::ContactPerson(int ContactPersonID,QString PersonalSalut,QString TitlePrefix,QString FirstName,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int CreatedBy_UserID,int EditedBy_UserID,int ContactID,QString CreatedOn,QString EditedOn){
this->ContactPersonID = ContactPersonID ;
this->PersonalSalut = PersonalSalut ;
this->TitlePrefix = TitlePrefix ;
this->FirstName = FirstName ;
this->LastName = LastName ;
this->Position = Position ;
this->Birthdate = Birthdate ;
this->ContactPersoneNumber = ContactPersoneNumber ;
this->Email = Email ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Mobile = Mobile ;
this->Fax = Fax ;
this->active = active ;
this->CreatedBy_UserID = CreatedBy_UserID ;
this->EditedBy_UserID = EditedBy_UserID ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPerson::ContactPerson(QString PersonalSalut,QString TitlePrefix,QString FirstName,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int CreatedBy_UserID,int EditedBy_UserID,int ContactID,QString CreatedOn,QString EditedOn){
this->PersonalSalut = PersonalSalut ;
this->TitlePrefix = TitlePrefix ;
this->FirstName = FirstName ;
this->LastName = LastName ;
this->Position = Position ;
this->Birthdate = Birthdate ;
this->ContactPersoneNumber = ContactPersoneNumber ;
this->Email = Email ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Mobile = Mobile ;
this->Fax = Fax ;
this->active = active ;
this->CreatedBy_UserID = CreatedBy_UserID ;
this->EditedBy_UserID = EditedBy_UserID ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactPerson::init()
{

QString table = "ContactPerson";
QString query =
"(ContactPersonID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactPersonID),"
"PersonalSalut VARCHAR(40) NOT NULL, "
"TitlePrefix VARCHAR(40) NOT NULL, "
"FirstName VARCHAR(40) NOT NULL, "
"LastName VARCHAR(40) NOT NULL, "
"Position VARCHAR(40) NOT NULL, "
"Birthdate VARCHAR(40) NOT NULL, "
"ContactPersoneNumber INT NOT NULL, "
"Email VARCHAR(40) NOT NULL, "
"PhoneNum VARCHAR(40) NOT NULL, "
"PhoneNum2 VARCHAR(40) NOT NULL, "
"Mobile VARCHAR(40) NOT NULL, "
"Fax VARCHAR(40) NOT NULL, "
"active VARCHAR(1) NOT NULL, "
"CreatedBy_UserID INT NOT NULL, "
"FOREIGN KEY (CreatedBy_UserID) REFERENCES CreatedBy_User(CreatedBy_UserID),"
"EditedBy_UserID INT NOT NULL, "
"FOREIGN KEY (EditedBy_UserID) REFERENCES EditedBy_User(EditedBy_UserID),"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool ContactPerson::save() {
if(ContactPersonID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPerson (PersonalSalut,TitlePrefix,FirstName,LastName,Position,Birthdate,ContactPersoneNumber,Email,PhoneNum,PhoneNum2,Mobile,Fax,active,CreatedBy_UserID,EditedBy_UserID,ContactID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->PersonalSalut)+"','"+QString(this->TitlePrefix)+"','"+QString(this->FirstName)+"','"+QString(this->LastName)+"','"+QString(this->Position)+"','"+QString(this->Birthdate)+"','"+QString::number(this->ContactPersoneNumber)+"','"+QString(this->Email)+"','"+QString(this->PhoneNum)+"','"+QString(this->PhoneNum2)+"','"+QString(this->Mobile)+"','"+QString(this->Fax)+"','"+QString::number(this->active)+"','"+QString::number(this->CreatedBy_UserID)+"','"+QString::number(this->EditedBy_UserID)+"','"+QString::number(this->ContactID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPerson SET ""PersonalSalut = '"+QString(this->PersonalSalut)+"','"+"TitlePrefix = '"+QString(this->TitlePrefix)+"','"+"FirstName = '"+QString(this->FirstName)+"','"+"LastName = '"+QString(this->LastName)+"','"+"Position = '"+QString(this->Position)+"','"+"Birthdate = '"+QString(this->Birthdate)+"','"+"ContactPersoneNumber = '"+QString::number(this->ContactPersoneNumber)+"','"+"Email = '"+QString(this->Email)+"','"+"PhoneNum = '"+QString(this->PhoneNum)+"','"+"PhoneNum2 = '"+QString(this->PhoneNum2)+"','"+"Mobile = '"+QString(this->Mobile)+"','"+"Fax = '"+QString(this->Fax)+"','"+"active = '"+QString::number(this->active)+"','"+"CreatedBy_UserID = '"+QString::number(this->CreatedBy_UserID)+"','"+"EditedBy_UserID = '"+QString::number(this->EditedBy_UserID)+"','"+"ContactID = '"+QString::number(this->ContactID)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonID ='"+QString::number(this->ContactPersonID)+"'");
 }
return true;
}

bool ContactPerson::remove() {
if(ContactPersonID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactPerson"
"WHERE ContactPersonID ='"+QString::number(this->ContactPersonID)+"'"));
return true;
 }
return false;
}

ContactPerson* ContactPerson::get() {
if(ContactPersonID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPerson"
"WHERE ContactPersonID ='"+QString::number(this->ContactPersonID)+"'"));
while (query.next()) {
return new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString());
 }

}
return new ContactPerson();
 }

QList<ContactPerson*> ContactPerson::getAll() {
QList<ContactPerson*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"));
while (query.next()) {
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString()));
}
return list;
 }

ContactPerson* ContactPerson::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPerson"
"WHERE ContactPersonID = '"+QString::number(id)+"'"));
while (query.next()) {
return new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString());
 }

}
return new ContactPerson();
 }

ContactPerson* ContactPerson::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"
"WHERE PersonalSalut = '"+name+"'"));
while (query.next()) {
return new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString());
 }

}
return new ContactPerson();
 }

QList<ContactPerson*> ContactPerson::search(QString keyword) {
QList<ContactPerson*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"
"WHERE" 
"PersonalSalut LIKE '%"+keyword+"%'"
"OR TitlePrefix LIKE '%"+keyword+"%'"
"OR FirstName LIKE '%"+keyword+"%'"
"OR LastName LIKE '%"+keyword+"%'"
"OR Position LIKE '%"+keyword+"%'"
"OR Birthdate LIKE '%"+keyword+"%'"
"OR Email LIKE '%"+keyword+"%'"
"OR PhoneNum LIKE '%"+keyword+"%'"
"OR PhoneNum2 LIKE '%"+keyword+"%'"
"OR Mobile LIKE '%"+keyword+"%'"
"OR Fax LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString()));
 }

}
return list;
 }

QList<ContactPerson*> ContactPerson::select(QString select) {
QList<ContactPerson*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString()));
 }

}
return list;
 }
