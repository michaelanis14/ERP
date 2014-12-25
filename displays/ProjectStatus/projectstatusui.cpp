/**************************************************************************
**   File: projectstatusui.cpp
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectstatusui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ProjectStatusUI::ProjectStatusUI(QWidget *parent) :ERPDisplay(parent)
{

projectstatus = new ProjectStatus();
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
description = new QLineEdit();
block0Layout->addRow(QObject::tr("Description"),description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectStatusUI::p_instance = 0;
void ProjectStatusUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ProjectStatus) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectStatusUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ProjectStatusUI*ProjectStatusUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectStatusUI*) p_instance; 
}
void ProjectStatusUI::fill(ProjectStatus* projectstatus){ 
clear();
this->projectstatus = projectstatus;
description->setText(projectstatus->Description);
} 
void ProjectStatusUI::clear(){ 
delete this->projectstatus;
description->setText("");
this->projectstatus = new ProjectStatus();
} 
void ProjectStatusUI::selectProjectStatus(){ 
if(ProjectStatus::GetStringList().contains(this->projectstatus->Description))
{
ProjectStatus* con = ProjectStatus::Get(this->projectstatus->Description);
if(this->projectstatus->ProjectStatusID != con->ProjectStatusID){
fill(con);
}
}
else if(projectstatus->ProjectStatusID != 0)
clear();
}
bool ProjectStatusUI::save(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Description Can't be Empty! \n");
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else { 
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
projectstatus->Description = description->text().trimmed();
}
if(!errors) {
projectstatus->save();
if(!errors){
ProjectStatusIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProjectStatus"),errorString.trimmed());
return false; 
 }
}
void ProjectStatusUI::cancel(){ 
ProjectStatusIndexUI::ShowUI();
}
bool ProjectStatusUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Description Can't be Empty! \n");
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else { 
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
projectstatus->Description = description->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProjectStatus"),errorString.trimmed());
return false; 
 }
}
