/**************************************************************************
**   File: invoiceperiodui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEPERIODUI_H
#define INVOICEPERIODUI_H
#include "../../erpdisplay.h"
#include "invoiceperiodindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoiceperiod.h"
#include "../../Model/invoiceperiod.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class InvoicePeriodUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoicePeriodUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoicePeriodUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(InvoicePeriod* invoiceperiod);
InvoicePeriod* invoiceperiod;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoicePeriod();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
