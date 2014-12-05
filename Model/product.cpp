/**************************************************************************
**   File: product.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "product.h"
#include "erpmodel.h"

Product::Product()
 : QSqlRelationalTableModel(){

this->ProductID = 0 ;
this->Name = "";
this->Image = "";
this->ShortDescription = "";
this->UnitID = 0 ;
this->ProductIsAComposite = 0 ;
this->SellingPrice = 0 ;
this->NetCoast = 0 ;
this->TradeMarginRate = 0 ;
this->TaxID = 0 ;
this->information = "";
this->Barcode = "";
this->ProductCategoryID = 0 ;
this->CriticalAmount = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Product");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(4, QSqlRelation("Unit", "UnitID", "Description"));
this->setRelation(9, QSqlRelation("Tax", "TaxID", "Title"));
this->setRelation(12, QSqlRelation("ProductCategory", "ProductCategoryID", "Description"));
}
Product::Product(int ProductID,QString Name,QString Image,QString ShortDescription,int UnitID,bool ProductIsAComposite,double SellingPrice,double NetCoast,double TradeMarginRate,int TaxID,QString information,QString Barcode,int ProductCategoryID,double CriticalAmount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductID = ProductID ;
this->Name = Name ;
this->Image = Image ;
this->ShortDescription = ShortDescription ;
this->UnitID = UnitID ;
this->ProductIsAComposite = ProductIsAComposite ;
this->SellingPrice = SellingPrice ;
this->NetCoast = NetCoast ;
this->TradeMarginRate = TradeMarginRate ;
this->TaxID = TaxID ;
this->information = information ;
this->Barcode = Barcode ;
this->ProductCategoryID = ProductCategoryID ;
this->CriticalAmount = CriticalAmount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Product::Product(QString Name,QString Image,QString ShortDescription,int UnitID,bool ProductIsAComposite,double SellingPrice,double NetCoast,double TradeMarginRate,int TaxID,QString information,QString Barcode,int ProductCategoryID,double CriticalAmount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductID = 0 ;
this->Name = Name ;
this->Image = Image ;
this->ShortDescription = ShortDescription ;
this->UnitID = UnitID ;
this->ProductIsAComposite = ProductIsAComposite ;
this->SellingPrice = SellingPrice ;
this->NetCoast = NetCoast ;
this->TradeMarginRate = TradeMarginRate ;
this->TaxID = TaxID ;
this->information = information ;
this->Barcode = Barcode ;
this->ProductCategoryID = ProductCategoryID ;
this->CriticalAmount = CriticalAmount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Product::Init()
{

QString table = "Product";
QString query =
"(ProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProductID),"
"Name VARCHAR(40) NOT NULL, "
"Image VARCHAR(40) NOT NULL, "
"ShortDescription VARCHAR(40) NOT NULL, "
"UnitID INT NOT NULL, "
"FOREIGN KEY (UnitID) REFERENCES Unit(UnitID)  ON DELETE CASCADE,"
"ProductIsAComposite VARCHAR(1) NOT NULL, "
"SellingPrice DECIMAL(6,2) NOT NULL, "
"NetCoast DECIMAL(6,2) NOT NULL, "
"TradeMarginRate DECIMAL(6,2) NOT NULL, "
"TaxID INT NOT NULL, "
"FOREIGN KEY (TaxID) REFERENCES Tax(TaxID)  ON DELETE CASCADE,"
"information VARCHAR(40) NOT NULL, "
"Barcode VARCHAR(40) NOT NULL, "
"ProductCategoryID INT NOT NULL, "
"FOREIGN KEY (ProductCategoryID) REFERENCES ProductCategory(ProductCategoryID)  ON DELETE CASCADE,"
"CriticalAmount DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Product* Product::p_instance = 0;
Product* Product::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Product();
		Product::GetAll();
	}
return p_instance;
}
bool Product::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProductID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Product (Name,Image,ShortDescription,UnitID,ProductIsAComposite,SellingPrice,NetCoast,TradeMarginRate,TaxID,information,Barcode,ProductCategoryID,CriticalAmount,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->Image)+"','"+QString(this->ShortDescription)+"','"+QString::number(this->UnitID)+"','"+QString::number(this->ProductIsAComposite)+"','"+QString::number(this->SellingPrice)+"','"+QString::number(this->NetCoast)+"','"+QString::number(this->TradeMarginRate)+"','"+QString::number(this->TaxID)+"','"+QString(this->information)+"','"+QString(this->Barcode)+"','"+QString::number(this->ProductCategoryID)+"','"+QString::number(this->CriticalAmount)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Product SET "	"Name = '"+QString(this->Name)+"',"+"Image = '"+QString(this->Image)+"',"+"ShortDescription = '"+QString(this->ShortDescription)+"',"+"UnitID = '"+QString::number(this->UnitID)+"',"+"ProductIsAComposite = '"+QString::number(this->ProductIsAComposite)+"',"+"SellingPrice = '"+QString::number(this->SellingPrice)+"',"+"NetCoast = '"+QString::number(this->NetCoast)+"',"+"TradeMarginRate = '"+QString::number(this->TradeMarginRate)+"',"+"TaxID = '"+QString::number(this->TaxID)+"',"+"information = '"+QString(this->information)+"',"+"Barcode = '"+QString(this->Barcode)+"',"+"ProductCategoryID = '"+QString::number(this->ProductCategoryID)+"',"+"CriticalAmount = '"+QString::number(this->CriticalAmount)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProductID ='"+QString::number(this->ProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProductID FROM Product WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProductID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Product::remove() {
if(ProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Product WHERE ProductID ="+QString::number(this->ProductID)+""));
return true;
 }
return false;
}

Product* Product::get() {
if(ProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Product"
"WHERE ProductID ='"+QString::number(this->ProductID)+"'"));
while (query.next()) {
return new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toString(),query.value(15).toString());
 }

}
return new Product();
 }

QList<Product*> Product::GetAll() {
	QList<Product*> products =   QList<Product*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product"));
	while (query.next()) {
products.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toString(),query.value(15).toString()));
	}
qStableSort(products.begin(),products.end());
	return products;
}

Product* Product::Get(int id) {
Product* product = new Product();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Product WHERE ProductID = '"+QString::number(id)+"'"));
while (query.next()) {
product = new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toString(),query.value(15).toString());
 }
product->productfielddatas = ProductFieldData::QuerySelect("ProductID = " + QString::number(id));

}
return product;
}

Product* Product::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Product();
}

Product* Product::Get(QString name) {
Product* product = new Product();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product WHERE Name = '"+name+"'"));
while (query.next()) {
product = new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toString(),query.value(15).toString());

 }
product->productfielddatas = ProductFieldData::QuerySelect("ProductID = " +QString::number(product->ProductID));

}
return product;
 }

QList<Product*> Product::Search(QString keyword) {
QList<Product*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR Image LIKE '%"+keyword+"%'"
"OR ShortDescription LIKE '%"+keyword+"%'"
"OR information LIKE '%"+keyword+"%'"
"OR Barcode LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toString(),query.value(15).toString()));
 }

}
return list;
 }

QList<QString> Product::GetStringList() {
	QList<QString> list;
	QList<Product*> products =   QList<Product*>();
products = GetAll();
	for(int i = 0; i <products.count(); i++){
		list.append(products[i]->Name);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> Product::GetHashList() {
	QHash<int,QString> list;
	QList<Product*> products =   QList<Product*>();
products = GetAll();
	for(int i = 0; i <products.count(); i++){
		list.insert(products[i]->ProductID,products[i]->Name);
	}
	return list;
}

int Product::GetIndex(QString name) {
	QList<Product*> products =   QList<Product*>();
products = GetAll();
	for(int i = 0; i <products.count(); i++){
		if(products[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Product*> Product::QuerySelect(QString select) {
QList<Product*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product WHERE "+select+"" ));
while (query.next()) {
list.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toString(),query.value(15).toString()));
 }

}
return list;
 }

Qt::ItemFlags Product::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 15 || index.column() == 16)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Product::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setImage(id, value.toString());
else if (index.column() == 3)
ok = setShortDescription(id, value.toString());
else if (index.column() == 4)
ok = setUnitID(id, value.toString());
else if (index.column() == 5)
ok = setProductIsAComposite(id, value.toString());
else if (index.column() == 6)
ok = setSellingPrice(id, value.toString());
else if (index.column() == 7)
ok = setNetCoast(id, value.toString());
else if (index.column() == 8)
ok = setTradeMarginRate(id, value.toString());
else if (index.column() == 9)
ok = setTaxID(id, value.toString());
else if (index.column() == 10)
ok = setinformation(id, value.toString());
else if (index.column() == 11)
ok = setBarcode(id, value.toString());
else if (index.column() == 12)
ok = setProductCategoryID(id, value.toString());
else if (index.column() == 13)
ok = setCriticalAmount(id, value.toString());
else if (index.column() == 15)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 16)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Product::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Product::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Product!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Image"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Short Description"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Unit"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Product Is A Composite"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Selling Price"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Net Coast"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Trade Margin Rate"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Tax"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("information"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Barcode"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Product Category"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Critical Amount"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(16, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Product::setName(int ProductID, const QString &Name) {
QSqlQuery query;
query.prepare("update Product set Name = ? where ProductID = ?");
query.addBindValue(Name);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setImage(int ProductID, const QString &Image) {
QSqlQuery query;
query.prepare("update Product set Image = ? where ProductID = ?");
query.addBindValue(Image);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setShortDescription(int ProductID, const QString &ShortDescription) {
QSqlQuery query;
query.prepare("update Product set ShortDescription = ? where ProductID = ?");
query.addBindValue(ShortDescription);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setUnitID(int ProductID, const QString &UnitID) {
QSqlQuery query;
query.prepare("update Product set UnitID = ? where ProductID = ?");
query.addBindValue(UnitID);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setProductIsAComposite(int ProductID, const QString &ProductIsAComposite) {
QSqlQuery query;
query.prepare("update Product set ProductIsAComposite = ? where ProductID = ?");
query.addBindValue(ProductIsAComposite);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setSellingPrice(int ProductID, const QString &SellingPrice) {
QSqlQuery query;
query.prepare("update Product set SellingPrice = ? where ProductID = ?");
query.addBindValue(SellingPrice);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setNetCoast(int ProductID, const QString &NetCoast) {
QSqlQuery query;
query.prepare("update Product set NetCoast = ? where ProductID = ?");
query.addBindValue(NetCoast);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setTradeMarginRate(int ProductID, const QString &TradeMarginRate) {
QSqlQuery query;
query.prepare("update Product set TradeMarginRate = ? where ProductID = ?");
query.addBindValue(TradeMarginRate);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setTaxID(int ProductID, const QString &TaxID) {
QSqlQuery query;
query.prepare("update Product set TaxID = ? where ProductID = ?");
query.addBindValue(TaxID);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setinformation(int ProductID, const QString &information) {
QSqlQuery query;
query.prepare("update Product set information = ? where ProductID = ?");
query.addBindValue(information);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setBarcode(int ProductID, const QString &Barcode) {
QSqlQuery query;
query.prepare("update Product set Barcode = ? where ProductID = ?");
query.addBindValue(Barcode);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setProductCategoryID(int ProductID, const QString &ProductCategoryID) {
QSqlQuery query;
query.prepare("update Product set ProductCategoryID = ? where ProductID = ?");
query.addBindValue(ProductCategoryID);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setCriticalAmount(int ProductID, const QString &CriticalAmount) {
QSqlQuery query;
query.prepare("update Product set CriticalAmount = ? where ProductID = ?");
query.addBindValue(CriticalAmount);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setCreatedOn(int ProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Product set CreatedOn = ? where ProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setEditedOn(int ProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Product set EditedOn = ? where ProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

