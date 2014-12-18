/**************************************************************************
**   File: productfieldui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productfieldui.h"
#include "../Login/loginui.h"
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
block0Layout->addRow(QObject::tr("Description"),description);
fieldtype = new ERPComboBox();
fieldtype->addItems(FieldType::GetPairList());
block0Layout->addRow(QObject::tr("Field Type"),fieldtype);
defaults = new QCheckBox();
block0Layout->addRow(QObject::tr("Defaults"),defaults);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProductFieldUI::p_instance = 0;
void ProductFieldUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ProductField) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProductFieldUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
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
fieldtype->setIndexByKey(productfield->FieldTypeID);
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
errorString += QObject::tr("Description Can't be Empty! \n");
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
if(!fieldtype->isHidden()) 
productfield->FieldTypeID = fieldtype->getKey();
productfield->Defaults = defaults->text().trimmed().toInt();
if(!errors) {
productfield->save();
if(!errors){
ProductFieldIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProductField"),errorString.trimmed());
return false; 
 }
}
void ProductFieldUI::cancel(){ 
ProductFieldIndexUI::ShowUI();
}
bool ProductFieldUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(description->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Description Can't be Empty! \n");
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
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProductField"),errorString.trimmed());
return false; 
 }
}
