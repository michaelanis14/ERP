/**************************************************************************
**   File: contactpersonfielddataui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersonfielddataui.h"
#include "../Login/loginui.h"
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
block0Layout->addRow(QObject::tr("Contact Person"),contactperson);
contactpersonfield = new ERPComboBox();
contactpersonfield->addItems(ContactPersonField::GetPairList());
block0Layout->addRow(QObject::tr("Contact Person Field"),contactpersonfield);
value = new QLineEdit();
block0Layout->addRow(QObject::tr("Value"),value);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactPersonFieldDataUI::p_instance = 0;
void ContactPersonFieldDataUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ContactPersonFieldData) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactPersonFieldDataUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ContactPersonFieldDataUI*ContactPersonFieldDataUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactPersonFieldDataUI*) p_instance; 
}
void ContactPersonFieldDataUI::fill(ContactPersonFieldData* contactpersonfielddata){ 
clear();
this->contactpersonfielddata = contactpersonfielddata;
contactperson->setIndexByKey(contactpersonfielddata->ContactPersonID);
contactpersonfield->setIndexByKey(contactpersonfielddata->ContactPersonFieldID);
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
errorString += QObject::tr("Value Can't be Empty! \n");
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
else{ QMessageBox::warning(this, QObject::tr("ContactPersonFieldData"),errorString.trimmed());
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
errorString += QObject::tr("Value Can't be Empty! \n");
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
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ContactPersonFieldData"),errorString.trimmed());
return false; 
 }
}
