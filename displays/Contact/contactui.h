/**************************************************************************
**   File: contactui.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
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
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contact.h"
#include "../../Model/contact.h"
#include "../../Model/contacttype.h"
#include "../../Model/contactclass.h"
#include "../../Model/country.h"
#include "../../Model/contactstatus.h"
#include "../../Model/employee.h"

#include "../ContactTelephone/contacttelephoneui.h"
#include "../ContactEmail/contactemailui.h"
#include "../BankAccount/bankaccountui.h"
#include "../ContactFieldData/contactfielddataui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
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
	ERPFormBlock* block6Layout;
	ERPFormBlock* block7Layout;
	QList<ContactTelephoneUI*> ContactTelephones;
	QList<ContactEmailUI*> ContactEmails;
	QList<BankAccountUI*> BankAccounts;
	QList<ContactFieldDataUI*> ContactFieldDatas;
	QLineEdit*name;
	QLineEdit*salutation;
	QDateEdit*birthdateordateoffoundation;
	ERPComboBox*contacttype;
	ERPComboBox*contactclass;
	QLineEdit*number;
	QLineEdit*address;
	QLineEdit*postalcode;
	QLineEdit*city;
	ERPComboBox*country;
	ERPComboBox*contactstatus;
	ERPComboBox*employee;
	QLineEdit*website;
	QLineEdit*taxnumber;
	void fill(Contact* contact);
Contact* contact;
private:
	static ERPDisplay* p_instance;
private slots:
	void addContactTelephone();
	void addContactTelephone(ContactTelephone* ContactTelephone);
	void removeContactTelephone(QWidget* widget);
	void addContactEmail();
	void addContactEmail(ContactEmail* ContactEmail);
	void removeContactEmail(QWidget* widget);
	void addBankAccount();
	void addBankAccount(BankAccount* BankAccount);
	void removeBankAccount(QWidget* widget);
	void addContactFieldData();
	void addContactFieldData(ContactFieldData* ContactFieldData);
	void removeContactFieldData(QWidget* widget);
	void selectContact();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
