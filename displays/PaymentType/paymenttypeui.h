/**************************************************************************
**   File: paymenttypeui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PAYMENTTYPEUI_H
#define PAYMENTTYPEUI_H
#include "../../erpdisplay.h"
#include "paymenttypeindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/paymenttype.h"
#include "../../Model/paymenttype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class PaymentTypeUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PaymentTypeUI(QWidget *parent = 0);
	static void ShowUI();
	static PaymentTypeUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(PaymentType* paymenttype);
PaymentType* paymenttype;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectPaymentType();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
