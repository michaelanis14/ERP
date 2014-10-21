/**************************************************************************
**   File: currency.cpp
**   Created on: Sat Oct 18 13:10:05 EET 2014
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
Currency* Currency::p_instance = 0;
Currency* Currency::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Currency();
		Currency::getAll();
	}
return p_instance;
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
	Currency::GetInstance()->currencys.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"));
	while (query.next()) {
		Currency::GetInstance()->currencys.append(new Currency(query.value(0).toInt(),query.value(1).toString()));
	}
	return Currency::GetInstance()->currencys;
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

QList<QString> Currency::GetStringList() {
	QList<QString> list;
	int count =Currency::GetInstance()->currencys.count();
	if( count < 2){
		Currency::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Currency::GetInstance()->currencys[i]->Description);
	}
	return list;
}

int Currency::GetIndex(QString name) {
	int count =Currency::GetInstance()->currencys.count();
	if( count < 2){
		Currency::getAll();
	}
	for(int i = 0; i < count; i++){
		if(Currency::GetInstance()->currencys[i]->Description == name){
			return i;
		}
	}
	return 0;
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
