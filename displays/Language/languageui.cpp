/**************************************************************************
**   File: languageui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "languageui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

LanguageUI::LanguageUI(QWidget *parent) :ERPDisplay(parent)
{

language = new Language();
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
block0Layout->addRow(QObject::tr("Title"),title);
file = new QLineEdit();
block0Layout->addRow(QObject::tr("File"),file);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* LanguageUI::p_instance = 0;
void LanguageUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Language) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new LanguageUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
LanguageUI*LanguageUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (LanguageUI*) p_instance; 
}
void LanguageUI::fill(Language* language){ 
clear();
this->language = language;
title->setText(language->Title);
file->setText(language->File);
} 
void LanguageUI::clear(){ 
delete this->language;
title->setText("");
file->setText("");
this->language = new Language();
} 
void LanguageUI::selectLanguage(){ 
if(Language::GetStringList().contains(this->language->Title))
{
Language* con = Language::Get(this->language->Title);
if(this->language->LanguageID != con->LanguageID){
fill(con);
}
}
else if(language->LanguageID != 0)
clear();
}
bool LanguageUI::save(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Title Can't be Empty! \n");
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
language->Title = title->text().trimmed();
}
if(file->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("File Can't be Empty! \n");
file->setObjectName("error");
file->style()->unpolish(file);
file->style()->polish(file);
file->update();
}
else { 
file->setObjectName("file");
file->style()->unpolish(file);
file->style()->polish(file);
file->update();
language->File = file->text().trimmed();
}
if(!errors) {
language->save();
if(!errors){
LanguageIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("Language"),errorString.trimmed());
return false; 
 }
}
void LanguageUI::cancel(){ 
LanguageIndexUI::ShowUI();
}
bool LanguageUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(title->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Title Can't be Empty! \n");
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
language->Title = title->text().trimmed();
}
if(file->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("File Can't be Empty! \n");
file->setObjectName("error");
file->style()->unpolish(file);
file->style()->polish(file);
file->update();
}
else { 
file->setObjectName("file");
file->style()->unpolish(file);
file->style()->polish(file);
file->update();
language->File = file->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Language"),errorString.trimmed());
return false; 
 }
}
