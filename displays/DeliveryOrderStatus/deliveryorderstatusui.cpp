/**************************************************************************
**   File: deliveryorderstatusui.cpp
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderstatusui.h"
#include "../Login/loginui.h"
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
block0Layout->addRow(QObject::tr("Description"),description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* DeliveryOrderStatusUI::p_instance = 0;
void DeliveryOrderStatusUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->DeliveryOrderStatus) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderStatusUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
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
errorString += QObject::tr("Description Can't be Empty! \n");
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
else{ QMessageBox::warning(this, QObject::tr("DeliveryOrderStatus"),errorString.trimmed());
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
errorString += QObject::tr("Description Can't be Empty! \n");
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
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("DeliveryOrderStatus"),errorString.trimmed());
return false; 
 }
}
