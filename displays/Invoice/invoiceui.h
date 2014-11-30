/**************************************************************************
**   File: invoiceui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEUI_H
#define INVOICEUI_H
#include "../../erpdisplay.h"
#include "invoiceindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoice.h"
#include "../../Model/invoice.h"
#include "../../Model/invoiceperiod.h"
#include "../../Model/invoiceyear.h"
#include "../../Model/project.h"

#include "../InvoiceStateDate/invoicestatedateui.h"
#include "../InvoiceFreeline/invoicefreelineui.h"
#include "../Payment/paymentui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class InvoiceUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceUI* GetUI();
	ERPFormBlock* block0Layout;
	QList<InvoiceStateDateUI*> InvoiceStateDates;
	QList<InvoiceFreelineUI*> InvoiceFreelines;
	QList<PaymentUI*> Payments;
	QLineEdit*title;
	QLineEdit*creationdate;
	QLineEdit*enddate;
	ERPComboBox*invoiceperiod;
	ERPComboBox*invoiceyear;
	ERPComboBox*project;
	QLineEdit*duedate;
	QLineEdit*discount;
	QLineEdit*allowance;
	QLineEdit*header;
	QLineEdit*footer;
	void fill(Invoice* invoice);
Invoice* invoice;
private:
	static ERPDisplay* p_instance;
private slots:
	void addInvoiceStateDate();
	void addInvoiceStateDate(InvoiceStateDate* InvoiceStateDate);
	void removeInvoiceStateDate(QWidget* widget);
	void addInvoiceFreeline();
	void addInvoiceFreeline(InvoiceFreeline* InvoiceFreeline);
	void removeInvoiceFreeline(QWidget* widget);
	void addPayment();
	void addPayment(Payment* Payment);
	void removePayment(QWidget* widget);
	void selectInvoice();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
