/**************************************************************************
**   File: bankaccountui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef BANKACCOUNTUI_H
#define BANKACCOUNTUI_H
#include "../../erpdisplay.h"
#include "bankaccountindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/bankaccount.h"
#include "../../Model/bankaccount.h"
#include "../../Model/country.h"
#include "../../Model/currency.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class BankAccountUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit BankAccountUI(QWidget *parent = 0);
	static void ShowUI();
	static BankAccountUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	ERPComboBox*country;
	QLineEdit*bankcode;
	QLineEdit*bankaddress;
	QLineEdit*accountnumber;
	QLineEdit*accountowner;
	QLineEdit*iban;
	QLineEdit*bic;
	ERPComboBox*currency;
	ERPComboBox*contact;
	void fill(BankAccount* bankaccount);
BankAccount* bankaccount;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectBankAccount();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
