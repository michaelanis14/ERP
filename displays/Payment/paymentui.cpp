/**************************************************************************
**   File: paymentui.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "paymentui.h"
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
invoice->addItems(Invoice::GetHashList());
block0Layout->addRow("Invoice",invoice);
totalamount = new QLineEdit();
totalamount->setValidator( doubleValidator );
block0Layout->addRow("Total Amount",totalamount);
comment = new QLineEdit();
block0Layout->addRow("Comment",comment);
paymenttype = new ERPComboBox();
paymenttype->addItems(PaymentType::GetHashList());
block0Layout->addRow("Payment Type",paymenttype);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* PaymentUI::p_instance = 0;
void PaymentUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new PaymentUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
PaymentUI*PaymentUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PaymentUI*) p_instance; 
}
void PaymentUI::fill(Payment* payment){ 
clear();
this->payment = payment;
totalamount->setText(QString::number(payment->TotalAmount));
comment->setText(payment->Comment);
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
if(payment->InvoiceID == 0) 
payment->InvoiceID = invoice->getKey();
if(totalamount->text().trimmed().isEmpty()){
errors = true;
errorString += "Total Amount Can't be Empty! \n";
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
errorString += "Comment Can't be Empty! \n";
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
if(!errors) {
payment->save();
if(!errors){
PaymentIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Payment",errorString.trimmed());
return false; 
 }
}
void PaymentUI::cancel(){ 
PaymentIndexUI::ShowUI();
}
