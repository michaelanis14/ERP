/**************************************************************************
**   File: invoicestateui.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESTATEUI_H
#define INVOICESTATEUI_H
#include "../../erpdisplay.h"
#include "invoicestateindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicestate.h"
#include "../../Model/invoicestate.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceStateUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceStateUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceStateUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(InvoiceState* invoicestate);
InvoiceState* invoicestate;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceState();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
