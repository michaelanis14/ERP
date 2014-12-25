/**************************************************************************
**   File: returnpurchaseui.h
**   Created on: Thu Dec 18 23:40:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNPURCHASEUI_H
#define RETURNPURCHASEUI_H
#include "../../erpdisplay.h"
#include "returnpurchaseindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/returnpurchase.h"
#include "../../Model/erpmodel.h"
#include "../../Model/returnpurchase.h"
#include "../../Model/purchase.h"

#include "../ReturnPurchaseStoreProduct/returnpurchasestoreproductui.h"
#include "../ReturnPurchaseFreeLine/returnpurchasefreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ReturnPurchaseUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnPurchaseUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnPurchaseUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	QList<ReturnPurchaseStoreProductUI*> ReturnPurchaseStoreProducts;
	QList<ReturnPurchaseFreeLineUI*> ReturnPurchaseFreeLines;
	ERPComboBox*purchase;
	QDateEdit*date;
	void fill(ReturnPurchase* returnpurchase);
ReturnPurchase* returnpurchase;
private:
	static ERPDisplay* p_instance;
private slots:
	void addReturnPurchaseStoreProduct();
	void addReturnPurchaseStoreProduct(ReturnPurchaseStoreProduct* ReturnPurchaseStoreProduct);
	void removeReturnPurchaseStoreProduct(QWidget* widget);
	void addReturnPurchaseFreeLine();
	void addReturnPurchaseFreeLine(ReturnPurchaseFreeLine* ReturnPurchaseFreeLine);
	void removeReturnPurchaseFreeLine(QWidget* widget);
	void selectReturnPurchase();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
	void selectionChanged(QString);
};
#endif
