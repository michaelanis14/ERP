/**************************************************************************
**   File: contactui.h
**   Created on: Thu Nov 06 01:32:13 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTUI_H
#define CONTACTUI_H
#include "../../erpdisplay.h"
#include "contactindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/contact.h"
#include "../../Model/contact.h"
#include "../../Model/contacttype.h"
#include "../../Model/contactclass.h"
#include "../../Model/country.h"
#include "../../Model/contactstatus.h"
#include "../../Model/employee.h"

#include "../BankAccount/bankaccountui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class ContactUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	ERPFormBlock* block3Layout;
	ERPFormBlock* block4Layout;
	ERPFormBlock* block5Layout;
	QList<BankAccountUI*> BankAccounts;
	void fill(Contact* contact);

	void clear();
private:
	static ERPDisplay* p_instance;
	Contact* contact = new Contact();
	QLineEdit*personalsalutation;
	QLineEdit*salutation;
	QLineEdit*name;
	QLineEdit*lastname;
	QLineEdit*birthdateordateoffoundation;
	ERPComboBox*contacttype;
	ERPComboBox*contactclass;
	QLineEdit*contactnumber;
	QLineEdit*address;
	QLineEdit*postalcode;
	QLineEdit*city;
	ERPComboBox*country;
	ERPComboBox*contactstatus;
	QCheckBox* active;
	ERPComboBox*employee;
	QLineEdit*phonenum;
	QLineEdit*phonenum2;
	QLineEdit*fax;
	QLineEdit*mobile;
	QLineEdit*email;
	QLineEdit*email2;
	QLineEdit*website;
	QLineEdit*taxnumber;
	QLineEdit*createdon;
	QLineEdit*editedon;
private slots:
	void addBankAccount();
	void addBankAccount(BankAccount* BankAccount);
	void removeBankAccount();
	void selectContact();
	void save();
	void cancel();
};
#endif
