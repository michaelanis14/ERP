/**************************************************************************
**   File: contacttelephoneindexui.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTTELEPHONEINDEXUI_H
#define CONTACTTELEPHONEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/contacttelephone.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactTelephoneIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactTelephoneIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactTelephoneIndexUI* GetUI();
ERPTableView *tabel; 
 ContactTelephone *model; 
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
