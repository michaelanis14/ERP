/**************************************************************************
**   File: deliveryorderstatusui.h
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSTATUSUI_H
#define DELIVERYORDERSTATUSUI_H
#include "../../erpdisplay.h"
#include "deliveryorderstatusindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderstatus.h"
#include "../../Model/deliveryorderstatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class DeliveryOrderStatusUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderStatusUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderStatusUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(DeliveryOrderStatus* deliveryorderstatus);
DeliveryOrderStatus* deliveryorderstatus;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectDeliveryOrderStatus();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
