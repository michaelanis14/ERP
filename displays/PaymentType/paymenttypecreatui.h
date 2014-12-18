/**************************************************************************
**   File: paymenttypecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PAYMENTTYPEUI_H
#define PAYMENTTYPEUI_H
#include "../../erpdisplay.h"
#include "paymenttypeui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/paymenttype.h"
#include "../../Model/erpmodel.h"
#include "../../Model/paymenttype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class PaymentTypeCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PaymentTypeCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static PaymentTypeCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(PaymentType* paymenttype);
PaymentType* paymenttype;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectPaymentType();
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
