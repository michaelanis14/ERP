/**************************************************************************
**   File: invoicestoreproductui.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESTOREPRODUCTUI_H
#define INVOICESTOREPRODUCTUI_H
#include "../../erpdisplay.h"
#include "invoicestoreproductindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicestoreproduct.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoicestoreproduct.h"
#include "../../Model/invoice.h"
#include "../../Model/store.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceStoreProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceStoreProductUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceStoreProductUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*invoice;
	ERPComboBox*store;
	ERPComboBox*product;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(InvoiceStoreProduct* invoicestoreproduct);
InvoiceStoreProduct* invoicestoreproduct;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceStoreProduct();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
