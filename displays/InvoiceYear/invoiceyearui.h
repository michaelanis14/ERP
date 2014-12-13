/**************************************************************************
**   File: invoiceyearui.h
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICEYEARUI_H
#define INVOICEYEARUI_H
#include "../../erpdisplay.h"
#include "invoiceyearindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoiceyear.h"
#include "../../Model/invoiceyear.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceYearUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceYearUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceYearUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(InvoiceYear* invoiceyear);
InvoiceYear* invoiceyear;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceYear();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
