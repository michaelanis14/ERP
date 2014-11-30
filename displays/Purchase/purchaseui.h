/**************************************************************************
**   File: purchaseui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASEUI_H
#define PURCHASEUI_H
#include "../../erpdisplay.h"
#include "purchaseindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchase.h"
#include "../../Model/purchase.h"
#include "../../Model/store.h"

#include "../PurchaseProduct/purchaseproductui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class PurchaseUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseUI* GetUI();
	ERPFormBlock* block0Layout;
	QList<PurchaseProductUI*> PurchaseProducts;
	QLineEdit*title;
	ERPComboBox*store;
	QLineEdit*creationdate;
	QLineEdit*deliverydate;
	void fill(Purchase* purchase);
Purchase* purchase;
private:
	static ERPDisplay* p_instance;
private slots:
	void addPurchaseProduct();
	void addPurchaseProduct(PurchaseProduct* PurchaseProduct);
	void removePurchaseProduct(QWidget* widget);
	void selectPurchase();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
