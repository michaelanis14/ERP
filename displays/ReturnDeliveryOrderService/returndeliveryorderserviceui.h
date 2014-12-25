/**************************************************************************
**   File: returndeliveryorderserviceui.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNDELIVERYORDERSERVICEUI_H
#define RETURNDELIVERYORDERSERVICEUI_H
#include "../../erpdisplay.h"
#include "returndeliveryorderserviceindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/returndeliveryorderservice.h"
#include "../../Model/erpmodel.h"
#include "../../Model/returndeliveryorderservice.h"
#include "../../Model/returndeliveryorder.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ReturnDeliveryOrderServiceUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnDeliveryOrderServiceUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnDeliveryOrderServiceUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*returndeliveryorder;
	ERPComboBox*service;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(ReturnDeliveryOrderService* returndeliveryorderservice);
ReturnDeliveryOrderService* returndeliveryorderservice;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectReturnDeliveryOrderService();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
