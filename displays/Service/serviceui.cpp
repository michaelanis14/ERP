/**************************************************************************
**   File: serviceui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "serviceui.h"
#include "../MainWindow.h"

ServiceUI::ServiceUI(QWidget *parent) :ERPDisplay(parent)
{

service = new Service();
flowLayout = new FlowLayout(formPanel);
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
name = new QLineEdit();
QStringList* list = new QStringList(Service::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectService()));
block0Layout->addRow("Name",name);
shortdescription = new QLineEdit();
block0Layout->addRow("Short Description",shortdescription);
sellingprice = new QLineEdit();
sellingprice->setValidator( doubleValidator );
block0Layout->addRow("Selling Price",sellingprice);
netcoast = new QLineEdit();
netcoast->setValidator( doubleValidator );
block0Layout->addRow("Net Coast",netcoast);
trademarginrate = new QLineEdit();
trademarginrate->setValidator( doubleValidator );
block0Layout->addRow("Trade Margin Rate",trademarginrate);
tax = new ERPComboBox();
tax->addItems(Tax::GetPairList());
block0Layout->addRow("Tax",tax);
barcode = new QLineEdit();
QObject::connect(barcode, SIGNAL(textChanged(QString)), this, SLOT(barcodeChanged(QString)));
block0Layout->addRow("Barcode",barcode);
barcodeDisplay = new Barcode(0,0); block0Layout->addRow("Barcode",barcodeDisplay); generatebarcode = new QPushButton("Generate Barcode"); QObject::connect(generatebarcode, SIGNAL(clicked()), this, SLOT(generateBarcode())); block0Layout->addRow("",generatebarcode);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ServiceUI::p_instance = 0;
void ServiceUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ServiceUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ServiceUI*ServiceUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ServiceUI*) p_instance; 
}
void ServiceUI::fill(Service* service){ 
clear();
this->service = service;
name->setText(service->Name);
shortdescription->setText(service->ShortDescription);
sellingprice->setText(QString::number(service->SellingPrice));
netcoast->setText(QString::number(service->NetCoast));
trademarginrate->setText(QString::number(service->TradeMarginRate));
barcode->setText(service->Barcode);
} 
void ServiceUI::clear(){ 
delete this->service;
shortdescription->setText("");
sellingprice->setText("");
netcoast->setText("");
trademarginrate->setText("");
barcode->setText("");
this->service = new Service();
} 
void ServiceUI::selectService(){ 
if(Service::GetStringList().contains(this->service->Name))
{
Service* con = Service::Get(this->service->Name);
if(this->service->ServiceID != con->ServiceID){
fill(con);
}
}
else if(service->ServiceID != 0)
clear();
}
void ServiceUI::generateBarcode(){ QString number = ""; for(int i = 0; i < 13; i++)  number += QString::number(rand() % 10); barcode->setText(number); barcodeDisplay->barcode = number; barcodeDisplay->repaint(); }
void ServiceUI::barcodeChanged(QString barcode){ if(this->barcode->text().count() > 13) this->barcode->setText(this->barcode->text().remove(12,20)); barcodeDisplay->barcode = barcode; barcodeDisplay->repaint(); }
bool ServiceUI::save(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += "Name Can't be Empty! \n";
name->setObjectName("error");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
}
else { 
name->setObjectName("name");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
service->Name = name->text().trimmed();
}
if(shortdescription->text().trimmed().isEmpty()){
errors = true;
errorString += "Short Description Can't be Empty! \n";
shortdescription->setObjectName("error");
shortdescription->style()->unpolish(shortdescription);
shortdescription->style()->polish(shortdescription);
shortdescription->update();
}
else { 
shortdescription->setObjectName("shortdescription");
shortdescription->style()->unpolish(shortdescription);
shortdescription->style()->polish(shortdescription);
shortdescription->update();
service->ShortDescription = shortdescription->text().trimmed();
}
if(sellingprice->text().trimmed().isEmpty()){
errors = true;
errorString += "Selling Price Can't be Empty! \n";
sellingprice->setObjectName("error");
sellingprice->style()->unpolish(sellingprice);
sellingprice->style()->polish(sellingprice);
sellingprice->update();
}
else { 
sellingprice->setObjectName("sellingprice");
sellingprice->style()->unpolish(sellingprice);
sellingprice->style()->polish(sellingprice);
sellingprice->update();
service->SellingPrice = sellingprice->text().trimmed().toDouble();
}
if(netcoast->text().trimmed().isEmpty()){
errors = true;
errorString += "Net Coast Can't be Empty! \n";
netcoast->setObjectName("error");
netcoast->style()->unpolish(netcoast);
netcoast->style()->polish(netcoast);
netcoast->update();
}
else { 
netcoast->setObjectName("netcoast");
netcoast->style()->unpolish(netcoast);
netcoast->style()->polish(netcoast);
netcoast->update();
service->NetCoast = netcoast->text().trimmed().toDouble();
}
if(trademarginrate->text().trimmed().isEmpty()){
errors = true;
errorString += "Trade Margin Rate Can't be Empty! \n";
trademarginrate->setObjectName("error");
trademarginrate->style()->unpolish(trademarginrate);
trademarginrate->style()->polish(trademarginrate);
trademarginrate->update();
}
else { 
trademarginrate->setObjectName("trademarginrate");
trademarginrate->style()->unpolish(trademarginrate);
trademarginrate->style()->polish(trademarginrate);
trademarginrate->update();
service->TradeMarginRate = trademarginrate->text().trimmed().toDouble();
}
if(!tax->isHidden()) 
service->TaxID = tax->getKey();
if(barcode->text().trimmed().isEmpty()){
errors = true;
errorString += "Barcode Can't be Empty! \n";
barcode->setObjectName("error");
barcode->style()->unpolish(barcode);
barcode->style()->polish(barcode);
barcode->update();
}
else { 
barcode->setObjectName("barcode");
barcode->style()->unpolish(barcode);
barcode->style()->polish(barcode);
barcode->update();
service->Barcode = barcode->text().trimmed();
}
if(!errors) {
service->save();
if(!errors){
ServiceIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Service",errorString.trimmed());
return false; 
 }
}
void ServiceUI::cancel(){ 
ServiceIndexUI::ShowUI();
}
bool ServiceUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += "Name Can't be Empty! \n";
name->setObjectName("error");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
}
else { 
name->setObjectName("name");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
service->Name = name->text().trimmed();
}
if(shortdescription->text().trimmed().isEmpty()){
errors = true;
errorString += "Short Description Can't be Empty! \n";
shortdescription->setObjectName("error");
shortdescription->style()->unpolish(shortdescription);
shortdescription->style()->polish(shortdescription);
shortdescription->update();
}
else { 
shortdescription->setObjectName("shortdescription");
shortdescription->style()->unpolish(shortdescription);
shortdescription->style()->polish(shortdescription);
shortdescription->update();
service->ShortDescription = shortdescription->text().trimmed();
}
if(sellingprice->text().trimmed().isEmpty()){
errors = true;
errorString += "Selling Price Can't be Empty! \n";
sellingprice->setObjectName("error");
sellingprice->style()->unpolish(sellingprice);
sellingprice->style()->polish(sellingprice);
sellingprice->update();
}
else { 
sellingprice->setObjectName("sellingprice");
sellingprice->style()->unpolish(sellingprice);
sellingprice->style()->polish(sellingprice);
sellingprice->update();
service->SellingPrice = sellingprice->text().trimmed().toDouble();
}
if(netcoast->text().trimmed().isEmpty()){
errors = true;
errorString += "Net Coast Can't be Empty! \n";
netcoast->setObjectName("error");
netcoast->style()->unpolish(netcoast);
netcoast->style()->polish(netcoast);
netcoast->update();
}
else { 
netcoast->setObjectName("netcoast");
netcoast->style()->unpolish(netcoast);
netcoast->style()->polish(netcoast);
netcoast->update();
service->NetCoast = netcoast->text().trimmed().toDouble();
}
if(trademarginrate->text().trimmed().isEmpty()){
errors = true;
errorString += "Trade Margin Rate Can't be Empty! \n";
trademarginrate->setObjectName("error");
trademarginrate->style()->unpolish(trademarginrate);
trademarginrate->style()->polish(trademarginrate);
trademarginrate->update();
}
else { 
trademarginrate->setObjectName("trademarginrate");
trademarginrate->style()->unpolish(trademarginrate);
trademarginrate->style()->polish(trademarginrate);
trademarginrate->update();
service->TradeMarginRate = trademarginrate->text().trimmed().toDouble();
}
if(service->TaxID == 0) 
service->TaxID = tax->getKey();
if(barcode->text().trimmed().isEmpty()){
errors = true;
errorString += "Barcode Can't be Empty! \n";
barcode->setObjectName("error");
barcode->style()->unpolish(barcode);
barcode->style()->polish(barcode);
barcode->update();
}
else { 
barcode->setObjectName("barcode");
barcode->style()->unpolish(barcode);
barcode->style()->polish(barcode);
barcode->update();
service->Barcode = barcode->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "Service",errorString.trimmed());
return false; 
 }
}
