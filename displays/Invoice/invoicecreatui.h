/**************************************************************************
**   File: invoicecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEUI_H
#define INVOICEUI_H
#include "../../erpdisplay.h"
#include "invoiceui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoice.h"
#include "../../Model/erpmodel.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class InvoiceCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	InvoiceStateDateUI* InvoiceStateDateui;
	QList<InvoiceStateDateUI*> InvoiceStateDates;
	AddRemoveButtons* addremoveInvoiceStateDateBtn;
	InvoiceFreelineUI* InvoiceFreelineui;
	QList<InvoiceFreelineUI*> InvoiceFreelines;
	AddRemoveButtons* addremoveInvoiceFreelineBtn;
	PaymentUI* Paymentui;
	QList<PaymentUI*> Payments;
	AddRemoveButtons* addremovePaymentBtn;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
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
	void refreshTabel();
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
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
