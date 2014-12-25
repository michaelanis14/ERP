/**************************************************************************
**   File: contactfielddataui.cpp
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactfielddataui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ContactFieldDataUI::ContactFieldDataUI(QWidget *parent) :ERPDisplay(parent)
{

contactfielddata = new ContactFieldData();
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
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
contactfield = new ERPComboBox();
contactfield->addItems(ContactField::GetPairList());
block0Layout->addRow(QObject::tr("Contact Field"),contactfield);
value = new QLineEdit();
block0Layout->addRow(QObject::tr("Value"),value);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactFieldDataUI::p_instance = 0;
void ContactFieldDataUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ContactFieldData) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactFieldDataUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ContactFieldDataUI*ContactFieldDataUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactFieldDataUI*) p_instance; 
}
void ContactFieldDataUI::fill(ContactFieldData* contactfielddata){ 
clear();
this->contactfielddata = contactfielddata;
contact->setIndexByKey(contactfielddata->ContactID);
contactfield->setIndexByKey(contactfielddata->ContactFieldID);
value->setText(contactfielddata->Value);
} 
void ContactFieldDataUI::clear(){ 
delete this->contactfielddata;
value->setText("");
this->contactfielddata = new ContactFieldData();
} 
void ContactFieldDataUI::selectContactFieldData(){ 
if(ContactFieldData::GetStringList().contains(QString::number(this->contactfielddata->ContactID)))
{
ContactFieldData* con = ContactFieldData::Get(QString::number(this->contactfielddata->ContactID));
if(this->contactfielddata->ContactFieldDataID != con->ContactFieldDataID){
fill(con);
}
}
else if(contactfielddata->ContactFieldDataID != 0)
clear();
}
bool ContactFieldDataUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!contact->isHidden()) 
contactfielddata->ContactID = contact->getKey();
if(!contactfield->isHidden()) 
contactfielddata->ContactFieldID = contactfield->getKey();
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
contactfielddata->Value = value->text().trimmed();
}
if(!errors) {
contactfielddata->save();
if(!errors){
ContactFieldDataIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ContactFieldData"),errorString.trimmed());
return false; 
 }
}
void ContactFieldDataUI::cancel(){ 
ContactFieldDataIndexUI::ShowUI();
}
bool ContactFieldDataUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(contactfielddata->ContactID == 0) 
contactfielddata->ContactID = contact->getKey();
if(contactfielddata->ContactFieldID == 0) 
contactfielddata->ContactFieldID = contactfield->getKey();
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
contactfielddata->Value = value->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ContactFieldData"),errorString.trimmed());
return false; 
 }
}
