/**************************************************************************
**   File: country.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "country.h"
#include "erpmodel.h"

Country::Country()
 : QSqlRelationalTableModel(){

this->CountryID = 0 ;
this->Name = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Country");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Country::Country(int CountryID,QString Name,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->CountryID = CountryID ;
this->Name = Name ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Country::Country(QString Name,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->CountryID = 0 ;
this->Name = Name ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Country::Init()
{

QString table = "Country";
QString query =
"(CountryID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (CountryID),"
"Name VARCHAR(40) NOT NULL, "
" KEY(Name),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("CountryID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Country* Country::p_instance = 0;
Country* Country::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Country();
		Country::GetAll();
	}
return p_instance;
}
bool Country::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(CountryID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Country (Name,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Country SET "	"Name = '"+QString(this->Name)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE CountryID ='"+QString::number(this->CountryID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  CountryID FROM Country WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->CountryID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Country::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
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
return new Country(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new Country();
 }

QList<Country*> Country::GetAll() {
	QList<Country*> countrys =   QList<Country*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country ORDER BY CountryID ASC"));
	while (query.next()) {
countrys.append(new Country(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return countrys;
}

Country* Country::Get(int id) {
Country* country = new Country();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Country WHERE CountryID = '"+QString::number(id)+"' ORDER BY CountryID ASC "));
while (query.next()) {
country = new Country(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return country;
}

Country* Country::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Country();
}

Country* Country::Get(QString name) {
Country* country = new Country();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country WHERE Name = '"+name+"'"));
while (query.next()) {
country = new Country(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return country;
 }

QList<Country*> Country::Search(QString keyword) {
QList<Country*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Country(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> Country::GetStringList() {
	QList<QString> list;
	QList<Country*> countrys =   QList<Country*>();
countrys = GetAll();
	for(int i = 0; i <countrys.count(); i++){
		list.append(countrys[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > Country::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Country*> countrys =   QList<Country*>();
countrys = GetAll();
	for(int i = 0; i <countrys.count(); i++){
		list.append(qMakePair(countrys[i]->CountryID,countrys[i]->Name));
	}
	return list;
}

QList<QPair< int,QString > > Country::GetPairList(QList<Country*> countrys) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <countrys.count(); i++){
		list.append(qMakePair(countrys[i]->CountryID,countrys[i]->Name));
	}
	return list;
}

int Country::GetIndex(QString name) {
	QList<Country*> countrys =   QList<Country*>();
countrys = GetAll();
	for(int i = 0; i <countrys.count(); i++){
		if(countrys[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Country*> Country::QuerySelect(QString select) {
QList<Country*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Country WHERE "+select+"" ));
while (query.next()) {
list.append(new Country(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags Country::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
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
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
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
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
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
bool Country::setCreatedOn(int CountryID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Country set CreatedOn = ? where CountryID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(CountryID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Country::setEditedOn(int CountryID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Country set EditedOn = ? where CountryID = ?");
query.addBindValue(EditedOn);
query.addBindValue(CountryID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

