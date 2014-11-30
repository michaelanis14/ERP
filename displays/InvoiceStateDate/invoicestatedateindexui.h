/**************************************************************************
**   File: invoicestatedateindexui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESTATEDATEINDEXUI_H
#define INVOICESTATEDATEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/invoicestatedate.h"
#include "../../Model/invoice.h"
#include "../../Model/invoicestate.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class InvoiceStateDateIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceStateDateIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceStateDateIndexUI* GetUI();
QTableView *tabel; 
 InvoiceStateDate *model; 
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
