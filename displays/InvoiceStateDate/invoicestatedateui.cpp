/**************************************************************************
**   File: invoicestatedateui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoicestatedateui.h"
#include "../Login/loginui.h"
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
invoice = new ERPComboBox();
invoice->addItems(Invoice::GetPairList());
block0Layout->addRow(QObject::tr("Invoice"),invoice);
invoicestate = new ERPComboBox();
invoicestate->addItems(InvoiceState::GetPairList());
block0Layout->addRow(QObject::tr("Invoice State"),invoicestate);
date = new QDateEdit(QDate::currentDate());
date->setCalendarPopup(true);
date->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Date"),date);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* InvoiceStateDateUI::p_instance = 0;
void InvoiceStateDateUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->InvoiceStateDate) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new InvoiceStateDateUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
InvoiceStateDateUI*InvoiceStateDateUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoiceStateDateUI*) p_instance; 
}
void InvoiceStateDateUI::fill(InvoiceStateDate* invoicestatedate){ 
clear();
this->invoicestatedate = invoicestatedate;
invoice->setIndexByKey(invoicestatedate->InvoiceID);
invoicestate->setIndexByKey(invoicestatedate->InvoiceStateID);
date->setDate(invoicestatedate->Date);
} 
void InvoiceStateDateUI::clear(){ 
delete this->invoicestatedate;
date->setDate(QDate::currentDate());
this->invoicestatedate = new InvoiceStateDate();
} 
void InvoiceStateDateUI::selectInvoiceStateDate(){ 
if(InvoiceStateDate::GetStringList().contains(QString::number(this->invoicestatedate->InvoiceID)))
{
InvoiceStateDate* con = InvoiceStateDate::Get(QString::number(this->invoicestatedate->InvoiceID));
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
if(!invoice->isHidden()) 
invoicestatedate->InvoiceID = invoice->getKey();
if(!invoicestate->isHidden()) 
invoicestatedate->InvoiceStateID = invoicestate->getKey();
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
invoicestatedate->Date.setDate(date->date().year(),date->date().month(),date->date().day());
}
if(!errors) {
invoicestatedate->save();
if(!errors){
InvoiceStateDateIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("InvoiceStateDate"),errorString.trimmed());
return false; 
 }
}
void InvoiceStateDateUI::cancel(){ 
InvoiceStateDateIndexUI::ShowUI();
}
bool InvoiceStateDateUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(invoicestatedate->InvoiceID == 0) 
invoicestatedate->InvoiceID = invoice->getKey();
if(invoicestatedate->InvoiceStateID == 0) 
invoicestatedate->InvoiceStateID = invoicestate->getKey();
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
invoicestatedate->Date.fromString(date->text().trimmed());
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("InvoiceStateDate"),errorString.trimmed());
return false; 
 }
}
