/**************************************************************************
**   File: invoicefreelineui.h
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEFREELINEUI_H
#define INVOICEFREELINEUI_H
#include "../../erpdisplay.h"
#include "invoicefreelineindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicefreeline.h"
#include "../../Model/invoicefreeline.h"
#include "../../Model/invoice.h"
#include "../../Model/tax.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceFreelineUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceFreelineUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceFreelineUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	ERPComboBox*invoice;
	QLineEdit*price;
	ERPComboBox*tax;
	QLineEdit*amount;
	void fill(InvoiceFreeline* invoicefreeline);
InvoiceFreeline* invoicefreeline;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceFreeline();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
