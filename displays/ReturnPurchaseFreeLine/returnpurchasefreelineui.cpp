/**************************************************************************
**   File: returnpurchasefreelineui.cpp
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "returnpurchasefreelineui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ReturnPurchaseFreeLineUI::ReturnPurchaseFreeLineUI(QWidget *parent) :ERPDisplay(parent)
{

returnpurchasefreeline = new ReturnPurchaseFreeLine();
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
returnpurchase = new ERPComboBox();
returnpurchase->addItems(ReturnPurchase::GetPairList());
block0Layout->addRow(QObject::tr("Return Purchase"),returnpurchase);
description = new QLineEdit();
block0Layout->addRow(QObject::tr("Description"),description);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
connect(amount, SIGNAL(textChanged(QString)), this, SLOT(updateTotal(QString)));

block0Layout->addRow(QObject::tr("Amount"),amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
connect(price, SIGNAL(textChanged(QString)), this, SLOT(updateTotal(QString)));

block0Layout->addRow(QObject::tr("Price Per Piece"),price);
total = new QLineEdit();
total->setEnabled(false);
total->setValidator( doubleValidator );
updateTotal("QString");
block0Layout->addRow(QObject::tr("Total"),total);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ReturnPurchaseFreeLineUI::p_instance = 0;
void ReturnPurchaseFreeLineUI::ShowUI() {
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
 LoginUI::ShowUI();
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ReturnPurchaseFreeLine)
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
 else{	if (p_instance != 0)
	p_instance->deleteLater();
	p_instance = new ReturnPurchaseFreeLineUI(mainwindow::GetMainDisplay());
  mainwindow::ShowDisplay(p_instance);
}
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ReturnPurchaseFreeLineUI*ReturnPurchaseFreeLineUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (ReturnPurchaseFreeLineUI*) p_instance;
}
void ReturnPurchaseFreeLineUI::fill(ReturnPurchaseFreeLine* returnpurchasefreeline){
clear();
this->returnpurchasefreeline = returnpurchasefreeline;
returnpurchase->setIndexByKey(returnpurchasefreeline->ReturnPurchaseID);
description->setText(returnpurchasefreeline->Description);
contact->setIndexByKey(returnpurchasefreeline->ContactID);
amount->setText(QString::number(returnpurchasefreeline->Amount));
price->setText(QString::number(returnpurchasefreeline->Price));
}
void ReturnPurchaseFreeLineUI::clear(){
delete this->returnpurchasefreeline;
description->setText("");
amount->setText("");
price->setText("");
this->returnpurchasefreeline = new ReturnPurchaseFreeLine();
}
void ReturnPurchaseFreeLineUI::selectReturnPurchaseFreeLine(){
if(ReturnPurchaseFreeLine::GetStringList().contains(QString::number(this->returnpurchasefreeline->ReturnPurchaseID)))
{
ReturnPurchaseFreeLine* con = ReturnPurchaseFreeLine::Get(QString::number(this->returnpurchasefreeline->ReturnPurchaseID));
if(this->returnpurchasefreeline->ReturnPurchaseFreeLineID != con->ReturnPurchaseFreeLineID){
fill(con);
}
}
else if(returnpurchasefreeline->ReturnPurchaseFreeLineID != 0)
clear();
}
bool ReturnPurchaseFreeLineUI::save(){
bool errors = false;
QString errorString =  "";
if(!returnpurchase->isHidden())
returnpurchasefreeline->ReturnPurchaseID = returnpurchase->getKey();
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Description Can't be Empty! \n");
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else {
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
returnpurchasefreeline->Description = description->text().trimmed();
}
if(!contact->isHidden())
returnpurchasefreeline->ContactID = contact->getKey();
if(amount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Amount Can't be Empty! \n");
amount->setObjectName("error");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
}
else {
amount->setObjectName("amount");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
returnpurchasefreeline->Amount = amount->text().trimmed().toDouble();
}
if(price->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Price Can't be Empty! \n");
price->setObjectName("error");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
}
else {
price->setObjectName("price");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
returnpurchasefreeline->Price = price->text().trimmed().toDouble();
}
if(!errors) {
returnpurchasefreeline->save();
if(!errors){
ReturnPurchaseFreeLineIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ReturnPurchaseFreeLine"),errorString.trimmed());
return false;
 }
}
void ReturnPurchaseFreeLineUI::cancel(){
ReturnPurchaseFreeLineIndexUI::ShowUI();
}
bool ReturnPurchaseFreeLineUI::updateModel(){
bool errors = false;
QString errorString =  "";
if(returnpurchasefreeline->ReturnPurchaseID == 0)
returnpurchasefreeline->ReturnPurchaseID = returnpurchase->getKey();
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Description Can't be Empty! \n");
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else {
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
returnpurchasefreeline->Description = description->text().trimmed();
}
if(returnpurchasefreeline->ContactID == 0)
returnpurchasefreeline->ContactID = contact->getKey();
if(amount->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Amount Can't be Empty! \n");
amount->setObjectName("error");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
}
else {
amount->setObjectName("amount");
amount->style()->unpolish(amount);
amount->style()->polish(amount);
amount->update();
returnpurchasefreeline->Amount = amount->text().trimmed().toDouble();
}
if(price->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Price Can't be Empty! \n");
price->setObjectName("error");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
}
else {
price->setObjectName("price");
price->style()->unpolish(price);
price->style()->polish(price);
price->update();
returnpurchasefreeline->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ReturnPurchaseFreeLine"),errorString.trimmed());
return false;
 }
}
void ReturnPurchaseFreeLineUI::updateTotal(QString){

	double tot = ((amount->text().toDouble()) * (price->text().toDouble()));
	total->setText(QString::number(tot,'f',2));
}
