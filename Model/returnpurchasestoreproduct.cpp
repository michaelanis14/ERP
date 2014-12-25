/**************************************************************************
**   File: returnpurchasestoreproduct.cpp
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "returnpurchasestoreproduct.h"
#include "erpmodel.h"

ReturnPurchaseStoreProduct::ReturnPurchaseStoreProduct()
 : QSqlRelationalTableModel(){

this->ReturnPurchaseStoreProductID = 0 ;
this->StoreID = 0 ;
this->ReturnPurchaseID = 0 ;
this->ContactID = 0 ;
this->ProductID = 0 ;
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ReturnPurchaseStoreProduct");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Store", "StoreID", "Name"));
this->setRelation(3, QSqlRelation("Contact", "ContactID", "Name"));
this->setRelation(4, QSqlRelation("Product", "ProductID", "Name"));
}
ReturnPurchaseStoreProduct::ReturnPurchaseStoreProduct(int ReturnPurchaseStoreProductID,int StoreID,int ReturnPurchaseID,int ContactID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnPurchaseStoreProductID = ReturnPurchaseStoreProductID ;
this->StoreID = StoreID ;
this->ReturnPurchaseID = ReturnPurchaseID ;
this->ContactID = ContactID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ReturnPurchaseStoreProduct::ReturnPurchaseStoreProduct(int StoreID,int ReturnPurchaseID,int ContactID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnPurchaseStoreProductID = 0 ;
this->StoreID = StoreID ;
this->ReturnPurchaseID = ReturnPurchaseID ;
this->ContactID = ContactID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ReturnPurchaseStoreProduct::Init()
{

QString table = "ReturnPurchaseStoreProduct";
QString query =
"(ReturnPurchaseStoreProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ReturnPurchaseStoreProductID),"
"StoreID INT NOT NULL, "
" KEY(StoreID),"
"FOREIGN KEY (StoreID) REFERENCES Store(StoreID)  ON DELETE CASCADE,"
"ReturnPurchaseID INT NOT NULL, "
"FOREIGN KEY (ReturnPurchaseID) REFERENCES ReturnPurchase(ReturnPurchaseID)  ON DELETE CASCADE,"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ReturnPurchaseStoreProductID")));variables.append(qMakePair(QString(" INT"),QString("StoreID")));variables.append(qMakePair(QString(" INT"),QString("ReturnPurchaseID")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" INT"),QString("ProductID")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ReturnPurchaseStoreProduct* ReturnPurchaseStoreProduct::p_instance = 0;
ReturnPurchaseStoreProduct* ReturnPurchaseStoreProduct::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ReturnPurchaseStoreProduct();
		ReturnPurchaseStoreProduct::GetAll();
	}
return p_instance;
}
bool ReturnPurchaseStoreProduct::save() {
this->EditedOn = QDate::currentDate().toString();
if(ReturnPurchaseStoreProductID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ReturnPurchaseStoreProduct (StoreID,ReturnPurchaseID,ContactID,ProductID,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->StoreID)+"','"+QString::number(this->ReturnPurchaseID)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->ProductID)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ReturnPurchaseStoreProduct SET "	"StoreID = '"+QString::number(this->StoreID)+"',"+"ReturnPurchaseID = '"+QString::number(this->ReturnPurchaseID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ReturnPurchaseStoreProductID ='"+QString::number(this->ReturnPurchaseStoreProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ReturnPurchaseStoreProductID FROM ReturnPurchaseStoreProduct WHERE StoreID = "+QString::number(StoreID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ReturnPurchaseStoreProductID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ReturnPurchaseStoreProduct::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ReturnPurchaseStoreProduct::remove() {
if(ReturnPurchaseStoreProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ReturnPurchaseStoreProduct WHERE ReturnPurchaseStoreProductID ="+QString::number(this->ReturnPurchaseStoreProductID)+""));
return true;
 }
return false;
}

ReturnPurchaseStoreProduct* ReturnPurchaseStoreProduct::get() {
if(ReturnPurchaseStoreProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnPurchaseStoreProduct"
"WHERE ReturnPurchaseStoreProductID ='"+QString::number(this->ReturnPurchaseStoreProductID)+"'"));
while (query.next()) {
return new ReturnPurchaseStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());
 }

}
return new ReturnPurchaseStoreProduct();
 }

QList<ReturnPurchaseStoreProduct*> ReturnPurchaseStoreProduct::GetAll() {
	QList<ReturnPurchaseStoreProduct*> returnpurchasestoreproducts =   QList<ReturnPurchaseStoreProduct*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseStoreProduct ORDER BY ReturnPurchaseStoreProductID ASC"));
	while (query.next()) {
returnpurchasestoreproducts.append(new ReturnPurchaseStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
	}
	return returnpurchasestoreproducts;
}

ReturnPurchaseStoreProduct* ReturnPurchaseStoreProduct::Get(int id) {
ReturnPurchaseStoreProduct* returnpurchasestoreproduct = new ReturnPurchaseStoreProduct();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnPurchaseStoreProduct WHERE ReturnPurchaseStoreProductID = '"+QString::number(id)+"' ORDER BY ReturnPurchaseStoreProductID ASC "));
while (query.next()) {
returnpurchasestoreproduct = new ReturnPurchaseStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());
 }

}
return returnpurchasestoreproduct;
}

ReturnPurchaseStoreProduct* ReturnPurchaseStoreProduct::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ReturnPurchaseStoreProduct();
}

ReturnPurchaseStoreProduct* ReturnPurchaseStoreProduct::Get(QString name) {
ReturnPurchaseStoreProduct* returnpurchasestoreproduct = new ReturnPurchaseStoreProduct();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseStoreProduct WHERE StoreID = QString::number("+name+")"));
while (query.next()) {
returnpurchasestoreproduct = new ReturnPurchaseStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());

 }

}
return returnpurchasestoreproduct;
 }

QList<ReturnPurchaseStoreProduct*> ReturnPurchaseStoreProduct::Search(QString keyword) {
QList<ReturnPurchaseStoreProduct*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseStoreProduct"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ReturnPurchaseStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
 }

}
return list;
 }

QList<QString> ReturnPurchaseStoreProduct::GetStringList() {
	QList<QString> list;
	QList<ReturnPurchaseStoreProduct*> returnpurchasestoreproducts =   QList<ReturnPurchaseStoreProduct*>();
returnpurchasestoreproducts = GetAll();
	for(int i = 0; i <returnpurchasestoreproducts.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ReturnPurchaseStoreProduct::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ReturnPurchaseStoreProduct*> returnpurchasestoreproducts =   QList<ReturnPurchaseStoreProduct*>();
returnpurchasestoreproducts = GetAll();
	for(int i = 0; i <returnpurchasestoreproducts.count(); i++){
		list.append(qMakePair(returnpurchasestoreproducts[i]->ReturnPurchaseStoreProductID,QString::number(returnpurchasestoreproducts[i]->StoreID)));
	}
	return list;
}

QList<QPair< int,QString > > ReturnPurchaseStoreProduct::GetPairList(QList<ReturnPurchaseStoreProduct*> returnpurchasestoreproducts) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <returnpurchasestoreproducts.count(); i++){
		list.append(qMakePair(returnpurchasestoreproducts[i]->ReturnPurchaseStoreProductID,QString::number(returnpurchasestoreproducts[i]->StoreID)));
	}
	return list;
}

int ReturnPurchaseStoreProduct::GetIndex(QString name) {
	QList<ReturnPurchaseStoreProduct*> returnpurchasestoreproducts =   QList<ReturnPurchaseStoreProduct*>();
returnpurchasestoreproducts = GetAll();
	for(int i = 0; i <returnpurchasestoreproducts.count(); i++){
		if(returnpurchasestoreproducts[i]->StoreID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ReturnPurchaseStoreProduct*> ReturnPurchaseStoreProduct::QuerySelect(QString select) {
QList<ReturnPurchaseStoreProduct*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseStoreProduct WHERE "+select+"" ));
while (query.next()) {
list.append(new ReturnPurchaseStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
 }

}
return list;
 }

Qt::ItemFlags ReturnPurchaseStoreProduct::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ReturnPurchaseStoreProduct::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setStoreID(id, value.toString());
else if (index.column() == 2)
ok = setReturnPurchaseID(id, value.toString());
else if (index.column() == 3)
ok = setContactID(id, value.toString());
else if (index.column() == 4)
ok = setProductID(id, value.toString());
else if (index.column() == 5)
ok = setAmount(id, value.toString());
else if (index.column() == 6)
ok = setPrice(id, value.toString());
else if (index.column() == 7)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 8)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ReturnPurchaseStoreProduct::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ReturnPurchaseStoreProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ReturnPurchaseStoreProduct::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ReturnPurchaseStoreProduct!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Store"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Return Purchase"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ReturnPurchaseStoreProduct::setStoreID(int ReturnPurchaseStoreProductID, const QString &StoreID) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set StoreID = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(StoreID);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseStoreProduct::setReturnPurchaseID(int ReturnPurchaseStoreProductID, const QString &ReturnPurchaseID) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set ReturnPurchaseID = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(ReturnPurchaseID);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseStoreProduct::setContactID(int ReturnPurchaseStoreProductID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set ContactID = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(ContactID);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseStoreProduct::setProductID(int ReturnPurchaseStoreProductID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set ProductID = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(ProductID);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseStoreProduct::setAmount(int ReturnPurchaseStoreProductID, const QString &Amount) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set Amount = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(Amount);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseStoreProduct::setPrice(int ReturnPurchaseStoreProductID, const QString &Price) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set Price = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(Price);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseStoreProduct::setCreatedOn(int ReturnPurchaseStoreProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set CreatedOn = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseStoreProduct::setEditedOn(int ReturnPurchaseStoreProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ReturnPurchaseStoreProduct set EditedOn = ? where ReturnPurchaseStoreProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ReturnPurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

