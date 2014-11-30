/**************************************************************************
**   File: contactpersonemailindexui.h
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONEMAILINDEXUI_H
#define CONTACTPERSONEMAILINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/contactpersonemail.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactPersonEmailIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonEmailIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonEmailIndexUI* GetUI();
QTableView *tabel; 
 ContactPersonEmail *model; 
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
