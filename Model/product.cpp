/**************************************************************************
**   File: product.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "product.h"
#include "erpmodel.h"

Product::Product()
{

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
}
Product::Product(int ProductID,QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription){
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
}

Product::Product(QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription){
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
}

bool Product::init()
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
"ShortDescription VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
bool Product::save() {
if(ProductID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Product (Name,SellingPrice,NetPrice,TradeMargine,Description,Barcode,CriticalAmount,ProductNumber,MoreInfo,BarcodeOnly,isComposite,SpecialTaxDescription,SpecialTaxValue,TaxID,UnitID,generateBarcode,ShortDescription)"
"VALUES ('" +QString(this->Name)+"','"+QString::number(this->SellingPrice)+"','"+QString::number(this->NetPrice)+"','"+QString::number(this->TradeMargine)+"','"+QString(this->Description)+"','"+QString(this->Barcode)+"','"+QString::number(this->CriticalAmount)+"','"+QString(this->ProductNumber)+"','"+QString(this->MoreInfo)+"','"+QString::number(this->BarcodeOnly)+"','"+QString::number(this->isComposite)+"','"+QString(this->SpecialTaxDescription)+"','"+QString::number(this->SpecialTaxValue)+"','"+QString::number(this->TaxID)+"','"+QString::number(this->UnitID)+"','"+QString::number(this->generateBarcode)+"','"+QString(this->ShortDescription)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Product SET ""Name = '"+QString(this->Name)+"','"+"SellingPrice = '"+QString::number(this->SellingPrice)+"','"+"NetPrice = '"+QString::number(this->NetPrice)+"','"+"TradeMargine = '"+QString::number(this->TradeMargine)+"','"+"Description = '"+QString(this->Description)+"','"+"Barcode = '"+QString(this->Barcode)+"','"+"CriticalAmount = '"+QString::number(this->CriticalAmount)+"','"+"ProductNumber = '"+QString(this->ProductNumber)+"','"+"MoreInfo = '"+QString(this->MoreInfo)+"','"+"BarcodeOnly = '"+QString::number(this->BarcodeOnly)+"','"+"isComposite = '"+QString::number(this->isComposite)+"','"+"SpecialTaxDescription = '"+QString(this->SpecialTaxDescription)+"','"+"SpecialTaxValue = '"+QString::number(this->SpecialTaxValue)+"','"+"TaxID = '"+QString::number(this->TaxID)+"','"+"UnitID = '"+QString::number(this->UnitID)+"','"+"generateBarcode = '"+QString::number(this->generateBarcode)+"','"+"ShortDescription = '"+QString(this->ShortDescription)+"' WHERE ProductID ='"+QString::number(this->ProductID)+"'");
 }
return true;
}

bool Product::remove() {
if(ProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Product"
"WHERE ProductID ='"+QString::number(this->ProductID)+"'"));
return true;
 }
return false;
}

Product* Product::get() {
if(ProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Product"
"WHERE ProductID ='"+QString::number(this->ProductID)+"'"));
while (query.next()) {
return new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString());
 }

}
return new Product();
 }

QList<Product*> Product::getAll() {
QList<Product*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product"));
while (query.next()) {
list.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString()));
}
return list;
 }

Product* Product::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Product"
"WHERE ProductID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString());
 }

}
return new Product();
 }

Product* Product::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product"
"WHERE Name = '"+name+"'"));
while (query.next()) {
return new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString());
 }

}
return new Product();
 }

QList<Product*> Product::search(QString keyword) {
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
));
while (query.next()) {
list.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString()));
 }

}
return list;
 }

QList<Product*> Product::select(QString select) {
QList<Product*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Product"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Product(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString()));
 }

}
return list;
 }
