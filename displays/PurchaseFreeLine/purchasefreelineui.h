/**************************************************************************
**   File: purchasefreelineui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASEFREELINEUI_H
#define PURCHASEFREELINEUI_H
#include "../../erpdisplay.h"
#include "purchasefreelineindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchasefreeline.h"
#include "../../Model/purchasefreeline.h"
#include "../../Model/purchase.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class PurchaseFreeLineUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseFreeLineUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseFreeLineUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*purchase;
	QLineEdit*description;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(PurchaseFreeLine* purchasefreeline);
PurchaseFreeLine* purchasefreeline;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectPurchaseFreeLine();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
