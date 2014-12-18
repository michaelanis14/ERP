/**************************************************************************
**   File: userui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "userui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

UserUI::UserUI(QWidget *parent) :ERPDisplay(parent)
{

user = new User();
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
name = new QLineEdit();
QStringList* list = new QStringList(User::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectUser()));
block0Layout->addRow(QObject::tr("Name"),name);
username = new QLineEdit();
block0Layout->addRow(QObject::tr("User Name"),username);
password = new QLineEdit();
block0Layout->addRow(QObject::tr("Password"),password);
language = new ERPComboBox();
language->addItems(Language::GetPairList());
block0Layout->addRow(QObject::tr("Language"),language);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* UserUI::p_instance = 0;
void UserUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Admin) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new UserUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
UserUI*UserUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (UserUI*) p_instance; 
}
void UserUI::fill(User* user){ 
clear();
this->user = user;
name->setText(user->Name);
username->setText(user->UserName);
password->setText(user->Password);
language->setIndexByKey(user->LanguageID);
contact->setIndexByKey(user->ContactID);
} 
void UserUI::clear(){ 
delete this->user;
username->setText("");
password->setText("");
this->user = new User();
} 
void UserUI::selectUser(){ 
if(User::GetStringList().contains(this->user->Name))
{
User* con = User::Get(this->user->Name);
if(this->user->UserID != con->UserID){
fill(con);
}
}
else if(user->UserID != 0)
clear();
}
bool UserUI::save(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
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
user->Name = name->text().trimmed();
}
if(username->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("User Name Can't be Empty! \n");
username->setObjectName("error");
username->style()->unpolish(username);
username->style()->polish(username);
username->update();
}
else { 
username->setObjectName("username");
username->style()->unpolish(username);
username->style()->polish(username);
username->update();
user->UserName = username->text().trimmed();
}
if(password->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Password Can't be Empty! \n");
password->setObjectName("error");
password->style()->unpolish(password);
password->style()->polish(password);
password->update();
}
else { 
password->setObjectName("password");
password->style()->unpolish(password);
password->style()->polish(password);
password->update();
user->Password = password->text().trimmed();
}
if(!language->isHidden()) 
user->LanguageID = language->getKey();
if(!contact->isHidden()) 
user->ContactID = contact->getKey();
if(!errors) {
user->save();
if(!errors){
UserIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("User"),errorString.trimmed());
return false; 
 }
}
void UserUI::cancel(){ 
UserIndexUI::ShowUI();
}
bool UserUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
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
user->Name = name->text().trimmed();
}
if(username->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("User Name Can't be Empty! \n");
username->setObjectName("error");
username->style()->unpolish(username);
username->style()->polish(username);
username->update();
}
else { 
username->setObjectName("username");
username->style()->unpolish(username);
username->style()->polish(username);
username->update();
user->UserName = username->text().trimmed();
}
if(password->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Password Can't be Empty! \n");
password->setObjectName("error");
password->style()->unpolish(password);
password->style()->polish(password);
password->update();
}
else { 
password->setObjectName("password");
password->style()->unpolish(password);
password->style()->polish(password);
password->update();
user->Password = password->text().trimmed();
}
if(user->LanguageID == 0) 
user->LanguageID = language->getKey();
if(user->ContactID == 0) 
user->ContactID = contact->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("User"),errorString.trimmed());
return false; 
 }
}
