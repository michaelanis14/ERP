/**************************************************************************
**   File: paymentui.h
**   Created on: Sat Dec 20 02:32:00 EET 2014
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
#include "../../Model/erpmodel.h"
#include "../../Model/payment.h"
#include "../../Model/paymenttype.h"
#include "../../Model/contact.h"
#include "../../Model/project.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class PaymentUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PaymentUI(QWidget *parent = 0);
	static void ShowUI();
	static PaymentUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*paymenttype;
	ERPComboBox*contact;
	ERPComboBox*project;
	QDateEdit*date;
	QLineEdit*netamount;
	QLineEdit*grossamount;
	QLineEdit*comment;
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
	bool updateModel();
};
#endif
