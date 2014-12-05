/**************************************************************************
**   File: deliveryorderfreelineui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERFREELINEUI_H
#define DELIVERYORDERFREELINEUI_H
#include "../../erpdisplay.h"
#include "deliveryorderfreelineindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderfreeline.h"
#include "../../Model/deliveryorderfreeline.h"
#include "../../Model/deliveryorder.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class DeliveryOrderFreelineUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderFreelineUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderFreelineUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*deliveryorder;
	QLineEdit*description;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(DeliveryOrderFreeline* deliveryorderfreeline);
DeliveryOrderFreeline* deliveryorderfreeline;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectDeliveryOrderFreeline();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
