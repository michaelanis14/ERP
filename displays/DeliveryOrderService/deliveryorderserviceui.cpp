/**************************************************************************
**   File: deliveryorderserviceui.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderserviceui.h"
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
title = new QLineEdit();
block0Layout->addRow("Title",title);
deliveryorder = new ERPComboBox();
deliveryorder->addItems(DeliveryOrder::GetHashList());
block0Layout->addRow("Delivery Order",deliveryorder);
service = new ERPComboBox();
service->addItems(Service::GetHashList());
block0Layout->addRow("Service",service);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow("Amount",amount);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* DeliveryOrderServiceUI::p_instance = 0;
void DeliveryOrderServiceUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderServiceUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
DeliveryOrderServiceUI*DeliveryOrderServiceUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderServiceUI*) p_instance; 
}
void DeliveryOrderServiceUI::fill(DeliveryOrderService* deliveryorderservice){ 
clear();
this->deliveryorderservice = deliveryorderservice;
title->setText(deliveryorderservice->Title);
amount->setText(QString::number(deliveryorderservice->Amount));
} 
void DeliveryOrderServiceUI::clear(){ 
delete this->deliveryorderservice;
title->setText("");
amount->setText("");
this->deliveryorderservice = new DeliveryOrderService();
} 
void DeliveryOrderServiceUI::selectDeliveryOrderService(){ 
if(DeliveryOrderService::GetStringList().contains(title->text()))
{
DeliveryOrderService* con = DeliveryOrderService::Get(title->text());
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
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += "Title Can't be Empty! \n";
title->setObjectName("error");
title->style()->unpolish(title);
title->style()->polish(title);
title->update();
}
else { 
title->setObjectName("title");
title->style()->unpolish(title);
title->style()->polish(title);
title->update();
deliveryorderservice->Title = title->text().trimmed();
}
if(deliveryorderservice->DeliveryOrderID == 0) 
deliveryorderservice->DeliveryOrderID = deliveryorder->getKey();
if(deliveryorderservice->ServiceID == 0) 
deliveryorderservice->ServiceID = service->getKey();
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
deliveryorderservice->Amount = amount->text().trimmed().toDouble();
}
if(!errors) {
deliveryorderservice->save();
if(!errors){
DeliveryOrderServiceIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "DeliveryOrderService",errorString.trimmed());
return false; 
 }
}
void DeliveryOrderServiceUI::cancel(){ 
DeliveryOrderServiceIndexUI::ShowUI();
}
