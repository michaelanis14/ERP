/**************************************************************************
**   File: paymentui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
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
invoice = new ERPComboBox();
invoice->addItems(Invoice::GetPairList());
block0Layout->addRow(QObject::tr("Invoice"),invoice);
totalamount = new QLineEdit();
totalamount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Total Amount"),totalamount);
comment = new QLineEdit();
block0Layout->addRow(QObject::tr("Comment"),comment);
paymenttype = new ERPComboBox();
paymenttype->addItems(PaymentType::GetPairList());
block0Layout->addRow(QObject::tr("Payment Type"),paymenttype);
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
invoice->setIndexByKey(payment->InvoiceID);
totalamount->setText(QString::number(payment->TotalAmount));
comment->setText(payment->Comment);
paymenttype->setIndexByKey(payment->PaymentTypeID);
} 
void PaymentUI::clear(){ 
delete this->payment;
totalamount->setText("");
comment->setText("");
this->payment = new Payment();
} 
void PaymentUI::selectPayment(){ 
if(Payment::GetStringList().contains(QString::number(this->payment->InvoiceID)))
{
Payment* con = Payment::Get(QString::number(this->payment->InvoiceID));
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
if(!invoice->isHidden()) 
payment->InvoiceID = invoice->getKey();
if(totalamount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Total Amount Can't be Empty! \n");
totalamount->setObjectName("error");
totalamount->style()->unpolish(totalamount);
totalamount->style()->polish(totalamount);
totalamount->update();
}
else { 
totalamount->setObjectName("totalamount");
totalamount->style()->unpolish(totalamount);
totalamount->style()->polish(totalamount);
totalamount->update();
payment->TotalAmount = totalamount->text().trimmed().toDouble();
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
if(!paymenttype->isHidden()) 
payment->PaymentTypeID = paymenttype->getKey();
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
if(payment->InvoiceID == 0) 
payment->InvoiceID = invoice->getKey();
if(totalamount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Total Amount Can't be Empty! \n");
totalamount->setObjectName("error");
totalamount->style()->unpolish(totalamount);
totalamount->style()->polish(totalamount);
totalamount->update();
}
else { 
totalamount->setObjectName("totalamount");
totalamount->style()->unpolish(totalamount);
totalamount->style()->polish(totalamount);
totalamount->update();
payment->TotalAmount = totalamount->text().trimmed().toDouble();
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
if(payment->PaymentTypeID == 0) 
payment->PaymentTypeID = paymenttype->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Payment"),errorString.trimmed());
return false; 
 }
}
