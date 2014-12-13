/**************************************************************************
**   File: deliveryorderstatusui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderstatusui.h"
#include "../MainWindow.h"

DeliveryOrderStatusUI::DeliveryOrderStatusUI(QWidget *parent) :ERPDisplay(parent)
{

deliveryorderstatus = new DeliveryOrderStatus();
flowLayout = new FlowLayout(this);
flowLayout->setContentsMargins(0,0,0,0);

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
description = new QLineEdit();
block0Layout->addRow("Description",description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* DeliveryOrderStatusUI::p_instance = 0;
void DeliveryOrderStatusUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderStatusUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
DeliveryOrderStatusUI*DeliveryOrderStatusUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderStatusUI*) p_instance; 
}
void DeliveryOrderStatusUI::fill(DeliveryOrderStatus* deliveryorderstatus){ 
clear();
this->deliveryorderstatus = deliveryorderstatus;
description->setText(deliveryorderstatus->Description);
} 
void DeliveryOrderStatusUI::clear(){ 
delete this->deliveryorderstatus;
description->setText("");
this->deliveryorderstatus = new DeliveryOrderStatus();
} 
void DeliveryOrderStatusUI::selectDeliveryOrderStatus(){ 
if(DeliveryOrderStatus::GetStringList().contains(this->deliveryorderstatus->Description))
{
DeliveryOrderStatus* con = DeliveryOrderStatus::Get(this->deliveryorderstatus->Description);
if(this->deliveryorderstatus->DeliveryOrderStatusID != con->DeliveryOrderStatusID){
fill(con);
}
}
else if(deliveryorderstatus->DeliveryOrderStatusID != 0)
clear();
}
bool DeliveryOrderStatusUI::save(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += "Description Can't be Empty! \n";
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else { 
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
deliveryorderstatus->Description = description->text().trimmed();
}
if(!errors) {
deliveryorderstatus->save();
if(!errors){
DeliveryOrderStatusIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "DeliveryOrderStatus",errorString.trimmed());
return false; 
 }
}
void DeliveryOrderStatusUI::cancel(){ 
DeliveryOrderStatusIndexUI::ShowUI();
}
bool DeliveryOrderStatusUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += "Description Can't be Empty! \n";
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else { 
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
deliveryorderstatus->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "DeliveryOrderStatus",errorString.trimmed());
return false; 
 }
}
