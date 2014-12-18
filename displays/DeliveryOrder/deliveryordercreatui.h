/**************************************************************************
**   File: deliveryordercreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERUI_H
#define DELIVERYORDERUI_H
#include "../../erpdisplay.h"
#include "deliveryorderui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/erpmodel.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/deliveryorderserial.h"
#include "../../Model/deliveryorderstatus.h"
#include "../../Model/contact.h"
#include "../../Model/project.h"

#include "../DeliveryOrderStoreProduct/deliveryorderstoreproductui.h"
#include "../DeliveryOrderService/deliveryorderserviceui.h"
#include "../DeliveryOrderFreeline/deliveryorderfreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class DeliveryOrderCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	DeliveryOrderStoreProductUI* DeliveryOrderStoreProductui;
	QList<DeliveryOrderStoreProductUI*> DeliveryOrderStoreProducts;
	AddRemoveButtons* addremoveDeliveryOrderStoreProductBtn;
	DeliveryOrderServiceUI* DeliveryOrderServiceui;
	QList<DeliveryOrderServiceUI*> DeliveryOrderServices;
	AddRemoveButtons* addremoveDeliveryOrderServiceBtn;
	DeliveryOrderFreelineUI* DeliveryOrderFreelineui;
	QList<DeliveryOrderFreelineUI*> DeliveryOrderFreelines;
	AddRemoveButtons* addremoveDeliveryOrderFreelineBtn;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*deliveryorderserial;
	ERPComboBox*deliveryorderstatus;
	ERPComboBox*contact;
	ERPComboBox*project;
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
	void refreshTabel();
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
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
