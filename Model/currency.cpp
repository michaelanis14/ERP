/**************************************************************************
**   File: currency.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "currency.h"
#include "erpmodel.h"

Currency::Currency()
{

this->CurrencyID = 0 ;
this->Description = " ";
}
Currency::Currency(int CurrencyID,QString Description){
this->CurrencyID = CurrencyID ;
this->Description = Description ;
}

Currency::Currency(QString Description){
this->Description = Description ;
}

bool Currency::init()
{

QString table = "Currency";
QString query =
"(CurrencyID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (CurrencyID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool Currency::save() {
if(CurrencyID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Currency (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Currency SET ""Description = '"+QString(this->Description)+"' WHERE CurrencyID ='"+QString::number(this->CurrencyID)+"'");
 }
return true;
}

bool Currency::remove() {
if(CurrencyID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Currency"
"WHERE CurrencyID ='"+QString::number(this->CurrencyID)+"'"));
return true;
 }
return false;
}

Currency* Currency::get() {
if(CurrencyID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Currency"
"WHERE CurrencyID ='"+QString::number(this->CurrencyID)+"'"));
while (query.next()) {
return new Currency(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Currency();
 }

QList<Currency*> Currency::getAll() {
QList<Currency*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"));
while (query.next()) {
list.append(new Currency(query.value(0).toInt(),query.value(1).toString()));
}
return list;
 }

Currency* Currency::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Currency"
"WHERE CurrencyID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Currency(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Currency();
 }

Currency* Currency::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"
"WHERE Description = '"+name+"'"));
while (query.next()) {
return new Currency(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Currency();
 }

QList<Currency*> Currency::search(QString keyword) {
QList<Currency*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Currency(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<Currency*> Currency::select(QString select) {
QList<Currency*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Currency(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }
