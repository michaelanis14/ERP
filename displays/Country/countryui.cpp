/**************************************************************************
**   File: countryui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "countryui.h"
#include "../MainWindow.h"

CountryUI::CountryUI(QWidget *parent) :ERPDisplay(parent)
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
name = new QLineEdit();
QStringList* list = new QStringList(Country::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectCountry()));
block0Layout->addRow("Name",name);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* CountryUI::p_instance = 0;
void CountryUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new CountryUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
CountryUI*CountryUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (CountryUI*) p_instance; 
}
void CountryUI::fill(Country* country){ 
this->country = country;
name->setText(country->Name);
} 
void CountryUI::clear(){ 
this->country = new Country();
} 
void CountryUI::selectCountry(){ 
if(Country::GetStringList().contains(name->text()))
{
Country* con = Country::Get(name->text());
if(this->country->CountryID != con->CountryID){
this->country = con;
fill(this->country);
}
}
else if(country->CountryID != 0)
clear();
}
void CountryUI::save(){ 
country->Name = name->text();
country->save();
CountryIndexUI::ShowUI();
}
void CountryUI::cancel(){ 
CountryIndexUI::ShowUI();
}
