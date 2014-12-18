/**************************************************************************
**   File: invoiceserialcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESERIALUI_H
#define INVOICESERIALUI_H
#include "../../erpdisplay.h"
#include "invoiceserialui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoiceserial.h"
#include "../../Model/erpmodel.h"
#include "../../Model/invoiceserial.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class InvoiceSerialCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceSerialCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceSerialCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*title;
	QLineEdit*serial;
	void fill(InvoiceSerial* invoiceserial);
InvoiceSerial* invoiceserial;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectInvoiceSerial();
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
