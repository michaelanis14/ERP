/**************************************************************************
**   File: invoicestateui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoicestateui.h"
#include "../MainWindow.h"

InvoiceStateUI::InvoiceStateUI(QWidget *parent) :ERPDisplay(parent)
{

invoicestate = new InvoiceState();
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
ERPDisplay* InvoiceStateUI::p_instance = 0;
void InvoiceStateUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new InvoiceStateUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
InvoiceStateUI*InvoiceStateUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoiceStateUI*) p_instance; 
}
void InvoiceStateUI::fill(InvoiceState* invoicestate){ 
clear();
this->invoicestate = invoicestate;
description->setText(invoicestate->Description);
} 
void InvoiceStateUI::clear(){ 
delete this->invoicestate;
description->setText("");
this->invoicestate = new InvoiceState();
} 
void InvoiceStateUI::selectInvoiceState(){ 
if(InvoiceState::GetStringList().contains(this->invoicestate->Description))
{
InvoiceState* con = InvoiceState::Get(this->invoicestate->Description);
if(this->invoicestate->InvoiceStateID != con->InvoiceStateID){
fill(con);
}
}
else if(invoicestate->InvoiceStateID != 0)
clear();
}
bool InvoiceStateUI::save(){ 
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
invoicestate->Description = description->text().trimmed();
}
if(!errors) {
invoicestate->save();
if(!errors){
InvoiceStateIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "InvoiceState",errorString.trimmed());
return false; 
 }
}
void InvoiceStateUI::cancel(){ 
InvoiceStateIndexUI::ShowUI();
}
bool InvoiceStateUI::updateModel(){ 
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
invoicestate->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "InvoiceState",errorString.trimmed());
return false; 
 }
}
