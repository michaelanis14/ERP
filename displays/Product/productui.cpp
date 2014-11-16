/**************************************************************************
**   File: productui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productui.h"
#include "../MainWindow.h"

ProductUI::ProductUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
ERPFormBlock * blockSaveCancel = new ERPFormBlock;
 QWidget* addremove = new QWidget();
 QHBoxLayout* addRemovelayout = new QHBoxLayout(addremove);
 addRemovelayout->setContentsMargins(0,0,0,0);
 QPushButton* save = new QPushButton("Save");
 QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
 save->setObjectName("save");
 QPushButton* cancel = new QPushButton("Cancel");
 cancel->setObjectName("cancel");
 QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
 QPushButton* clear = new QPushButton("Clear");
 QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
 clear->setObjectName("clear");
 addRemovelayout->addStretch(1);
 addRemovelayout->addWidget(save,0,Qt::AlignCenter);
 addRemovelayout->addStretch(0);
 addRemovelayout->addWidget(clear,0,Qt::AlignCenter);
 addRemovelayout->addWidget(cancel,0,Qt::AlignCenter);
 addRemovelayout->addStretch(1);
 blockSaveCancel->addRow("",addremove);
 flowLayout->addWidget(blockSaveCancel);
block0Layout = new ERPFormBlock;
name = new QLineEdit();
QStringList* list = new QStringList(Product::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectProduct()));
block0Layout->addRow("Name",name);
sellingprice = new QLineEdit();
sellingprice->setValidator( doubleValidator );
block0Layout->addRow("Selling Price",sellingprice);
netprice = new QLineEdit();
netprice->setValidator( doubleValidator );
block0Layout->addRow("Net Price",netprice);
trademargine = new QLineEdit();
trademargine->setValidator( doubleValidator );
block0Layout->addRow("Trade Margine",trademargine);
description = new QLineEdit();
block0Layout->addRow("Description",description);
barcode = new QLineEdit();
block0Layout->addRow("Barcode",barcode);
criticalamount = new QLineEdit();
criticalamount->setValidator( doubleValidator );
block0Layout->addRow("Critical Amount",criticalamount);
productnumber = new QLineEdit();
block0Layout->addRow("Product Number",productnumber);
moreinfo = new QLineEdit();
block0Layout->addRow("More Info",moreinfo);
barcodeonly = new QCheckBox();
block0Layout->addRow("Barcode Only",barcodeonly);
iscomposite = new QCheckBox();
block0Layout->addRow("isComposite",iscomposite);
specialtaxdescription = new QLineEdit();
block0Layout->addRow("Special Tax Description",specialtaxdescription);
specialtaxvalue = new QLineEdit();
specialtaxvalue->setValidator( doubleValidator );
block0Layout->addRow("Special Tax Value",specialtaxvalue);
tax = new ERPComboBox();
tax->addItems(Tax::GetHashList());
block0Layout->addRow("Tax",tax);
unit = new ERPComboBox();
unit->addItems(Unit::GetHashList());
block0Layout->addRow("Unit",unit);
generatebarcode = new QCheckBox();
block0Layout->addRow("generateBarcode",generatebarcode);
shortdescription = new QLineEdit();
block0Layout->addRow("Short Description",shortdescription);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProductUI::p_instance = 0;
void ProductUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ProductUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
ProductUI*ProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProductUI*) p_instance; 
}
void ProductUI::fill(Product* product){ 
this->product = product;
name->setText(product->Name);
sellingprice->setText(QString::number(product->SellingPrice));
netprice->setText(QString::number(product->NetPrice));
trademargine->setText(QString::number(product->TradeMargine));
description->setText(product->Description);
barcode->setText(product->Barcode);
criticalamount->setText(QString::number(product->CriticalAmount));
productnumber->setText(product->ProductNumber);
moreinfo->setText(product->MoreInfo);
barcodeonly->setChecked(product->BarcodeOnly);
iscomposite->setChecked(product->isComposite);
specialtaxdescription->setText(product->SpecialTaxDescription);
specialtaxvalue->setText(QString::number(product->SpecialTaxValue));
generatebarcode->setChecked(product->generateBarcode);
shortdescription->setText(product->ShortDescription);
} 
void ProductUI::clear(){ 
sellingprice->setText("");
netprice->setText("");
trademargine->setText("");
description->setText("");
barcode->setText("");
criticalamount->setText("");
productnumber->setText("");
moreinfo->setText("");
barcodeonly->setChecked(false);
iscomposite->setChecked(false);
specialtaxdescription->setText("");
specialtaxvalue->setText("");
generatebarcode->setChecked(false);
shortdescription->setText("");
this->product = new Product();
} 
void ProductUI::selectProduct(){ 
if(Product::GetStringList().contains(name->text()))
{
Product* con = Product::Get(name->text());
if(this->product->ProductID != con->ProductID){
this->product = con;
fill(this->product);
}
}
else if(product->ProductID != 0)
clear();
}
void ProductUI::save(){ 
product->Name = name->text();
product->SellingPrice = sellingprice->text().toDouble();
product->NetPrice = netprice->text().toDouble();
product->TradeMargine = trademargine->text().toDouble();
product->Description = description->text();
product->Barcode = barcode->text();
product->CriticalAmount = criticalamount->text().toDouble();
product->ProductNumber = productnumber->text();
product->MoreInfo = moreinfo->text();
product->BarcodeOnly = barcodeonly->text().toInt();
product->isComposite = iscomposite->text().toInt();
product->SpecialTaxDescription = specialtaxdescription->text();
product->SpecialTaxValue = specialtaxvalue->text().toDouble();
if(product->TaxID == 0) 
product->TaxID = tax->getKey();
if(product->UnitID == 0) 
product->UnitID = unit->getKey();
product->generateBarcode = generatebarcode->text().toInt();
product->ShortDescription = shortdescription->text();
product->save();
ProductIndexUI::ShowUI();
}
void ProductUI::cancel(){ 
ProductIndexUI::ShowUI();
}
