/**************************************************************************
**   File: bankaccountcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef BANKACCOUNTUI_H
#define BANKACCOUNTUI_H
#include "../../erpdisplay.h"
#include "bankaccountui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/bankaccount.h"
#include "../../Model/erpmodel.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class BankAccountCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit BankAccountCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static BankAccountCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
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
	void refreshTabel();
private slots:
	void selectBankAccount();
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
