/**************************************************************************
**   File: invoiceindexui.h
**   Created on: Fri Dec 19 22:39:36 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEINDEXUI_H
#define INVOICEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/invoice.h"
#include "../../Model/invoiceserial.h"
#include "../../Model/contact.h"
#include "../../Model/project.h"
#include "../../Model/invoiceperiod.h"
#include "../../Model/invoiceyear.h"

#include "../InvoiceStoreProduct/invoicestoreproductui.h"
#include "../InvoiceService/invoiceserviceui.h"
#include "../InvoiceDeliveryOrderFreeline/invoicedeliveryorderfreelineui.h"
#include "../InvoiceFreeline/invoicefreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class InvoiceIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceIndexUI* GetUI();
ERPTableView *tabel; 
 Invoice *model; 
 QPushButton* add; 
 QPushButton* remove; 
 QPushButton* edit;
private:
	static ERPDisplay* p_instance;
private slots:
	void addRow(); 
 void removeRow(); 
 void editRow(); 
 void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
