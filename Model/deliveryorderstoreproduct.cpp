/**************************************************************************
**   File: deliveryorderstoreproduct.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "deliveryorderstoreproduct.h"
#include "erpmodel.h"

DeliveryOrderStoreProduct::DeliveryOrderStoreProduct()
 : QSqlRelationalTableModel(){

this->DeliveryOrderStoreProductID = 0 ;
this->DeliveryOrderID = 0 ;
this->StoreID = 0 ;
this->ProductID = 0 ;
this->Amount = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("DeliveryOrderStoreProduct");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Store", "StoreID", "Name"));
this->setRelation(3, QSqlRelation("Product", "ProductID", "Name"));
}
DeliveryOrderStoreProduct::DeliveryOrderStoreProduct(int DeliveryOrderStoreProductID,int DeliveryOrderID,int StoreID,int ProductID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderStoreProductID = DeliveryOrderStoreProductID ;
this->DeliveryOrderID = DeliveryOrderID ;
this->StoreID = StoreID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

DeliveryOrderStoreProduct::DeliveryOrderStoreProduct(int DeliveryOrderID,int StoreID,int ProductID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderStoreProductID = 0 ;
this->DeliveryOrderID = DeliveryOrderID ;
this->StoreID = StoreID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool DeliveryOrderStoreProduct::Init()
{

QString table = "DeliveryOrderStoreProduct";
QString query =
"(DeliveryOrderStoreProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (DeliveryOrderStoreProductID),"
"DeliveryOrderID INT NOT NULL, "
" KEY(DeliveryOrderID),"
"FOREIGN KEY (DeliveryOrderID) REFERENCES DeliveryOrder(DeliveryOrderID)  ON DELETE CASCADE,"
"StoreID INT NOT NULL, "
"FOREIGN KEY (StoreID) REFERENCES Store(StoreID)  ON DELETE CASCADE,"
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("DeliveryOrderStoreProductID")));variables.append(qMakePair(QString(" INT"),QString("DeliveryOrderID")));variables.append(qMakePair(QString(" INT"),QString("StoreID")));variables.append(qMakePair(QString(" INT"),QString("ProductID")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
DeliveryOrderStoreProduct* DeliveryOrderStoreProduct::p_instance = 0;
DeliveryOrderStoreProduct* DeliveryOrderStoreProduct::GetInstance() {
	if (p_instance == 0) {
		p_instance = new DeliveryOrderStoreProduct();
		DeliveryOrderStoreProduct::GetAll();
	}
return p_instance;
}
bool DeliveryOrderStoreProduct::save() {
this->EditedOn = QDate::currentDate().toString();
if(DeliveryOrderStoreProductID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO DeliveryOrderStoreProduct (DeliveryOrderID,StoreID,ProductID,Amount,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->DeliveryOrderID)+"','"+QString::number(this->StoreID)+"','"+QString::number(this->ProductID)+"','"+QString::number(this->Amount)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE DeliveryOrderStoreProduct SET "	"DeliveryOrderID = '"+QString::number(this->DeliveryOrderID)+"',"+"StoreID = '"+QString::number(this->StoreID)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE DeliveryOrderStoreProductID ='"+QString::number(this->DeliveryOrderStoreProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  DeliveryOrderStoreProductID FROM DeliveryOrderStoreProduct WHERE DeliveryOrderID = "+QString::number(DeliveryOrderID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->DeliveryOrderStoreProductID = query.value(0).toInt();	
 } 
 }
return true;
}
bool DeliveryOrderStoreProduct::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool DeliveryOrderStoreProduct::remove() {
if(DeliveryOrderStoreProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM DeliveryOrderStoreProduct WHERE DeliveryOrderStoreProductID ="+QString::number(this->DeliveryOrderStoreProductID)+""));
return true;
 }
return false;
}

DeliveryOrderStoreProduct* DeliveryOrderStoreProduct::get() {
if(DeliveryOrderStoreProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderStoreProduct"
"WHERE DeliveryOrderStoreProductID ='"+QString::number(this->DeliveryOrderStoreProductID)+"'"));
while (query.next()) {
return new DeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new DeliveryOrderStoreProduct();
 }

QList<DeliveryOrderStoreProduct*> DeliveryOrderStoreProduct::GetAll() {
	QList<DeliveryOrderStoreProduct*> deliveryorderstoreproducts =   QList<DeliveryOrderStoreProduct*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStoreProduct ORDER BY DeliveryOrderStoreProductID ASC"));
	while (query.next()) {
deliveryorderstoreproducts.append(new DeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
	return deliveryorderstoreproducts;
}

DeliveryOrderStoreProduct* DeliveryOrderStoreProduct::Get(int id) {
DeliveryOrderStoreProduct* deliveryorderstoreproduct = new DeliveryOrderStoreProduct();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrderStoreProduct WHERE DeliveryOrderStoreProductID = '"+QString::number(id)+"' ORDER BY DeliveryOrderStoreProductID ASC "));
while (query.next()) {
deliveryorderstoreproduct = new DeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return deliveryorderstoreproduct;
}

DeliveryOrderStoreProduct* DeliveryOrderStoreProduct::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new DeliveryOrderStoreProduct();
}

DeliveryOrderStoreProduct* DeliveryOrderStoreProduct::Get(QString name) {
DeliveryOrderStoreProduct* deliveryorderstoreproduct = new DeliveryOrderStoreProduct();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStoreProduct WHERE DeliveryOrderID = QString::number("+name+")"));
while (query.next()) {
deliveryorderstoreproduct = new DeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return deliveryorderstoreproduct;
 }

QList<DeliveryOrderStoreProduct*> DeliveryOrderStoreProduct::Search(QString keyword) {
QList<DeliveryOrderStoreProduct*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStoreProduct"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new DeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> DeliveryOrderStoreProduct::GetStringList() {
	QList<QString> list;
	QList<DeliveryOrderStoreProduct*> deliveryorderstoreproducts =   QList<DeliveryOrderStoreProduct*>();
deliveryorderstoreproducts = GetAll();
	for(int i = 0; i <deliveryorderstoreproducts.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrderStoreProduct::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<DeliveryOrderStoreProduct*> deliveryorderstoreproducts =   QList<DeliveryOrderStoreProduct*>();
deliveryorderstoreproducts = GetAll();
	for(int i = 0; i <deliveryorderstoreproducts.count(); i++){
		list.append(qMakePair(deliveryorderstoreproducts[i]->DeliveryOrderStoreProductID,QString::number(deliveryorderstoreproducts[i]->DeliveryOrderID)));
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrderStoreProduct::GetPairList(QList<DeliveryOrderStoreProduct*> deliveryorderstoreproducts) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <deliveryorderstoreproducts.count(); i++){
		list.append(qMakePair(deliveryorderstoreproducts[i]->DeliveryOrderStoreProductID,QString::number(deliveryorderstoreproducts[i]->DeliveryOrderID)));
	}
	return list;
}

int DeliveryOrderStoreProduct::GetIndex(QString name) {
	QList<DeliveryOrderStoreProduct*> deliveryorderstoreproducts =   QList<DeliveryOrderStoreProduct*>();
deliveryorderstoreproducts = GetAll();
	for(int i = 0; i <deliveryorderstoreproducts.count(); i++){
		if(deliveryorderstoreproducts[i]->DeliveryOrderID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<DeliveryOrderStoreProduct*> DeliveryOrderStoreProduct::QuerySelect(QString select) {
QList<DeliveryOrderStoreProduct*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrderStoreProduct WHERE "+select+"" ));
while (query.next()) {
list.append(new DeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags DeliveryOrderStoreProduct::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool DeliveryOrderStoreProduct::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDeliveryOrderID(id, value.toString());
else if (index.column() == 2)
ok = setStoreID(id, value.toString());
else if (index.column() == 3)
ok = setProductID(id, value.toString());
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

bool DeliveryOrderStoreProduct::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->DeliveryOrderStoreProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void DeliveryOrderStoreProduct::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() DeliveryOrderStoreProduct!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Delivery Order"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Store"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool DeliveryOrderStoreProduct::setDeliveryOrderID(int DeliveryOrderStoreProductID, const QString &DeliveryOrderID) {
QSqlQuery query;
query.prepare("update DeliveryOrderStoreProduct set DeliveryOrderID = ? where DeliveryOrderStoreProductID = ?");
query.addBindValue(DeliveryOrderID);
query.addBindValue(DeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderStoreProduct::setStoreID(int DeliveryOrderStoreProductID, const QString &StoreID) {
QSqlQuery query;
query.prepare("update DeliveryOrderStoreProduct set StoreID = ? where DeliveryOrderStoreProductID = ?");
query.addBindValue(StoreID);
query.addBindValue(DeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderStoreProduct::setProductID(int DeliveryOrderStoreProductID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update DeliveryOrderStoreProduct set ProductID = ? where DeliveryOrderStoreProductID = ?");
query.addBindValue(ProductID);
query.addBindValue(DeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderStoreProduct::setAmount(int DeliveryOrderStoreProductID, const QString &Amount) {
QSqlQuery query;
query.prepare("update DeliveryOrderStoreProduct set Amount = ? where DeliveryOrderStoreProductID = ?");
query.addBindValue(Amount);
query.addBindValue(DeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderStoreProduct::setCreatedOn(int DeliveryOrderStoreProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderStoreProduct set CreatedOn = ? where DeliveryOrderStoreProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(DeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrderStoreProduct::setEditedOn(int DeliveryOrderStoreProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrderStoreProduct set EditedOn = ? where DeliveryOrderStoreProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(DeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

