/**************************************************************************
**   File: currencyui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "currencyui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

CurrencyUI::CurrencyUI(QWidget *parent) :ERPDisplay(parent)
{

currency = new Currency();
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
ERPDisplay* CurrencyUI::p_instance = 0;
void CurrencyUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Currency) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new CurrencyUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
CurrencyUI*CurrencyUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (CurrencyUI*) p_instance; 
}
void CurrencyUI::fill(Currency* currency){ 
clear();
this->currency = currency;
description->setText(currency->Description);
} 
void CurrencyUI::clear(){ 
delete this->currency;
description->setText("");
this->currency = new Currency();
} 
void CurrencyUI::selectCurrency(){ 
if(Currency::GetStringList().contains(this->currency->Description))
{
Currency* con = Currency::Get(this->currency->Description);
if(this->currency->CurrencyID != con->CurrencyID){
fill(con);
}
}
else if(currency->CurrencyID != 0)
clear();
}
bool CurrencyUI::save(){ 
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
currency->Description = description->text().trimmed();
}
if(!errors) {
currency->save();
if(!errors){
CurrencyIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("Currency"),errorString.trimmed());
return false; 
 }
}
void CurrencyUI::cancel(){ 
CurrencyIndexUI::ShowUI();
}
bool CurrencyUI::updateModel(){ 
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
currency->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Currency"),errorString.trimmed());
return false; 
 }
}
