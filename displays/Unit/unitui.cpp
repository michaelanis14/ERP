/**************************************************************************
**   File: unitui.cpp
**   Created on: Sun Nov 23 14:11:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "unitui.h"
#include "../MainWindow.h"

UnitUI::UnitUI(QWidget *parent) :ERPDisplay(parent)
{

unit = new Unit();
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
description = new QLineEdit();
block0Layout->addRow("Description",description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* UnitUI::p_instance = 0;
void UnitUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new UnitUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
UnitUI*UnitUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (UnitUI*) p_instance; 
}
void UnitUI::fill(Unit* unit){ 
clear();
this->unit = unit;
description->setText(unit->Description);
} 
void UnitUI::clear(){ 
delete this->unit;
description->setText("");
this->unit = new Unit();
} 
void UnitUI::selectUnit(){ 
if(Unit::GetStringList().contains(description->text()))
{
Unit* con = Unit::Get(description->text());
if(this->unit->UnitID != con->UnitID){
fill(con);
}
}
else if(unit->UnitID != 0)
clear();
}
void UnitUI::save(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += "Description Can't be Empty! \n";
description->setObjectName("error");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
}
else { 
description->setObjectName("description");
description->style()->unpolish(description);
description->style()->polish(description);
description->update();
unit->Description = description->text().trimmed();
}
if(!errors) {
unit->save();
UnitIndexUI::ShowUI();
}
else{ QByteArray byteArray = errorString.toUtf8();	const char* cString = byteArray.constData(); 
 QMessageBox::warning(this, tr("My Application"), tr(cString)); 
 }
}
void UnitUI::cancel(){ 
UnitIndexUI::ShowUI();
}
