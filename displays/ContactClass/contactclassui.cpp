/**************************************************************************
**   File: contactclassui.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactclassui.h"
#include "../MainWindow.h"

ContactClassUI::ContactClassUI(QWidget *parent) :ERPDisplay(parent)
{

contactclass = new ContactClass();
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
ERPDisplay* ContactClassUI::p_instance = 0;
void ContactClassUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactClassUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactClassUI*ContactClassUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactClassUI*) p_instance; 
}
void ContactClassUI::fill(ContactClass* contactclass){ 
clear();
this->contactclass = contactclass;
description->setText(contactclass->Description);
} 
void ContactClassUI::clear(){ 
delete this->contactclass;
description->setText("");
this->contactclass = new ContactClass();
} 
void ContactClassUI::selectContactClass(){ 
if(ContactClass::GetStringList().contains(this->contactclass->Description))
{
ContactClass* con = ContactClass::Get(this->contactclass->Description);
if(this->contactclass->ContactClassID != con->ContactClassID){
fill(con);
}
}
else if(contactclass->ContactClassID != 0)
clear();
}
bool ContactClassUI::save(){ 
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
contactclass->Description = description->text().trimmed();
}
if(!errors) {
contactclass->save();
if(!errors){
ContactClassIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactClass",errorString.trimmed());
return false; 
 }
}
void ContactClassUI::cancel(){ 
ContactClassIndexUI::ShowUI();
}
