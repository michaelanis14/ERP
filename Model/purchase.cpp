/**************************************************************************
**   File: purchase.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchase.h"
#include "erpmodel.h"

Purchase::Purchase()
 : QSqlRelationalTableModel(){

this->PurchaseID = 0 ;
this->Title = "";
this->StoreID = 0 ;
this->CreationDate = "";
this->DeliveryDate = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Purchase");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Store", "StoreID", "Name"));
}
Purchase::Purchase(int PurchaseID,QString Title,int StoreID,QString CreationDate,QString DeliveryDate,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseID = PurchaseID ;
this->Title = Title ;
this->StoreID = StoreID ;
this->CreationDate = CreationDate ;
this->DeliveryDate = DeliveryDate ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Purchase::Purchase(QString Title,int StoreID,QString CreationDate,QString DeliveryDate,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseID = 0 ;
this->Title = Title ;
this->StoreID = StoreID ;
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
"Title VARCHAR(40) NOT NULL, "
"StoreID INT NOT NULL, "
"FOREIGN KEY (StoreID) REFERENCES Store(StoreID)  ON DELETE CASCADE,"
"CreationDate VARCHAR(40) NOT NULL, "
"DeliveryDate VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

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
ErpModel::GetInstance()->qeryExec("INSERT INTO Purchase (Title,StoreID,CreationDate,DeliveryDate,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->StoreID)+"','"+QString(this->CreationDate)+"','"+QString(this->DeliveryDate)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Purchase SET "	"Title = '"+QString(this->Title)+"',"+"StoreID = '"+QString::number(this->StoreID)+"',"+"CreationDate = '"+QString(this->CreationDate)+"',"+"DeliveryDate = '"+QString(this->DeliveryDate)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseID ='"+QString::number(this->PurchaseID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseID FROM Purchase WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
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
return new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString());
 }

}
return new Purchase();
 }

QList<Purchase*> Purchase::GetAll() {
	QList<Purchase*> purchases =   QList<Purchase*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase"));
	while (query.next()) {
purchases.append(new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString()));
	}
qSort(purchases);
	return purchases;
}

Purchase* Purchase::Get(int id) {
Purchase* purchase = new Purchase();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Purchase WHERE PurchaseID = '"+QString::number(id)+"'"));
while (query.next()) {
purchase = new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString());
 }
purchase->purchaseproducts = PurchaseProduct::QuerySelect("PurchaseID = " + QString::number(id));

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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase WHERE Title = '"+name+"'"));
while (query.next()) {
purchase = new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString());

 }
purchase->purchaseproducts = PurchaseProduct::QuerySelect("PurchaseID = " +QString::number(purchase->PurchaseID));

}
return purchase;
 }

QList<Purchase*> Purchase::Search(QString keyword) {
QList<Purchase*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreationDate LIKE '%"+keyword+"%'"
"OR DeliveryDate LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> Purchase::GetStringList() {
	QList<QString> list;
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
		list.append(purchases[i]->Title);
	}
	qSort(list);
	return list;
}

QHash<int,QString> Purchase::GetHashList() {
	QHash<int,QString> list;
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
		list.insert(purchases[i]->PurchaseID,purchases[i]->Title);
	}
	return list;
}

int Purchase::GetIndex(QString name) {
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
		if(purchases[i]->Title == name){
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
list.append(new Purchase(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags Purchase::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 6 || index.column() == 7)
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
ok = setTitle(id, value.toString());
else if (index.column() == 2)
ok = setStoreID(id, value.toString());
else if (index.column() == 3)
ok = setCreationDate(id, value.toString());
else if (index.column() == 4)
ok = setDeliveryDate(id, value.toString());
else if (index.column() == 6)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 7)
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
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Store"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Creation Date"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Delivery Date"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Purchase::setTitle(int PurchaseID, const QString &Title) {
QSqlQuery query;
query.prepare("update Purchase set Title = ? where PurchaseID = ?");
query.addBindValue(Title);
query.addBindValue(PurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Purchase::setStoreID(int PurchaseID, const QString &StoreID) {
QSqlQuery query;
query.prepare("update Purchase set StoreID = ? where PurchaseID = ?");
query.addBindValue(StoreID);
query.addBindValue(PurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
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

