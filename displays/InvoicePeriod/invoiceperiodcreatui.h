/**************************************************************************
**   File: invoiceperiodcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEPERIODUI_H
#define INVOICEPERIODUI_H
#include "../../erpdisplay.h"
#include "invoiceperiodui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoiceperiod.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoiceperiod.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class InvoicePeriodCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoicePeriodCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoicePeriodCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(InvoicePeriod* invoiceperiod);
InvoicePeriod* invoiceperiod;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectInvoicePeriod();
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
