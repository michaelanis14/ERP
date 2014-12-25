/**************************************************************************
**   File: productimage.cpp
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "productimage.h"
#include "erpmodel.h"

ProductImage::ProductImage()
 : QSqlRelationalTableModel(){

this->ProductImageID = 0 ;
this->Name = "";
this->imageData = 0 ;
this->ProductID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProductImage");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("Product", "ProductID", "Name"));
}
ProductImage::ProductImage(int ProductImageID,QString Name,QVariant imageData,int ProductID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductImageID = ProductImageID ;
this->Name = Name ;
this->imageData = imageData ;
this->ProductID = ProductID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProductImage::ProductImage(QString Name,QVariant imageData,int ProductID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductImageID = 0 ;
this->Name = Name ;
this->imageData = imageData ;
this->ProductID = ProductID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProductImage::Init()
{

QString table = "ProductImage";
QString query =
"(ProductImageID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProductImageID),"
"Name VARCHAR(40) NOT NULL, "
" KEY(Name),"
"imageData LONGBLOB NOT NULL, "
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProductImageID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" LONGBLOB"),QString("imageData")));variables.append(qMakePair(QString(" INT"),QString("ProductID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProductImage* ProductImage::p_instance = 0;
ProductImage* ProductImage::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProductImage();
		ProductImage::GetAll();
	}
return p_instance;
}
bool ProductImage::save() {
this->EditedOn = QDate::currentDate().toString();
if(ProductImageID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProductImage (Name,imageData,ProductID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+(this->imageData.toString())+"','"+QString::number(this->ProductID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProductImage SET "	"Name = '"+QString(this->Name)+"',"+"imageData = '"+(this->imageData.toString())+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProductImageID ='"+QString::number(this->ProductImageID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProductImageID FROM ProductImage WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProductImageID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProductImage::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProductImage::remove() {
if(ProductImageID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProductImage WHERE ProductImageID ="+QString::number(this->ProductImageID)+""));
return true;
 }
return false;
}

ProductImage* ProductImage::get() {
if(ProductImageID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductImage"
"WHERE ProductImageID ='"+QString::number(this->ProductImageID)+"'"));
while (query.next()) {
return new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ProductImage();
 }

QList<ProductImage*> ProductImage::GetAll() {
	QList<ProductImage*> productimages =   QList<ProductImage*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductImage ORDER BY ProductImageID ASC"));
	while (query.next()) {
productimages.append(new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
	return productimages;
}

ProductImage* ProductImage::Get(int id) {
ProductImage* productimage = new ProductImage();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductImage WHERE ProductImageID = '"+QString::number(id)+"' ORDER BY ProductImageID ASC "));
while (query.next()) {
productimage = new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return productimage;
}

ProductImage* ProductImage::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProductImage();
}

ProductImage* ProductImage::Get(QString name) {
ProductImage* productimage = new ProductImage();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductImage WHERE Name = '"+name+"'"));
while (query.next()) {
productimage = new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return productimage;
 }

QList<ProductImage*> ProductImage::Search(QString keyword) {
QList<ProductImage*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductImage"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ProductImage::GetStringList() {
	QList<QString> list;
	QList<ProductImage*> productimages =   QList<ProductImage*>();
productimages = GetAll();
	for(int i = 0; i <productimages.count(); i++){
		list.append(productimages[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > ProductImage::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProductImage*> productimages =   QList<ProductImage*>();
productimages = GetAll();
	for(int i = 0; i <productimages.count(); i++){
		list.append(qMakePair(productimages[i]->ProductImageID,productimages[i]->Name));
	}
	return list;
}

QList<QPair< int,QString > > ProductImage::GetPairList(QList<ProductImage*> productimages) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <productimages.count(); i++){
		list.append(qMakePair(productimages[i]->ProductImageID,productimages[i]->Name));
	}
	return list;
}

int ProductImage::GetIndex(QString name) {
	QList<ProductImage*> productimages =   QList<ProductImage*>();
productimages = GetAll();
	for(int i = 0; i <productimages.count(); i++){
		if(productimages[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<ProductImage*> ProductImage::QuerySelect(QString select) {
QList<ProductImage*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductImage WHERE "+select+"" ));
while (query.next()) {
list.append(new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProductImage::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProductImage::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setimageData(id, value.toString());
else if (index.column() == 3)
ok = setProductID(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProductImage::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProductImageID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProductImage::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProductImage!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("imageData"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProductImage::setName(int ProductImageID, const QString &Name) {
QSqlQuery query;
query.prepare("update ProductImage set Name = ? where ProductImageID = ?");
query.addBindValue(Name);
query.addBindValue(ProductImageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductImage::setimageData(int ProductImageID, const QString &imageData) {
QSqlQuery query;
query.prepare("update ProductImage set imageData = ? where ProductImageID = ?");
query.addBindValue(imageData);
query.addBindValue(ProductImageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductImage::setProductID(int ProductImageID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update ProductImage set ProductID = ? where ProductImageID = ?");
query.addBindValue(ProductID);
query.addBindValue(ProductImageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductImage::setCreatedOn(int ProductImageID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProductImage set CreatedOn = ? where ProductImageID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProductImageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductImage::setEditedOn(int ProductImageID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProductImage set EditedOn = ? where ProductImageID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProductImageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

