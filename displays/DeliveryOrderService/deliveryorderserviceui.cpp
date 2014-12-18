/**************************************************************************
**   File: deliveryorderserviceui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderserviceui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

DeliveryOrderServiceUI::DeliveryOrderServiceUI(QWidget *parent) :ERPDisplay(parent)
{

deliveryorderservice = new DeliveryOrderService();
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
service = new ERPComboBox();
service->addItems(Service::GetPairList());
block0Layout->addRow(QObject::tr("Service"),service);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Amount"),amount);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* DeliveryOrderServiceUI::p_instance = 0;
void DeliveryOrderServiceUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->DeliveryOrderService) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderServiceUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
DeliveryOrderServiceUI*DeliveryOrderServiceUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderServiceUI*) p_instance; 
}
void DeliveryOrderServiceUI::fill(DeliveryOrderService* deliveryorderservice){ 
clear();
this->deliveryorderservice = deliveryorderservice;
deliveryorder->setIndexByKey(deliveryorderservice->DeliveryOrderID);
service->setIndexByKey(deliveryorderservice->ServiceID);
amount->setText(QString::number(deliveryorderservice->Amount));
} 
void DeliveryOrderServiceUI::clear(){ 
delete this->deliveryorderservice;
amount->setText("");
this->deliveryorderservice = new DeliveryOrderService();
} 
void DeliveryOrderServiceUI::selectDeliveryOrderService(){ 
if(DeliveryOrderService::GetStringList().contains(QString::number(this->deliveryorderservice->DeliveryOrderID)))
{
DeliveryOrderService* con = DeliveryOrderService::Get(QString::number(this->deliveryorderservice->DeliveryOrderID));
if(this->deliveryorderservice->DeliveryOrderServiceID != con->DeliveryOrderServiceID){
fill(con);
}
}
else if(deliveryorderservice->DeliveryOrderServiceID != 0)
clear();
}
bool DeliveryOrderServiceUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!deliveryorder->isHidden()) 
deliveryorderservice->DeliveryOrderID = deliveryorder->getKey();
if(!service->isHidden()) 
deliveryorderservice->ServiceID = service->getKey();
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
deliveryorderservice->Amount = amount->text().trimmed().toDouble();
}
if(!errors) {
deliveryorderservice->save();
if(!errors){
DeliveryOrderServiceIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("DeliveryOrderService"),errorString.trimmed());
return false; 
 }
}
void DeliveryOrderServiceUI::cancel(){ 
DeliveryOrderServiceIndexUI::ShowUI();
}
bool DeliveryOrderServiceUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(deliveryorderservice->DeliveryOrderID == 0) 
deliveryorderservice->DeliveryOrderID = deliveryorder->getKey();
if(deliveryorderservice->ServiceID == 0) 
deliveryorderservice->ServiceID = service->getKey();
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
deliveryorderservice->Amount = amount->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("DeliveryOrderService"),errorString.trimmed());
return false; 
 }
}
