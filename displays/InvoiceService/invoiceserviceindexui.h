/**************************************************************************
**   File: invoiceserviceindexui.h
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESERVICEINDEXUI_H
#define INVOICESERVICEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/invoiceservice.h"
#include "../../Model/invoice.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class InvoiceServiceIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceServiceIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceServiceIndexUI* GetUI();
ERPTableView *tabel; 
 InvoiceService *model; 
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
