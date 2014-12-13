/**************************************************************************
**   File: purchaseserialui.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchaseserialui.h"
#include "../MainWindow.h"

PurchaseSerialUI::PurchaseSerialUI(QWidget *parent) :ERPDisplay(parent)
{

purchaseserial = new PurchaseSerial();
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
block0Layout->addRow("Title",title);
serial = new QLineEdit();
serial->setValidator( intValidator );
block0Layout->addRow("Serial",serial);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* PurchaseSerialUI::p_instance = 0;
void PurchaseSerialUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new PurchaseSerialUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
PurchaseSerialUI*PurchaseSerialUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PurchaseSerialUI*) p_instance; 
}
void PurchaseSerialUI::fill(PurchaseSerial* purchaseserial){ 
clear();
this->purchaseserial = purchaseserial;
title->setText(purchaseserial->Title);
serial->setText(QString::number(purchaseserial->Serial));
} 
void PurchaseSerialUI::clear(){ 
delete this->purchaseserial;
title->setText("");
serial->setText("");
this->purchaseserial = new PurchaseSerial();
} 
void PurchaseSerialUI::selectPurchaseSerial(){ 
if(PurchaseSerial::GetStringList().contains(this->purchaseserial->Title))
{
PurchaseSerial* con = PurchaseSerial::Get(this->purchaseserial->Title);
if(this->purchaseserial->PurchaseSerialID != con->PurchaseSerialID){
fill(con);
}
}
else if(purchaseserial->PurchaseSerialID != 0)
clear();
}
bool PurchaseSerialUI::save(){ 
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
purchaseserial->Title = title->text().trimmed();
}
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += "Serial Can't be Empty! \n";
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
purchaseserial->Serial = serial->text().trimmed().toInt();
}
if(!errors) {
purchaseserial->save();
if(!errors){
PurchaseSerialIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "PurchaseSerial",errorString.trimmed());
return false; 
 }
}
void PurchaseSerialUI::cancel(){ 
PurchaseSerialIndexUI::ShowUI();
}
bool PurchaseSerialUI::updateModel(){ 
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
purchaseserial->Title = title->text().trimmed();
}
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += "Serial Can't be Empty! \n";
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
purchaseserial->Serial = serial->text().trimmed().toInt();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "PurchaseSerial",errorString.trimmed());
return false; 
 }
}
