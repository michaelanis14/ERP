/**************************************************************************
**   File: userui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "userui.h"
#include "../MainWindow.h"

UserUI::UserUI(QWidget *parent) :ERPDisplay(parent)
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
this->user = user;
name->setText(user->Name);
username->setText(user->Username);
password->setText(user->Password);
lastlogin->setText(user->LastLogin);
active->setChecked(user->active);
lastip->setText(user->lastIP);
} 
void UserUI::clear(){ 
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
this->user = con;
fill(this->user);
}
}
else if(user->UserID != 0)
clear();
}
void UserUI::save(){ 
user->Name = name->text();
user->Username = username->text();
user->Password = password->text();
user->LastLogin = lastlogin->text();
if(user->EmployeeID == 0) 
user->EmployeeID = employee->getKey();
user->active = active->text().toInt();
user->lastIP = lastip->text();
user->save();
UserIndexUI::ShowUI();
}
void UserUI::cancel(){ 
UserIndexUI::ShowUI();
}
