/**************************************************************************
**   File: unit.cpp
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "unit.h"
#include "erpmodel.h"

Unit::Unit()
{

this->UnitID = 0 ;
this->Description = " ";
}
Unit::Unit(int UnitID,QString Description){
this->UnitID = UnitID ;
this->Description = Description ;
}

Unit::Unit(QString Description){
this->Description = Description ;
}

bool Unit::init()
{

QString table = "Unit";
QString query =
"(UnitID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (UnitID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Unit* Unit::p_instance = 0;
Unit* Unit::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Unit();
		Unit::getAll();
	}
return p_instance;
}
bool Unit::save() {
if(UnitID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Unit (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Unit SET ""Description = '"+QString(this->Description)+"' WHERE UnitID ='"+QString::number(this->UnitID)+"'");
 }
return true;
}

bool Unit::remove() {
if(UnitID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Unit"
"WHERE UnitID ='"+QString::number(this->UnitID)+"'"));
return true;
 }
return false;
}

Unit* Unit::get() {
if(UnitID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Unit"
"WHERE UnitID ='"+QString::number(this->UnitID)+"'"));
while (query.next()) {
return new Unit(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Unit();
 }

QList<Unit*> Unit::getAll() {
	Unit::GetInstance()->units.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit"));
	while (query.next()) {
		Unit::GetInstance()->units.append(new Unit(query.value(0).toInt(),query.value(1).toString()));
	}
	return Unit::GetInstance()->units;
}

Unit* Unit::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Unit"
"WHERE UnitID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Unit(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Unit();
 }

Unit* Unit::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit"
"WHERE Description = '"+name+"'"));
while (query.next()) {
return new Unit(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Unit();
 }

QList<Unit*> Unit::search(QString keyword) {
QList<Unit*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Unit(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<QString> Unit::GetStringList() {
	QList<QString> list;
	int count =Unit::GetInstance()->units.count();
	if( count < 2){
		Unit::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Unit::GetInstance()->units[i]->Description);
	}
	return list;
}

int Unit::GetIndex(QString name) {
	int count =Unit::GetInstance()->units.count();
	if( count < 2){
		Unit::getAll();
	}
	for(int i = 0; i < count; i++){
		if(Unit::GetInstance()->units[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<Unit*> Unit::select(QString select) {
QList<Unit*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Unit(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }
