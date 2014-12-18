/**************************************************************************
**   File: invoicestatedatecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESTATEDATEUI_H
#define INVOICESTATEDATEUI_H
#include "../../erpdisplay.h"
#include "invoicestatedateui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicestatedate.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoicestatedate.h"
#include "../../Model/invoice.h"
#include "../../Model/invoicestate.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class InvoiceStateDateCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceStateDateCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceStateDateCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*invoice;
	ERPComboBox*invoicestate;
	QDateEdit*date;
	void fill(InvoiceStateDate* invoicestatedate);
InvoiceStateDate* invoicestatedate;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectInvoiceStateDate();
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
