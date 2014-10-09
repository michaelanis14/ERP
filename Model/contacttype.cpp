/**************************************************************************
**   File: contacttype.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contacttype.h"
#include "erpmodel.h"

ContactType::ContactType()
{

this->ContactTypeID = 0 ;
this->Description = " ";
}
ContactType::ContactType(int ContactTypeID,QString Description){
this->ContactTypeID = ContactTypeID ;
this->Description = Description ;
}

ContactType::ContactType(QString Description){
this->Description = Description ;
}

bool ContactType::init()
{

QString table = "ContactType";
QString query =
"(ContactTypeID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactTypeID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool ContactType::save() {
if(ContactTypeID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactType (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactType SET ""Description = '"+QString(this->Description)+"' WHERE ContactTypeID ='"+QString::number(this->ContactTypeID)+"'");
 }
return true;
}

bool ContactType::remove() {
if(ContactTypeID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactType"
"WHERE ContactTypeID ='"+QString::number(this->ContactTypeID)+"'"));
return true;
 }
return false;
}

ContactType* ContactType::get() {
if(ContactTypeID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactType"
"WHERE ContactTypeID ='"+QString::number(this->ContactTypeID)+"'"));
while (query.next()) {
return new ContactType(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactType();
 }

QList<ContactType*> ContactType::getAll() {
QList<ContactType*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"));
while (query.next()) {
list.append(new ContactType(query.value(0).toInt(),query.value(1).toString()));
}
return list;
 }

ContactType* ContactType::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactType"
"WHERE ContactTypeID = '"+QString::number(id)+"'"));
while (query.next()) {
return new ContactType(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactType();
 }

ContactType* ContactType::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"
"WHERE Description = '"+name+"'"));
while (query.next()) {
return new ContactType(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactType();
 }

QList<ContactType*> ContactType::search(QString keyword) {
QList<ContactType*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactType(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<ContactType*> ContactType::select(QString select) {
QList<ContactType*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new ContactType(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }
