/**************************************************************************
**   File: returnpurchasestoreproductui.h
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNPURCHASESTOREPRODUCTUI_H
#define RETURNPURCHASESTOREPRODUCTUI_H
#include "../../erpdisplay.h"
#include "returnpurchasestoreproductindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/returnpurchasestoreproduct.h"
#include "../../Model/erpmodel.h"
#include "../../Model/returnpurchasestoreproduct.h"
#include "../../Model/store.h"
#include "../../Model/returnpurchase.h"
#include "../../Model/contact.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ReturnPurchaseStoreProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnPurchaseStoreProductUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnPurchaseStoreProductUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*store;
	ERPComboBox*returnpurchase;
	ERPComboBox*contact;
	ERPComboBox*product;
	QLineEdit*amount;
	QLineEdit*price;
		QLineEdit*total;
	void fill(ReturnPurchaseStoreProduct* returnpurchasestoreproduct);
ReturnPurchaseStoreProduct* returnpurchasestoreproduct;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectReturnPurchaseStoreProduct();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
	void updateTotal(QString);
};
#endif
