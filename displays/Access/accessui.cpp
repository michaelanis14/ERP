/**************************************************************************
**   File: accessui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "accessui.h"
#include "../MainWindow.h"

AccessUI::AccessUI(QWidget *parent) :ERPDisplay(parent)
{

access = new Access();
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
title = new QLineEdit();
block0Layout->addRow("Title",title);
tax = new QCheckBox();
block0Layout->addRow("Tax",tax);
employee = new QCheckBox();
block0Layout->addRow("Employee",employee);
contact = new QCheckBox();
block0Layout->addRow("Contact",contact);
contacttelephone = new QCheckBox();
block0Layout->addRow("Contact Telephone",contacttelephone);
contactemail = new QCheckBox();
block0Layout->addRow("Contact Email",contactemail);
bankaccount = new QCheckBox();
block0Layout->addRow("Bank Account",bankaccount);
contactclass = new QCheckBox();
block0Layout->addRow("Contact Class",contactclass);
contacttype = new QCheckBox();
block0Layout->addRow("Contact Type",contacttype);
country = new QCheckBox();
block0Layout->addRow("Country",country);
currency = new QCheckBox();
block0Layout->addRow("Currency",currency);
contactstatus = new QCheckBox();
block0Layout->addRow("Contact Status",contactstatus);
fieldtype = new QCheckBox();
block0Layout->addRow("Field Type",fieldtype);
contactfield = new QCheckBox();
block0Layout->addRow("Contact Field",contactfield);
contactfielddata = new QCheckBox();
block0Layout->addRow("Contact Field Data",contactfielddata);
contactpersonfield = new QCheckBox();
block0Layout->addRow("Contact Person Field",contactpersonfield);
contactpersonfielddata = new QCheckBox();
block0Layout->addRow("Contact Person Field Data",contactpersonfielddata);
contactperson = new QCheckBox();
block0Layout->addRow("Contact Person",contactperson);
contactpersontelephone = new QCheckBox();
block0Layout->addRow("Contact Person Telephone",contactpersontelephone);
contactpersonemail = new QCheckBox();
block0Layout->addRow("Contact Person Email",contactpersonemail);
projectstatus = new QCheckBox();
block0Layout->addRow("Project Status",projectstatus);
project = new QCheckBox();
block0Layout->addRow("Project",project);
projectfile = new QCheckBox();
block0Layout->addRow("Project File",projectfile);
projectcontactperson = new QCheckBox();
block0Layout->addRow("Project Contact Person",projectcontactperson);
projectproduct = new QCheckBox();
block0Layout->addRow("Project Product",projectproduct);
projectservice = new QCheckBox();
block0Layout->addRow("Project Service",projectservice);
unit = new QCheckBox();
block0Layout->addRow("Unit",unit);
productcategory = new QCheckBox();
block0Layout->addRow("Product Category",productcategory);
productimage = new QCheckBox();
block0Layout->addRow("Product Image",productimage);
product = new QCheckBox();
block0Layout->addRow("Product",product);
productfield = new QCheckBox();
block0Layout->addRow("Product Field",productfield);
productfielddata = new QCheckBox();
block0Layout->addRow("Product Field Data",productfielddata);
service = new QCheckBox();
block0Layout->addRow("Service",service);
store = new QCheckBox();
block0Layout->addRow("Store",store);
purchasestatus = new QCheckBox();
block0Layout->addRow("Purchase Status",purchasestatus);
purchaseserial = new QCheckBox();
block0Layout->addRow("Purchase Serial",purchaseserial);
purchase = new QCheckBox();
block0Layout->addRow("Purchase",purchase);
purchasestoreproduct = new QCheckBox();
block0Layout->addRow("Purchase Store Product",purchasestoreproduct);
purchasefreeline = new QCheckBox();
block0Layout->addRow("Purchase Free Line",purchasefreeline);
deliveryorderstatus = new QCheckBox();
block0Layout->addRow("Delivery Order Status",deliveryorderstatus);
deliveryorder = new QCheckBox();
block0Layout->addRow("Delivery Order",deliveryorder);
deliveryorderstoreproduct = new QCheckBox();
block0Layout->addRow("Delivery Order Store Product",deliveryorderstoreproduct);
deliveryorderservice = new QCheckBox();
block0Layout->addRow("Delivery Order Service",deliveryorderservice);
deliveryorderfreeline = new QCheckBox();
block0Layout->addRow("Delivery Order Freeline",deliveryorderfreeline);
invoiceperiod = new QCheckBox();
block0Layout->addRow("Invoice Period",invoiceperiod);
invoiceyear = new QCheckBox();
block0Layout->addRow("Invoice Year",invoiceyear);
invoicestate = new QCheckBox();
block0Layout->addRow("Invoice State",invoicestate);
invoiceserial = new QCheckBox();
block0Layout->addRow("Invoice Serial",invoiceserial);
invoice = new QCheckBox();
block0Layout->addRow("Invoice",invoice);
invoicestatedate = new QCheckBox();
block0Layout->addRow("Invoice State Date",invoicestatedate);
invoicefreeline = new QCheckBox();
block0Layout->addRow("Invoice Freeline",invoicefreeline);
paymenttype = new QCheckBox();
block0Layout->addRow("Payment Type",paymenttype);
payment = new QCheckBox();
block0Layout->addRow("Payment",payment);
task = new QCheckBox();
block0Layout->addRow("Task",task);
timebooking = new QCheckBox();
block0Layout->addRow("Time Booking",timebooking);
hashkey = new QLineEdit();
block0Layout->addRow("hashKey",hashkey);
employee = new ERPComboBox();
employee->addItems(Employee::GetPairList());
block0Layout->addRow("Employee",employee);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* AccessUI::p_instance = 0;
void AccessUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new AccessUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
AccessUI*AccessUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (AccessUI*) p_instance; 
}
void AccessUI::fill(Access* access){ 
clear();
this->access = access;
company->setChecked(access->Company);
title->setText(access->Title);
tax->setChecked(access->Tax);
employee->setChecked(access->Employee);
contact->setChecked(access->Contact);
contacttelephone->setChecked(access->ContactTelephone);
contactemail->setChecked(access->ContactEmail);
bankaccount->setChecked(access->BankAccount);
contactclass->setChecked(access->ContactClass);
contacttype->setChecked(access->ContactType);
country->setChecked(access->Country);
currency->setChecked(access->Currency);
contactstatus->setChecked(access->ContactStatus);
fieldtype->setChecked(access->FieldType);
contactfield->setChecked(access->ContactField);
contactfielddata->setChecked(access->ContactFieldData);
contactpersonfield->setChecked(access->ContactPersonField);
contactpersonfielddata->setChecked(access->ContactPersonFieldData);
contactperson->setChecked(access->ContactPerson);
contactpersontelephone->setChecked(access->ContactPersonTelephone);
contactpersonemail->setChecked(access->ContactPersonEmail);
projectstatus->setChecked(access->ProjectStatus);
project->setChecked(access->Project);
projectfile->setChecked(access->ProjectFile);
projectcontactperson->setChecked(access->ProjectContactPerson);
projectproduct->setChecked(access->ProjectProduct);
projectservice->setChecked(access->ProjectService);
unit->setChecked(access->Unit);
productcategory->setChecked(access->ProductCategory);
productimage->setChecked(access->ProductImage);
product->setChecked(access->Product);
productfield->setChecked(access->ProductField);
productfielddata->setChecked(access->ProductFieldData);
service->setChecked(access->Service);
store->setChecked(access->Store);
purchasestatus->setChecked(access->PurchaseStatus);
purchaseserial->setChecked(access->PurchaseSerial);
purchase->setChecked(access->Purchase);
purchasestoreproduct->setChecked(access->PurchaseStoreProduct);
purchasefreeline->setChecked(access->PurchaseFreeLine);
deliveryorderstatus->setChecked(access->DeliveryOrderStatus);
deliveryorder->setChecked(access->DeliveryOrder);
deliveryorderstoreproduct->setChecked(access->DeliveryOrderStoreProduct);
deliveryorderservice->setChecked(access->DeliveryOrderService);
deliveryorderfreeline->setChecked(access->DeliveryOrderFreeline);
invoiceperiod->setChecked(access->InvoicePeriod);
invoiceyear->setChecked(access->InvoiceYear);
invoicestate->setChecked(access->InvoiceState);
invoiceserial->setChecked(access->InvoiceSerial);
invoice->setChecked(access->Invoice);
invoicestatedate->setDate(QDate::fromString(access->InvoiceStateDate));
invoicefreeline->setChecked(access->InvoiceFreeline);
paymenttype->setChecked(access->PaymentType);
payment->setChecked(access->Payment);
task->setChecked(access->Task);
timebooking->setChecked(access->TimeBooking);
hashkey->setText(access->hashKey);
} 
void AccessUI::clear(){ 
delete this->access;
company->setChecked(false);
title->setText("");
tax->setChecked(false);
employee->setChecked(false);
contact->setChecked(false);
contacttelephone->setChecked(false);
contactemail->setChecked(false);
bankaccount->setChecked(false);
contactclass->setChecked(false);
contacttype->setChecked(false);
country->setChecked(false);
currency->setChecked(false);
contactstatus->setChecked(false);
fieldtype->setChecked(false);
contactfield->setChecked(false);
contactfielddata->setChecked(false);
contactpersonfield->setChecked(false);
contactpersonfielddata->setChecked(false);
contactperson->setChecked(false);
contactpersontelephone->setChecked(false);
contactpersonemail->setChecked(false);
projectstatus->setChecked(false);
project->setChecked(false);
projectfile->setChecked(false);
projectcontactperson->setChecked(false);
projectproduct->setChecked(false);
projectservice->setChecked(false);
unit->setChecked(false);
productcategory->setChecked(false);
productimage->setChecked(false);
product->setChecked(false);
productfield->setChecked(false);
productfielddata->setChecked(false);
service->setChecked(false);
store->setChecked(false);
purchasestatus->setChecked(false);
purchaseserial->setChecked(false);
purchase->setChecked(false);
purchasestoreproduct->setChecked(false);
purchasefreeline->setChecked(false);
deliveryorderstatus->setChecked(false);
deliveryorder->setChecked(false);
deliveryorderstoreproduct->setChecked(false);
deliveryorderservice->setChecked(false);
deliveryorderfreeline->setChecked(false);
invoiceperiod->setChecked(false);
invoiceyear->setChecked(false);
invoicestate->setChecked(false);
invoiceserial->setChecked(false);
invoice->setChecked(false);
invoicestatedate->setDate(QDate::currentDate());
invoicefreeline->setChecked(false);
paymenttype->setChecked(false);
payment->setChecked(false);
task->setChecked(false);
timebooking->setChecked(false);
hashkey->setText("");
this->access = new Access();
} 
void AccessUI::selectAccess(){ 
if(Access::GetStringList().contains(this->access->Title))
{
Access* con = Access::Get(this->access->Title);
if(this->access->AccessID != con->AccessID){
fill(con);
}
}
else if(access->AccessID != 0)
clear();
}
bool AccessUI::save(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += "Title Can't be Empty! \n";
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
access->Title = title->text().trimmed();
}
access->Tax = tax->text().trimmed().toInt();
access->Employee = employee->text().trimmed().toInt();
access->Contact = contact->text().trimmed().toInt();
access->ContactTelephone = contacttelephone->text().trimmed().toInt();
access->ContactEmail = contactemail->text().trimmed().toInt();
access->BankAccount = bankaccount->text().trimmed().toInt();
access->ContactClass = contactclass->text().trimmed().toInt();
access->ContactType = contacttype->text().trimmed().toInt();
access->Country = country->text().trimmed().toInt();
access->Currency = currency->text().trimmed().toInt();
access->ContactStatus = contactstatus->text().trimmed().toInt();
access->FieldType = fieldtype->text().trimmed().toInt();
access->ContactField = contactfield->text().trimmed().toInt();
access->ContactFieldData = contactfielddata->text().trimmed().toInt();
access->ContactPersonField = contactpersonfield->text().trimmed().toInt();
access->ContactPersonFieldData = contactpersonfielddata->text().trimmed().toInt();
access->ContactPerson = contactperson->text().trimmed().toInt();
access->ContactPersonTelephone = contactpersontelephone->text().trimmed().toInt();
access->ContactPersonEmail = contactpersonemail->text().trimmed().toInt();
access->ProjectStatus = projectstatus->text().trimmed().toInt();
access->Project = project->text().trimmed().toInt();
access->ProjectFile = projectfile->text().trimmed().toInt();
access->ProjectContactPerson = projectcontactperson->text().trimmed().toInt();
access->ProjectProduct = projectproduct->text().trimmed().toInt();
access->ProjectService = projectservice->text().trimmed().toInt();
access->Unit = unit->text().trimmed().toInt();
access->ProductCategory = productcategory->text().trimmed().toInt();
access->ProductImage = productimage->text().trimmed().toInt();
access->Product = product->text().trimmed().toInt();
access->ProductField = productfield->text().trimmed().toInt();
access->ProductFieldData = productfielddata->text().trimmed().toInt();
access->Service = service->text().trimmed().toInt();
access->Store = store->text().trimmed().toInt();
access->PurchaseStatus = purchasestatus->text().trimmed().toInt();
access->PurchaseSerial = purchaseserial->text().trimmed().toInt();
access->Purchase = purchase->text().trimmed().toInt();
access->PurchaseStoreProduct = purchasestoreproduct->text().trimmed().toInt();
access->PurchaseFreeLine = purchasefreeline->text().trimmed().toInt();
access->DeliveryOrderStatus = deliveryorderstatus->text().trimmed().toInt();
access->DeliveryOrder = deliveryorder->text().trimmed().toInt();
access->DeliveryOrderStoreProduct = deliveryorderstoreproduct->text().trimmed().toInt();
access->DeliveryOrderService = deliveryorderservice->text().trimmed().toInt();
access->DeliveryOrderFreeline = deliveryorderfreeline->text().trimmed().toInt();
access->InvoicePeriod = invoiceperiod->text().trimmed().toInt();
access->InvoiceYear = invoiceyear->text().trimmed().toInt();
access->InvoiceState = invoicestate->text().trimmed().toInt();
access->InvoiceSerial = invoiceserial->text().trimmed().toInt();
access->Invoice = invoice->text().trimmed().toInt();
access->InvoiceStateDate = invoicestatedate->text().trimmed().toInt();
access->InvoiceFreeline = invoicefreeline->text().trimmed().toInt();
access->PaymentType = paymenttype->text().trimmed().toInt();
access->Payment = payment->text().trimmed().toInt();
access->Task = task->text().trimmed().toInt();
access->TimeBooking = timebooking->text().trimmed().toInt();
if(hashkey->text().trimmed().isEmpty()){
errors = true;
errorString += "hashKey Can't be Empty! \n";
hashkey->setObjectName("error");
hashkey->style()->unpolish(hashkey);
hashkey->style()->polish(hashkey);
hashkey->update();
}
else { 
hashkey->setObjectName("hashkey");
hashkey->style()->unpolish(hashkey);
hashkey->style()->polish(hashkey);
hashkey->update();
access->hashKey = hashkey->text().trimmed();
}
if(!employee->isHidden()) 
access->EmployeeID = employee->getKey();
if(createdon->text().trimmed().isEmpty()){
errors = true;
errorString += "Created O N Can't be Empty! \n";
createdon->setObjectName("error");
createdon->style()->unpolish(createdon);
createdon->style()->polish(createdon);
createdon->update();
}
else { 
createdon->setObjectName("createdon");
createdon->style()->unpolish(createdon);
createdon->style()->polish(createdon);
createdon->update();
access->CreatedON = createdon->text().trimmed();
}
if(editedon->text().trimmed().isEmpty()){
errors = true;
errorString += "Edited O N Can't be Empty! \n";
editedon->setObjectName("error");
editedon->style()->unpolish(editedon);
editedon->style()->polish(editedon);
editedon->update();
}
else { 
editedon->setObjectName("editedon");
editedon->style()->unpolish(editedon);
editedon->style()->polish(editedon);
editedon->update();
access->EditedON = editedon->text().trimmed();
}
if(!errors) {
access->save();
if(!errors){
AccessIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Access",errorString.trimmed());
return false; 
 }
}
void AccessUI::cancel(){ 
AccessIndexUI::ShowUI();
}
bool AccessUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += "Title Can't be Empty! \n";
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
access->Title = title->text().trimmed();
}
access->Tax = tax->text().trimmed().toInt();
access->Employee = employee->text().trimmed().toInt();
access->Contact = contact->text().trimmed().toInt();
access->ContactTelephone = contacttelephone->text().trimmed().toInt();
access->ContactEmail = contactemail->text().trimmed().toInt();
access->BankAccount = bankaccount->text().trimmed().toInt();
access->ContactClass = contactclass->text().trimmed().toInt();
access->ContactType = contacttype->text().trimmed().toInt();
access->Country = country->text().trimmed().toInt();
access->Currency = currency->text().trimmed().toInt();
access->ContactStatus = contactstatus->text().trimmed().toInt();
access->FieldType = fieldtype->text().trimmed().toInt();
access->ContactField = contactfield->text().trimmed().toInt();
access->ContactFieldData = contactfielddata->text().trimmed().toInt();
access->ContactPersonField = contactpersonfield->text().trimmed().toInt();
access->ContactPersonFieldData = contactpersonfielddata->text().trimmed().toInt();
access->ContactPerson = contactperson->text().trimmed().toInt();
access->ContactPersonTelephone = contactpersontelephone->text().trimmed().toInt();
access->ContactPersonEmail = contactpersonemail->text().trimmed().toInt();
access->ProjectStatus = projectstatus->text().trimmed().toInt();
access->Project = project->text().trimmed().toInt();
access->ProjectFile = projectfile->text().trimmed().toInt();
access->ProjectContactPerson = projectcontactperson->text().trimmed().toInt();
access->ProjectProduct = projectproduct->text().trimmed().toInt();
access->ProjectService = projectservice->text().trimmed().toInt();
access->Unit = unit->text().trimmed().toInt();
access->ProductCategory = productcategory->text().trimmed().toInt();
access->ProductImage = productimage->text().trimmed().toInt();
access->Product = product->text().trimmed().toInt();
access->ProductField = productfield->text().trimmed().toInt();
access->ProductFieldData = productfielddata->text().trimmed().toInt();
access->Service = service->text().trimmed().toInt();
access->Store = store->text().trimmed().toInt();
access->PurchaseStatus = purchasestatus->text().trimmed().toInt();
access->PurchaseSerial = purchaseserial->text().trimmed().toInt();
access->Purchase = purchase->text().trimmed().toInt();
access->PurchaseStoreProduct = purchasestoreproduct->text().trimmed().toInt();
access->PurchaseFreeLine = purchasefreeline->text().trimmed().toInt();
access->DeliveryOrderStatus = deliveryorderstatus->text().trimmed().toInt();
access->DeliveryOrder = deliveryorder->text().trimmed().toInt();
access->DeliveryOrderStoreProduct = deliveryorderstoreproduct->text().trimmed().toInt();
access->DeliveryOrderService = deliveryorderservice->text().trimmed().toInt();
access->DeliveryOrderFreeline = deliveryorderfreeline->text().trimmed().toInt();
access->InvoicePeriod = invoiceperiod->text().trimmed().toInt();
access->InvoiceYear = invoiceyear->text().trimmed().toInt();
access->InvoiceState = invoicestate->text().trimmed().toInt();
access->InvoiceSerial = invoiceserial->text().trimmed().toInt();
access->Invoice = invoice->text().trimmed().toInt();
access->InvoiceStateDate = invoicestatedate->text().trimmed().toInt();
access->InvoiceFreeline = invoicefreeline->text().trimmed().toInt();
access->PaymentType = paymenttype->text().trimmed().toInt();
access->Payment = payment->text().trimmed().toInt();
access->Task = task->text().trimmed().toInt();
access->TimeBooking = timebooking->text().trimmed().toInt();
if(hashkey->text().trimmed().isEmpty()){
errors = true;
errorString += "hashKey Can't be Empty! \n";
hashkey->setObjectName("error");
hashkey->style()->unpolish(hashkey);
hashkey->style()->polish(hashkey);
hashkey->update();
}
else { 
hashkey->setObjectName("hashkey");
hashkey->style()->unpolish(hashkey);
hashkey->style()->polish(hashkey);
hashkey->update();
access->hashKey = hashkey->text().trimmed();
}
if(access->EmployeeID == 0) 
access->EmployeeID = employee->getKey();
if(createdon->text().trimmed().isEmpty()){
errors = true;
errorString += "Created O N Can't be Empty! \n";
createdon->setObjectName("error");
createdon->style()->unpolish(createdon);
createdon->style()->polish(createdon);
createdon->update();
}
else { 
createdon->setObjectName("createdon");
createdon->style()->unpolish(createdon);
createdon->style()->polish(createdon);
createdon->update();
access->CreatedON = createdon->text().trimmed();
}
if(editedon->text().trimmed().isEmpty()){
errors = true;
errorString += "Edited O N Can't be Empty! \n";
editedon->setObjectName("error");
editedon->style()->unpolish(editedon);
editedon->style()->polish(editedon);
editedon->update();
}
else { 
editedon->setObjectName("editedon");
editedon->style()->unpolish(editedon);
editedon->style()->polish(editedon);
editedon->update();
access->EditedON = editedon->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "Access",errorString.trimmed());
return false; 
 }
}
