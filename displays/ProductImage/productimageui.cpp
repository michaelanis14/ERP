/**************************************************************************
**   File: productimageui.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
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
name = new QLineEdit();
QStringList* list = new QStringList(ProductImage::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectProductImage()));
block0Layout->addRow(QObject::tr("Name"),name);
imageLabel =  new QLabel();
 Add = new QPushButton(QObject::tr("Browse"));
QObject::connect(Add, SIGNAL(clicked()), this, SLOT(on_loadImageButton_clicked()));
imagedata = new QVariant();
block0Layout->addRow(QObject::tr("Image: "),imageLabel);
block0Layout->addRow("",Add);
product = new ERPComboBox();
product->addItems(Product::GetPairList());
block0Layout->addRow(QObject::tr("Product"),product);
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
name->setText(productimage->Name);
	QVariant currentImage = productimage->imageData;bytes = currentImage.toByteArray();QImage image;image.loadFromData(bytes);imageLabel->setPixmap(QPixmap::fromImage(image)); this->Add->setFixedHeight(0);this->Add->setParent(0);
product->setIndexByKey(productimage->ProductID);
} 
void ProductImageUI::clear(){ 
delete this->productimage;
this->productimage = new ProductImage();
} 
void ProductImageUI::selectProductImage(){ 
if(ProductImage::GetStringList().contains(this->productimage->Name))
{
ProductImage* con = ProductImage::Get(this->productimage->Name);
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
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
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
productimage->Name = name->text().trimmed();
}
if(!product->isHidden()) 
productimage->ProductID = product->getKey();
if(!errors) {
	QSqlRecord record; record.append(QSqlField("Name", QVariant::String));record.append(QSqlField("imagedata", QVariant::Image));record.append(QSqlField("ProductImageID", QVariant::Int));record.setValue("Name", name->text());record.setValue("imageData", bytes);record.setValue("ProductImageID", productimage->ProductImageID);
productimage->save(record);
if(!errors){
ProductImageIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("ProductImage"),errorString.trimmed());
return false; 
 }
}
void ProductImageUI::cancel(){ 
ProductImageIndexUI::ShowUI();
}
bool ProductImageUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
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
productimage->Name = name->text().trimmed();
}
if(productimage->ProductID == 0) 
productimage->ProductID = product->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("ProductImage"),errorString.trimmed());
return false; 
 }
}
void ProductImageUI::on_loadImageButton_clicked(){ 
QString fileName;
fileName = QFileDialog::getOpenFileName(this,QObject::tr("Choose Image"),".", tr("Image Files (*.png *.jpg *.bmp)"));
imageLabel->setPixmap(QPixmap(fileName));
QFileInfo fi(fileName);
this->name->setText(fi.fileName());
this->adjustSize();
	QImage currentImage = imageLabel->pixmap()->toImage();QBuffer buffer(&bytes);buffer.open(QIODevice::WriteOnly);currentImage.save(&buffer, "PNG");buffer.open(QIODevice::WriteOnly);this->productimage->imageData.setValue(bytes);
}
