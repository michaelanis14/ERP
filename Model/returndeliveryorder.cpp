/**************************************************************************
**   File: returndeliveryorder.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "returndeliveryorder.h"
#include "erpmodel.h"

ReturnDeliveryOrder::ReturnDeliveryOrder()
 : QSqlRelationalTableModel(){

this->ReturnDeliveryOrderID = 0 ;
this->Serial = 0 ;
this->DeliveryOrderID = 0 ;
this->Date = QDate();
this->Note = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ReturnDeliveryOrder");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ReturnDeliveryOrder::ReturnDeliveryOrder(int ReturnDeliveryOrderID,int Serial,int DeliveryOrderID,QDate Date,QString Note,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderID = ReturnDeliveryOrderID ;
this->Serial = Serial ;
this->DeliveryOrderID = DeliveryOrderID ;
this->Date = Date ;
this->Note = Note ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ReturnDeliveryOrder::ReturnDeliveryOrder(int Serial,int DeliveryOrderID,QDate Date,QString Note,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderID = 0 ;
this->Serial = Serial ;
this->DeliveryOrderID = DeliveryOrderID ;
this->Date = Date ;
this->Note = Note ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ReturnDeliveryOrder::Init()
{

QString table = "ReturnDeliveryOrder";
QString query =
"(ReturnDeliveryOrderID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ReturnDeliveryOrderID),"
"Serial INT NOT NULL, "
" KEY(Serial),"
"DeliveryOrderID INT NOT NULL, "
"FOREIGN KEY (DeliveryOrderID) REFERENCES DeliveryOrder(DeliveryOrderID)  ON DELETE CASCADE,"
"Date DATE NOT NULL, "
"Note VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ReturnDeliveryOrderID")));variables.append(qMakePair(QString(" INT"),QString("Serial")));variables.append(qMakePair(QString(" INT"),QString("DeliveryOrderID")));variables.append(qMakePair(QString(""),QString("Date")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Note")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ReturnDeliveryOrder* ReturnDeliveryOrder::p_instance = 0;
ReturnDeliveryOrder* ReturnDeliveryOrder::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ReturnDeliveryOrder();
		ReturnDeliveryOrder::GetAll();
	}
return p_instance;
}
bool ReturnDeliveryOrder::save() {
this->EditedOn = QDate::currentDate().toString();
if(ReturnDeliveryOrderID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ReturnDeliveryOrder (Serial,DeliveryOrderID,Date,Note,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->Serial)+"','"+QString::number(this->DeliveryOrderID)+"','"+(this->Date.toString("yyyy-MM-dd"))+"','"+QString(this->Note)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ReturnDeliveryOrder SET "	"Serial = '"+QString::number(this->Serial)+"',"+"DeliveryOrderID = '"+QString::number(this->DeliveryOrderID)+"',"+"Date = '"+(this->Date.toString("yyyy-MM-dd"))+"',"+"Note = '"+QString(this->Note)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ReturnDeliveryOrderID ='"+QString::number(this->ReturnDeliveryOrderID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ReturnDeliveryOrderID FROM ReturnDeliveryOrder WHERE Serial = "+QString::number(Serial)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ReturnDeliveryOrderID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ReturnDeliveryOrder::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ReturnDeliveryOrder::remove() {
if(ReturnDeliveryOrderID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ReturnDeliveryOrder WHERE ReturnDeliveryOrderID ="+QString::number(this->ReturnDeliveryOrderID)+""));
return true;
 }
return false;
}

ReturnDeliveryOrder* ReturnDeliveryOrder::get() {
if(ReturnDeliveryOrderID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrder"
"WHERE ReturnDeliveryOrderID ='"+QString::number(this->ReturnDeliveryOrderID)+"'"));
while (query.next()) {
return new ReturnDeliveryOrder(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString());
 }

}
return new ReturnDeliveryOrder();
 }

QList<ReturnDeliveryOrder*> ReturnDeliveryOrder::GetAll() {
	QList<ReturnDeliveryOrder*> returndeliveryorders =   QList<ReturnDeliveryOrder*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrder ORDER BY ReturnDeliveryOrderID ASC"));
	while (query.next()) {
returndeliveryorders.append(new ReturnDeliveryOrder(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString()));
	}
	return returndeliveryorders;
}

ReturnDeliveryOrder* ReturnDeliveryOrder::Get(int id) {
ReturnDeliveryOrder* returndeliveryorder = new ReturnDeliveryOrder();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrder WHERE ReturnDeliveryOrderID = '"+QString::number(id)+"' ORDER BY ReturnDeliveryOrderID ASC "));
while (query.next()) {
returndeliveryorder = new ReturnDeliveryOrder(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString());
 }
returndeliveryorder->returndeliveryorderstoreproducts = ReturnDeliveryOrderStoreProduct::QuerySelect("ReturnDeliveryOrderID = " + QString::number(id));
returndeliveryorder->returndeliveryorderservices = ReturnDeliveryOrderService::QuerySelect("ReturnDeliveryOrderID = " + QString::number(id));
returndeliveryorder->returndeliveryorderfreelines = ReturnDeliveryOrderFreeline::QuerySelect("ReturnDeliveryOrderID = " + QString::number(id));

}
return returndeliveryorder;
}

ReturnDeliveryOrder* ReturnDeliveryOrder::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ReturnDeliveryOrder();
}

ReturnDeliveryOrder* ReturnDeliveryOrder::Get(QString name) {
ReturnDeliveryOrder* returndeliveryorder = new ReturnDeliveryOrder();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrder WHERE Serial = QString::number("+name+")"));
while (query.next()) {
returndeliveryorder = new ReturnDeliveryOrder(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString());

 }
returndeliveryorder->returndeliveryorderstoreproducts = ReturnDeliveryOrderStoreProduct::QuerySelect("ReturnDeliveryOrderID = " +QString::number(returndeliveryorder->ReturnDeliveryOrderID));
returndeliveryorder->returndeliveryorderservices = ReturnDeliveryOrderService::QuerySelect("ReturnDeliveryOrderID = " +QString::number(returndeliveryorder->ReturnDeliveryOrderID));
returndeliveryorder->returndeliveryorderfreelines = ReturnDeliveryOrderFreeline::QuerySelect("ReturnDeliveryOrderID = " +QString::number(returndeliveryorder->ReturnDeliveryOrderID));

}
return returndeliveryorder;
 }

QList<ReturnDeliveryOrder*> ReturnDeliveryOrder::Search(QString keyword) {
QList<ReturnDeliveryOrder*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrder"
"WHERE" 
"Note LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ReturnDeliveryOrder(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> ReturnDeliveryOrder::GetStringList() {
	QList<QString> list;
	QList<ReturnDeliveryOrder*> returndeliveryorders =   QList<ReturnDeliveryOrder*>();
returndeliveryorders = GetAll();
	for(int i = 0; i <returndeliveryorders.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrder::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ReturnDeliveryOrder*> returndeliveryorders =   QList<ReturnDeliveryOrder*>();
returndeliveryorders = GetAll();
	for(int i = 0; i <returndeliveryorders.count(); i++){
		list.append(qMakePair(returndeliveryorders[i]->ReturnDeliveryOrderID,QString::number(returndeliveryorders[i]->Serial)));
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrder::GetPairList(QList<ReturnDeliveryOrder*> returndeliveryorders) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <returndeliveryorders.count(); i++){
		list.append(qMakePair(returndeliveryorders[i]->ReturnDeliveryOrderID,QString::number(returndeliveryorders[i]->Serial)));
	}
	return list;
}

int ReturnDeliveryOrder::GetIndex(QString name) {
	QList<ReturnDeliveryOrder*> returndeliveryorders =   QList<ReturnDeliveryOrder*>();
returndeliveryorders = GetAll();
	for(int i = 0; i <returndeliveryorders.count(); i++){
		if(returndeliveryorders[i]->Serial == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ReturnDeliveryOrder*> ReturnDeliveryOrder::QuerySelect(QString select) {
QList<ReturnDeliveryOrder*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrder WHERE "+select+"" ));
while (query.next()) {
list.append(new ReturnDeliveryOrder(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags ReturnDeliveryOrder::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 8 || index.column() == 9)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ReturnDeliveryOrder::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setSerial(id, value.toString());
else if (index.column() == 2)
ok = setDeliveryOrderID(id, value.toString());
else if (index.column() == 3)
ok = setDate(id, value.toString());
else if (index.column() == 4)
ok = setNote(id, value.toString());
else if (index.column() == 8)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 9)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ReturnDeliveryOrder::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ReturnDeliveryOrderID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ReturnDeliveryOrder::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ReturnDeliveryOrder!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Serial"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Delivery Order"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ReturnDeliveryOrder::setSerial(int ReturnDeliveryOrderID, const QString &Serial) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrder set Serial = ? where ReturnDeliveryOrderID = ?");
query.addBindValue(Serial);
query.addBindValue(ReturnDeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrder::setDeliveryOrderID(int ReturnDeliveryOrderID, const QString &DeliveryOrderID) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrder set DeliveryOrderID = ? where ReturnDeliveryOrderID = ?");
query.addBindValue(DeliveryOrderID);
query.addBindValue(ReturnDeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrder::setDate(int ReturnDeliveryOrderID, const QString &Date) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrder set Date = ? where ReturnDeliveryOrderID = ?");
query.addBindValue(Date);
query.addBindValue(ReturnDeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrder::setNote(int ReturnDeliveryOrderID, const QString &Note) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrder set Note = ? where ReturnDeliveryOrderID = ?");
query.addBindValue(Note);
query.addBindValue(ReturnDeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrder::setCreatedOn(int ReturnDeliveryOrderID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrder set CreatedOn = ? where ReturnDeliveryOrderID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ReturnDeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrder::setEditedOn(int ReturnDeliveryOrderID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrder set EditedOn = ? where ReturnDeliveryOrderID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ReturnDeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

