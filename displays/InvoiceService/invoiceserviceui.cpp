/**************************************************************************
**   File: invoiceserviceui.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoiceserviceui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

InvoiceServiceUI::InvoiceServiceUI(QWidget *parent) :ERPDisplay(parent)
{

invoiceservice = new InvoiceService();
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
service = new ERPComboBox();
service->addItems(Service::GetPairList());
block0Layout->addRow(QObject::tr("Service"),service);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Amount"),amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Price"),price);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* InvoiceServiceUI::p_instance = 0;
void InvoiceServiceUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Invoice)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new InvoiceServiceUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
InvoiceServiceUI*InvoiceServiceUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (InvoiceServiceUI*) p_instance;
}
void InvoiceServiceUI::fill(InvoiceService* invoiceservice){
clear();
this->invoiceservice = invoiceservice;
invoice->setIndexByKey(invoiceservice->InvoiceID);
service->setIndexByKey(invoiceservice->ServiceID);
amount->setText(QString::number(invoiceservice->Amount));
price->setText(QString::number(invoiceservice->Price));
}
void InvoiceServiceUI::clear(){
delete this->invoiceservice;
amount->setText("");
price->setText("");
this->invoiceservice = new InvoiceService();
}
void InvoiceServiceUI::selectInvoiceService(){
if(InvoiceService::GetStringList().contains(QString::number(this->invoiceservice->InvoiceID)))
{
InvoiceService* con = InvoiceService::Get(QString::number(this->invoiceservice->InvoiceID));
if(this->invoiceservice->InvoiceServiceID != con->InvoiceServiceID){
fill(con);
}
}
else if(invoiceservice->InvoiceServiceID != 0)
clear();
}
bool InvoiceServiceUI::save(){
bool errors = false;
QString errorString =  "";
if(!invoice->isHidden())
invoiceservice->InvoiceID = invoice->getKey();
if(!service->isHidden())
invoiceservice->ServiceID = service->getKey();
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
invoiceservice->Amount = amount->text().trimmed().toDouble();
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
invoiceservice->Price = price->text().trimmed().toDouble();
}
if(!errors) {
invoiceservice->save();
if(!errors){
InvoiceServiceIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("InvoiceService"),errorString.trimmed());
return false;
 }
}
void InvoiceServiceUI::cancel(){
InvoiceServiceIndexUI::ShowUI();
}
bool InvoiceServiceUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(invoiceservice->InvoiceID == 0)
invoiceservice->InvoiceID = invoice->getKey();
if(invoiceservice->ServiceID == 0)
invoiceservice->ServiceID = service->getKey();
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
invoiceservice->Amount = amount->text().trimmed().toDouble();
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
invoiceservice->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("InvoiceService"),errorString.trimmed());
return false;
 }
}
