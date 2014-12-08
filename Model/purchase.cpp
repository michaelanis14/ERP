/**************************************************************************
**   File: purchase.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchase.h"
#include "erpmodel.h"

Purchase::Purchase()
 : QSqlRelationalTableModel(){

this->PurchaseID = 0 ;
this->CreationDate = "";
this->DeliveryDate = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Purchase");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Purchase::Purchase(int PurchaseID,QString CreationDate,QString DeliveryDate,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseID = PurchaseID ;
this->CreationDate = CreationDate ;
this->DeliveryDate = DeliveryDate ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Purchase::Purchase(QString CreationDate,QString DeliveryDate,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseID = 0 ;
this->CreationDate = CreationDate ;
this->DeliveryDate = DeliveryDate ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Purchase::Init()
{

QString table = "Purchase";
QString query =
"(PurchaseID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PurchaseID),"
"CreationDate VARCHAR(40) NOT NULL, "
" KEY(CreationDate),"
"DeliveryDate VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Purchase* Purchase::p_instance = 0;
Purchase* Purchase::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Purchase();
		Purchase::GetAll();
	}
return p_instance;
}
bool Purchase::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(PurchaseID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Purchase (CreationDate,DeliveryDate,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->CreationDate)+"','"+QString(this->DeliveryDate)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Purchase SET "	"CreationDate = '"+QString(this->CreationDate)+"',"+"DeliveryDate = '"+QString(this->DeliveryDate)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseID ='"+QString::number(this->PurchaseID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseID FROM Purchase WHERE CreationDate = '"+CreationDate+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PurchaseID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Purchase::remove() {
if(PurchaseID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Purchase WHERE PurchaseID ="+QString::number(this->PurchaseID)+""));
return true;
 }
return false;
}

Purchase* Purchase::get() {
if(PurchaseID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Purchase"
"WHERE PurchaseID ='"+QString::number(this->PurchaseID)+"'"));
while (query.next()) {
return new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
 }

}
return new Purchase();
 }

QList<Purchase*> Purchase::GetAll() {
	QList<Purchase*> purchases =   QList<Purchase*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase"));
	while (query.next()) {
purchases.append(new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
	}
qStableSort(purchases.begin(),purchases.end());
	return purchases;
}

Purchase* Purchase::Get(int id) {
Purchase* purchase = new Purchase();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Purchase WHERE PurchaseID = '"+QString::number(id)+"'"));
while (query.next()) {
purchase = new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
 }
purchase->purchasestoreproducts = PurchaseStoreProduct::QuerySelect("PurchaseID = " + QString::number(id));

}
return purchase;
}

Purchase* Purchase::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Purchase();
}

Purchase* Purchase::Get(QString name) {
Purchase* purchase = new Purchase();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase WHERE CreationDate = '"+name+"'"));
while (query.next()) {
purchase = new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());

 }
purchase->purchasestoreproducts = PurchaseStoreProduct::QuerySelect("PurchaseID = " +QString::number(purchase->PurchaseID));

}
return purchase;
 }

QList<Purchase*> Purchase::Search(QString keyword) {
QList<Purchase*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase"
"WHERE" 
"CreationDate LIKE '%"+keyword+"%'"
"OR DeliveryDate LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> Purchase::GetStringList() {
	QList<QString> list;
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> Purchase::GetHashList() {
	QHash<int,QString> list;
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
		list.insert(purchases[i]->PurchaseID,purchases[i]->CreationDate);
	}
	return list;
}

int Purchase::GetIndex(QString name) {
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
		if(purchases[i]->CreationDate == name){
			return i;
		}
	}
	return 0;
}

QList<Purchase*> Purchase::QuerySelect(QString select) {
QList<Purchase*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase WHERE "+select+"" ));
while (query.next()) {
list.append(new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags Purchase::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Purchase::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setCreationDate(id, value.toString());
else if (index.column() == 2)
ok = setDeliveryDate(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Purchase::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->PurchaseID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Purchase::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Purchase!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Creation Date"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Delivery Date"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Purchase::setCreationDate(int PurchaseID, const QString &CreationDate) {
QSqlQuery query;
query.prepare("update Purchase set CreationDate = ? where PurchaseID = ?");
query.addBindValue(CreationDate);
query.addBindValue(PurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Purchase::setDeliveryDate(int PurchaseID, const QString &DeliveryDate) {
QSqlQuery query;
query.prepare("update Purchase set DeliveryDate = ? where PurchaseID = ?");
query.addBindValue(DeliveryDate);
query.addBindValue(PurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Purchase::setCreatedOn(int PurchaseID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Purchase set CreatedOn = ? where PurchaseID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(PurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Purchase::setEditedOn(int PurchaseID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Purchase set EditedOn = ? where PurchaseID = ?");
query.addBindValue(EditedOn);
query.addBindValue(PurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

