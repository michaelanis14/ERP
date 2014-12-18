/**************************************************************************
**   File: taskui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "taskui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

TaskUI::TaskUI(QWidget *parent) :ERPDisplay(parent)
{

task = new Task();
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
note = new QLineEdit();
block0Layout->addRow(QObject::tr("Note"),note);
project = new ERPComboBox();
project->addItems(Project::GetPairList());
block0Layout->addRow(QObject::tr("Project"),project);
contactperson = new ERPComboBox();
contactperson->addItems(ContactPerson::GetPairList());
block0Layout->addRow(QObject::tr("Contact Person"),contactperson);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* TaskUI::p_instance = 0;
void TaskUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Task) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new TaskUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
TaskUI*TaskUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (TaskUI*) p_instance; 
}
void TaskUI::fill(Task* task){ 
clear();
this->task = task;
note->setText(task->Note);
project->setIndexByKey(task->ProjectID);
contactperson->setIndexByKey(task->ContactPersonID);
} 
void TaskUI::clear(){ 
delete this->task;
note->setText("");
this->task = new Task();
} 
void TaskUI::selectTask(){ 
if(Task::GetStringList().contains(this->task->Note))
{
Task* con = Task::Get(this->task->Note);
if(this->task->TaskID != con->TaskID){
fill(con);
}
}
else if(task->TaskID != 0)
clear();
}
bool TaskUI::save(){ 
bool errors = false;
QString errorString =  "";
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Note Can't be Empty! \n");
note->setObjectName("error");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
}
else { 
note->setObjectName("note");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
task->Note = note->text().trimmed();
}
if(!project->isHidden()) 
task->ProjectID = project->getKey();
if(!contactperson->isHidden()) 
task->ContactPersonID = contactperson->getKey();
if(!errors) {
task->save();
if(!errors){
TaskIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("Task"),errorString.trimmed());
return false; 
 }
}
void TaskUI::cancel(){ 
TaskIndexUI::ShowUI();
}
bool TaskUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Note Can't be Empty! \n");
note->setObjectName("error");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
}
else { 
note->setObjectName("note");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
task->Note = note->text().trimmed();
}
if(task->ProjectID == 0) 
task->ProjectID = project->getKey();
if(task->ContactPersonID == 0) 
task->ContactPersonID = contactperson->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Task"),errorString.trimmed());
return false; 
 }
}
