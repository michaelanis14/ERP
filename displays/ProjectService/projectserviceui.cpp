/**************************************************************************
**   File: projectserviceui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectserviceui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ProjectServiceUI::ProjectServiceUI(QWidget *parent) :ERPDisplay(parent)
{

projectservice = new ProjectService();
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
service = new ERPComboBox();
service->addItems(Service::GetPairList());
block0Layout->addRow(QObject::tr("Service"),service);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectServiceUI::p_instance = 0;
void ProjectServiceUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ProjectService) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectServiceUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ProjectServiceUI*ProjectServiceUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectServiceUI*) p_instance; 
}
void ProjectServiceUI::fill(ProjectService* projectservice){ 
clear();
this->projectservice = projectservice;
project->setIndexByKey(projectservice->ProjectID);
service->setIndexByKey(projectservice->ServiceID);
} 
void ProjectServiceUI::clear(){ 
delete this->projectservice;
this->projectservice = new ProjectService();
} 
void ProjectServiceUI::selectProjectService(){ 
if(ProjectService::GetStringList().contains(QString::number(this->projectservice->ProjectID)))
{
ProjectService* con = ProjectService::Get(QString::number(this->projectservice->ProjectID));
if(this->projectservice->ProjectServiceID != con->ProjectServiceID){
fill(con);
}
}
else if(projectservice->ProjectServiceID != 0)
clear();
}
bool ProjectServiceUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!project->isHidden()) 
projectservice->ProjectID = project->getKey();
if(!service->isHidden()) 
projectservice->ServiceID = service->getKey();
if(!errors) {
projectservice->save();
if(!errors){
ProjectServiceIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProjectService"),errorString.trimmed());
return false; 
 }
}
void ProjectServiceUI::cancel(){ 
ProjectServiceIndexUI::ShowUI();
}
bool ProjectServiceUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(projectservice->ProjectID == 0) 
projectservice->ProjectID = project->getKey();
if(projectservice->ServiceID == 0) 
projectservice->ServiceID = service->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProjectService"),errorString.trimmed());
return false; 
 }
}
