/**************************************************************************
**   File: productui.h
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTUI_H
#define PRODUCTUI_H
#include "../../erpdisplay.h"
#include "productindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../CommonUI/barcode.h"
#include "../../Model/product.h"
#include "../../Model/product.h"
#include "../../Model/unit.h"
#include "../../Model/tax.h"
#include "../../Model/productcategory.h"

#include "../ProductImage/productimageui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	QList<ProductImageUI*> ProductImages;
	QLineEdit*name;
	QLineEdit*shortdescription;
	ERPComboBox*unit;
	QLineEdit*sellingprice;
	QLineEdit*netcoast;
	QLineEdit*trademarginrate;
	ERPComboBox*tax;
	QLineEdit*information;
	QLineEdit*barcode;
	Barcode* barcodeDisplay;
	QPushButton* generatebarcode;
	ERPComboBox*productcategory;
	QLineEdit*criticalamount;
	void fill(Product* product);
Product* product;
private:
	static ERPDisplay* p_instance;
private slots:
	void addProductImage();
	void addProductImage(ProductImage* ProductImage);
	void removeProductImage(QWidget* widget);
	void selectProduct();
	void cancel();
	void clear();
	void generateBarcode();
	void barcodeChanged(QString barcode);
public slots:
	bool save();
	bool updateModel();
};
#endif
