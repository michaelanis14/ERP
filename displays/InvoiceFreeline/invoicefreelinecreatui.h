/**************************************************************************
**   File: invoicefreelinecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEFREELINEUI_H
#define INVOICEFREELINEUI_H
#include "../../erpdisplay.h"
#include "invoicefreelineui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicefreeline.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoicefreeline.h"
#include "../../Model/invoice.h"
#include "../../Model/tax.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class InvoiceFreelineCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceFreelineCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceFreelineCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	ERPComboBox*invoice;
	QLineEdit*price;
	ERPComboBox*tax;
	QLineEdit*amount;
	void fill(InvoiceFreeline* invoicefreeline);
InvoiceFreeline* invoicefreeline;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectInvoiceFreeline();
	void cancel();
	void clear();
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
