/**************************************************************************
**   File: contactpersontelephoneui.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersontelephoneui.h"
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
block0Layout->addRow("Description",description);
number = new QLineEdit();
number->setValidator( intValidator );
block0Layout->addRow("Number",number);
contactperson = new ERPComboBox();
contactperson->addItems(ContactPerson::GetHashList());
block0Layout->addRow("Contact Person",contactperson);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactPersonTelephoneUI::p_instance = 0;
void ContactPersonTelephoneUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ContactPersonTelephoneUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
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
} 
void ContactPersonTelephoneUI::clear(){ 
delete this->contactpersontelephone;
description->setText("");
number->setText("");
this->contactpersontelephone = new ContactPersonTelephone();
} 
void ContactPersonTelephoneUI::selectContactPersonTelephone(){ 
if(ContactPersonTelephone::GetStringList().contains(description->text()))
{
ContactPersonTelephone* con = ContactPersonTelephone::Get(description->text());
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
contactpersontelephone->Description = description->text().trimmed();
}
if(number->text().trimmed().isEmpty()){
errors = true;
errorString += "Number Can't be Empty! \n";
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
if(!errors) {
contactpersontelephone->save();
if(!errors){
ContactPersonTelephoneIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactPersonTelephone",errorString.trimmed());
return false; 
 }
}
void ContactPersonTelephoneUI::cancel(){ 
ContactPersonTelephoneIndexUI::ShowUI();
}
