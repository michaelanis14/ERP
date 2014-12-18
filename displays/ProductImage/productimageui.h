/**************************************************************************
**   File: productimageui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTIMAGEUI_H
#define PRODUCTIMAGEUI_H
#include "../../erpdisplay.h"
#include "productimageindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/productimage.h"
#include "../../Model/erpmodel.h"
#include "../../Model/productimage.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProductImageUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductImageUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductImageUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
 QLabel* imageLabel;
 QLineEdit* fileName;
 QPushButton* Add;
QByteArray bytes;
	QVariant* imagedata;
	ERPComboBox*product;
	void fill(ProductImage* productimage);
ProductImage* productimage;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProductImage();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
void on_loadImageButton_clicked(); 
};
#endif
