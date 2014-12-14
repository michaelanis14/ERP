/**************************************************************************
**   File: taxui.cpp
**   Created on: Sun Dec 14 22:39:11 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "taxui.h"
#include "../MainWindow.h"

TaxUI::TaxUI(QWidget *parent) :ERPDisplay(parent)
{

tax = new Tax();
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
block0Layout->addRow(QObject::tr("Title"),title);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* TaxUI::p_instance = 0;
void TaxUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new TaxUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
TaxUI*TaxUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (TaxUI*) p_instance; 
}
void TaxUI::fill(Tax* tax){ 
clear();
this->tax = tax;
title->setText(tax->Title);
} 
void TaxUI::clear(){ 
delete this->tax;
title->setText("");
this->tax = new Tax();
} 
void TaxUI::selectTax(){ 
if(Tax::GetStringList().contains(this->tax->Title))
{
Tax* con = Tax::Get(this->tax->Title);
if(this->tax->TaxID != con->TaxID){
fill(con);
}
}
else if(tax->TaxID != 0)
clear();
}
bool TaxUI::save(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Title Can't be Empty! \n");
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
tax->Title = title->text().trimmed();
}
if(!errors) {
tax->save();
if(!errors){
TaxIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("Tax"),errorString.trimmed());
return false; 
 }
}
void TaxUI::cancel(){ 
TaxIndexUI::ShowUI();
}
bool TaxUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Title Can't be Empty! \n");
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
tax->Title = title->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Tax"),errorString.trimmed());
return false; 
 }
}
