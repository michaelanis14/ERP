/**************************************************************************
**   File: deliveryorderservicecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSERVICEUI_H
#define DELIVERYORDERSERVICEUI_H
#include "../../erpdisplay.h"
#include "deliveryorderserviceui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderservice.h"
#include "../../Model/erpmodel.h"
#include "../../Model/deliveryorderservice.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class DeliveryOrderServiceCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderServiceCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderServiceCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*deliveryorder;
	ERPComboBox*service;
	QLineEdit*amount;
	void fill(DeliveryOrderService* deliveryorderservice);
DeliveryOrderService* deliveryorderservice;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectDeliveryOrderService();
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
