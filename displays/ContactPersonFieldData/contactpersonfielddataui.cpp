/**************************************************************************
**   File: contactpersonfielddataui.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersonfielddataui.h"
#include "../MainWindow.h"

ContactPersonFieldDataUI::ContactPersonFieldDataUI(QWidget *parent) :ERPDisplay(parent)
{

contactpersonfielddata = new ContactPersonFieldData();
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
contactperson = new ERPComboBox();
contactperson->addItems(ContactPerson::GetPairList());
block0Layout->addRow("Contact Person",contactperson);
contactpersonfield = new ERPComboBox();
contactpersonfield->addItems(ContactPersonField::GetPairList());
block0Layout->addRow("Contact Person Field",contactpersonfield);
value = new QLineEdit();
block0Layout->addRow("Value",value);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactPersonFieldDataUI::p_instance = 0;
void ContactPersonFieldDataUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactPersonFieldDataUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactPersonFieldDataUI*ContactPersonFieldDataUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactPersonFieldDataUI*) p_instance; 
}
void ContactPersonFieldDataUI::fill(ContactPersonFieldData* contactpersonfielddata){ 
clear();
this->contactpersonfielddata = contactpersonfielddata;
value->setText(contactpersonfielddata->Value);
} 
void ContactPersonFieldDataUI::clear(){ 
delete this->contactpersonfielddata;
value->setText("");
this->contactpersonfielddata = new ContactPersonFieldData();
} 
void ContactPersonFieldDataUI::selectContactPersonFieldData(){ 
if(ContactPersonFieldData::GetStringList().contains(QString::number(this->contactpersonfielddata->ContactPersonID)))
{
ContactPersonFieldData* con = ContactPersonFieldData::Get(QString::number(this->contactpersonfielddata->ContactPersonID));
if(this->contactpersonfielddata->ContactPersonFieldDataID != con->ContactPersonFieldDataID){
fill(con);
}
}
else if(contactpersonfielddata->ContactPersonFieldDataID != 0)
clear();
}
bool ContactPersonFieldDataUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!contactperson->isHidden()) 
contactpersonfielddata->ContactPersonID = contactperson->getKey();
if(!contactpersonfield->isHidden()) 
contactpersonfielddata->ContactPersonFieldID = contactpersonfield->getKey();
if(value->text().trimmed().isEmpty()){
errors = true;
errorString += "Value Can't be Empty! \n";
value->setObjectName("error");
value->style()->unpolish(value);
value->style()->polish(value);
value->update();
}
else { 
value->setObjectName("value");
value->style()->unpolish(value);
value->style()->polish(value);
value->update();
contactpersonfielddata->Value = value->text().trimmed();
}
if(!errors) {
contactpersonfielddata->save();
if(!errors){
ContactPersonFieldDataIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactPersonFieldData",errorString.trimmed());
return false; 
 }
}
void ContactPersonFieldDataUI::cancel(){ 
ContactPersonFieldDataIndexUI::ShowUI();
}
bool ContactPersonFieldDataUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(contactpersonfielddata->ContactPersonID == 0) 
contactpersonfielddata->ContactPersonID = contactperson->getKey();
if(contactpersonfielddata->ContactPersonFieldID == 0) 
contactpersonfielddata->ContactPersonFieldID = contactpersonfield->getKey();
if(value->text().trimmed().isEmpty()){
errors = true;
errorString += "Value Can't be Empty! \n";
value->setObjectName("error");
value->style()->unpolish(value);
value->style()->polish(value);
value->update();
}
else { 
value->setObjectName("value");
value->style()->unpolish(value);
value->style()->polish(value);
value->update();
contactpersonfielddata->Value = value->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "ContactPersonFieldData",errorString.trimmed());
return false; 
 }
}
