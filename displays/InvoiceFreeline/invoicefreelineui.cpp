/**************************************************************************
**   File: invoicefreelineui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoicefreelineui.h"
#include "../MainWindow.h"

InvoiceFreelineUI::InvoiceFreelineUI(QWidget *parent) :ERPDisplay(parent)
{

invoicefreeline = new InvoiceFreeline();
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
description = new QLineEdit();
block0Layout->addRow("Description",description);
invoice = new ERPComboBox();
invoice->addItems(Invoice::GetPairList());
block0Layout->addRow("Invoice",invoice);
price = new QLineEdit();
price->setValidator( doubleValidator );
block0Layout->addRow("Price",price);
tax = new ERPComboBox();
tax->addItems(Tax::GetPairList());
block0Layout->addRow("Tax",tax);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow("Amount",amount);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* InvoiceFreelineUI::p_instance = 0;
void InvoiceFreelineUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new InvoiceFreelineUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
InvoiceFreelineUI*InvoiceFreelineUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoiceFreelineUI*) p_instance; 
}
void InvoiceFreelineUI::fill(InvoiceFreeline* invoicefreeline){ 
clear();
this->invoicefreeline = invoicefreeline;
description->setText(invoicefreeline->Description);
price->setText(QString::number(invoicefreeline->Price));
amount->setText(QString::number(invoicefreeline->Amount));
} 
void InvoiceFreelineUI::clear(){ 
delete this->invoicefreeline;
description->setText("");
price->setText("");
amount->setText("");
this->invoicefreeline = new InvoiceFreeline();
} 
void InvoiceFreelineUI::selectInvoiceFreeline(){ 
if(InvoiceFreeline::GetStringList().contains(this->invoicefreeline->Description))
{
InvoiceFreeline* con = InvoiceFreeline::Get(this->invoicefreeline->Description);
if(this->invoicefreeline->InvoiceFreelineID != con->InvoiceFreelineID){
fill(con);
}
}
else if(invoicefreeline->InvoiceFreelineID != 0)
clear();
}
bool InvoiceFreelineUI::save(){ 
bool errors = false;
QString errorString =  "";
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
invoicefreeline->Description = description->text().trimmed();
}
if(!invoice->isHidden()) 
invoicefreeline->InvoiceID = invoice->getKey();
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
invoicefreeline->Price = price->text().trimmed().toDouble();
}
if(!tax->isHidden()) 
invoicefreeline->TaxID = tax->getKey();
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
invoicefreeline->Amount = amount->text().trimmed().toDouble();
}
if(!errors) {
invoicefreeline->save();
if(!errors){
InvoiceFreelineIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "InvoiceFreeline",errorString.trimmed());
return false; 
 }
}
void InvoiceFreelineUI::cancel(){ 
InvoiceFreelineIndexUI::ShowUI();
}
bool InvoiceFreelineUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
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
invoicefreeline->Description = description->text().trimmed();
}
if(invoicefreeline->InvoiceID == 0) 
invoicefreeline->InvoiceID = invoice->getKey();
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
invoicefreeline->Price = price->text().trimmed().toDouble();
}
if(invoicefreeline->TaxID == 0) 
invoicefreeline->TaxID = tax->getKey();
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
invoicefreeline->Amount = amount->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "InvoiceFreeline",errorString.trimmed());
return false; 
 }
}
