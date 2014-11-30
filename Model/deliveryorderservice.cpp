/**************************************************************************
**   File: deliveryorderservice.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "deliveryorderservice.h"
#include "erpmodel.h"

DeliveryOrderService::DeliveryOrderService()
 : QSqlRelationalTableModel(){

this->DeliveryOrderServiceID = 0 ;
this->Title = "";
this->DeliveryOrderID = 0 ;
this->ServiceID = 0 ;
this->Amount = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("DeliveryOrderService");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("DeliveryOrder", "DeliveryOrderID", "Title"));
this->setRelation(3, QSqlRelation("Service", "ServiceID", "Name"));
}
DeliveryOrderService::DeliveryOrderService(int DeliveryOrderServiceID,QString Title,int DeliveryOrderID,int ServiceID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderServiceID = DeliveryOrderServiceID ;
this->Title = Title ;
this->DeliveryOrderID = DeliveryOrderID ;
this->ServiceID = ServiceID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

DeliveryOrderService::DeliveryOrderService(QString Title,int DeliveryOrderID,int ServiceID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderServiceID = 0 ;
this->Title = Title ;
this->DeliveryOrderID = DeliveryOrderID ;
this->ServiceID = ServiceID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool DeliveryOrderService::Init()
{

QString table = "DeliveryOrderService";
QString query =
"(DeliveryOrderServiceID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (DeliveryOrderServiceID),"
"Title VARCHAR(40) NOT NULL, "
"DeliveryOrderID INT NOT NULL, "
"FOREIGN KEY (DeliveryOrderID) REFERENCES DeliveryOrder(DeliveryOrderID)  ON DELETE CASCADE,"
"ServiceID INT NOT NULL, "
"FOREIGN KEY (ServiceID) REFERENCES Service(ServiceID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
DeliveryOrderService* DeliveryOrderService::p_instance = 0;
DeliveryOrderService* DeliveryOrderService::GetInstance() {
	if (p_instance == 0) {
		p_instance = new DeliveryOrderService();
		DeliveryOrderService::GetAll();
	}
return p_instance;
}
bool DeliveryOrderService::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(DeliveryOrderServiceID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO DeliveryOrderService (Title,DeliveryOrderID,ServiceID,Amount,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->DeliveryOrderID)+"','"+QString::number(this->ServiceID)+"','"+QString::number(this->Amount)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE DeliveryOrderService SET "	"Title = '"+QString(this->Title)+"',"+"DeliveryOrderID = '"+QString::number(this->DeliveryOrderID)+"',"+"ServiceID = '"+QString::number(this->ServiceID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE DeliveryOrderServiceID ='"+QString::number(this->DeliveryOrderServiceID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  DeliveryOrderServiceID FROM DeliveryOrderService WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->DeliveryOrderServiceID = query.value(0).toInt();	
 } 
 }
return true;
}

bool DeliveryOrderService::remove() {
if(DeliveryOrderServiceID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM DeliveryOrderService WHERE DeliveryOrderServiceID ="+QString::number(this->DeliveryOrderServiceID)+""));
return true;
 }
return false;
}

DeliveryOrderService* DeliveryOrderService::get() {
if(DeliveryOrderServiceID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderService"
"WHERE DeliveryOrderServiceID ='"+QString::number(this->DeliveryOrderServiceID)+"'"));
while (query.next()) {
return new DeliveryOrderService(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new DeliveryOrderService();
 }

QList<DeliveryOrderService*> DeliveryOrderService::GetAll() {
	QList<DeliveryOrderService*> deliveryorderservices =   QList<DeliveryOrderService*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderService"));
	while (query.next()) {
deliveryorderservices.append(new DeliveryOrderService(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
qSort(deliveryorderservices);
	return deliveryorderservices;
}

DeliveryOrderService* DeliveryOrderService::Get(int id) {
DeliveryOrderService* deliveryorderservice = new DeliveryOrderService();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderService WHERE DeliveryOrderServiceID = '"+QString::number(id)+"'"));
while (query.next()) {
deliveryorderservice = new DeliveryOrderService(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return deliveryorderservice;
}

DeliveryOrderService* DeliveryOrderService::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new DeliveryOrderService();
}

DeliveryOrderService* DeliveryOrderService::Get(QString name) {
DeliveryOrderService* deliveryorderservice = new DeliveryOrderService();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderService WHERE Title = '"+name+"'"));
while (query.next()) {
deliveryorderservice = new DeliveryOrderService(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return deliveryorderservice;
 }

QList<DeliveryOrderService*> DeliveryOrderService::Search(QString keyword) {
QList<DeliveryOrderService*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderService"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new DeliveryOrderService(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> DeliveryOrderService::GetStringList() {
	QList<QString> list;
	QList<DeliveryOrderService*> deliveryorderservices =   QList<DeliveryOrderService*>();
deliveryorderservices = GetAll();
	for(int i = 0; i <deliveryorderservices.count(); i++){
		list.append(deliveryorderservices[i]->Title);
	}
	qSort(list);
	return list;
}

QHash<int,QString> DeliveryOrderService::GetHashList() {
	QHash<int,QString> list;
	QList<DeliveryOrderService*> deliveryorderservices =   QList<DeliveryOrderService*>();
deliveryorderservices = GetAll();
	for(int i = 0; i <deliveryorderservices.count(); i++){
		list.insert(deliveryorderservices[i]->DeliveryOrderServiceID,deliveryorderservices[i]->Title);
	}
	return list;
}

int DeliveryOrderService::GetIndex(QString name) {
	QList<DeliveryOrderService*> deliveryorderservices =   QList<DeliveryOrderService*>();
deliveryorderservices = GetAll();
	for(int i = 0; i <deliveryorderservices.count(); i++){
		if(deliveryorderservices[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<DeliveryOrderService*> DeliveryOrderService::QuerySelect(QString select) {
QList<DeliveryOrderService*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderService WHERE "+select+"" ));
while (query.next()) {
list.append(new DeliveryOrderService(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags DeliveryOrderService::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool DeliveryOrderService::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setTitle(id, value.toString());
else if (index.column() == 2)
ok = setDeliveryOrderID(id, value.toString());
else if (index.column() == 3)
ok = setServiceID(id, value.toString());
else if (index.column() == 4)
ok = setAmount(id, value.toString());
else if (index.column() == 5)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 6)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool DeliveryOrderService::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->DeliveryOrderServiceID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void DeliveryOrderService::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() DeliveryOrderService!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Delivery Order"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Service"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool DeliveryOrderService::setTitle(int DeliveryOrderServiceID, const QString &Title) {
QSqlQuery query;
query.prepare("update DeliveryOrderService set Title = ? where DeliveryOrderServiceID = ?");
query.addBindValue(Title);
query.addBindValue(DeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderService::setDeliveryOrderID(int DeliveryOrderServiceID, const QString &DeliveryOrderID) {
QSqlQuery query;
query.prepare("update DeliveryOrderService set DeliveryOrderID = ? where DeliveryOrderServiceID = ?");
query.addBindValue(DeliveryOrderID);
query.addBindValue(DeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderService::setServiceID(int DeliveryOrderServiceID, const QString &ServiceID) {
QSqlQuery query;
query.prepare("update DeliveryOrderService set ServiceID = ? where DeliveryOrderServiceID = ?");
query.addBindValue(ServiceID);
query.addBindValue(DeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderService::setAmount(int DeliveryOrderServiceID, const QString &Amount) {
QSqlQuery query;
query.prepare("update DeliveryOrderService set Amount = ? where DeliveryOrderServiceID = ?");
query.addBindValue(Amount);
query.addBindValue(DeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderService::setCreatedOn(int DeliveryOrderServiceID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderService set CreatedOn = ? where DeliveryOrderServiceID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(DeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderService::setEditedOn(int DeliveryOrderServiceID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderService set EditedOn = ? where DeliveryOrderServiceID = ?");
query.addBindValue(EditedOn);
query.addBindValue(DeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

