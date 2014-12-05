/**************************************************************************
**   File: productfielddataui.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productfielddataui.h"
#include "../MainWindow.h"

ProductFieldDataUI::ProductFieldDataUI(QWidget *parent) :ERPDisplay(parent)
{

productfielddata = new ProductFieldData();
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
product = new ERPComboBox();
product->addItems(Product::GetHashList());
block0Layout->addRow("Product",product);
productfield = new ERPComboBox();
productfield->addItems(ProductField::GetHashList());
block0Layout->addRow("Product Field",productfield);
value = new QLineEdit();
block0Layout->addRow("Value",value);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProductFieldDataUI::p_instance = 0;
void ProductFieldDataUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProductFieldDataUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ProductFieldDataUI*ProductFieldDataUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProductFieldDataUI*) p_instance; 
}
void ProductFieldDataUI::fill(ProductFieldData* productfielddata){ 
clear();
this->productfielddata = productfielddata;
value->setText(productfielddata->Value);
} 
void ProductFieldDataUI::clear(){ 
delete this->productfielddata;
value->setText("");
this->productfielddata = new ProductFieldData();
} 
void ProductFieldDataUI::selectProductFieldData(){ 
if(ProductFieldData::GetStringList().contains(value->text()))
{
ProductFieldData* con = ProductFieldData::Get(value->text());
if(this->productfielddata->ProductFieldDataID != con->ProductFieldDataID){
fill(con);
}
}
else if(productfielddata->ProductFieldDataID != 0)
clear();
}
bool ProductFieldDataUI::save(){ 
bool errors = false;
QString errorString =  "";
if(productfielddata->ProductID == 0) 
productfielddata->ProductID = product->getKey();
if(productfielddata->ProductFieldID == 0) 
productfielddata->ProductFieldID = productfield->getKey();
if(value->text().trimmed().isEmpty()){
errors = true;
errorString += "Value Can't be Empty! \n";
value->setObjectName("error");
value->style()->unpolish(value);
value->style()->polish(value);
value->update();
}
else { 
value->setObjectName("value");
value->style()->unpolish(value);
value->style()->polish(value);
value->update();
productfielddata->Value = value->text().trimmed();
}
if(!errors) {
productfielddata->save();
if(!errors){
ProductFieldDataIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ProductFieldData",errorString.trimmed());
return false; 
 }
}
void ProductFieldDataUI::cancel(){ 
ProductFieldDataIndexUI::ShowUI();
}
