/**************************************************************************
**   File: returndeliveryorderui.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "returndeliveryorderui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ReturnDeliveryOrderUI::ReturnDeliveryOrderUI(QWidget *parent) :ERPDisplay(parent)
{

returndeliveryorder = new ReturnDeliveryOrder();
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
serial = new QLineEdit();
serial->setValidator( intValidator );
block0Layout->addRow(QObject::tr("Serial"),serial);
deliveryorder = new ERPComboBox();
deliveryorder->addItems(DeliveryOrder::GetPairList());
QObject::connect(deliveryorder, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectionChanged(QString)));

block0Layout->addRow(QObject::tr("Delivery Order"),deliveryorder);
date = new QDateEdit(QDate::currentDate());
date->setCalendarPopup(true);
date->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Date"),date);
note = new QLineEdit();
block0Layout->addRow(QObject::tr("Note"),note);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block1Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveReturnDeliveryOrderStoreProductButtons = new AddRemoveButtons();
block1Layout->addRow("ReturnDeliveryOrderStoreProducts",addremoveReturnDeliveryOrderStoreProductButtons);
QObject::connect(addremoveReturnDeliveryOrderStoreProductButtons, SIGNAL(addPressed()), this, SLOT(addReturnDeliveryOrderStoreProduct()));

flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block2Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveReturnDeliveryOrderServiceButtons = new AddRemoveButtons();
block2Layout->addRow("ReturnDeliveryOrderServices",addremoveReturnDeliveryOrderServiceButtons);
QObject::connect(addremoveReturnDeliveryOrderServiceButtons, SIGNAL(addPressed()), this, SLOT(addReturnDeliveryOrderService()));

flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block3Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveReturnDeliveryOrderFreelineButtons = new AddRemoveButtons();
block3Layout->addRow("ReturnDeliveryOrderFreelines",addremoveReturnDeliveryOrderFreelineButtons);
QObject::connect(addremoveReturnDeliveryOrderFreelineButtons, SIGNAL(addPressed()), this, SLOT(addReturnDeliveryOrderFreeline()));
selectionChanged("QString");
flowLayout->addWidget(block3Layout);

}
ERPDisplay* ReturnDeliveryOrderUI::p_instance = 0;
void ReturnDeliveryOrderUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ReturnDeliveryOrder)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new ReturnDeliveryOrderUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ReturnDeliveryOrderUI*ReturnDeliveryOrderUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (ReturnDeliveryOrderUI*) p_instance;
}
void ReturnDeliveryOrderUI::addReturnDeliveryOrderStoreProduct(){
ReturnDeliveryOrderStoreProductUI* returndeliveryorderstoreproductui = new ReturnDeliveryOrderStoreProductUI();
returndeliveryorderstoreproductui->block0Layout->hideRow(returndeliveryorderstoreproductui->returndeliveryorder);
returndeliveryorderstoreproductui->controllers->setFixedHeight(0);
ReturnDeliveryOrderStoreProducts.append(returndeliveryorderstoreproductui);
RemovebtnWidgets* rmreturndeliveryorderstoreproduct = new RemovebtnWidgets(0,returndeliveryorderstoreproductui);
QObject::connect(rmreturndeliveryorderstoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnDeliveryOrderStoreProduct(QWidget*)));
block1Layout->addRow(QObject::tr("ReturnDeliveryOrderStoreProduct")+QString::number(ReturnDeliveryOrderStoreProducts.count()),rmreturndeliveryorderstoreproduct);
}
void ReturnDeliveryOrderUI::addReturnDeliveryOrderStoreProduct(ReturnDeliveryOrderStoreProduct* returndeliveryorderstoreproduct){
ReturnDeliveryOrderStoreProductUI* returndeliveryorderstoreproductui = new ReturnDeliveryOrderStoreProductUI();
returndeliveryorderstoreproductui->block0Layout->hideRow(returndeliveryorderstoreproductui->returndeliveryorder);
returndeliveryorderstoreproductui->controllers->setFixedHeight(0);
returndeliveryorderstoreproductui->fill(returndeliveryorderstoreproduct);
ReturnDeliveryOrderStoreProducts.append(returndeliveryorderstoreproductui);
RemovebtnWidgets* rmreturndeliveryorderstoreproduct = new RemovebtnWidgets(0,returndeliveryorderstoreproductui);
QObject::connect(rmreturndeliveryorderstoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnDeliveryOrderStoreProduct(QWidget*)));
block1Layout->addRow(QObject::tr("ReturnDeliveryOrderStoreProduct") +QString::number(ReturnDeliveryOrderStoreProducts.count()),rmreturndeliveryorderstoreproduct);
}
void ReturnDeliveryOrderUI::removeReturnDeliveryOrderStoreProduct(QWidget* widget){
if(ReturnDeliveryOrderStoreProducts.count()  > 0){
ReturnDeliveryOrderStoreProductUI* returndeliveryorderstoreproductui = (ReturnDeliveryOrderStoreProductUI*) widget;
ReturnDeliveryOrderStoreProducts.removeOne(returndeliveryorderstoreproductui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block1Layout->removeRow(sender);
}
}
void ReturnDeliveryOrderUI::addReturnDeliveryOrderService(){
ReturnDeliveryOrderServiceUI* returndeliveryorderserviceui = new ReturnDeliveryOrderServiceUI();
returndeliveryorderserviceui->block0Layout->hideRow(returndeliveryorderserviceui->returndeliveryorder);
returndeliveryorderserviceui->controllers->setFixedHeight(0);
ReturnDeliveryOrderServices.append(returndeliveryorderserviceui);
RemovebtnWidgets* rmreturndeliveryorderservice = new RemovebtnWidgets(0,returndeliveryorderserviceui);
QObject::connect(rmreturndeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnDeliveryOrderService(QWidget*)));
block2Layout->addRow(QObject::tr("ReturnDeliveryOrderService")+QString::number(ReturnDeliveryOrderServices.count()),rmreturndeliveryorderservice);
}
void ReturnDeliveryOrderUI::addReturnDeliveryOrderService(ReturnDeliveryOrderService* returndeliveryorderservice){
ReturnDeliveryOrderServiceUI* returndeliveryorderserviceui = new ReturnDeliveryOrderServiceUI();
returndeliveryorderserviceui->block0Layout->hideRow(returndeliveryorderserviceui->returndeliveryorder);
returndeliveryorderserviceui->controllers->setFixedHeight(0);
returndeliveryorderserviceui->fill(returndeliveryorderservice);
ReturnDeliveryOrderServices.append(returndeliveryorderserviceui);
RemovebtnWidgets* rmreturndeliveryorderservice = new RemovebtnWidgets(0,returndeliveryorderserviceui);
QObject::connect(rmreturndeliveryorderservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnDeliveryOrderService(QWidget*)));
block2Layout->addRow(QObject::tr("ReturnDeliveryOrderService") +QString::number(ReturnDeliveryOrderServices.count()),rmreturndeliveryorderservice);
}
void ReturnDeliveryOrderUI::removeReturnDeliveryOrderService(QWidget* widget){
if(ReturnDeliveryOrderServices.count()  > 0){
ReturnDeliveryOrderServiceUI* returndeliveryorderserviceui = (ReturnDeliveryOrderServiceUI*) widget;
ReturnDeliveryOrderServices.removeOne(returndeliveryorderserviceui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block2Layout->removeRow(sender);
}
}
void ReturnDeliveryOrderUI::addReturnDeliveryOrderFreeline(){
ReturnDeliveryOrderFreelineUI* returndeliveryorderfreelineui = new ReturnDeliveryOrderFreelineUI();
returndeliveryorderfreelineui->block0Layout->hideRow(returndeliveryorderfreelineui->returndeliveryorder);
returndeliveryorderfreelineui->controllers->setFixedHeight(0);
ReturnDeliveryOrderFreelines.append(returndeliveryorderfreelineui);
RemovebtnWidgets* rmreturndeliveryorderfreeline = new RemovebtnWidgets(0,returndeliveryorderfreelineui);
QObject::connect(rmreturndeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnDeliveryOrderFreeline(QWidget*)));
block3Layout->addRow(QObject::tr("ReturnDeliveryOrderFreeline")+QString::number(ReturnDeliveryOrderFreelines.count()),rmreturndeliveryorderfreeline);
}
void ReturnDeliveryOrderUI::addReturnDeliveryOrderFreeline(ReturnDeliveryOrderFreeline* returndeliveryorderfreeline){
ReturnDeliveryOrderFreelineUI* returndeliveryorderfreelineui = new ReturnDeliveryOrderFreelineUI();
returndeliveryorderfreelineui->block0Layout->hideRow(returndeliveryorderfreelineui->returndeliveryorder);
returndeliveryorderfreelineui->controllers->setFixedHeight(0);
returndeliveryorderfreelineui->fill(returndeliveryorderfreeline);
ReturnDeliveryOrderFreelines.append(returndeliveryorderfreelineui);
RemovebtnWidgets* rmreturndeliveryorderfreeline = new RemovebtnWidgets(0,returndeliveryorderfreelineui);
QObject::connect(rmreturndeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnDeliveryOrderFreeline(QWidget*)));
block3Layout->addRow(QObject::tr("ReturnDeliveryOrderFreeline") +QString::number(ReturnDeliveryOrderFreelines.count()),rmreturndeliveryorderfreeline);
}
void ReturnDeliveryOrderUI::removeReturnDeliveryOrderFreeline(QWidget* widget){
if(ReturnDeliveryOrderFreelines.count()  > 0){
ReturnDeliveryOrderFreelineUI* returndeliveryorderfreelineui = (ReturnDeliveryOrderFreelineUI*) widget;
ReturnDeliveryOrderFreelines.removeOne(returndeliveryorderfreelineui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block3Layout->removeRow(sender);
}
}
void ReturnDeliveryOrderUI::fill(ReturnDeliveryOrder* returndeliveryorder){
clear();
this->returndeliveryorder = returndeliveryorder;
serial->setText(QString::number(returndeliveryorder->Serial));
deliveryorder->setIndexByKey(returndeliveryorder->DeliveryOrderID);
date->setDate(returndeliveryorder->Date);
note->setText(returndeliveryorder->Note);
foreach(ReturnDeliveryOrderStoreProduct* returndeliveryorderstoreproduct, returndeliveryorder->returndeliveryorderstoreproducts) {
addReturnDeliveryOrderStoreProduct(returndeliveryorderstoreproduct);
}
foreach(ReturnDeliveryOrderService* returndeliveryorderservice, returndeliveryorder->returndeliveryorderservices) {
addReturnDeliveryOrderService(returndeliveryorderservice);
}
foreach(ReturnDeliveryOrderFreeline* returndeliveryorderfreeline, returndeliveryorder->returndeliveryorderfreelines) {
addReturnDeliveryOrderFreeline(returndeliveryorderfreeline);
}
}
void ReturnDeliveryOrderUI::clear(){
delete this->returndeliveryorder;
this->ReturnDeliveryOrderStoreProducts.clear();
this->ReturnDeliveryOrderServices.clear();
this->ReturnDeliveryOrderFreelines.clear();
serial->setText("");
date->setDate(QDate::currentDate());
note->setText("");
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->returndeliveryorder = new ReturnDeliveryOrder();
}
void ReturnDeliveryOrderUI::selectReturnDeliveryOrder(){
if(ReturnDeliveryOrder::GetStringList().contains(QString::number(this->returndeliveryorder->Serial)))
{
ReturnDeliveryOrder* con = ReturnDeliveryOrder::Get(QString::number(this->returndeliveryorder->Serial));
if(this->returndeliveryorder->ReturnDeliveryOrderID != con->ReturnDeliveryOrderID){
fill(con);
}
}
else if(returndeliveryorder->ReturnDeliveryOrderID != 0)
clear();
}
bool ReturnDeliveryOrderUI::save(){
bool errors = false;
QString errorString =  "";
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Serial Can't be Empty! \n");
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
returndeliveryorder->Serial = serial->text().trimmed().toInt();
}
if(!deliveryorder->isHidden())
returndeliveryorder->DeliveryOrderID = deliveryorder->getKey();
if(date->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Date Can't be Empty! \n");
date->setObjectName("error");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
}
else {
date->setObjectName("date");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
returndeliveryorder->Date.setDate(date->date().year(),date->date().month(),date->date().day());
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
returndeliveryorder->Note = note->text().trimmed();
}
for(int j = 0; j < ReturnDeliveryOrderFreelines.length(); j++){
ReturnDeliveryOrderFreelines.at(j)->description->setObjectName("description");
ReturnDeliveryOrderFreelines.at(j)->description->style()->unpolish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->style()->polish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->update();
for(int w = 0; w < ReturnDeliveryOrderFreelines.length(); w++){
if(ReturnDeliveryOrderFreelines.at(j) != ReturnDeliveryOrderFreelines.at(w))
if(ReturnDeliveryOrderFreelines.at(j)->description->text() == ReturnDeliveryOrderFreelines.at(w)->description->text()){
errors = true;
 errorString += QObject::tr("ReturnDeliveryOrderFreeline has the same description \n");
ReturnDeliveryOrderFreelines.at(j)->description->setObjectName("error");
ReturnDeliveryOrderFreelines.at(j)->description->style()->unpolish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->style()->polish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->update();
}}}
if(!errors) {
returndeliveryorder->save();
for(int i = 0; i < ReturnDeliveryOrderStoreProducts.length(); i++){
ReturnDeliveryOrderStoreProducts.at(i)->returndeliveryorderstoreproduct->ReturnDeliveryOrderID= returndeliveryorder->ReturnDeliveryOrderID;
if(!ReturnDeliveryOrderStoreProducts.at(i)->save()){
 errors = true;
 break; }
}
for(int i = 0; i < returndeliveryorder->returndeliveryorderstoreproducts.length(); i++){
bool flag = false;
for(int j = 0; j < ReturnDeliveryOrderStoreProducts.length(); j++){
if(returndeliveryorder->returndeliveryorderstoreproducts.at(i)->ReturnDeliveryOrderStoreProductID == ReturnDeliveryOrderStoreProducts.at(j)->returndeliveryorderstoreproduct->ReturnDeliveryOrderStoreProductID){
flag = true;}}
if(!flag){
returndeliveryorder->returndeliveryorderstoreproducts.at(i)->remove();}
}
for(int i = 0; i < ReturnDeliveryOrderServices.length(); i++){
ReturnDeliveryOrderServices.at(i)->returndeliveryorderservice->ReturnDeliveryOrderID= returndeliveryorder->ReturnDeliveryOrderID;
if(!ReturnDeliveryOrderServices.at(i)->save()){
 errors = true;
 break; }
}
for(int i = 0; i < returndeliveryorder->returndeliveryorderservices.length(); i++){
bool flag = false;
for(int j = 0; j < ReturnDeliveryOrderServices.length(); j++){
if(returndeliveryorder->returndeliveryorderservices.at(i)->ReturnDeliveryOrderServiceID == ReturnDeliveryOrderServices.at(j)->returndeliveryorderservice->ReturnDeliveryOrderServiceID){
flag = true;}}
if(!flag){
returndeliveryorder->returndeliveryorderservices.at(i)->remove();}
}
for(int i = 0; i < ReturnDeliveryOrderFreelines.length(); i++){
ReturnDeliveryOrderFreelines.at(i)->returndeliveryorderfreeline->ReturnDeliveryOrderID= returndeliveryorder->ReturnDeliveryOrderID;
if(!ReturnDeliveryOrderFreelines.at(i)->save()){
 errors = true;
 break; }
}
for(int i = 0; i < returndeliveryorder->returndeliveryorderfreelines.length(); i++){
bool flag = false;
for(int j = 0; j < ReturnDeliveryOrderFreelines.length(); j++){
if(returndeliveryorder->returndeliveryorderfreelines.at(i)->ReturnDeliveryOrderFreelineID == ReturnDeliveryOrderFreelines.at(j)->returndeliveryorderfreeline->ReturnDeliveryOrderFreelineID){
flag = true;}}
if(!flag){
returndeliveryorder->returndeliveryorderfreelines.at(i)->remove();}
}
if(!errors){
ReturnDeliveryOrderIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrder"),errorString.trimmed());
return false;
 }
}
void ReturnDeliveryOrderUI::cancel(){
ReturnDeliveryOrderIndexUI::ShowUI();
}
bool ReturnDeliveryOrderUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Serial Can't be Empty! \n");
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
returndeliveryorder->Serial = serial->text().trimmed().toInt();
}
if(returndeliveryorder->DeliveryOrderID == 0)
returndeliveryorder->DeliveryOrderID = deliveryorder->getKey();
if(date->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Date Can't be Empty! \n");
date->setObjectName("error");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
}
else {
date->setObjectName("date");
date->style()->unpolish(date);
date->style()->polish(date);
date->update();
returndeliveryorder->Date.fromString(date->text().trimmed());
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
returndeliveryorder->Note = note->text().trimmed();
}
for(int j = 0; j < ReturnDeliveryOrderFreelines.length(); j++){
ReturnDeliveryOrderFreelines.at(j)->description->setObjectName("description");
ReturnDeliveryOrderFreelines.at(j)->description->style()->unpolish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->style()->polish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->update();
for(int w = 0; w < ReturnDeliveryOrderFreelines.length(); w++){
if(ReturnDeliveryOrderFreelines.at(j) != ReturnDeliveryOrderFreelines.at(w))
if(ReturnDeliveryOrderFreelines.at(j)->description->text() == ReturnDeliveryOrderFreelines.at(w)->description->text()){
errors = true;
 errorString +=QObject::tr( "ReturnDeliveryOrderFreeline has the same description \n");
ReturnDeliveryOrderFreelines.at(j)->description->setObjectName("error");
ReturnDeliveryOrderFreelines.at(j)->description->style()->unpolish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->style()->polish(ReturnDeliveryOrderFreelines.at(j)->description);
ReturnDeliveryOrderFreelines.at(j)->description->update();
}}}
for(int i = 0; i < ReturnDeliveryOrderStoreProducts.length(); i++){
ReturnDeliveryOrderStoreProducts.at(i)->returndeliveryorderstoreproduct->ReturnDeliveryOrderID= returndeliveryorder->ReturnDeliveryOrderID;
if(!ReturnDeliveryOrderStoreProducts.at(i)->updateModel()){
 errors = true;
 break; }
}
for(int i = 0; i < ReturnDeliveryOrderServices.length(); i++){
ReturnDeliveryOrderServices.at(i)->returndeliveryorderservice->ReturnDeliveryOrderID= returndeliveryorder->ReturnDeliveryOrderID;
if(!ReturnDeliveryOrderServices.at(i)->updateModel()){
 errors = true;
 break; }
}
for(int i = 0; i < ReturnDeliveryOrderFreelines.length(); i++){
ReturnDeliveryOrderFreelines.at(i)->returndeliveryorderfreeline->ReturnDeliveryOrderID= returndeliveryorder->ReturnDeliveryOrderID;
if(!ReturnDeliveryOrderFreelines.at(i)->updateModel()){
 errors = true;
 break; }
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ReturnDeliveryOrder"),errorString.trimmed());
return false;
 }
}
void ReturnDeliveryOrderUI::selectionChanged(QString){
	clear();
	DeliveryOrder * delv = (DeliveryOrder::Get(deliveryorder->getKey()));
		foreach(DeliveryOrderStoreProduct* delvProduct, delv->deliveryorderstoreproducts) {
		ReturnDeliveryOrderStoreProduct* r = new ReturnDeliveryOrderStoreProduct(0,delvProduct->StoreID,delvProduct->ProductID,delvProduct->Amount,delvProduct->Price,"","");
			addReturnDeliveryOrderStoreProduct(r);
		}
		foreach(DeliveryOrderService* delvSer, delv->deliveryorderservices) {
			ReturnDeliveryOrderService* r = new ReturnDeliveryOrderService(0,delvSer->ServiceID,delvSer->Amount,delvSer->Price,"","");
			addReturnDeliveryOrderService(r);
		}
		foreach(DeliveryOrderFreeline* delvFreeLine, delv->deliveryorderfreelines) {
			ReturnDeliveryOrderFreeline* r = new ReturnDeliveryOrderFreeline(0,delvFreeLine->Description,delvFreeLine->Amount,delvFreeLine->Price,"","");
			addReturnDeliveryOrderFreeline(r);
		}

}
