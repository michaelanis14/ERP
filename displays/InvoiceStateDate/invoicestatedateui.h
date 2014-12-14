/**************************************************************************
**   File: invoicestatedateui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESTATEDATEUI_H
#define INVOICESTATEDATEUI_H
#include "../../erpdisplay.h"
#include "invoicestatedateindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicestatedate.h"
#include "../../Model/invoicestatedate.h"
#include "../../Model/invoice.h"
#include "../../Model/invoicestate.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceStateDateUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceStateDateUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceStateDateUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*invoice;
	ERPComboBox*invoicestate;
	QDateEdit*date;
	void fill(InvoiceStateDate* invoicestatedate);
InvoiceStateDate* invoicestatedate;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceStateDate();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
