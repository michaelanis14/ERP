/**************************************************************************
**   File: contacttelephoneui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contacttelephoneui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ContactTelephoneUI::ContactTelephoneUI(QWidget *parent) :ERPDisplay(parent)
{

contacttelephone = new ContactTelephone();
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
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactTelephoneUI::p_instance = 0;
void ContactTelephoneUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ContactTelephone) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactTelephoneUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ContactTelephoneUI*ContactTelephoneUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactTelephoneUI*) p_instance; 
}
void ContactTelephoneUI::fill(ContactTelephone* contacttelephone){ 
clear();
this->contacttelephone = contacttelephone;
description->setText(contacttelephone->Description);
number->setText(QString::number(contacttelephone->Number));
contact->setIndexByKey(contacttelephone->ContactID);
} 
void ContactTelephoneUI::clear(){ 
delete this->contacttelephone;
description->setText("");
number->setText("");
this->contacttelephone = new ContactTelephone();
} 
void ContactTelephoneUI::selectContactTelephone(){ 
if(ContactTelephone::GetStringList().contains(this->contacttelephone->Description))
{
ContactTelephone* con = ContactTelephone::Get(this->contacttelephone->Description);
if(this->contacttelephone->ContactTelephoneID != con->ContactTelephoneID){
fill(con);
}
}
else if(contacttelephone->ContactTelephoneID != 0)
clear();
}
bool ContactTelephoneUI::save(){ 
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
contacttelephone->Description = description->text().trimmed();
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
contacttelephone->Number = number->text().trimmed().toInt();
}
if(!contact->isHidden()) 
contacttelephone->ContactID = contact->getKey();
if(!errors) {
contacttelephone->save();
if(!errors){
ContactTelephoneIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ContactTelephone"),errorString.trimmed());
return false; 
 }
}
void ContactTelephoneUI::cancel(){ 
ContactTelephoneIndexUI::ShowUI();
}
bool ContactTelephoneUI::updateModel(){ 
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
contacttelephone->Description = description->text().trimmed();
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
contacttelephone->Number = number->text().trimmed().toInt();
}
if(contacttelephone->ContactID == 0) 
contacttelephone->ContactID = contact->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ContactTelephone"),errorString.trimmed());
return false; 
 }
}
