/**************************************************************************
**   File: productfield.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "productfield.h"
#include "erpmodel.h"

ProductField::ProductField()
 : QSqlRelationalTableModel(){

this->ProductFieldID = 0 ;
this->Description = "";
this->FieldTypeID = 0 ;
this->Defaults = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProductField");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("FieldType", "FieldTypeID", "Description"));
}
ProductField::ProductField(int ProductFieldID,QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductFieldID = ProductFieldID ;
this->Description = Description ;
this->FieldTypeID = FieldTypeID ;
this->Defaults = Defaults ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProductField::ProductField(QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductFieldID = 0 ;
this->Description = Description ;
this->FieldTypeID = FieldTypeID ;
this->Defaults = Defaults ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProductField::Init()
{

QString table = "ProductField";
QString query =
"(ProductFieldID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProductFieldID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"FieldTypeID INT NOT NULL, "
"FOREIGN KEY (FieldTypeID) REFERENCES FieldType(FieldTypeID)  ON DELETE CASCADE,"
"Defaults VARCHAR(1) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProductFieldID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" INT"),QString("FieldTypeID")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Defaults")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProductField* ProductField::p_instance = 0;
ProductField* ProductField::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProductField();
		ProductField::GetAll();
	}
return p_instance;
}
bool ProductField::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProductFieldID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProductField (Description,FieldTypeID,Defaults,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString::number(this->FieldTypeID)+"','"+QString::number(this->Defaults)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProductField SET "	"Description = '"+QString(this->Description)+"',"+"FieldTypeID = '"+QString::number(this->FieldTypeID)+"',"+"Defaults = '"+QString::number(this->Defaults)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProductFieldID ='"+QString::number(this->ProductFieldID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProductFieldID FROM ProductField WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProductFieldID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProductField::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProductField::remove() {
if(ProductFieldID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProductField WHERE ProductFieldID ="+QString::number(this->ProductFieldID)+""));
return true;
 }
return false;
}

ProductField* ProductField::get() {
if(ProductFieldID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductField"
"WHERE ProductFieldID ='"+QString::number(this->ProductFieldID)+"'"));
while (query.next()) {
return new ProductField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ProductField();
 }

QList<ProductField*> ProductField::GetAll() {
	QList<ProductField*> productfields =   QList<ProductField*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductField ORDER BY ProductFieldID ASC"));
	while (query.next()) {
productfields.append(new ProductField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
	return productfields;
}

ProductField* ProductField::Get(int id) {
ProductField* productfield = new ProductField();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProductField WHERE ProductFieldID = '"+QString::number(id)+"' ORDER BY ProductFieldID ASC "));
while (query.next()) {
productfield = new ProductField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return productfield;
}

ProductField* ProductField::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProductField();
}

ProductField* ProductField::Get(QString name) {
ProductField* productfield = new ProductField();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductField WHERE Description = '"+name+"'"));
while (query.next()) {
productfield = new ProductField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return productfield;
 }

QList<ProductField*> ProductField::Search(QString keyword) {
QList<ProductField*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductField"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProductField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ProductField::GetStringList() {
	QList<QString> list;
	QList<ProductField*> productfields =   QList<ProductField*>();
productfields = GetAll();
	for(int i = 0; i <productfields.count(); i++){
		list.append(productfields[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > ProductField::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProductField*> productfields =   QList<ProductField*>();
productfields = GetAll();
	for(int i = 0; i <productfields.count(); i++){
		list.append(qMakePair(productfields[i]->ProductFieldID,productfields[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > ProductField::GetPairList(QList<ProductField*> productfields) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <productfields.count(); i++){
		list.append(qMakePair(productfields[i]->ProductFieldID,productfields[i]->Description));
	}
	return list;
}

int ProductField::GetIndex(QString name) {
	QList<ProductField*> productfields =   QList<ProductField*>();
productfields = GetAll();
	for(int i = 0; i <productfields.count(); i++){
		if(productfields[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ProductField*> ProductField::QuerySelect(QString select) {
QList<ProductField*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProductField WHERE "+select+"" ));
while (query.next()) {
list.append(new ProductField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProductField::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProductField::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setFieldTypeID(id, value.toString());
else if (index.column() == 3)
ok = setDefaults(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProductField::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProductFieldID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProductField::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProductField!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Field Type"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Defaults"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProductField::setDescription(int ProductFieldID, const QString &Description) {
QSqlQuery query;
query.prepare("update ProductField set Description = ? where ProductFieldID = ?");
query.addBindValue(Description);
query.addBindValue(ProductFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductField::setFieldTypeID(int ProductFieldID, const QString &FieldTypeID) {
QSqlQuery query;
query.prepare("update ProductField set FieldTypeID = ? where ProductFieldID = ?");
query.addBindValue(FieldTypeID);
query.addBindValue(ProductFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductField::setDefaults(int ProductFieldID, const QString &Defaults) {
QSqlQuery query;
query.prepare("update ProductField set Defaults = ? where ProductFieldID = ?");
query.addBindValue(Defaults);
query.addBindValue(ProductFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductField::setCreatedOn(int ProductFieldID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProductField set CreatedOn = ? where ProductFieldID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProductFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProductField::setEditedOn(int ProductFieldID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProductField set EditedOn = ? where ProductFieldID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProductFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

