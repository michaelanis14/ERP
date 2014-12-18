/**************************************************************************
**   File: invoiceindexui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
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
#include "../../Model/invoiceperiod.h"
#include "../../Model/invoiceyear.h"
#include "../../Model/project.h"

#include "../InvoiceStateDate/invoicestatedateui.h"
#include "../InvoiceFreeline/invoicefreelineui.h"
#include "../Payment/paymentui.h"

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
