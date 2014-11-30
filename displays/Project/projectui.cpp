/**************************************************************************
**   File: projectui.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectui.h"
#include "../MainWindow.h"

ProjectUI::ProjectUI(QWidget *parent) :ERPDisplay(parent)
{

project = new Project();
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
title = new QLineEdit();
block0Layout->addRow("Title",title);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectUI::p_instance = 0;
void ProjectUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new ProjectUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
ProjectUI*ProjectUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectUI*) p_instance; 
}
void ProjectUI::fill(Project* project){ 
clear();
this->project = project;
title->setText(project->Title);
} 
void ProjectUI::clear(){ 
delete this->project;
title->setText("");
this->project = new Project();
} 
void ProjectUI::selectProject(){ 
if(Project::GetStringList().contains(title->text()))
{
Project* con = Project::Get(title->text());
if(this->project->ProjectID != con->ProjectID){
fill(con);
}
}
else if(project->ProjectID != 0)
clear();
}
bool ProjectUI::save(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += "Title Can't be Empty! \n";
title->setObjectName("error");
title->style()->unpolish(title);
title->style()->polish(title);
title->update();
}
else { 
title->setObjectName("title");
title->style()->unpolish(title);
title->style()->polish(title);
title->update();
project->Title = title->text().trimmed();
}
if(!errors) {
project->save();
if(!errors){
ProjectIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Project",errorString.trimmed());
return false; 
 }
}
void ProjectUI::cancel(){ 
ProjectIndexUI::ShowUI();
}
