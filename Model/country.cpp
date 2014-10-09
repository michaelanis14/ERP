/**************************************************************************
**   File: country.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "country.h"
#include "erpmodel.h"

Country::Country()
{

this->CountryID = 0 ;
this->Name = " ";
}
Country::Country(int CountryID,QString Name){
this->CountryID = CountryID ;
this->Name = Name ;
}

Country::Country(QString Name){
this->Name = Name ;
}

bool Country::init()
{

QString table = "Country";
QString query =
"(CountryID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (CountryID),"
"Name VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool Country::save() {
if(CountryID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Country (Name)"
"VALUES ('" +QString(this->Name)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Country SET ""Name = '"+QString(this->Name)+"' WHERE CountryID ='"+QString::number(this->CountryID)+"'");
 }
return true;
}

bool Country::remove() {
if(CountryID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Country"
"WHERE CountryID ='"+QString::number(this->CountryID)+"'"));
return true;
 }
return false;
}

Country* Country::get() {
if(CountryID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Country"
"WHERE CountryID ='"+QString::number(this->CountryID)+"'"));
while (query.next()) {
return new Country(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Country();
 }

QList<Country*> Country::getAll() {
QList<Country*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country"));
while (query.next()) {
list.append(new Country(query.value(0).toInt(),query.value(1).toString()));
}
return list;
 }

Country* Country::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Country"
"WHERE CountryID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Country(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Country();
 }

Country* Country::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country"
"WHERE Name = '"+name+"'"));
while (query.next()) {
return new Country(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Country();
 }

QList<Country*> Country::search(QString keyword) {
QList<Country*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Country(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<Country*> Country::select(QString select) {
QList<Country*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Country(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }
