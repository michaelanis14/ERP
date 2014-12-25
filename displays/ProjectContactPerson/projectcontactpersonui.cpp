/**************************************************************************
**   File: projectcontactpersonui.cpp
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectcontactpersonui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ProjectContactPersonUI::ProjectContactPersonUI(QWidget *parent) :ERPDisplay(parent)
{

projectcontactperson = new ProjectContactPerson();
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
block0Layout->addRow(QObject::tr("Project"),project);
contactperson = new ERPComboBox();
contactperson->addItems(ContactPerson::GetPairList());
block0Layout->addRow(QObject::tr("Contact Person"),contactperson);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectContactPersonUI::p_instance = 0;
void ProjectContactPersonUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ProjectContactPerson) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectContactPersonUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ProjectContactPersonUI*ProjectContactPersonUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectContactPersonUI*) p_instance; 
}
void ProjectContactPersonUI::fill(ProjectContactPerson* projectcontactperson){ 
clear();
this->projectcontactperson = projectcontactperson;
project->setIndexByKey(projectcontactperson->ProjectID);
contactperson->setIndexByKey(projectcontactperson->ContactPersonID);
} 
void ProjectContactPersonUI::clear(){ 
delete this->projectcontactperson;
this->projectcontactperson = new ProjectContactPerson();
} 
void ProjectContactPersonUI::selectProjectContactPerson(){ 
if(ProjectContactPerson::GetStringList().contains(QString::number(this->projectcontactperson->ProjectID)))
{
ProjectContactPerson* con = ProjectContactPerson::Get(QString::number(this->projectcontactperson->ProjectID));
if(this->projectcontactperson->ProjectContactPersonID != con->ProjectContactPersonID){
fill(con);
}
}
else if(projectcontactperson->ProjectContactPersonID != 0)
clear();
}
bool ProjectContactPersonUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!project->isHidden()) 
projectcontactperson->ProjectID = project->getKey();
if(!contactperson->isHidden()) 
projectcontactperson->ContactPersonID = contactperson->getKey();
if(!errors) {
projectcontactperson->save();
if(!errors){
ProjectContactPersonIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProjectContactPerson"),errorString.trimmed());
return false; 
 }
}
void ProjectContactPersonUI::cancel(){ 
ProjectContactPersonIndexUI::ShowUI();
}
bool ProjectContactPersonUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(projectcontactperson->ProjectID == 0) 
projectcontactperson->ProjectID = project->getKey();
if(projectcontactperson->ContactPersonID == 0) 
projectcontactperson->ContactPersonID = contactperson->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProjectContactPerson"),errorString.trimmed());
return false; 
 }
}
