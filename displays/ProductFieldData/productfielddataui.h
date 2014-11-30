/**************************************************************************
**   File: productfielddataui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTFIELDDATAUI_H
#define PRODUCTFIELDDATAUI_H
#include "../../erpdisplay.h"
#include "productfielddataindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/productfielddata.h"
#include "../../Model/productfielddata.h"
#include "../../Model/product.h"
#include "../../Model/productfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class ProductFieldDataUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductFieldDataUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductFieldDataUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*product;
	ERPComboBox*productfield;
	QLineEdit*value;
	void fill(ProductFieldData* productfielddata);
ProductFieldData* productfielddata;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProductFieldData();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
