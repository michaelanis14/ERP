/**************************************************************************
**   File: contactpersonui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersonui.h"
#include "../MainWindow.h"

ContactPersonUI::ContactPersonUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
ERPFormBlock * blockSaveCancel = new ERPFormBlock;
 QWidget* addremove = new QWidget();
 QHBoxLayout* addRemovelayout = new QHBoxLayout(addremove);
 addRemovelayout->setContentsMargins(0,0,0,0);
 QPushButton* save = new QPushButton("Save");
 QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
 save->setObjectName("save");
 QPushButton* cancel = new QPushButton("Cancel");
 cancel->setObjectName("cancel");
 QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
 QPushButton* clear = new QPushButton("Clear");
 QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
 clear->setObjectName("clear");
 addRemovelayout->addStretch(1);
 addRemovelayout->addWidget(save,0,Qt::AlignCenter);
 addRemovelayout->addStretch(0);
 addRemovelayout->addWidget(clear,0,Qt::AlignCenter);
 addRemovelayout->addWidget(cancel,0,Qt::AlignCenter);
 addRemovelayout->addStretch(1);
 blockSaveCancel->addRow("",addremove);
 flowLayout->addWidget(blockSaveCancel);
block0Layout = new ERPFormBlock;
personalsalut = new QLineEdit();
block0Layout->addRow("Personal Salut",personalsalut);
titleprefix = new QLineEdit();
block0Layout->addRow("Title Prefix",titleprefix);
name = new QLineEdit();
QStringList* list = new QStringList(ContactPerson::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectContactPerson()));
block0Layout->addRow("Name",name);
lastname = new QLineEdit();
block0Layout->addRow("Last Name",lastname);
position = new QLineEdit();
block0Layout->addRow("Position",position);
birthdate = new QLineEdit();
block0Layout->addRow("Birthdate",birthdate);
contactpersonenumber = new QLineEdit();
contactpersonenumber->setValidator( intValidator );
block0Layout->addRow("Contact Persone Number",contactpersonenumber);
email = new QLineEdit();
block0Layout->addRow("Email",email);
phonenum = new QLineEdit();
block0Layout->addRow("Phone Num",phonenum);
phonenum2 = new QLineEdit();
block0Layout->addRow("Phone Num2",phonenum2);
mobile = new QLineEdit();
block0Layout->addRow("Mobile",mobile);
fax = new QLineEdit();
block0Layout->addRow("Fax",fax);
active = new QCheckBox();
block0Layout->addRow("active",active);
contact = new ERPComboBox();
contact->addItems(Contact::GetHashList());
block0Layout->addRow("Contact",contact);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ContactPersonUI::p_instance = 0;
void ContactPersonUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ContactPersonUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
ContactPersonUI*ContactPersonUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactPersonUI*) p_instance; 
}
void ContactPersonUI::fill(ContactPerson* contactperson){ 
this->contactperson = contactperson;
personalsalut->setText(contactperson->PersonalSalut);
titleprefix->setText(contactperson->TitlePrefix);
name->setText(contactperson->Name);
lastname->setText(contactperson->LastName);
position->setText(contactperson->Position);
birthdate->setText(contactperson->Birthdate);
contactpersonenumber->setText(QString::number(contactperson->ContactPersoneNumber));
email->setText(contactperson->Email);
phonenum->setText(contactperson->PhoneNum);
phonenum2->setText(contactperson->PhoneNum2);
mobile->setText(contactperson->Mobile);
fax->setText(contactperson->Fax);
active->setChecked(contactperson->active);
} 
void ContactPersonUI::clear(){ 
personalsalut->setText("");
titleprefix->setText("");
lastname->setText("");
position->setText("");
birthdate->setText("");
contactpersonenumber->setText("");
email->setText("");
phonenum->setText("");
phonenum2->setText("");
mobile->setText("");
fax->setText("");
active->setChecked(false);
this->contactperson = new ContactPerson();
} 
void ContactPersonUI::selectContactPerson(){ 
if(ContactPerson::GetStringList().contains(name->text()))
{
ContactPerson* con = ContactPerson::Get(name->text());
if(this->contactperson->ContactPersonID != con->ContactPersonID){
this->contactperson = con;
fill(this->contactperson);
}
}
else if(contactperson->ContactPersonID != 0)
clear();
}
void ContactPersonUI::save(){ 
contactperson->PersonalSalut = personalsalut->text();
contactperson->TitlePrefix = titleprefix->text();
contactperson->Name = name->text();
contactperson->LastName = lastname->text();
contactperson->Position = position->text();
contactperson->Birthdate = birthdate->text();
contactperson->ContactPersoneNumber = contactpersonenumber->text().toInt();
contactperson->Email = email->text();
contactperson->PhoneNum = phonenum->text();
contactperson->PhoneNum2 = phonenum2->text();
contactperson->Mobile = mobile->text();
contactperson->Fax = fax->text();
contactperson->active = active->text().toInt();
if(contactperson->ContactID == 0) 
contactperson->ContactID = contact->getKey();
contactperson->save();
ContactPersonIndexUI::ShowUI();
}
void ContactPersonUI::cancel(){ 
ContactPersonIndexUI::ShowUI();
}
