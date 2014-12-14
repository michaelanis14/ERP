/**************************************************************************
**   File: invoiceserialui.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef INVOICESERIALUI_H
#define INVOICESERIALUI_H
#include "../../erpdisplay.h"
#include "invoiceserialindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/invoiceserial.h"
#include "../../Model/invoiceserial.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class InvoiceSerialUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit InvoiceSerialUI(QWidget *parent = 0);
	static void ShowUI();
	static InvoiceSerialUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*title;
	QLineEdit*serial;
	void fill(InvoiceSerial* invoiceserial);
InvoiceSerial* invoiceserial;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectInvoiceSerial();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
