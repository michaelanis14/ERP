/**************************************************************************
**   File: purchaseui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchaseui.h"
#include "../MainWindow.h"

PurchaseUI::PurchaseUI(QWidget *parent) :ERPDisplay(parent)
{

purchase = new Purchase();
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
purchaseserial = new ERPComboBox();
purchaseserial->addItems(PurchaseSerial::GetPairList());
block0Layout->addRow("Purchase Serial",purchaseserial);
creationdate = new QDateEdit(QDate::currentDate());
creationdate->setCalendarPopup(true);
creationdate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow("Creation Date",creationdate);
deliverydate = new QDateEdit(QDate::currentDate());
deliverydate->setCalendarPopup(true);
deliverydate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow("Delivery Date",deliverydate);
AddRemoveButtons* addremovePurchaseStoreProductButtons = new AddRemoveButtons();
block0Layout->addRow("PurchaseStoreProducts",addremovePurchaseStoreProductButtons);
QObject::connect(addremovePurchaseStoreProductButtons, SIGNAL(addPressed()), this, SLOT(addPurchaseStoreProduct()));

AddRemoveButtons* addremovePurchaseFreeLineButtons = new AddRemoveButtons();
block0Layout->addRow("PurchaseFreeLines",addremovePurchaseFreeLineButtons);
QObject::connect(addremovePurchaseFreeLineButtons, SIGNAL(addPressed()), this, SLOT(addPurchaseFreeLine()));

flowLayout->addWidget(block0Layout);

}
ERPDisplay* PurchaseUI::p_instance = 0;
void PurchaseUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new PurchaseUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
PurchaseUI*PurchaseUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PurchaseUI*) p_instance; 
}
void PurchaseUI::addPurchaseStoreProduct(){ 
PurchaseStoreProductUI* purchasestoreproductui = new PurchaseStoreProductUI();
purchasestoreproductui->block0Layout->hideRow(purchasestoreproductui->purchase);
purchasestoreproductui->controllers->setFixedHeight(0);
PurchaseStoreProducts.append(purchasestoreproductui);
RemovebtnWidgets* rmpurchasestoreproduct = new RemovebtnWidgets(0,purchasestoreproductui);
QObject::connect(rmpurchasestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseStoreProduct(QWidget*)));
block0Layout->addRow("PurchaseStoreProduct"+QString::number(PurchaseStoreProducts.count()),rmpurchasestoreproduct);
}
void PurchaseUI::addPurchaseStoreProduct(PurchaseStoreProduct* PurchaseStoreProduct){ 
PurchaseStoreProductUI* purchasestoreproductui = new PurchaseStoreProductUI();
purchasestoreproductui->block0Layout->hideRow(purchasestoreproductui->purchase);
purchasestoreproductui->controllers->setFixedHeight(0);
purchasestoreproductui->fill(PurchaseStoreProduct);
PurchaseStoreProducts.append(purchasestoreproductui);
RemovebtnWidgets* rmpurchasestoreproduct = new RemovebtnWidgets(0,purchasestoreproductui);
QObject::connect(rmpurchasestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseStoreProduct(QWidget*)));
block0Layout->addRow("PurchaseStoreProduct"+QString::number(PurchaseStoreProducts.count()),rmpurchasestoreproduct);
}
void PurchaseUI::removePurchaseStoreProduct(QWidget* widget){ 
if(PurchaseStoreProducts.count()  > 0){
PurchaseStoreProductUI* purchasestoreproductui = (PurchaseStoreProductUI*) widget;
PurchaseStoreProducts.removeOne(purchasestoreproductui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block0Layout->removeRow(sender);
}
}
void PurchaseUI::addPurchaseFreeLine(){ 
PurchaseFreeLineUI* purchasefreelineui = new PurchaseFreeLineUI();
purchasefreelineui->block0Layout->hideRow(purchasefreelineui->purchase);
purchasefreelineui->controllers->setFixedHeight(0);
PurchaseFreeLines.append(purchasefreelineui);
RemovebtnWidgets* rmpurchasefreeline = new RemovebtnWidgets(0,purchasefreelineui);
QObject::connect(rmpurchasefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseFreeLine(QWidget*)));
block0Layout->addRow("PurchaseFreeLine"+QString::number(PurchaseFreeLines.count()),rmpurchasefreeline);
}
void PurchaseUI::addPurchaseFreeLine(PurchaseFreeLine* PurchaseFreeLine){ 
PurchaseFreeLineUI* purchasefreelineui = new PurchaseFreeLineUI();
purchasefreelineui->block0Layout->hideRow(purchasefreelineui->purchase);
purchasefreelineui->controllers->setFixedHeight(0);
purchasefreelineui->fill(PurchaseFreeLine);
PurchaseFreeLines.append(purchasefreelineui);
RemovebtnWidgets* rmpurchasefreeline = new RemovebtnWidgets(0,purchasefreelineui);
QObject::connect(rmpurchasefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseFreeLine(QWidget*)));
block0Layout->addRow("PurchaseFreeLine"+QString::number(PurchaseFreeLines.count()),rmpurchasefreeline);
}
void PurchaseUI::removePurchaseFreeLine(QWidget* widget){ 
if(PurchaseFreeLines.count()  > 0){
PurchaseFreeLineUI* purchasefreelineui = (PurchaseFreeLineUI*) widget;
PurchaseFreeLines.removeOne(purchasefreelineui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block0Layout->removeRow(sender);
}
}
void PurchaseUI::fill(Purchase* purchase){ 
clear();
this->purchase = purchase;
creationdate->setDate(QDate::fromString(purchase->CreationDate));
deliverydate->setDate(QDate::fromString(purchase->DeliveryDate));
foreach(PurchaseStoreProduct* purchasestoreproduct, purchase->purchasestoreproducts) {
addPurchaseStoreProduct(purchasestoreproduct);
}
foreach(PurchaseFreeLine* purchasefreeline, purchase->purchasefreelines) {
addPurchaseFreeLine(purchasefreeline);
}
} 
void PurchaseUI::clear(){ 
delete this->purchase;
this->PurchaseStoreProducts.clear();
this->PurchaseFreeLines.clear();
creationdate->setDate(QDate::currentDate());
deliverydate->setDate(QDate::currentDate());
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->purchase = new Purchase();
} 
void PurchaseUI::selectPurchase(){ 
if(Purchase::GetStringList().contains(QString::number(this->purchase->PurchaseSerialID)))
{
Purchase* con = Purchase::Get(QString::number(this->purchase->PurchaseSerialID));
if(this->purchase->PurchaseID != con->PurchaseID){
fill(con);
}
}
else if(purchase->PurchaseID != 0)
clear();
}
bool PurchaseUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!purchaseserial->isHidden()) 
purchase->PurchaseSerialID = purchaseserial->getKey();
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
purchase->CreationDate = creationdate->text().trimmed();
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
purchase->DeliveryDate = deliverydate->text().trimmed();
}
for(int j = 0; j < PurchaseFreeLines.length(); j++){
PurchaseFreeLines.at(j)->description->setObjectName("description");
PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->update();
for(int w = 0; w < PurchaseFreeLines.length(); w++){
if(PurchaseFreeLines.at(j) != PurchaseFreeLines.at(w))
if(PurchaseFreeLines.at(j)->description->text() == PurchaseFreeLines.at(w)->description->text()){
errors = true; 
 errorString += "PurchaseFreeLine has the same description \n";
PurchaseFreeLines.at(j)->description->setObjectName("error");
PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->update();
}}}
if(!errors) {
purchase->save();
for(int i = 0; i < PurchaseStoreProducts.length(); i++){
PurchaseStoreProducts.at(i)->purchasestoreproduct->PurchaseID= purchase->PurchaseID;
if(!PurchaseStoreProducts.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < purchase->purchasestoreproducts.length(); i++){
bool flag = false;
for(int j = 0; j < PurchaseStoreProducts.length(); j++){
if(purchase->purchasestoreproducts.at(i)->PurchaseStoreProductID == PurchaseStoreProducts.at(j)->purchasestoreproduct->PurchaseStoreProductID){
flag = true;}}
if(!flag){
purchase->purchasestoreproducts.at(i)->remove();}
}
for(int i = 0; i < PurchaseFreeLines.length(); i++){
PurchaseFreeLines.at(i)->purchasefreeline->PurchaseID= purchase->PurchaseID;
if(!PurchaseFreeLines.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < purchase->purchasefreelines.length(); i++){
bool flag = false;
for(int j = 0; j < PurchaseFreeLines.length(); j++){
if(purchase->purchasefreelines.at(i)->PurchaseFreeLineID == PurchaseFreeLines.at(j)->purchasefreeline->PurchaseFreeLineID){
flag = true;}}
if(!flag){
purchase->purchasefreelines.at(i)->remove();}
}
if(!errors){
PurchaseIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Purchase",errorString.trimmed());
return false; 
 }
}
void PurchaseUI::cancel(){ 
PurchaseIndexUI::ShowUI();
}
bool PurchaseUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(purchase->PurchaseSerialID == 0) 
purchase->PurchaseSerialID = purchaseserial->getKey();
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
purchase->CreationDate = creationdate->text().trimmed();
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
purchase->DeliveryDate = deliverydate->text().trimmed();
}
for(int j = 0; j < PurchaseFreeLines.length(); j++){
PurchaseFreeLines.at(j)->description->setObjectName("description");
PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->update();
for(int w = 0; w < PurchaseFreeLines.length(); w++){
if(PurchaseFreeLines.at(j) != PurchaseFreeLines.at(w))
if(PurchaseFreeLines.at(j)->description->text() == PurchaseFreeLines.at(w)->description->text()){
errors = true; 
 errorString += "PurchaseFreeLine has the same description \n";
PurchaseFreeLines.at(j)->description->setObjectName("error");
PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
PurchaseFreeLines.at(j)->description->update();
}}}
for(int i = 0; i < PurchaseStoreProducts.length(); i++){
PurchaseStoreProducts.at(i)->purchasestoreproduct->PurchaseID= purchase->PurchaseID;
if(!PurchaseStoreProducts.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < PurchaseFreeLines.length(); i++){
PurchaseFreeLines.at(i)->purchasefreeline->PurchaseID= purchase->PurchaseID;
if(!PurchaseFreeLines.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "Purchase",errorString.trimmed());
return false; 
 }
}
