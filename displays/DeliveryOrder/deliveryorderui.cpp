/**************************************************************************
**   File: deliveryorderui.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderui.h"
#include "../Login/loginui.h"
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
deliveryorderserial = new ERPComboBox();
deliveryorderserial->addItems(DeliveryOrderSerial::GetPairList());
block0Layout->addRow(QObject::tr("Delivery Order Serial"),deliveryorderserial);
deliveryorderstatus = new ERPComboBox();
deliveryorderstatus->addItems(DeliveryOrderStatus::GetPairList());
block0Layout->addRow(QObject::tr("Delivery Order Status"),deliveryorderstatus);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
project = new ERPComboBox();
project->addItems(Project::GetPairList());
block0Layout->addRow(QObject::tr("Project"),project);
creationdate = new QDateEdit(QDate::currentDate());
creationdate->setCalendarPopup(true);
creationdate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Creation Date"),creationdate);
deliverydate = new QDateEdit(QDate::currentDate());
deliverydate->setCalendarPopup(true);
deliverydate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Delivery Date"),deliverydate);
note = new QLineEdit();
block0Layout->addRow(QObject::tr("Note"),note);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block1Layout->setMinimumWidth(330);
header = new QLineEdit();
block1Layout->addRow(QObject::tr("Header"),header);
footer = new QLineEdit();
block1Layout->addRow(QObject::tr("Footer"),footer);
deliveryaddress = new QLineEdit();
block1Layout->addRow(QObject::tr("Delivery Address"),deliveryaddress);
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
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->DeliveryOrder) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new DeliveryOrderUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
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
block2Layout->addRow(QObject::tr("DeliveryOrderStoreProduct")+QString::number(DeliveryOrderStoreProducts.count()),rmdeliveryorderstoreproduct);
}
void DeliveryOrderUI::addDeliveryOrderStoreProduct(DeliveryOrderStoreProduct* deliveryorderstoreproduct){ 
DeliveryOrderStoreProductUI* deliveryorderstoreproductui = new DeliveryOrderStoreProductUI();
deliveryorderstoreproductui->block0Layout->hideRow(deliveryorderstoreproductui->deliveryorder);
deliveryorderstoreproductui->controllers->setFixedHeight(0);
deliveryorderstoreproductui->fill(deliveryorderstoreproduct);
DeliveryOrderStoreProducts.append(deliveryorderstoreproductui);
RemovebtnWidgets* rmdeliveryorderstoreproduct = new RemovebtnWidgets(0,deliveryorderstoreproductui);
QObject::connect(rmdeliveryorderstoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderStoreProduct(QWidget*)));
block2Layout->addRow(QObject::tr("DeliveryOrderStoreProduct") +QString::number(DeliveryOrderStoreProducts.count()),rmdeliveryorderstoreproduct);
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
deliveryorderserviceui->block0Layout->hideRow(deliveryorderserviceui->deliveryorder);
deliveryorderserviceui->controllers->setFixedHeight(0);
DeliveryOrderServices.append(deliveryorderserviceui);
RemovebtnWidgets* rmdeliveryorderservice = new RemovebtnWidgets(0,deliveryorderserviceui);
QObject::connect(rmdeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderService(QWidget*)));
block3Layout->addRow(QObject::tr("DeliveryOrderService")+QString::number(DeliveryOrderServices.count()),rmdeliveryorderservice);
}
void DeliveryOrderUI::addDeliveryOrderService(DeliveryOrderService* deliveryorderservice){ 
DeliveryOrderServiceUI* deliveryorderserviceui = new DeliveryOrderServiceUI();
deliveryorderserviceui->block0Layout->hideRow(deliveryorderserviceui->deliveryorder);
deliveryorderserviceui->controllers->setFixedHeight(0);
deliveryorderserviceui->fill(deliveryorderservice);
DeliveryOrderServices.append(deliveryorderserviceui);
RemovebtnWidgets* rmdeliveryorderservice = new RemovebtnWidgets(0,deliveryorderserviceui);
QObject::connect(rmdeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderService(QWidget*)));
block3Layout->addRow(QObject::tr("DeliveryOrderService") +QString::number(DeliveryOrderServices.count()),rmdeliveryorderservice);
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
deliveryorderfreelineui->block0Layout->hideRow(deliveryorderfreelineui->deliveryorder);
deliveryorderfreelineui->controllers->setFixedHeight(0);
DeliveryOrderFreelines.append(deliveryorderfreelineui);
RemovebtnWidgets* rmdeliveryorderfreeline = new RemovebtnWidgets(0,deliveryorderfreelineui);
QObject::connect(rmdeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderFreeline(QWidget*)));
block4Layout->addRow(QObject::tr("DeliveryOrderFreeline")+QString::number(DeliveryOrderFreelines.count()),rmdeliveryorderfreeline);
}
void DeliveryOrderUI::addDeliveryOrderFreeline(DeliveryOrderFreeline* deliveryorderfreeline){ 
DeliveryOrderFreelineUI* deliveryorderfreelineui = new DeliveryOrderFreelineUI();
deliveryorderfreelineui->block0Layout->hideRow(deliveryorderfreelineui->deliveryorder);
deliveryorderfreelineui->controllers->setFixedHeight(0);
deliveryorderfreelineui->fill(deliveryorderfreeline);
DeliveryOrderFreelines.append(deliveryorderfreelineui);
RemovebtnWidgets* rmdeliveryorderfreeline = new RemovebtnWidgets(0,deliveryorderfreelineui);
QObject::connect(rmdeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeDeliveryOrderFreeline(QWidget*)));
block4Layout->addRow(QObject::tr("DeliveryOrderFreeline") +QString::number(DeliveryOrderFreelines.count()),rmdeliveryorderfreeline);
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
deliveryorderserial->setIndexByKey(deliveryorder->DeliveryOrderSerialID);
deliveryorderstatus->setIndexByKey(deliveryorder->DeliveryOrderStatusID);
contact->setIndexByKey(deliveryorder->ContactID);
project->setIndexByKey(deliveryorder->ProjectID);
creationdate->setDate(deliveryorder->CreationDate);
deliverydate->setDate(deliveryorder->DeliveryDate);
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
if(DeliveryOrder::GetStringList().contains(QString::number(this->deliveryorder->DeliveryOrderSerialID)))
{
DeliveryOrder* con = DeliveryOrder::Get(QString::number(this->deliveryorder->DeliveryOrderSerialID));
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
if(!deliveryorderserial->isHidden()) 
deliveryorder->DeliveryOrderSerialID = deliveryorderserial->getKey();
if(!deliveryorderstatus->isHidden()) 
deliveryorder->DeliveryOrderStatusID = deliveryorderstatus->getKey();
if(!contact->isHidden()) 
deliveryorder->ContactID = contact->getKey();
if(!project->isHidden()) 
deliveryorder->ProjectID = project->getKey();
if(creationdate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Creation Date Can't be Empty! \n");
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
deliveryorder->CreationDate.setDate(creationdate->date().year(),creationdate->date().month(),creationdate->date().day());
}
if(deliverydate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Delivery Date Can't be Empty! \n");
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
deliveryorder->DeliveryDate.setDate(deliverydate->date().year(),deliverydate->date().month(),deliverydate->date().day());
}
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Note Can't be Empty! \n");
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
errorString += QObject::tr("Header Can't be Empty! \n");
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
errorString += QObject::tr("Footer Can't be Empty! \n");
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
errorString += QObject::tr("Delivery Address Can't be Empty! \n");
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
 errorString += QObject::tr("DeliveryOrderFreeline has the same description \n");
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
else{ QMessageBox::warning(this, QObject::tr("DeliveryOrder"),errorString.trimmed());
return false; 
 }
}
void DeliveryOrderUI::cancel(){ 
DeliveryOrderIndexUI::ShowUI();
}
bool DeliveryOrderUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(deliveryorder->DeliveryOrderSerialID == 0) 
deliveryorder->DeliveryOrderSerialID = deliveryorderserial->getKey();
if(deliveryorder->DeliveryOrderStatusID == 0) 
deliveryorder->DeliveryOrderStatusID = deliveryorderstatus->getKey();
if(deliveryorder->ContactID == 0) 
deliveryorder->ContactID = contact->getKey();
if(deliveryorder->ProjectID == 0) 
deliveryorder->ProjectID = project->getKey();
if(creationdate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Creation Date Can't be Empty! \n");
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
deliveryorder->CreationDate.fromString(creationdate->text().trimmed());
}
if(deliverydate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Delivery Date Can't be Empty! \n");
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
deliveryorder->DeliveryDate.fromString(deliverydate->text().trimmed());
}
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Note Can't be Empty! \n");
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
errorString += QObject::tr("Header Can't be Empty! \n");
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
errorString += QObject::tr("Footer Can't be Empty! \n");
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
errorString += QObject::tr("Delivery Address Can't be Empty! \n");
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
 errorString +=QObject::tr( "DeliveryOrderFreeline has the same description \n");
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
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("DeliveryOrder"),errorString.trimmed());
return false; 
 }
}
