/**************************************************************************
**   File: contactemailui.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactemailui.h"
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
block0Layout->addRow("Description",description);
email = new QLineEdit();
block0Layout->addRow("Email",email);
contact = new ERPComboBox();
contact->addItems(Contact::GetHashList());
block0Layout->addRow("Contact",contact);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactEmailUI::p_instance = 0;
void ContactEmailUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ContactEmailUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
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
} 
void ContactEmailUI::clear(){ 
delete this->contactemail;
description->setText("");
email->setText("");
this->contactemail = new ContactEmail();
} 
void ContactEmailUI::selectContactEmail(){ 
if(ContactEmail::GetStringList().contains(description->text()))
{
ContactEmail* con = ContactEmail::Get(description->text());
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
contactemail->Description = description->text().trimmed();
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
contactemail->Email = email->text().trimmed();
}
if(contactemail->ContactID == 0) 
contactemail->ContactID = contact->getKey();
if(!errors) {
contactemail->save();
if(!errors){
ContactEmailIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactEmail",errorString.trimmed());
return false; 
 }
}
void ContactEmailUI::cancel(){ 
ContactEmailIndexUI::ShowUI();
}
