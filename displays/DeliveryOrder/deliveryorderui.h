/**************************************************************************
**   File: deliveryorderui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERUI_H
#define DELIVERYORDERUI_H
#include "../../erpdisplay.h"
#include "deliveryorderindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/deliveryorderstatus.h"
#include "../../Model/contact.h"

#include "../DeliveryOrderStoreProduct/deliveryorderstoreproductui.h"
#include "../DeliveryOrderService/deliveryorderserviceui.h"
#include "../DeliveryOrderFreeline/deliveryorderfreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class DeliveryOrderUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	ERPFormBlock* block3Layout;
	ERPFormBlock* block4Layout;
	QList<DeliveryOrderStoreProductUI*> DeliveryOrderStoreProducts;
	QList<DeliveryOrderServiceUI*> DeliveryOrderServices;
	QList<DeliveryOrderFreelineUI*> DeliveryOrderFreelines;
	QLineEdit*title;
	QLineEdit*number;
	ERPComboBox*deliveryorderstatus;
	ERPComboBox*contact;
	QLineEdit*creationdate;
	QLineEdit*deliverydate;
	QLineEdit*note;
	QLineEdit*header;
	QLineEdit*footer;
	QLineEdit*deliveryaddress;
	void fill(DeliveryOrder* deliveryorder);
DeliveryOrder* deliveryorder;
private:
	static ERPDisplay* p_instance;
private slots:
	void addDeliveryOrderStoreProduct();
	void addDeliveryOrderStoreProduct(DeliveryOrderStoreProduct* DeliveryOrderStoreProduct);
	void removeDeliveryOrderStoreProduct(QWidget* widget);
	void addDeliveryOrderService();
	void addDeliveryOrderService(DeliveryOrderService* DeliveryOrderService);
	void removeDeliveryOrderService(QWidget* widget);
	void addDeliveryOrderFreeline();
	void addDeliveryOrderFreeline(DeliveryOrderFreeline* DeliveryOrderFreeline);
	void removeDeliveryOrderFreeline(QWidget* widget);
	void selectDeliveryOrder();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
