/**************************************************************************
**   File: deliveryorderui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
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

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
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
number = new QLineEdit();
number->setValidator( intValidator );
block0Layout->addRow("Number",number);
deliveryorderstatus = new ERPComboBox();
deliveryorderstatus->addItems(DeliveryOrderStatus::GetHashList());
block0Layout->addRow("Delivery Order Status",deliveryorderstatus);
contact = new ERPComboBox();
contact->addItems(Contact::GetHashList());
block0Layout->addRow("Contact",contact);
creationdate = new QLineEdit();
block0Layout->addRow("Creation Date",creationdate);
deliverydate = new QLineEdit();
block0Layout->addRow("Delivery Date",deliverydate);
note = new QLineEdit();
block0Layout->addRow("Note",note);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block1Layout->setMinimumWidth(330);
header = new QLineEdit();
block1Layout->addRow("Header",header);
footer = new QLineEdit();
block1Layout->addRow("Footer",footer);
deliveryaddress = new QLineEdit();
block1Layout->addRow("Delivery Address",deliveryaddress);
flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block2Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveDeliveryOrderStoreProductButtons = new AddRemoveButtons();
block2Layout->addRow("DeliveryOrderStoreProducts",addremoveDeliveryOrderStoreProductButtons);
QObject::connect(addremoveDeliveryOrderStoreProductButtons, SIGNAL(addPressed()), this, SLOT(addDeliveryOrderStoreProduct()));

flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block3Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveDeliveryOrderServiceButtons = new AddRemoveButtons();
block3Layout->addRow("DeliveryOrderServices",addremoveDeliveryOrderServiceButtons);
QObject::connect(addremoveDeliveryOrderServiceButtons, SIGNAL(addPressed()), this, SLOT(addDeliveryOrderService()));

flowLayout->addWidget(block3Layout);

block4Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block4Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveDeliveryOrderFreelineButtons = new AddRemoveButtons();
block4Layout->addRow("DeliveryOrderFreelines",addremoveDeliveryOrderFreelineButtons);
QObject::connect(addremoveDeliveryOrderFreelineButtons, SIGNAL(addPressed()), this, SLOT(addDeliveryOrderFreeline()));

flowLayout->addWidget(block4Layout);

}
ERPDisplay* DeliveryOrderUI::p_instance = 0;
void DeliveryOrderUI::ShowUI() {
	if (p_instance == 0) {
		p_instance = new DeliveryOrderUI(mainwindow::GetMainDisplay());
	}
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
deliveryorderstoreproductui->block0Layout->removeRow(deliveryorderstoreproductui->deliveryorder);
deliveryorderstoreproductui->controllers->setFixedHeight(0);
DeliveryOrderStoreProducts.append(deliveryorderstoreproductui);
RemovebtnWidgets* rmdeliveryorderstoreproduct = new RemovebtnWidgets(0,deliveryorderstoreproductui);
QObject::connect(rmdeliveryorderstoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderStoreProduct(QWidget*)));
block2Layout->addRow("DeliveryOrderStoreProduct"+QString::number(DeliveryOrderStoreProducts.count()),rmdeliveryorderstoreproduct);
}
void DeliveryOrderUI::addDeliveryOrderStoreProduct(DeliveryOrderStoreProduct* DeliveryOrderStoreProduct){
DeliveryOrderStoreProductUI* deliveryorderstoreproductui = new DeliveryOrderStoreProductUI();
deliveryorderstoreproductui->block0Layout->removeRow(deliveryorderstoreproductui->deliveryorder);
deliveryorderstoreproductui->controllers->setFixedHeight(0);
deliveryorderstoreproductui->fill(DeliveryOrderStoreProduct);
DeliveryOrderStoreProducts.append(deliveryorderstoreproductui);
RemovebtnWidgets* rmdeliveryorderstoreproduct = new RemovebtnWidgets(0,deliveryorderstoreproductui);
QObject::connect(rmdeliveryorderstoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderStoreProduct(QWidget*)));
block2Layout->addRow("DeliveryOrderStoreProduct"+QString::number(DeliveryOrderStoreProducts.count()),rmdeliveryorderstoreproduct);
}
void DeliveryOrderUI::removeDeliveryOrderStoreProduct(QWidget* widget){
if(DeliveryOrderStoreProducts.count()  > 0){
DeliveryOrderStoreProductUI* deliveryorderstoreproductui = (DeliveryOrderStoreProductUI*) widget;
DeliveryOrderStoreProducts.removeOne(deliveryorderstoreproductui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block2Layout->removeRow(sender);
}
}
void DeliveryOrderUI::addDeliveryOrderService(){
DeliveryOrderServiceUI* deliveryorderserviceui = new DeliveryOrderServiceUI();
deliveryorderserviceui->block0Layout->removeRow(deliveryorderserviceui->deliveryorder);
deliveryorderserviceui->controllers->setFixedHeight(0);
DeliveryOrderServices.append(deliveryorderserviceui);
RemovebtnWidgets* rmdeliveryorderservice = new RemovebtnWidgets(0,deliveryorderserviceui);
QObject::connect(rmdeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderService(QWidget*)));
block3Layout->addRow("DeliveryOrderService"+QString::number(DeliveryOrderServices.count()),rmdeliveryorderservice);
}
void DeliveryOrderUI::addDeliveryOrderService(DeliveryOrderService* DeliveryOrderService){
DeliveryOrderServiceUI* deliveryorderserviceui = new DeliveryOrderServiceUI();
deliveryorderserviceui->block0Layout->removeRow(deliveryorderserviceui->deliveryorder);
deliveryorderserviceui->controllers->setFixedHeight(0);
deliveryorderserviceui->fill(DeliveryOrderService);
DeliveryOrderServices.append(deliveryorderserviceui);
RemovebtnWidgets* rmdeliveryorderservice = new RemovebtnWidgets(0,deliveryorderserviceui);
QObject::connect(rmdeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderService(QWidget*)));
block3Layout->addRow("DeliveryOrderService"+QString::number(DeliveryOrderServices.count()),rmdeliveryorderservice);
}
void DeliveryOrderUI::removeDeliveryOrderService(QWidget* widget){
if(DeliveryOrderServices.count()  > 0){
DeliveryOrderServiceUI* deliveryorderserviceui = (DeliveryOrderServiceUI*) widget;
DeliveryOrderServices.removeOne(deliveryorderserviceui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block3Layout->removeRow(sender);
}
}
void DeliveryOrderUI::addDeliveryOrderFreeline(){
DeliveryOrderFreelineUI* deliveryorderfreelineui = new DeliveryOrderFreelineUI();
deliveryorderfreelineui->block0Layout->removeRow(deliveryorderfreelineui->deliveryorder);
deliveryorderfreelineui->controllers->setFixedHeight(0);
DeliveryOrderFreelines.append(deliveryorderfreelineui);
RemovebtnWidgets* rmdeliveryorderfreeline = new RemovebtnWidgets(0,deliveryorderfreelineui);
QObject::connect(rmdeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderFreeline(QWidget*)));
block4Layout->addRow("DeliveryOrderFreeline"+QString::number(DeliveryOrderFreelines.count()),rmdeliveryorderfreeline);
}
void DeliveryOrderUI::addDeliveryOrderFreeline(DeliveryOrderFreeline* DeliveryOrderFreeline){
DeliveryOrderFreelineUI* deliveryorderfreelineui = new DeliveryOrderFreelineUI();
deliveryorderfreelineui->block0Layout->removeRow(deliveryorderfreelineui->deliveryorder);
deliveryorderfreelineui->controllers->setFixedHeight(0);
deliveryorderfreelineui->fill(DeliveryOrderFreeline);
DeliveryOrderFreelines.append(deliveryorderfreelineui);
RemovebtnWidgets* rmdeliveryorderfreeline = new RemovebtnWidgets(0,deliveryorderfreelineui);
QObject::connect(rmdeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderFreeline(QWidget*)));
block4Layout->addRow("DeliveryOrderFreeline"+QString::number(DeliveryOrderFreelines.count()),rmdeliveryorderfreeline);
}
void DeliveryOrderUI::removeDeliveryOrderFreeline(QWidget* widget){
if(DeliveryOrderFreelines.count()  > 0){
DeliveryOrderFreelineUI* deliveryorderfreelineui = (DeliveryOrderFreelineUI*) widget;
DeliveryOrderFreelines.removeOne(deliveryorderfreelineui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block4Layout->removeRow(sender);
}
}
void DeliveryOrderUI::fill(DeliveryOrder* deliveryorder){
clear();
this->deliveryorder = deliveryorder;
title->setText(deliveryorder->Title);
number->setText(QString::number(deliveryorder->Number));
creationdate->setText(deliveryorder->CreationDate);
deliverydate->setText(deliveryorder->DeliveryDate);
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
title->setText("");
number->setText("");
creationdate->setText("");
deliverydate->setText("");
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
if(DeliveryOrder::GetStringList().contains(title->text()))
{
DeliveryOrder* con = DeliveryOrder::Get(title->text());
if(this->deliveryorder->DeliveryOrderID != con->DeliveryOrderID){
fill(con);
}
}
else if(deliveryorder->DeliveryOrderID != 0)
clear();
}
bool DeliveryOrderUI::save(){
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
deliveryorder->Title = title->text().trimmed();
}
if(number->text().trimmed().isEmpty()){
errors = true;
errorString += "Number Can't be Empty! \n";
number->setObjectName("error");
number->style()->unpolish(number);
number->style()->polish(number);
number->update();
}
else {
number->setObjectName("number");
number->style()->unpolish(number);
number->style()->polish(number);
number->update();
deliveryorder->Number = number->text().trimmed().toInt();
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
for(int j = 0; j < DeliveryOrderStoreProducts.length(); j++){
DeliveryOrderStoreProducts.at(j)->title->setObjectName("title");
DeliveryOrderStoreProducts.at(j)->title->style()->unpolish(DeliveryOrderStoreProducts.at(j)->title);
DeliveryOrderStoreProducts.at(j)->title->style()->polish(DeliveryOrderStoreProducts.at(j)->title);
DeliveryOrderStoreProducts.at(j)->title->update();
for(int w = 0; w < DeliveryOrderStoreProducts.length(); w++){
if(DeliveryOrderStoreProducts.at(j) != DeliveryOrderStoreProducts.at(w))
if(DeliveryOrderStoreProducts.at(j)->title->text() == DeliveryOrderStoreProducts.at(w)->title->text()){
errors = true;
 errorString += "DeliveryOrderStoreProduct has the same title \n";
DeliveryOrderStoreProducts.at(j)->title->setObjectName("error");
DeliveryOrderStoreProducts.at(j)->title->style()->unpolish(DeliveryOrderStoreProducts.at(j)->title);
DeliveryOrderStoreProducts.at(j)->title->style()->polish(DeliveryOrderStoreProducts.at(j)->title);
DeliveryOrderStoreProducts.at(j)->title->update();
}}}
for(int j = 0; j < DeliveryOrderServices.length(); j++){
DeliveryOrderServices.at(j)->title->setObjectName("title");
DeliveryOrderServices.at(j)->title->style()->unpolish(DeliveryOrderServices.at(j)->title);
DeliveryOrderServices.at(j)->title->style()->polish(DeliveryOrderServices.at(j)->title);
DeliveryOrderServices.at(j)->title->update();
for(int w = 0; w < DeliveryOrderServices.length(); w++){
if(DeliveryOrderServices.at(j) != DeliveryOrderServices.at(w))
if(DeliveryOrderServices.at(j)->title->text() == DeliveryOrderServices.at(w)->title->text()){
errors = true;
 errorString += "DeliveryOrderService has the same title \n";
DeliveryOrderServices.at(j)->title->setObjectName("error");
DeliveryOrderServices.at(j)->title->style()->unpolish(DeliveryOrderServices.at(j)->title);
DeliveryOrderServices.at(j)->title->style()->polish(DeliveryOrderServices.at(j)->title);
DeliveryOrderServices.at(j)->title->update();
}}}
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
