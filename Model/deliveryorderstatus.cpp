/**************************************************************************
**   File: deliveryorderstatus.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "deliveryorderstatus.h"
#include "erpmodel.h"

DeliveryOrderStatus::DeliveryOrderStatus()
 : QSqlRelationalTableModel(){

this->DeliveryOrderStatusID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("DeliveryOrderStatus");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
DeliveryOrderStatus::DeliveryOrderStatus(int DeliveryOrderStatusID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderStatusID = DeliveryOrderStatusID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

DeliveryOrderStatus::DeliveryOrderStatus(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderStatusID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool DeliveryOrderStatus::Init()
{

QString table = "DeliveryOrderStatus";
QString query =
"(DeliveryOrderStatusID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (DeliveryOrderStatusID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("DeliveryOrderStatusID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
DeliveryOrderStatus* DeliveryOrderStatus::p_instance = 0;
DeliveryOrderStatus* DeliveryOrderStatus::GetInstance() {
	if (p_instance == 0) {
		p_instance = new DeliveryOrderStatus();
		DeliveryOrderStatus::GetAll();
	}
return p_instance;
}
bool DeliveryOrderStatus::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(DeliveryOrderStatusID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO DeliveryOrderStatus (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE DeliveryOrderStatus SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE DeliveryOrderStatusID ='"+QString::number(this->DeliveryOrderStatusID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  DeliveryOrderStatusID FROM DeliveryOrderStatus WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->DeliveryOrderStatusID = query.value(0).toInt();	
 } 
 }
return true;
}
bool DeliveryOrderStatus::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool DeliveryOrderStatus::remove() {
if(DeliveryOrderStatusID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM DeliveryOrderStatus WHERE DeliveryOrderStatusID ="+QString::number(this->DeliveryOrderStatusID)+""));
return true;
 }
return false;
}

DeliveryOrderStatus* DeliveryOrderStatus::get() {
if(DeliveryOrderStatusID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderStatus"
"WHERE DeliveryOrderStatusID ='"+QString::number(this->DeliveryOrderStatusID)+"'"));
while (query.next()) {
return new DeliveryOrderStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new DeliveryOrderStatus();
 }

QList<DeliveryOrderStatus*> DeliveryOrderStatus::GetAll() {
	QList<DeliveryOrderStatus*> deliveryorderstatuss =   QList<DeliveryOrderStatus*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStatus ORDER BY DeliveryOrderStatusID ASC"));
	while (query.next()) {
deliveryorderstatuss.append(new DeliveryOrderStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return deliveryorderstatuss;
}

DeliveryOrderStatus* DeliveryOrderStatus::Get(int id) {
DeliveryOrderStatus* deliveryorderstatus = new DeliveryOrderStatus();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderStatus WHERE DeliveryOrderStatusID = '"+QString::number(id)+"' ORDER BY DeliveryOrderStatusID ASC "));
while (query.next()) {
deliveryorderstatus = new DeliveryOrderStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return deliveryorderstatus;
}

DeliveryOrderStatus* DeliveryOrderStatus::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new DeliveryOrderStatus();
}

DeliveryOrderStatus* DeliveryOrderStatus::Get(QString name) {
DeliveryOrderStatus* deliveryorderstatus = new DeliveryOrderStatus();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStatus WHERE Description = '"+name+"'"));
while (query.next()) {
deliveryorderstatus = new DeliveryOrderStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return deliveryorderstatus;
 }

QList<DeliveryOrderStatus*> DeliveryOrderStatus::Search(QString keyword) {
QList<DeliveryOrderStatus*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStatus"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new DeliveryOrderStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> DeliveryOrderStatus::GetStringList() {
	QList<QString> list;
	QList<DeliveryOrderStatus*> deliveryorderstatuss =   QList<DeliveryOrderStatus*>();
deliveryorderstatuss = GetAll();
	for(int i = 0; i <deliveryorderstatuss.count(); i++){
		list.append(deliveryorderstatuss[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrderStatus::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<DeliveryOrderStatus*> deliveryorderstatuss =   QList<DeliveryOrderStatus*>();
deliveryorderstatuss = GetAll();
	for(int i = 0; i <deliveryorderstatuss.count(); i++){
		list.append(qMakePair(deliveryorderstatuss[i]->DeliveryOrderStatusID,deliveryorderstatuss[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrderStatus::GetPairList(QList<DeliveryOrderStatus*> deliveryorderstatuss) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <deliveryorderstatuss.count(); i++){
		list.append(qMakePair(deliveryorderstatuss[i]->DeliveryOrderStatusID,deliveryorderstatuss[i]->Description));
	}
	return list;
}

int DeliveryOrderStatus::GetIndex(QString name) {
	QList<DeliveryOrderStatus*> deliveryorderstatuss =   QList<DeliveryOrderStatus*>();
deliveryorderstatuss = GetAll();
	for(int i = 0; i <deliveryorderstatuss.count(); i++){
		if(deliveryorderstatuss[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<DeliveryOrderStatus*> DeliveryOrderStatus::QuerySelect(QString select) {
QList<DeliveryOrderStatus*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStatus WHERE "+select+"" ));
while (query.next()) {
list.append(new DeliveryOrderStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags DeliveryOrderStatus::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool DeliveryOrderStatus::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool DeliveryOrderStatus::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->DeliveryOrderStatusID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void DeliveryOrderStatus::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() DeliveryOrderStatus!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool DeliveryOrderStatus::setDescription(int DeliveryOrderStatusID, const QString &Description) {
QSqlQuery query;
query.prepare("update DeliveryOrderStatus set Description = ? where DeliveryOrderStatusID = ?");
query.addBindValue(Description);
query.addBindValue(DeliveryOrderStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderStatus::setCreatedOn(int DeliveryOrderStatusID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderStatus set CreatedOn = ? where DeliveryOrderStatusID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(DeliveryOrderStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderStatus::setEditedOn(int DeliveryOrderStatusID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderStatus set EditedOn = ? where DeliveryOrderStatusID = ?");
query.addBindValue(EditedOn);
query.addBindValue(DeliveryOrderStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

