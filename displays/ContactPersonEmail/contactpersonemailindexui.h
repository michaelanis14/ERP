/**************************************************************************
**   File: contactpersonemailindexui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONEMAILINDEXUI_H
#define CONTACTPERSONEMAILINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/contactpersonemail.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
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
ERPTableView *tabel; 
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
