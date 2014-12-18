/**************************************************************************
**   File: invoiceyearcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEYEARUI_H
#define INVOICEYEARUI_H
#include "../../erpdisplay.h"
#include "invoiceyearui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoiceyear.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoiceyear.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class InvoiceYearCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceYearCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceYearCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(InvoiceYear* invoiceyear);
InvoiceYear* invoiceyear;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectInvoiceYear();
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
