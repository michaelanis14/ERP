/**************************************************************************
**   File: returnpurchasefreelineui.h
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNPURCHASEFREELINEUI_H
#define RETURNPURCHASEFREELINEUI_H
#include "../../erpdisplay.h"
#include "returnpurchasefreelineindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/returnpurchasefreeline.h"
#include "../../Model/erpmodel.h"
#include "../../Model/returnpurchasefreeline.h"
#include "../../Model/returnpurchase.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ReturnPurchaseFreeLineUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnPurchaseFreeLineUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnPurchaseFreeLineUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*returnpurchase;
	QLineEdit*description;
	ERPComboBox*contact;
	QLineEdit*amount;
	QLineEdit*price;
		QLineEdit*total;
	void fill(ReturnPurchaseFreeLine* returnpurchasefreeline);
ReturnPurchaseFreeLine* returnpurchasefreeline;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectReturnPurchaseFreeLine();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
	void updateTotal(QString);
};
#endif
