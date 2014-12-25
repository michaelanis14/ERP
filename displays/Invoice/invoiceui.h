/**************************************************************************
**   File: invoiceui.h
**   Created on: Fri Dec 19 22:39:36 EET 2014
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
#include "../../Model/erpmodel.h"
#include "../../Model/invoice.h"
#include "../../Model/invoiceserial.h"
#include "../../Model/contact.h"
#include "../../Model/project.h"
#include "../../Model/invoiceperiod.h"
#include "../../Model/invoiceyear.h"
#include "../../Model/deliveryorder.h"


#include "../InvoiceStoreProduct/invoicestoreproductui.h"
#include "../InvoiceService/invoiceserviceui.h"
#include "../InvoiceDeliveryOrderFreeline/invoicedeliveryorderfreelineui.h"
#include "../InvoiceFreeline/invoicefreelineui.h"

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
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	ERPFormBlock* block3Layout;
	ERPFormBlock* block4Layout;
	ERPFormBlock* block5Layout;
	ERPFormBlock* block6Layout;
	ERPFormBlock* block7Layout;
	ERPFormBlock* block8Layout;
	QList<InvoiceStoreProductUI*> InvoiceStoreProducts;
	QList<InvoiceServiceUI*> InvoiceServices;
	QList<InvoiceDeliveryOrderFreelineUI*> InvoiceDeliveryOrderFreelines;
	QList<InvoiceFreelineUI*> InvoiceFreelines;
	QLineEdit*serial;
	ERPComboBox*invoiceserial;
	ERPComboBox*contact;
	ERPComboBox*project;
	QDateEdit*date;
	ERPComboBox*invoiceperiod;
	ERPComboBox*invoiceyear;
	QDateEdit*duedate;
	QLineEdit*discount;
	QLineEdit*allowance;
	QLineEdit*header;
	QLineEdit*footer;
	QLineEdit*note;
	void fill(Invoice* invoice);
Invoice* invoice;
private:
	static ERPDisplay* p_instance;
private slots:
	void addInvoiceStoreProduct();
	void addInvoiceStoreProduct(InvoiceStoreProduct* InvoiceStoreProduct);
	void removeInvoiceStoreProduct(QWidget* widget);
	void addInvoiceService();
	void addInvoiceService(InvoiceService* InvoiceService);
	void removeInvoiceService(QWidget* widget);
	void addInvoiceDeliveryOrderFreeline();
	void addInvoiceDeliveryOrderFreeline(InvoiceDeliveryOrderFreeline* InvoiceDeliveryOrderFreeline);
	void removeInvoiceDeliveryOrderFreeline(QWidget* widget);
	void addInvoiceFreeline();
	void addInvoiceFreeline(InvoiceFreeline* InvoiceFreeline);
	void removeInvoiceFreeline(QWidget* widget);
	void selectInvoice();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
	void selectionChanged(QString);
};
#endif
