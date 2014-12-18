/**************************************************************************
**   File: productfieldcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTFIELDUI_H
#define PRODUCTFIELDUI_H
#include "../../erpdisplay.h"
#include "productfieldui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class ProductFieldCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductFieldCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductFieldCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	ERPComboBox*fieldtype;
	QCheckBox* defaults;
	void fill(ProductField* productfield);
ProductField* productfield;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProductField();
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
