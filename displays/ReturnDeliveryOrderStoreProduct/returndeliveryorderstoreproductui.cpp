/**************************************************************************
**   File: returndeliveryorderstoreproductui.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "returndeliveryorderstoreproductui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ReturnDeliveryOrderStoreProductUI::ReturnDeliveryOrderStoreProductUI(QWidget *parent) :ERPDisplay(parent)
{

returndeliveryorderstoreproduct = new ReturnDeliveryOrderStoreProduct();
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
returndeliveryorder = new ERPComboBox();
returndeliveryorder->addItems(ReturnDeliveryOrder::GetPairList());
block0Layout->addRow(QObject::tr("Return Delivery Order"),returndeliveryorder);
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
ERPDisplay* ReturnDeliveryOrderStoreProductUI::p_instance = 0;
void ReturnDeliveryOrderStoreProductUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ReturnDeliveryOrderStoreProduct) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ReturnDeliveryOrderStoreProductUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ReturnDeliveryOrderStoreProductUI*ReturnDeliveryOrderStoreProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ReturnDeliveryOrderStoreProductUI*) p_instance; 
}
void ReturnDeliveryOrderStoreProductUI::fill(ReturnDeliveryOrderStoreProduct* returndeliveryorderstoreproduct){ 
clear();
this->returndeliveryorderstoreproduct = returndeliveryorderstoreproduct;
returndeliveryorder->setIndexByKey(returndeliveryorderstoreproduct->ReturnDeliveryOrderID);
store->setIndexByKey(returndeliveryorderstoreproduct->StoreID);
product->setIndexByKey(returndeliveryorderstoreproduct->ProductID);
amount->setText(QString::number(returndeliveryorderstoreproduct->Amount));
price->setText(QString::number(returndeliveryorderstoreproduct->Price));
} 
void ReturnDeliveryOrderStoreProductUI::clear(){ 
delete this->returndeliveryorderstoreproduct;
amount->setText("");
price->setText("");
this->returndeliveryorderstoreproduct = new ReturnDeliveryOrderStoreProduct();
} 
void ReturnDeliveryOrderStoreProductUI::selectReturnDeliveryOrderStoreProduct(){ 
if(ReturnDeliveryOrderStoreProduct::GetStringList().contains(QString::number(this->returndeliveryorderstoreproduct->ReturnDeliveryOrderID)))
{
ReturnDeliveryOrderStoreProduct* con = ReturnDeliveryOrderStoreProduct::Get(QString::number(this->returndeliveryorderstoreproduct->ReturnDeliveryOrderID));
if(this->returndeliveryorderstoreproduct->ReturnDeliveryOrderStoreProductID != con->ReturnDeliveryOrderStoreProductID){
fill(con);
}
}
else if(returndeliveryorderstoreproduct->ReturnDeliveryOrderStoreProductID != 0)
clear();
}
bool ReturnDeliveryOrderStoreProductUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!returndeliveryorder->isHidden()) 
returndeliveryorderstoreproduct->ReturnDeliveryOrderID = returndeliveryorder->getKey();
if(!store->isHidden()) 
returndeliveryorderstoreproduct->StoreID = store->getKey();
if(!product->isHidden()) 
returndeliveryorderstoreproduct->ProductID = product->getKey();
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
returndeliveryorderstoreproduct->Amount = amount->text().trimmed().toDouble();
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
returndeliveryorderstoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors) {
returndeliveryorderstoreproduct->save();
if(!errors){
ReturnDeliveryOrderStoreProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrderStoreProduct"),errorString.trimmed());
return false; 
 }
}
void ReturnDeliveryOrderStoreProductUI::cancel(){ 
ReturnDeliveryOrderStoreProductIndexUI::ShowUI();
}
bool ReturnDeliveryOrderStoreProductUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(returndeliveryorderstoreproduct->ReturnDeliveryOrderID == 0) 
returndeliveryorderstoreproduct->ReturnDeliveryOrderID = returndeliveryorder->getKey();
if(returndeliveryorderstoreproduct->StoreID == 0) 
returndeliveryorderstoreproduct->StoreID = store->getKey();
if(returndeliveryorderstoreproduct->ProductID == 0) 
returndeliveryorderstoreproduct->ProductID = product->getKey();
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
returndeliveryorderstoreproduct->Amount = amount->text().trimmed().toDouble();
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
returndeliveryorderstoreproduct->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrderStoreProduct"),errorString.trimmed());
return false; 
 }
}
