/**************************************************************************
**   File: deliveryorderstoreproductui.cpp
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderstoreproductui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

DeliveryOrderStoreProductUI::DeliveryOrderStoreProductUI(QWidget *parent) :ERPDisplay(parent)
{

deliveryorderstoreproduct = new DeliveryOrderStoreProduct();
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
deliveryorder = new ERPComboBox();
deliveryorder->addItems(DeliveryOrder::GetPairList());
block0Layout->addRow(QObject::tr("Delivery Order"),deliveryorder);
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
ERPDisplay* DeliveryOrderStoreProductUI::p_instance = 0;
void DeliveryOrderStoreProductUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->DeliveryOrderStoreProduct) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderStoreProductUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
DeliveryOrderStoreProductUI*DeliveryOrderStoreProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderStoreProductUI*) p_instance; 
}
void DeliveryOrderStoreProductUI::fill(DeliveryOrderStoreProduct* deliveryorderstoreproduct){ 
clear();
this->deliveryorderstoreproduct = deliveryorderstoreproduct;
deliveryorder->setIndexByKey(deliveryorderstoreproduct->DeliveryOrderID);
store->setIndexByKey(deliveryorderstoreproduct->StoreID);
product->setIndexByKey(deliveryorderstoreproduct->ProductID);
amount->setText(QString::number(deliveryorderstoreproduct->Amount));
price->setText(QString::number(deliveryorderstoreproduct->Price));
} 
void DeliveryOrderStoreProductUI::clear(){ 
delete this->deliveryorderstoreproduct;
amount->setText("");
price->setText("");
this->deliveryorderstoreproduct = new DeliveryOrderStoreProduct();
} 
void DeliveryOrderStoreProductUI::selectDeliveryOrderStoreProduct(){ 
if(DeliveryOrderStoreProduct::GetStringList().contains(QString::number(this->deliveryorderstoreproduct->DeliveryOrderID)))
{
DeliveryOrderStoreProduct* con = DeliveryOrderStoreProduct::Get(QString::number(this->deliveryorderstoreproduct->DeliveryOrderID));
if(this->deliveryorderstoreproduct->DeliveryOrderStoreProductID != con->DeliveryOrderStoreProductID){
fill(con);
}
}
else if(deliveryorderstoreproduct->DeliveryOrderStoreProductID != 0)
clear();
}
bool DeliveryOrderStoreProductUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!deliveryorder->isHidden()) 
deliveryorderstoreproduct->DeliveryOrderID = deliveryorder->getKey();
if(!store->isHidden()) 
deliveryorderstoreproduct->StoreID = store->getKey();
if(!product->isHidden()) 
deliveryorderstoreproduct->ProductID = product->getKey();
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
deliveryorderstoreproduct->Amount = amount->text().trimmed().toDouble();
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
deliveryorderstoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors) {
deliveryorderstoreproduct->save();
if(!errors){
DeliveryOrderStoreProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("DeliveryOrderStoreProduct"),errorString.trimmed());
return false; 
 }
}
void DeliveryOrderStoreProductUI::cancel(){ 
DeliveryOrderStoreProductIndexUI::ShowUI();
}
bool DeliveryOrderStoreProductUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(deliveryorderstoreproduct->DeliveryOrderID == 0) 
deliveryorderstoreproduct->DeliveryOrderID = deliveryorder->getKey();
if(deliveryorderstoreproduct->StoreID == 0) 
deliveryorderstoreproduct->StoreID = store->getKey();
if(deliveryorderstoreproduct->ProductID == 0) 
deliveryorderstoreproduct->ProductID = product->getKey();
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
deliveryorderstoreproduct->Amount = amount->text().trimmed().toDouble();
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
deliveryorderstoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("DeliveryOrderStoreProduct"),errorString.trimmed());
return false; 
 }
}
