/**************************************************************************
**   File: tax.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "tax.h"
#include "erpmodel.h"

Tax::Tax()
{

this->TaxID = 0 ;
this->Ratio = 0 ;
this->Description = " ";
}
Tax::Tax(int TaxID,double Ratio,QString Description){
this->TaxID = TaxID ;
this->Ratio = Ratio ;
this->Description = Description ;
}

Tax::Tax(double Ratio,QString Description){
this->Ratio = Ratio ;
this->Description = Description ;
}

bool Tax::init()
{

QString table = "Tax";
QString query =
"(TaxID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (TaxID),"
"Ratio DECIMAL(6,2) NOT NULL, "
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool Tax::save() {
if(TaxID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Tax (Ratio,Description)"
"VALUES ('" +QString::number(this->Ratio)+"','"+QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Tax SET ""Ratio = '"+QString::number(this->Ratio)+"','"+"Description = '"+QString(this->Description)+"' WHERE TaxID ='"+QString::number(this->TaxID)+"'");
 }
return true;
}

bool Tax::remove() {
if(TaxID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Tax"
"WHERE TaxID ='"+QString::number(this->TaxID)+"'"));
return true;
 }
return false;
}

Tax* Tax::get() {
if(TaxID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Tax"
"WHERE TaxID ='"+QString::number(this->TaxID)+"'"));
while (query.next()) {
return new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString());
 }

}
return new Tax();
 }

QList<Tax*> Tax::getAll() {
QList<Tax*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"));
while (query.next()) {
list.append(new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString()));
}
return list;
 }

Tax* Tax::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Tax"
"WHERE TaxID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString());
 }

}
return new Tax();
 }

Tax* Tax::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"
"WHERE Ratio = '"+name+"'"));
while (query.next()) {
return new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString());
 }

}
return new Tax();
 }

QList<Tax*> Tax::search(QString keyword) {
QList<Tax*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString()));
 }

}
return list;
 }

QList<Tax*> Tax::select(QString select) {
QList<Tax*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString()));
 }

}
return list;
 }
