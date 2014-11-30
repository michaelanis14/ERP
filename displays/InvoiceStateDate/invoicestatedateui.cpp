/**************************************************************************
**   File: invoicestatedateui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoicestatedateui.h"
#include "../MainWindow.h"

InvoiceStateDateUI::InvoiceStateDateUI(QWidget *parent) :ERPDisplay(parent)
{

invoicestatedate = new InvoiceStateDate();
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
title = new QLineEdit();
block0Layout->addRow("Title",title);
invoice = new ERPComboBox();
invoice->addItems(Invoice::GetHashList());
block0Layout->addRow("Invoice",invoice);
invoicestate = new ERPComboBox();
invoicestate->addItems(InvoiceState::GetHashList());
block0Layout->addRow("Invoice State",invoicestate);
date = new QLineEdit();
block0Layout->addRow("Date",date);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* InvoiceStateDateUI::p_instance = 0;
void InvoiceStateDateUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new InvoiceStateDateUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
InvoiceStateDateUI*InvoiceStateDateUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoiceStateDateUI*) p_instance; 
}
void InvoiceStateDateUI::fill(InvoiceStateDate* invoicestatedate){ 
clear();
this->invoicestatedate = invoicestatedate;
title->setText(invoicestatedate->Title);
date->setText(invoicestatedate->Date);
} 
void InvoiceStateDateUI::clear(){ 
delete this->invoicestatedate;
title->setText("");
date->setText("");
this->invoicestatedate = new InvoiceStateDate();
} 
void InvoiceStateDateUI::selectInvoiceStateDate(){ 
if(InvoiceStateDate::GetStringList().contains(title->text()))
{
InvoiceStateDate* con = InvoiceStateDate::Get(title->text());
if(this->invoicestatedate->InvoiceStateDateID != con->InvoiceStateDateID){
fill(con);
}
}
else if(invoicestatedate->InvoiceStateDateID != 0)
clear();
}
bool InvoiceStateDateUI::save(){ 
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
invoicestatedate->Title = title->text().trimmed();
}
if(invoicestatedate->InvoiceID == 0) 
invoicestatedate->InvoiceID = invoice->getKey();
if(invoicestatedate->InvoiceStateID == 0) 
invoicestatedate->InvoiceStateID = invoicestate->getKey();
if(date->text().trimmed().isEmpty()){
errors = true;
errorString += "Date Can't be Empty! \n";
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
invoicestatedate->Date = date->text().trimmed();
}
if(!errors) {
invoicestatedate->save();
if(!errors){
InvoiceStateDateIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "InvoiceStateDate",errorString.trimmed());
return false; 
 }
}
void InvoiceStateDateUI::cancel(){ 
InvoiceStateDateIndexUI::ShowUI();
}
