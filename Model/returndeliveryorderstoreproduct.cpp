/**************************************************************************
**   File: returndeliveryorderstoreproduct.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "returndeliveryorderstoreproduct.h"
#include "erpmodel.h"

ReturnDeliveryOrderStoreProduct::ReturnDeliveryOrderStoreProduct()
 : QSqlRelationalTableModel(){

this->ReturnDeliveryOrderStoreProductID = 0 ;
this->ReturnDeliveryOrderID = 0 ;
this->StoreID = 0 ;
this->ProductID = 0 ;
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ReturnDeliveryOrderStoreProduct");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Store", "StoreID", "Name"));
this->setRelation(3, QSqlRelation("Product", "ProductID", "Name"));
}
ReturnDeliveryOrderStoreProduct::ReturnDeliveryOrderStoreProduct(int ReturnDeliveryOrderStoreProductID,int ReturnDeliveryOrderID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderStoreProductID = ReturnDeliveryOrderStoreProductID ;
this->ReturnDeliveryOrderID = ReturnDeliveryOrderID ;
this->StoreID = StoreID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ReturnDeliveryOrderStoreProduct::ReturnDeliveryOrderStoreProduct(int ReturnDeliveryOrderID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderStoreProductID = 0 ;
this->ReturnDeliveryOrderID = ReturnDeliveryOrderID ;
this->StoreID = StoreID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ReturnDeliveryOrderStoreProduct::Init()
{

QString table = "ReturnDeliveryOrderStoreProduct";
QString query =
"(ReturnDeliveryOrderStoreProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ReturnDeliveryOrderStoreProductID),"
"ReturnDeliveryOrderID INT NOT NULL, "
" KEY(ReturnDeliveryOrderID),"
"FOREIGN KEY (ReturnDeliveryOrderID) REFERENCES ReturnDeliveryOrder(ReturnDeliveryOrderID)  ON DELETE CASCADE,"
"StoreID INT NOT NULL, "
"FOREIGN KEY (StoreID) REFERENCES Store(StoreID)  ON DELETE CASCADE,"
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ReturnDeliveryOrderStoreProductID")));variables.append(qMakePair(QString(" INT"),QString("ReturnDeliveryOrderID")));variables.append(qMakePair(QString(" INT"),QString("StoreID")));variables.append(qMakePair(QString(" INT"),QString("ProductID")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ReturnDeliveryOrderStoreProduct* ReturnDeliveryOrderStoreProduct::p_instance = 0;
ReturnDeliveryOrderStoreProduct* ReturnDeliveryOrderStoreProduct::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ReturnDeliveryOrderStoreProduct();
		ReturnDeliveryOrderStoreProduct::GetAll();
	}
return p_instance;
}
bool ReturnDeliveryOrderStoreProduct::save() {
this->EditedOn = QDate::currentDate().toString();
if(ReturnDeliveryOrderStoreProductID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ReturnDeliveryOrderStoreProduct (ReturnDeliveryOrderID,StoreID,ProductID,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ReturnDeliveryOrderID)+"','"+QString::number(this->StoreID)+"','"+QString::number(this->ProductID)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ReturnDeliveryOrderStoreProduct SET "	"ReturnDeliveryOrderID = '"+QString::number(this->ReturnDeliveryOrderID)+"',"+"StoreID = '"+QString::number(this->StoreID)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ReturnDeliveryOrderStoreProductID ='"+QString::number(this->ReturnDeliveryOrderStoreProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ReturnDeliveryOrderStoreProductID FROM ReturnDeliveryOrderStoreProduct WHERE ReturnDeliveryOrderID = "+QString::number(ReturnDeliveryOrderID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ReturnDeliveryOrderStoreProductID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ReturnDeliveryOrderStoreProduct::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ReturnDeliveryOrderStoreProduct::remove() {
if(ReturnDeliveryOrderStoreProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ReturnDeliveryOrderStoreProduct WHERE ReturnDeliveryOrderStoreProductID ="+QString::number(this->ReturnDeliveryOrderStoreProductID)+""));
return true;
 }
return false;
}

ReturnDeliveryOrderStoreProduct* ReturnDeliveryOrderStoreProduct::get() {
if(ReturnDeliveryOrderStoreProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrderStoreProduct"
"WHERE ReturnDeliveryOrderStoreProductID ='"+QString::number(this->ReturnDeliveryOrderStoreProductID)+"'"));
while (query.next()) {
return new ReturnDeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return new ReturnDeliveryOrderStoreProduct();
 }

QList<ReturnDeliveryOrderStoreProduct*> ReturnDeliveryOrderStoreProduct::GetAll() {
	QList<ReturnDeliveryOrderStoreProduct*> returndeliveryorderstoreproducts =   QList<ReturnDeliveryOrderStoreProduct*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderStoreProduct ORDER BY ReturnDeliveryOrderStoreProductID ASC"));
	while (query.next()) {
returndeliveryorderstoreproducts.append(new ReturnDeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
	}
	return returndeliveryorderstoreproducts;
}

ReturnDeliveryOrderStoreProduct* ReturnDeliveryOrderStoreProduct::Get(int id) {
ReturnDeliveryOrderStoreProduct* returndeliveryorderstoreproduct = new ReturnDeliveryOrderStoreProduct();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrderStoreProduct WHERE ReturnDeliveryOrderStoreProductID = '"+QString::number(id)+"' ORDER BY ReturnDeliveryOrderStoreProductID ASC "));
while (query.next()) {
returndeliveryorderstoreproduct = new ReturnDeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return returndeliveryorderstoreproduct;
}

ReturnDeliveryOrderStoreProduct* ReturnDeliveryOrderStoreProduct::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ReturnDeliveryOrderStoreProduct();
}

ReturnDeliveryOrderStoreProduct* ReturnDeliveryOrderStoreProduct::Get(QString name) {
ReturnDeliveryOrderStoreProduct* returndeliveryorderstoreproduct = new ReturnDeliveryOrderStoreProduct();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderStoreProduct WHERE ReturnDeliveryOrderID = QString::number("+name+")"));
while (query.next()) {
returndeliveryorderstoreproduct = new ReturnDeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());

 }

}
return returndeliveryorderstoreproduct;
 }

QList<ReturnDeliveryOrderStoreProduct*> ReturnDeliveryOrderStoreProduct::Search(QString keyword) {
QList<ReturnDeliveryOrderStoreProduct*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderStoreProduct"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ReturnDeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

QList<QString> ReturnDeliveryOrderStoreProduct::GetStringList() {
	QList<QString> list;
	QList<ReturnDeliveryOrderStoreProduct*> returndeliveryorderstoreproducts =   QList<ReturnDeliveryOrderStoreProduct*>();
returndeliveryorderstoreproducts = GetAll();
	for(int i = 0; i <returndeliveryorderstoreproducts.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrderStoreProduct::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ReturnDeliveryOrderStoreProduct*> returndeliveryorderstoreproducts =   QList<ReturnDeliveryOrderStoreProduct*>();
returndeliveryorderstoreproducts = GetAll();
	for(int i = 0; i <returndeliveryorderstoreproducts.count(); i++){
		list.append(qMakePair(returndeliveryorderstoreproducts[i]->ReturnDeliveryOrderStoreProductID,QString::number(returndeliveryorderstoreproducts[i]->ReturnDeliveryOrderID)));
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrderStoreProduct::GetPairList(QList<ReturnDeliveryOrderStoreProduct*> returndeliveryorderstoreproducts) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <returndeliveryorderstoreproducts.count(); i++){
		list.append(qMakePair(returndeliveryorderstoreproducts[i]->ReturnDeliveryOrderStoreProductID,QString::number(returndeliveryorderstoreproducts[i]->ReturnDeliveryOrderID)));
	}
	return list;
}

int ReturnDeliveryOrderStoreProduct::GetIndex(QString name) {
	QList<ReturnDeliveryOrderStoreProduct*> returndeliveryorderstoreproducts =   QList<ReturnDeliveryOrderStoreProduct*>();
returndeliveryorderstoreproducts = GetAll();
	for(int i = 0; i <returndeliveryorderstoreproducts.count(); i++){
		if(returndeliveryorderstoreproducts[i]->ReturnDeliveryOrderID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ReturnDeliveryOrderStoreProduct*> ReturnDeliveryOrderStoreProduct::QuerySelect(QString select) {
QList<ReturnDeliveryOrderStoreProduct*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderStoreProduct WHERE "+select+"" ));
while (query.next()) {
list.append(new ReturnDeliveryOrderStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

Qt::ItemFlags ReturnDeliveryOrderStoreProduct::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ReturnDeliveryOrderStoreProduct::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setReturnDeliveryOrderID(id, value.toString());
else if (index.column() == 2)
ok = setStoreID(id, value.toString());
else if (index.column() == 3)
ok = setProductID(id, value.toString());
else if (index.column() == 4)
ok = setAmount(id, value.toString());
else if (index.column() == 5)
ok = setPrice(id, value.toString());
else if (index.column() == 6)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 7)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ReturnDeliveryOrderStoreProduct::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ReturnDeliveryOrderStoreProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ReturnDeliveryOrderStoreProduct::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ReturnDeliveryOrderStoreProduct!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Return Delivery Order"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Store"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ReturnDeliveryOrderStoreProduct::setReturnDeliveryOrderID(int ReturnDeliveryOrderStoreProductID, const QString &ReturnDeliveryOrderID) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderStoreProduct set ReturnDeliveryOrderID = ? where ReturnDeliveryOrderStoreProductID = ?");
query.addBindValue(ReturnDeliveryOrderID);
query.addBindValue(ReturnDeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderStoreProduct::setStoreID(int ReturnDeliveryOrderStoreProductID, const QString &StoreID) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderStoreProduct set StoreID = ? where ReturnDeliveryOrderStoreProductID = ?");
query.addBindValue(StoreID);
query.addBindValue(ReturnDeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderStoreProduct::setProductID(int ReturnDeliveryOrderStoreProductID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderStoreProduct set ProductID = ? where ReturnDeliveryOrderStoreProductID = ?");
query.addBindValue(ProductID);
query.addBindValue(ReturnDeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderStoreProduct::setAmount(int ReturnDeliveryOrderStoreProductID, const QString &Amount) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderStoreProduct set Amount = ? where ReturnDeliveryOrderStoreProductID = ?");
query.addBindValue(Amount);
query.addBindValue(ReturnDeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderStoreProduct::setPrice(int ReturnDeliveryOrderStoreProductID, const QString &Price) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderStoreProduct set Price = ? where ReturnDeliveryOrderStoreProductID = ?");
query.addBindValue(Price);
query.addBindValue(ReturnDeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderStoreProduct::setCreatedOn(int ReturnDeliveryOrderStoreProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderStoreProduct set CreatedOn = ? where ReturnDeliveryOrderStoreProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ReturnDeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderStoreProduct::setEditedOn(int ReturnDeliveryOrderStoreProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderStoreProduct set EditedOn = ? where ReturnDeliveryOrderStoreProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ReturnDeliveryOrderStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

