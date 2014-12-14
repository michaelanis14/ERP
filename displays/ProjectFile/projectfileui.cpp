/**************************************************************************
**   File: projectfileui.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "projectfileui.h"
#include "../MainWindow.h"

ProjectFileUI::ProjectFileUI(QWidget *parent) :ERPDisplay(parent)
{

projectfile = new ProjectFile();
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
name = new QLineEdit();
QStringList* list = new QStringList(ProjectFile::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectProjectFile()));
block0Layout->addRow(QObject::tr("Name"),name);
imageLabel =  new QLabel();
 Add = new QPushButton(QObject::tr("Browse"));
QObject::connect(Add, SIGNAL(clicked()), this, SLOT(on_loadImageButton_clicked()));
imagedata = new QVariant();
block0Layout->addRow(QObject::tr("Image: "),imageLabel);
block0Layout->addRow("",Add);
project = new ERPComboBox();
project->addItems(Project::GetPairList());
block0Layout->addRow(QObject::tr("Project"),project);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProjectFileUI::p_instance = 0;
void ProjectFileUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProjectFileUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ProjectFileUI*ProjectFileUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProjectFileUI*) p_instance; 
}
void ProjectFileUI::fill(ProjectFile* projectfile){ 
clear();
this->projectfile = projectfile;
name->setText(projectfile->Name);
	QVariant currentImage = projectfile->imageData;bytes = currentImage.toByteArray();QImage image;image.loadFromData(bytes);imageLabel->setPixmap(QPixmap::fromImage(image)); this->Add->setFixedHeight(0);this->Add->setParent(0);
project->setIndexByKey(projectfile->ProjectID);
} 
void ProjectFileUI::clear(){ 
delete this->projectfile;
this->projectfile = new ProjectFile();
} 
void ProjectFileUI::selectProjectFile(){ 
if(ProjectFile::GetStringList().contains(this->projectfile->Name))
{
ProjectFile* con = ProjectFile::Get(this->projectfile->Name);
if(this->projectfile->ProjectFileID != con->ProjectFileID){
fill(con);
}
}
else if(projectfile->ProjectFileID != 0)
clear();
}
bool ProjectFileUI::save(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
name->setObjectName("error");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
}
else { 
name->setObjectName("name");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
projectfile->Name = name->text().trimmed();
}
if(!project->isHidden()) 
projectfile->ProjectID = project->getKey();
if(!errors) {
	QSqlRecord record; record.append(QSqlField("Name", QVariant::String));record.append(QSqlField("imagedata", QVariant::Image));record.append(QSqlField("ProjectFileID", QVariant::Int));record.setValue("Name", name->text());record.setValue("imageData", bytes);record.setValue("ProjectFileID", projectfile->ProjectFileID);
projectfile->save(record);
if(!errors){
ProjectFileIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProjectFile"),errorString.trimmed());
return false; 
 }
}
void ProjectFileUI::cancel(){ 
ProjectFileIndexUI::ShowUI();
}
bool ProjectFileUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
name->setObjectName("error");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
}
else { 
name->setObjectName("name");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
projectfile->Name = name->text().trimmed();
}
if(projectfile->ProjectID == 0) 
projectfile->ProjectID = project->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProjectFile"),errorString.trimmed());
return false; 
 }
}
void ProjectFileUI::on_loadImageButton_clicked(){ 
QString fileName;
fileName = QFileDialog::getOpenFileName(this,QObject::tr("Choose Image"),".", tr("Image Files (*.png *.jpg *.bmp)"));
imageLabel->setPixmap(QPixmap(fileName));
QFileInfo fi(fileName);
this->name->setText(fi.fileName());
this->adjustSize();
	QImage currentImage = imageLabel->pixmap()->toImage();QBuffer buffer(&bytes);buffer.open(QIODevice::WriteOnly);currentImage.save(&buffer, "PNG");buffer.open(QIODevice::WriteOnly);this->projectfile->imageData.setValue(bytes);
}
