/**************************************************************************
**   File: paymentcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PAYMENTUI_H
#define PAYMENTUI_H
#include "../../erpdisplay.h"
#include "paymentui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/payment.h"
#include "../../Model/erpmodel.h"
#include "../../Model/payment.h"
#include "../../Model/invoice.h"
#include "../../Model/paymenttype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class PaymentCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PaymentCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static PaymentCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*invoice;
	QLineEdit*totalamount;
	QLineEdit*comment;
	ERPComboBox*paymenttype;
	void fill(Payment* payment);
Payment* payment;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectPayment();
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
