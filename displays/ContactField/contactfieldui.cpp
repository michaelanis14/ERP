/**************************************************************************
**   File: contactfieldui.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
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
fieldtype = new ERPComboBox();
fieldtype->addItems(FieldType::GetHashList());
block0Layout->addRow("Field Type",fieldtype);
description = new QLineEdit();
block0Layout->addRow("Description",description);
defaults = new QCheckBox();
block0Layout->addRow("Defaults",defaults);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactFieldUI::p_instance = 0;
void ContactFieldUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ContactFieldUI(mainwindow::GetMainDisplay());
	} 
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
defaults->setChecked(contactfield->Defaults);
} 
void ContactFieldUI::clear(){ 
delete this->contactfield;
description->setText("");
defaults->setChecked(false);
this->contactfield = new ContactField();
} 
void ContactFieldUI::selectContactField(){ 
if(ContactField::GetStringList().contains(description->text()))
{
ContactField* con = ContactField::Get(description->text());
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
if(contactfield->FieldTypeID == 0) 
contactfield->FieldTypeID = fieldtype->getKey();
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
contactfield->Description = description->text().trimmed();
}
contactfield->Defaults = defaults->text().trimmed().toInt();
if(!errors) {
contactfield->save();
if(!errors){
ContactFieldIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactField",errorString.trimmed());
return false; 
 }
}
void ContactFieldUI::cancel(){ 
ContactFieldIndexUI::ShowUI();
}
