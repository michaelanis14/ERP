/**************************************************************************
**   File: employeeui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "employeeui.h"
#include "../MainWindow.h"

EmployeeUI::EmployeeUI(QWidget *parent) :ERPDisplay(parent)
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
QStringList* list = new QStringList(Employee::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectEmployee()));
block0Layout->addRow("Name",name);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* EmployeeUI::p_instance = 0;
void EmployeeUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new EmployeeUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
EmployeeUI*EmployeeUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (EmployeeUI*) p_instance; 
}
void EmployeeUI::fill(Employee* employee){ 
this->employee = employee;
name->setText(employee->Name);
} 
void EmployeeUI::clear(){ 
this->employee = new Employee();
} 
void EmployeeUI::selectEmployee(){ 
if(Employee::GetStringList().contains(name->text()))
{
Employee* con = Employee::Get(name->text());
if(this->employee->EmployeeID != con->EmployeeID){
this->employee = con;
fill(this->employee);
}
}
else if(employee->EmployeeID != 0)
clear();
}
void EmployeeUI::save(){ 
employee->Name = name->text();
employee->save();
EmployeeIndexUI::ShowUI();
}
void EmployeeUI::cancel(){ 
EmployeeIndexUI::ShowUI();
}
