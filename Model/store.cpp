/**************************************************************************
**   File: store.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "store.h"
#include "erpmodel.h"

Store::Store()
 : QSqlRelationalTableModel(){

this->StoreID = 0 ;
this->Name = "";
this->Address = "";
this->PostalCode = "";
this->City = "";
this->CountryID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Store");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(5, QSqlRelation("Country", "CountryID", "Name"));
}
Store::Store(int StoreID,QString Name,QString Address,QString PostalCode,QString City,int CountryID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->StoreID = StoreID ;
this->Name = Name ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Store::Store(QString Name,QString Address,QString PostalCode,QString City,int CountryID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->StoreID = 0 ;
this->Name = Name ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Store::Init()
{

QString table = "Store";
QString query =
"(StoreID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (StoreID),"
"Name VARCHAR(40) NOT NULL, "
" KEY(Name),"
"Address VARCHAR(40) NOT NULL, "
"PostalCode VARCHAR(40) NOT NULL, "
"City VARCHAR(40) NOT NULL, "
"CountryID INT NOT NULL, "
"FOREIGN KEY (CountryID) REFERENCES Country(CountryID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("StoreID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Address")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("PostalCode")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("City")));variables.append(qMakePair(QString(" INT"),QString("CountryID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Store* Store::p_instance = 0;
Store* Store::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Store();
		Store::GetAll();
	}
return p_instance;
}
bool Store::save() {
this->EditedOn = QDate::currentDate().toString();
if(StoreID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Store (Name,Address,PostalCode,City,CountryID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->Address)+"','"+QString(this->PostalCode)+"','"+QString(this->City)+"','"+QString::number(this->CountryID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Store SET "	"Name = '"+QString(this->Name)+"',"+"Address = '"+QString(this->Address)+"',"+"PostalCode = '"+QString(this->PostalCode)+"',"+"City = '"+QString(this->City)+"',"+"CountryID = '"+QString::number(this->CountryID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE StoreID ='"+QString::number(this->StoreID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  StoreID FROM Store WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->StoreID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Store::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Store::remove() {
if(StoreID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Store WHERE StoreID ="+QString::number(this->StoreID)+""));
return true;
 }
return false;
}

Store* Store::get() {
if(StoreID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Store"
"WHERE StoreID ='"+QString::number(this->StoreID)+"'"));
while (query.next()) {
return new Store(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return new Store();
 }

QList<Store*> Store::GetAll() {
	QList<Store*> stores =   QList<Store*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Store ORDER BY StoreID ASC"));
	while (query.next()) {
stores.append(new Store(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
	}
	return stores;
}

Store* Store::Get(int id) {
Store* store = new Store();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Store WHERE StoreID = '"+QString::number(id)+"' ORDER BY StoreID ASC "));
while (query.next()) {
store = new Store(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return store;
}

Store* Store::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Store();
}

Store* Store::Get(QString name) {
Store* store = new Store();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Store WHERE Name = '"+name+"'"));
while (query.next()) {
store = new Store(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());

 }

}
return store;
 }

QList<Store*> Store::Search(QString keyword) {
QList<Store*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Store"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR Address LIKE '%"+keyword+"%'"
"OR PostalCode LIKE '%"+keyword+"%'"
"OR City LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Store(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

QList<QString> Store::GetStringList() {
	QList<QString> list;
	QList<Store*> stores =   QList<Store*>();
stores = GetAll();
	for(int i = 0; i <stores.count(); i++){
		list.append(stores[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > Store::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Store*> stores =   QList<Store*>();
stores = GetAll();
	for(int i = 0; i <stores.count(); i++){
		list.append(qMakePair(stores[i]->StoreID,stores[i]->Name));
	}
	return list;
}

QList<QPair< int,QString > > Store::GetPairList(QList<Store*> stores) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <stores.count(); i++){
		list.append(qMakePair(stores[i]->StoreID,stores[i]->Name));
	}
	return list;
}

int Store::GetIndex(QString name) {
	QList<Store*> stores =   QList<Store*>();
stores = GetAll();
	for(int i = 0; i <stores.count(); i++){
		if(stores[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Store*> Store::QuerySelect(QString select) {
QList<Store*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Store WHERE "+select+"" ));
while (query.next()) {
list.append(new Store(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

Qt::ItemFlags Store::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Store::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setAddress(id, value.toString());
else if (index.column() == 3)
ok = setPostalCode(id, value.toString());
else if (index.column() == 4)
ok = setCity(id, value.toString());
else if (index.column() == 5)
ok = setCountryID(id, value.toString());
else if (index.column() == 6)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 7)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Store::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->StoreID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Store::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Store!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Address"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Postal Code"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("City"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Country"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Store::setName(int StoreID, const QString &Name) {
QSqlQuery query;
query.prepare("update Store set Name = ? where StoreID = ?");
query.addBindValue(Name);
query.addBindValue(StoreID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Store::setAddress(int StoreID, const QString &Address) {
QSqlQuery query;
query.prepare("update Store set Address = ? where StoreID = ?");
query.addBindValue(Address);
query.addBindValue(StoreID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Store::setPostalCode(int StoreID, const QString &PostalCode) {
QSqlQuery query;
query.prepare("update Store set PostalCode = ? where StoreID = ?");
query.addBindValue(PostalCode);
query.addBindValue(StoreID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Store::setCity(int StoreID, const QString &City) {
QSqlQuery query;
query.prepare("update Store set City = ? where StoreID = ?");
query.addBindValue(City);
query.addBindValue(StoreID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Store::setCountryID(int StoreID, const QString &CountryID) {
QSqlQuery query;
query.prepare("update Store set CountryID = ? where StoreID = ?");
query.addBindValue(CountryID);
query.addBindValue(StoreID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Store::setCreatedOn(int StoreID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Store set CreatedOn = ? where StoreID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(StoreID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Store::setEditedOn(int StoreID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Store set EditedOn = ? where StoreID = ?");
query.addBindValue(EditedOn);
query.addBindValue(StoreID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

