/**************************************************************************
**   File: purchaseserial.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchaseserial.h"
#include "erpmodel.h"

PurchaseSerial::PurchaseSerial()
 : QSqlRelationalTableModel(){

this->PurchaseSerialID = 0 ;
this->Title = "";
this->Serial = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("PurchaseSerial");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
PurchaseSerial::PurchaseSerial(int PurchaseSerialID,QString Title,int Serial,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseSerialID = PurchaseSerialID ;
this->Title = Title ;
this->Serial = Serial ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

PurchaseSerial::PurchaseSerial(QString Title,int Serial,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseSerialID = 0 ;
this->Title = Title ;
this->Serial = Serial ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool PurchaseSerial::Init()
{

QString table = "PurchaseSerial";
QString query =
"(PurchaseSerialID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PurchaseSerialID),"
"Title VARCHAR(40) NOT NULL, "
" KEY(Title),"
"Serial INT NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("PurchaseSerialID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Title")));variables.append(qMakePair(QString(" INT"),QString("Serial")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
PurchaseSerial* PurchaseSerial::p_instance = 0;
PurchaseSerial* PurchaseSerial::GetInstance() {
	if (p_instance == 0) {
		p_instance = new PurchaseSerial();
		PurchaseSerial::GetAll();
	}
return p_instance;
}
bool PurchaseSerial::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(PurchaseSerialID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO PurchaseSerial (Title,Serial,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->Serial)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE PurchaseSerial SET "	"Title = '"+QString(this->Title)+"',"+"Serial = '"+QString::number(this->Serial)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseSerialID ='"+QString::number(this->PurchaseSerialID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseSerialID FROM PurchaseSerial WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PurchaseSerialID = query.value(0).toInt();	
 } 
 }
return true;
}
bool PurchaseSerial::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool PurchaseSerial::remove() {
if(PurchaseSerialID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM PurchaseSerial WHERE PurchaseSerialID ="+QString::number(this->PurchaseSerialID)+""));
return true;
 }
return false;
}

PurchaseSerial* PurchaseSerial::get() {
if(PurchaseSerialID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseSerial"
"WHERE PurchaseSerialID ='"+QString::number(this->PurchaseSerialID)+"'"));
while (query.next()) {
return new PurchaseSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new PurchaseSerial();
 }

QList<PurchaseSerial*> PurchaseSerial::GetAll() {
	QList<PurchaseSerial*> purchaseserials =   QList<PurchaseSerial*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseSerial ORDER BY PurchaseSerialID ASC"));
	while (query.next()) {
purchaseserials.append(new PurchaseSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return purchaseserials;
}

PurchaseSerial* PurchaseSerial::Get(int id) {
PurchaseSerial* purchaseserial = new PurchaseSerial();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseSerial WHERE PurchaseSerialID = '"+QString::number(id)+"' ORDER BY PurchaseSerialID ASC "));
while (query.next()) {
purchaseserial = new PurchaseSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return purchaseserial;
}

PurchaseSerial* PurchaseSerial::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new PurchaseSerial();
}

PurchaseSerial* PurchaseSerial::Get(QString name) {
PurchaseSerial* purchaseserial = new PurchaseSerial();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseSerial WHERE Title = '"+name+"'"));
while (query.next()) {
purchaseserial = new PurchaseSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return purchaseserial;
 }

QList<PurchaseSerial*> PurchaseSerial::Search(QString keyword) {
QList<PurchaseSerial*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseSerial"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new PurchaseSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> PurchaseSerial::GetStringList() {
	QList<QString> list;
	QList<PurchaseSerial*> purchaseserials =   QList<PurchaseSerial*>();
purchaseserials = GetAll();
	for(int i = 0; i <purchaseserials.count(); i++){
		list.append(purchaseserials[i]->Title);
	}
	return list;
}

QList<QPair< int,QString > > PurchaseSerial::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<PurchaseSerial*> purchaseserials =   QList<PurchaseSerial*>();
purchaseserials = GetAll();
	for(int i = 0; i <purchaseserials.count(); i++){
		list.append(qMakePair(purchaseserials[i]->PurchaseSerialID,purchaseserials[i]->Title));
	}
	return list;
}

QList<QPair< int,QString > > PurchaseSerial::GetPairList(QList<PurchaseSerial*> purchaseserials) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <purchaseserials.count(); i++){
		list.append(qMakePair(purchaseserials[i]->PurchaseSerialID,purchaseserials[i]->Title));
	}
	return list;
}

int PurchaseSerial::GetIndex(QString name) {
	QList<PurchaseSerial*> purchaseserials =   QList<PurchaseSerial*>();
purchaseserials = GetAll();
	for(int i = 0; i <purchaseserials.count(); i++){
		if(purchaseserials[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<PurchaseSerial*> PurchaseSerial::QuerySelect(QString select) {
QList<PurchaseSerial*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseSerial WHERE "+select+"" ));
while (query.next()) {
list.append(new PurchaseSerial(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags PurchaseSerial::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool PurchaseSerial::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool PurchaseSerial::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->PurchaseSerialID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void PurchaseSerial::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() PurchaseSerial!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Serial"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool PurchaseSerial::setTitle(int PurchaseSerialID, const QString &Title) {
QSqlQuery query;
query.prepare("update PurchaseSerial set Title = ? where PurchaseSerialID = ?");
query.addBindValue(Title);
query.addBindValue(PurchaseSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseSerial::setSerial(int PurchaseSerialID, const QString &Serial) {
QSqlQuery query;
query.prepare("update PurchaseSerial set Serial = ? where PurchaseSerialID = ?");
query.addBindValue(Serial);
query.addBindValue(PurchaseSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseSerial::setCreatedOn(int PurchaseSerialID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update PurchaseSerial set CreatedOn = ? where PurchaseSerialID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(PurchaseSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseSerial::setEditedOn(int PurchaseSerialID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update PurchaseSerial set EditedOn = ? where PurchaseSerialID = ?");
query.addBindValue(EditedOn);
query.addBindValue(PurchaseSerialID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

