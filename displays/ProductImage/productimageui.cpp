/**************************************************************************
**   File: productimageui.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productimageui.h"
#include "../MainWindow.h"

ProductImageUI::ProductImageUI(QWidget *parent) :ERPDisplay(parent)
{

productimage = new ProductImage();
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
product = new ERPComboBox();
product->addItems(Product::GetHashList());
block0Layout->addRow("Product",product);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* ProductImageUI::p_instance = 0;
void ProductImageUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProductImageUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ProductImageUI*ProductImageUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProductImageUI*) p_instance; 
}
void ProductImageUI::fill(ProductImage* productimage){ 
clear();
this->productimage = productimage;
description->setText(productimage->Description);
} 
void ProductImageUI::clear(){ 
delete this->productimage;
description->setText("");
this->productimage = new ProductImage();
} 
void ProductImageUI::selectProductImage(){ 
if(ProductImage::GetStringList().contains(this->productimage->Description))
{
ProductImage* con = ProductImage::Get(this->productimage->Description);
if(this->productimage->ProductImageID != con->ProductImageID){
fill(con);
}
}
else if(productimage->ProductImageID != 0)
clear();
}
bool ProductImageUI::save(){ 
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
productimage->Description = description->text().trimmed();
}
if(productimage->ProductID == 0) 
productimage->ProductID = product->getKey();
if(!errors) {
productimage->save();
if(!errors){
ProductImageIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "ProductImage",errorString.trimmed());
return false; 
 }
}
void ProductImageUI::cancel(){ 
ProductImageIndexUI::ShowUI();
}
