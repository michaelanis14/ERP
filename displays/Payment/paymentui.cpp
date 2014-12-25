/**************************************************************************
**   File: paymentui.cpp
**   Created on: Sat Dec 20 02:32:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "paymentui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

PaymentUI::PaymentUI(QWidget *parent) :ERPDisplay(parent)
{

payment = new Payment();
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
paymenttype = new ERPComboBox();
paymenttype->addItems(PaymentType::GetPairList());
block0Layout->addRow(QObject::tr("Payment Type"),paymenttype);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
project = new ERPComboBox();
project->addItems(Project::GetPairList());
block0Layout->addRow(QObject::tr("Project"),project);
date = new QDateEdit(QDate::currentDate());
date->setCalendarPopup(true);
date->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Date"),date);
netamount = new QLineEdit();
netamount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Net Amount"),netamount);
grossamount = new QLineEdit();
grossamount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Gross Amount"),grossamount);
comment = new QLineEdit();
block0Layout->addRow(QObject::tr("Comment"),comment);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* PaymentUI::p_instance = 0;
void PaymentUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Payment) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new PaymentUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
PaymentUI*PaymentUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PaymentUI*) p_instance; 
}
void PaymentUI::fill(Payment* payment){ 
clear();
this->payment = payment;
paymenttype->setIndexByKey(payment->PaymentTypeID);
contact->setIndexByKey(payment->ContactID);
project->setIndexByKey(payment->ProjectID);
date->setDate(payment->Date);
netamount->setText(QString::number(payment->NetAmount));
grossamount->setText(QString::number(payment->GrossAmount));
comment->setText(payment->Comment);
} 
void PaymentUI::clear(){ 
delete this->payment;
date->setDate(QDate::currentDate());
netamount->setText("");
grossamount->setText("");
comment->setText("");
this->payment = new Payment();
} 
void PaymentUI::selectPayment(){ 
if(Payment::GetStringList().contains(QString::number(this->payment->PaymentTypeID)))
{
Payment* con = Payment::Get(QString::number(this->payment->PaymentTypeID));
if(this->payment->PaymentID != con->PaymentID){
fill(con);
}
}
else if(payment->PaymentID != 0)
clear();
}
bool PaymentUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!paymenttype->isHidden()) 
payment->PaymentTypeID = paymenttype->getKey();
if(!contact->isHidden()) 
payment->ContactID = contact->getKey();
if(!project->isHidden()) 
payment->ProjectID = project->getKey();
if(date->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Date Can't be Empty! \n");
date->setObjectName("error");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
}
else { 
date->setObjectName("date");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
payment->Date.setDate(date->date().year(),date->date().month(),date->date().day());
}
if(netamount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Net Amount Can't be Empty! \n");
netamount->setObjectName("error");
netamount->style()->unpolish(netamount);
netamount->style()->polish(netamount);
netamount->update();
}
else { 
netamount->setObjectName("netamount");
netamount->style()->unpolish(netamount);
netamount->style()->polish(netamount);
netamount->update();
payment->NetAmount = netamount->text().trimmed().toDouble();
}
if(grossamount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Gross Amount Can't be Empty! \n");
grossamount->setObjectName("error");
grossamount->style()->unpolish(grossamount);
grossamount->style()->polish(grossamount);
grossamount->update();
}
else { 
grossamount->setObjectName("grossamount");
grossamount->style()->unpolish(grossamount);
grossamount->style()->polish(grossamount);
grossamount->update();
payment->GrossAmount = grossamount->text().trimmed().toDouble();
}
if(comment->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Comment Can't be Empty! \n");
comment->setObjectName("error");
comment->style()->unpolish(comment);
comment->style()->polish(comment);
comment->update();
}
else { 
comment->setObjectName("comment");
comment->style()->unpolish(comment);
comment->style()->polish(comment);
comment->update();
payment->Comment = comment->text().trimmed();
}
if(!errors) {
payment->save();
if(!errors){
PaymentIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("Payment"),errorString.trimmed());
return false; 
 }
}
void PaymentUI::cancel(){ 
PaymentIndexUI::ShowUI();
}
bool PaymentUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(payment->PaymentTypeID == 0) 
payment->PaymentTypeID = paymenttype->getKey();
if(payment->ContactID == 0) 
payment->ContactID = contact->getKey();
if(payment->ProjectID == 0) 
payment->ProjectID = project->getKey();
if(date->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Date Can't be Empty! \n");
date->setObjectName("error");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
}
else { 
date->setObjectName("date");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
payment->Date.fromString(date->text().trimmed());
}
if(netamount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Net Amount Can't be Empty! \n");
netamount->setObjectName("error");
netamount->style()->unpolish(netamount);
netamount->style()->polish(netamount);
netamount->update();
}
else { 
netamount->setObjectName("netamount");
netamount->style()->unpolish(netamount);
netamount->style()->polish(netamount);
netamount->update();
payment->NetAmount = netamount->text().trimmed().toDouble();
}
if(grossamount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Gross Amount Can't be Empty! \n");
grossamount->setObjectName("error");
grossamount->style()->unpolish(grossamount);
grossamount->style()->polish(grossamount);
grossamount->update();
}
else { 
grossamount->setObjectName("grossamount");
grossamount->style()->unpolish(grossamount);
grossamount->style()->polish(grossamount);
grossamount->update();
payment->GrossAmount = grossamount->text().trimmed().toDouble();
}
if(comment->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Comment Can't be Empty! \n");
comment->setObjectName("error");
comment->style()->unpolish(comment);
comment->style()->polish(comment);
comment->update();
}
else { 
comment->setObjectName("comment");
comment->style()->unpolish(comment);
comment->style()->polish(comment);
comment->update();
payment->Comment = comment->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Payment"),errorString.trimmed());
return false; 
 }
}
