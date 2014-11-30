/**************************************************************************
**   File: employeeui.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "employeeui.h"
#include "../MainWindow.h"

EmployeeUI::EmployeeUI(QWidget *parent) :ERPDisplay(parent)
{

employee = new Employee();
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
clear();
this->employee = employee;
name->setText(employee->Name);
} 
void EmployeeUI::clear(){ 
delete this->employee;
this->employee = new Employee();
} 
void EmployeeUI::selectEmployee(){ 
if(Employee::GetStringList().contains(name->text()))
{
Employee* con = Employee::Get(name->text());
if(this->employee->EmployeeID != con->EmployeeID){
fill(con);
}
}
else if(employee->EmployeeID != 0)
clear();
}
bool EmployeeUI::save(){ 
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
employee->Name = name->text().trimmed();
}
if(!errors) {
employee->save();
if(!errors){
EmployeeIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Employee",errorString.trimmed());
return false; 
 }
}
void EmployeeUI::cancel(){ 
EmployeeIndexUI::ShowUI();
}
