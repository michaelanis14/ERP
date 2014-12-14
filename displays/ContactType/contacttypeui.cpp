/**************************************************************************
**   File: contacttypeui.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contacttypeui.h"
#include "../MainWindow.h"

ContactTypeUI::ContactTypeUI(QWidget *parent) :ERPDisplay(parent)
{

contacttype = new ContactType();
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
block0Layout->addRow(QObject::tr("Description"),description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactTypeUI::p_instance = 0;
void ContactTypeUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactTypeUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactTypeUI*ContactTypeUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactTypeUI*) p_instance; 
}
void ContactTypeUI::fill(ContactType* contacttype){ 
clear();
this->contacttype = contacttype;
description->setText(contacttype->Description);
} 
void ContactTypeUI::clear(){ 
delete this->contacttype;
description->setText("");
this->contacttype = new ContactType();
} 
void ContactTypeUI::selectContactType(){ 
if(ContactType::GetStringList().contains(this->contacttype->Description))
{
ContactType* con = ContactType::Get(this->contacttype->Description);
if(this->contacttype->ContactTypeID != con->ContactTypeID){
fill(con);
}
}
else if(contacttype->ContactTypeID != 0)
clear();
}
bool ContactTypeUI::save(){ 
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
contacttype->Description = description->text().trimmed();
}
if(!errors) {
contacttype->save();
if(!errors){
ContactTypeIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactType",errorString.trimmed());
return false; 
 }
}
void ContactTypeUI::cancel(){ 
ContactTypeIndexUI::ShowUI();
}
bool ContactTypeUI::updateModel(){ 
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
contacttype->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "ContactType",errorString.trimmed());
return false; 
 }
}
