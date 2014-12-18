/**************************************************************************
**   File: invoiceyearui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoiceyearui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

InvoiceYearUI::InvoiceYearUI(QWidget *parent) :ERPDisplay(parent)
{

invoiceyear = new InvoiceYear();
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
block0Layout->addRow(QObject::tr("Description"),description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* InvoiceYearUI::p_instance = 0;
void InvoiceYearUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->InvoiceYear) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new InvoiceYearUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
InvoiceYearUI*InvoiceYearUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (InvoiceYearUI*) p_instance; 
}
void InvoiceYearUI::fill(InvoiceYear* invoiceyear){ 
clear();
this->invoiceyear = invoiceyear;
description->setText(invoiceyear->Description);
} 
void InvoiceYearUI::clear(){ 
delete this->invoiceyear;
description->setText("");
this->invoiceyear = new InvoiceYear();
} 
void InvoiceYearUI::selectInvoiceYear(){ 
if(InvoiceYear::GetStringList().contains(this->invoiceyear->Description))
{
InvoiceYear* con = InvoiceYear::Get(this->invoiceyear->Description);
if(this->invoiceyear->InvoiceYearID != con->InvoiceYearID){
fill(con);
}
}
else if(invoiceyear->InvoiceYearID != 0)
clear();
}
bool InvoiceYearUI::save(){ 
bool errors = false;
QString errorString =  "";
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
invoiceyear->Description = description->text().trimmed();
}
if(!errors) {
invoiceyear->save();
if(!errors){
InvoiceYearIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("InvoiceYear"),errorString.trimmed());
return false; 
 }
}
void InvoiceYearUI::cancel(){ 
InvoiceYearIndexUI::ShowUI();
}
bool InvoiceYearUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
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
invoiceyear->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("InvoiceYear"),errorString.trimmed());
return false; 
 }
}
