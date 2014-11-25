/**************************************************************************
**   File: contactpersonindexui.h
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONINDEXUI_H
#define CONTACTPERSONINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/contactperson.h"
#include "../../Model/contactperson.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
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
QTableView *tabel; 
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
};
#endif
