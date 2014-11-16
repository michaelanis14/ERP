/**************************************************************************
**   File: currencyui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "currencyui.h"
#include "../MainWindow.h"

CurrencyUI::CurrencyUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
ERPFormBlock * blockSaveCancel = new ERPFormBlock;
 QWidget* addremove = new QWidget();
 QHBoxLayout* addRemovelayout = new QHBoxLayout(addremove);
 addRemovelayout->setContentsMargins(0,0,0,0);
 QPushButton* save = new QPushButton("Save");
 QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
 save->setObjectName("save");
 QPushButton* cancel = new QPushButton("Cancel");
 cancel->setObjectName("cancel");
 QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
 QPushButton* clear = new QPushButton("Clear");
 QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
 clear->setObjectName("clear");
 addRemovelayout->addStretch(1);
 addRemovelayout->addWidget(save,0,Qt::AlignCenter);
 addRemovelayout->addStretch(0);
 addRemovelayout->addWidget(clear,0,Qt::AlignCenter);
 addRemovelayout->addWidget(cancel,0,Qt::AlignCenter);
 addRemovelayout->addStretch(1);
 blockSaveCancel->addRow("",addremove);
 flowLayout->addWidget(blockSaveCancel);
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
this->currency = currency;
description->setText(currency->Description);
} 
void CurrencyUI::clear(){ 
description->setText("");
this->currency = new Currency();
} 
void CurrencyUI::selectCurrency(){ 
if(Currency::GetStringList().contains(description->text()))
{
Currency* con = Currency::Get(description->text());
if(this->currency->CurrencyID != con->CurrencyID){
this->currency = con;
fill(this->currency);
}
}
else if(currency->CurrencyID != 0)
clear();
}
void CurrencyUI::save(){ 
currency->Description = description->text();
currency->save();
CurrencyIndexUI::ShowUI();
}
void CurrencyUI::cancel(){ 
CurrencyIndexUI::ShowUI();
}
