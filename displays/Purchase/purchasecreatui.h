/**************************************************************************
**   File: purchasecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASEUI_H
#define PURCHASEUI_H
#include "../../erpdisplay.h"
#include "purchaseui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchase.h"
#include "../../Model/erpmodel.h"
#include "../../Model/purchase.h"
#include "../../Model/purchaseserial.h"

#include "../PurchaseStoreProduct/purchasestoreproductui.h"
#include "../PurchaseFreeLine/purchasefreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class PurchaseCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	PurchaseStoreProductUI* PurchaseStoreProductui;
	QList<PurchaseStoreProductUI*> PurchaseStoreProducts;
	AddRemoveButtons* addremovePurchaseStoreProductBtn;
	PurchaseFreeLineUI* PurchaseFreeLineui;
	QList<PurchaseFreeLineUI*> PurchaseFreeLines;
	AddRemoveButtons* addremovePurchaseFreeLineBtn;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*purchaseserial;
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
	void addPurchaseFreeLine();
	void addPurchaseFreeLine(PurchaseFreeLine* PurchaseFreeLine);
	void removePurchaseFreeLine(QWidget* widget);
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
#endif
