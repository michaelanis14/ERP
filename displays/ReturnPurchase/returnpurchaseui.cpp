/**************************************************************************
**   File: returnpurchaseui.cpp
**   Created on: Thu Dec 18 23:40:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "returnpurchaseui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ReturnPurchaseUI::ReturnPurchaseUI(QWidget *parent) :ERPDisplay(parent)
{

returnpurchase = new ReturnPurchase();
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
purchase = new ERPComboBox();
purchase->addItems(Purchase::GetPairList());
QObject::connect(purchase, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectionChanged(QString)));

block0Layout->addRow(QObject::tr("Purchase"),purchase);
date = new QDateEdit(QDate::currentDate());
date->setCalendarPopup(true);
date->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Date"),date);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block1Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveReturnPurchaseStoreProductButtons = new AddRemoveButtons();
block1Layout->addRow("ReturnPurchaseStoreProducts",addremoveReturnPurchaseStoreProductButtons);
QObject::connect(addremoveReturnPurchaseStoreProductButtons, SIGNAL(addPressed()), this, SLOT(addReturnPurchaseStoreProduct()));

flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
 block2Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveReturnPurchaseFreeLineButtons = new AddRemoveButtons();
block2Layout->addRow("ReturnPurchaseFreeLines",addremoveReturnPurchaseFreeLineButtons);
QObject::connect(addremoveReturnPurchaseFreeLineButtons, SIGNAL(addPressed()), this, SLOT(addReturnPurchaseFreeLine()));
selectionChanged("QString");
flowLayout->addWidget(block2Layout);

}
ERPDisplay* ReturnPurchaseUI::p_instance = 0;
void ReturnPurchaseUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ReturnPurchase)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new ReturnPurchaseUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ReturnPurchaseUI*ReturnPurchaseUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (ReturnPurchaseUI*) p_instance;
}
void ReturnPurchaseUI::addReturnPurchaseStoreProduct(){
ReturnPurchaseStoreProductUI* returnpurchasestoreproductui = new ReturnPurchaseStoreProductUI();
returnpurchasestoreproductui->block0Layout->hideRow(returnpurchasestoreproductui->returnpurchase);
returnpurchasestoreproductui->controllers->setFixedHeight(0);
ReturnPurchaseStoreProducts.append(returnpurchasestoreproductui);
RemovebtnWidgets* rmreturnpurchasestoreproduct = new RemovebtnWidgets(0,returnpurchasestoreproductui);
QObject::connect(rmreturnpurchasestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnPurchaseStoreProduct(QWidget*)));
block1Layout->addRow(QObject::tr("ReturnPurchaseStoreProduct")+QString::number(ReturnPurchaseStoreProducts.count()),rmreturnpurchasestoreproduct);
}
void ReturnPurchaseUI::addReturnPurchaseStoreProduct(ReturnPurchaseStoreProduct* returnpurchasestoreproduct){
ReturnPurchaseStoreProductUI* returnpurchasestoreproductui = new ReturnPurchaseStoreProductUI();
returnpurchasestoreproductui->block0Layout->hideRow(returnpurchasestoreproductui->returnpurchase);
returnpurchasestoreproductui->controllers->setFixedHeight(0);
returnpurchasestoreproductui->fill(returnpurchasestoreproduct);
ReturnPurchaseStoreProducts.append(returnpurchasestoreproductui);
RemovebtnWidgets* rmreturnpurchasestoreproduct = new RemovebtnWidgets(0,returnpurchasestoreproductui);
QObject::connect(rmreturnpurchasestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnPurchaseStoreProduct(QWidget*)));
block1Layout->addRow(QObject::tr("ReturnPurchaseStoreProduct") +QString::number(ReturnPurchaseStoreProducts.count()),rmreturnpurchasestoreproduct);
}
void ReturnPurchaseUI::removeReturnPurchaseStoreProduct(QWidget* widget){
if(ReturnPurchaseStoreProducts.count()  > 0){
ReturnPurchaseStoreProductUI* returnpurchasestoreproductui = (ReturnPurchaseStoreProductUI*) widget;
ReturnPurchaseStoreProducts.removeOne(returnpurchasestoreproductui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block1Layout->removeRow(sender);
}
}
void ReturnPurchaseUI::addReturnPurchaseFreeLine(){
ReturnPurchaseFreeLineUI* returnpurchasefreelineui = new ReturnPurchaseFreeLineUI();
returnpurchasefreelineui->block0Layout->hideRow(returnpurchasefreelineui->returnpurchase);
returnpurchasefreelineui->controllers->setFixedHeight(0);
ReturnPurchaseFreeLines.append(returnpurchasefreelineui);
RemovebtnWidgets* rmreturnpurchasefreeline = new RemovebtnWidgets(0,returnpurchasefreelineui);
QObject::connect(rmreturnpurchasefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnPurchaseFreeLine(QWidget*)));
block2Layout->addRow(QObject::tr("ReturnPurchaseFreeLine")+QString::number(ReturnPurchaseFreeLines.count()),rmreturnpurchasefreeline);
}
void ReturnPurchaseUI::addReturnPurchaseFreeLine(ReturnPurchaseFreeLine* returnpurchasefreeline){
ReturnPurchaseFreeLineUI* returnpurchasefreelineui = new ReturnPurchaseFreeLineUI();
returnpurchasefreelineui->block0Layout->hideRow(returnpurchasefreelineui->returnpurchase);
returnpurchasefreelineui->controllers->setFixedHeight(0);
returnpurchasefreelineui->fill(returnpurchasefreeline);
ReturnPurchaseFreeLines.append(returnpurchasefreelineui);
RemovebtnWidgets* rmreturnpurchasefreeline = new RemovebtnWidgets(0,returnpurchasefreelineui);
QObject::connect(rmreturnpurchasefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeReturnPurchaseFreeLine(QWidget*)));
block2Layout->addRow(QObject::tr("ReturnPurchaseFreeLine") +QString::number(ReturnPurchaseFreeLines.count()),rmreturnpurchasefreeline);
}
void ReturnPurchaseUI::removeReturnPurchaseFreeLine(QWidget* widget){
if(ReturnPurchaseFreeLines.count()  > 0){
ReturnPurchaseFreeLineUI* returnpurchasefreelineui = (ReturnPurchaseFreeLineUI*) widget;
ReturnPurchaseFreeLines.removeOne(returnpurchasefreelineui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block2Layout->removeRow(sender);
}
}
void ReturnPurchaseUI::fill(ReturnPurchase* returnpurchase){
clear();
this->returnpurchase = returnpurchase;
purchase->setIndexByKey(returnpurchase->PurchaseID);
date->setDate(returnpurchase->Date);
foreach(ReturnPurchaseStoreProduct* returnpurchasestoreproduct, returnpurchase->returnpurchasestoreproducts) {
addReturnPurchaseStoreProduct(returnpurchasestoreproduct);
}
foreach(ReturnPurchaseFreeLine* returnpurchasefreeline, returnpurchase->returnpurchasefreelines) {
addReturnPurchaseFreeLine(returnpurchasefreeline);
}
}
void ReturnPurchaseUI::clear(){
delete this->returnpurchase;
this->ReturnPurchaseStoreProducts.clear();
this->ReturnPurchaseFreeLines.clear();
date->setDate(QDate::currentDate());
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->returnpurchase = new ReturnPurchase();
}
void ReturnPurchaseUI::selectReturnPurchase(){
if(ReturnPurchase::GetStringList().contains(QString::number(this->returnpurchase->PurchaseID)))
{
ReturnPurchase* con = ReturnPurchase::Get(QString::number(this->returnpurchase->PurchaseID));
if(this->returnpurchase->ReturnPurchaseID != con->ReturnPurchaseID){
fill(con);
}
}
else if(returnpurchase->ReturnPurchaseID != 0)
clear();
}
bool ReturnPurchaseUI::save(){
bool errors = false;
QString errorString =  "";
if(!purchase->isHidden())
returnpurchase->PurchaseID = purchase->getKey();
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
returnpurchase->Date.setDate(date->date().year(),date->date().month(),date->date().day());
}
for(int j = 0; j < ReturnPurchaseFreeLines.length(); j++){
ReturnPurchaseFreeLines.at(j)->description->setObjectName("description");
ReturnPurchaseFreeLines.at(j)->description->style()->unpolish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->style()->polish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->update();
for(int w = 0; w < ReturnPurchaseFreeLines.length(); w++){
if(ReturnPurchaseFreeLines.at(j) != ReturnPurchaseFreeLines.at(w))
if(ReturnPurchaseFreeLines.at(j)->description->text() == ReturnPurchaseFreeLines.at(w)->description->text()){
errors = true;
 errorString += QObject::tr("ReturnPurchaseFreeLine has the same description \n");
ReturnPurchaseFreeLines.at(j)->description->setObjectName("error");
ReturnPurchaseFreeLines.at(j)->description->style()->unpolish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->style()->polish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->update();
}}}
if(!errors) {
returnpurchase->save();
for(int i = 0; i < ReturnPurchaseStoreProducts.length(); i++){
ReturnPurchaseStoreProducts.at(i)->returnpurchasestoreproduct->ReturnPurchaseID= returnpurchase->ReturnPurchaseID;
if(!ReturnPurchaseStoreProducts.at(i)->save()){
 errors = true;
 break; }
}
for(int i = 0; i < returnpurchase->returnpurchasestoreproducts.length(); i++){
bool flag = false;
for(int j = 0; j < ReturnPurchaseStoreProducts.length(); j++){
if(returnpurchase->returnpurchasestoreproducts.at(i)->ReturnPurchaseStoreProductID == ReturnPurchaseStoreProducts.at(j)->returnpurchasestoreproduct->ReturnPurchaseStoreProductID){
flag = true;}}
if(!flag){
returnpurchase->returnpurchasestoreproducts.at(i)->remove();}
}
for(int i = 0; i < ReturnPurchaseFreeLines.length(); i++){
ReturnPurchaseFreeLines.at(i)->returnpurchasefreeline->ReturnPurchaseID= returnpurchase->ReturnPurchaseID;
if(!ReturnPurchaseFreeLines.at(i)->save()){
 errors = true;
 break; }
}
for(int i = 0; i < returnpurchase->returnpurchasefreelines.length(); i++){
bool flag = false;
for(int j = 0; j < ReturnPurchaseFreeLines.length(); j++){
if(returnpurchase->returnpurchasefreelines.at(i)->ReturnPurchaseFreeLineID == ReturnPurchaseFreeLines.at(j)->returnpurchasefreeline->ReturnPurchaseFreeLineID){
flag = true;}}
if(!flag){
returnpurchase->returnpurchasefreelines.at(i)->remove();}
}
if(!errors){
ReturnPurchaseIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ReturnPurchase"),errorString.trimmed());
return false;
 }
}
void ReturnPurchaseUI::cancel(){
ReturnPurchaseIndexUI::ShowUI();
}
bool ReturnPurchaseUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(returnpurchase->PurchaseID == 0)
returnpurchase->PurchaseID = purchase->getKey();
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
returnpurchase->Date.fromString(date->text().trimmed());
}
for(int j = 0; j < ReturnPurchaseFreeLines.length(); j++){
ReturnPurchaseFreeLines.at(j)->description->setObjectName("description");
ReturnPurchaseFreeLines.at(j)->description->style()->unpolish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->style()->polish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->update();
for(int w = 0; w < ReturnPurchaseFreeLines.length(); w++){
if(ReturnPurchaseFreeLines.at(j) != ReturnPurchaseFreeLines.at(w))
if(ReturnPurchaseFreeLines.at(j)->description->text() == ReturnPurchaseFreeLines.at(w)->description->text()){
errors = true;
 errorString +=QObject::tr( "ReturnPurchaseFreeLine has the same description \n");
ReturnPurchaseFreeLines.at(j)->description->setObjectName("error");
ReturnPurchaseFreeLines.at(j)->description->style()->unpolish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->style()->polish(ReturnPurchaseFreeLines.at(j)->description);
ReturnPurchaseFreeLines.at(j)->description->update();
}}}
for(int i = 0; i < ReturnPurchaseStoreProducts.length(); i++){
ReturnPurchaseStoreProducts.at(i)->returnpurchasestoreproduct->ReturnPurchaseID= returnpurchase->ReturnPurchaseID;
if(!ReturnPurchaseStoreProducts.at(i)->updateModel()){
 errors = true;
 break; }
}
for(int i = 0; i < ReturnPurchaseFreeLines.length(); i++){
ReturnPurchaseFreeLines.at(i)->returnpurchasefreeline->ReturnPurchaseID= returnpurchase->ReturnPurchaseID;
if(!ReturnPurchaseFreeLines.at(i)->updateModel()){
 errors = true;
 break; }
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ReturnPurchase"),errorString.trimmed());
return false;
 }
}
void ReturnPurchaseUI::selectionChanged(QString){

	clear();
	Purchase * purch = (Purchase::Get(purchase->getKey()));
		foreach(PurchaseStoreProduct* returnpurchasestoreproduct, purch->purchasestoreproducts) {
		ReturnPurchaseStoreProduct* r = new ReturnPurchaseStoreProduct(returnpurchasestoreproduct->StoreID,0,returnpurchasestoreproduct->ContactID,returnpurchasestoreproduct->ProductID,returnpurchasestoreproduct->Amount,returnpurchasestoreproduct->Price,"","");
			addReturnPurchaseStoreProduct(r);
		}
		foreach(PurchaseFreeLine* returnpurchasefreeline, purch->purchasefreelines) {
			ReturnPurchaseFreeLine* rr = new ReturnPurchaseFreeLine(0,returnpurchasefreeline->Description,returnpurchasefreeline->ContactID,returnpurchasefreeline->Amount,returnpurchasefreeline->Price,"","");
			addReturnPurchaseFreeLine(rr);
		}

}
