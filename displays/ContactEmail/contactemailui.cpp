/**************************************************************************
**   File: contactemailui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactemailui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ContactEmailUI::ContactEmailUI(QWidget *parent) :ERPDisplay(parent)
{

contactemail = new ContactEmail();
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
email = new QLineEdit();
block0Layout->addRow(QObject::tr("Email"),email);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactEmailUI::p_instance = 0;
void ContactEmailUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ContactEmail) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactEmailUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ContactEmailUI*ContactEmailUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactEmailUI*) p_instance; 
}
void ContactEmailUI::fill(ContactEmail* contactemail){ 
clear();
this->contactemail = contactemail;
description->setText(contactemail->Description);
email->setText(contactemail->Email);
contact->setIndexByKey(contactemail->ContactID);
} 
void ContactEmailUI::clear(){ 
delete this->contactemail;
description->setText("");
email->setText("");
this->contactemail = new ContactEmail();
} 
void ContactEmailUI::selectContactEmail(){ 
if(ContactEmail::GetStringList().contains(this->contactemail->Description))
{
ContactEmail* con = ContactEmail::Get(this->contactemail->Description);
if(this->contactemail->ContactEmailID != con->ContactEmailID){
fill(con);
}
}
else if(contactemail->ContactEmailID != 0)
clear();
}
bool ContactEmailUI::save(){ 
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
contactemail->Description = description->text().trimmed();
}
if(email->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Email Can't be Empty! \n");
email->setObjectName("error");
email->style()->unpolish(email);
email->style()->polish(email);
email->update();
}
else { 
email->setObjectName("email");
email->style()->unpolish(email);
email->style()->polish(email);
email->update();
contactemail->Email = email->text().trimmed();
}
if(!contact->isHidden()) 
contactemail->ContactID = contact->getKey();
if(!errors) {
contactemail->save();
if(!errors){
ContactEmailIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ContactEmail"),errorString.trimmed());
return false; 
 }
}
void ContactEmailUI::cancel(){ 
ContactEmailIndexUI::ShowUI();
}
bool ContactEmailUI::updateModel(){ 
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
contactemail->Description = description->text().trimmed();
}
if(email->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Email Can't be Empty! \n");
email->setObjectName("error");
email->style()->unpolish(email);
email->style()->polish(email);
email->update();
}
else { 
email->setObjectName("email");
email->style()->unpolish(email);
email->style()->polish(email);
email->update();
contactemail->Email = email->text().trimmed();
}
if(contactemail->ContactID == 0) 
contactemail->ContactID = contact->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ContactEmail"),errorString.trimmed());
return false; 
 }
}
