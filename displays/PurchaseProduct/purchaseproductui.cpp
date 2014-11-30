/**************************************************************************
**   File: purchaseproductui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchaseproductui.h"
#include "../MainWindow.h"

PurchaseProductUI::PurchaseProductUI(QWidget *parent) :ERPDisplay(parent)
{

purchaseproduct = new PurchaseProduct();
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
title = new QLineEdit();
block0Layout->addRow("Title",title);
purchase = new ERPComboBox();
purchase->addItems(Purchase::GetHashList());
block0Layout->addRow("Purchase",purchase);
contact = new ERPComboBox();
contact->addItems(Contact::GetHashList());
block0Layout->addRow("Contact",contact);
product = new ERPComboBox();
product->addItems(Product::GetHashList());
block0Layout->addRow("Product",product);
amount = new QLineEdit();
amount->setValidator( doubleValidator );
block0Layout->addRow("Amount",amount);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* PurchaseProductUI::p_instance = 0;
void PurchaseProductUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new PurchaseProductUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
PurchaseProductUI*PurchaseProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PurchaseProductUI*) p_instance; 
}
void PurchaseProductUI::fill(PurchaseProduct* purchaseproduct){ 
clear();
this->purchaseproduct = purchaseproduct;
title->setText(purchaseproduct->Title);
amount->setText(QString::number(purchaseproduct->Amount));
} 
void PurchaseProductUI::clear(){ 
delete this->purchaseproduct;
title->setText("");
amount->setText("");
this->purchaseproduct = new PurchaseProduct();
} 
void PurchaseProductUI::selectPurchaseProduct(){ 
if(PurchaseProduct::GetStringList().contains(title->text()))
{
PurchaseProduct* con = PurchaseProduct::Get(title->text());
if(this->purchaseproduct->PurchaseProductID != con->PurchaseProductID){
fill(con);
}
}
else if(purchaseproduct->PurchaseProductID != 0)
clear();
}
bool PurchaseProductUI::save(){ 
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
purchaseproduct->Title = title->text().trimmed();
}
if(purchaseproduct->PurchaseID == 0) 
purchaseproduct->PurchaseID = purchase->getKey();
if(purchaseproduct->ContactID == 0) 
purchaseproduct->ContactID = contact->getKey();
if(purchaseproduct->ProductID == 0) 
purchaseproduct->ProductID = product->getKey();
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
purchaseproduct->Amount = amount->text().trimmed().toDouble();
}
if(!errors) {
purchaseproduct->save();
if(!errors){
PurchaseProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "PurchaseProduct",errorString.trimmed());
return false; 
 }
}
void PurchaseProductUI::cancel(){ 
PurchaseProductIndexUI::ShowUI();
}
