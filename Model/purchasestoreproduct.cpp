/**************************************************************************
**   File: purchasestoreproduct.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchasestoreproduct.h"
#include "erpmodel.h"

PurchaseStoreProduct::PurchaseStoreProduct()
 : QSqlRelationalTableModel(){

this->PurchaseStoreProductID = 0 ;
this->Title = "";
this->StoreID = 0 ;
this->PurchaseID = 0 ;
this->ContactID = 0 ;
this->ProductID = 0 ;
this->Amount = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("PurchaseStoreProduct");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Store", "StoreID", "Name"));
this->setRelation(3, QSqlRelation("Purchase", "PurchaseID", "Title"));
this->setRelation(4, QSqlRelation("Contact", "ContactID", "Name"));
this->setRelation(5, QSqlRelation("Product", "ProductID", "Name"));
}
PurchaseStoreProduct::PurchaseStoreProduct(int PurchaseStoreProductID,QString Title,int StoreID,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseStoreProductID = PurchaseStoreProductID ;
this->Title = Title ;
this->StoreID = StoreID ;
this->PurchaseID = PurchaseID ;
this->ContactID = ContactID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

PurchaseStoreProduct::PurchaseStoreProduct(QString Title,int StoreID,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseStoreProductID = 0 ;
this->Title = Title ;
this->StoreID = StoreID ;
this->PurchaseID = PurchaseID ;
this->ContactID = ContactID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool PurchaseStoreProduct::Init()
{

QString table = "PurchaseStoreProduct";
QString query =
"(PurchaseStoreProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PurchaseStoreProductID),"
"Title VARCHAR(40) NOT NULL, "
"StoreID INT NOT NULL, "
"FOREIGN KEY (StoreID) REFERENCES Store(StoreID)  ON DELETE CASCADE,"
"PurchaseID INT NOT NULL, "
"FOREIGN KEY (PurchaseID) REFERENCES Purchase(PurchaseID)  ON DELETE CASCADE,"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
PurchaseStoreProduct* PurchaseStoreProduct::p_instance = 0;
PurchaseStoreProduct* PurchaseStoreProduct::GetInstance() {
	if (p_instance == 0) {
		p_instance = new PurchaseStoreProduct();
		PurchaseStoreProduct::GetAll();
	}
return p_instance;
}
bool PurchaseStoreProduct::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(PurchaseStoreProductID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO PurchaseStoreProduct (Title,StoreID,PurchaseID,ContactID,ProductID,Amount,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->StoreID)+"','"+QString::number(this->PurchaseID)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->ProductID)+"','"+QString::number(this->Amount)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE PurchaseStoreProduct SET "	"Title = '"+QString(this->Title)+"',"+"StoreID = '"+QString::number(this->StoreID)+"',"+"PurchaseID = '"+QString::number(this->PurchaseID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseStoreProductID ='"+QString::number(this->PurchaseStoreProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseStoreProductID FROM PurchaseStoreProduct WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PurchaseStoreProductID = query.value(0).toInt();	
 } 
 }
return true;
}

bool PurchaseStoreProduct::remove() {
if(PurchaseStoreProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM PurchaseStoreProduct WHERE PurchaseStoreProductID ="+QString::number(this->PurchaseStoreProductID)+""));
return true;
 }
return false;
}

PurchaseStoreProduct* PurchaseStoreProduct::get() {
if(PurchaseStoreProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseStoreProduct"
"WHERE PurchaseStoreProductID ='"+QString::number(this->PurchaseStoreProductID)+"'"));
while (query.next()) {
return new PurchaseStoreProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());
 }

}
return new PurchaseStoreProduct();
 }

QList<PurchaseStoreProduct*> PurchaseStoreProduct::GetAll() {
	QList<PurchaseStoreProduct*> purchasestoreproducts =   QList<PurchaseStoreProduct*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStoreProduct"));
	while (query.next()) {
purchasestoreproducts.append(new PurchaseStoreProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
	}
qStableSort(purchasestoreproducts.begin(),purchasestoreproducts.end());
	return purchasestoreproducts;
}

PurchaseStoreProduct* PurchaseStoreProduct::Get(int id) {
PurchaseStoreProduct* purchasestoreproduct = new PurchaseStoreProduct();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseStoreProduct WHERE PurchaseStoreProductID = '"+QString::number(id)+"'"));
while (query.next()) {
purchasestoreproduct = new PurchaseStoreProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());
 }

}
return purchasestoreproduct;
}

PurchaseStoreProduct* PurchaseStoreProduct::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new PurchaseStoreProduct();
}

PurchaseStoreProduct* PurchaseStoreProduct::Get(QString name) {
PurchaseStoreProduct* purchasestoreproduct = new PurchaseStoreProduct();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStoreProduct WHERE Title = '"+name+"'"));
while (query.next()) {
purchasestoreproduct = new PurchaseStoreProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());

 }

}
return purchasestoreproduct;
 }

QList<PurchaseStoreProduct*> PurchaseStoreProduct::Search(QString keyword) {
QList<PurchaseStoreProduct*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStoreProduct"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new PurchaseStoreProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
 }

}
return list;
 }

QList<QString> PurchaseStoreProduct::GetStringList() {
	QList<QString> list;
	QList<PurchaseStoreProduct*> purchasestoreproducts =   QList<PurchaseStoreProduct*>();
purchasestoreproducts = GetAll();
	for(int i = 0; i <purchasestoreproducts.count(); i++){
		list.append(purchasestoreproducts[i]->Title);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> PurchaseStoreProduct::GetHashList() {
	QHash<int,QString> list;
	QList<PurchaseStoreProduct*> purchasestoreproducts =   QList<PurchaseStoreProduct*>();
purchasestoreproducts = GetAll();
	for(int i = 0; i <purchasestoreproducts.count(); i++){
		list.insert(purchasestoreproducts[i]->PurchaseStoreProductID,purchasestoreproducts[i]->Title);
	}
	return list;
}

int PurchaseStoreProduct::GetIndex(QString name) {
	QList<PurchaseStoreProduct*> purchasestoreproducts =   QList<PurchaseStoreProduct*>();
purchasestoreproducts = GetAll();
	for(int i = 0; i <purchasestoreproducts.count(); i++){
		if(purchasestoreproducts[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<PurchaseStoreProduct*> PurchaseStoreProduct::QuerySelect(QString select) {
QList<PurchaseStoreProduct*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStoreProduct WHERE "+select+"" ));
while (query.next()) {
list.append(new PurchaseStoreProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
 }

}
return list;
 }

Qt::ItemFlags PurchaseStoreProduct::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8)
flags |= Qt::ItemIsEditable;
return flags;
}

bool PurchaseStoreProduct::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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
ok = setPurchaseID(id, value.toString());
else if (index.column() == 4)
ok = setContactID(id, value.toString());
else if (index.column() == 5)
ok = setProductID(id, value.toString());
else if (index.column() == 6)
ok = setAmount(id, value.toString());
else if (index.column() == 7)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 8)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool PurchaseStoreProduct::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->PurchaseStoreProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void PurchaseStoreProduct::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() PurchaseStoreProduct!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Store"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Purchase"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool PurchaseStoreProduct::setTitle(int PurchaseStoreProductID, const QString &Title) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set Title = ? where PurchaseStoreProductID = ?");
query.addBindValue(Title);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStoreProduct::setStoreID(int PurchaseStoreProductID, const QString &StoreID) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set StoreID = ? where PurchaseStoreProductID = ?");
query.addBindValue(StoreID);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStoreProduct::setPurchaseID(int PurchaseStoreProductID, const QString &PurchaseID) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set PurchaseID = ? where PurchaseStoreProductID = ?");
query.addBindValue(PurchaseID);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStoreProduct::setContactID(int PurchaseStoreProductID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set ContactID = ? where PurchaseStoreProductID = ?");
query.addBindValue(ContactID);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStoreProduct::setProductID(int PurchaseStoreProductID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set ProductID = ? where PurchaseStoreProductID = ?");
query.addBindValue(ProductID);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStoreProduct::setAmount(int PurchaseStoreProductID, const QString &Amount) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set Amount = ? where PurchaseStoreProductID = ?");
query.addBindValue(Amount);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStoreProduct::setCreatedOn(int PurchaseStoreProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set CreatedOn = ? where PurchaseStoreProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStoreProduct::setEditedOn(int PurchaseStoreProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update PurchaseStoreProduct set EditedOn = ? where PurchaseStoreProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(PurchaseStoreProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

