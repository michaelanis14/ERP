/**************************************************************************
**   File: purchaseproduct.cpp
**   Created on: Mon Dec 01 14:22:11 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchaseproduct.h"
#include "erpmodel.h"

PurchaseProduct::PurchaseProduct()
 : QSqlRelationalTableModel(){

this->PurchaseProductID = 0 ;
this->Title = "";
this->PurchaseID = 0 ;
this->ContactID = 0 ;
this->ProductID = 0 ;
this->Amount = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("PurchaseProduct");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Purchase", "PurchaseID", "Title"));
this->setRelation(3, QSqlRelation("Contact", "ContactID", "Name"));
this->setRelation(4, QSqlRelation("Product", "ProductID", "Name"));
}
PurchaseProduct::PurchaseProduct(int PurchaseProductID,QString Title,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseProductID = PurchaseProductID ;
this->Title = Title ;
this->PurchaseID = PurchaseID ;
this->ContactID = ContactID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

PurchaseProduct::PurchaseProduct(QString Title,int PurchaseID,int ContactID,int ProductID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseProductID = 0 ;
this->Title = Title ;
this->PurchaseID = PurchaseID ;
this->ContactID = ContactID ;
this->ProductID = ProductID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool PurchaseProduct::Init()
{

QString table = "PurchaseProduct";
QString query =
"(PurchaseProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PurchaseProductID),"
"Title VARCHAR(40) NOT NULL, "
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
PurchaseProduct* PurchaseProduct::p_instance = 0;
PurchaseProduct* PurchaseProduct::GetInstance() {
	if (p_instance == 0) {
		p_instance = new PurchaseProduct();
		PurchaseProduct::GetAll();
	}
return p_instance;
}
bool PurchaseProduct::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(PurchaseProductID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO PurchaseProduct (Title,PurchaseID,ContactID,ProductID,Amount,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->PurchaseID)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->ProductID)+"','"+QString::number(this->Amount)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE PurchaseProduct SET "	"Title = '"+QString(this->Title)+"',"+"PurchaseID = '"+QString::number(this->PurchaseID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseProductID ='"+QString::number(this->PurchaseProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseProductID FROM PurchaseProduct WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PurchaseProductID = query.value(0).toInt();	
 } 
 }
return true;
}

bool PurchaseProduct::remove() {
if(PurchaseProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM PurchaseProduct WHERE PurchaseProductID ="+QString::number(this->PurchaseProductID)+""));
return true;
 }
return false;
}

PurchaseProduct* PurchaseProduct::get() {
if(PurchaseProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseProduct"
"WHERE PurchaseProductID ='"+QString::number(this->PurchaseProductID)+"'"));
while (query.next()) {
return new PurchaseProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return new PurchaseProduct();
 }

QList<PurchaseProduct*> PurchaseProduct::GetAll() {
	QList<PurchaseProduct*> purchaseproducts =   QList<PurchaseProduct*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseProduct"));
	while (query.next()) {
purchaseproducts.append(new PurchaseProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
	}
qSort(purchaseproducts);
	return purchaseproducts;
}

PurchaseProduct* PurchaseProduct::Get(int id) {
PurchaseProduct* purchaseproduct = new PurchaseProduct();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseProduct WHERE PurchaseProductID = '"+QString::number(id)+"'"));
while (query.next()) {
purchaseproduct = new PurchaseProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return purchaseproduct;
}

PurchaseProduct* PurchaseProduct::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new PurchaseProduct();
}

PurchaseProduct* PurchaseProduct::Get(QString name) {
PurchaseProduct* purchaseproduct = new PurchaseProduct();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseProduct WHERE Title = '"+name+"'"));
while (query.next()) {
purchaseproduct = new PurchaseProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());

 }

}
return purchaseproduct;
 }

QList<PurchaseProduct*> PurchaseProduct::Search(QString keyword) {
QList<PurchaseProduct*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseProduct"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new PurchaseProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

QList<QString> PurchaseProduct::GetStringList() {
	QList<QString> list;
	QList<PurchaseProduct*> purchaseproducts =   QList<PurchaseProduct*>();
purchaseproducts = GetAll();
	for(int i = 0; i <purchaseproducts.count(); i++){
		list.append(purchaseproducts[i]->Title);
	}
	qSort(list);
	return list;
}

QHash<int,QString> PurchaseProduct::GetHashList() {
	QHash<int,QString> list;
	QList<PurchaseProduct*> purchaseproducts =   QList<PurchaseProduct*>();
purchaseproducts = GetAll();
	for(int i = 0; i <purchaseproducts.count(); i++){
		list.insert(purchaseproducts[i]->PurchaseProductID,purchaseproducts[i]->Title);
	}
	return list;
}

int PurchaseProduct::GetIndex(QString name) {
	QList<PurchaseProduct*> purchaseproducts =   QList<PurchaseProduct*>();
purchaseproducts = GetAll();
	for(int i = 0; i <purchaseproducts.count(); i++){
		if(purchaseproducts[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<PurchaseProduct*> PurchaseProduct::QuerySelect(QString select) {
QList<PurchaseProduct*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseProduct WHERE "+select+"" ));
while (query.next()) {
list.append(new PurchaseProduct(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

Qt::ItemFlags PurchaseProduct::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7)
flags |= Qt::ItemIsEditable;
return flags;
}

bool PurchaseProduct::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setTitle(id, value.toString());
else if (index.column() == 2)
ok = setPurchaseID(id, value.toString());
else if (index.column() == 3)
ok = setContactID(id, value.toString());
else if (index.column() == 4)
ok = setProductID(id, value.toString());
else if (index.column() == 5)
ok = setAmount(id, value.toString());
else if (index.column() == 6)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 7)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool PurchaseProduct::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->PurchaseProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void PurchaseProduct::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() PurchaseProduct!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Purchase"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool PurchaseProduct::setTitle(int PurchaseProductID, const QString &Title) {
QSqlQuery query;
query.prepare("update PurchaseProduct set Title = ? where PurchaseProductID = ?");
query.addBindValue(Title);
query.addBindValue(PurchaseProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseProduct::setPurchaseID(int PurchaseProductID, const QString &PurchaseID) {
QSqlQuery query;
query.prepare("update PurchaseProduct set PurchaseID = ? where PurchaseProductID = ?");
query.addBindValue(PurchaseID);
query.addBindValue(PurchaseProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseProduct::setContactID(int PurchaseProductID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update PurchaseProduct set ContactID = ? where PurchaseProductID = ?");
query.addBindValue(ContactID);
query.addBindValue(PurchaseProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseProduct::setProductID(int PurchaseProductID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update PurchaseProduct set ProductID = ? where PurchaseProductID = ?");
query.addBindValue(ProductID);
query.addBindValue(PurchaseProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseProduct::setAmount(int PurchaseProductID, const QString &Amount) {
QSqlQuery query;
query.prepare("update PurchaseProduct set Amount = ? where PurchaseProductID = ?");
query.addBindValue(Amount);
query.addBindValue(PurchaseProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseProduct::setCreatedOn(int PurchaseProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update PurchaseProduct set CreatedOn = ? where PurchaseProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(PurchaseProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseProduct::setEditedOn(int PurchaseProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update PurchaseProduct set EditedOn = ? where PurchaseProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(PurchaseProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

