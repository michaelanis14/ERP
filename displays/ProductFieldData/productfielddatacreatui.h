/**************************************************************************
**   File: productfielddatacreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTFIELDDATAUI_H
#define PRODUCTFIELDDATAUI_H
#include "../../erpdisplay.h"
#include "productfielddataui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/productfielddata.h"
#include "../../Model/erpmodel.h"
#include "../../Model/productfielddata.h"
#include "../../Model/product.h"
#include "../../Model/productfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ProductFieldDataCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductFieldDataCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductFieldDataCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*product;
	ERPComboBox*productfield;
	QLineEdit*value;
	void fill(ProductFieldData* productfielddata);
ProductFieldData* productfielddata;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProductFieldData();
	void cancel();
	void clear();
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
