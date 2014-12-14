/**************************************************************************
**   File: productui.cpp
**   Created on: Sun Dec 14 22:39:13 EET 2014
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
block0Layout->addRow(QObject::tr("Name"),name);
shortdescription = new QLineEdit();
block0Layout->addRow(QObject::tr("Short Description"),shortdescription);
unit = new ERPComboBox();
unit->addItems(Unit::GetPairList());
block0Layout->addRow(QObject::tr("Unit"),unit);
sellingprice = new QLineEdit();
sellingprice->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Selling Price"),sellingprice);
netcoast = new QLineEdit();
netcoast->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Net Coast"),netcoast);
trademarginrate = new QLineEdit();
trademarginrate->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Trade Margin Rate"),trademarginrate);
tax = new ERPComboBox();
tax->addItems(Tax::GetPairList());
block0Layout->addRow(QObject::tr("Tax"),tax);
information = new QLineEdit();
block0Layout->addRow(QObject::tr("information"),information);
barcode = new QLineEdit();
QObject::connect(barcode, SIGNAL(textChanged(QString)), this, SLOT(barcodeChanged(QString)));
block0Layout->addRow(QObject::tr("Barcode"),barcode);
barcodeDisplay = new Barcode(0,0); block0Layout->addRow(QObject::tr("Barcode"),barcodeDisplay); generatebarcode = new QPushButton(QObject::tr("Generate Barcode")); QObject::connect(generatebarcode, SIGNAL(clicked()), this, SLOT(generateBarcode())); block0Layout->addRow("",generatebarcode);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block1Layout->setMinimumWidth(330);
productcategory = new ERPComboBox();
productcategory->addItems(ProductCategory::GetPairList());
block1Layout->addRow(QObject::tr("Product Category"),productcategory);
criticalamount = new QLineEdit();
criticalamount->setValidator( doubleValidator );
block1Layout->addRow(QObject::tr("Critical Amount"),criticalamount);
flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block2Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveProductImageButtons = new AddRemoveButtons();
block2Layout->addRow("ProductImages",addremoveProductImageButtons);
QObject::connect(addremoveProductImageButtons, SIGNAL(addPressed()), this, SLOT(addProductImage()));

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
void ProductUI::addProductImage(){ 
ProductImageUI* productimageui = new ProductImageUI();
productimageui->block0Layout->hideRow(productimageui->product);
productimageui->controllers->setFixedHeight(0);
ProductImages.append(productimageui);
RemovebtnWidgets* rmproductimage = new RemovebtnWidgets(0,productimageui);
QObject::connect(rmproductimage, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProductImage(QWidget*)));
block2Layout->addRow(QObject::tr("ProductImage")+QString::number(ProductImages.count()),rmproductimage);
}
void ProductUI::addProductImage(ProductImage* ProductImage){ 
ProductImageUI* productimageui = new ProductImageUI();
productimageui->block0Layout->hideRow(productimageui->product);
productimageui->controllers->setFixedHeight(0);
productimageui->fill(ProductImage);
ProductImages.append(productimageui);
RemovebtnWidgets* rmproductimage = new RemovebtnWidgets(0,productimageui);
QObject::connect(rmproductimage, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProductImage(QWidget*)));
block2Layout->addRow(QObject::tr("ProductImage") +QString::number(ProductImages.count()),rmproductimage);
}
void ProductUI::removeProductImage(QWidget* widget){ 
if(ProductImages.count()  > 0){
ProductImageUI* productimageui = (ProductImageUI*) widget;
ProductImages.removeOne(productimageui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block2Layout->removeRow(sender);
}
}
void ProductUI::fill(Product* product){ 
clear();
this->product = product;
name->setText(product->Name);
shortdescription->setText(product->ShortDescription);
unit->setIndexByKey(product->UnitID);
sellingprice->setText(QString::number(product->SellingPrice));
netcoast->setText(QString::number(product->NetCoast));
trademarginrate->setText(QString::number(product->TradeMarginRate));
tax->setIndexByKey(product->TaxID);
information->setText(product->information);
barcode->setText(product->Barcode);
productcategory->setIndexByKey(product->ProductCategoryID);
criticalamount->setText(QString::number(product->CriticalAmount));
foreach(ProductImage* productimage, product->productimages) {
addProductImage(productimage);
}
} 
void ProductUI::clear(){ 
delete this->product;
this->ProductImages.clear();
shortdescription->setText("");
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
if(Product::GetStringList().contains(this->product->Name))
{
Product* con = Product::Get(this->product->Name);
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
errorString += QObject::tr("Name Can't be Empty! \n");
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
if(shortdescription->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Short Description Can't be Empty! \n");
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
if(!unit->isHidden()) 
product->UnitID = unit->getKey();
if(sellingprice->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Selling Price Can't be Empty! \n");
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
errorString += QObject::tr("Net Coast Can't be Empty! \n");
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
errorString += QObject::tr("Trade Margin Rate Can't be Empty! \n");
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
if(!tax->isHidden()) 
product->TaxID = tax->getKey();
if(information->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("information Can't be Empty! \n");
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
errorString += QObject::tr("Barcode Can't be Empty! \n");
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
if(!productcategory->isHidden()) 
product->ProductCategoryID = productcategory->getKey();
if(criticalamount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Critical Amount Can't be Empty! \n");
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
for(int j = 0; j < ProductImages.length(); j++){
ProductImages.at(j)->name->setObjectName("name");
ProductImages.at(j)->name->style()->unpolish(ProductImages.at(j)->name);
ProductImages.at(j)->name->style()->polish(ProductImages.at(j)->name);
ProductImages.at(j)->name->update();
for(int w = 0; w < ProductImages.length(); w++){
if(ProductImages.at(j) != ProductImages.at(w))
if(ProductImages.at(j)->name->text() == ProductImages.at(w)->name->text()){
errors = true; 
 errorString += QObject::tr("ProductImage has the same name \n");
ProductImages.at(j)->name->setObjectName("error");
ProductImages.at(j)->name->style()->unpolish(ProductImages.at(j)->name);
ProductImages.at(j)->name->style()->polish(ProductImages.at(j)->name);
ProductImages.at(j)->name->update();
}}}
if(!errors) {
product->save();
for(int i = 0; i < ProductImages.length(); i++){
ProductImages.at(i)->productimage->ProductID= product->ProductID;
if(!ProductImages.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < product->productimages.length(); i++){
bool flag = false;
for(int j = 0; j < ProductImages.length(); j++){
if(product->productimages.at(i)->ProductImageID == ProductImages.at(j)->productimage->ProductImageID){
flag = true;}}
if(!flag){
product->productimages.at(i)->remove();}
}
if(!errors){
ProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("Product"),errorString.trimmed());
return false; 
 }
}
void ProductUI::cancel(){ 
ProductIndexUI::ShowUI();
}
bool ProductUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
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
if(shortdescription->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Short Description Can't be Empty! \n");
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
if(sellingprice->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Selling Price Can't be Empty! \n");
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
errorString += QObject::tr("Net Coast Can't be Empty! \n");
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
errorString += QObject::tr("Trade Margin Rate Can't be Empty! \n");
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
errorString += QObject::tr("information Can't be Empty! \n");
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
errorString += QObject::tr("Barcode Can't be Empty! \n");
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
errorString += QObject::tr("Critical Amount Can't be Empty! \n");
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
for(int j = 0; j < ProductImages.length(); j++){
ProductImages.at(j)->name->setObjectName("name");
ProductImages.at(j)->name->style()->unpolish(ProductImages.at(j)->name);
ProductImages.at(j)->name->style()->polish(ProductImages.at(j)->name);
ProductImages.at(j)->name->update();
for(int w = 0; w < ProductImages.length(); w++){
if(ProductImages.at(j) != ProductImages.at(w))
if(ProductImages.at(j)->name->text() == ProductImages.at(w)->name->text()){
errors = true; 
 errorString +=QObject::tr( "ProductImage has the same name \n");
ProductImages.at(j)->name->setObjectName("error");
ProductImages.at(j)->name->style()->unpolish(ProductImages.at(j)->name);
ProductImages.at(j)->name->style()->polish(ProductImages.at(j)->name);
ProductImages.at(j)->name->update();
}}}
for(int i = 0; i < ProductImages.length(); i++){
ProductImages.at(i)->productimage->ProductID= product->ProductID;
if(!ProductImages.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Product"),errorString.trimmed());
return false; 
 }
}
