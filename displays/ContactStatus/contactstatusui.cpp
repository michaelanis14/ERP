/**************************************************************************
**   File: contactstatusui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactstatusui.h"
#include "../MainWindow.h"

ContactStatusUI::ContactStatusUI(QWidget *parent) :ERPDisplay(parent)
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
ERPDisplay* ContactStatusUI::p_instance = 0;
void ContactStatusUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ContactStatusUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
ContactStatusUI*ContactStatusUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactStatusUI*) p_instance; 
}
void ContactStatusUI::fill(ContactStatus* contactstatus){ 
this->contactstatus = contactstatus;
description->setText(contactstatus->Description);
} 
void ContactStatusUI::clear(){ 
description->setText("");
this->contactstatus = new ContactStatus();
} 
void ContactStatusUI::selectContactStatus(){ 
if(ContactStatus::GetStringList().contains(description->text()))
{
ContactStatus* con = ContactStatus::Get(description->text());
if(this->contactstatus->ContactStatusID != con->ContactStatusID){
this->contactstatus = con;
fill(this->contactstatus);
}
}
else if(contactstatus->ContactStatusID != 0)
clear();
}
void ContactStatusUI::save(){ 
contactstatus->Description = description->text();
contactstatus->save();
ContactStatusIndexUI::ShowUI();
}
void ContactStatusUI::cancel(){ 
ContactStatusIndexUI::ShowUI();
}
