/**************************************************************************
**   File: contactclass.cpp
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactclass.h"
#include "erpmodel.h"

ContactClass::ContactClass()
{

this->ContactClassID = 0 ;
this->Description = " ";
}
ContactClass::ContactClass(int ContactClassID,QString Description){
this->ContactClassID = ContactClassID ;
this->Description = Description ;
}

ContactClass::ContactClass(QString Description){
this->Description = Description ;
}

bool ContactClass::init()
{

QString table = "ContactClass";
QString query =
"(ContactClassID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactClassID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactClass* ContactClass::p_instance = 0;
ContactClass* ContactClass::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactClass();
		ContactClass::getAll();
	}
return p_instance;
}
bool ContactClass::save() {
if(ContactClassID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactClass (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactClass SET ""Description = '"+QString(this->Description)+"' WHERE ContactClassID ='"+QString::number(this->ContactClassID)+"'");
 }
return true;
}

bool ContactClass::remove() {
if(ContactClassID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactClass"
"WHERE ContactClassID ='"+QString::number(this->ContactClassID)+"'"));
return true;
 }
return false;
}

ContactClass* ContactClass::get() {
if(ContactClassID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactClass"
"WHERE ContactClassID ='"+QString::number(this->ContactClassID)+"'"));
while (query.next()) {
return new ContactClass(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactClass();
 }

QList<ContactClass*> ContactClass::getAll() {
	ContactClass::GetInstance()->contactclasss.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactClass"));
	while (query.next()) {
		ContactClass::GetInstance()->contactclasss.append(new ContactClass(query.value(0).toInt(),query.value(1).toString()));
	}
	return ContactClass::GetInstance()->contactclasss;
}

ContactClass* ContactClass::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactClass"
"WHERE ContactClassID = '"+QString::number(id)+"'"));
while (query.next()) {
return new ContactClass(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactClass();
 }

ContactClass* ContactClass::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactClass"
"WHERE Description = '"+name+"'"));
while (query.next()) {
return new ContactClass(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactClass();
 }

QList<ContactClass*> ContactClass::search(QString keyword) {
QList<ContactClass*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactClass"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactClass(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<QString> ContactClass::GetStringList() {
	QList<QString> list;
	int count =ContactClass::GetInstance()->contactclasss.count();
	if( count < 2){
		ContactClass::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(ContactClass::GetInstance()->contactclasss[i]->Description);
	}
	return list;
}

int ContactClass::GetIndex(QString name) {
	int count =ContactClass::GetInstance()->contactclasss.count();
	if( count < 2){
		ContactClass::getAll();
	}
	for(int i = 0; i < count; i++){
		if(ContactClass::GetInstance()->contactclasss[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactClass*> ContactClass::select(QString select) {
QList<ContactClass*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactClass"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new ContactClass(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }
