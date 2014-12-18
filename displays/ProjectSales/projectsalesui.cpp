/**************************************************************************
**   File: projectsalesui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectsalesui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ProjectSalesUI::ProjectSalesUI(QWidget *parent) :ERPDisplay(parent)
{

projectsales = new ProjectSales();
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
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectSalesUI::p_instance = 0;
void ProjectSalesUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ProjectSales) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectSalesUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ProjectSalesUI*ProjectSalesUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectSalesUI*) p_instance; 
}
void ProjectSalesUI::fill(ProjectSales* projectsales){ 
clear();
this->projectsales = projectsales;
project->setIndexByKey(projectsales->ProjectID);
contact->setIndexByKey(projectsales->ContactID);
} 
void ProjectSalesUI::clear(){ 
delete this->projectsales;
this->projectsales = new ProjectSales();
} 
void ProjectSalesUI::selectProjectSales(){ 
if(ProjectSales::GetStringList().contains(QString::number(this->projectsales->ProjectID)))
{
ProjectSales* con = ProjectSales::Get(QString::number(this->projectsales->ProjectID));
if(this->projectsales->ProjectSalesID != con->ProjectSalesID){
fill(con);
}
}
else if(projectsales->ProjectSalesID != 0)
clear();
}
bool ProjectSalesUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!project->isHidden()) 
projectsales->ProjectID = project->getKey();
if(!contact->isHidden()) 
projectsales->ContactID = contact->getKey();
if(!errors) {
projectsales->save();
if(!errors){
ProjectSalesIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProjectSales"),errorString.trimmed());
return false; 
 }
}
void ProjectSalesUI::cancel(){ 
ProjectSalesIndexUI::ShowUI();
}
bool ProjectSalesUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(projectsales->ProjectID == 0) 
projectsales->ProjectID = project->getKey();
if(projectsales->ContactID == 0) 
projectsales->ContactID = contact->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProjectSales"),errorString.trimmed());
return false; 
 }
}
