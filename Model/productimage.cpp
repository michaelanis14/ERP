/**************************************************************************
**   File: productimage.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "productimage.h"
#include "erpmodel.h"

ProductImage::ProductImage()
 : QSqlRelationalTableModel(){

this->ProductImageID = 0 ;
this->Description = "";
this->ProductID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProductImage");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Product", "ProductID", "Name"));
}
ProductImage::ProductImage(int ProductImageID,QString Description,int ProductID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductImageID = ProductImageID ;
this->Description = Description ;
this->ProductID = ProductID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProductImage::ProductImage(QString Description,int ProductID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductImageID = 0 ;
this->Description = Description ;
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
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

ErpModel::GetInstance()->createTable(table,query);
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
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProductImageID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProductImage (Description,ProductID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString::number(this->ProductID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProductImage SET "	"Description = '"+QString(this->Description)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProductImageID ='"+QString::number(this->ProductImageID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProductImageID FROM ProductImage WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProductImageID = query.value(0).toInt();	
 } 
 }
return true;
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
return new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new ProductImage();
 }

QList<ProductImage*> ProductImage::GetAll() {
	QList<ProductImage*> productimages =   QList<ProductImage*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductImage"));
	while (query.next()) {
productimages.append(new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
qStableSort(productimages.begin(),productimages.end());
	return productimages;
}

ProductImage* ProductImage::Get(int id) {
ProductImage* productimage = new ProductImage();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductImage WHERE ProductImageID = '"+QString::number(id)+"'"));
while (query.next()) {
productimage = new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductImage WHERE Description = '"+name+"'"));
while (query.next()) {
productimage = new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return productimage;
 }

QList<ProductImage*> ProductImage::Search(QString keyword) {
QList<ProductImage*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductImage"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> ProductImage::GetStringList() {
	QList<QString> list;
	QList<ProductImage*> productimages =   QList<ProductImage*>();
productimages = GetAll();
	for(int i = 0; i <productimages.count(); i++){
		list.append(productimages[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> ProductImage::GetHashList() {
	QHash<int,QString> list;
	QList<ProductImage*> productimages =   QList<ProductImage*>();
productimages = GetAll();
	for(int i = 0; i <productimages.count(); i++){
		list.insert(productimages[i]->ProductImageID,productimages[i]->Description);
	}
	return list;
}

int ProductImage::GetIndex(QString name) {
	QList<ProductImage*> productimages =   QList<ProductImage*>();
productimages = GetAll();
	for(int i = 0; i <productimages.count(); i++){
		if(productimages[i]->Description == name){
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
list.append(new ProductImage(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProductImage::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
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
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setProductID(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
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
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProductImage::setDescription(int ProductImageID, const QString &Description) {
QSqlQuery query;
query.prepare("update ProductImage set Description = ? where ProductImageID = ?");
query.addBindValue(Description);
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

