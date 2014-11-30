/**************************************************************************
**   File: deliveryorderserviceui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSERVICEUI_H
#define DELIVERYORDERSERVICEUI_H
#include "../../erpdisplay.h"
#include "deliveryorderserviceindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderservice.h"
#include "../../Model/deliveryorderservice.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class DeliveryOrderServiceUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderServiceUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderServiceUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*title;
	ERPComboBox*deliveryorder;
	ERPComboBox*service;
	QLineEdit*amount;
	void fill(DeliveryOrderService* deliveryorderservice);
DeliveryOrderService* deliveryorderservice;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectDeliveryOrderService();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
