/**************************************************************************
**   File: countryui.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "countryui.h"
#include "../MainWindow.h"

CountryUI::CountryUI(QWidget *parent) :ERPDisplay(parent)
{

country = new Country();
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
QStringList* list = new QStringList(Country::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectCountry()));
block0Layout->addRow("Name",name);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* CountryUI::p_instance = 0;
void CountryUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new CountryUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
CountryUI*CountryUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (CountryUI*) p_instance; 
}
void CountryUI::fill(Country* country){ 
clear();
this->country = country;
name->setText(country->Name);
} 
void CountryUI::clear(){ 
delete this->country;
this->country = new Country();
} 
void CountryUI::selectCountry(){ 
if(Country::GetStringList().contains(this->country->Name))
{
Country* con = Country::Get(this->country->Name);
if(this->country->CountryID != con->CountryID){
fill(con);
}
}
else if(country->CountryID != 0)
clear();
}
bool CountryUI::save(){ 
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
country->Name = name->text().trimmed();
}
if(!errors) {
country->save();
if(!errors){
CountryIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Country",errorString.trimmed());
return false; 
 }
}
void CountryUI::cancel(){ 
CountryIndexUI::ShowUI();
}
