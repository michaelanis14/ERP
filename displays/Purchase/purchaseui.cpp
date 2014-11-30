/**************************************************************************
**   File: purchaseui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
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
title = new QLineEdit();
block0Layout->addRow("Title",title);
store = new ERPComboBox();
store->addItems(Store::GetHashList());
block0Layout->addRow("Store",store);
creationdate = new QLineEdit();
block0Layout->addRow("Creation Date",creationdate);
deliverydate = new QLineEdit();
block0Layout->addRow("Delivery Date",deliverydate);
AddRemoveButtons* addremovePurchaseProductButtons = new AddRemoveButtons();
block0Layout->addRow("PurchaseProducts",addremovePurchaseProductButtons);
QObject::connect(addremovePurchaseProductButtons, SIGNAL(addPressed()), this, SLOT(addPurchaseProduct()));

flowLayout->addWidget(block0Layout);

}
ERPDisplay* PurchaseUI::p_instance = 0;
void PurchaseUI::ShowUI() {
	if (p_instance == 0) {
		p_instance = new PurchaseUI(mainwindow::GetMainDisplay());
	}
	mainwindow::ShowDisplay(p_instance);
}
PurchaseUI*PurchaseUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (PurchaseUI*) p_instance;
}
void PurchaseUI::addPurchaseProduct(){
PurchaseProductUI* purchaseproductui = new PurchaseProductUI();
purchaseproductui->block0Layout->removeRow(purchaseproductui->purchase);
purchaseproductui->controllers->setFixedHeight(0);
PurchaseProducts.append(purchaseproductui);
RemovebtnWidgets* rmpurchaseproduct = new RemovebtnWidgets(0,purchaseproductui);
QObject::connect(rmpurchaseproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseProduct(QWidget*)));
block0Layout->addRow("PurchaseProduct"+QString::number(PurchaseProducts.count()),rmpurchaseproduct);
}
void PurchaseUI::addPurchaseProduct(PurchaseProduct* PurchaseProduct){
PurchaseProductUI* purchaseproductui = new PurchaseProductUI();
purchaseproductui->block0Layout->removeRow(purchaseproductui->purchase);
purchaseproductui->controllers->setFixedHeight(0);
purchaseproductui->fill(PurchaseProduct);
PurchaseProducts.append(purchaseproductui);
RemovebtnWidgets* rmpurchaseproduct = new RemovebtnWidgets(0,purchaseproductui);
QObject::connect(rmpurchaseproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseProduct(QWidget*)));
block0Layout->addRow("PurchaseProduct"+QString::number(PurchaseProducts.count()),rmpurchaseproduct);
}
void PurchaseUI::removePurchaseProduct(QWidget* widget){
if(PurchaseProducts.count()  > 0){
PurchaseProductUI* purchaseproductui = (PurchaseProductUI*) widget;
PurchaseProducts.removeOne(purchaseproductui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block0Layout->removeRow(sender);
}
}
void PurchaseUI::fill(Purchase* purchase){
clear();
this->purchase = purchase;
title->setText(purchase->Title);
creationdate->setText(purchase->CreationDate);
deliverydate->setText(purchase->DeliveryDate);
foreach(PurchaseProduct* purchaseproduct, purchase->purchaseproducts) {
addPurchaseProduct(purchaseproduct);
}
}
void PurchaseUI::clear(){
delete this->purchase;
title->setText("");
creationdate->setText("");
deliverydate->setText("");
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->purchase = new Purchase();
}
void PurchaseUI::selectPurchase(){
if(Purchase::GetStringList().contains(title->text()))
{
Purchase* con = Purchase::Get(title->text());
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
purchase->Title = title->text().trimmed();
}
if(purchase->StoreID == 0)
purchase->StoreID = store->getKey();
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
for(int j = 0; j < PurchaseProducts.length(); j++){
PurchaseProducts.at(j)->title->setObjectName("title");
PurchaseProducts.at(j)->title->style()->unpolish(PurchaseProducts.at(j)->title);
PurchaseProducts.at(j)->title->style()->polish(PurchaseProducts.at(j)->title);
PurchaseProducts.at(j)->title->update();
for(int w = 0; w < PurchaseProducts.length(); w++){
if(PurchaseProducts.at(j) != PurchaseProducts.at(w))
if(PurchaseProducts.at(j)->title->text() == PurchaseProducts.at(w)->title->text()){
errors = true;
 errorString += "PurchaseProduct has the same title \n";
PurchaseProducts.at(j)->title->setObjectName("error");
PurchaseProducts.at(j)->title->style()->unpolish(PurchaseProducts.at(j)->title);
PurchaseProducts.at(j)->title->style()->polish(PurchaseProducts.at(j)->title);
PurchaseProducts.at(j)->title->update();
}}}
if(!errors) {
purchase->save();
for(int i = 0; i < PurchaseProducts.length(); i++){
PurchaseProducts.at(i)->purchaseproduct->PurchaseID= purchase->PurchaseID;
if(!PurchaseProducts.at(i)->save()){
 errors = true;
 break; }
}
for(int i = 0; i < purchase->purchaseproducts.length(); i++){
bool flag = false;
for(int j = 0; j < PurchaseProducts.length(); j++){
if(purchase->purchaseproducts.at(i)->PurchaseProductID == PurchaseProducts.at(j)->purchaseproduct->PurchaseProductID){
flag = true;}}
if(!flag){
purchase->purchaseproducts.at(i)->remove();}
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
