/**************************************************************************
**   File: returnpurchasestoreproductui.cpp
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "returnpurchasestoreproductui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ReturnPurchaseStoreProductUI::ReturnPurchaseStoreProductUI(QWidget *parent) :ERPDisplay(parent)
{

returnpurchasestoreproduct = new ReturnPurchaseStoreProduct();
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
store = new ERPComboBox();
store->addItems(Store::GetPairList());
block0Layout->addRow(QObject::tr("Store"),store);
returnpurchase = new ERPComboBox();
returnpurchase->addItems(ReturnPurchase::GetPairList());
block0Layout->addRow(QObject::tr("Return Purchase"),returnpurchase);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
product = new ERPComboBox();
product->addItems(Product::GetPairList());
block0Layout->addRow(QObject::tr("Product"),product);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
connect(amount, SIGNAL(textChanged(QString)), this, SLOT(updateTotal(QString)));

block0Layout->addRow(QObject::tr("Amount"),amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
connect(price, SIGNAL(textChanged(QString)), this, SLOT(updateTotal(QString)));

block0Layout->addRow(QObject::tr("Price Per Piece"),price);
total = new QLineEdit();
total->setEnabled(false);
total->setValidator( doubleValidator );
updateTotal("QString");
block0Layout->addRow(QObject::tr("Total"),total);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ReturnPurchaseStoreProductUI::p_instance = 0;
void ReturnPurchaseStoreProductUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ReturnPurchaseStoreProduct)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new ReturnPurchaseStoreProductUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ReturnPurchaseStoreProductUI*ReturnPurchaseStoreProductUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (ReturnPurchaseStoreProductUI*) p_instance;
}
void ReturnPurchaseStoreProductUI::fill(ReturnPurchaseStoreProduct* returnpurchasestoreproduct){
clear();
this->returnpurchasestoreproduct = returnpurchasestoreproduct;
store->setIndexByKey(returnpurchasestoreproduct->StoreID);
returnpurchase->setIndexByKey(returnpurchasestoreproduct->ReturnPurchaseID);
contact->setIndexByKey(returnpurchasestoreproduct->ContactID);
product->setIndexByKey(returnpurchasestoreproduct->ProductID);
amount->setText(QString::number(returnpurchasestoreproduct->Amount));
price->setText(QString::number(returnpurchasestoreproduct->Price));
}
void ReturnPurchaseStoreProductUI::clear(){
delete this->returnpurchasestoreproduct;
amount->setText("");
price->setText("");
this->returnpurchasestoreproduct = new ReturnPurchaseStoreProduct();
}
void ReturnPurchaseStoreProductUI::selectReturnPurchaseStoreProduct(){
if(ReturnPurchaseStoreProduct::GetStringList().contains(QString::number(this->returnpurchasestoreproduct->StoreID)))
{
ReturnPurchaseStoreProduct* con = ReturnPurchaseStoreProduct::Get(QString::number(this->returnpurchasestoreproduct->StoreID));
if(this->returnpurchasestoreproduct->ReturnPurchaseStoreProductID != con->ReturnPurchaseStoreProductID){
fill(con);
}
}
else if(returnpurchasestoreproduct->ReturnPurchaseStoreProductID != 0)
clear();
}
bool ReturnPurchaseStoreProductUI::save(){
bool errors = false;
QString errorString =  "";
if(!store->isHidden())
returnpurchasestoreproduct->StoreID = store->getKey();
if(!returnpurchase->isHidden())
returnpurchasestoreproduct->ReturnPurchaseID = returnpurchase->getKey();
if(!contact->isHidden())
returnpurchasestoreproduct->ContactID = contact->getKey();
if(!product->isHidden())
returnpurchasestoreproduct->ProductID = product->getKey();
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
returnpurchasestoreproduct->Amount = amount->text().trimmed().toDouble();
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
returnpurchasestoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors) {
returnpurchasestoreproduct->save();
if(!errors){
ReturnPurchaseStoreProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ReturnPurchaseStoreProduct"),errorString.trimmed());
return false;
 }
}
void ReturnPurchaseStoreProductUI::cancel(){
ReturnPurchaseStoreProductIndexUI::ShowUI();
}
bool ReturnPurchaseStoreProductUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(returnpurchasestoreproduct->StoreID == 0)
returnpurchasestoreproduct->StoreID = store->getKey();
if(returnpurchasestoreproduct->ReturnPurchaseID == 0)
returnpurchasestoreproduct->ReturnPurchaseID = returnpurchase->getKey();
if(returnpurchasestoreproduct->ContactID == 0)
returnpurchasestoreproduct->ContactID = contact->getKey();
if(returnpurchasestoreproduct->ProductID == 0)
returnpurchasestoreproduct->ProductID = product->getKey();
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
returnpurchasestoreproduct->Amount = amount->text().trimmed().toDouble();
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
returnpurchasestoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ReturnPurchaseStoreProduct"),errorString.trimmed());
return false;
 }
}
void ReturnPurchaseStoreProductUI::updateTotal(QString){

	double tot = ((amount->text().toDouble()) * (price->text().toDouble()));
	total->setText(QString::number(tot,'f',2));
}
