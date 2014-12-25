/**************************************************************************
**   File: deliveryorderserialui.cpp
**   Created on: Fri Dec 19 13:01:03 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderserialui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

DeliveryOrderSerialUI::DeliveryOrderSerialUI(QWidget *parent) :ERPDisplay(parent)
{

deliveryorderserial = new DeliveryOrderSerial();
flowLayout = new FlowLayout(this);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
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
block0Layout->addRow(QObject::tr("Title"),title);
serial = new QLineEdit();
serial->setValidator( intValidator );
block0Layout->addRow(QObject::tr("Serial"),serial);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* DeliveryOrderSerialUI::p_instance = 0;
void DeliveryOrderSerialUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->DeliveryOrderSerial) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderSerialUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
DeliveryOrderSerialUI*DeliveryOrderSerialUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderSerialUI*) p_instance; 
}
void DeliveryOrderSerialUI::fill(DeliveryOrderSerial* deliveryorderserial){ 
clear();
this->deliveryorderserial = deliveryorderserial;
title->setText(deliveryorderserial->Title);
serial->setText(QString::number(deliveryorderserial->Serial));
} 
void DeliveryOrderSerialUI::clear(){ 
delete this->deliveryorderserial;
title->setText("");
serial->setText("");
this->deliveryorderserial = new DeliveryOrderSerial();
} 
void DeliveryOrderSerialUI::selectDeliveryOrderSerial(){ 
if(DeliveryOrderSerial::GetStringList().contains(this->deliveryorderserial->Title))
{
DeliveryOrderSerial* con = DeliveryOrderSerial::Get(this->deliveryorderserial->Title);
if(this->deliveryorderserial->DeliveryOrderSerialID != con->DeliveryOrderSerialID){
fill(con);
}
}
else if(deliveryorderserial->DeliveryOrderSerialID != 0)
clear();
}
bool DeliveryOrderSerialUI::save(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Title Can't be Empty! \n");
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
deliveryorderserial->Title = title->text().trimmed();
}
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Serial Can't be Empty! \n");
serial->setObjectName("error");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
}
else { 
serial->setObjectName("serial");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
deliveryorderserial->Serial = serial->text().trimmed().toInt();
}
if(!errors) {
deliveryorderserial->save();
if(!errors){
DeliveryOrderSerialIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("DeliveryOrderSerial"),errorString.trimmed());
return false; 
 }
}
void DeliveryOrderSerialUI::cancel(){ 
DeliveryOrderSerialIndexUI::ShowUI();
}
bool DeliveryOrderSerialUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Title Can't be Empty! \n");
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
deliveryorderserial->Title = title->text().trimmed();
}
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Serial Can't be Empty! \n");
serial->setObjectName("error");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
}
else { 
serial->setObjectName("serial");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
deliveryorderserial->Serial = serial->text().trimmed().toInt();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("DeliveryOrderSerial"),errorString.trimmed());
return false; 
 }
}
