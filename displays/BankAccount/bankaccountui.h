/**************************************************************************
**   File: bankaccountui.h
**   Created on: Sun Nov 09 16:51:23 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef BANKACCOUNTUI_H
#define BANKACCOUNTUI_H
#include "../../erpdisplay.h"
//#include "bankaccountindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/bankaccount.h"
#include "../../Model/bankaccount.h"
#include "../../Model/currency.h"
#include "../../Model/contact.h"
#include "../../Model/country.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class BankAccountUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit BankAccountUI(QWidget *parent = 0);
	static void ShowUI();
	static BankAccountUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	QLineEdit*bankaddress;
	QLineEdit*bankcode;
	QLineEdit*accountname;
	QLineEdit*accountnumber;
	QLineEdit*iban;
	QLineEdit*bic;
	QLineEdit*zipcode;
	ERPComboBox*currency;
	ERPComboBox*contact;
	ERPComboBox*country;
	QLineEdit*bankcountrycode;
	void fill(BankAccount* bankaccount);
private:
	static ERPDisplay* p_instance;
	BankAccount* bankaccount = new BankAccount();
private slots:
	void selectBankAccount();
	void save();
	void cancel();
	void clear();
};
#endif
