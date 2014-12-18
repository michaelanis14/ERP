/**************************************************************************
**   File: contactpersontelephoneui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersontelephoneui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ContactPersonTelephoneUI::ContactPersonTelephoneUI(QWidget *parent) :ERPDisplay(parent)
{

contactpersontelephone = new ContactPersonTelephone();
flowLayout = new FlowLayout(this);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
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
number = new QLineEdit();
number->setValidator( intValidator );
block0Layout->addRow(QObject::tr("Number"),number);
contactperson = new ERPComboBox();
contactperson->addItems(ContactPerson::GetPairList());
block0Layout->addRow(QObject::tr("Contact Person"),contactperson);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactPersonTelephoneUI::p_instance = 0;
void ContactPersonTelephoneUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ContactPersonTelephone) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactPersonTelephoneUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ContactPersonTelephoneUI*ContactPersonTelephoneUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactPersonTelephoneUI*) p_instance; 
}
void ContactPersonTelephoneUI::fill(ContactPersonTelephone* contactpersontelephone){ 
clear();
this->contactpersontelephone = contactpersontelephone;
description->setText(contactpersontelephone->Description);
number->setText(QString::number(contactpersontelephone->Number));
contactperson->setIndexByKey(contactpersontelephone->ContactPersonID);
} 
void ContactPersonTelephoneUI::clear(){ 
delete this->contactpersontelephone;
description->setText("");
number->setText("");
this->contactpersontelephone = new ContactPersonTelephone();
} 
void ContactPersonTelephoneUI::selectContactPersonTelephone(){ 
if(ContactPersonTelephone::GetStringList().contains(this->contactpersontelephone->Description))
{
ContactPersonTelephone* con = ContactPersonTelephone::Get(this->contactpersontelephone->Description);
if(this->contactpersontelephone->ContactPersonTelephoneID != con->ContactPersonTelephoneID){
fill(con);
}
}
else if(contactpersontelephone->ContactPersonTelephoneID != 0)
clear();
}
bool ContactPersonTelephoneUI::save(){ 
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
contactpersontelephone->Description = description->text().trimmed();
}
if(number->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Number Can't be Empty! \n");
number->setObjectName("error");
number->style()->unpolish(number);
number->style()->polish(number);
number->update();
}
else { 
number->setObjectName("number");
number->style()->unpolish(number);
number->style()->polish(number);
number->update();
contactpersontelephone->Number = number->text().trimmed().toInt();
}
if(!contactperson->isHidden()) 
contactpersontelephone->ContactPersonID = contactperson->getKey();
if(!errors) {
contactpersontelephone->save();
if(!errors){
ContactPersonTelephoneIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ContactPersonTelephone"),errorString.trimmed());
return false; 
 }
}
void ContactPersonTelephoneUI::cancel(){ 
ContactPersonTelephoneIndexUI::ShowUI();
}
bool ContactPersonTelephoneUI::updateModel(){ 
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
contactpersontelephone->Description = description->text().trimmed();
}
if(number->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Number Can't be Empty! \n");
number->setObjectName("error");
number->style()->unpolish(number);
number->style()->polish(number);
number->update();
}
else { 
number->setObjectName("number");
number->style()->unpolish(number);
number->style()->polish(number);
number->update();
contactpersontelephone->Number = number->text().trimmed().toInt();
}
if(contactpersontelephone->ContactPersonID == 0) 
contactpersontelephone->ContactPersonID = contactperson->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ContactPersonTelephone"),errorString.trimmed());
return false; 
 }
}
