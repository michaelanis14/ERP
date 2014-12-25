/**************************************************************************
**   File: deliveryorderserial.cpp
**   Created on: Fri Dec 19 13:01:03 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "deliveryorderserial.h"
#include "erpmodel.h"

DeliveryOrderSerial::DeliveryOrderSerial()
 : QSqlRelationalTableModel(){

this->DeliveryOrderSerialID = 0 ;
this->Title = "";
this->Serial = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("DeliveryOrderSerial");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
DeliveryOrderSerial::DeliveryOrderSerial(int DeliveryOrderSerialID,QString Title,int Serial,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderSerialID = DeliveryOrderSerialID ;
this->Title = Title ;
this->Serial = Serial ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

DeliveryOrderSerial::DeliveryOrderSerial(QString Title,int Serial,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderSerialID = 0 ;
this->Title = Title ;
this->Serial = Serial ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool DeliveryOrderSerial::Init()
{

QString table = "DeliveryOrderSerial";
QString query =
"(DeliveryOrderSerialID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (DeliveryOrderSerialID),"
"Title VARCHAR(40) NOT NULL, "
" KEY(Title),"
"Serial INT NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("DeliveryOrderSerialID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Title")));variables.append(qMakePair(QString(" INT"),QString("Serial")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
DeliveryOrderSerial* DeliveryOrderSerial::p_instance = 0;
DeliveryOrderSerial* DeliveryOrderSerial::GetInstance() {
	if (p_instance == 0) {
		p_instance = new DeliveryOrderSerial();
		DeliveryOrderSerial::GetAll();
	}
return p_instance;
}
bool DeliveryOrderSerial::save() {
this->EditedOn = QDate::currentDate().toString();
if(DeliveryOrderSerialID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO DeliveryOrderSerial (Title,Serial,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->Serial)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE DeliveryOrderSerial SET "	"Title = '"+QString(this->Title)+"',"+"Serial = '"+QString::number(this->Serial)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE DeliveryOrderSerialID ='"+QString::number(this->DeliveryOrderSerialID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  DeliveryOrderSerialID FROM DeliveryOrderSerial WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->DeliveryOrderSerialID = query.value(0).toInt();	
 } 
 }
return true;
}
bool DeliveryOrderSerial::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool DeliveryOrderSerial::remove() {
if(DeliveryOrderSerialID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM DeliveryOrderSerial WHERE DeliveryOrderSerialID ="+QString::number(this->DeliveryOrderSerialID)+""));
return true;
 }
return false;
}

DeliveryOrderSerial* DeliveryOrderSerial::get() {
if(DeliveryOrderSerialID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderSerial"
"WHERE DeliveryOrderSerialID ='"+QString::number(this->DeliveryOrderSerialID)+"'"));
while (query.next()) {
return new DeliveryOrderSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new DeliveryOrderSerial();
 }

QList<DeliveryOrderSerial*> DeliveryOrderSerial::GetAll() {
	QList<DeliveryOrderSerial*> deliveryorderserials =   QList<DeliveryOrderSerial*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderSerial ORDER BY DeliveryOrderSerialID ASC"));
	while (query.next()) {
deliveryorderserials.append(new DeliveryOrderSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return deliveryorderserials;
}

DeliveryOrderSerial* DeliveryOrderSerial::Get(int id) {
DeliveryOrderSerial* deliveryorderserial = new DeliveryOrderSerial();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderSerial WHERE DeliveryOrderSerialID = '"+QString::number(id)+"' ORDER BY DeliveryOrderSerialID ASC "));
while (query.next()) {
deliveryorderserial = new DeliveryOrderSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return deliveryorderserial;
}

DeliveryOrderSerial* DeliveryOrderSerial::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new DeliveryOrderSerial();
}

DeliveryOrderSerial* DeliveryOrderSerial::Get(QString name) {
DeliveryOrderSerial* deliveryorderserial = new DeliveryOrderSerial();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderSerial WHERE Title = '"+name+"'"));
while (query.next()) {
deliveryorderserial = new DeliveryOrderSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return deliveryorderserial;
 }

QList<DeliveryOrderSerial*> DeliveryOrderSerial::Search(QString keyword) {
QList<DeliveryOrderSerial*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderSerial"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new DeliveryOrderSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> DeliveryOrderSerial::GetStringList() {
	QList<QString> list;
	QList<DeliveryOrderSerial*> deliveryorderserials =   QList<DeliveryOrderSerial*>();
deliveryorderserials = GetAll();
	for(int i = 0; i <deliveryorderserials.count(); i++){
		list.append(deliveryorderserials[i]->Title);
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrderSerial::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<DeliveryOrderSerial*> deliveryorderserials =   QList<DeliveryOrderSerial*>();
deliveryorderserials = GetAll();
	for(int i = 0; i <deliveryorderserials.count(); i++){
		list.append(qMakePair(deliveryorderserials[i]->DeliveryOrderSerialID,deliveryorderserials[i]->Title));
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrderSerial::GetPairList(QList<DeliveryOrderSerial*> deliveryorderserials) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <deliveryorderserials.count(); i++){
		list.append(qMakePair(deliveryorderserials[i]->DeliveryOrderSerialID,deliveryorderserials[i]->Title));
	}
	return list;
}

int DeliveryOrderSerial::GetIndex(QString name) {
	QList<DeliveryOrderSerial*> deliveryorderserials =   QList<DeliveryOrderSerial*>();
deliveryorderserials = GetAll();
	for(int i = 0; i <deliveryorderserials.count(); i++){
		if(deliveryorderserials[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<DeliveryOrderSerial*> DeliveryOrderSerial::QuerySelect(QString select) {
QList<DeliveryOrderSerial*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderSerial WHERE "+select+"" ));
while (query.next()) {
list.append(new DeliveryOrderSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags DeliveryOrderSerial::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool DeliveryOrderSerial::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool DeliveryOrderSerial::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->DeliveryOrderSerialID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void DeliveryOrderSerial::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() DeliveryOrderSerial!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Serial"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool DeliveryOrderSerial::setTitle(int DeliveryOrderSerialID, const QString &Title) {
QSqlQuery query;
query.prepare("update DeliveryOrderSerial set Title = ? where DeliveryOrderSerialID = ?");
query.addBindValue(Title);
query.addBindValue(DeliveryOrderSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderSerial::setSerial(int DeliveryOrderSerialID, const QString &Serial) {
QSqlQuery query;
query.prepare("update DeliveryOrderSerial set Serial = ? where DeliveryOrderSerialID = ?");
query.addBindValue(Serial);
query.addBindValue(DeliveryOrderSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderSerial::setCreatedOn(int DeliveryOrderSerialID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderSerial set CreatedOn = ? where DeliveryOrderSerialID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(DeliveryOrderSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderSerial::setEditedOn(int DeliveryOrderSerialID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderSerial set EditedOn = ? where DeliveryOrderSerialID = ?");
query.addBindValue(EditedOn);
query.addBindValue(DeliveryOrderSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

