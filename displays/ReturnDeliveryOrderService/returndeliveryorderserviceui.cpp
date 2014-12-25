/**************************************************************************
**   File: returndeliveryorderserviceui.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "returndeliveryorderserviceui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ReturnDeliveryOrderServiceUI::ReturnDeliveryOrderServiceUI(QWidget *parent) :ERPDisplay(parent)
{

returndeliveryorderservice = new ReturnDeliveryOrderService();
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
service = new ERPComboBox();
service->addItems(Service::GetPairList());
block0Layout->addRow(QObject::tr("Service"),service);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Amount"),amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Price"),price);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ReturnDeliveryOrderServiceUI::p_instance = 0;
void ReturnDeliveryOrderServiceUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ReturnDeliveryOrderService) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ReturnDeliveryOrderServiceUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ReturnDeliveryOrderServiceUI*ReturnDeliveryOrderServiceUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ReturnDeliveryOrderServiceUI*) p_instance; 
}
void ReturnDeliveryOrderServiceUI::fill(ReturnDeliveryOrderService* returndeliveryorderservice){ 
clear();
this->returndeliveryorderservice = returndeliveryorderservice;
returndeliveryorder->setIndexByKey(returndeliveryorderservice->ReturnDeliveryOrderID);
service->setIndexByKey(returndeliveryorderservice->ServiceID);
amount->setText(QString::number(returndeliveryorderservice->Amount));
price->setText(QString::number(returndeliveryorderservice->Price));
} 
void ReturnDeliveryOrderServiceUI::clear(){ 
delete this->returndeliveryorderservice;
amount->setText("");
price->setText("");
this->returndeliveryorderservice = new ReturnDeliveryOrderService();
} 
void ReturnDeliveryOrderServiceUI::selectReturnDeliveryOrderService(){ 
if(ReturnDeliveryOrderService::GetStringList().contains(QString::number(this->returndeliveryorderservice->ReturnDeliveryOrderID)))
{
ReturnDeliveryOrderService* con = ReturnDeliveryOrderService::Get(QString::number(this->returndeliveryorderservice->ReturnDeliveryOrderID));
if(this->returndeliveryorderservice->ReturnDeliveryOrderServiceID != con->ReturnDeliveryOrderServiceID){
fill(con);
}
}
else if(returndeliveryorderservice->ReturnDeliveryOrderServiceID != 0)
clear();
}
bool ReturnDeliveryOrderServiceUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!returndeliveryorder->isHidden()) 
returndeliveryorderservice->ReturnDeliveryOrderID = returndeliveryorder->getKey();
if(!service->isHidden()) 
returndeliveryorderservice->ServiceID = service->getKey();
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
returndeliveryorderservice->Amount = amount->text().trimmed().toDouble();
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
returndeliveryorderservice->Price = price->text().trimmed().toDouble();
}
if(!errors) {
returndeliveryorderservice->save();
if(!errors){
ReturnDeliveryOrderServiceIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrderService"),errorString.trimmed());
return false; 
 }
}
void ReturnDeliveryOrderServiceUI::cancel(){ 
ReturnDeliveryOrderServiceIndexUI::ShowUI();
}
bool ReturnDeliveryOrderServiceUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(returndeliveryorderservice->ReturnDeliveryOrderID == 0) 
returndeliveryorderservice->ReturnDeliveryOrderID = returndeliveryorder->getKey();
if(returndeliveryorderservice->ServiceID == 0) 
returndeliveryorderservice->ServiceID = service->getKey();
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
returndeliveryorderservice->Amount = amount->text().trimmed().toDouble();
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
returndeliveryorderservice->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrderService"),errorString.trimmed());
return false; 
 }
}
