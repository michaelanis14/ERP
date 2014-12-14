/**************************************************************************
**   File: contactpersonfieldindexui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONFIELDINDEXUI_H
#define CONTACTPERSONFIELDINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/contactpersonfield.h"
#include "../../Model/fieldtype.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactPersonFieldIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonFieldIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonFieldIndexUI* GetUI();
ERPTableView *tabel; 
 ContactPersonField *model; 
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
