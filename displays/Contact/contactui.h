/*************************************
**   Created on:  10/9/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef CONTACTUI_H
#define CONTACTUI_H

#include "../../erpdisplay.h"
#include "../BankAccount/bankaccountui.h"
#include "../../Model/contact.h"

#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"

#include "../../Model/contactclass.h"
#include "../../Model/contactperson.h"
#include "../../Model/contactstatus.h"
#include "../../Model/contacttype.h"
#include "../../Model/employee.h"
#include "../../Model/country.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class ContactUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactUI* GetUI();
	ERPFormBlock* block5Layout;
	QList<BankAccountUI*> BankAccounts;

private:
	static ERPDisplay* p_instance;
	Contact* contact;
private slots:
	void addBankAccount();
	void removeBankAccount();




};

#endif // CONTACTUI_H
