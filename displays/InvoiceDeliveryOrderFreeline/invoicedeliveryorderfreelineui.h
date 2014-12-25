/**************************************************************************
**   File: invoicedeliveryorderfreelineui.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEDELIVERYORDERFREELINEUI_H
#define INVOICEDELIVERYORDERFREELINEUI_H
#include "../../erpdisplay.h"
#include "invoicedeliveryorderfreelineindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicedeliveryorderfreeline.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoicedeliveryorderfreeline.h"
#include "../../Model/invoice.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceDeliveryOrderFreelineUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceDeliveryOrderFreelineUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceDeliveryOrderFreelineUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*invoice;
	QLineEdit*description;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(InvoiceDeliveryOrderFreeline* invoicedeliveryorderfreeline);
InvoiceDeliveryOrderFreeline* invoicedeliveryorderfreeline;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceDeliveryOrderFreeline();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
