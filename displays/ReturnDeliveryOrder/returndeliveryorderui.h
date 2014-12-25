/**************************************************************************
**   File: returndeliveryorderui.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNDELIVERYORDERUI_H
#define RETURNDELIVERYORDERUI_H
#include "../../erpdisplay.h"
#include "returndeliveryorderindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/returndeliveryorder.h"
#include "../../Model/erpmodel.h"
#include "../../Model/returndeliveryorder.h"
#include "../../Model/deliveryorder.h"

#include "../ReturnDeliveryOrderStoreProduct/returndeliveryorderstoreproductui.h"
#include "../ReturnDeliveryOrderService/returndeliveryorderserviceui.h"
#include "../ReturnDeliveryOrderFreeline/returndeliveryorderfreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ReturnDeliveryOrderUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnDeliveryOrderUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnDeliveryOrderUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	ERPFormBlock* block3Layout;
	QList<ReturnDeliveryOrderStoreProductUI*> ReturnDeliveryOrderStoreProducts;
	QList<ReturnDeliveryOrderServiceUI*> ReturnDeliveryOrderServices;
	QList<ReturnDeliveryOrderFreelineUI*> ReturnDeliveryOrderFreelines;
	QLineEdit*serial;
	ERPComboBox*deliveryorder;
	QDateEdit*date;
	QLineEdit*note;
	void fill(ReturnDeliveryOrder* returndeliveryorder);
ReturnDeliveryOrder* returndeliveryorder;
private:
	static ERPDisplay* p_instance;
private slots:
	void addReturnDeliveryOrderStoreProduct();
	void addReturnDeliveryOrderStoreProduct(ReturnDeliveryOrderStoreProduct* ReturnDeliveryOrderStoreProduct);
	void removeReturnDeliveryOrderStoreProduct(QWidget* widget);
	void addReturnDeliveryOrderService();
	void addReturnDeliveryOrderService(ReturnDeliveryOrderService* ReturnDeliveryOrderService);
	void removeReturnDeliveryOrderService(QWidget* widget);
	void addReturnDeliveryOrderFreeline();
	void addReturnDeliveryOrderFreeline(ReturnDeliveryOrderFreeline* ReturnDeliveryOrderFreeline);
	void removeReturnDeliveryOrderFreeline(QWidget* widget);
	void selectReturnDeliveryOrder();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
	void selectionChanged(QString);
};
#endif
