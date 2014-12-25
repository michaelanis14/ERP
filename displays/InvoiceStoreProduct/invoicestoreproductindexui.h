/**************************************************************************
**   File: invoicestoreproductindexui.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESTOREPRODUCTINDEXUI_H
#define INVOICESTOREPRODUCTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/invoicestoreproduct.h"
#include "../../Model/invoice.h"
#include "../../Model/store.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class InvoiceStoreProductIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceStoreProductIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceStoreProductIndexUI* GetUI();
ERPTableView *tabel; 
 InvoiceStoreProduct *model; 
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
