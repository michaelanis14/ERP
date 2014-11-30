/**************************************************************************
**   File: purchaseproductui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASEPRODUCTUI_H
#define PURCHASEPRODUCTUI_H
#include "../../erpdisplay.h"
#include "purchaseproductindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchaseproduct.h"
#include "../../Model/purchaseproduct.h"
#include "../../Model/purchase.h"
#include "../../Model/contact.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class PurchaseProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseProductUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseProductUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*title;
	ERPComboBox*purchase;
	ERPComboBox*contact;
	ERPComboBox*product;
	QLineEdit*amount;
	void fill(PurchaseProduct* purchaseproduct);
PurchaseProduct* purchaseproduct;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectPurchaseProduct();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
