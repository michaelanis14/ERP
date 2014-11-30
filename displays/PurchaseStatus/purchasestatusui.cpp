/**************************************************************************
**   File: purchasestatusui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchasestatusui.h"
#include "../MainWindow.h"

PurchaseStatusUI::PurchaseStatusUI(QWidget *parent) :ERPDisplay(parent)
{

purchasestatus = new PurchaseStatus();
flowLayout = new FlowLayout(this);
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
description = new QLineEdit();
block0Layout->addRow("Description",description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* PurchaseStatusUI::p_instance = 0;
void PurchaseStatusUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new PurchaseStatusUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
PurchaseStatusUI*PurchaseStatusUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PurchaseStatusUI*) p_instance; 
}
void PurchaseStatusUI::fill(PurchaseStatus* purchasestatus){ 
clear();
this->purchasestatus = purchasestatus;
description->setText(purchasestatus->Description);
} 
void PurchaseStatusUI::clear(){ 
delete this->purchasestatus;
description->setText("");
this->purchasestatus = new PurchaseStatus();
} 
void PurchaseStatusUI::selectPurchaseStatus(){ 
if(PurchaseStatus::GetStringList().contains(description->text()))
{
PurchaseStatus* con = PurchaseStatus::Get(description->text());
if(this->purchasestatus->PurchaseStatusID != con->PurchaseStatusID){
fill(con);
}
}
else if(purchasestatus->PurchaseStatusID != 0)
clear();
}
bool PurchaseStatusUI::save(){ 
bool errors = false;
QString errorString =  "";
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
purchasestatus->Description = description->text().trimmed();
}
if(!errors) {
purchasestatus->save();
if(!errors){
PurchaseStatusIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "PurchaseStatus",errorString.trimmed());
return false; 
 }
}
void PurchaseStatusUI::cancel(){ 
PurchaseStatusIndexUI::ShowUI();
}
