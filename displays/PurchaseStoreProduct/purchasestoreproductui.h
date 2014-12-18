/**************************************************************************
**   File: purchasestoreproductui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESTOREPRODUCTUI_H
#define PURCHASESTOREPRODUCTUI_H
#include "../../erpdisplay.h"
#include "purchasestoreproductindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchasestoreproduct.h"
#include "../../Model/erpmodel.h"
#include "../../Model/purchasestoreproduct.h"
#include "../../Model/store.h"
#include "../../Model/purchase.h"
#include "../../Model/contact.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class PurchaseStoreProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseStoreProductUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseStoreProductUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*store;
	ERPComboBox*purchase;
	ERPComboBox*contact;
	ERPComboBox*product;
	QLineEdit*amount;
	void fill(PurchaseStoreProduct* purchasestoreproduct);
PurchaseStoreProduct* purchasestoreproduct;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectPurchaseStoreProduct();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
