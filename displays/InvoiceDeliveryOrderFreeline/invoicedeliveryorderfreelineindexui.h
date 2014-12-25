/**************************************************************************
**   File: invoicedeliveryorderfreelineindexui.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEDELIVERYORDERFREELINEINDEXUI_H
#define INVOICEDELIVERYORDERFREELINEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/invoicedeliveryorderfreeline.h"
#include "../../Model/invoice.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class InvoiceDeliveryOrderFreelineIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceDeliveryOrderFreelineIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceDeliveryOrderFreelineIndexUI* GetUI();
ERPTableView *tabel; 
 InvoiceDeliveryOrderFreeline *model; 
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
