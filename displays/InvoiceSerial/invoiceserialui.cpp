/**************************************************************************
**   File: invoiceserialui.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoiceserialui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

InvoiceSerialUI::InvoiceSerialUI(QWidget *parent) :ERPDisplay(parent)
{

invoiceserial = new InvoiceSerial();
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
ERPDisplay* InvoiceSerialUI::p_instance = 0;
void InvoiceSerialUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->InvoiceSerial) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new InvoiceSerialUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
InvoiceSerialUI*InvoiceSerialUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoiceSerialUI*) p_instance; 
}
void InvoiceSerialUI::fill(InvoiceSerial* invoiceserial){ 
clear();
this->invoiceserial = invoiceserial;
title->setText(invoiceserial->Title);
serial->setText(QString::number(invoiceserial->Serial));
} 
void InvoiceSerialUI::clear(){ 
delete this->invoiceserial;
title->setText("");
serial->setText("");
this->invoiceserial = new InvoiceSerial();
} 
void InvoiceSerialUI::selectInvoiceSerial(){ 
if(InvoiceSerial::GetStringList().contains(this->invoiceserial->Title))
{
InvoiceSerial* con = InvoiceSerial::Get(this->invoiceserial->Title);
if(this->invoiceserial->InvoiceSerialID != con->InvoiceSerialID){
fill(con);
}
}
else if(invoiceserial->InvoiceSerialID != 0)
clear();
}
bool InvoiceSerialUI::save(){ 
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
invoiceserial->Title = title->text().trimmed();
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
invoiceserial->Serial = serial->text().trimmed().toInt();
}
if(!errors) {
invoiceserial->save();
if(!errors){
InvoiceSerialIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("InvoiceSerial"),errorString.trimmed());
return false; 
 }
}
void InvoiceSerialUI::cancel(){ 
InvoiceSerialIndexUI::ShowUI();
}
bool InvoiceSerialUI::updateModel(){ 
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
invoiceserial->Title = title->text().trimmed();
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
invoiceserial->Serial = serial->text().trimmed().toInt();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("InvoiceSerial"),errorString.trimmed());
return false; 
 }
}
