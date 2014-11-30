/**************************************************************************
**   File: invoiceindexui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEINDEXUI_H
#define INVOICEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/invoice.h"
#include "../../Model/invoiceperiod.h"
#include "../../Model/invoiceyear.h"
#include "../../Model/project.h"

#include "../InvoiceStateDate/invoicestatedateui.h"
#include "../InvoiceFreeline/invoicefreelineui.h"
#include "../Payment/paymentui.h"

#include <QWidget>
#include <QLineEdit>
#include <QTableView>
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
QTableView *tabel; 
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
