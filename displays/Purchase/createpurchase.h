/*************************************
**   Created on:  12/7/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef CREATEPURCHASE_H
#define CREATEPURCHASE_H

#include "../../erpdisplay.h"
#include "purchaseindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchase.h"
#include "../../Model/purchase.h"

#include "../PurchaseStoreProduct/purchasestoreproductui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>

class CreatePurchase : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CreatePurchase(QWidget *parent = 0);
	static void ShowUI();
	static CreatePurchase* GetUI();
	ERPTableView *tabel;
	QStandardItemModel *model;
	ERPFormBlock* block0Layout;
	AddRemoveButtons* addremovePurchaseStoreProductButtons;
	QPushButton *remove;
	ERPFormBlock *block1Layout;

	PurchaseStoreProductUI* purchasestoreproductui;
	QList<PurchaseStoreProductUI*> PurchaseStoreProducts;
	QDateEdit*creationdate;
	QDateEdit*deliverydate;
	void fill(Purchase* purchase);
Purchase* purchase;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void addPurchaseStoreProduct();
	void addPurchaseStoreProduct(PurchaseStoreProduct* PurchaseStoreProduct);
	void removePurchaseStoreProduct(QWidget* widget);
	void selectPurchase();
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

#endif // CREATEPURCHASE_H
