/**************************************************************************
**   File: deliveryorderfreeline.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "deliveryorderfreeline.h"
#include "erpmodel.h"

DeliveryOrderFreeline::DeliveryOrderFreeline()
 : QSqlRelationalTableModel(){

this->DeliveryOrderFreelineID = 0 ;
this->DeliveryOrderID = 0 ;
this->Description = "";
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("DeliveryOrderFreeline");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("DeliveryOrder", "DeliveryOrderID", "Title"));
}
DeliveryOrderFreeline::DeliveryOrderFreeline(int DeliveryOrderFreelineID,int DeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderFreelineID = DeliveryOrderFreelineID ;
this->DeliveryOrderID = DeliveryOrderID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

DeliveryOrderFreeline::DeliveryOrderFreeline(int DeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderFreelineID = 0 ;
this->DeliveryOrderID = DeliveryOrderID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool DeliveryOrderFreeline::Init()
{

QString table = "DeliveryOrderFreeline";
QString query =
"(DeliveryOrderFreelineID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (DeliveryOrderFreelineID),"
"DeliveryOrderID INT NOT NULL, "
"FOREIGN KEY (DeliveryOrderID) REFERENCES DeliveryOrder(DeliveryOrderID)  ON DELETE CASCADE,"
"Description VARCHAR(40) NOT NULL, "
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
DeliveryOrderFreeline* DeliveryOrderFreeline::p_instance = 0;
DeliveryOrderFreeline* DeliveryOrderFreeline::GetInstance() {
	if (p_instance == 0) {
		p_instance = new DeliveryOrderFreeline();
		DeliveryOrderFreeline::GetAll();
	}
return p_instance;
}
bool DeliveryOrderFreeline::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(DeliveryOrderFreelineID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO DeliveryOrderFreeline (DeliveryOrderID,Description,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->DeliveryOrderID)+"','"+QString(this->Description)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE DeliveryOrderFreeline SET "	"DeliveryOrderID = '"+QString::number(this->DeliveryOrderID)+"',"+"Description = '"+QString(this->Description)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE DeliveryOrderFreelineID ='"+QString::number(this->DeliveryOrderFreelineID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  DeliveryOrderFreelineID FROM DeliveryOrderFreeline WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->DeliveryOrderFreelineID = query.value(0).toInt();	
 } 
 }
return true;
}

bool DeliveryOrderFreeline::remove() {
if(DeliveryOrderFreelineID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM DeliveryOrderFreeline WHERE DeliveryOrderFreelineID ="+QString::number(this->DeliveryOrderFreelineID)+""));
return true;
 }
return false;
}

DeliveryOrderFreeline* DeliveryOrderFreeline::get() {
if(DeliveryOrderFreelineID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderFreeline"
"WHERE DeliveryOrderFreelineID ='"+QString::number(this->DeliveryOrderFreelineID)+"'"));
while (query.next()) {
return new DeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new DeliveryOrderFreeline();
 }

QList<DeliveryOrderFreeline*> DeliveryOrderFreeline::GetAll() {
	QList<DeliveryOrderFreeline*> deliveryorderfreelines =   QList<DeliveryOrderFreeline*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderFreeline"));
	while (query.next()) {
deliveryorderfreelines.append(new DeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
qStableSort(deliveryorderfreelines.begin(),deliveryorderfreelines.end());
	return deliveryorderfreelines;
}

DeliveryOrderFreeline* DeliveryOrderFreeline::Get(int id) {
DeliveryOrderFreeline* deliveryorderfreeline = new DeliveryOrderFreeline();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderFreeline WHERE DeliveryOrderFreelineID = '"+QString::number(id)+"'"));
while (query.next()) {
deliveryorderfreeline = new DeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return deliveryorderfreeline;
}

DeliveryOrderFreeline* DeliveryOrderFreeline::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new DeliveryOrderFreeline();
}

DeliveryOrderFreeline* DeliveryOrderFreeline::Get(QString name) {
DeliveryOrderFreeline* deliveryorderfreeline = new DeliveryOrderFreeline();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderFreeline WHERE Description = '"+name+"'"));
while (query.next()) {
deliveryorderfreeline = new DeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return deliveryorderfreeline;
 }

QList<DeliveryOrderFreeline*> DeliveryOrderFreeline::Search(QString keyword) {
QList<DeliveryOrderFreeline*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderFreeline"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new DeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> DeliveryOrderFreeline::GetStringList() {
	QList<QString> list;
	QList<DeliveryOrderFreeline*> deliveryorderfreelines =   QList<DeliveryOrderFreeline*>();
deliveryorderfreelines = GetAll();
	for(int i = 0; i <deliveryorderfreelines.count(); i++){
		list.append(deliveryorderfreelines[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> DeliveryOrderFreeline::GetHashList() {
	QHash<int,QString> list;
	QList<DeliveryOrderFreeline*> deliveryorderfreelines =   QList<DeliveryOrderFreeline*>();
deliveryorderfreelines = GetAll();
	for(int i = 0; i <deliveryorderfreelines.count(); i++){
		list.insert(deliveryorderfreelines[i]->DeliveryOrderFreelineID,deliveryorderfreelines[i]->Description);
	}
	return list;
}

int DeliveryOrderFreeline::GetIndex(QString name) {
	QList<DeliveryOrderFreeline*> deliveryorderfreelines =   QList<DeliveryOrderFreeline*>();
deliveryorderfreelines = GetAll();
	for(int i = 0; i <deliveryorderfreelines.count(); i++){
		if(deliveryorderfreelines[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<DeliveryOrderFreeline*> DeliveryOrderFreeline::QuerySelect(QString select) {
QList<DeliveryOrderFreeline*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderFreeline WHERE "+select+"" ));
while (query.next()) {
list.append(new DeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags DeliveryOrderFreeline::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool DeliveryOrderFreeline::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDeliveryOrderID(id, value.toString());
else if (index.column() == 2)
ok = setDescription(id, value.toString());
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

bool DeliveryOrderFreeline::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->DeliveryOrderFreelineID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void DeliveryOrderFreeline::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() DeliveryOrderFreeline!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Delivery Order"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool DeliveryOrderFreeline::setDeliveryOrderID(int DeliveryOrderFreelineID, const QString &DeliveryOrderID) {
QSqlQuery query;
query.prepare("update DeliveryOrderFreeline set DeliveryOrderID = ? where DeliveryOrderFreelineID = ?");
query.addBindValue(DeliveryOrderID);
query.addBindValue(DeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderFreeline::setDescription(int DeliveryOrderFreelineID, const QString &Description) {
QSqlQuery query;
query.prepare("update DeliveryOrderFreeline set Description = ? where DeliveryOrderFreelineID = ?");
query.addBindValue(Description);
query.addBindValue(DeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderFreeline::setAmount(int DeliveryOrderFreelineID, const QString &Amount) {
QSqlQuery query;
query.prepare("update DeliveryOrderFreeline set Amount = ? where DeliveryOrderFreelineID = ?");
query.addBindValue(Amount);
query.addBindValue(DeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderFreeline::setPrice(int DeliveryOrderFreelineID, const QString &Price) {
QSqlQuery query;
query.prepare("update DeliveryOrderFreeline set Price = ? where DeliveryOrderFreelineID = ?");
query.addBindValue(Price);
query.addBindValue(DeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderFreeline::setCreatedOn(int DeliveryOrderFreelineID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderFreeline set CreatedOn = ? where DeliveryOrderFreelineID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(DeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderFreeline::setEditedOn(int DeliveryOrderFreelineID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderFreeline set EditedOn = ? where DeliveryOrderFreelineID = ?");
query.addBindValue(EditedOn);
query.addBindValue(DeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

