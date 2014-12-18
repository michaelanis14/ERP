/**************************************************************************
**   File: purchasestoreproductcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESTOREPRODUCTUI_H
#define PURCHASESTOREPRODUCTUI_H
#include "../../erpdisplay.h"
#include "purchasestoreproductui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class PurchaseStoreProductCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseStoreProductCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseStoreProductCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*store;
	ERPComboBox*purchase;
	ERPComboBox*contact;
	ERPComboBox*product;
	QLineEdit*amount;
	void fill(PurchaseStoreProduct* purchasestoreproduct);
PurchaseStoreProduct* purchasestoreproduct;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectPurchaseStoreProduct();
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
