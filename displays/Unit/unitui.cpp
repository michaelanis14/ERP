/**************************************************************************
**   File: unitui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "unitui.h"
#include "../MainWindow.h"

UnitUI::UnitUI(QWidget *parent) :ERPDisplay(parent)
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
ERPDisplay* UnitUI::p_instance = 0;
void UnitUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new UnitUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
UnitUI*UnitUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (UnitUI*) p_instance; 
}
void UnitUI::fill(Unit* unit){ 
this->unit = unit;
description->setText(unit->Description);
} 
void UnitUI::clear(){ 
description->setText("");
this->unit = new Unit();
} 
void UnitUI::selectUnit(){ 
if(Unit::GetStringList().contains(description->text()))
{
Unit* con = Unit::Get(description->text());
if(this->unit->UnitID != con->UnitID){
this->unit = con;
fill(this->unit);
}
}
else if(unit->UnitID != 0)
clear();
}
void UnitUI::save(){ 
unit->Description = description->text();
unit->save();
UnitIndexUI::ShowUI();
}
void UnitUI::cancel(){ 
UnitIndexUI::ShowUI();
}
