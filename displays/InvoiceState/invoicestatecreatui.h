/**************************************************************************
**   File: invoicestatecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESTATEUI_H
#define INVOICESTATEUI_H
#include "../../erpdisplay.h"
#include "invoicestateui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoicestate.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoicestate.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class InvoiceStateCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceStateCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceStateCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(InvoiceState* invoicestate);
InvoiceState* invoicestate;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectInvoiceState();
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
