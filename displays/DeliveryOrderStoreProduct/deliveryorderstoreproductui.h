/**************************************************************************
**   File: deliveryorderstoreproductui.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSTOREPRODUCTUI_H
#define DELIVERYORDERSTOREPRODUCTUI_H
#include "../../erpdisplay.h"
#include "deliveryorderstoreproductindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderstoreproduct.h"
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
#include <QDateEdit>
class DeliveryOrderStoreProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderStoreProductUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderStoreProductUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*deliveryorder;
	ERPComboBox*store;
	ERPComboBox*product;
	QLineEdit*amount;
	void fill(DeliveryOrderStoreProduct* deliveryorderstoreproduct);
DeliveryOrderStoreProduct* deliveryorderstoreproduct;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectDeliveryOrderStoreProduct();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
