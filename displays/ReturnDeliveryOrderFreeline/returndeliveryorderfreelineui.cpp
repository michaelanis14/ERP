/**************************************************************************
**   File: returndeliveryorderfreelineui.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "returndeliveryorderfreelineui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ReturnDeliveryOrderFreelineUI::ReturnDeliveryOrderFreelineUI(QWidget *parent) :ERPDisplay(parent)
{

returndeliveryorderfreeline = new ReturnDeliveryOrderFreeline();
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
description = new QLineEdit();
block0Layout->addRow(QObject::tr("Description"),description);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Amount"),amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Price"),price);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ReturnDeliveryOrderFreelineUI::p_instance = 0;
void ReturnDeliveryOrderFreelineUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ReturnDeliveryOrderFreeline) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ReturnDeliveryOrderFreelineUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ReturnDeliveryOrderFreelineUI*ReturnDeliveryOrderFreelineUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ReturnDeliveryOrderFreelineUI*) p_instance; 
}
void ReturnDeliveryOrderFreelineUI::fill(ReturnDeliveryOrderFreeline* returndeliveryorderfreeline){ 
clear();
this->returndeliveryorderfreeline = returndeliveryorderfreeline;
returndeliveryorder->setIndexByKey(returndeliveryorderfreeline->ReturnDeliveryOrderID);
description->setText(returndeliveryorderfreeline->Description);
amount->setText(QString::number(returndeliveryorderfreeline->Amount));
price->setText(QString::number(returndeliveryorderfreeline->Price));
} 
void ReturnDeliveryOrderFreelineUI::clear(){ 
delete this->returndeliveryorderfreeline;
description->setText("");
amount->setText("");
price->setText("");
this->returndeliveryorderfreeline = new ReturnDeliveryOrderFreeline();
} 
void ReturnDeliveryOrderFreelineUI::selectReturnDeliveryOrderFreeline(){ 
if(ReturnDeliveryOrderFreeline::GetStringList().contains(QString::number(this->returndeliveryorderfreeline->ReturnDeliveryOrderID)))
{
ReturnDeliveryOrderFreeline* con = ReturnDeliveryOrderFreeline::Get(QString::number(this->returndeliveryorderfreeline->ReturnDeliveryOrderID));
if(this->returndeliveryorderfreeline->ReturnDeliveryOrderFreelineID != con->ReturnDeliveryOrderFreelineID){
fill(con);
}
}
else if(returndeliveryorderfreeline->ReturnDeliveryOrderFreelineID != 0)
clear();
}
bool ReturnDeliveryOrderFreelineUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!returndeliveryorder->isHidden()) 
returndeliveryorderfreeline->ReturnDeliveryOrderID = returndeliveryorder->getKey();
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
returndeliveryorderfreeline->Description = description->text().trimmed();
}
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
returndeliveryorderfreeline->Amount = amount->text().trimmed().toDouble();
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
returndeliveryorderfreeline->Price = price->text().trimmed().toDouble();
}
if(!errors) {
returndeliveryorderfreeline->save();
if(!errors){
ReturnDeliveryOrderFreelineIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrderFreeline"),errorString.trimmed());
return false; 
 }
}
void ReturnDeliveryOrderFreelineUI::cancel(){ 
ReturnDeliveryOrderFreelineIndexUI::ShowUI();
}
bool ReturnDeliveryOrderFreelineUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(returndeliveryorderfreeline->ReturnDeliveryOrderID == 0) 
returndeliveryorderfreeline->ReturnDeliveryOrderID = returndeliveryorder->getKey();
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
returndeliveryorderfreeline->Description = description->text().trimmed();
}
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
returndeliveryorderfreeline->Amount = amount->text().trimmed().toDouble();
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
returndeliveryorderfreeline->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrderFreeline"),errorString.trimmed());
return false; 
 }
}
