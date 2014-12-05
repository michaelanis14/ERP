/**************************************************************************
**   File: invoiceperiodindexui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEPERIODINDEXUI_H
#define INVOICEPERIODINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/invoiceperiod.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class InvoicePeriodIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoicePeriodIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoicePeriodIndexUI* GetUI();
ERPTableView *tabel; 
 InvoicePeriod *model; 
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
