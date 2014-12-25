/**************************************************************************
**   File: purchasestoreproductui.cpp
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchasestoreproductui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

PurchaseStoreProductUI::PurchaseStoreProductUI(QWidget *parent) :ERPDisplay(parent)
{

purchasestoreproduct = new PurchaseStoreProduct();
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
purchase = new ERPComboBox();
purchase->addItems(Purchase::GetPairList());
block0Layout->addRow(QObject::tr("Purchase"),purchase);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList((Contact::QuerySelect("ContactTypeID = 2"))));
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
ERPDisplay* PurchaseStoreProductUI::p_instance = 0;
void PurchaseStoreProductUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->PurchaseStoreProduct)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new PurchaseStoreProductUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
PurchaseStoreProductUI*PurchaseStoreProductUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (PurchaseStoreProductUI*) p_instance;
}
void PurchaseStoreProductUI::fill(PurchaseStoreProduct* purchasestoreproduct){
clear();
this->purchasestoreproduct = purchasestoreproduct;
store->setIndexByKey(purchasestoreproduct->StoreID);
purchase->setIndexByKey(purchasestoreproduct->PurchaseID);
contact->setIndexByKey(purchasestoreproduct->ContactID);
product->setIndexByKey(purchasestoreproduct->ProductID);
amount->setText(QString::number(purchasestoreproduct->Amount));
price->setText(QString::number(purchasestoreproduct->Price));
}
void PurchaseStoreProductUI::clear(){
delete this->purchasestoreproduct;
amount->setText("");
price->setText("");
this->purchasestoreproduct = new PurchaseStoreProduct();
}
void PurchaseStoreProductUI::selectPurchaseStoreProduct(){
if(PurchaseStoreProduct::GetStringList().contains(QString::number(this->purchasestoreproduct->StoreID)))
{
PurchaseStoreProduct* con = PurchaseStoreProduct::Get(QString::number(this->purchasestoreproduct->StoreID));
if(this->purchasestoreproduct->PurchaseStoreProductID != con->PurchaseStoreProductID){
fill(con);
}
}
else if(purchasestoreproduct->PurchaseStoreProductID != 0)
clear();
}
bool PurchaseStoreProductUI::save(){
bool errors = false;
QString errorString =  "";
if(!store->isHidden())
purchasestoreproduct->StoreID = store->getKey();
if(!purchase->isHidden())
purchasestoreproduct->PurchaseID = purchase->getKey();
if(!contact->isHidden())
purchasestoreproduct->ContactID = contact->getKey();
if(!product->isHidden())
purchasestoreproduct->ProductID = product->getKey();
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
purchasestoreproduct->Amount = amount->text().trimmed().toDouble();
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
purchasestoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors) {
purchasestoreproduct->save();
if(!errors){
PurchaseStoreProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("PurchaseStoreProduct"),errorString.trimmed());
return false;
 }
}
void PurchaseStoreProductUI::cancel(){
PurchaseStoreProductIndexUI::ShowUI();
}
bool PurchaseStoreProductUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(purchasestoreproduct->StoreID == 0)
purchasestoreproduct->StoreID = store->getKey();
if(purchasestoreproduct->PurchaseID == 0)
purchasestoreproduct->PurchaseID = purchase->getKey();
if(purchasestoreproduct->ContactID == 0)
purchasestoreproduct->ContactID = contact->getKey();
if(purchasestoreproduct->ProductID == 0)
purchasestoreproduct->ProductID = product->getKey();
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
purchasestoreproduct->Amount = amount->text().trimmed().toDouble();
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
purchasestoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("PurchaseStoreProduct"),errorString.trimmed());
return false;
 }
}
void PurchaseStoreProductUI::updateTotal(QString){

	double tot = ((amount->text().toDouble()) * (price->text().toDouble()));
	total->setText(QString::number(tot,'f',2));
}
