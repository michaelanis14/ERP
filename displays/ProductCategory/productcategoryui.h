/**************************************************************************
**   File: productcategoryui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTCATEGORYUI_H
#define PRODUCTCATEGORYUI_H
#include "../../erpdisplay.h"
#include "productcategoryindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/productcategory.h"
#include "../../Model/productcategory.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class ProductCategoryUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductCategoryUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductCategoryUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(ProductCategory* productcategory);
ProductCategory* productcategory;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProductCategory();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
