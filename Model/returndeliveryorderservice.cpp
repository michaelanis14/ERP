/**************************************************************************
**   File: returndeliveryorderservice.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "returndeliveryorderservice.h"
#include "erpmodel.h"

ReturnDeliveryOrderService::ReturnDeliveryOrderService()
 : QSqlRelationalTableModel(){

this->ReturnDeliveryOrderServiceID = 0 ;
this->ReturnDeliveryOrderID = 0 ;
this->ServiceID = 0 ;
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ReturnDeliveryOrderService");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Service", "ServiceID", "Name"));
}
ReturnDeliveryOrderService::ReturnDeliveryOrderService(int ReturnDeliveryOrderServiceID,int ReturnDeliveryOrderID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderServiceID = ReturnDeliveryOrderServiceID ;
this->ReturnDeliveryOrderID = ReturnDeliveryOrderID ;
this->ServiceID = ServiceID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ReturnDeliveryOrderService::ReturnDeliveryOrderService(int ReturnDeliveryOrderID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderServiceID = 0 ;
this->ReturnDeliveryOrderID = ReturnDeliveryOrderID ;
this->ServiceID = ServiceID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ReturnDeliveryOrderService::Init()
{

QString table = "ReturnDeliveryOrderService";
QString query =
"(ReturnDeliveryOrderServiceID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ReturnDeliveryOrderServiceID),"
"ReturnDeliveryOrderID INT NOT NULL, "
" KEY(ReturnDeliveryOrderID),"
"FOREIGN KEY (ReturnDeliveryOrderID) REFERENCES ReturnDeliveryOrder(ReturnDeliveryOrderID)  ON DELETE CASCADE,"
"ServiceID INT NOT NULL, "
"FOREIGN KEY (ServiceID) REFERENCES Service(ServiceID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ReturnDeliveryOrderServiceID")));variables.append(qMakePair(QString(" INT"),QString("ReturnDeliveryOrderID")));variables.append(qMakePair(QString(" INT"),QString("ServiceID")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ReturnDeliveryOrderService* ReturnDeliveryOrderService::p_instance = 0;
ReturnDeliveryOrderService* ReturnDeliveryOrderService::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ReturnDeliveryOrderService();
		ReturnDeliveryOrderService::GetAll();
	}
return p_instance;
}
bool ReturnDeliveryOrderService::save() {
this->EditedOn = QDate::currentDate().toString();
if(ReturnDeliveryOrderServiceID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ReturnDeliveryOrderService (ReturnDeliveryOrderID,ServiceID,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ReturnDeliveryOrderID)+"','"+QString::number(this->ServiceID)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ReturnDeliveryOrderService SET "	"ReturnDeliveryOrderID = '"+QString::number(this->ReturnDeliveryOrderID)+"',"+"ServiceID = '"+QString::number(this->ServiceID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ReturnDeliveryOrderServiceID ='"+QString::number(this->ReturnDeliveryOrderServiceID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ReturnDeliveryOrderServiceID FROM ReturnDeliveryOrderService WHERE ReturnDeliveryOrderID = "+QString::number(ReturnDeliveryOrderID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ReturnDeliveryOrderServiceID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ReturnDeliveryOrderService::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ReturnDeliveryOrderService::remove() {
if(ReturnDeliveryOrderServiceID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ReturnDeliveryOrderService WHERE ReturnDeliveryOrderServiceID ="+QString::number(this->ReturnDeliveryOrderServiceID)+""));
return true;
 }
return false;
}

ReturnDeliveryOrderService* ReturnDeliveryOrderService::get() {
if(ReturnDeliveryOrderServiceID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrderService"
"WHERE ReturnDeliveryOrderServiceID ='"+QString::number(this->ReturnDeliveryOrderServiceID)+"'"));
while (query.next()) {
return new ReturnDeliveryOrderService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new ReturnDeliveryOrderService();
 }

QList<ReturnDeliveryOrderService*> ReturnDeliveryOrderService::GetAll() {
	QList<ReturnDeliveryOrderService*> returndeliveryorderservices =   QList<ReturnDeliveryOrderService*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderService ORDER BY ReturnDeliveryOrderServiceID ASC"));
	while (query.next()) {
returndeliveryorderservices.append(new ReturnDeliveryOrderService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
	return returndeliveryorderservices;
}

ReturnDeliveryOrderService* ReturnDeliveryOrderService::Get(int id) {
ReturnDeliveryOrderService* returndeliveryorderservice = new ReturnDeliveryOrderService();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrderService WHERE ReturnDeliveryOrderServiceID = '"+QString::number(id)+"' ORDER BY ReturnDeliveryOrderServiceID ASC "));
while (query.next()) {
returndeliveryorderservice = new ReturnDeliveryOrderService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return returndeliveryorderservice;
}

ReturnDeliveryOrderService* ReturnDeliveryOrderService::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ReturnDeliveryOrderService();
}

ReturnDeliveryOrderService* ReturnDeliveryOrderService::Get(QString name) {
ReturnDeliveryOrderService* returndeliveryorderservice = new ReturnDeliveryOrderService();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderService WHERE ReturnDeliveryOrderID = QString::number("+name+")"));
while (query.next()) {
returndeliveryorderservice = new ReturnDeliveryOrderService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return returndeliveryorderservice;
 }

QList<ReturnDeliveryOrderService*> ReturnDeliveryOrderService::Search(QString keyword) {
QList<ReturnDeliveryOrderService*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderService"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ReturnDeliveryOrderService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> ReturnDeliveryOrderService::GetStringList() {
	QList<QString> list;
	QList<ReturnDeliveryOrderService*> returndeliveryorderservices =   QList<ReturnDeliveryOrderService*>();
returndeliveryorderservices = GetAll();
	for(int i = 0; i <returndeliveryorderservices.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrderService::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ReturnDeliveryOrderService*> returndeliveryorderservices =   QList<ReturnDeliveryOrderService*>();
returndeliveryorderservices = GetAll();
	for(int i = 0; i <returndeliveryorderservices.count(); i++){
		list.append(qMakePair(returndeliveryorderservices[i]->ReturnDeliveryOrderServiceID,QString::number(returndeliveryorderservices[i]->ReturnDeliveryOrderID)));
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrderService::GetPairList(QList<ReturnDeliveryOrderService*> returndeliveryorderservices) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <returndeliveryorderservices.count(); i++){
		list.append(qMakePair(returndeliveryorderservices[i]->ReturnDeliveryOrderServiceID,QString::number(returndeliveryorderservices[i]->ReturnDeliveryOrderID)));
	}
	return list;
}

int ReturnDeliveryOrderService::GetIndex(QString name) {
	QList<ReturnDeliveryOrderService*> returndeliveryorderservices =   QList<ReturnDeliveryOrderService*>();
returndeliveryorderservices = GetAll();
	for(int i = 0; i <returndeliveryorderservices.count(); i++){
		if(returndeliveryorderservices[i]->ReturnDeliveryOrderID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ReturnDeliveryOrderService*> ReturnDeliveryOrderService::QuerySelect(QString select) {
QList<ReturnDeliveryOrderService*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderService WHERE "+select+"" ));
while (query.next()) {
list.append(new ReturnDeliveryOrderService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags ReturnDeliveryOrderService::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ReturnDeliveryOrderService::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setReturnDeliveryOrderID(id, value.toString());
else if (index.column() == 2)
ok = setServiceID(id, value.toString());
else if (index.column() == 3)
ok = setAmount(id, value.toString());
else if (index.column() == 4)
ok = setPrice(id, value.toString());
else if (index.column() == 5)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 6)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ReturnDeliveryOrderService::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ReturnDeliveryOrderServiceID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ReturnDeliveryOrderService::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ReturnDeliveryOrderService!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Return Delivery Order"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Service"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ReturnDeliveryOrderService::setReturnDeliveryOrderID(int ReturnDeliveryOrderServiceID, const QString &ReturnDeliveryOrderID) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderService set ReturnDeliveryOrderID = ? where ReturnDeliveryOrderServiceID = ?");
query.addBindValue(ReturnDeliveryOrderID);
query.addBindValue(ReturnDeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderService::setServiceID(int ReturnDeliveryOrderServiceID, const QString &ServiceID) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderService set ServiceID = ? where ReturnDeliveryOrderServiceID = ?");
query.addBindValue(ServiceID);
query.addBindValue(ReturnDeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderService::setAmount(int ReturnDeliveryOrderServiceID, const QString &Amount) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderService set Amount = ? where ReturnDeliveryOrderServiceID = ?");
query.addBindValue(Amount);
query.addBindValue(ReturnDeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderService::setPrice(int ReturnDeliveryOrderServiceID, const QString &Price) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderService set Price = ? where ReturnDeliveryOrderServiceID = ?");
query.addBindValue(Price);
query.addBindValue(ReturnDeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderService::setCreatedOn(int ReturnDeliveryOrderServiceID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderService set CreatedOn = ? where ReturnDeliveryOrderServiceID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ReturnDeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderService::setEditedOn(int ReturnDeliveryOrderServiceID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderService set EditedOn = ? where ReturnDeliveryOrderServiceID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ReturnDeliveryOrderServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

