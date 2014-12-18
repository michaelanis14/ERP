/**************************************************************************
**   File: invoiceserial.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoiceserial.h"
#include "erpmodel.h"

InvoiceSerial::InvoiceSerial()
 : QSqlRelationalTableModel(){

this->InvoiceSerialID = 0 ;
this->Title = "";
this->Serial = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceSerial");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
InvoiceSerial::InvoiceSerial(int InvoiceSerialID,QString Title,int Serial,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceSerialID = InvoiceSerialID ;
this->Title = Title ;
this->Serial = Serial ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceSerial::InvoiceSerial(QString Title,int Serial,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceSerialID = 0 ;
this->Title = Title ;
this->Serial = Serial ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceSerial::Init()
{

QString table = "InvoiceSerial";
QString query =
"(InvoiceSerialID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceSerialID),"
"Title VARCHAR(40) NOT NULL, "
" KEY(Title),"
"Serial INT NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceSerialID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Title")));variables.append(qMakePair(QString(" INT"),QString("Serial")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
InvoiceSerial* InvoiceSerial::p_instance = 0;
InvoiceSerial* InvoiceSerial::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceSerial();
		InvoiceSerial::GetAll();
	}
return p_instance;
}
bool InvoiceSerial::save() {
this->EditedOn = QDate::currentDate().toString();
if(InvoiceSerialID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceSerial (Title,Serial,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->Serial)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceSerial SET "	"Title = '"+QString(this->Title)+"',"+"Serial = '"+QString::number(this->Serial)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceSerialID ='"+QString::number(this->InvoiceSerialID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceSerialID FROM InvoiceSerial WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceSerialID = query.value(0).toInt();	
 } 
 }
return true;
}
bool InvoiceSerial::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool InvoiceSerial::remove() {
if(InvoiceSerialID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceSerial WHERE InvoiceSerialID ="+QString::number(this->InvoiceSerialID)+""));
return true;
 }
return false;
}

InvoiceSerial* InvoiceSerial::get() {
if(InvoiceSerialID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceSerial"
"WHERE InvoiceSerialID ='"+QString::number(this->InvoiceSerialID)+"'"));
while (query.next()) {
return new InvoiceSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new InvoiceSerial();
 }

QList<InvoiceSerial*> InvoiceSerial::GetAll() {
	QList<InvoiceSerial*> invoiceserials =   QList<InvoiceSerial*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceSerial ORDER BY InvoiceSerialID ASC"));
	while (query.next()) {
invoiceserials.append(new InvoiceSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return invoiceserials;
}

InvoiceSerial* InvoiceSerial::Get(int id) {
InvoiceSerial* invoiceserial = new InvoiceSerial();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceSerial WHERE InvoiceSerialID = '"+QString::number(id)+"' ORDER BY InvoiceSerialID ASC "));
while (query.next()) {
invoiceserial = new InvoiceSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return invoiceserial;
}

InvoiceSerial* InvoiceSerial::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceSerial();
}

InvoiceSerial* InvoiceSerial::Get(QString name) {
InvoiceSerial* invoiceserial = new InvoiceSerial();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceSerial WHERE Title = '"+name+"'"));
while (query.next()) {
invoiceserial = new InvoiceSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return invoiceserial;
 }

QList<InvoiceSerial*> InvoiceSerial::Search(QString keyword) {
QList<InvoiceSerial*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceSerial"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> InvoiceSerial::GetStringList() {
	QList<QString> list;
	QList<InvoiceSerial*> invoiceserials =   QList<InvoiceSerial*>();
invoiceserials = GetAll();
	for(int i = 0; i <invoiceserials.count(); i++){
		list.append(invoiceserials[i]->Title);
	}
	return list;
}

QList<QPair< int,QString > > InvoiceSerial::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<InvoiceSerial*> invoiceserials =   QList<InvoiceSerial*>();
invoiceserials = GetAll();
	for(int i = 0; i <invoiceserials.count(); i++){
		list.append(qMakePair(invoiceserials[i]->InvoiceSerialID,invoiceserials[i]->Title));
	}
	return list;
}

QList<QPair< int,QString > > InvoiceSerial::GetPairList(QList<InvoiceSerial*> invoiceserials) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoiceserials.count(); i++){
		list.append(qMakePair(invoiceserials[i]->InvoiceSerialID,invoiceserials[i]->Title));
	}
	return list;
}

int InvoiceSerial::GetIndex(QString name) {
	QList<InvoiceSerial*> invoiceserials =   QList<InvoiceSerial*>();
invoiceserials = GetAll();
	for(int i = 0; i <invoiceserials.count(); i++){
		if(invoiceserials[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<InvoiceSerial*> InvoiceSerial::QuerySelect(QString select) {
QList<InvoiceSerial*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceSerial WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceSerial::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceSerial::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setTitle(id, value.toString());
else if (index.column() == 2)
ok = setSerial(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool InvoiceSerial::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceSerialID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceSerial::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceSerial!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Serial"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoiceSerial::setTitle(int InvoiceSerialID, const QString &Title) {
QSqlQuery query;
query.prepare("update InvoiceSerial set Title = ? where InvoiceSerialID = ?");
query.addBindValue(Title);
query.addBindValue(InvoiceSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceSerial::setSerial(int InvoiceSerialID, const QString &Serial) {
QSqlQuery query;
query.prepare("update InvoiceSerial set Serial = ? where InvoiceSerialID = ?");
query.addBindValue(Serial);
query.addBindValue(InvoiceSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceSerial::setCreatedOn(int InvoiceSerialID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceSerial set CreatedOn = ? where InvoiceSerialID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceSerial::setEditedOn(int InvoiceSerialID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceSerial set EditedOn = ? where InvoiceSerialID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

