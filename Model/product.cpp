/**************************************************************************
**   File: product.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "product.h"
#include "erpmodel.h"

Product::Product()
 : QSqlRelationalTableModel(){

this->ProductID = 0 ;
this->Name = " ";
this->SellingPrice = 0 ;
this->NetPrice = 0 ;
this->TradeMargine = 0 ;
this->Description = " ";
this->Barcode = " ";
this->CriticalAmount = 0 ;
this->ProductNumber = " ";
this->MoreInfo = " ";
this->BarcodeOnly = 0 ;
this->isComposite = 0 ;
this->SpecialTaxDescription = " ";
this->SpecialTaxValue = 0 ;
this->TaxID = 0 ;
this->UnitID = 0 ;
this->generateBarcode = 0 ;
this->ShortDescription = " ";
this->CreatedOn = " ";
this->EditedOn = " ";
this->setTable("Product");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(14, QSqlRelation("Tax", "TaxID", "Description"));
this->setRelation(15, QSqlRelation("Unit", "UnitID", "Description"));
}
Product::Product(int ProductID,QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductID = ProductID ;
this->Name = Name ;
this->SellingPrice = SellingPrice ;
this->NetPrice = NetPrice ;
this->TradeMargine = TradeMargine ;
this->Description = Description ;
this->Barcode = Barcode ;
this->CriticalAmount = CriticalAmount ;
this->ProductNumber = ProductNumber ;
this->MoreInfo = MoreInfo ;
this->BarcodeOnly = BarcodeOnly ;
this->isComposite = isComposite ;
this->SpecialTaxDescription = SpecialTaxDescription ;
this->SpecialTaxValue = SpecialTaxValue ;
this->TaxID = TaxID ;
this->UnitID = UnitID ;
this->generateBarcode = generateBarcode ;
this->ShortDescription = ShortDescription ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Product::Product(QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProductID = 0 ;
this->Name = Name ;
this->SellingPrice = SellingPrice ;
this->NetPrice = NetPrice ;
this->TradeMargine = TradeMargine ;
this->Description = Description ;
this->Barcode = Barcode ;
this->CriticalAmount = CriticalAmount ;
this->ProductNumber = ProductNumber ;
this->MoreInfo = MoreInfo ;
this->BarcodeOnly = BarcodeOnly ;
this->isComposite = isComposite ;
this->SpecialTaxDescription = SpecialTaxDescription ;
this->SpecialTaxValue = SpecialTaxValue ;
this->TaxID = TaxID ;
this->UnitID = UnitID ;
this->generateBarcode = generateBarcode ;
this->ShortDescription = ShortDescription ;
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
"SellingPrice DECIMAL(6,2) NOT NULL, "
"NetPrice DECIMAL(6,2) NOT NULL, "
"TradeMargine DECIMAL(6,2) NOT NULL, "
"Description VARCHAR(40) NOT NULL, "
"Barcode VARCHAR(40) NOT NULL, "
"CriticalAmount DECIMAL(6,2) NOT NULL, "
"ProductNumber VARCHAR(40) NOT NULL, "
"MoreInfo VARCHAR(40) NOT NULL, "
"BarcodeOnly VARCHAR(1) NOT NULL, "
"isComposite VARCHAR(1) NOT NULL, "
"SpecialTaxDescription VARCHAR(40) NOT NULL, "
"SpecialTaxValue DECIMAL(6,2) NOT NULL, "
"TaxID INT NOT NULL, "
"FOREIGN KEY (TaxID) REFERENCES Tax(TaxID),"
"UnitID INT NOT NULL, "
"FOREIGN KEY (UnitID) REFERENCES Unit(UnitID),"
"generateBarcode VARCHAR(1) NOT NULL, "
"ShortDescription VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

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
if(ProductID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString(); 
	this->EditedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Product (Name,SellingPrice,NetPrice,TradeMargine,Description,Barcode,CriticalAmount,ProductNumber,MoreInfo,BarcodeOnly,isComposite,SpecialTaxDescription,SpecialTaxValue,TaxID,UnitID,generateBarcode,ShortDescription,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString::number(this->SellingPrice)+"','"+QString::number(this->NetPrice)+"','"+QString::number(this->TradeMargine)+"','"+QString(this->Description)+"','"+QString(this->Barcode)+"','"+QString::number(this->CriticalAmount)+"','"+QString(this->ProductNumber)+"','"+QString(this->MoreInfo)+"','"+QString::number(this->BarcodeOnly)+"','"+QString::number(this->isComposite)+"','"+QString(this->SpecialTaxDescription)+"','"+QString::number(this->SpecialTaxValue)+"','"+QString::number(this->TaxID)+"','"+QString::number(this->UnitID)+"','"+QString::number(this->generateBarcode)+"','"+QString(this->ShortDescription)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Product SET ""Name = '"+QString(this->Name)+"','"+"SellingPrice = '"+QString::number(this->SellingPrice)+"','"+"NetPrice = '"+QString::number(this->NetPrice)+"','"+"TradeMargine = '"+QString::number(this->TradeMargine)+"','"+"Description = '"+QString(this->Description)+"','"+"Barcode = '"+QString(this->Barcode)+"','"+"CriticalAmount = '"+QString::number(this->CriticalAmount)+"','"+"ProductNumber = '"+QString(this->ProductNumber)+"','"+"MoreInfo = '"+QString(this->MoreInfo)+"','"+"BarcodeOnly = '"+QString::number(this->BarcodeOnly)+"','"+"isComposite = '"+QString::number(this->isComposite)+"','"+"SpecialTaxDescription = '"+QString(this->SpecialTaxDescription)+"','"+"SpecialTaxValue = '"+QString::number(this->SpecialTaxValue)+"','"+"TaxID = '"+QString::number(this->TaxID)+"','"+"UnitID = '"+QString::number(this->UnitID)+"','"+"generateBarcode = '"+QString::number(this->generateBarcode)+"','"+"ShortDescription = '"+QString(this->ShortDescription)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProductID ='"+QString::number(this->ProductID)+"'");
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
return new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString());
 }

}
return new Product();
 }

QList<Product*> Product::GetAll() {
	Product::GetInstance()->products.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product"));
	while (query.next()) {
		Product::GetInstance()->products.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString()));
	}
	return Product::GetInstance()->products;
}

Product* Product::Get(int id) {
Product* product = new Product();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Product WHERE ProductID = '"+QString::number(id)+"'"));
while (query.next()) {
product = new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString());
 }

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
product = new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString());

 }

}
return product;
 }

QList<Product*> Product::Search(QString keyword) {
QList<Product*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR Description LIKE '%"+keyword+"%'"
"OR Barcode LIKE '%"+keyword+"%'"
"OR ProductNumber LIKE '%"+keyword+"%'"
"OR MoreInfo LIKE '%"+keyword+"%'"
"OR SpecialTaxDescription LIKE '%"+keyword+"%'"
"OR ShortDescription LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString()));
 }

}
return list;
 }

QList<QString> Product::GetStringList() {
	QList<QString> list;
	int count =Product::GetInstance()->products.count();
	if( count < 2){
		Product::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Product::GetInstance()->products[i]->Name);
	}
	return list;
}

QHash<int,QString> Product::GetHashList() {
	QHash<int,QString> list;
	int count =Product::GetInstance()->products.count();
	if( count < 2){
		Product::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(Product::GetInstance()->products[i]->ProductID,Product::GetInstance()->products[i]->Name);
	}
	return list;
}

int Product::GetIndex(QString name) {
	int count =Product::GetInstance()->products.count();
	if( count < 2){
		Product::GetAll();
	}
	for(int i = 0; i < count; i++){
		if(Product::GetInstance()->products[i]->Name == name){
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
list.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString(),query.value(19).toString()));
 }

}
return list;
 }

Qt::ItemFlags Product::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 14 || index.column() == 15 || index.column() == 16 || index.column() == 17 || index.column() == 18 || index.column() == 19)
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
ok = setSellingPrice(id, value.toString());
else if (index.column() == 3)
ok = setNetPrice(id, value.toString());
else if (index.column() == 4)
ok = setTradeMargine(id, value.toString());
else if (index.column() == 5)
ok = setDescription(id, value.toString());
else if (index.column() == 6)
ok = setBarcode(id, value.toString());
else if (index.column() == 7)
ok = setCriticalAmount(id, value.toString());
else if (index.column() == 8)
ok = setProductNumber(id, value.toString());
else if (index.column() == 9)
ok = setMoreInfo(id, value.toString());
else if (index.column() == 10)
ok = setBarcodeOnly(id, value.toString());
else if (index.column() == 11)
ok = setisComposite(id, value.toString());
else if (index.column() == 12)
ok = setSpecialTaxDescription(id, value.toString());
else if (index.column() == 13)
ok = setSpecialTaxValue(id, value.toString());
else if (index.column() == 14)
ok = setTaxID(id, value.toString());
else if (index.column() == 15)
ok = setUnitID(id, value.toString());
else if (index.column() == 16)
ok = setgenerateBarcode(id, value.toString());
else if (index.column() == 17)
ok = setShortDescription(id, value.toString());
else if (index.column() == 18)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 19)
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
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Selling Price"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Net Price"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Trade Margine"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Barcode"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Critical Amount"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Product Number"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("More Info"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Barcode Only"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("isComposite"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Special Tax Description"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Special Tax Value"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Tax"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Unit"));
this->setHeaderData(16, Qt::Horizontal, QObject::tr("generateBarcode"));
this->setHeaderData(17, Qt::Horizontal, QObject::tr("Short Description"));
this->setHeaderData(18, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(19, Qt::Horizontal, QObject::tr("Edited On"));
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
bool Product::setSellingPrice(int ProductID, const QString &SellingPrice) {
QSqlQuery query;
query.prepare("update Product set SellingPrice = ? where ProductID = ?");
query.addBindValue(SellingPrice);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setNetPrice(int ProductID, const QString &NetPrice) {
QSqlQuery query;
query.prepare("update Product set NetPrice = ? where ProductID = ?");
query.addBindValue(NetPrice);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setTradeMargine(int ProductID, const QString &TradeMargine) {
QSqlQuery query;
query.prepare("update Product set TradeMargine = ? where ProductID = ?");
query.addBindValue(TradeMargine);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setDescription(int ProductID, const QString &Description) {
QSqlQuery query;
query.prepare("update Product set Description = ? where ProductID = ?");
query.addBindValue(Description);
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
bool Product::setCriticalAmount(int ProductID, const QString &CriticalAmount) {
QSqlQuery query;
query.prepare("update Product set CriticalAmount = ? where ProductID = ?");
query.addBindValue(CriticalAmount);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setProductNumber(int ProductID, const QString &ProductNumber) {
QSqlQuery query;
query.prepare("update Product set ProductNumber = ? where ProductID = ?");
query.addBindValue(ProductNumber);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setMoreInfo(int ProductID, const QString &MoreInfo) {
QSqlQuery query;
query.prepare("update Product set MoreInfo = ? where ProductID = ?");
query.addBindValue(MoreInfo);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setBarcodeOnly(int ProductID, const QString &BarcodeOnly) {
QSqlQuery query;
query.prepare("update Product set BarcodeOnly = ? where ProductID = ?");
query.addBindValue(BarcodeOnly);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setisComposite(int ProductID, const QString &isComposite) {
QSqlQuery query;
query.prepare("update Product set isComposite = ? where ProductID = ?");
query.addBindValue(isComposite);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setSpecialTaxDescription(int ProductID, const QString &SpecialTaxDescription) {
QSqlQuery query;
query.prepare("update Product set SpecialTaxDescription = ? where ProductID = ?");
query.addBindValue(SpecialTaxDescription);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setSpecialTaxValue(int ProductID, const QString &SpecialTaxValue) {
QSqlQuery query;
query.prepare("update Product set SpecialTaxValue = ? where ProductID = ?");
query.addBindValue(SpecialTaxValue);
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
bool Product::setUnitID(int ProductID, const QString &UnitID) {
QSqlQuery query;
query.prepare("update Product set UnitID = ? where ProductID = ?");
query.addBindValue(UnitID);
query.addBindValue(ProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Product::setgenerateBarcode(int ProductID, const QString &generateBarcode) {
QSqlQuery query;
query.prepare("update Product set generateBarcode = ? where ProductID = ?");
query.addBindValue(generateBarcode);
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

