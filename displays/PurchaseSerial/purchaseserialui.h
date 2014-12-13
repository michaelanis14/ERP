/**************************************************************************
**   File: purchaseserialui.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESERIALUI_H
#define PURCHASESERIALUI_H
#include "../../erpdisplay.h"
#include "purchaseserialindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchaseserial.h"
#include "../../Model/purchaseserial.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class PurchaseSerialUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseSerialUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseSerialUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*title;
	QLineEdit*serial;
	void fill(PurchaseSerial* purchaseserial);
PurchaseSerial* purchaseserial;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectPurchaseSerial();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
