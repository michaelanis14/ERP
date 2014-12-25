/**************************************************************************
**   File: deliveryorderserialui.h
**   Created on: Fri Dec 19 13:01:03 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSERIALUI_H
#define DELIVERYORDERSERIALUI_H
#include "../../erpdisplay.h"
#include "deliveryorderserialindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderserial.h"
#include "../../Model/erpmodel.h"
#include "../../Model/deliveryorderserial.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class DeliveryOrderSerialUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderSerialUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderSerialUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*title;
	QLineEdit*serial;
	void fill(DeliveryOrderSerial* deliveryorderserial);
DeliveryOrderSerial* deliveryorderserial;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectDeliveryOrderSerial();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
