/**************************************************************************
**   File: contactpersonemailui.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersonemailui.h"
#include "../MainWindow.h"

ContactPersonEmailUI::ContactPersonEmailUI(QWidget *parent) :ERPDisplay(parent)
{

contactpersonemail = new ContactPersonEmail();
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
email = new QLineEdit();
block0Layout->addRow("Email",email);
contactperson = new ERPComboBox();
contactperson->addItems(ContactPerson::GetHashList());
block0Layout->addRow("Contact Person",contactperson);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactPersonEmailUI::p_instance = 0;
void ContactPersonEmailUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactPersonEmailUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactPersonEmailUI*ContactPersonEmailUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactPersonEmailUI*) p_instance; 
}
void ContactPersonEmailUI::fill(ContactPersonEmail* contactpersonemail){ 
clear();
this->contactpersonemail = contactpersonemail;
description->setText(contactpersonemail->Description);
email->setText(contactpersonemail->Email);
} 
void ContactPersonEmailUI::clear(){ 
delete this->contactpersonemail;
description->setText("");
email->setText("");
this->contactpersonemail = new ContactPersonEmail();
} 
void ContactPersonEmailUI::selectContactPersonEmail(){ 
if(ContactPersonEmail::GetStringList().contains(description->text()))
{
ContactPersonEmail* con = ContactPersonEmail::Get(description->text());
if(this->contactpersonemail->ContactPersonEmailID != con->ContactPersonEmailID){
fill(con);
}
}
else if(contactpersonemail->ContactPersonEmailID != 0)
clear();
}
bool ContactPersonEmailUI::save(){ 
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
contactpersonemail->Description = description->text().trimmed();
}
if(email->text().trimmed().isEmpty()){
errors = true;
errorString += "Email Can't be Empty! \n";
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
contactpersonemail->Email = email->text().trimmed();
}
if(contactpersonemail->ContactPersonID == 0) 
contactpersonemail->ContactPersonID = contactperson->getKey();
if(!errors) {
contactpersonemail->save();
if(!errors){
ContactPersonEmailIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactPersonEmail",errorString.trimmed());
return false; 
 }
}
void ContactPersonEmailUI::cancel(){ 
ContactPersonEmailIndexUI::ShowUI();
}
