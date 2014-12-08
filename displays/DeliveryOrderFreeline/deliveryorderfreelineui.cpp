/**************************************************************************
**   File: deliveryorderfreelineui.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderfreelineui.h"
#include "../MainWindow.h"

DeliveryOrderFreelineUI::DeliveryOrderFreelineUI(QWidget *parent) :ERPDisplay(parent)
{

deliveryorderfreeline = new DeliveryOrderFreeline();
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
deliveryorder->addItems(DeliveryOrder::GetHashList());
block0Layout->addRow("Delivery Order",deliveryorder);
description = new QLineEdit();
block0Layout->addRow("Description",description);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow("Amount",amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
block0Layout->addRow("Price",price);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* DeliveryOrderFreelineUI::p_instance = 0;
void DeliveryOrderFreelineUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderFreelineUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
DeliveryOrderFreelineUI*DeliveryOrderFreelineUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderFreelineUI*) p_instance; 
}
void DeliveryOrderFreelineUI::fill(DeliveryOrderFreeline* deliveryorderfreeline){ 
clear();
this->deliveryorderfreeline = deliveryorderfreeline;
description->setText(deliveryorderfreeline->Description);
amount->setText(QString::number(deliveryorderfreeline->Amount));
price->setText(QString::number(deliveryorderfreeline->Price));
} 
void DeliveryOrderFreelineUI::clear(){ 
delete this->deliveryorderfreeline;
description->setText("");
amount->setText("");
price->setText("");
this->deliveryorderfreeline = new DeliveryOrderFreeline();
} 
void DeliveryOrderFreelineUI::selectDeliveryOrderFreeline(){ 
if(DeliveryOrderFreeline::GetStringList().contains(QString::number(this->deliveryorderfreeline->DeliveryOrderID)))
{
DeliveryOrderFreeline* con = DeliveryOrderFreeline::Get(QString::number(this->deliveryorderfreeline->DeliveryOrderID));
if(this->deliveryorderfreeline->DeliveryOrderFreelineID != con->DeliveryOrderFreelineID){
fill(con);
}
}
else if(deliveryorderfreeline->DeliveryOrderFreelineID != 0)
clear();
}
bool DeliveryOrderFreelineUI::save(){ 
bool errors = false;
QString errorString =  "";
if(deliveryorderfreeline->DeliveryOrderID == 0) 
deliveryorderfreeline->DeliveryOrderID = deliveryorder->getKey();
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
deliveryorderfreeline->Description = description->text().trimmed();
}
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
deliveryorderfreeline->Amount = amount->text().trimmed().toDouble();
}
if(price->text().trimmed().isEmpty()){
errors = true;
errorString += "Price Can't be Empty! \n";
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
deliveryorderfreeline->Price = price->text().trimmed().toDouble();
}
if(!errors) {
deliveryorderfreeline->save();
if(!errors){
DeliveryOrderFreelineIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "DeliveryOrderFreeline",errorString.trimmed());
return false; 
 }
}
void DeliveryOrderFreelineUI::cancel(){ 
DeliveryOrderFreelineIndexUI::ShowUI();
}
