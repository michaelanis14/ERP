/**************************************************************************
**   File: productui.cpp
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productui.h"
#include "../MainWindow.h"

ProductUI::ProductUI(QWidget *parent) :ERPDisplay(parent)
{

product = new Product();
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
QPushButton* save = new QPushButton("Save");
 QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
 save->setObjectName("save");
 QPushButton* cancel = new QPushButton("Cancel");
 cancel->setObjectName("cancel");
 QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
 QPushButton* clear = new QPushButton("Clear");
 QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
 clear->setObjectName("clear");
 this->controllers->addControllerButton(save); 
 this->controllers->addControllerButton(clear);  
 this->controllers->addControllerButton(cancel);
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
clear();
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
delete this->product;
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
fill(con);
}
}
else if(product->ProductID != 0)
clear();
}
bool ProductUI::save(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += "Name Can't be Empty! \n";
name->setObjectName("error");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
}
else { 
name->setObjectName("name");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
product->Name = name->text().trimmed();
}
if(sellingprice->text().trimmed().isEmpty()){
errors = true;
errorString += "Selling Price Can't be Empty! \n";
sellingprice->setObjectName("error");
sellingprice->style()->unpolish(sellingprice);
sellingprice->style()->polish(sellingprice);
sellingprice->update();
}
else { 
sellingprice->setObjectName("sellingprice");
sellingprice->style()->unpolish(sellingprice);
sellingprice->style()->polish(sellingprice);
sellingprice->update();
product->SellingPrice = sellingprice->text().trimmed().toDouble();
}
if(netprice->text().trimmed().isEmpty()){
errors = true;
errorString += "Net Price Can't be Empty! \n";
netprice->setObjectName("error");
netprice->style()->unpolish(netprice);
netprice->style()->polish(netprice);
netprice->update();
}
else { 
netprice->setObjectName("netprice");
netprice->style()->unpolish(netprice);
netprice->style()->polish(netprice);
netprice->update();
product->NetPrice = netprice->text().trimmed().toDouble();
}
if(trademargine->text().trimmed().isEmpty()){
errors = true;
errorString += "Trade Margine Can't be Empty! \n";
trademargine->setObjectName("error");
trademargine->style()->unpolish(trademargine);
trademargine->style()->polish(trademargine);
trademargine->update();
}
else { 
trademargine->setObjectName("trademargine");
trademargine->style()->unpolish(trademargine);
trademargine->style()->polish(trademargine);
trademargine->update();
product->TradeMargine = trademargine->text().trimmed().toDouble();
}
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += "Description Can't be Empty! \n";
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else { 
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
product->Description = description->text().trimmed();
}
if(barcode->text().trimmed().isEmpty()){
errors = true;
errorString += "Barcode Can't be Empty! \n";
barcode->setObjectName("error");
barcode->style()->unpolish(barcode);
barcode->style()->polish(barcode);
barcode->update();
}
else { 
barcode->setObjectName("barcode");
barcode->style()->unpolish(barcode);
barcode->style()->polish(barcode);
barcode->update();
product->Barcode = barcode->text().trimmed();
}
if(criticalamount->text().trimmed().isEmpty()){
errors = true;
errorString += "Critical Amount Can't be Empty! \n";
criticalamount->setObjectName("error");
criticalamount->style()->unpolish(criticalamount);
criticalamount->style()->polish(criticalamount);
criticalamount->update();
}
else { 
criticalamount->setObjectName("criticalamount");
criticalamount->style()->unpolish(criticalamount);
criticalamount->style()->polish(criticalamount);
criticalamount->update();
product->CriticalAmount = criticalamount->text().trimmed().toDouble();
}
if(productnumber->text().trimmed().isEmpty()){
errors = true;
errorString += "Product Number Can't be Empty! \n";
productnumber->setObjectName("error");
productnumber->style()->unpolish(productnumber);
productnumber->style()->polish(productnumber);
productnumber->update();
}
else { 
productnumber->setObjectName("productnumber");
productnumber->style()->unpolish(productnumber);
productnumber->style()->polish(productnumber);
productnumber->update();
product->ProductNumber = productnumber->text().trimmed();
}
if(moreinfo->text().trimmed().isEmpty()){
errors = true;
errorString += "More Info Can't be Empty! \n";
moreinfo->setObjectName("error");
moreinfo->style()->unpolish(moreinfo);
moreinfo->style()->polish(moreinfo);
moreinfo->update();
}
else { 
moreinfo->setObjectName("moreinfo");
moreinfo->style()->unpolish(moreinfo);
moreinfo->style()->polish(moreinfo);
moreinfo->update();
product->MoreInfo = moreinfo->text().trimmed();
}
product->BarcodeOnly = barcodeonly->text().trimmed().toInt();
product->isComposite = iscomposite->text().trimmed().toInt();
if(specialtaxdescription->text().trimmed().isEmpty()){
errors = true;
errorString += "Special Tax Description Can't be Empty! \n";
specialtaxdescription->setObjectName("error");
specialtaxdescription->style()->unpolish(specialtaxdescription);
specialtaxdescription->style()->polish(specialtaxdescription);
specialtaxdescription->update();
}
else { 
specialtaxdescription->setObjectName("specialtaxdescription");
specialtaxdescription->style()->unpolish(specialtaxdescription);
specialtaxdescription->style()->polish(specialtaxdescription);
specialtaxdescription->update();
product->SpecialTaxDescription = specialtaxdescription->text().trimmed();
}
if(specialtaxvalue->text().trimmed().isEmpty()){
errors = true;
errorString += "Special Tax Value Can't be Empty! \n";
specialtaxvalue->setObjectName("error");
specialtaxvalue->style()->unpolish(specialtaxvalue);
specialtaxvalue->style()->polish(specialtaxvalue);
specialtaxvalue->update();
}
else { 
specialtaxvalue->setObjectName("specialtaxvalue");
specialtaxvalue->style()->unpolish(specialtaxvalue);
specialtaxvalue->style()->polish(specialtaxvalue);
specialtaxvalue->update();
product->SpecialTaxValue = specialtaxvalue->text().trimmed().toDouble();
}
if(product->TaxID == 0) 
product->TaxID = tax->getKey();
if(product->UnitID == 0) 
product->UnitID = unit->getKey();
product->generateBarcode = generatebarcode->text().trimmed().toInt();
if(shortdescription->text().trimmed().isEmpty()){
errors = true;
errorString += "Short Description Can't be Empty! \n";
shortdescription->setObjectName("error");
shortdescription->style()->unpolish(shortdescription);
shortdescription->style()->polish(shortdescription);
shortdescription->update();
}
else { 
shortdescription->setObjectName("shortdescription");
shortdescription->style()->unpolish(shortdescription);
shortdescription->style()->polish(shortdescription);
shortdescription->update();
product->ShortDescription = shortdescription->text().trimmed();
}
if(!errors) {
product->save();
if(!errors){
ProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Product",errorString.trimmed());
return false; 
 }
}
void ProductUI::cancel(){ 
ProductIndexUI::ShowUI();
}
