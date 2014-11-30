/**************************************************************************
**   File: contacttelephoneindexui.h
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTTELEPHONEINDEXUI_H
#define CONTACTTELEPHONEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/contacttelephone.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
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
QTableView *tabel; 
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
