/**************************************************************************
**   File: contactpersonindexui.h
**   Created on: Sun Dec 14 22:39:13 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONINDEXUI_H
#define CONTACTPERSONINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/contactperson.h"
#include "../../Model/contact.h"

#include "../ContactPersonTelephone/contactpersontelephoneui.h"
#include "../ContactPersonEmail/contactpersonemailui.h"
#include "../ProjectContactPerson/projectcontactpersonui.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactPersonIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonIndexUI* GetUI();
ERPTableView *tabel; 
 ContactPerson *model; 
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
