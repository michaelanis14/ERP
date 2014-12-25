/**************************************************************************
**   File: returndeliveryorderstoreproductui.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNDELIVERYORDERSTOREPRODUCTUI_H
#define RETURNDELIVERYORDERSTOREPRODUCTUI_H
#include "../../erpdisplay.h"
#include "returndeliveryorderstoreproductindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/returndeliveryorderstoreproduct.h"
#include "../../Model/erpmodel.h"
#include "../../Model/returndeliveryorderstoreproduct.h"
#include "../../Model/returndeliveryorder.h"
#include "../../Model/store.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ReturnDeliveryOrderStoreProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnDeliveryOrderStoreProductUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnDeliveryOrderStoreProductUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*returndeliveryorder;
	ERPComboBox*store;
	ERPComboBox*product;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(ReturnDeliveryOrderStoreProduct* returndeliveryorderstoreproduct);
ReturnDeliveryOrderStoreProduct* returndeliveryorderstoreproduct;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectReturnDeliveryOrderStoreProduct();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
