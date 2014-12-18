/**************************************************************************
**   File: productcategory.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "productcategory.h"
#include "erpmodel.h"

ProductCategory::ProductCategory()
 : QSqlRelationalTableModel(){

this->ProductCategoryID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProductCategory");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ProductCategory::ProductCategory(int ProductCategoryID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductCategoryID = ProductCategoryID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProductCategory::ProductCategory(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductCategoryID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProductCategory::Init()
{

QString table = "ProductCategory";
QString query =
"(ProductCategoryID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProductCategoryID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProductCategoryID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProductCategory* ProductCategory::p_instance = 0;
ProductCategory* ProductCategory::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProductCategory();
		ProductCategory::GetAll();
	}
return p_instance;
}
bool ProductCategory::save() {
this->EditedOn = QDate::currentDate().toString();
if(ProductCategoryID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProductCategory (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProductCategory SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProductCategoryID ='"+QString::number(this->ProductCategoryID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProductCategoryID FROM ProductCategory WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProductCategoryID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProductCategory::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProductCategory::remove() {
if(ProductCategoryID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProductCategory WHERE ProductCategoryID ="+QString::number(this->ProductCategoryID)+""));
return true;
 }
return false;
}

ProductCategory* ProductCategory::get() {
if(ProductCategoryID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductCategory"
"WHERE ProductCategoryID ='"+QString::number(this->ProductCategoryID)+"'"));
while (query.next()) {
return new ProductCategory(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new ProductCategory();
 }

QList<ProductCategory*> ProductCategory::GetAll() {
	QList<ProductCategory*> productcategorys =   QList<ProductCategory*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductCategory ORDER BY ProductCategoryID ASC"));
	while (query.next()) {
productcategorys.append(new ProductCategory(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return productcategorys;
}

ProductCategory* ProductCategory::Get(int id) {
ProductCategory* productcategory = new ProductCategory();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductCategory WHERE ProductCategoryID = '"+QString::number(id)+"' ORDER BY ProductCategoryID ASC "));
while (query.next()) {
productcategory = new ProductCategory(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return productcategory;
}

ProductCategory* ProductCategory::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProductCategory();
}

ProductCategory* ProductCategory::Get(QString name) {
ProductCategory* productcategory = new ProductCategory();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductCategory WHERE Description = '"+name+"'"));
while (query.next()) {
productcategory = new ProductCategory(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return productcategory;
 }

QList<ProductCategory*> ProductCategory::Search(QString keyword) {
QList<ProductCategory*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductCategory"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProductCategory(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> ProductCategory::GetStringList() {
	QList<QString> list;
	QList<ProductCategory*> productcategorys =   QList<ProductCategory*>();
productcategorys = GetAll();
	for(int i = 0; i <productcategorys.count(); i++){
		list.append(productcategorys[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > ProductCategory::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProductCategory*> productcategorys =   QList<ProductCategory*>();
productcategorys = GetAll();
	for(int i = 0; i <productcategorys.count(); i++){
		list.append(qMakePair(productcategorys[i]->ProductCategoryID,productcategorys[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > ProductCategory::GetPairList(QList<ProductCategory*> productcategorys) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <productcategorys.count(); i++){
		list.append(qMakePair(productcategorys[i]->ProductCategoryID,productcategorys[i]->Description));
	}
	return list;
}

int ProductCategory::GetIndex(QString name) {
	QList<ProductCategory*> productcategorys =   QList<ProductCategory*>();
productcategorys = GetAll();
	for(int i = 0; i <productcategorys.count(); i++){
		if(productcategorys[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ProductCategory*> ProductCategory::QuerySelect(QString select) {
QList<ProductCategory*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductCategory WHERE "+select+"" ));
while (query.next()) {
list.append(new ProductCategory(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProductCategory::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProductCategory::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProductCategory::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProductCategoryID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProductCategory::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProductCategory!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProductCategory::setDescription(int ProductCategoryID, const QString &Description) {
QSqlQuery query;
query.prepare("update ProductCategory set Description = ? where ProductCategoryID = ?");
query.addBindValue(Description);
query.addBindValue(ProductCategoryID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductCategory::setCreatedOn(int ProductCategoryID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProductCategory set CreatedOn = ? where ProductCategoryID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProductCategoryID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductCategory::setEditedOn(int ProductCategoryID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProductCategory set EditedOn = ? where ProductCategoryID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProductCategoryID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

