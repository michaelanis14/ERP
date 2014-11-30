/**************************************************************************
**   File: paymentui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PAYMENTUI_H
#define PAYMENTUI_H
#include "../../erpdisplay.h"
#include "paymentindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/payment.h"
#include "../../Model/payment.h"
#include "../../Model/invoice.h"
#include "../../Model/paymenttype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class PaymentUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PaymentUI(QWidget *parent = 0);
	static void ShowUI();
	static PaymentUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*invoice;
	QLineEdit*title;
	QLineEdit*totalamount;
	QLineEdit*comment;
	ERPComboBox*paymenttype;
	void fill(Payment* payment);
Payment* payment;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectPayment();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
