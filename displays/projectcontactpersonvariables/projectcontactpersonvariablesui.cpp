/**************************************************************************
**   File: projectcontactpersonvariablesui.cpp
**   Created on: Wed Dec 10 20:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectcontactpersonvariablesui.h"
#include "../MainWindow.h"

projectcontactpersonvariablesUI::projectcontactpersonvariablesUI(QWidget *parent) :ERPDisplay(parent)
{

projectcontactpersonvariables = new projectcontactpersonvariables();
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
project = new ERPComboBox();
project->addItems(Project::GetPairList());
block0Layout->addRow("Project",project);
contactperson = new ERPComboBox();
contactperson->addItems(ContactPerson::GetPairList());
block0Layout->addRow("Contact Person",contactperson);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* projectcontactpersonvariablesUI::p_instance = 0;
void projectcontactpersonvariablesUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new projectcontactpersonvariablesUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
projectcontactpersonvariablesUI*projectcontactpersonvariablesUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (projectcontactpersonvariablesUI*) p_instance; 
}
void projectcontactpersonvariablesUI::fill(projectcontactpersonvariables* projectcontactpersonvariables){ 
clear();
this->projectcontactpersonvariables = projectcontactpersonvariables;
} 
void projectcontactpersonvariablesUI::clear(){ 
delete this->projectcontactpersonvariables;
this->projectcontactpersonvariables = new projectcontactpersonvariables();
} 
void projectcontactpersonvariablesUI::selectprojectcontactpersonvariables(){ 
if(projectcontactpersonvariables::GetStringList().contains(QString::number(this->projectcontactpersonvariables->ProjectID)))
{
projectcontactpersonvariables* con = projectcontactpersonvariables::Get(QString::number(this->projectcontactpersonvariables->ProjectID));
if(this->projectcontactpersonvariables->projectcontactpersonvariablesID != con->projectcontactpersonvariablesID){
fill(con);
}
}
else if(projectcontactpersonvariables->projectcontactpersonvariablesID != 0)
clear();
}
bool projectcontactpersonvariablesUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!project->isHidden()) 
projectcontactpersonvariables->ProjectID = project->getKey();
if(!contactperson->isHidden()) 
projectcontactpersonvariables->ContactPersonID = contactperson->getKey();
if(!errors) {
projectcontactpersonvariables->save();
if(!errors){
projectcontactpersonvariablesIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "projectcontactpersonvariables",errorString.trimmed());
return false; 
 }
}
void projectcontactpersonvariablesUI::cancel(){ 
projectcontactpersonvariablesIndexUI::ShowUI();
}
bool projectcontactpersonvariablesUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(projectcontactpersonvariables->ProjectID == 0) 
projectcontactpersonvariables->ProjectID = project->getKey();
if(projectcontactpersonvariables->ContactPersonID == 0) 
projectcontactpersonvariables->ContactPersonID = contactperson->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "projectcontactpersonvariables",errorString.trimmed());
return false; 
 }
}
