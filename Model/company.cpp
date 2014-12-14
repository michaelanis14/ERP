/**************************************************************************
**   File: company.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "company.h"
#include "erpmodel.h"

Company::Company()
 : QSqlRelationalTableModel(){

this->CompanyID = 0 ;
this->Name = "";
this->Header = "";
this->Footer = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Company");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Company::Company(int CompanyID,QString Name,QString Header,QString Footer,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->CompanyID = CompanyID ;
this->Name = Name ;
this->Header = Header ;
this->Footer = Footer ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Company::Company(QString Name,QString Header,QString Footer,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->CompanyID = 0 ;
this->Name = Name ;
this->Header = Header ;
this->Footer = Footer ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Company::Init()
{

QString table = "Company";
QString query =
"(CompanyID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (CompanyID),"
"Name VARCHAR(40) NOT NULL, "
" KEY(Name),"
"Header VARCHAR(40) NOT NULL, "
"Footer VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("CompanyID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Header")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Footer")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Company* Company::p_instance = 0;
Company* Company::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Company();
		Company::GetAll();
	}
return p_instance;
}
bool Company::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(CompanyID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Company (Name,Header,Footer,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->Header)+"','"+QString(this->Footer)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Company SET "	"Name = '"+QString(this->Name)+"',"+"Header = '"+QString(this->Header)+"',"+"Footer = '"+QString(this->Footer)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE CompanyID ='"+QString::number(this->CompanyID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  CompanyID FROM Company WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->CompanyID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Company::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Company::remove() {
if(CompanyID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Company WHERE CompanyID ="+QString::number(this->CompanyID)+""));
return true;
 }
return false;
}

Company* Company::get() {
if(CompanyID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Company"
"WHERE CompanyID ='"+QString::number(this->CompanyID)+"'"));
while (query.next()) {
return new Company(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
 }

}
return new Company();
 }

QList<Company*> Company::GetAll() {
	QList<Company*> companys =   QList<Company*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Company ORDER BY CompanyID ASC"));
	while (query.next()) {
companys.append(new Company(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
	}
	return companys;
}

Company* Company::Get(int id) {
Company* company = new Company();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Company WHERE CompanyID = '"+QString::number(id)+"' ORDER BY CompanyID ASC "));
while (query.next()) {
company = new Company(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
 }

}
return company;
}

Company* Company::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Company();
}

Company* Company::Get(QString name) {
Company* company = new Company();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Company WHERE Name = '"+name+"'"));
while (query.next()) {
company = new Company(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());

 }

}
return company;
 }

QList<Company*> Company::Search(QString keyword) {
QList<Company*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Company"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR Header LIKE '%"+keyword+"%'"
"OR Footer LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Company(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> Company::GetStringList() {
	QList<QString> list;
	QList<Company*> companys =   QList<Company*>();
companys = GetAll();
	for(int i = 0; i <companys.count(); i++){
		list.append(companys[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > Company::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Company*> companys =   QList<Company*>();
companys = GetAll();
	for(int i = 0; i <companys.count(); i++){
		list.append(qMakePair(companys[i]->CompanyID,companys[i]->Name));
	}
	return list;
}

QList<QPair< int,QString > > Company::GetPairList(QList<Company*> companys) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <companys.count(); i++){
		list.append(qMakePair(companys[i]->CompanyID,companys[i]->Name));
	}
	return list;
}

int Company::GetIndex(QString name) {
	QList<Company*> companys =   QList<Company*>();
companys = GetAll();
	for(int i = 0; i <companys.count(); i++){
		if(companys[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Company*> Company::QuerySelect(QString select) {
QList<Company*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Company WHERE "+select+"" ));
while (query.next()) {
list.append(new Company(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags Company::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Company::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setHeader(id, value.toString());
else if (index.column() == 3)
ok = setFooter(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Company::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->CompanyID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Company::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Company!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Header"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Footer"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Company::setName(int CompanyID, const QString &Name) {
QSqlQuery query;
query.prepare("update Company set Name = ? where CompanyID = ?");
query.addBindValue(Name);
query.addBindValue(CompanyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Company::setHeader(int CompanyID, const QString &Header) {
QSqlQuery query;
query.prepare("update Company set Header = ? where CompanyID = ?");
query.addBindValue(Header);
query.addBindValue(CompanyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Company::setFooter(int CompanyID, const QString &Footer) {
QSqlQuery query;
query.prepare("update Company set Footer = ? where CompanyID = ?");
query.addBindValue(Footer);
query.addBindValue(CompanyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Company::setCreatedOn(int CompanyID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Company set CreatedOn = ? where CompanyID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(CompanyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Company::setEditedOn(int CompanyID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Company set EditedOn = ? where CompanyID = ?");
query.addBindValue(EditedOn);
query.addBindValue(CompanyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

