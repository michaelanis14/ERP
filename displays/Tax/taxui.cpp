/**************************************************************************
**   File: taxui.cpp
**   Created on: Wed Nov 26 16:22:56 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "taxui.h"
#include "../MainWindow.h"

TaxUI::TaxUI(QWidget *parent) :ERPDisplay(parent)
{

tax = new Tax();
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
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
ratio = new QLineEdit();
ratio->setValidator( doubleValidator );
block0Layout->addRow("Ratio",ratio);
description = new QLineEdit();
block0Layout->addRow("Description",description);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* TaxUI::p_instance = 0;
void TaxUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new TaxUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
TaxUI*TaxUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (TaxUI*) p_instance; 
}
void TaxUI::fill(Tax* tax){ 
clear();
this->tax = tax;
ratio->setText(QString::number(tax->Ratio));
description->setText(tax->Description);
} 
void TaxUI::clear(){ 
delete this->tax;
ratio->setText("");
description->setText("");
this->tax = new Tax();
} 
void TaxUI::selectTax(){ 
if(Tax::GetStringList().contains(description->text()))
{
Tax* con = Tax::Get(description->text());
if(this->tax->TaxID != con->TaxID){
fill(con);
}
}
else if(tax->TaxID != 0)
clear();
}
bool TaxUI::save(){ 
bool errors = false;
QString errorString =  "";
if(ratio->text().trimmed().isEmpty()){
errors = true;
errorString += "Ratio Can't be Empty! \n";
ratio->setObjectName("error");
ratio->style()->unpolish(ratio);
ratio->style()->polish(ratio);
ratio->update();
}
else { 
ratio->setObjectName("ratio");
ratio->style()->unpolish(ratio);
ratio->style()->polish(ratio);
ratio->update();
tax->Ratio = ratio->text().trimmed().toDouble();
}
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
tax->Description = description->text().trimmed();
}
if(!errors) {
tax->save();
if(!errors){
TaxIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Tax",errorString.trimmed());
return false; 
 }
}
void TaxUI::cancel(){ 
TaxIndexUI::ShowUI();
}
