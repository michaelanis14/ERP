/**************************************************************************
**   File: invoiceserviceui.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESERVICEUI_H
#define INVOICESERVICEUI_H
#include "../../erpdisplay.h"
#include "invoiceserviceindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoiceservice.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoiceservice.h"
#include "../../Model/invoice.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceServiceUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceServiceUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceServiceUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*invoice;
	ERPComboBox*service;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(InvoiceService* invoiceservice);
InvoiceService* invoiceservice;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceService();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
