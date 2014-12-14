/**************************************************************************
**   File: invoiceui.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoiceui.h"
#include "../MainWindow.h"

InvoiceUI::InvoiceUI(QWidget *parent) :ERPDisplay(parent)
{

invoice = new Invoice();
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
invoiceserial = new ERPComboBox();
invoiceserial->addItems(InvoiceSerial::GetPairList());
block0Layout->addRow(QObject::tr("Invoice Serial"),invoiceserial);
creationdate = new QDateEdit(QDate::currentDate());
creationdate->setCalendarPopup(true);
creationdate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Creation Date"),creationdate);
enddate = new QDateEdit(QDate::currentDate());
enddate->setCalendarPopup(true);
enddate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("End Date"),enddate);
invoiceperiod = new ERPComboBox();
invoiceperiod->addItems(InvoicePeriod::GetPairList());
block0Layout->addRow(QObject::tr("Invoice Period"),invoiceperiod);
invoiceyear = new ERPComboBox();
invoiceyear->addItems(InvoiceYear::GetPairList());
block0Layout->addRow(QObject::tr("Invoice Year"),invoiceyear);
project = new ERPComboBox();
project->addItems(Project::GetPairList());
block0Layout->addRow(QObject::tr("Project"),project);
duedate = new QDateEdit(QDate::currentDate());
duedate->setCalendarPopup(true);
duedate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Due Date"),duedate);
discount = new QLineEdit();
discount->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("discount"),discount);
allowance = new QLineEdit();
allowance->setValidator( doubleValidator );
block0Layout->addRow(QObject::tr("Allowance"),allowance);
AddRemoveButtons* addremoveInvoiceStateDateButtons = new AddRemoveButtons();
block0Layout->addRow("InvoiceStateDates",addremoveInvoiceStateDateButtons);
QObject::connect(addremoveInvoiceStateDateButtons, SIGNAL(addPressed()), this, SLOT(addInvoiceStateDate()));

AddRemoveButtons* addremoveInvoiceFreelineButtons = new AddRemoveButtons();
block0Layout->addRow("InvoiceFreelines",addremoveInvoiceFreelineButtons);
QObject::connect(addremoveInvoiceFreelineButtons, SIGNAL(addPressed()), this, SLOT(addInvoiceFreeline()));

AddRemoveButtons* addremovePaymentButtons = new AddRemoveButtons();
block0Layout->addRow("Payments",addremovePaymentButtons);
QObject::connect(addremovePaymentButtons, SIGNAL(addPressed()), this, SLOT(addPayment()));

header = new QLineEdit();
block0Layout->addRow(QObject::tr("Header"),header);
footer = new QLineEdit();
block0Layout->addRow(QObject::tr("Footer"),footer);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* InvoiceUI::p_instance = 0;
void InvoiceUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new InvoiceUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
InvoiceUI*InvoiceUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoiceUI*) p_instance; 
}
void InvoiceUI::addInvoiceStateDate(){ 
InvoiceStateDateUI* invoicestatedateui = new InvoiceStateDateUI();
invoicestatedateui->block0Layout->hideRow(invoicestatedateui->invoice);
invoicestatedateui->controllers->setFixedHeight(0);
InvoiceStateDates.append(invoicestatedateui);
RemovebtnWidgets* rminvoicestatedate = new RemovebtnWidgets(0,invoicestatedateui);
QObject::connect(rminvoicestatedate, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceStateDate(QWidget*)));
block0Layout->addRow("InvoiceStateDate"+QString::number(InvoiceStateDates.count()),rminvoicestatedate);
}
void InvoiceUI::addInvoiceStateDate(InvoiceStateDate* InvoiceStateDate){ 
InvoiceStateDateUI* invoicestatedateui = new InvoiceStateDateUI();
invoicestatedateui->block0Layout->hideRow(invoicestatedateui->invoice);
invoicestatedateui->controllers->setFixedHeight(0);
invoicestatedateui->fill(InvoiceStateDate);
InvoiceStateDates.append(invoicestatedateui);
RemovebtnWidgets* rminvoicestatedate = new RemovebtnWidgets(0,invoicestatedateui);
QObject::connect(rminvoicestatedate, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceStateDate(QWidget*)));
block0Layout->addRow(QObject::tr("InvoiceStateDate") +QString::number(InvoiceStateDates.count()),rminvoicestatedate);
}
void InvoiceUI::removeInvoiceStateDate(QWidget* widget){ 
if(InvoiceStateDates.count()  > 0){
InvoiceStateDateUI* invoicestatedateui = (InvoiceStateDateUI*) widget;
InvoiceStateDates.removeOne(invoicestatedateui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block0Layout->removeRow(sender);
}
}
void InvoiceUI::addInvoiceFreeline(){ 
InvoiceFreelineUI* invoicefreelineui = new InvoiceFreelineUI();
invoicefreelineui->block0Layout->hideRow(invoicefreelineui->invoice);
invoicefreelineui->controllers->setFixedHeight(0);
InvoiceFreelines.append(invoicefreelineui);
RemovebtnWidgets* rminvoicefreeline = new RemovebtnWidgets(0,invoicefreelineui);
QObject::connect(rminvoicefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceFreeline(QWidget*)));
block0Layout->addRow("InvoiceFreeline"+QString::number(InvoiceFreelines.count()),rminvoicefreeline);
}
void InvoiceUI::addInvoiceFreeline(InvoiceFreeline* InvoiceFreeline){ 
InvoiceFreelineUI* invoicefreelineui = new InvoiceFreelineUI();
invoicefreelineui->block0Layout->hideRow(invoicefreelineui->invoice);
invoicefreelineui->controllers->setFixedHeight(0);
invoicefreelineui->fill(InvoiceFreeline);
InvoiceFreelines.append(invoicefreelineui);
RemovebtnWidgets* rminvoicefreeline = new RemovebtnWidgets(0,invoicefreelineui);
QObject::connect(rminvoicefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceFreeline(QWidget*)));
block0Layout->addRow(QObject::tr("InvoiceFreeline") +QString::number(InvoiceFreelines.count()),rminvoicefreeline);
}
void InvoiceUI::removeInvoiceFreeline(QWidget* widget){ 
if(InvoiceFreelines.count()  > 0){
InvoiceFreelineUI* invoicefreelineui = (InvoiceFreelineUI*) widget;
InvoiceFreelines.removeOne(invoicefreelineui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block0Layout->removeRow(sender);
}
}
void InvoiceUI::addPayment(){ 
PaymentUI* paymentui = new PaymentUI();
paymentui->block0Layout->hideRow(paymentui->invoice);
paymentui->controllers->setFixedHeight(0);
Payments.append(paymentui);
RemovebtnWidgets* rmpayment = new RemovebtnWidgets(0,paymentui);
QObject::connect(rmpayment, SIGNAL(removePressed(QWidget*)), this, SLOT(removePayment(QWidget*)));
block0Layout->addRow("Payment"+QString::number(Payments.count()),rmpayment);
}
void InvoiceUI::addPayment(Payment* Payment){ 
PaymentUI* paymentui = new PaymentUI();
paymentui->block0Layout->hideRow(paymentui->invoice);
paymentui->controllers->setFixedHeight(0);
paymentui->fill(Payment);
Payments.append(paymentui);
RemovebtnWidgets* rmpayment = new RemovebtnWidgets(0,paymentui);
QObject::connect(rmpayment, SIGNAL(removePressed(QWidget*)), this, SLOT(removePayment(QWidget*)));
block0Layout->addRow(QObject::tr("Payment") +QString::number(Payments.count()),rmpayment);
}
void InvoiceUI::removePayment(QWidget* widget){ 
if(Payments.count()  > 0){
PaymentUI* paymentui = (PaymentUI*) widget;
Payments.removeOne(paymentui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block0Layout->removeRow(sender);
}
}
void InvoiceUI::fill(Invoice* invoice){ 
clear();
this->invoice = invoice;
creationdate->setDate(QDate::fromString(invoice->CreationDate));
enddate->setDate(QDate::fromString(invoice->EndDate));
duedate->setDate(QDate::fromString(invoice->DueDate));
discount->setText(QString::number(invoice->discount));
allowance->setText(QString::number(invoice->Allowance));
foreach(InvoiceStateDate* invoicestatedate, invoice->invoicestatedates) {
addInvoiceStateDate(invoicestatedate);
}
foreach(InvoiceFreeline* invoicefreeline, invoice->invoicefreelines) {
addInvoiceFreeline(invoicefreeline);
}
foreach(Payment* payment, invoice->payments) {
addPayment(payment);
}
header->setText(invoice->Header);
footer->setText(invoice->Footer);
} 
void InvoiceUI::clear(){ 
delete this->invoice;
this->InvoiceStateDates.clear();
this->InvoiceFreelines.clear();
this->Payments.clear();
creationdate->setDate(QDate::currentDate());
enddate->setDate(QDate::currentDate());
duedate->setDate(QDate::currentDate());
discount->setText("");
allowance->setText("");
header->setText("");
footer->setText("");
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->invoice = new Invoice();
} 
void InvoiceUI::selectInvoice(){ 
if(Invoice::GetStringList().contains(QString::number(this->invoice->InvoiceSerialID)))
{
Invoice* con = Invoice::Get(QString::number(this->invoice->InvoiceSerialID));
if(this->invoice->InvoiceID != con->InvoiceID){
fill(con);
}
}
else if(invoice->InvoiceID != 0)
clear();
}
bool InvoiceUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!invoiceserial->isHidden()) 
invoice->InvoiceSerialID = invoiceserial->getKey();
if(creationdate->text().trimmed().isEmpty()){
errors = true;
errorString += "Creation Date Can't be Empty! \n";
creationdate->setObjectName("error");
creationdate->style()->unpolish(creationdate);
creationdate->style()->polish(creationdate);
creationdate->update();
}
else { 
creationdate->setObjectName("creationdate");
creationdate->style()->unpolish(creationdate);
creationdate->style()->polish(creationdate);
creationdate->update();
invoice->CreationDate = creationdate->text().trimmed();
}
if(enddate->text().trimmed().isEmpty()){
errors = true;
errorString += "End Date Can't be Empty! \n";
enddate->setObjectName("error");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
}
else { 
enddate->setObjectName("enddate");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
invoice->EndDate = enddate->text().trimmed();
}
if(!invoiceperiod->isHidden()) 
invoice->InvoicePeriodID = invoiceperiod->getKey();
if(!invoiceyear->isHidden()) 
invoice->InvoiceYearID = invoiceyear->getKey();
if(!project->isHidden()) 
invoice->ProjectID = project->getKey();
if(duedate->text().trimmed().isEmpty()){
errors = true;
errorString += "Due Date Can't be Empty! \n";
duedate->setObjectName("error");
duedate->style()->unpolish(duedate);
duedate->style()->polish(duedate);
duedate->update();
}
else { 
duedate->setObjectName("duedate");
duedate->style()->unpolish(duedate);
duedate->style()->polish(duedate);
duedate->update();
invoice->DueDate = duedate->text().trimmed();
}
if(discount->text().trimmed().isEmpty()){
errors = true;
errorString += "discount Can't be Empty! \n";
discount->setObjectName("error");
discount->style()->unpolish(discount);
discount->style()->polish(discount);
discount->update();
}
else { 
discount->setObjectName("discount");
discount->style()->unpolish(discount);
discount->style()->polish(discount);
discount->update();
invoice->discount = discount->text().trimmed().toDouble();
}
if(allowance->text().trimmed().isEmpty()){
errors = true;
errorString += "Allowance Can't be Empty! \n";
allowance->setObjectName("error");
allowance->style()->unpolish(allowance);
allowance->style()->polish(allowance);
allowance->update();
}
else { 
allowance->setObjectName("allowance");
allowance->style()->unpolish(allowance);
allowance->style()->polish(allowance);
allowance->update();
invoice->Allowance = allowance->text().trimmed().toDouble();
}
for(int j = 0; j < InvoiceFreelines.length(); j++){
InvoiceFreelines.at(j)->description->setObjectName("description");
InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->update();
for(int w = 0; w < InvoiceFreelines.length(); w++){
if(InvoiceFreelines.at(j) != InvoiceFreelines.at(w))
if(InvoiceFreelines.at(j)->description->text() == InvoiceFreelines.at(w)->description->text()){
errors = true; 
 errorString += "InvoiceFreeline has the same description \n";
InvoiceFreelines.at(j)->description->setObjectName("error");
InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->update();
}}}
if(header->text().trimmed().isEmpty()){
errors = true;
errorString += "Header Can't be Empty! \n";
header->setObjectName("error");
header->style()->unpolish(header);
header->style()->polish(header);
header->update();
}
else { 
header->setObjectName("header");
header->style()->unpolish(header);
header->style()->polish(header);
header->update();
invoice->Header = header->text().trimmed();
}
if(footer->text().trimmed().isEmpty()){
errors = true;
errorString += "Footer Can't be Empty! \n";
footer->setObjectName("error");
footer->style()->unpolish(footer);
footer->style()->polish(footer);
footer->update();
}
else { 
footer->setObjectName("footer");
footer->style()->unpolish(footer);
footer->style()->polish(footer);
footer->update();
invoice->Footer = footer->text().trimmed();
}
if(!errors) {
invoice->save();
for(int i = 0; i < InvoiceStateDates.length(); i++){
InvoiceStateDates.at(i)->invoicestatedate->InvoiceID= invoice->InvoiceID;
if(!InvoiceStateDates.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < invoice->invoicestatedates.length(); i++){
bool flag = false;
for(int j = 0; j < InvoiceStateDates.length(); j++){
if(invoice->invoicestatedates.at(i)->InvoiceStateDateID == InvoiceStateDates.at(j)->invoicestatedate->InvoiceStateDateID){
flag = true;}}
if(!flag){
invoice->invoicestatedates.at(i)->remove();}
}
for(int i = 0; i < InvoiceFreelines.length(); i++){
InvoiceFreelines.at(i)->invoicefreeline->InvoiceID= invoice->InvoiceID;
if(!InvoiceFreelines.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < invoice->invoicefreelines.length(); i++){
bool flag = false;
for(int j = 0; j < InvoiceFreelines.length(); j++){
if(invoice->invoicefreelines.at(i)->InvoiceFreelineID == InvoiceFreelines.at(j)->invoicefreeline->InvoiceFreelineID){
flag = true;}}
if(!flag){
invoice->invoicefreelines.at(i)->remove();}
}
for(int i = 0; i < Payments.length(); i++){
Payments.at(i)->payment->InvoiceID= invoice->InvoiceID;
if(!Payments.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < invoice->payments.length(); i++){
bool flag = false;
for(int j = 0; j < Payments.length(); j++){
if(invoice->payments.at(i)->PaymentID == Payments.at(j)->payment->PaymentID){
flag = true;}}
if(!flag){
invoice->payments.at(i)->remove();}
}
if(!errors){
InvoiceIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Invoice",errorString.trimmed());
return false; 
 }
}
void InvoiceUI::cancel(){ 
InvoiceIndexUI::ShowUI();
}
bool InvoiceUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(invoice->InvoiceSerialID == 0) 
invoice->InvoiceSerialID = invoiceserial->getKey();
if(creationdate->text().trimmed().isEmpty()){
errors = true;
errorString += "Creation Date Can't be Empty! \n";
creationdate->setObjectName("error");
creationdate->style()->unpolish(creationdate);
creationdate->style()->polish(creationdate);
creationdate->update();
}
else { 
creationdate->setObjectName("creationdate");
creationdate->style()->unpolish(creationdate);
creationdate->style()->polish(creationdate);
creationdate->update();
invoice->CreationDate = creationdate->text().trimmed();
}
if(enddate->text().trimmed().isEmpty()){
errors = true;
errorString += "End Date Can't be Empty! \n";
enddate->setObjectName("error");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
}
else { 
enddate->setObjectName("enddate");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
invoice->EndDate = enddate->text().trimmed();
}
if(invoice->InvoicePeriodID == 0) 
invoice->InvoicePeriodID = invoiceperiod->getKey();
if(invoice->InvoiceYearID == 0) 
invoice->InvoiceYearID = invoiceyear->getKey();
if(invoice->ProjectID == 0) 
invoice->ProjectID = project->getKey();
if(duedate->text().trimmed().isEmpty()){
errors = true;
errorString += "Due Date Can't be Empty! \n";
duedate->setObjectName("error");
duedate->style()->unpolish(duedate);
duedate->style()->polish(duedate);
duedate->update();
}
else { 
duedate->setObjectName("duedate");
duedate->style()->unpolish(duedate);
duedate->style()->polish(duedate);
duedate->update();
invoice->DueDate = duedate->text().trimmed();
}
if(discount->text().trimmed().isEmpty()){
errors = true;
errorString += "discount Can't be Empty! \n";
discount->setObjectName("error");
discount->style()->unpolish(discount);
discount->style()->polish(discount);
discount->update();
}
else { 
discount->setObjectName("discount");
discount->style()->unpolish(discount);
discount->style()->polish(discount);
discount->update();
invoice->discount = discount->text().trimmed().toDouble();
}
if(allowance->text().trimmed().isEmpty()){
errors = true;
errorString += "Allowance Can't be Empty! \n";
allowance->setObjectName("error");
allowance->style()->unpolish(allowance);
allowance->style()->polish(allowance);
allowance->update();
}
else { 
allowance->setObjectName("allowance");
allowance->style()->unpolish(allowance);
allowance->style()->polish(allowance);
allowance->update();
invoice->Allowance = allowance->text().trimmed().toDouble();
}
for(int j = 0; j < InvoiceFreelines.length(); j++){
InvoiceFreelines.at(j)->description->setObjectName("description");
InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->update();
for(int w = 0; w < InvoiceFreelines.length(); w++){
if(InvoiceFreelines.at(j) != InvoiceFreelines.at(w))
if(InvoiceFreelines.at(j)->description->text() == InvoiceFreelines.at(w)->description->text()){
errors = true; 
 errorString += "InvoiceFreeline has the same description \n";
InvoiceFreelines.at(j)->description->setObjectName("error");
InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
InvoiceFreelines.at(j)->description->update();
}}}
if(header->text().trimmed().isEmpty()){
errors = true;
errorString += "Header Can't be Empty! \n";
header->setObjectName("error");
header->style()->unpolish(header);
header->style()->polish(header);
header->update();
}
else { 
header->setObjectName("header");
header->style()->unpolish(header);
header->style()->polish(header);
header->update();
invoice->Header = header->text().trimmed();
}
if(footer->text().trimmed().isEmpty()){
errors = true;
errorString += "Footer Can't be Empty! \n";
footer->setObjectName("error");
footer->style()->unpolish(footer);
footer->style()->polish(footer);
footer->update();
}
else { 
footer->setObjectName("footer");
footer->style()->unpolish(footer);
footer->style()->polish(footer);
footer->update();
invoice->Footer = footer->text().trimmed();
}
for(int i = 0; i < InvoiceStateDates.length(); i++){
InvoiceStateDates.at(i)->invoicestatedate->InvoiceID= invoice->InvoiceID;
if(!InvoiceStateDates.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < InvoiceFreelines.length(); i++){
InvoiceFreelines.at(i)->invoicefreeline->InvoiceID= invoice->InvoiceID;
if(!InvoiceFreelines.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < Payments.length(); i++){
Payments.at(i)->payment->InvoiceID= invoice->InvoiceID;
if(!Payments.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "Invoice",errorString.trimmed());
return false; 
 }
}
