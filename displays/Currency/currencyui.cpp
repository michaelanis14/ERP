/**************************************************************************
**   File: currencyui.cpp
**   Created on: Wed Nov 26 16:22:56 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "currencyui.h"
#include "../MainWindow.h"

CurrencyUI::CurrencyUI(QWidget *parent) :ERPDisplay(parent)
{

currency = new Currency();
flowLayout = new FlowLayout(formPanel);
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
description = new QLineEdit();
block0Layout->addRow("Description",description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* CurrencyUI::p_instance = 0;
void CurrencyUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new CurrencyUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
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
if(Currency::GetStringList().contains(description->text()))
{
Currency* con = Currency::Get(description->text());
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
currency->Description = description->text().trimmed();
}
if(!errors) {
currency->save();
if(!errors){
CurrencyIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Currency",errorString.trimmed());
return false; 
 }
}
void CurrencyUI::cancel(){ 
CurrencyIndexUI::ShowUI();
}
