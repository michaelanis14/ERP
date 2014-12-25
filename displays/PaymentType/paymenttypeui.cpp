/**************************************************************************
**   File: paymenttypeui.cpp
**   Created on: Sat Dec 20 02:32:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "paymenttypeui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

PaymentTypeUI::PaymentTypeUI(QWidget *parent) :ERPDisplay(parent)
{

paymenttype = new PaymentType();
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
ERPDisplay* PaymentTypeUI::p_instance = 0;
void PaymentTypeUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->PaymentType) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new PaymentTypeUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
PaymentTypeUI*PaymentTypeUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PaymentTypeUI*) p_instance; 
}
void PaymentTypeUI::fill(PaymentType* paymenttype){ 
clear();
this->paymenttype = paymenttype;
description->setText(paymenttype->Description);
} 
void PaymentTypeUI::clear(){ 
delete this->paymenttype;
description->setText("");
this->paymenttype = new PaymentType();
} 
void PaymentTypeUI::selectPaymentType(){ 
if(PaymentType::GetStringList().contains(this->paymenttype->Description))
{
PaymentType* con = PaymentType::Get(this->paymenttype->Description);
if(this->paymenttype->PaymentTypeID != con->PaymentTypeID){
fill(con);
}
}
else if(paymenttype->PaymentTypeID != 0)
clear();
}
bool PaymentTypeUI::save(){ 
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
paymenttype->Description = description->text().trimmed();
}
if(!errors) {
paymenttype->save();
if(!errors){
PaymentTypeIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("PaymentType"),errorString.trimmed());
return false; 
 }
}
void PaymentTypeUI::cancel(){ 
PaymentTypeIndexUI::ShowUI();
}
bool PaymentTypeUI::updateModel(){ 
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
paymenttype->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("PaymentType"),errorString.trimmed());
return false; 
 }
}
