/**************************************************************************
**   File: purchasestoreproductui.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchasestoreproductui.h"
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
block0Layout->addRow("Store",store);
purchase = new ERPComboBox();
purchase->addItems(Purchase::GetPairList());
block0Layout->addRow("Purchase",purchase);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow("Contact",contact);
product = new ERPComboBox();
product->addItems(Product::GetPairList());
block0Layout->addRow("Product",product);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow("Amount",amount);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* PurchaseStoreProductUI::p_instance = 0;
void PurchaseStoreProductUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new PurchaseStoreProductUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
PurchaseStoreProductUI*PurchaseStoreProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PurchaseStoreProductUI*) p_instance; 
}
void PurchaseStoreProductUI::fill(PurchaseStoreProduct* purchasestoreproduct){ 
clear();
this->purchasestoreproduct = purchasestoreproduct;
amount->setText(QString::number(purchasestoreproduct->Amount));
} 
void PurchaseStoreProductUI::clear(){ 
delete this->purchasestoreproduct;
amount->setText("");
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
errorString += "Amount Can't be Empty! \n";
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
if(!errors) {
purchasestoreproduct->save();
if(!errors){
PurchaseStoreProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "PurchaseStoreProduct",errorString.trimmed());
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
errorString += "Amount Can't be Empty! \n";
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
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "PurchaseStoreProduct",errorString.trimmed());
return false; 
 }
}
