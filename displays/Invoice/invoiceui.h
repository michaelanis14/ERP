/**************************************************************************
**   File: invoiceui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
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
#include "../../Model/invoiceserial.h"
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
#include <QDateEdit>
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
	ERPComboBox*invoiceserial;
	QDateEdit*creationdate;
	QDateEdit*enddate;
	ERPComboBox*invoiceperiod;
	ERPComboBox*invoiceyear;
	ERPComboBox*project;
	QDateEdit*duedate;
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
	bool updateModel();
};
#endif
