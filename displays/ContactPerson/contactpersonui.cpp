/**************************************************************************
**   File: contactpersonui.cpp
**   Created on: Sun Nov 23 14:11:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersonui.h"
#include "../MainWindow.h"

ContactPersonUI::ContactPersonUI(QWidget *parent) :ERPDisplay(parent)
{

contactperson = new ContactPerson();
flowLayout = new FlowLayout(formPanel);
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
clear();
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
delete this->contactperson;
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
fill(con);
}
}
else if(contactperson->ContactPersonID != 0)
clear();
}
void ContactPersonUI::save(){ 
bool errors = false;
QString errorString =  "";
if(personalsalut->text().trimmed().isEmpty()){
errors = true;
errorString += "Personal Salut Can't be Empty! \n";
personalsalut->setObjectName("error");
personalsalut->style()->unpolish(personalsalut);
personalsalut->style()->polish(personalsalut);
personalsalut->update();
}
else { 
personalsalut->setObjectName("personalsalut");
personalsalut->style()->unpolish(personalsalut);
personalsalut->style()->polish(personalsalut);
personalsalut->update();
contactperson->PersonalSalut = personalsalut->text().trimmed();
}
if(titleprefix->text().trimmed().isEmpty()){
errors = true;
errorString += "Title Prefix Can't be Empty! \n";
titleprefix->setObjectName("error");
titleprefix->style()->unpolish(titleprefix);
titleprefix->style()->polish(titleprefix);
titleprefix->update();
}
else { 
titleprefix->setObjectName("titleprefix");
titleprefix->style()->unpolish(titleprefix);
titleprefix->style()->polish(titleprefix);
titleprefix->update();
contactperson->TitlePrefix = titleprefix->text().trimmed();
}
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += "Name Can't be Empty! \n";
name->setObjectName("error");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
}
else { 
name->setObjectName("name");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
contactperson->Name = name->text().trimmed();
}
if(lastname->text().trimmed().isEmpty()){
errors = true;
errorString += "Last Name Can't be Empty! \n";
lastname->setObjectName("error");
lastname->style()->unpolish(lastname);
lastname->style()->polish(lastname);
lastname->update();
}
else { 
lastname->setObjectName("lastname");
lastname->style()->unpolish(lastname);
lastname->style()->polish(lastname);
lastname->update();
contactperson->LastName = lastname->text().trimmed();
}
if(position->text().trimmed().isEmpty()){
errors = true;
errorString += "Position Can't be Empty! \n";
position->setObjectName("error");
position->style()->unpolish(position);
position->style()->polish(position);
position->update();
}
else { 
position->setObjectName("position");
position->style()->unpolish(position);
position->style()->polish(position);
position->update();
contactperson->Position = position->text().trimmed();
}
if(birthdate->text().trimmed().isEmpty()){
errors = true;
errorString += "Birthdate Can't be Empty! \n";
birthdate->setObjectName("error");
birthdate->style()->unpolish(birthdate);
birthdate->style()->polish(birthdate);
birthdate->update();
}
else { 
birthdate->setObjectName("birthdate");
birthdate->style()->unpolish(birthdate);
birthdate->style()->polish(birthdate);
birthdate->update();
contactperson->Birthdate = birthdate->text().trimmed();
}
if(contactpersonenumber->text().trimmed().isEmpty()){
errors = true;
errorString += "Contact Persone Number Can't be Empty! \n";
contactpersonenumber->setObjectName("error");
contactpersonenumber->style()->unpolish(contactpersonenumber);
contactpersonenumber->style()->polish(contactpersonenumber);
contactpersonenumber->update();
}
else { 
contactpersonenumber->setObjectName("contactpersonenumber");
contactpersonenumber->style()->unpolish(contactpersonenumber);
contactpersonenumber->style()->polish(contactpersonenumber);
contactpersonenumber->update();
contactperson->ContactPersoneNumber = contactpersonenumber->text().trimmed().toInt();
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
contactperson->Email = email->text().trimmed();
}
if(phonenum->text().trimmed().isEmpty()){
errors = true;
errorString += "Phone Num Can't be Empty! \n";
phonenum->setObjectName("error");
phonenum->style()->unpolish(phonenum);
phonenum->style()->polish(phonenum);
phonenum->update();
}
else { 
phonenum->setObjectName("phonenum");
phonenum->style()->unpolish(phonenum);
phonenum->style()->polish(phonenum);
phonenum->update();
contactperson->PhoneNum = phonenum->text().trimmed();
}
if(phonenum2->text().trimmed().isEmpty()){
errors = true;
errorString += "Phone Num2 Can't be Empty! \n";
phonenum2->setObjectName("error");
phonenum2->style()->unpolish(phonenum2);
phonenum2->style()->polish(phonenum2);
phonenum2->update();
}
else { 
phonenum2->setObjectName("phonenum2");
phonenum2->style()->unpolish(phonenum2);
phonenum2->style()->polish(phonenum2);
phonenum2->update();
contactperson->PhoneNum2 = phonenum2->text().trimmed();
}
if(mobile->text().trimmed().isEmpty()){
errors = true;
errorString += "Mobile Can't be Empty! \n";
mobile->setObjectName("error");
mobile->style()->unpolish(mobile);
mobile->style()->polish(mobile);
mobile->update();
}
else { 
mobile->setObjectName("mobile");
mobile->style()->unpolish(mobile);
mobile->style()->polish(mobile);
mobile->update();
contactperson->Mobile = mobile->text().trimmed();
}
if(fax->text().trimmed().isEmpty()){
errors = true;
errorString += "Fax Can't be Empty! \n";
fax->setObjectName("error");
fax->style()->unpolish(fax);
fax->style()->polish(fax);
fax->update();
}
else { 
fax->setObjectName("fax");
fax->style()->unpolish(fax);
fax->style()->polish(fax);
fax->update();
contactperson->Fax = fax->text().trimmed();
}
contactperson->active = active->text().trimmed().toInt();
if(contactperson->ContactID == 0) 
contactperson->ContactID = contact->getKey();
if(!errors) {
contactperson->save();
ContactPersonIndexUI::ShowUI();
}
else{ QByteArray byteArray = errorString.toUtf8();	const char* cString = byteArray.constData(); 
 QMessageBox::warning(this, tr("My Application"), tr(cString)); 
 }
}
void ContactPersonUI::cancel(){ 
ContactPersonIndexUI::ShowUI();
}
