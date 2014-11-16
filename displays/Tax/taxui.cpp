/**************************************************************************
**   File: taxui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "taxui.h"
#include "../MainWindow.h"

TaxUI::TaxUI(QWidget *parent) :ERPDisplay(parent)
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
ratio = new QLineEdit();
ratio->setValidator( doubleValidator );
block0Layout->addRow("Ratio",ratio);
description = new QLineEdit();
block0Layout->addRow("Description",description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* TaxUI::p_instance = 0;
void TaxUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new TaxUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
TaxUI*TaxUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (TaxUI*) p_instance; 
}
void TaxUI::fill(Tax* tax){ 
this->tax = tax;
ratio->setText(QString::number(tax->Ratio));
description->setText(tax->Description);
} 
void TaxUI::clear(){ 
ratio->setText("");
description->setText("");
this->tax = new Tax();
} 
void TaxUI::selectTax(){ 
if(Tax::GetStringList().contains(description->text()))
{
Tax* con = Tax::Get(description->text());
if(this->tax->TaxID != con->TaxID){
this->tax = con;
fill(this->tax);
}
}
else if(tax->TaxID != 0)
clear();
}
void TaxUI::save(){ 
tax->Ratio = ratio->text().toDouble();
tax->Description = description->text();
tax->save();
TaxIndexUI::ShowUI();
}
void TaxUI::cancel(){ 
TaxIndexUI::ShowUI();
}
