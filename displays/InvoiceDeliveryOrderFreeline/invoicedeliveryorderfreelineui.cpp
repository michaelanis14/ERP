/**************************************************************************
**   File: invoicedeliveryorderfreelineui.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoicedeliveryorderfreelineui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

InvoiceDeliveryOrderFreelineUI::InvoiceDeliveryOrderFreelineUI(QWidget *parent) :ERPDisplay(parent)
{

invoicedeliveryorderfreeline = new InvoiceDeliveryOrderFreeline();
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
ERPDisplay* InvoiceDeliveryOrderFreelineUI::p_instance = 0;
void InvoiceDeliveryOrderFreelineUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Invoice)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new InvoiceDeliveryOrderFreelineUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
InvoiceDeliveryOrderFreelineUI*InvoiceDeliveryOrderFreelineUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (InvoiceDeliveryOrderFreelineUI*) p_instance;
}
void InvoiceDeliveryOrderFreelineUI::fill(InvoiceDeliveryOrderFreeline* invoicedeliveryorderfreeline){
clear();
this->invoicedeliveryorderfreeline = invoicedeliveryorderfreeline;
invoice->setIndexByKey(invoicedeliveryorderfreeline->InvoiceID);
description->setText(invoicedeliveryorderfreeline->Description);
amount->setText(QString::number(invoicedeliveryorderfreeline->Amount));
price->setText(QString::number(invoicedeliveryorderfreeline->Price));
}
void InvoiceDeliveryOrderFreelineUI::clear(){
delete this->invoicedeliveryorderfreeline;
description->setText("");
amount->setText("");
price->setText("");
this->invoicedeliveryorderfreeline = new InvoiceDeliveryOrderFreeline();
}
void InvoiceDeliveryOrderFreelineUI::selectInvoiceDeliveryOrderFreeline(){
if(InvoiceDeliveryOrderFreeline::GetStringList().contains(QString::number(this->invoicedeliveryorderfreeline->InvoiceID)))
{
InvoiceDeliveryOrderFreeline* con = InvoiceDeliveryOrderFreeline::Get(QString::number(this->invoicedeliveryorderfreeline->InvoiceID));
if(this->invoicedeliveryorderfreeline->InvoiceDeliveryOrderFreelineID != con->InvoiceDeliveryOrderFreelineID){
fill(con);
}
}
else if(invoicedeliveryorderfreeline->InvoiceDeliveryOrderFreelineID != 0)
clear();
}
bool InvoiceDeliveryOrderFreelineUI::save(){
bool errors = false;
QString errorString =  "";
if(!invoice->isHidden())
invoicedeliveryorderfreeline->InvoiceID = invoice->getKey();
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
invoicedeliveryorderfreeline->Description = description->text().trimmed();
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
invoicedeliveryorderfreeline->Amount = amount->text().trimmed().toDouble();
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
invoicedeliveryorderfreeline->Price = price->text().trimmed().toDouble();
}
if(!errors) {
invoicedeliveryorderfreeline->save();
if(!errors){
InvoiceDeliveryOrderFreelineIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("InvoiceDeliveryOrderFreeline"),errorString.trimmed());
return false;
 }
}
void InvoiceDeliveryOrderFreelineUI::cancel(){
InvoiceDeliveryOrderFreelineIndexUI::ShowUI();
}
bool InvoiceDeliveryOrderFreelineUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(invoicedeliveryorderfreeline->InvoiceID == 0)
invoicedeliveryorderfreeline->InvoiceID = invoice->getKey();
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
invoicedeliveryorderfreeline->Description = description->text().trimmed();
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
invoicedeliveryorderfreeline->Amount = amount->text().trimmed().toDouble();
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
invoicedeliveryorderfreeline->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("InvoiceDeliveryOrderFreeline"),errorString.trimmed());
return false;
 }
}
