/**************************************************************************
**   File: projectui.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectui.h"
#include "../MainWindow.h"

ProjectUI::ProjectUI(QWidget *parent) :ERPDisplay(parent)
{

project = new Project();
flowLayout = new FlowLayout(formPanel);
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
projectstatus = new ERPComboBox();
projectstatus->addItems(ProjectStatus::GetPairList());
block0Layout->addRow("Project Status",projectstatus);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow("Contact",contact);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block1Layout->setMinimumWidth(330);
startdate = new QDateEdit(QDate::currentDate());
startdate->setCalendarPopup(true);
startdate->setDisplayFormat("ddd dd/MM/yyyy");
block1Layout->addRow("Start Date",startdate);
enddate = new QDateEdit(QDate::currentDate());
enddate->setCalendarPopup(true);
enddate->setDisplayFormat("ddd dd/MM/yyyy");
block1Layout->addRow("End Date",enddate);
willbeinvoiced = new QCheckBox();
block1Layout->addRow("Will Be Invoiced",willbeinvoiced);
flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block2Layout->setMinimumWidth(330);
note = new QLineEdit();
block2Layout->addRow("Note",note);
flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block3Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveTaskButtons = new AddRemoveButtons();
block3Layout->addRow("Tasks",addremoveTaskButtons);
QObject::connect(addremoveTaskButtons, SIGNAL(addPressed()), this, SLOT(addTask()));

flowLayout->addWidget(block3Layout);

block4Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block4Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveProjectContactPersonButtons = new AddRemoveButtons();
block4Layout->addRow("ProjectContactPersons",addremoveProjectContactPersonButtons);
QObject::connect(addremoveProjectContactPersonButtons, SIGNAL(addPressed()), this, SLOT(addProjectContactPerson()));

flowLayout->addWidget(block4Layout);

block5Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block5Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveProjectProductButtons = new AddRemoveButtons();
block5Layout->addRow("ProjectProducts",addremoveProjectProductButtons);
QObject::connect(addremoveProjectProductButtons, SIGNAL(addPressed()), this, SLOT(addProjectProduct()));

flowLayout->addWidget(block5Layout);

block6Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block6Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveProjectServiceButtons = new AddRemoveButtons();
block6Layout->addRow("ProjectServices",addremoveProjectServiceButtons);
QObject::connect(addremoveProjectServiceButtons, SIGNAL(addPressed()), this, SLOT(addProjectService()));

flowLayout->addWidget(block6Layout);

block7Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block7Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveProjectFileButtons = new AddRemoveButtons();
block7Layout->addRow("ProjectFiles",addremoveProjectFileButtons);
QObject::connect(addremoveProjectFileButtons, SIGNAL(addPressed()), this, SLOT(addProjectFile()));

flowLayout->addWidget(block7Layout);

}
ERPDisplay* ProjectUI::p_instance = 0;
void ProjectUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ProjectUI*ProjectUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectUI*) p_instance; 
}
void ProjectUI::addTask(){ 
TaskUI* taskui = new TaskUI();
taskui->block0Layout->hideRow(taskui->project);
taskui->controllers->setFixedHeight(0);
Tasks.append(taskui);
RemovebtnWidgets* rmtask = new RemovebtnWidgets(0,taskui);
QObject::connect(rmtask, SIGNAL(removePressed(QWidget*)), this, SLOT(removeTask(QWidget*)));
block3Layout->addRow("Task"+QString::number(Tasks.count()),rmtask);
}
void ProjectUI::addTask(Task* Task){ 
TaskUI* taskui = new TaskUI();
taskui->block0Layout->hideRow(taskui->project);
taskui->controllers->setFixedHeight(0);
taskui->fill(Task);
Tasks.append(taskui);
RemovebtnWidgets* rmtask = new RemovebtnWidgets(0,taskui);
QObject::connect(rmtask, SIGNAL(removePressed(QWidget*)), this, SLOT(removeTask(QWidget*)));
block3Layout->addRow("Task"+QString::number(Tasks.count()),rmtask);
}
void ProjectUI::removeTask(QWidget* widget){ 
if(Tasks.count()  > 0){
TaskUI* taskui = (TaskUI*) widget;
Tasks.removeOne(taskui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block3Layout->removeRow(sender);
}
}
void ProjectUI::addProjectContactPerson(){ 
ProjectContactPersonUI* projectcontactpersonui = new ProjectContactPersonUI();
projectcontactpersonui->block0Layout->hideRow(projectcontactpersonui->project);
projectcontactpersonui->controllers->setFixedHeight(0);
ProjectContactPersons.append(projectcontactpersonui);
RemovebtnWidgets* rmprojectcontactperson = new RemovebtnWidgets(0,projectcontactpersonui);
QObject::connect(rmprojectcontactperson, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectContactPerson(QWidget*)));
block4Layout->addRow("ProjectContactPerson"+QString::number(ProjectContactPersons.count()),rmprojectcontactperson);
}
void ProjectUI::addProjectContactPerson(ProjectContactPerson* ProjectContactPerson){ 
ProjectContactPersonUI* projectcontactpersonui = new ProjectContactPersonUI();
projectcontactpersonui->block0Layout->hideRow(projectcontactpersonui->project);
projectcontactpersonui->controllers->setFixedHeight(0);
projectcontactpersonui->fill(ProjectContactPerson);
ProjectContactPersons.append(projectcontactpersonui);
RemovebtnWidgets* rmprojectcontactperson = new RemovebtnWidgets(0,projectcontactpersonui);
QObject::connect(rmprojectcontactperson, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectContactPerson(QWidget*)));
block4Layout->addRow("ProjectContactPerson"+QString::number(ProjectContactPersons.count()),rmprojectcontactperson);
}
void ProjectUI::removeProjectContactPerson(QWidget* widget){ 
if(ProjectContactPersons.count()  > 0){
ProjectContactPersonUI* projectcontactpersonui = (ProjectContactPersonUI*) widget;
ProjectContactPersons.removeOne(projectcontactpersonui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block4Layout->removeRow(sender);
}
}
void ProjectUI::addProjectProduct(){ 
ProjectProductUI* projectproductui = new ProjectProductUI();
projectproductui->block0Layout->hideRow(projectproductui->project);
projectproductui->controllers->setFixedHeight(0);
ProjectProducts.append(projectproductui);
RemovebtnWidgets* rmprojectproduct = new RemovebtnWidgets(0,projectproductui);
QObject::connect(rmprojectproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectProduct(QWidget*)));
block5Layout->addRow("ProjectProduct"+QString::number(ProjectProducts.count()),rmprojectproduct);
}
void ProjectUI::addProjectProduct(ProjectProduct* ProjectProduct){ 
ProjectProductUI* projectproductui = new ProjectProductUI();
projectproductui->block0Layout->hideRow(projectproductui->project);
projectproductui->controllers->setFixedHeight(0);
projectproductui->fill(ProjectProduct);
ProjectProducts.append(projectproductui);
RemovebtnWidgets* rmprojectproduct = new RemovebtnWidgets(0,projectproductui);
QObject::connect(rmprojectproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectProduct(QWidget*)));
block5Layout->addRow("ProjectProduct"+QString::number(ProjectProducts.count()),rmprojectproduct);
}
void ProjectUI::removeProjectProduct(QWidget* widget){ 
if(ProjectProducts.count()  > 0){
ProjectProductUI* projectproductui = (ProjectProductUI*) widget;
ProjectProducts.removeOne(projectproductui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block5Layout->removeRow(sender);
}
}
void ProjectUI::addProjectService(){ 
ProjectServiceUI* projectserviceui = new ProjectServiceUI();
projectserviceui->block0Layout->hideRow(projectserviceui->project);
projectserviceui->controllers->setFixedHeight(0);
ProjectServices.append(projectserviceui);
RemovebtnWidgets* rmprojectservice = new RemovebtnWidgets(0,projectserviceui);
QObject::connect(rmprojectservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectService(QWidget*)));
block6Layout->addRow("ProjectService"+QString::number(ProjectServices.count()),rmprojectservice);
}
void ProjectUI::addProjectService(ProjectService* ProjectService){ 
ProjectServiceUI* projectserviceui = new ProjectServiceUI();
projectserviceui->block0Layout->hideRow(projectserviceui->project);
projectserviceui->controllers->setFixedHeight(0);
projectserviceui->fill(ProjectService);
ProjectServices.append(projectserviceui);
RemovebtnWidgets* rmprojectservice = new RemovebtnWidgets(0,projectserviceui);
QObject::connect(rmprojectservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectService(QWidget*)));
block6Layout->addRow("ProjectService"+QString::number(ProjectServices.count()),rmprojectservice);
}
void ProjectUI::removeProjectService(QWidget* widget){ 
if(ProjectServices.count()  > 0){
ProjectServiceUI* projectserviceui = (ProjectServiceUI*) widget;
ProjectServices.removeOne(projectserviceui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block6Layout->removeRow(sender);
}
}
void ProjectUI::addProjectFile(){ 
ProjectFileUI* projectfileui = new ProjectFileUI();
projectfileui->block0Layout->hideRow(projectfileui->project);
projectfileui->controllers->setFixedHeight(0);
ProjectFiles.append(projectfileui);
RemovebtnWidgets* rmprojectfile = new RemovebtnWidgets(0,projectfileui);
QObject::connect(rmprojectfile, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectFile(QWidget*)));
block7Layout->addRow("ProjectFile"+QString::number(ProjectFiles.count()),rmprojectfile);
}
void ProjectUI::addProjectFile(ProjectFile* ProjectFile){ 
ProjectFileUI* projectfileui = new ProjectFileUI();
projectfileui->block0Layout->hideRow(projectfileui->project);
projectfileui->controllers->setFixedHeight(0);
projectfileui->fill(ProjectFile);
ProjectFiles.append(projectfileui);
RemovebtnWidgets* rmprojectfile = new RemovebtnWidgets(0,projectfileui);
QObject::connect(rmprojectfile, SIGNAL(removePressed(QWidget*)), this, SLOT(removeProjectFile(QWidget*)));
block7Layout->addRow("ProjectFile"+QString::number(ProjectFiles.count()),rmprojectfile);
}
void ProjectUI::removeProjectFile(QWidget* widget){ 
if(ProjectFiles.count()  > 0){
ProjectFileUI* projectfileui = (ProjectFileUI*) widget;
ProjectFiles.removeOne(projectfileui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block7Layout->removeRow(sender);
}
}
void ProjectUI::fill(Project* project){ 
clear();
this->project = project;
title->setText(project->Title);
startdate->setDate(QDate::fromString(project->StartDate));
enddate->setDate(QDate::fromString(project->EndDate));
willbeinvoiced->setChecked(project->WillBeInvoiced);
note->setText(project->Note);
foreach(Task* task, project->tasks) {
addTask(task);
}
foreach(ProjectContactPerson* projectcontactperson, project->projectcontactpersons) {
addProjectContactPerson(projectcontactperson);
}
foreach(ProjectProduct* projectproduct, project->projectproducts) {
addProjectProduct(projectproduct);
}
foreach(ProjectService* projectservice, project->projectservices) {
addProjectService(projectservice);
}
foreach(ProjectFile* projectfile, project->projectfiles) {
addProjectFile(projectfile);
}
} 
void ProjectUI::clear(){ 
delete this->project;
this->Tasks.clear();
this->ProjectContactPersons.clear();
this->ProjectProducts.clear();
this->ProjectServices.clear();
this->ProjectFiles.clear();
title->setText("");
startdate->setDate(QDate::currentDate());
enddate->setDate(QDate::currentDate());
willbeinvoiced->setChecked(false);
note->setText("");
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->project = new Project();
} 
void ProjectUI::selectProject(){ 
if(Project::GetStringList().contains(this->project->Title))
{
Project* con = Project::Get(this->project->Title);
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
if(!projectstatus->isHidden()) 
project->ProjectStatusID = projectstatus->getKey();
if(!contact->isHidden()) 
project->ContactID = contact->getKey();
if(startdate->text().trimmed().isEmpty()){
errors = true;
errorString += "Start Date Can't be Empty! \n";
startdate->setObjectName("error");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
}
else { 
startdate->setObjectName("startdate");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
project->StartDate = startdate->text().trimmed();
}
if(enddate->text().trimmed().isEmpty()){
errors = true;
errorString += "End Date Can't be Empty! \n";
enddate->setObjectName("error");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
}
else { 
enddate->setObjectName("enddate");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
project->EndDate = enddate->text().trimmed();
}
project->WillBeInvoiced = willbeinvoiced->text().trimmed().toInt();
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += "Note Can't be Empty! \n";
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
project->Note = note->text().trimmed();
}
for(int j = 0; j < ProjectFiles.length(); j++){
ProjectFiles.at(j)->name->setObjectName("name");
ProjectFiles.at(j)->name->style()->unpolish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->style()->polish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->update();
for(int w = 0; w < ProjectFiles.length(); w++){
if(ProjectFiles.at(j) != ProjectFiles.at(w))
if(ProjectFiles.at(j)->name->text() == ProjectFiles.at(w)->name->text()){
errors = true; 
 errorString += "ProjectFile has the same name \n";
ProjectFiles.at(j)->name->setObjectName("error");
ProjectFiles.at(j)->name->style()->unpolish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->style()->polish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->update();
}}}
if(!errors) {
project->save();
for(int i = 0; i < Tasks.length(); i++){
Tasks.at(i)->task->ProjectID= project->ProjectID;
if(!Tasks.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < project->tasks.length(); i++){
bool flag = false;
for(int j = 0; j < Tasks.length(); j++){
if(project->tasks.at(i)->TaskID == Tasks.at(j)->task->TaskID){
flag = true;}}
if(!flag){
project->tasks.at(i)->remove();}
}
for(int i = 0; i < ProjectContactPersons.length(); i++){
ProjectContactPersons.at(i)->projectcontactperson->ProjectID= project->ProjectID;
if(!ProjectContactPersons.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < project->projectcontactpersons.length(); i++){
bool flag = false;
for(int j = 0; j < ProjectContactPersons.length(); j++){
if(project->projectcontactpersons.at(i)->ProjectContactPersonID == ProjectContactPersons.at(j)->projectcontactperson->ProjectContactPersonID){
flag = true;}}
if(!flag){
project->projectcontactpersons.at(i)->remove();}
}
for(int i = 0; i < ProjectProducts.length(); i++){
ProjectProducts.at(i)->projectproduct->ProjectID= project->ProjectID;
if(!ProjectProducts.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < project->projectproducts.length(); i++){
bool flag = false;
for(int j = 0; j < ProjectProducts.length(); j++){
if(project->projectproducts.at(i)->ProjectProductID == ProjectProducts.at(j)->projectproduct->ProjectProductID){
flag = true;}}
if(!flag){
project->projectproducts.at(i)->remove();}
}
for(int i = 0; i < ProjectServices.length(); i++){
ProjectServices.at(i)->projectservice->ProjectID= project->ProjectID;
if(!ProjectServices.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < project->projectservices.length(); i++){
bool flag = false;
for(int j = 0; j < ProjectServices.length(); j++){
if(project->projectservices.at(i)->ProjectServiceID == ProjectServices.at(j)->projectservice->ProjectServiceID){
flag = true;}}
if(!flag){
project->projectservices.at(i)->remove();}
}
for(int i = 0; i < ProjectFiles.length(); i++){
ProjectFiles.at(i)->projectfile->ProjectID= project->ProjectID;
if(!ProjectFiles.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < project->projectfiles.length(); i++){
bool flag = false;
for(int j = 0; j < ProjectFiles.length(); j++){
if(project->projectfiles.at(i)->ProjectFileID == ProjectFiles.at(j)->projectfile->ProjectFileID){
flag = true;}}
if(!flag){
project->projectfiles.at(i)->remove();}
}
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
bool ProjectUI::updateModel(){ 
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
if(project->ProjectStatusID == 0) 
project->ProjectStatusID = projectstatus->getKey();
if(project->ContactID == 0) 
project->ContactID = contact->getKey();
if(startdate->text().trimmed().isEmpty()){
errors = true;
errorString += "Start Date Can't be Empty! \n";
startdate->setObjectName("error");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
}
else { 
startdate->setObjectName("startdate");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
project->StartDate = startdate->text().trimmed();
}
if(enddate->text().trimmed().isEmpty()){
errors = true;
errorString += "End Date Can't be Empty! \n";
enddate->setObjectName("error");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
}
else { 
enddate->setObjectName("enddate");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
project->EndDate = enddate->text().trimmed();
}
project->WillBeInvoiced = willbeinvoiced->text().trimmed().toInt();
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += "Note Can't be Empty! \n";
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
project->Note = note->text().trimmed();
}
for(int j = 0; j < ProjectFiles.length(); j++){
ProjectFiles.at(j)->name->setObjectName("name");
ProjectFiles.at(j)->name->style()->unpolish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->style()->polish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->update();
for(int w = 0; w < ProjectFiles.length(); w++){
if(ProjectFiles.at(j) != ProjectFiles.at(w))
if(ProjectFiles.at(j)->name->text() == ProjectFiles.at(w)->name->text()){
errors = true; 
 errorString += "ProjectFile has the same name \n";
ProjectFiles.at(j)->name->setObjectName("error");
ProjectFiles.at(j)->name->style()->unpolish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->style()->polish(ProjectFiles.at(j)->name);
ProjectFiles.at(j)->name->update();
}}}
for(int i = 0; i < Tasks.length(); i++){
Tasks.at(i)->task->ProjectID= project->ProjectID;
if(!Tasks.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < ProjectContactPersons.length(); i++){
ProjectContactPersons.at(i)->projectcontactperson->ProjectID= project->ProjectID;
if(!ProjectContactPersons.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < ProjectProducts.length(); i++){
ProjectProducts.at(i)->projectproduct->ProjectID= project->ProjectID;
if(!ProjectProducts.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < ProjectServices.length(); i++){
ProjectServices.at(i)->projectservice->ProjectID= project->ProjectID;
if(!ProjectServices.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < ProjectFiles.length(); i++){
ProjectFiles.at(i)->projectfile->ProjectID= project->ProjectID;
if(!ProjectFiles.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "Project",errorString.trimmed());
return false; 
 }
}
