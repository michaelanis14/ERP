/**************************************************************************
**   File: contactstatus.cpp
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactstatus.h"
#include "erpmodel.h"

ContactStatus::ContactStatus()
{

this->ContactStatusID = 0 ;
this->Description = " ";
}
ContactStatus::ContactStatus(int ContactStatusID,QString Description){
this->ContactStatusID = ContactStatusID ;
this->Description = Description ;
}

ContactStatus::ContactStatus(QString Description){
this->Description = Description ;
}

bool ContactStatus::init()
{

QString table = "ContactStatus";
QString query =
"(ContactStatusID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactStatusID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactStatus* ContactStatus::p_instance = 0;
ContactStatus* ContactStatus::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactStatus();
		ContactStatus::getAll();
	}
return p_instance;
}
bool ContactStatus::save() {
if(ContactStatusID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactStatus (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactStatus SET ""Description = '"+QString(this->Description)+"' WHERE ContactStatusID ='"+QString::number(this->ContactStatusID)+"'");
 }
return true;
}

bool ContactStatus::remove() {
if(ContactStatusID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactStatus"
"WHERE ContactStatusID ='"+QString::number(this->ContactStatusID)+"'"));
return true;
 }
return false;
}

ContactStatus* ContactStatus::get() {
if(ContactStatusID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactStatus"
"WHERE ContactStatusID ='"+QString::number(this->ContactStatusID)+"'"));
while (query.next()) {
return new ContactStatus(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactStatus();
 }

QList<ContactStatus*> ContactStatus::getAll() {
	ContactStatus::GetInstance()->contactstatuss.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"));
	while (query.next()) {
		ContactStatus::GetInstance()->contactstatuss.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString()));
	}
	return ContactStatus::GetInstance()->contactstatuss;
}

ContactStatus* ContactStatus::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactStatus"
"WHERE ContactStatusID = '"+QString::number(id)+"'"));
while (query.next()) {
return new ContactStatus(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactStatus();
 }

ContactStatus* ContactStatus::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"
"WHERE Description = '"+name+"'"));
while (query.next()) {
return new ContactStatus(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactStatus();
 }

QList<ContactStatus*> ContactStatus::search(QString keyword) {
QList<ContactStatus*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<QString> ContactStatus::GetStringList() {
	QList<QString> list;
	int count =ContactStatus::GetInstance()->contactstatuss.count();
	if( count < 2){
		ContactStatus::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(ContactStatus::GetInstance()->contactstatuss[i]->Description);
	}
	return list;
}

int ContactStatus::GetIndex(QString name) {
	int count =ContactStatus::GetInstance()->contactstatuss.count();
	if( count < 2){
		ContactStatus::getAll();
	}
	for(int i = 0; i < count; i++){
		if(ContactStatus::GetInstance()->contactstatuss[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactStatus*> ContactStatus::select(QString select) {
QList<ContactStatus*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }
