/**************************************************************************
**   File: productcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTUI_H
#define PRODUCTUI_H
#include "../../erpdisplay.h"
#include "productui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../CommonUI/barcode.h"
#include "../../Model/product.h"
#include "../../Model/erpmodel.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class ProductCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ProductImageUI* ProductImageui;
	QList<ProductImageUI*> ProductImages;
	AddRemoveButtons* addremoveProductImageBtn;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
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
	void refreshTabel();
private slots:
	void addProductImage();
	void addProductImage(ProductImage* ProductImage);
	void removeProductImage(QWidget* widget);
	void selectProduct();
	void cancel();
	void clear();
	void removeRow();
	void generateBarcode();
	void barcodeChanged(QString barcode);
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
