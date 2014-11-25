/**************************************************************************
**   File: contactclassindexui.h
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTCLASSINDEXUI_H
#define CONTACTCLASSINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/contactclass.h"
#include "../../Model/contactclass.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactClassIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactClassIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactClassIndexUI* GetUI();
QTableView *tabel; 
 ContactClass *model; 
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
