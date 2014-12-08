/**************************************************************************
**   File: productfieldui.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productfieldui.h"
#include "../MainWindow.h"

ProductFieldUI::ProductFieldUI(QWidget *parent) :ERPDisplay(parent)
{

productfield = new ProductField();
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
description = new QLineEdit();
block0Layout->addRow("Description",description);
fieldtype = new ERPComboBox();
fieldtype->addItems(FieldType::GetHashList());
block0Layout->addRow("Field Type",fieldtype);
defaults = new QCheckBox();
block0Layout->addRow("Defaults",defaults);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProductFieldUI::p_instance = 0;
void ProductFieldUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProductFieldUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ProductFieldUI*ProductFieldUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProductFieldUI*) p_instance; 
}
void ProductFieldUI::fill(ProductField* productfield){ 
clear();
this->productfield = productfield;
description->setText(productfield->Description);
defaults->setChecked(productfield->Defaults);
} 
void ProductFieldUI::clear(){ 
delete this->productfield;
description->setText("");
defaults->setChecked(false);
this->productfield = new ProductField();
} 
void ProductFieldUI::selectProductField(){ 
if(ProductField::GetStringList().contains(this->productfield->Description))
{
ProductField* con = ProductField::Get(this->productfield->Description);
if(this->productfield->ProductFieldID != con->ProductFieldID){
fill(con);
}
}
else if(productfield->ProductFieldID != 0)
clear();
}
bool ProductFieldUI::save(){ 
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
productfield->Description = description->text().trimmed();
}
if(productfield->FieldTypeID == 0) 
productfield->FieldTypeID = fieldtype->getKey();
productfield->Defaults = defaults->text().trimmed().toInt();
if(!errors) {
productfield->save();
if(!errors){
ProductFieldIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ProductField",errorString.trimmed());
return false; 
 }
}
void ProductFieldUI::cancel(){ 
ProductFieldIndexUI::ShowUI();
}
