/**************************************************************************
**   File: invoiceperiodui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoiceperiodui.h"
#include "../MainWindow.h"

InvoicePeriodUI::InvoicePeriodUI(QWidget *parent) :ERPDisplay(parent)
{

invoiceperiod = new InvoicePeriod();
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
ERPDisplay* InvoicePeriodUI::p_instance = 0;
void InvoicePeriodUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new InvoicePeriodUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
InvoicePeriodUI*InvoicePeriodUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoicePeriodUI*) p_instance; 
}
void InvoicePeriodUI::fill(InvoicePeriod* invoiceperiod){ 
clear();
this->invoiceperiod = invoiceperiod;
description->setText(invoiceperiod->Description);
} 
void InvoicePeriodUI::clear(){ 
delete this->invoiceperiod;
description->setText("");
this->invoiceperiod = new InvoicePeriod();
} 
void InvoicePeriodUI::selectInvoicePeriod(){ 
if(InvoicePeriod::GetStringList().contains(this->invoiceperiod->Description))
{
InvoicePeriod* con = InvoicePeriod::Get(this->invoiceperiod->Description);
if(this->invoiceperiod->InvoicePeriodID != con->InvoicePeriodID){
fill(con);
}
}
else if(invoiceperiod->InvoicePeriodID != 0)
clear();
}
bool InvoicePeriodUI::save(){ 
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
invoiceperiod->Description = description->text().trimmed();
}
if(!errors) {
invoiceperiod->save();
if(!errors){
InvoicePeriodIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "InvoicePeriod",errorString.trimmed());
return false; 
 }
}
void InvoicePeriodUI::cancel(){ 
InvoicePeriodIndexUI::ShowUI();
}
bool InvoicePeriodUI::updateModel(){ 
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
invoiceperiod->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "InvoicePeriod",errorString.trimmed());
return false; 
 }
}
