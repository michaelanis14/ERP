/**************************************************************************
**   File: productui.h
**   Created on: Sun Nov 23 14:11:12 EET 2014
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
#include "../../Model/product.h"
#include "../../Model/product.h"
#include "../../Model/tax.h"
#include "../../Model/unit.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class ProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	QLineEdit*sellingprice;
	QLineEdit*netprice;
	QLineEdit*trademargine;
	QLineEdit*description;
	QLineEdit*barcode;
	QLineEdit*criticalamount;
	QLineEdit*productnumber;
	QLineEdit*moreinfo;
	QCheckBox* barcodeonly;
	QCheckBox* iscomposite;
	QLineEdit*specialtaxdescription;
	QLineEdit*specialtaxvalue;
	ERPComboBox*tax;
	ERPComboBox*unit;
	QCheckBox* generatebarcode;
	QLineEdit*shortdescription;
	void fill(Product* product);
Product* product;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProduct();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
