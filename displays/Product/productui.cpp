/**************************************************************************
**   File: productui.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
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
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block0Layout->setMinimumWidth(330);
name = new QLineEdit();
QStringList* list = new QStringList(Product::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectProduct()));
block0Layout->addRow("Name",name);
image = new QLineEdit();
block0Layout->addRow("Image",image);
shortdescription = new QLineEdit();
block0Layout->addRow("Short Description",shortdescription);
unit = new ERPComboBox();
unit->addItems(Unit::GetHashList());
block0Layout->addRow("Unit",unit);
productisacomposite = new QCheckBox();
block0Layout->addRow("Product Is A Composite",productisacomposite);
sellingprice = new QLineEdit();
sellingprice->setValidator( doubleValidator );
block0Layout->addRow("Selling Price",sellingprice);
netcoast = new QLineEdit();
netcoast->setValidator( doubleValidator );
block0Layout->addRow("Net Coast",netcoast);
trademarginrate = new QLineEdit();
trademarginrate->setValidator( doubleValidator );
block0Layout->addRow("Trade Margin Rate",trademarginrate);
tax = new ERPComboBox();
tax->addItems(Tax::GetHashList());
block0Layout->addRow("Tax",tax);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block1Layout->setMinimumWidth(330);
information = new QLineEdit();
block1Layout->addRow("information",information);
barcode = new QLineEdit();
QObject::connect(barcode, SIGNAL(textChanged(QString)), this, SLOT(barcodeChanged(QString)));
block1Layout->addRow("Barcode",barcode);
barcodeDisplay = new Barcode(0,0); block1Layout->addRow("Barcode",barcodeDisplay); generatebarcode = new QPushButton("Generate Barcode"); QObject::connect(generatebarcode, SIGNAL(clicked()), this, SLOT(generateBarcode())); block1Layout->addRow("",generatebarcode);
productcategory = new ERPComboBox();
productcategory->addItems(ProductCategory::GetHashList());
block1Layout->addRow("Product Category",productcategory);
criticalamount = new QLineEdit();
criticalamount->setValidator( doubleValidator );
block1Layout->addRow("Critical Amount",criticalamount);
flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block2Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveProductFieldDataButtons = new AddRemoveButtons();
block2Layout->addRow("ProductFieldDatas",addremoveProductFieldDataButtons);
QObject::connect(addremoveProductFieldDataButtons, SIGNAL(addPressed()), this, SLOT(addProductFieldData()));

flowLayout->addWidget(block2Layout);

}
ERPDisplay* ProductUI::p_instance = 0;
void ProductUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProductUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ProductUI*ProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProductUI*) p_instance; 
}
void ProductUI::addProductFieldData(){ 
ProductFieldDataUI* productfielddataui = new ProductFieldDataUI();
productfielddataui->block0Layout->removeRow(productfielddataui->product);
productfielddataui->controllers->setFixedHeight(0);
ProductFieldDatas.append(productfielddataui);
RemovebtnWidgets* rmproductfielddata = new RemovebtnWidgets(0,productfielddataui);
QObject::connect(rmproductfielddata, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProductFieldData(QWidget*)));
block2Layout->addRow("ProductFieldData"+QString::number(ProductFieldDatas.count()),rmproductfielddata);
}
void ProductUI::addProductFieldData(ProductFieldData* ProductFieldData){ 
ProductFieldDataUI* productfielddataui = new ProductFieldDataUI();
productfielddataui->block0Layout->removeRow(productfielddataui->product);
productfielddataui->controllers->setFixedHeight(0);
productfielddataui->fill(ProductFieldData);
ProductFieldDatas.append(productfielddataui);
RemovebtnWidgets* rmproductfielddata = new RemovebtnWidgets(0,productfielddataui);
QObject::connect(rmproductfielddata, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProductFieldData(QWidget*)));
block2Layout->addRow("ProductFieldData"+QString::number(ProductFieldDatas.count()),rmproductfielddata);
}
void ProductUI::removeProductFieldData(QWidget* widget){ 
if(ProductFieldDatas.count()  > 0){
ProductFieldDataUI* productfielddataui = (ProductFieldDataUI*) widget;
ProductFieldDatas.removeOne(productfielddataui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block2Layout->removeRow(sender);
}
}
void ProductUI::fill(Product* product){ 
clear();
this->product = product;
name->setText(product->Name);
image->setText(product->Image);
shortdescription->setText(product->ShortDescription);
productisacomposite->setChecked(product->ProductIsAComposite);
sellingprice->setText(QString::number(product->SellingPrice));
netcoast->setText(QString::number(product->NetCoast));
trademarginrate->setText(QString::number(product->TradeMarginRate));
information->setText(product->information);
barcode->setText(product->Barcode);
criticalamount->setText(QString::number(product->CriticalAmount));
foreach(ProductFieldData* productfielddata, product->productfielddatas) {
addProductFieldData(productfielddata);
}
} 
void ProductUI::clear(){ 
delete this->product;
this->ProductFieldDatas.clear();
image->setText("");
shortdescription->setText("");
productisacomposite->setChecked(false);
sellingprice->setText("");
netcoast->setText("");
trademarginrate->setText("");
information->setText("");
barcode->setText("");
criticalamount->setText("");
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
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
void ProductUI::generateBarcode(){ QString number = ""; for(int i = 0; i < 13; i++)  number += QString::number(rand() % 10); barcode->setText(number); barcodeDisplay->barcode = number; barcodeDisplay->repaint(); }
void ProductUI::barcodeChanged(QString barcode){ if(this->barcode->text().count() > 13) this->barcode->setText(this->barcode->text().remove(12,20)); barcodeDisplay->barcode = barcode; barcodeDisplay->repaint(); }
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
if(image->text().trimmed().isEmpty()){
errors = true;
errorString += "Image Can't be Empty! \n";
image->setObjectName("error");
image->style()->unpolish(image);
image->style()->polish(image);
image->update();
}
else { 
image->setObjectName("image");
image->style()->unpolish(image);
image->style()->polish(image);
image->update();
product->Image = image->text().trimmed();
}
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
if(product->UnitID == 0) 
product->UnitID = unit->getKey();
product->ProductIsAComposite = productisacomposite->text().trimmed().toInt();
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
if(netcoast->text().trimmed().isEmpty()){
errors = true;
errorString += "Net Coast Can't be Empty! \n";
netcoast->setObjectName("error");
netcoast->style()->unpolish(netcoast);
netcoast->style()->polish(netcoast);
netcoast->update();
}
else { 
netcoast->setObjectName("netcoast");
netcoast->style()->unpolish(netcoast);
netcoast->style()->polish(netcoast);
netcoast->update();
product->NetCoast = netcoast->text().trimmed().toDouble();
}
if(trademarginrate->text().trimmed().isEmpty()){
errors = true;
errorString += "Trade Margin Rate Can't be Empty! \n";
trademarginrate->setObjectName("error");
trademarginrate->style()->unpolish(trademarginrate);
trademarginrate->style()->polish(trademarginrate);
trademarginrate->update();
}
else { 
trademarginrate->setObjectName("trademarginrate");
trademarginrate->style()->unpolish(trademarginrate);
trademarginrate->style()->polish(trademarginrate);
trademarginrate->update();
product->TradeMarginRate = trademarginrate->text().trimmed().toDouble();
}
if(product->TaxID == 0) 
product->TaxID = tax->getKey();
if(information->text().trimmed().isEmpty()){
errors = true;
errorString += "information Can't be Empty! \n";
information->setObjectName("error");
information->style()->unpolish(information);
information->style()->polish(information);
information->update();
}
else { 
information->setObjectName("information");
information->style()->unpolish(information);
information->style()->polish(information);
information->update();
product->information = information->text().trimmed();
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
if(product->ProductCategoryID == 0) 
product->ProductCategoryID = productcategory->getKey();
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
for(int j = 0; j < ProductFieldDatas.length(); j++){
ProductFieldDatas.at(j)->value->setObjectName("value");
ProductFieldDatas.at(j)->value->style()->unpolish(ProductFieldDatas.at(j)->value);
ProductFieldDatas.at(j)->value->style()->polish(ProductFieldDatas.at(j)->value);
ProductFieldDatas.at(j)->value->update();
for(int w = 0; w < ProductFieldDatas.length(); w++){
if(ProductFieldDatas.at(j) != ProductFieldDatas.at(w))
if(ProductFieldDatas.at(j)->value->text() == ProductFieldDatas.at(w)->value->text()){
errors = true; 
 errorString += "ProductFieldData has the same value \n";
ProductFieldDatas.at(j)->value->setObjectName("error");
ProductFieldDatas.at(j)->value->style()->unpolish(ProductFieldDatas.at(j)->value);
ProductFieldDatas.at(j)->value->style()->polish(ProductFieldDatas.at(j)->value);
ProductFieldDatas.at(j)->value->update();
}}}
if(!errors) {
product->save();
for(int i = 0; i < ProductFieldDatas.length(); i++){
ProductFieldDatas.at(i)->productfielddata->ProductID= product->ProductID;
if(!ProductFieldDatas.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < product->productfielddatas.length(); i++){
bool flag = false;
for(int j = 0; j < ProductFieldDatas.length(); j++){
if(product->productfielddatas.at(i)->ProductFieldDataID == ProductFieldDatas.at(j)->productfielddata->ProductFieldDataID){
flag = true;}}
if(!flag){
product->productfielddatas.at(i)->remove();}
}
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
