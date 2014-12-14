/**************************************************************************
**   File: purchasestatusui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESTATUSUI_H
#define PURCHASESTATUSUI_H
#include "../../erpdisplay.h"
#include "purchasestatusindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchasestatus.h"
#include "../../Model/purchasestatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class PurchaseStatusUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseStatusUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseStatusUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(PurchaseStatus* purchasestatus);
PurchaseStatus* purchasestatus;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectPurchaseStatus();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
