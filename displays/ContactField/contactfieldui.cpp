/**************************************************************************
**   File: contactfieldui.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactfieldui.h"
#include "../MainWindow.h"

ContactFieldUI::ContactFieldUI(QWidget *parent) :ERPDisplay(parent)
{

contactfield = new ContactField();
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
fieldtype = new ERPComboBox();
fieldtype->addItems(FieldType::GetPairList());
block0Layout->addRow(QObject::tr("Field Type"),fieldtype);
defaults = new QCheckBox();
block0Layout->addRow(QObject::tr("Defaults"),defaults);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactFieldUI::p_instance = 0;
void ContactFieldUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactFieldUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactFieldUI*ContactFieldUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactFieldUI*) p_instance; 
}
void ContactFieldUI::fill(ContactField* contactfield){ 
clear();
this->contactfield = contactfield;
description->setText(contactfield->Description);
fieldtype->setIndexByKey(contactfield->FieldTypeID);
defaults->setChecked(contactfield->Defaults);
} 
void ContactFieldUI::clear(){ 
delete this->contactfield;
description->setText("");
defaults->setChecked(false);
this->contactfield = new ContactField();
} 
void ContactFieldUI::selectContactField(){ 
if(ContactField::GetStringList().contains(this->contactfield->Description))
{
ContactField* con = ContactField::Get(this->contactfield->Description);
if(this->contactfield->ContactFieldID != con->ContactFieldID){
fill(con);
}
}
else if(contactfield->ContactFieldID != 0)
clear();
}
bool ContactFieldUI::save(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Description Can't be Empty! \n");
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
contactfield->Description = description->text().trimmed();
}
if(!fieldtype->isHidden()) 
contactfield->FieldTypeID = fieldtype->getKey();
contactfield->Defaults = defaults->text().trimmed().toInt();
if(!errors) {
contactfield->save();
if(!errors){
ContactFieldIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ContactField"),errorString.trimmed());
return false; 
 }
}
void ContactFieldUI::cancel(){ 
ContactFieldIndexUI::ShowUI();
}
bool ContactFieldUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Description Can't be Empty! \n");
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
contactfield->Description = description->text().trimmed();
}
if(contactfield->FieldTypeID == 0) 
contactfield->FieldTypeID = fieldtype->getKey();
contactfield->Defaults = defaults->text().trimmed().toInt();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ContactField"),errorString.trimmed());
return false; 
 }
}
