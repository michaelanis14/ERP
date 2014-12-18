/**************************************************************************
**   File: deliveryorderstoreproductcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSTOREPRODUCTUI_H
#define DELIVERYORDERSTOREPRODUCTUI_H
#include "../../erpdisplay.h"
#include "deliveryorderstoreproductui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderstoreproduct.h"
#include "../../Model/erpmodel.h"
#include "../../Model/deliveryorderstoreproduct.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/store.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class DeliveryOrderStoreProductCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderStoreProductCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderStoreProductCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*deliveryorder;
	ERPComboBox*store;
	ERPComboBox*product;
	QLineEdit*amount;
	void fill(DeliveryOrderStoreProduct* deliveryorderstoreproduct);
DeliveryOrderStoreProduct* deliveryorderstoreproduct;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectDeliveryOrderStoreProduct();
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
