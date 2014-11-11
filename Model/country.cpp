/**************************************************************************
**   File: country.cpp
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "country.h"
#include "erpmodel.h"

Country::Country()
 : QSqlRelationalTableModel(){

this->CountryID = 0 ;
this->Name = " ";
this->setTable("Country");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Country::Country(int CountryID,QString Name) : QSqlRelationalTableModel(){
this->CountryID = CountryID ;
this->Name = Name ;
}

Country::Country(QString Name) : QSqlRelationalTableModel(){
this->CountryID = 0 ;
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
Country* Country::p_instance = 0;
Country* Country::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Country();
		Country::getAll();
	}
return p_instance;
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
(ErpModel::GetInstance()->qeryExec("DELETE FROM Country WHERE CountryID ="+QString::number(this->CountryID)+""));
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
	Country::GetInstance()->countrys.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country"));
	while (query.next()) {
		Country::GetInstance()->countrys.append(new Country(query.value(0).toInt(),query.value(1).toString()));
	}
	return Country::GetInstance()->countrys;
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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country WHERE Name = '"+name+"'"));
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

QList<QString> Country::GetStringList() {
	QList<QString> list;
	int count =Country::GetInstance()->countrys.count();
	if( count < 2){
		Country::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Country::GetInstance()->countrys[i]->Name);
	}
	return list;
}

QHash<int,QString> Country::GetHashList() {
	QHash<int,QString> list;
	int count =Country::GetInstance()->countrys.count();
	if( count < 2){
		Country::getAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(Country::GetInstance()->countrys[i]->CountryID,Country::GetInstance()->countrys[i]->Name);
	}
	return list;
}

int Country::GetIndex(QString name) {
	int count =Country::GetInstance()->countrys.count();
	if( count < 2){
		Country::getAll();
	}
	for(int i = 0; i < count; i++){
		if(Country::GetInstance()->countrys[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Country*> Country::querySelect(QString select) {
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

Qt::ItemFlags Country::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Country::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
refresh();
}
return ok;
}

bool Country::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->CountryID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Country::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Country!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Country::setName(int CountryID, const QString &Name) {
QSqlQuery query;
query.prepare("update Country set Name = ? where CountryID = ?");
query.addBindValue(Name);
query.addBindValue(CountryID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

