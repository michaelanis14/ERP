/**************************************************************************
**   File: productfielddata.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "productfielddata.h"
#include "erpmodel.h"

ProductFieldData::ProductFieldData()
 : QSqlRelationalTableModel(){

this->ProductFieldDataID = 0 ;
this->ProductID = 0 ;
this->ProductFieldID = 0 ;
this->Value = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProductFieldData");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Product", "ProductID", "Name"));
this->setRelation(2, QSqlRelation("ProductField", "ProductFieldID", "Description"));
}
ProductFieldData::ProductFieldData(int ProductFieldDataID,int ProductID,int ProductFieldID,QString Value,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductFieldDataID = ProductFieldDataID ;
this->ProductID = ProductID ;
this->ProductFieldID = ProductFieldID ;
this->Value = Value ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProductFieldData::ProductFieldData(int ProductID,int ProductFieldID,QString Value,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductFieldDataID = 0 ;
this->ProductID = ProductID ;
this->ProductFieldID = ProductFieldID ;
this->Value = Value ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProductFieldData::Init()
{

QString table = "ProductFieldData";
QString query =
"(ProductFieldDataID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProductFieldDataID),"
"ProductID INT NOT NULL, "
" KEY(ProductID),"
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"ProductFieldID INT NOT NULL, "
"FOREIGN KEY (ProductFieldID) REFERENCES ProductField(ProductFieldID)  ON DELETE CASCADE,"
"Value VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProductFieldDataID")));variables.append(qMakePair(QString(" INT"),QString("ProductID")));variables.append(qMakePair(QString(" INT"),QString("ProductFieldID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Value")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProductFieldData* ProductFieldData::p_instance = 0;
ProductFieldData* ProductFieldData::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProductFieldData();
		ProductFieldData::GetAll();
	}
return p_instance;
}
bool ProductFieldData::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProductFieldDataID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProductFieldData (ProductID,ProductFieldID,Value,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ProductID)+"','"+QString::number(this->ProductFieldID)+"','"+QString(this->Value)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProductFieldData SET "	"ProductID = '"+QString::number(this->ProductID)+"',"+"ProductFieldID = '"+QString::number(this->ProductFieldID)+"',"+"Value = '"+QString(this->Value)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProductFieldDataID ='"+QString::number(this->ProductFieldDataID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProductFieldDataID FROM ProductFieldData WHERE ProductID = "+QString::number(ProductID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProductFieldDataID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProductFieldData::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProductFieldData::remove() {
if(ProductFieldDataID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProductFieldData WHERE ProductFieldDataID ="+QString::number(this->ProductFieldDataID)+""));
return true;
 }
return false;
}

ProductFieldData* ProductFieldData::get() {
if(ProductFieldDataID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductFieldData"
"WHERE ProductFieldDataID ='"+QString::number(this->ProductFieldDataID)+"'"));
while (query.next()) {
return new ProductFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ProductFieldData();
 }

QList<ProductFieldData*> ProductFieldData::GetAll() {
	QList<ProductFieldData*> productfielddatas =   QList<ProductFieldData*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductFieldData ORDER BY ProductFieldDataID ASC"));
	while (query.next()) {
productfielddatas.append(new ProductFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
	}
	return productfielddatas;
}

ProductFieldData* ProductFieldData::Get(int id) {
ProductFieldData* productfielddata = new ProductFieldData();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductFieldData WHERE ProductFieldDataID = '"+QString::number(id)+"' ORDER BY ProductFieldDataID ASC "));
while (query.next()) {
productfielddata = new ProductFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
 }

}
return productfielddata;
}

ProductFieldData* ProductFieldData::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProductFieldData();
}

ProductFieldData* ProductFieldData::Get(QString name) {
ProductFieldData* productfielddata = new ProductFieldData();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductFieldData WHERE ProductID = QString::number("+name+")"));
while (query.next()) {
productfielddata = new ProductFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());

 }

}
return productfielddata;
 }

QList<ProductFieldData*> ProductFieldData::Search(QString keyword) {
QList<ProductFieldData*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductFieldData"
"WHERE" 
"Value LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProductFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ProductFieldData::GetStringList() {
	QList<QString> list;
	QList<ProductFieldData*> productfielddatas =   QList<ProductFieldData*>();
productfielddatas = GetAll();
	for(int i = 0; i <productfielddatas.count(); i++){
		list.append(productfielddatas[i]->Value);
	}
	return list;
}

QList<QPair< int,QString > > ProductFieldData::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProductFieldData*> productfielddatas =   QList<ProductFieldData*>();
productfielddatas = GetAll();
	for(int i = 0; i <productfielddatas.count(); i++){
		list.append(qMakePair(productfielddatas[i]->ProductFieldDataID,QString::number(productfielddatas[i]->ProductID)));
	}
	return list;
}

QList<QPair< int,QString > > ProductFieldData::GetPairList(QList<ProductFieldData*> productfielddatas) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <productfielddatas.count(); i++){
		list.append(qMakePair(productfielddatas[i]->ProductFieldDataID,QString::number(productfielddatas[i]->ProductID)));
	}
	return list;
}

int ProductFieldData::GetIndex(QString name) {
	QList<ProductFieldData*> productfielddatas =   QList<ProductFieldData*>();
productfielddatas = GetAll();
	for(int i = 0; i <productfielddatas.count(); i++){
		if(productfielddatas[i]->ProductID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ProductFieldData*> ProductFieldData::QuerySelect(QString select) {
QList<ProductFieldData*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductFieldData WHERE "+select+"" ));
while (query.next()) {
list.append(new ProductFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProductFieldData::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProductFieldData::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setProductID(id, value.toString());
else if (index.column() == 2)
ok = setProductFieldID(id, value.toString());
else if (index.column() == 3)
ok = setValue(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProductFieldData::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProductFieldDataID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProductFieldData::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProductFieldData!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Product Field"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Value"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProductFieldData::setProductID(int ProductFieldDataID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update ProductFieldData set ProductID = ? where ProductFieldDataID = ?");
query.addBindValue(ProductID);
query.addBindValue(ProductFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductFieldData::setProductFieldID(int ProductFieldDataID, const QString &ProductFieldID) {
QSqlQuery query;
query.prepare("update ProductFieldData set ProductFieldID = ? where ProductFieldDataID = ?");
query.addBindValue(ProductFieldID);
query.addBindValue(ProductFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductFieldData::setValue(int ProductFieldDataID, const QString &Value) {
QSqlQuery query;
query.prepare("update ProductFieldData set Value = ? where ProductFieldDataID = ?");
query.addBindValue(Value);
query.addBindValue(ProductFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductFieldData::setCreatedOn(int ProductFieldDataID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProductFieldData set CreatedOn = ? where ProductFieldDataID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProductFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductFieldData::setEditedOn(int ProductFieldDataID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProductFieldData set EditedOn = ? where ProductFieldDataID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProductFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

