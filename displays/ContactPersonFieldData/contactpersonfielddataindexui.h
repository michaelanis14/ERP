/**************************************************************************
**   File: contactpersonfielddataindexui.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONFIELDDATAINDEXUI_H
#define CONTACTPERSONFIELDDATAINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/contactpersonfielddata.h"
#include "../../Model/contactperson.h"
#include "../../Model/contactpersonfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactPersonFieldDataIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonFieldDataIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonFieldDataIndexUI* GetUI();
ERPTableView *tabel; 
 ContactPersonFieldData *model; 
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
