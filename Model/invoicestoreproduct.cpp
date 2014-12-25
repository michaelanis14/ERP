/**************************************************************************
**   File: invoicestoreproduct.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoicestoreproduct.h"
#include "erpmodel.h"

InvoiceStoreProduct::InvoiceStoreProduct()
 : QSqlRelationalTableModel(){

this->InvoiceStoreProductID = 0 ;
this->InvoiceID = 0 ;
this->StoreID = 0 ;
this->ProductID = 0 ;
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceStoreProduct");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Store", "StoreID", "Name"));
this->setRelation(3, QSqlRelation("Product", "ProductID", "Name"));
}
InvoiceStoreProduct::InvoiceStoreProduct(int InvoiceStoreProductID,int InvoiceID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceStoreProductID = InvoiceStoreProductID ;
this->InvoiceID = InvoiceID ;
this->StoreID = StoreID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceStoreProduct::InvoiceStoreProduct(int InvoiceID,int StoreID,int ProductID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceStoreProductID = 0 ;
this->InvoiceID = InvoiceID ;
this->StoreID = StoreID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceStoreProduct::Init()
{

QString table = "InvoiceStoreProduct";
QString query =
"(InvoiceStoreProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceStoreProductID),"
"InvoiceID INT NOT NULL, "
" KEY(InvoiceID),"
"FOREIGN KEY (InvoiceID) REFERENCES Invoice(InvoiceID)  ON DELETE CASCADE,"
"StoreID INT NOT NULL, "
"FOREIGN KEY (StoreID) REFERENCES Store(StoreID)  ON DELETE CASCADE,"
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceStoreProductID")));variables.append(qMakePair(QString(" INT"),QString("InvoiceID")));variables.append(qMakePair(QString(" INT"),QString("StoreID")));variables.append(qMakePair(QString(" INT"),QString("ProductID")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
InvoiceStoreProduct* InvoiceStoreProduct::p_instance = 0;
InvoiceStoreProduct* InvoiceStoreProduct::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceStoreProduct();
		InvoiceStoreProduct::GetAll();
	}
return p_instance;
}
bool InvoiceStoreProduct::save() {
this->EditedOn = QDate::currentDate().toString();
if(InvoiceStoreProductID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceStoreProduct (InvoiceID,StoreID,ProductID,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->InvoiceID)+"','"+QString::number(this->StoreID)+"','"+QString::number(this->ProductID)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceStoreProduct SET "	"InvoiceID = '"+QString::number(this->InvoiceID)+"',"+"StoreID = '"+QString::number(this->StoreID)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceStoreProductID ='"+QString::number(this->InvoiceStoreProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceStoreProductID FROM InvoiceStoreProduct WHERE InvoiceID = "+QString::number(InvoiceID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceStoreProductID = query.value(0).toInt();	
 } 
 }
return true;
}
bool InvoiceStoreProduct::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool InvoiceStoreProduct::remove() {
if(InvoiceStoreProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceStoreProduct WHERE InvoiceStoreProductID ="+QString::number(this->InvoiceStoreProductID)+""));
return true;
 }
return false;
}

InvoiceStoreProduct* InvoiceStoreProduct::get() {
if(InvoiceStoreProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceStoreProduct"
"WHERE InvoiceStoreProductID ='"+QString::number(this->InvoiceStoreProductID)+"'"));
while (query.next()) {
return new InvoiceStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return new InvoiceStoreProduct();
 }

QList<InvoiceStoreProduct*> InvoiceStoreProduct::GetAll() {
	QList<InvoiceStoreProduct*> invoicestoreproducts =   QList<InvoiceStoreProduct*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStoreProduct ORDER BY InvoiceStoreProductID ASC"));
	while (query.next()) {
invoicestoreproducts.append(new InvoiceStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
	}
	return invoicestoreproducts;
}

InvoiceStoreProduct* InvoiceStoreProduct::Get(int id) {
InvoiceStoreProduct* invoicestoreproduct = new InvoiceStoreProduct();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceStoreProduct WHERE InvoiceStoreProductID = '"+QString::number(id)+"' ORDER BY InvoiceStoreProductID ASC "));
while (query.next()) {
invoicestoreproduct = new InvoiceStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return invoicestoreproduct;
}

InvoiceStoreProduct* InvoiceStoreProduct::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceStoreProduct();
}

InvoiceStoreProduct* InvoiceStoreProduct::Get(QString name) {
InvoiceStoreProduct* invoicestoreproduct = new InvoiceStoreProduct();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStoreProduct WHERE InvoiceID = QString::number("+name+")"));
while (query.next()) {
invoicestoreproduct = new InvoiceStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());

 }

}
return invoicestoreproduct;
 }

QList<InvoiceStoreProduct*> InvoiceStoreProduct::Search(QString keyword) {
QList<InvoiceStoreProduct*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStoreProduct"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

QList<QString> InvoiceStoreProduct::GetStringList() {
	QList<QString> list;
	QList<InvoiceStoreProduct*> invoicestoreproducts =   QList<InvoiceStoreProduct*>();
invoicestoreproducts = GetAll();
	for(int i = 0; i <invoicestoreproducts.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > InvoiceStoreProduct::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<InvoiceStoreProduct*> invoicestoreproducts =   QList<InvoiceStoreProduct*>();
invoicestoreproducts = GetAll();
	for(int i = 0; i <invoicestoreproducts.count(); i++){
		list.append(qMakePair(invoicestoreproducts[i]->InvoiceStoreProductID,QString::number(invoicestoreproducts[i]->InvoiceID)));
	}
	return list;
}

QList<QPair< int,QString > > InvoiceStoreProduct::GetPairList(QList<InvoiceStoreProduct*> invoicestoreproducts) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoicestoreproducts.count(); i++){
		list.append(qMakePair(invoicestoreproducts[i]->InvoiceStoreProductID,QString::number(invoicestoreproducts[i]->InvoiceID)));
	}
	return list;
}

int InvoiceStoreProduct::GetIndex(QString name) {
	QList<InvoiceStoreProduct*> invoicestoreproducts =   QList<InvoiceStoreProduct*>();
invoicestoreproducts = GetAll();
	for(int i = 0; i <invoicestoreproducts.count(); i++){
		if(invoicestoreproducts[i]->InvoiceID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<InvoiceStoreProduct*> InvoiceStoreProduct::QuerySelect(QString select) {
QList<InvoiceStoreProduct*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStoreProduct WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceStoreProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceStoreProduct::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceStoreProduct::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setInvoiceID(id, value.toString());
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

bool InvoiceStoreProduct::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceStoreProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceStoreProduct::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceStoreProduct!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Invoice"));
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
bool InvoiceStoreProduct::setInvoiceID(int InvoiceStoreProductID, const QString &InvoiceID) {
QSqlQuery query;
query.prepare("update InvoiceStoreProduct set InvoiceID = ? where InvoiceStoreProductID = ?");
query.addBindValue(InvoiceID);
query.addBindValue(InvoiceStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStoreProduct::setStoreID(int InvoiceStoreProductID, const QString &StoreID) {
QSqlQuery query;
query.prepare("update InvoiceStoreProduct set StoreID = ? where InvoiceStoreProductID = ?");
query.addBindValue(StoreID);
query.addBindValue(InvoiceStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStoreProduct::setProductID(int InvoiceStoreProductID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update InvoiceStoreProduct set ProductID = ? where InvoiceStoreProductID = ?");
query.addBindValue(ProductID);
query.addBindValue(InvoiceStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStoreProduct::setAmount(int InvoiceStoreProductID, const QString &Amount) {
QSqlQuery query;
query.prepare("update InvoiceStoreProduct set Amount = ? where InvoiceStoreProductID = ?");
query.addBindValue(Amount);
query.addBindValue(InvoiceStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStoreProduct::setPrice(int InvoiceStoreProductID, const QString &Price) {
QSqlQuery query;
query.prepare("update InvoiceStoreProduct set Price = ? where InvoiceStoreProductID = ?");
query.addBindValue(Price);
query.addBindValue(InvoiceStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStoreProduct::setCreatedOn(int InvoiceStoreProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceStoreProduct set CreatedOn = ? where InvoiceStoreProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStoreProduct::setEditedOn(int InvoiceStoreProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceStoreProduct set EditedOn = ? where InvoiceStoreProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

