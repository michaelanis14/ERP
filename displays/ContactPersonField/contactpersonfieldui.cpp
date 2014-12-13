/**************************************************************************
**   File: contactpersonfieldui.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersonfieldui.h"
#include "../MainWindow.h"

ContactPersonFieldUI::ContactPersonFieldUI(QWidget *parent) :ERPDisplay(parent)
{

contactpersonfield = new ContactPersonField();
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
fieldtype = new ERPComboBox();
fieldtype->addItems(FieldType::GetPairList());
block0Layout->addRow("Field Type",fieldtype);
defaults = new QCheckBox();
block0Layout->addRow("Defaults",defaults);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactPersonFieldUI::p_instance = 0;
void ContactPersonFieldUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactPersonFieldUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactPersonFieldUI*ContactPersonFieldUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactPersonFieldUI*) p_instance; 
}
void ContactPersonFieldUI::fill(ContactPersonField* contactpersonfield){ 
clear();
this->contactpersonfield = contactpersonfield;
description->setText(contactpersonfield->Description);
defaults->setChecked(contactpersonfield->Defaults);
} 
void ContactPersonFieldUI::clear(){ 
delete this->contactpersonfield;
description->setText("");
defaults->setChecked(false);
this->contactpersonfield = new ContactPersonField();
} 
void ContactPersonFieldUI::selectContactPersonField(){ 
if(ContactPersonField::GetStringList().contains(this->contactpersonfield->Description))
{
ContactPersonField* con = ContactPersonField::Get(this->contactpersonfield->Description);
if(this->contactpersonfield->ContactPersonFieldID != con->ContactPersonFieldID){
fill(con);
}
}
else if(contactpersonfield->ContactPersonFieldID != 0)
clear();
}
bool ContactPersonFieldUI::save(){ 
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
contactpersonfield->Description = description->text().trimmed();
}
if(!fieldtype->isHidden()) 
contactpersonfield->FieldTypeID = fieldtype->getKey();
contactpersonfield->Defaults = defaults->text().trimmed().toInt();
if(!errors) {
contactpersonfield->save();
if(!errors){
ContactPersonFieldIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactPersonField",errorString.trimmed());
return false; 
 }
}
void ContactPersonFieldUI::cancel(){ 
ContactPersonFieldIndexUI::ShowUI();
}
bool ContactPersonFieldUI::updateModel(){ 
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
contactpersonfield->Description = description->text().trimmed();
}
if(contactpersonfield->FieldTypeID == 0) 
contactpersonfield->FieldTypeID = fieldtype->getKey();
contactpersonfield->Defaults = defaults->text().trimmed().toInt();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "ContactPersonField",errorString.trimmed());
return false; 
 }
}
