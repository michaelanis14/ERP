/**************************************************************************
**   File: userui.cpp
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "userui.h"
#include "../MainWindow.h"

UserUI::UserUI(QWidget *parent) :ERPDisplay(parent)
{

user = new User();
flowLayout = new FlowLayout(formPanel);
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
name = new QLineEdit();
QStringList* list = new QStringList(User::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectUser()));
block0Layout->addRow("Name",name);
username = new QLineEdit();
block0Layout->addRow("Username",username);
password = new QLineEdit();
block0Layout->addRow("Password",password);
lastlogin = new QLineEdit();
block0Layout->addRow("Last Login",lastlogin);
employee = new ERPComboBox();
employee->addItems(Employee::GetHashList());
block0Layout->addRow("Employee",employee);
active = new QCheckBox();
block0Layout->addRow("active",active);
lastip = new QLineEdit();
block0Layout->addRow("lastI P",lastip);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* UserUI::p_instance = 0;
void UserUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new UserUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
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
username->setText(user->Username);
password->setText(user->Password);
lastlogin->setText(user->LastLogin);
active->setChecked(user->active);
lastip->setText(user->lastIP);
} 
void UserUI::clear(){ 
delete this->user;
username->setText("");
password->setText("");
lastlogin->setText("");
active->setChecked(false);
lastip->setText("");
this->user = new User();
} 
void UserUI::selectUser(){ 
if(User::GetStringList().contains(name->text()))
{
User* con = User::Get(name->text());
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
user->Name = name->text().trimmed();
}
if(username->text().trimmed().isEmpty()){
errors = true;
errorString += "Username Can't be Empty! \n";
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
user->Username = username->text().trimmed();
}
if(password->text().trimmed().isEmpty()){
errors = true;
errorString += "Password Can't be Empty! \n";
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
if(lastlogin->text().trimmed().isEmpty()){
errors = true;
errorString += "Last Login Can't be Empty! \n";
lastlogin->setObjectName("error");
lastlogin->style()->unpolish(lastlogin);
lastlogin->style()->polish(lastlogin);
lastlogin->update();
}
else { 
lastlogin->setObjectName("lastlogin");
lastlogin->style()->unpolish(lastlogin);
lastlogin->style()->polish(lastlogin);
lastlogin->update();
user->LastLogin = lastlogin->text().trimmed();
}
if(user->EmployeeID == 0) 
user->EmployeeID = employee->getKey();
user->active = active->text().trimmed().toInt();
if(lastip->text().trimmed().isEmpty()){
errors = true;
errorString += "lastI P Can't be Empty! \n";
lastip->setObjectName("error");
lastip->style()->unpolish(lastip);
lastip->style()->polish(lastip);
lastip->update();
}
else { 
lastip->setObjectName("lastip");
lastip->style()->unpolish(lastip);
lastip->style()->polish(lastip);
lastip->update();
user->lastIP = lastip->text().trimmed();
}
if(!errors) {
user->save();
if(!errors){
UserIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "User",errorString.trimmed());
return false; 
 }
}
void UserUI::cancel(){ 
UserIndexUI::ShowUI();
}
