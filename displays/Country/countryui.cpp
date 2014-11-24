/**************************************************************************
**   File: countryui.cpp
**   Created on: Sun Nov 23 14:11:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "countryui.h"
#include "../MainWindow.h"

CountryUI::CountryUI(QWidget *parent) :ERPDisplay(parent)
{

country = new Country();
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
	if (p_instance == 0) { 
		p_instance = new CountryUI(mainwindow::GetMainDisplay());
	} 
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
if(Country::GetStringList().contains(name->text()))
{
Country* con = Country::Get(name->text());
if(this->country->CountryID != con->CountryID){
fill(con);
}
}
else if(country->CountryID != 0)
clear();
}
void CountryUI::save(){ 
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
CountryIndexUI::ShowUI();
}
else{ QByteArray byteArray = errorString.toUtf8();	const char* cString = byteArray.constData(); 
 QMessageBox::warning(this, tr("My Application"), tr(cString)); 
 }
}
void CountryUI::cancel(){ 
CountryIndexUI::ShowUI();
}
