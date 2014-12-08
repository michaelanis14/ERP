/**************************************************************************
**   File: contactindexui.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTINDEXUI_H
#define CONTACTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
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
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactIndexUI* GetUI();
ERPTableView *tabel; 
 Contact *model; 
 QPushButton* add; 
 QPushButton* remove; 
 QPushButton* edit;
private:
	static ERPDisplay* p_instance;
private slots:
	void addRow(); 
 void removeRow(); 
 void editRow(); 
 void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
