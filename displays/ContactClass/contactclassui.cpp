/**************************************************************************
**   File: contactclassui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactclassui.h"
#include "../MainWindow.h"

ContactClassUI::ContactClassUI(QWidget *parent) :ERPDisplay(parent)
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
ERPDisplay* ContactClassUI::p_instance = 0;
void ContactClassUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ContactClassUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
ContactClassUI*ContactClassUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactClassUI*) p_instance; 
}
void ContactClassUI::fill(ContactClass* contactclass){ 
this->contactclass = contactclass;
description->setText(contactclass->Description);
} 
void ContactClassUI::clear(){ 
description->setText("");
this->contactclass = new ContactClass();
} 
void ContactClassUI::selectContactClass(){ 
if(ContactClass::GetStringList().contains(description->text()))
{
ContactClass* con = ContactClass::Get(description->text());
if(this->contactclass->ContactClassID != con->ContactClassID){
this->contactclass = con;
fill(this->contactclass);
}
}
else if(contactclass->ContactClassID != 0)
clear();
}
void ContactClassUI::save(){ 
contactclass->Description = description->text();
contactclass->save();
ContactClassIndexUI::ShowUI();
}
void ContactClassUI::cancel(){ 
ContactClassIndexUI::ShowUI();
}
