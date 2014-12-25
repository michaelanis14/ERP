/**************************************************************************
**   File: productfieldui.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTFIELDUI_H
#define PRODUCTFIELDUI_H
#include "../../erpdisplay.h"
#include "productfieldindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/productfield.h"
#include "../../Model/erpmodel.h"
#include "../../Model/productfield.h"
#include "../../Model/fieldtype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProductFieldUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductFieldUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductFieldUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	ERPComboBox*fieldtype;
	QCheckBox* defaults;
	void fill(ProductField* productfield);
ProductField* productfield;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProductField();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
