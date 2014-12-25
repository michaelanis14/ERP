/**************************************************************************
**   File: invoicefreelineindexui.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEFREELINEINDEXUI_H
#define INVOICEFREELINEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/invoicefreeline.h"
#include "../../Model/invoice.h"
#include "../../Model/tax.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class InvoiceFreelineIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceFreelineIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceFreelineIndexUI* GetUI();
ERPTableView *tabel; 
 InvoiceFreeline *model; 
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
