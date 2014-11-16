/**************************************************************************
**   File: contacttypeui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contacttypeui.h"
#include "../MainWindow.h"

ContactTypeUI::ContactTypeUI(QWidget *parent) :ERPDisplay(parent)
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
ERPDisplay* ContactTypeUI::p_instance = 0;
void ContactTypeUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ContactTypeUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
ContactTypeUI*ContactTypeUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactTypeUI*) p_instance; 
}
void ContactTypeUI::fill(ContactType* contacttype){ 
this->contacttype = contacttype;
description->setText(contacttype->Description);
} 
void ContactTypeUI::clear(){ 
description->setText("");
this->contacttype = new ContactType();
} 
void ContactTypeUI::selectContactType(){ 
if(ContactType::GetStringList().contains(description->text()))
{
ContactType* con = ContactType::Get(description->text());
if(this->contacttype->ContactTypeID != con->ContactTypeID){
this->contacttype = con;
fill(this->contacttype);
}
}
else if(contacttype->ContactTypeID != 0)
clear();
}
void ContactTypeUI::save(){ 
contacttype->Description = description->text();
contacttype->save();
ContactTypeIndexUI::ShowUI();
}
void ContactTypeUI::cancel(){ 
ContactTypeIndexUI::ShowUI();
}
