/*************************************
**   Created on:  10/18/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef BANKACCOUNTUI_H
#define BANKACCOUNTUI_H

#include "../../erpdisplay.h"
#include "../../Model/contact.h"

#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"

#include "../../Model/contactclass.h"
#include "../../Model/contactperson.h"
#include "../../Model/contactstatus.h"
#include "../../Model/contacttype.h"
#include "../../Model/employee.h"
#include "../../Model/country.h"
#include "../../Model/currency.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPalette>

class BankAccountUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit BankAccountUI(QWidget *parent = 0);
	static void ShowUI();
	static BankAccountUI* GetUI();

private:
	static ERPDisplay* p_instance;
signals:

public slots:

};

#endif // BANKACCOUNTUI_H
