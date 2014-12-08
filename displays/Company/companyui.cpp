/**************************************************************************
**   File: companyui.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "companyui.h"
#include "../MainWindow.h"

CompanyUI::CompanyUI(QWidget *parent) :ERPDisplay(parent)
{

company = new Company();
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
QStringList* list = new QStringList(Company::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectCompany()));
block0Layout->addRow("Name",name);
header = new QLineEdit();
block0Layout->addRow("Header",header);
footer = new QLineEdit();
block0Layout->addRow("Footer",footer);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* CompanyUI::p_instance = 0;
void CompanyUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new CompanyUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
CompanyUI*CompanyUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (CompanyUI*) p_instance; 
}
void CompanyUI::fill(Company* company){ 
clear();
this->company = company;
name->setText(company->Name);
header->setText(company->Header);
footer->setText(company->Footer);
} 
void CompanyUI::clear(){ 
delete this->company;
header->setText("");
footer->setText("");
this->company = new Company();
} 
void CompanyUI::selectCompany(){ 
if(Company::GetStringList().contains(this->company->Name))
{
Company* con = Company::Get(this->company->Name);
if(this->company->CompanyID != con->CompanyID){
fill(con);
}
}
else if(company->CompanyID != 0)
clear();
}
bool CompanyUI::save(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += "Name Can't be Empty! \n";
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
company->Name = name->text().trimmed();
}
if(header->text().trimmed().isEmpty()){
errors = true;
errorString += "Header Can't be Empty! \n";
header->setObjectName("error");
header->style()->unpolish(header);
header->style()->polish(header);
header->update();
}
else { 
header->setObjectName("header");
header->style()->unpolish(header);
header->style()->polish(header);
header->update();
company->Header = header->text().trimmed();
}
if(footer->text().trimmed().isEmpty()){
errors = true;
errorString += "Footer Can't be Empty! \n";
footer->setObjectName("error");
footer->style()->unpolish(footer);
footer->style()->polish(footer);
footer->update();
}
else { 
footer->setObjectName("footer");
footer->style()->unpolish(footer);
footer->style()->polish(footer);
footer->update();
company->Footer = footer->text().trimmed();
}
if(!errors) {
company->save();
if(!errors){
CompanyIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Company",errorString.trimmed());
return false; 
 }
}
void CompanyUI::cancel(){ 
CompanyIndexUI::ShowUI();
}
