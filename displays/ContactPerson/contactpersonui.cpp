/**************************************************************************
**   File: contactpersonui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactpersonui.h"
#include "../MainWindow.h"

ContactPersonUI::ContactPersonUI(QWidget *parent) :ERPDisplay(parent)
{

contactperson = new ContactPerson();
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
contact = new ERPComboBox();
contact->addItems(Contact::GetHashList());
block0Layout->addRow("Contact",contact);
title = new QLineEdit();
block0Layout->addRow("Title",title);
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
number = new QLineEdit();
number->setValidator( intValidator );
block0Layout->addRow("Number",number);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block1Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveContactPersonTelephoneButtons = new AddRemoveButtons();
block1Layout->addRow("ContactPersonTelephones",addremoveContactPersonTelephoneButtons);
QObject::connect(addremoveContactPersonTelephoneButtons, SIGNAL(addPressed()), this, SLOT(addContactPersonTelephone()));

flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block2Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveContactPersonEmailButtons = new AddRemoveButtons();
block2Layout->addRow("ContactPersonEmails",addremoveContactPersonEmailButtons);
QObject::connect(addremoveContactPersonEmailButtons, SIGNAL(addPressed()), this, SLOT(addContactPersonEmail()));

flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block3Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveContactPersonFieldDataButtons = new AddRemoveButtons();
block3Layout->addRow("ContactPersonFieldDatas",addremoveContactPersonFieldDataButtons);
QObject::connect(addremoveContactPersonFieldDataButtons, SIGNAL(addPressed()), this, SLOT(addContactPersonFieldData()));

flowLayout->addWidget(block3Layout);

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
void ContactPersonUI::addContactPersonTelephone(){ 
ContactPersonTelephoneUI* contactpersontelephoneui = new ContactPersonTelephoneUI();
contactpersontelephoneui->block0Layout->removeRow(contactpersontelephoneui->contactperson);
contactpersontelephoneui->controllers->setFixedHeight(0);
ContactPersonTelephones.append(contactpersontelephoneui);
RemovebtnWidgets* rmcontactpersontelephone = new RemovebtnWidgets(0,contactpersontelephoneui);
QObject::connect(rmcontactpersontelephone, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactPersonTelephone(QWidget*)));
block1Layout->addRow("ContactPersonTelephone"+QString::number(ContactPersonTelephones.count()),rmcontactpersontelephone);
}
void ContactPersonUI::addContactPersonTelephone(ContactPersonTelephone* ContactPersonTelephone){ 
ContactPersonTelephoneUI* contactpersontelephoneui = new ContactPersonTelephoneUI();
contactpersontelephoneui->block0Layout->removeRow(contactpersontelephoneui->contactperson);
contactpersontelephoneui->controllers->setFixedHeight(0);
contactpersontelephoneui->fill(ContactPersonTelephone);
ContactPersonTelephones.append(contactpersontelephoneui);
RemovebtnWidgets* rmcontactpersontelephone = new RemovebtnWidgets(0,contactpersontelephoneui);
QObject::connect(rmcontactpersontelephone, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactPersonTelephone(QWidget*)));
block1Layout->addRow("ContactPersonTelephone"+QString::number(ContactPersonTelephones.count()),rmcontactpersontelephone);
}
void ContactPersonUI::removeContactPersonTelephone(QWidget* widget){ 
if(ContactPersonTelephones.count()  > 0){
ContactPersonTelephoneUI* contactpersontelephoneui = (ContactPersonTelephoneUI*) widget;
ContactPersonTelephones.removeOne(contactpersontelephoneui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block1Layout->removeRow(sender);
}
}
void ContactPersonUI::addContactPersonEmail(){ 
ContactPersonEmailUI* contactpersonemailui = new ContactPersonEmailUI();
contactpersonemailui->block0Layout->removeRow(contactpersonemailui->contactperson);
contactpersonemailui->controllers->setFixedHeight(0);
ContactPersonEmails.append(contactpersonemailui);
RemovebtnWidgets* rmcontactpersonemail = new RemovebtnWidgets(0,contactpersonemailui);
QObject::connect(rmcontactpersonemail, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactPersonEmail(QWidget*)));
block2Layout->addRow("ContactPersonEmail"+QString::number(ContactPersonEmails.count()),rmcontactpersonemail);
}
void ContactPersonUI::addContactPersonEmail(ContactPersonEmail* ContactPersonEmail){ 
ContactPersonEmailUI* contactpersonemailui = new ContactPersonEmailUI();
contactpersonemailui->block0Layout->removeRow(contactpersonemailui->contactperson);
contactpersonemailui->controllers->setFixedHeight(0);
contactpersonemailui->fill(ContactPersonEmail);
ContactPersonEmails.append(contactpersonemailui);
RemovebtnWidgets* rmcontactpersonemail = new RemovebtnWidgets(0,contactpersonemailui);
QObject::connect(rmcontactpersonemail, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactPersonEmail(QWidget*)));
block2Layout->addRow("ContactPersonEmail"+QString::number(ContactPersonEmails.count()),rmcontactpersonemail);
}
void ContactPersonUI::removeContactPersonEmail(QWidget* widget){ 
if(ContactPersonEmails.count()  > 0){
ContactPersonEmailUI* contactpersonemailui = (ContactPersonEmailUI*) widget;
ContactPersonEmails.removeOne(contactpersonemailui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block2Layout->removeRow(sender);
}
}
void ContactPersonUI::addContactPersonFieldData(){ 
ContactPersonFieldDataUI* contactpersonfielddataui = new ContactPersonFieldDataUI();
contactpersonfielddataui->block0Layout->removeRow(contactpersonfielddataui->contactperson);
contactpersonfielddataui->controllers->setFixedHeight(0);
ContactPersonFieldDatas.append(contactpersonfielddataui);
RemovebtnWidgets* rmcontactpersonfielddata = new RemovebtnWidgets(0,contactpersonfielddataui);
QObject::connect(rmcontactpersonfielddata, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactPersonFieldData(QWidget*)));
block3Layout->addRow("ContactPersonFieldData"+QString::number(ContactPersonFieldDatas.count()),rmcontactpersonfielddata);
}
void ContactPersonUI::addContactPersonFieldData(ContactPersonFieldData* ContactPersonFieldData){ 
ContactPersonFieldDataUI* contactpersonfielddataui = new ContactPersonFieldDataUI();
contactpersonfielddataui->block0Layout->removeRow(contactpersonfielddataui->contactperson);
contactpersonfielddataui->controllers->setFixedHeight(0);
contactpersonfielddataui->fill(ContactPersonFieldData);
ContactPersonFieldDatas.append(contactpersonfielddataui);
RemovebtnWidgets* rmcontactpersonfielddata = new RemovebtnWidgets(0,contactpersonfielddataui);
QObject::connect(rmcontactpersonfielddata, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactPersonFieldData(QWidget*)));
block3Layout->addRow("ContactPersonFieldData"+QString::number(ContactPersonFieldDatas.count()),rmcontactpersonfielddata);
}
void ContactPersonUI::removeContactPersonFieldData(QWidget* widget){ 
if(ContactPersonFieldDatas.count()  > 0){
ContactPersonFieldDataUI* contactpersonfielddataui = (ContactPersonFieldDataUI*) widget;
ContactPersonFieldDatas.removeOne(contactpersonfielddataui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block3Layout->removeRow(sender);
}
}
void ContactPersonUI::fill(ContactPerson* contactperson){ 
clear();
this->contactperson = contactperson;
title->setText(contactperson->Title);
name->setText(contactperson->Name);
lastname->setText(contactperson->LastName);
position->setText(contactperson->Position);
birthdate->setText(contactperson->Birthdate);
number->setText(QString::number(contactperson->Number));
foreach(ContactPersonTelephone* contactpersontelephone, contactperson->contactpersontelephones) {
addContactPersonTelephone(contactpersontelephone);
}
foreach(ContactPersonEmail* contactpersonemail, contactperson->contactpersonemails) {
addContactPersonEmail(contactpersonemail);
}
foreach(ContactPersonFieldData* contactpersonfielddata, contactperson->contactpersonfielddatas) {
addContactPersonFieldData(contactpersonfielddata);
}
} 
void ContactPersonUI::clear(){ 
delete this->contactperson;
title->setText("");
lastname->setText("");
position->setText("");
birthdate->setText("");
number->setText("");
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->contactperson = new ContactPerson();
} 
void ContactPersonUI::selectContactPerson(){ 
if(ContactPerson::GetStringList().contains(title->text()))
{
ContactPerson* con = ContactPerson::Get(title->text());
if(this->contactperson->ContactPersonID != con->ContactPersonID){
fill(con);
}
}
else if(contactperson->ContactPersonID != 0)
clear();
}
bool ContactPersonUI::save(){ 
bool errors = false;
QString errorString =  "";
if(contactperson->ContactID == 0) 
contactperson->ContactID = contact->getKey();
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += "Title Can't be Empty! \n";
title->setObjectName("error");
title->style()->unpolish(title);
title->style()->polish(title);
title->update();
}
else { 
title->setObjectName("title");
title->style()->unpolish(title);
title->style()->polish(title);
title->update();
contactperson->Title = title->text().trimmed();
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
contactperson->Number = number->text().trimmed().toInt();
}
for(int j = 0; j < ContactPersonTelephones.length(); j++){
ContactPersonTelephones.at(j)->description->setObjectName("description");
ContactPersonTelephones.at(j)->description->style()->unpolish(ContactPersonTelephones.at(j)->description);
ContactPersonTelephones.at(j)->description->style()->polish(ContactPersonTelephones.at(j)->description);
ContactPersonTelephones.at(j)->description->update();
for(int w = 0; w < ContactPersonTelephones.length(); w++){
if(ContactPersonTelephones.at(j) != ContactPersonTelephones.at(w))
if(ContactPersonTelephones.at(j)->description->text() == ContactPersonTelephones.at(w)->description->text()){
errors = true; 
 errorString += "ContactPersonTelephone has the same description \n";
ContactPersonTelephones.at(j)->description->setObjectName("error");
ContactPersonTelephones.at(j)->description->style()->unpolish(ContactPersonTelephones.at(j)->description);
ContactPersonTelephones.at(j)->description->style()->polish(ContactPersonTelephones.at(j)->description);
ContactPersonTelephones.at(j)->description->update();
}}}
for(int j = 0; j < ContactPersonEmails.length(); j++){
ContactPersonEmails.at(j)->description->setObjectName("description");
ContactPersonEmails.at(j)->description->style()->unpolish(ContactPersonEmails.at(j)->description);
ContactPersonEmails.at(j)->description->style()->polish(ContactPersonEmails.at(j)->description);
ContactPersonEmails.at(j)->description->update();
for(int w = 0; w < ContactPersonEmails.length(); w++){
if(ContactPersonEmails.at(j) != ContactPersonEmails.at(w))
if(ContactPersonEmails.at(j)->description->text() == ContactPersonEmails.at(w)->description->text()){
errors = true; 
 errorString += "ContactPersonEmail has the same description \n";
ContactPersonEmails.at(j)->description->setObjectName("error");
ContactPersonEmails.at(j)->description->style()->unpolish(ContactPersonEmails.at(j)->description);
ContactPersonEmails.at(j)->description->style()->polish(ContactPersonEmails.at(j)->description);
ContactPersonEmails.at(j)->description->update();
}}}
for(int j = 0; j < ContactPersonFieldDatas.length(); j++){
ContactPersonFieldDatas.at(j)->value->setObjectName("value");
ContactPersonFieldDatas.at(j)->value->style()->unpolish(ContactPersonFieldDatas.at(j)->value);
ContactPersonFieldDatas.at(j)->value->style()->polish(ContactPersonFieldDatas.at(j)->value);
ContactPersonFieldDatas.at(j)->value->update();
for(int w = 0; w < ContactPersonFieldDatas.length(); w++){
if(ContactPersonFieldDatas.at(j) != ContactPersonFieldDatas.at(w))
if(ContactPersonFieldDatas.at(j)->value->text() == ContactPersonFieldDatas.at(w)->value->text()){
errors = true; 
 errorString += "ContactPersonFieldData has the same value \n";
ContactPersonFieldDatas.at(j)->value->setObjectName("error");
ContactPersonFieldDatas.at(j)->value->style()->unpolish(ContactPersonFieldDatas.at(j)->value);
ContactPersonFieldDatas.at(j)->value->style()->polish(ContactPersonFieldDatas.at(j)->value);
ContactPersonFieldDatas.at(j)->value->update();
}}}
if(!errors) {
contactperson->save();
for(int i = 0; i < ContactPersonTelephones.length(); i++){
ContactPersonTelephones.at(i)->contactpersontelephone->ContactPersonID= contactperson->ContactPersonID;
if(!ContactPersonTelephones.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < contactperson->contactpersontelephones.length(); i++){
bool flag = false;
for(int j = 0; j < ContactPersonTelephones.length(); j++){
if(contactperson->contactpersontelephones.at(i)->ContactPersonTelephoneID == ContactPersonTelephones.at(j)->contactpersontelephone->ContactPersonTelephoneID){
flag = true;}}
if(!flag){
contactperson->contactpersontelephones.at(i)->remove();}
}
for(int i = 0; i < ContactPersonEmails.length(); i++){
ContactPersonEmails.at(i)->contactpersonemail->ContactPersonID= contactperson->ContactPersonID;
if(!ContactPersonEmails.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < contactperson->contactpersonemails.length(); i++){
bool flag = false;
for(int j = 0; j < ContactPersonEmails.length(); j++){
if(contactperson->contactpersonemails.at(i)->ContactPersonEmailID == ContactPersonEmails.at(j)->contactpersonemail->ContactPersonEmailID){
flag = true;}}
if(!flag){
contactperson->contactpersonemails.at(i)->remove();}
}
for(int i = 0; i < ContactPersonFieldDatas.length(); i++){
ContactPersonFieldDatas.at(i)->contactpersonfielddata->ContactPersonID= contactperson->ContactPersonID;
if(!ContactPersonFieldDatas.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < contactperson->contactpersonfielddatas.length(); i++){
bool flag = false;
for(int j = 0; j < ContactPersonFieldDatas.length(); j++){
if(contactperson->contactpersonfielddatas.at(i)->ContactPersonFieldDataID == ContactPersonFieldDatas.at(j)->contactpersonfielddata->ContactPersonFieldDataID){
flag = true;}}
if(!flag){
contactperson->contactpersonfielddatas.at(i)->remove();}
}
if(!errors){
ContactPersonIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ContactPerson",errorString.trimmed());
return false; 
 }
}
void ContactPersonUI::cancel(){ 
ContactPersonIndexUI::ShowUI();
}
