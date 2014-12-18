/**************************************************************************
**   File: deliveryorderstatuscreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSTATUSUI_H
#define DELIVERYORDERSTATUSUI_H
#include "../../erpdisplay.h"
#include "deliveryorderstatusui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderstatus.h"
#include "../../Model/erpmodel.h"
#include "../../Model/deliveryorderstatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class DeliveryOrderStatusCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderStatusCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderStatusCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(DeliveryOrderStatus* deliveryorderstatus);
DeliveryOrderStatus* deliveryorderstatus;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectDeliveryOrderStatus();
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
