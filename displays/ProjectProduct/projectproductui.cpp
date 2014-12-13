/**************************************************************************
**   File: projectproductui.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectproductui.h"
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
block0Layout->addRow("Project",project);
product = new ERPComboBox();
product->addItems(Product::GetPairList());
block0Layout->addRow("Product",product);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectProductUI::p_instance = 0;
void ProjectProductUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectProductUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ProjectProductUI*ProjectProductUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectProductUI*) p_instance; 
}
void ProjectProductUI::fill(ProjectProduct* projectproduct){ 
clear();
this->projectproduct = projectproduct;
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
else{ QMessageBox::warning(this, "ProjectProduct",errorString.trimmed());
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
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "ProjectProduct",errorString.trimmed());
return false; 
 }
}
