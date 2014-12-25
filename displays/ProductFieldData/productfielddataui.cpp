/**************************************************************************
**   File: productfielddataui.cpp
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productfielddataui.h"
#include "../Login/loginui.h"
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
product->addItems(Product::GetPairList());
block0Layout->addRow(QObject::tr("Product"),product);
productfield = new ERPComboBox();
productfield->addItems(ProductField::GetPairList());
block0Layout->addRow(QObject::tr("Product Field"),productfield);
value = new QLineEdit();
block0Layout->addRow(QObject::tr("Value"),value);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProductFieldDataUI::p_instance = 0;
void ProductFieldDataUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->ProductFieldData) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProductFieldDataUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
ProductFieldDataUI*ProductFieldDataUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProductFieldDataUI*) p_instance; 
}
void ProductFieldDataUI::fill(ProductFieldData* productfielddata){ 
clear();
this->productfielddata = productfielddata;
product->setIndexByKey(productfielddata->ProductID);
productfield->setIndexByKey(productfielddata->ProductFieldID);
value->setText(productfielddata->Value);
} 
void ProductFieldDataUI::clear(){ 
delete this->productfielddata;
value->setText("");
this->productfielddata = new ProductFieldData();
} 
void ProductFieldDataUI::selectProductFieldData(){ 
if(ProductFieldData::GetStringList().contains(QString::number(this->productfielddata->ProductID)))
{
ProductFieldData* con = ProductFieldData::Get(QString::number(this->productfielddata->ProductID));
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
if(!product->isHidden()) 
productfielddata->ProductID = product->getKey();
if(!productfield->isHidden()) 
productfielddata->ProductFieldID = productfield->getKey();
if(value->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Value Can't be Empty! \n");
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
else{ QMessageBox::warning(this, QObject::tr("ProductFieldData"),errorString.trimmed());
return false; 
 }
}
void ProductFieldDataUI::cancel(){ 
ProductFieldDataIndexUI::ShowUI();
}
bool ProductFieldDataUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(productfielddata->ProductID == 0) 
productfielddata->ProductID = product->getKey();
if(productfielddata->ProductFieldID == 0) 
productfielddata->ProductFieldID = productfield->getKey();
if(value->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Value Can't be Empty! \n");
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
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProductFieldData"),errorString.trimmed());
return false; 
 }
}
