/**************************************************************************
**   File: deliveryorderui.h
**   Created on: Sat Dec 13 13:51:05 EET 2014
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
#include "../CommonUI/barcode.h"
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
#include <QDateEdit>
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
	QLineEdit*serial;
	QLineEdit*barcode;
	Barcode* barcodeDisplay;
	QPushButton* generatebarcode;
	ERPComboBox*deliveryorderstatus;
	ERPComboBox*contact;
	QDateEdit*creationdate;
	QDateEdit*deliverydate;
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
	void generateBarcode();
	void barcodeChanged(QString barcode);
public slots:
	bool save();
	bool updateModel();
};
#endif
