/**************************************************************************
**   File: deliveryorderui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderui.h"
#include "../MainWindow.h"

DeliveryOrderUI::DeliveryOrderUI(QWidget *parent) :ERPDisplay(parent)
{

deliveryorder = new DeliveryOrder();
flowLayout = new FlowLayout(formPanel);
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
serial = new QLineEdit();
block0Layout->addRow("Serial",serial);
barcode = new QLineEdit();
QObject::connect(barcode, SIGNAL(textChanged(QString)), this, SLOT(barcodeChanged(QString)));
block0Layout->addRow("Barcode",barcode);
barcodeDisplay = new Barcode(0,0); block0Layout->addRow("Barcode",barcodeDisplay); generatebarcode = new QPushButton("Generate Barcode"); QObject::connect(generatebarcode, SIGNAL(clicked()), this, SLOT(generateBarcode())); block0Layout->addRow("",generatebarcode);
deliveryorderstatus = new ERPComboBox();
deliveryorderstatus->addItems(DeliveryOrderStatus::GetPairList());
block0Layout->addRow("Delivery Order Status",deliveryorderstatus);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow("Contact",contact);
creationdate = new QDateEdit(QDate::currentDate());
creationdate->setCalendarPopup(true);
creationdate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow("Creation Date",creationdate);
deliverydate = new QDateEdit(QDate::currentDate());
deliverydate->setCalendarPopup(true);
deliverydate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow("Delivery Date",deliverydate);
note = new QLineEdit();
block0Layout->addRow("Note",note);
header = new QLineEdit();
block0Layout->addRow("Header",header);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block1Layout->setMinimumWidth(330);
footer = new QLineEdit();
block1Layout->addRow("Footer",footer);
deliveryaddress = new QLineEdit();
block1Layout->addRow("Delivery Address",deliveryaddress);
AddRemoveButtons* addremoveDeliveryOrderStoreProductButtons = new AddRemoveButtons();
block1Layout->addRow("DeliveryOrderStoreProducts",addremoveDeliveryOrderStoreProductButtons);
QObject::connect(addremoveDeliveryOrderStoreProductButtons, SIGNAL(addPressed()), this, SLOT(addDeliveryOrderStoreProduct()));

flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block2Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveDeliveryOrderServiceButtons = new AddRemoveButtons();
block2Layout->addRow("DeliveryOrderServices",addremoveDeliveryOrderServiceButtons);
QObject::connect(addremoveDeliveryOrderServiceButtons, SIGNAL(addPressed()), this, SLOT(addDeliveryOrderService()));

flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block3Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveDeliveryOrderFreelineButtons = new AddRemoveButtons();
block3Layout->addRow("DeliveryOrderFreelines",addremoveDeliveryOrderFreelineButtons);
QObject::connect(addremoveDeliveryOrderFreelineButtons, SIGNAL(addPressed()), this, SLOT(addDeliveryOrderFreeline()));

flowLayout->addWidget(block3Layout);

block4Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block4Layout->setMinimumWidth(330);
flowLayout->addWidget(block4Layout);

}
ERPDisplay* DeliveryOrderUI::p_instance = 0;
void DeliveryOrderUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
DeliveryOrderUI*DeliveryOrderUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderUI*) p_instance; 
}
void DeliveryOrderUI::addDeliveryOrderStoreProduct(){ 
DeliveryOrderStoreProductUI* deliveryorderstoreproductui = new DeliveryOrderStoreProductUI();
deliveryorderstoreproductui->block0Layout->hideRow(deliveryorderstoreproductui->deliveryorder);
deliveryorderstoreproductui->controllers->setFixedHeight(0);
DeliveryOrderStoreProducts.append(deliveryorderstoreproductui);
RemovebtnWidgets* rmdeliveryorderstoreproduct = new RemovebtnWidgets(0,deliveryorderstoreproductui);
QObject::connect(rmdeliveryorderstoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderStoreProduct(QWidget*)));
block1Layout->addRow("DeliveryOrderStoreProduct"+QString::number(DeliveryOrderStoreProducts.count()),rmdeliveryorderstoreproduct);
}
void DeliveryOrderUI::addDeliveryOrderStoreProduct(DeliveryOrderStoreProduct* DeliveryOrderStoreProduct){ 
DeliveryOrderStoreProductUI* deliveryorderstoreproductui = new DeliveryOrderStoreProductUI();
deliveryorderstoreproductui->block0Layout->hideRow(deliveryorderstoreproductui->deliveryorder);
deliveryorderstoreproductui->controllers->setFixedHeight(0);
deliveryorderstoreproductui->fill(DeliveryOrderStoreProduct);
DeliveryOrderStoreProducts.append(deliveryorderstoreproductui);
RemovebtnWidgets* rmdeliveryorderstoreproduct = new RemovebtnWidgets(0,deliveryorderstoreproductui);
QObject::connect(rmdeliveryorderstoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderStoreProduct(QWidget*)));
block1Layout->addRow("DeliveryOrderStoreProduct"+QString::number(DeliveryOrderStoreProducts.count()),rmdeliveryorderstoreproduct);
}
void DeliveryOrderUI::removeDeliveryOrderStoreProduct(QWidget* widget){ 
if(DeliveryOrderStoreProducts.count()  > 0){
DeliveryOrderStoreProductUI* deliveryorderstoreproductui = (DeliveryOrderStoreProductUI*) widget;
DeliveryOrderStoreProducts.removeOne(deliveryorderstoreproductui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block1Layout->removeRow(sender);
}
}
void DeliveryOrderUI::addDeliveryOrderService(){ 
DeliveryOrderServiceUI* deliveryorderserviceui = new DeliveryOrderServiceUI();
deliveryorderserviceui->block0Layout->hideRow(deliveryorderserviceui->deliveryorder);
deliveryorderserviceui->controllers->setFixedHeight(0);
DeliveryOrderServices.append(deliveryorderserviceui);
RemovebtnWidgets* rmdeliveryorderservice = new RemovebtnWidgets(0,deliveryorderserviceui);
QObject::connect(rmdeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderService(QWidget*)));
block2Layout->addRow("DeliveryOrderService"+QString::number(DeliveryOrderServices.count()),rmdeliveryorderservice);
}
void DeliveryOrderUI::addDeliveryOrderService(DeliveryOrderService* DeliveryOrderService){ 
DeliveryOrderServiceUI* deliveryorderserviceui = new DeliveryOrderServiceUI();
deliveryorderserviceui->block0Layout->hideRow(deliveryorderserviceui->deliveryorder);
deliveryorderserviceui->controllers->setFixedHeight(0);
deliveryorderserviceui->fill(DeliveryOrderService);
DeliveryOrderServices.append(deliveryorderserviceui);
RemovebtnWidgets* rmdeliveryorderservice = new RemovebtnWidgets(0,deliveryorderserviceui);
QObject::connect(rmdeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderService(QWidget*)));
block2Layout->addRow("DeliveryOrderService"+QString::number(DeliveryOrderServices.count()),rmdeliveryorderservice);
}
void DeliveryOrderUI::removeDeliveryOrderService(QWidget* widget){ 
if(DeliveryOrderServices.count()  > 0){
DeliveryOrderServiceUI* deliveryorderserviceui = (DeliveryOrderServiceUI*) widget;
DeliveryOrderServices.removeOne(deliveryorderserviceui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block2Layout->removeRow(sender);
}
}
void DeliveryOrderUI::addDeliveryOrderFreeline(){ 
DeliveryOrderFreelineUI* deliveryorderfreelineui = new DeliveryOrderFreelineUI();
deliveryorderfreelineui->block0Layout->hideRow(deliveryorderfreelineui->deliveryorder);
deliveryorderfreelineui->controllers->setFixedHeight(0);
DeliveryOrderFreelines.append(deliveryorderfreelineui);
RemovebtnWidgets* rmdeliveryorderfreeline = new RemovebtnWidgets(0,deliveryorderfreelineui);
QObject::connect(rmdeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderFreeline(QWidget*)));
block3Layout->addRow("DeliveryOrderFreeline"+QString::number(DeliveryOrderFreelines.count()),rmdeliveryorderfreeline);
}
void DeliveryOrderUI::addDeliveryOrderFreeline(DeliveryOrderFreeline* DeliveryOrderFreeline){ 
DeliveryOrderFreelineUI* deliveryorderfreelineui = new DeliveryOrderFreelineUI();
deliveryorderfreelineui->block0Layout->hideRow(deliveryorderfreelineui->deliveryorder);
deliveryorderfreelineui->controllers->setFixedHeight(0);
deliveryorderfreelineui->fill(DeliveryOrderFreeline);
DeliveryOrderFreelines.append(deliveryorderfreelineui);
RemovebtnWidgets* rmdeliveryorderfreeline = new RemovebtnWidgets(0,deliveryorderfreelineui);
QObject::connect(rmdeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderFreeline(QWidget*)));
block3Layout->addRow("DeliveryOrderFreeline"+QString::number(DeliveryOrderFreelines.count()),rmdeliveryorderfreeline);
}
void DeliveryOrderUI::removeDeliveryOrderFreeline(QWidget* widget){ 
if(DeliveryOrderFreelines.count()  > 0){
DeliveryOrderFreelineUI* deliveryorderfreelineui = (DeliveryOrderFreelineUI*) widget;
DeliveryOrderFreelines.removeOne(deliveryorderfreelineui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block3Layout->removeRow(sender);
}
}
void DeliveryOrderUI::fill(DeliveryOrder* deliveryorder){ 
clear();
this->deliveryorder = deliveryorder;
serial->setText(deliveryorder->Serial);
barcode->setText(deliveryorder->Barcode);
creationdate->setDate(QDate::fromString(deliveryorder->CreationDate));
deliverydate->setDate(QDate::fromString(deliveryorder->DeliveryDate));
note->setText(deliveryorder->Note);
header->setText(deliveryorder->Header);
footer->setText(deliveryorder->Footer);
deliveryaddress->setText(deliveryorder->DeliveryAddress);
foreach(DeliveryOrderStoreProduct* deliveryorderstoreproduct, deliveryorder->deliveryorderstoreproducts) {
addDeliveryOrderStoreProduct(deliveryorderstoreproduct);
}
foreach(DeliveryOrderService* deliveryorderservice, deliveryorder->deliveryorderservices) {
addDeliveryOrderService(deliveryorderservice);
}
foreach(DeliveryOrderFreeline* deliveryorderfreeline, deliveryorder->deliveryorderfreelines) {
addDeliveryOrderFreeline(deliveryorderfreeline);
}
} 
void DeliveryOrderUI::clear(){ 
delete this->deliveryorder;
this->DeliveryOrderStoreProducts.clear();
this->DeliveryOrderServices.clear();
this->DeliveryOrderFreelines.clear();
serial->setText("");
barcode->setText("");
creationdate->setDate(QDate::currentDate());
deliverydate->setDate(QDate::currentDate());
note->setText("");
header->setText("");
footer->setText("");
deliveryaddress->setText("");
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->deliveryorder = new DeliveryOrder();
} 
void DeliveryOrderUI::selectDeliveryOrder(){ 
if(DeliveryOrder::GetStringList().contains(this->deliveryorder->Serial))
{
DeliveryOrder* con = DeliveryOrder::Get(this->deliveryorder->Serial);
if(this->deliveryorder->DeliveryOrderID != con->DeliveryOrderID){
fill(con);
}
}
else if(deliveryorder->DeliveryOrderID != 0)
clear();
}
void DeliveryOrderUI::generateBarcode(){ QString number = ""; for(int i = 0; i < 13; i++)  number += QString::number(rand() % 10); barcode->setText(number); barcodeDisplay->barcode = number; barcodeDisplay->repaint(); }
void DeliveryOrderUI::barcodeChanged(QString barcode){ if(this->barcode->text().count() > 13) this->barcode->setText(this->barcode->text().remove(12,20)); barcodeDisplay->barcode = barcode; barcodeDisplay->repaint(); }
bool DeliveryOrderUI::save(){ 
bool errors = false;
QString errorString =  "";
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += "Serial Can't be Empty! \n";
serial->setObjectName("error");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
}
else { 
serial->setObjectName("serial");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
deliveryorder->Serial = serial->text().trimmed();
}
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
deliveryorder->Barcode = barcode->text().trimmed();
}
if(!deliveryorderstatus->isHidden()) 
deliveryorder->DeliveryOrderStatusID = deliveryorderstatus->getKey();
if(!contact->isHidden()) 
deliveryorder->ContactID = contact->getKey();
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
deliveryorder->CreationDate = creationdate->text().trimmed();
}
if(deliverydate->text().trimmed().isEmpty()){
errors = true;
errorString += "Delivery Date Can't be Empty! \n";
deliverydate->setObjectName("error");
deliverydate->style()->unpolish(deliverydate);
deliverydate->style()->polish(deliverydate);
deliverydate->update();
}
else { 
deliverydate->setObjectName("deliverydate");
deliverydate->style()->unpolish(deliverydate);
deliverydate->style()->polish(deliverydate);
deliverydate->update();
deliveryorder->DeliveryDate = deliverydate->text().trimmed();
}
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += "Note Can't be Empty! \n";
note->setObjectName("error");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
}
else { 
note->setObjectName("note");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
deliveryorder->Note = note->text().trimmed();
}
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
deliveryorder->Header = header->text().trimmed();
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
deliveryorder->Footer = footer->text().trimmed();
}
if(deliveryaddress->text().trimmed().isEmpty()){
errors = true;
errorString += "Delivery Address Can't be Empty! \n";
deliveryaddress->setObjectName("error");
deliveryaddress->style()->unpolish(deliveryaddress);
deliveryaddress->style()->polish(deliveryaddress);
deliveryaddress->update();
}
else { 
deliveryaddress->setObjectName("deliveryaddress");
deliveryaddress->style()->unpolish(deliveryaddress);
deliveryaddress->style()->polish(deliveryaddress);
deliveryaddress->update();
deliveryorder->DeliveryAddress = deliveryaddress->text().trimmed();
}
for(int j = 0; j < DeliveryOrderFreelines.length(); j++){
DeliveryOrderFreelines.at(j)->description->setObjectName("description");
DeliveryOrderFreelines.at(j)->description->style()->unpolish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->style()->polish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->update();
for(int w = 0; w < DeliveryOrderFreelines.length(); w++){
if(DeliveryOrderFreelines.at(j) != DeliveryOrderFreelines.at(w))
if(DeliveryOrderFreelines.at(j)->description->text() == DeliveryOrderFreelines.at(w)->description->text()){
errors = true; 
 errorString += "DeliveryOrderFreeline has the same description \n";
DeliveryOrderFreelines.at(j)->description->setObjectName("error");
DeliveryOrderFreelines.at(j)->description->style()->unpolish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->style()->polish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->update();
}}}
if(!errors) {
deliveryorder->save();
for(int i = 0; i < DeliveryOrderStoreProducts.length(); i++){
DeliveryOrderStoreProducts.at(i)->deliveryorderstoreproduct->DeliveryOrderID= deliveryorder->DeliveryOrderID;
if(!DeliveryOrderStoreProducts.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < deliveryorder->deliveryorderstoreproducts.length(); i++){
bool flag = false;
for(int j = 0; j < DeliveryOrderStoreProducts.length(); j++){
if(deliveryorder->deliveryorderstoreproducts.at(i)->DeliveryOrderStoreProductID == DeliveryOrderStoreProducts.at(j)->deliveryorderstoreproduct->DeliveryOrderStoreProductID){
flag = true;}}
if(!flag){
deliveryorder->deliveryorderstoreproducts.at(i)->remove();}
}
for(int i = 0; i < DeliveryOrderServices.length(); i++){
DeliveryOrderServices.at(i)->deliveryorderservice->DeliveryOrderID= deliveryorder->DeliveryOrderID;
if(!DeliveryOrderServices.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < deliveryorder->deliveryorderservices.length(); i++){
bool flag = false;
for(int j = 0; j < DeliveryOrderServices.length(); j++){
if(deliveryorder->deliveryorderservices.at(i)->DeliveryOrderServiceID == DeliveryOrderServices.at(j)->deliveryorderservice->DeliveryOrderServiceID){
flag = true;}}
if(!flag){
deliveryorder->deliveryorderservices.at(i)->remove();}
}
for(int i = 0; i < DeliveryOrderFreelines.length(); i++){
DeliveryOrderFreelines.at(i)->deliveryorderfreeline->DeliveryOrderID= deliveryorder->DeliveryOrderID;
if(!DeliveryOrderFreelines.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < deliveryorder->deliveryorderfreelines.length(); i++){
bool flag = false;
for(int j = 0; j < DeliveryOrderFreelines.length(); j++){
if(deliveryorder->deliveryorderfreelines.at(i)->DeliveryOrderFreelineID == DeliveryOrderFreelines.at(j)->deliveryorderfreeline->DeliveryOrderFreelineID){
flag = true;}}
if(!flag){
deliveryorder->deliveryorderfreelines.at(i)->remove();}
}
if(!errors){
DeliveryOrderIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "DeliveryOrder",errorString.trimmed());
return false; 
 }
}
void DeliveryOrderUI::cancel(){ 
DeliveryOrderIndexUI::ShowUI();
}
bool DeliveryOrderUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += "Serial Can't be Empty! \n";
serial->setObjectName("error");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
}
else { 
serial->setObjectName("serial");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
deliveryorder->Serial = serial->text().trimmed();
}
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
deliveryorder->Barcode = barcode->text().trimmed();
}
if(deliveryorder->DeliveryOrderStatusID == 0) 
deliveryorder->DeliveryOrderStatusID = deliveryorderstatus->getKey();
if(deliveryorder->ContactID == 0) 
deliveryorder->ContactID = contact->getKey();
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
deliveryorder->CreationDate = creationdate->text().trimmed();
}
if(deliverydate->text().trimmed().isEmpty()){
errors = true;
errorString += "Delivery Date Can't be Empty! \n";
deliverydate->setObjectName("error");
deliverydate->style()->unpolish(deliverydate);
deliverydate->style()->polish(deliverydate);
deliverydate->update();
}
else { 
deliverydate->setObjectName("deliverydate");
deliverydate->style()->unpolish(deliverydate);
deliverydate->style()->polish(deliverydate);
deliverydate->update();
deliveryorder->DeliveryDate = deliverydate->text().trimmed();
}
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += "Note Can't be Empty! \n";
note->setObjectName("error");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
}
else { 
note->setObjectName("note");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
deliveryorder->Note = note->text().trimmed();
}
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
deliveryorder->Header = header->text().trimmed();
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
deliveryorder->Footer = footer->text().trimmed();
}
if(deliveryaddress->text().trimmed().isEmpty()){
errors = true;
errorString += "Delivery Address Can't be Empty! \n";
deliveryaddress->setObjectName("error");
deliveryaddress->style()->unpolish(deliveryaddress);
deliveryaddress->style()->polish(deliveryaddress);
deliveryaddress->update();
}
else { 
deliveryaddress->setObjectName("deliveryaddress");
deliveryaddress->style()->unpolish(deliveryaddress);
deliveryaddress->style()->polish(deliveryaddress);
deliveryaddress->update();
deliveryorder->DeliveryAddress = deliveryaddress->text().trimmed();
}
for(int j = 0; j < DeliveryOrderFreelines.length(); j++){
DeliveryOrderFreelines.at(j)->description->setObjectName("description");
DeliveryOrderFreelines.at(j)->description->style()->unpolish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->style()->polish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->update();
for(int w = 0; w < DeliveryOrderFreelines.length(); w++){
if(DeliveryOrderFreelines.at(j) != DeliveryOrderFreelines.at(w))
if(DeliveryOrderFreelines.at(j)->description->text() == DeliveryOrderFreelines.at(w)->description->text()){
errors = true; 
 errorString += "DeliveryOrderFreeline has the same description \n";
DeliveryOrderFreelines.at(j)->description->setObjectName("error");
DeliveryOrderFreelines.at(j)->description->style()->unpolish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->style()->polish(DeliveryOrderFreelines.at(j)->description);
DeliveryOrderFreelines.at(j)->description->update();
}}}
for(int i = 0; i < DeliveryOrderStoreProducts.length(); i++){
DeliveryOrderStoreProducts.at(i)->deliveryorderstoreproduct->DeliveryOrderID= deliveryorder->DeliveryOrderID;
if(!DeliveryOrderStoreProducts.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < DeliveryOrderServices.length(); i++){
DeliveryOrderServices.at(i)->deliveryorderservice->DeliveryOrderID= deliveryorder->DeliveryOrderID;
if(!DeliveryOrderServices.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < DeliveryOrderFreelines.length(); i++){
DeliveryOrderFreelines.at(i)->deliveryorderfreeline->DeliveryOrderID= deliveryorder->DeliveryOrderID;
if(!DeliveryOrderFreelines.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "DeliveryOrder",errorString.trimmed());
return false; 
 }
}
