/**************************************************************************
**   File: bankaccountindexui.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef BANKACCOUNTINDEXUI_H
#define BANKACCOUNTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/bankaccount.h"
#include "../../Model/country.h"
#include "../../Model/currency.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class BankAccountIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit BankAccountIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static BankAccountIndexUI* GetUI();
ERPTableView *tabel; 
 BankAccount *model; 
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
