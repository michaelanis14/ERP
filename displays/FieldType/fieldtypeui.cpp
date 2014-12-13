/**************************************************************************
**   File: fieldtypeui.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "fieldtypeui.h"
#include "../MainWindow.h"

FieldTypeUI::FieldTypeUI(QWidget *parent) :ERPDisplay(parent)
{

fieldtype = new FieldType();
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
ERPDisplay* FieldTypeUI::p_instance = 0;
void FieldTypeUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new FieldTypeUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
FieldTypeUI*FieldTypeUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (FieldTypeUI*) p_instance; 
}
void FieldTypeUI::fill(FieldType* fieldtype){ 
clear();
this->fieldtype = fieldtype;
description->setText(fieldtype->Description);
} 
void FieldTypeUI::clear(){ 
delete this->fieldtype;
description->setText("");
this->fieldtype = new FieldType();
} 
void FieldTypeUI::selectFieldType(){ 
if(FieldType::GetStringList().contains(this->fieldtype->Description))
{
FieldType* con = FieldType::Get(this->fieldtype->Description);
if(this->fieldtype->FieldTypeID != con->FieldTypeID){
fill(con);
}
}
else if(fieldtype->FieldTypeID != 0)
clear();
}
bool FieldTypeUI::save(){ 
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
fieldtype->Description = description->text().trimmed();
}
if(!errors) {
fieldtype->save();
if(!errors){
FieldTypeIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "FieldType",errorString.trimmed());
return false; 
 }
}
void FieldTypeUI::cancel(){ 
FieldTypeIndexUI::ShowUI();
}
bool FieldTypeUI::updateModel(){ 
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
fieldtype->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "FieldType",errorString.trimmed());
return false; 
 }
}
