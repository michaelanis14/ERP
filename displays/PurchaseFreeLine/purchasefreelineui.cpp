/**************************************************************************
**   File: purchasefreelineui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchasefreelineui.h"
#include "../MainWindow.h"

PurchaseFreeLineUI::PurchaseFreeLineUI(QWidget *parent) :ERPDisplay(parent)
{

purchasefreeline = new PurchaseFreeLine();
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
purchase = new ERPComboBox();
purchase->addItems(Purchase::GetPairList());
block0Layout->addRow("Purchase",purchase);
description = new QLineEdit();
block0Layout->addRow("Description",description);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow("Contact",contact);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow("Amount",amount);
price = new QLineEdit();
price->setValidator( doubleValidator );
block0Layout->addRow("Price",price);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* PurchaseFreeLineUI::p_instance = 0;
void PurchaseFreeLineUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new PurchaseFreeLineUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
PurchaseFreeLineUI*PurchaseFreeLineUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PurchaseFreeLineUI*) p_instance; 
}
void PurchaseFreeLineUI::fill(PurchaseFreeLine* purchasefreeline){ 
clear();
this->purchasefreeline = purchasefreeline;
description->setText(purchasefreeline->Description);
amount->setText(QString::number(purchasefreeline->Amount));
price->setText(QString::number(purchasefreeline->Price));
} 
void PurchaseFreeLineUI::clear(){ 
delete this->purchasefreeline;
description->setText("");
amount->setText("");
price->setText("");
this->purchasefreeline = new PurchaseFreeLine();
} 
void PurchaseFreeLineUI::selectPurchaseFreeLine(){ 
if(PurchaseFreeLine::GetStringList().contains(QString::number(this->purchasefreeline->PurchaseID)))
{
PurchaseFreeLine* con = PurchaseFreeLine::Get(QString::number(this->purchasefreeline->PurchaseID));
if(this->purchasefreeline->PurchaseFreeLineID != con->PurchaseFreeLineID){
fill(con);
}
}
else if(purchasefreeline->PurchaseFreeLineID != 0)
clear();
}
bool PurchaseFreeLineUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!purchase->isHidden()) 
purchasefreeline->PurchaseID = purchase->getKey();
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += "Description Can't be Empty! \n";
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
purchasefreeline->Description = description->text().trimmed();
}
if(!contact->isHidden()) 
purchasefreeline->ContactID = contact->getKey();
if(amount->text().trimmed().isEmpty()){
errors = true;
errorString += "Amount Can't be Empty! \n";
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
purchasefreeline->Amount = amount->text().trimmed().toDouble();
}
if(price->text().trimmed().isEmpty()){
errors = true;
errorString += "Price Can't be Empty! \n";
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
purchasefreeline->Price = price->text().trimmed().toDouble();
}
if(!errors) {
purchasefreeline->save();
if(!errors){
PurchaseFreeLineIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "PurchaseFreeLine",errorString.trimmed());
return false; 
 }
}
void PurchaseFreeLineUI::cancel(){ 
PurchaseFreeLineIndexUI::ShowUI();
}
bool PurchaseFreeLineUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(purchasefreeline->PurchaseID == 0) 
purchasefreeline->PurchaseID = purchase->getKey();
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += "Description Can't be Empty! \n";
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
purchasefreeline->Description = description->text().trimmed();
}
if(purchasefreeline->ContactID == 0) 
purchasefreeline->ContactID = contact->getKey();
if(amount->text().trimmed().isEmpty()){
errors = true;
errorString += "Amount Can't be Empty! \n";
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
purchasefreeline->Amount = amount->text().trimmed().toDouble();
}
if(price->text().trimmed().isEmpty()){
errors = true;
errorString += "Price Can't be Empty! \n";
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
purchasefreeline->Price = price->text().trimmed().toDouble();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "PurchaseFreeLine",errorString.trimmed());
return false; 
 }
}
