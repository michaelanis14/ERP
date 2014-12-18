/**************************************************************************
**   File: purchase.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchase.h"
#include "erpmodel.h"

Purchase::Purchase()
 : QSqlRelationalTableModel(){

this->PurchaseID = 0 ;
this->PurchaseSerialID = 0 ;
this->CreationDate = QDate();
this->DeliveryDate = QDate();
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Purchase");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("PurchaseSerial", "PurchaseSerialID", "Title"));
}
Purchase::Purchase(int PurchaseID,int PurchaseSerialID,QDate CreationDate,QDate DeliveryDate,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseID = PurchaseID ;
this->PurchaseSerialID = PurchaseSerialID ;
this->CreationDate = CreationDate ;
this->DeliveryDate = DeliveryDate ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Purchase::Purchase(int PurchaseSerialID,QDate CreationDate,QDate DeliveryDate,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseID = 0 ;
this->PurchaseSerialID = PurchaseSerialID ;
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
"PurchaseSerialID INT NOT NULL, "
" KEY(PurchaseSerialID),"
"FOREIGN KEY (PurchaseSerialID) REFERENCES PurchaseSerial(PurchaseSerialID)  ON DELETE CASCADE,"
"CreationDate DATE NOT NULL, "
"DeliveryDate DATE NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("PurchaseID")));variables.append(qMakePair(QString(" INT"),QString("PurchaseSerialID")));variables.append(qMakePair(QString(""),QString("CreationDate")));variables.append(qMakePair(QString(""),QString("DeliveryDate")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
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
this->EditedOn = QDate::currentDate().toString();
if(PurchaseID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Purchase (PurchaseSerialID,CreationDate,DeliveryDate,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->PurchaseSerialID)+"','"+(this->CreationDate.toString("yyyy-MM-dd"))+"','"+(this->DeliveryDate.toString("yyyy-MM-dd"))+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Purchase SET "	"PurchaseSerialID = '"+QString::number(this->PurchaseSerialID)+"',"+"CreationDate = '"+(this->CreationDate.toString("yyyy-MM-dd"))+"',"+"DeliveryDate = '"+(this->DeliveryDate.toString("yyyy-MM-dd"))+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseID ='"+QString::number(this->PurchaseID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseID FROM Purchase WHERE PurchaseSerialID = "+QString::number(PurchaseSerialID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PurchaseID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Purchase::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
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
return new Purchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString());
 }

}
return new Purchase();
 }

QList<Purchase*> Purchase::GetAll() {
	QList<Purchase*> purchases =   QList<Purchase*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase ORDER BY PurchaseID ASC"));
	while (query.next()) {
purchases.append(new Purchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString()));
	}
	return purchases;
}

Purchase* Purchase::Get(int id) {
Purchase* purchase = new Purchase();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Purchase WHERE PurchaseID = '"+QString::number(id)+"' ORDER BY PurchaseID ASC "));
while (query.next()) {
purchase = new Purchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString());
 }
purchase->purchasestoreproducts = PurchaseStoreProduct::QuerySelect("PurchaseID = " + QString::number(id));
purchase->purchasefreelines = PurchaseFreeLine::QuerySelect("PurchaseID = " + QString::number(id));

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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase WHERE PurchaseSerialID = QString::number("+name+")"));
while (query.next()) {
purchase = new Purchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString());

 }
purchase->purchasestoreproducts = PurchaseStoreProduct::QuerySelect("PurchaseID = " +QString::number(purchase->PurchaseID));
purchase->purchasefreelines = PurchaseFreeLine::QuerySelect("PurchaseID = " +QString::number(purchase->PurchaseID));

}
return purchase;
 }

QList<Purchase*> Purchase::Search(QString keyword) {
QList<Purchase*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Purchase"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Purchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString()));
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
	return list;
}

QList<QPair< int,QString > > Purchase::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
		list.append(qMakePair(purchases[i]->PurchaseID,QString::number(purchases[i]->PurchaseSerialID)));
	}
	return list;
}

QList<QPair< int,QString > > Purchase::GetPairList(QList<Purchase*> purchases) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <purchases.count(); i++){
		list.append(qMakePair(purchases[i]->PurchaseID,QString::number(purchases[i]->PurchaseSerialID)));
	}
	return list;
}

int Purchase::GetIndex(QString name) {
	QList<Purchase*> purchases =   QList<Purchase*>();
purchases = GetAll();
	for(int i = 0; i <purchases.count(); i++){
		if(purchases[i]->PurchaseSerialID == name.toInt()){
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
list.append(new Purchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags Purchase::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 6 || index.column() == 7)
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
ok = setPurchaseSerialID(id, value.toString());
else if (index.column() == 2)
ok = setCreationDate(id, value.toString());
else if (index.column() == 3)
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
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Purchase Serial"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Creation Date"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Delivery Date"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Purchase::setPurchaseSerialID(int PurchaseID, const QString &PurchaseSerialID) {
QSqlQuery query;
query.prepare("update Purchase set PurchaseSerialID = ? where PurchaseID = ?");
query.addBindValue(PurchaseSerialID);
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

