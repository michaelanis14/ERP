/**************************************************************************
**   File: contactfielddataindexui.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTFIELDDATAINDEXUI_H
#define CONTACTFIELDDATAINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/contactfielddata.h"
#include "../../Model/contact.h"
#include "../../Model/contactfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactFieldDataIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactFieldDataIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactFieldDataIndexUI* GetUI();
ERPTableView *tabel; 
 ContactFieldData *model; 
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
