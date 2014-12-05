/**************************************************************************
**   File: contactstatusui.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactstatusui.h"
#include "../MainWindow.h"

ContactStatusUI::ContactStatusUI(QWidget *parent) :ERPDisplay(parent)
{

contactstatus = new ContactStatus();
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
block0Layout->addRow("Description",description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactStatusUI::p_instance = 0;
void ContactStatusUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactStatusUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactStatusUI*ContactStatusUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactStatusUI*) p_instance; 
}
void ContactStatusUI::fill(ContactStatus* contactstatus){ 
clear();
this->contactstatus = contactstatus;
description->setText(contactstatus->Description);
} 
void ContactStatusUI::clear(){ 
delete this->contactstatus;
description->setText("");
this->contactstatus = new ContactStatus();
} 
void ContactStatusUI::selectContactStatus(){ 
if(ContactStatus::GetStringList().contains(description->text()))
{
ContactStatus* con = ContactStatus::Get(description->text());
if(this->contactstatus->ContactStatusID != con->ContactStatusID){
fill(con);
}
}
else if(contactstatus->ContactStatusID != 0)
clear();
}
bool ContactStatusUI::save(){ 
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
contactstatus->Description = description->text().trimmed();
}
if(!errors) {
contactstatus->save();
if(!errors){
ContactStatusIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactStatus",errorString.trimmed());
return false; 
 }
}
void ContactStatusUI::cancel(){ 
ContactStatusIndexUI::ShowUI();
}
