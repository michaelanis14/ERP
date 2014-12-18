/**************************************************************************
**   File: projectproductui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectproductui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

ProjectProductUI::ProjectProductUI(QWidget *parent) :ERPDisplay(parent)
{

projectproduct = new ProjectProduct();
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
product = new ERPComboBox();
product->addItems(Product::GetPairList());
block0Layout->addRow(QObject::tr("Product"),product);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectProductUI::p_instance = 0;
void ProjectProductUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ProjectProduct) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectProductUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ProjectProductUI*ProjectProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectProductUI*) p_instance; 
}
void ProjectProductUI::fill(ProjectProduct* projectproduct){ 
clear();
this->projectproduct = projectproduct;
project->setIndexByKey(projectproduct->ProjectID);
product->setIndexByKey(projectproduct->ProductID);
} 
void ProjectProductUI::clear(){ 
delete this->projectproduct;
this->projectproduct = new ProjectProduct();
} 
void ProjectProductUI::selectProjectProduct(){ 
if(ProjectProduct::GetStringList().contains(QString::number(this->projectproduct->ProjectID)))
{
ProjectProduct* con = ProjectProduct::Get(QString::number(this->projectproduct->ProjectID));
if(this->projectproduct->ProjectProductID != con->ProjectProductID){
fill(con);
}
}
else if(projectproduct->ProjectProductID != 0)
clear();
}
bool ProjectProductUI::save(){ 
bool errors = false;
QString errorString =  "";
if(!project->isHidden()) 
projectproduct->ProjectID = project->getKey();
if(!product->isHidden()) 
projectproduct->ProductID = product->getKey();
if(!errors) {
projectproduct->save();
if(!errors){
ProjectProductIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProjectProduct"),errorString.trimmed());
return false; 
 }
}
void ProjectProductUI::cancel(){ 
ProjectProductIndexUI::ShowUI();
}
bool ProjectProductUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(projectproduct->ProjectID == 0) 
projectproduct->ProjectID = project->getKey();
if(projectproduct->ProductID == 0) 
projectproduct->ProductID = product->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProjectProduct"),errorString.trimmed());
return false; 
 }
}
