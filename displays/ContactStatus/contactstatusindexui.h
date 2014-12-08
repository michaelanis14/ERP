/**************************************************************************
**   File: contactstatusindexui.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTSTATUSINDEXUI_H
#define CONTACTSTATUSINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/contactstatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactStatusIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactStatusIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactStatusIndexUI* GetUI();
ERPTableView *tabel; 
 ContactStatus *model; 
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
