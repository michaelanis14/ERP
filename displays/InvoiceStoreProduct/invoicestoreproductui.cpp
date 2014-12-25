/**************************************************************************
**   File: invoicestoreproductui.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoicestoreproductui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

InvoiceStoreProductUI::InvoiceStoreProductUI(QWidget *parent) :ERPDisplay(parent)
{

invoicestoreproduct = new InvoiceStoreProduct();
flowLayout = new FlowLayout(this);
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
invoice = new ERPComboBox();
invoice->addItems(Invoice::GetPairList());
block0Layout->addRow(QObject::tr("Invoice"),invoice);
store = new ERPComboBox();
store->addItems(Store::GetPairList());
block0Layout->addRow(QObject::tr("Store"),store);
product = new ERPComboBox();
product->addItems(Product::GetPairList());
block0Layout->addRow(QObject::tr("Product"),product);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Amount"),amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Price"),price);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* InvoiceStoreProductUI::p_instance = 0;
void InvoiceStoreProductUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Invoice)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new InvoiceStoreProductUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
InvoiceStoreProductUI*InvoiceStoreProductUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (InvoiceStoreProductUI*) p_instance;
}
void InvoiceStoreProductUI::fill(InvoiceStoreProduct* invoicestoreproduct){
clear();
this->invoicestoreproduct = invoicestoreproduct;
invoice->setIndexByKey(invoicestoreproduct->InvoiceID);
store->setIndexByKey(invoicestoreproduct->StoreID);
product->setIndexByKey(invoicestoreproduct->ProductID);
amount->setText(QString::number(invoicestoreproduct->Amount));
price->setText(QString::number(invoicestoreproduct->Price));
}
void InvoiceStoreProductUI::clear(){
delete this->invoicestoreproduct;
amount->setText("");
price->setText("");
this->invoicestoreproduct = new InvoiceStoreProduct();
}
void InvoiceStoreProductUI::selectInvoiceStoreProduct(){
if(InvoiceStoreProduct::GetStringList().contains(QString::number(this->invoicestoreproduct->InvoiceID)))
{
InvoiceStoreProduct* con = InvoiceStoreProduct::Get(QString::number(this->invoicestoreproduct->InvoiceID));
if(this->invoicestoreproduct->InvoiceStoreProductID != con->InvoiceStoreProductID){
fill(con);
}
}
else if(invoicestoreproduct->InvoiceStoreProductID != 0)
clear();
}
bool InvoiceStoreProductUI::save(){
bool errors = false;
QString errorString =  "";
if(!invoice->isHidden())
invoicestoreproduct->InvoiceID = invoice->getKey();
if(!store->isHidden())
invoicestoreproduct->StoreID = store->getKey();
if(!product->isHidden())
invoicestoreproduct->ProductID = product->getKey();
if(amount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Amount Can't be Empty! \n");
amount->setObjectName("error");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
}
else {
amount->setObjectName("amount");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
invoicestoreproduct->Amount = amount->text().trimmed().toDouble();
}
if(price->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Price Can't be Empty! \n");
price->setObjectName("error");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
}
else {
price->setObjectName("price");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
invoicestoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors) {
invoicestoreproduct->save();
if(!errors){
InvoiceStoreProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("InvoiceStoreProduct"),errorString.trimmed());
return false;
 }
}
void InvoiceStoreProductUI::cancel(){
InvoiceStoreProductIndexUI::ShowUI();
}
bool InvoiceStoreProductUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(invoicestoreproduct->InvoiceID == 0)
invoicestoreproduct->InvoiceID = invoice->getKey();
if(invoicestoreproduct->StoreID == 0)
invoicestoreproduct->StoreID = store->getKey();
if(invoicestoreproduct->ProductID == 0)
invoicestoreproduct->ProductID = product->getKey();
if(amount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Amount Can't be Empty! \n");
amount->setObjectName("error");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
}
else {
amount->setObjectName("amount");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
invoicestoreproduct->Amount = amount->text().trimmed().toDouble();
}
if(price->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Price Can't be Empty! \n");
price->setObjectName("error");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
}
else {
price->setObjectName("price");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
invoicestoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("InvoiceStoreProduct"),errorString.trimmed());
return false;
 }
}
