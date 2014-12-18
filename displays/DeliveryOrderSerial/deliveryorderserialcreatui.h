/**************************************************************************
**   File: deliveryorderserialcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSERIALUI_H
#define DELIVERYORDERSERIALUI_H
#include "../../erpdisplay.h"
#include "deliveryorderserialui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class DeliveryOrderSerialCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderSerialCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderSerialCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*title;
	QLineEdit*serial;
	void fill(DeliveryOrderSerial* deliveryorderserial);
DeliveryOrderSerial* deliveryorderserial;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectDeliveryOrderSerial();
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
