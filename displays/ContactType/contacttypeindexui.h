/**************************************************************************
**   File: contacttypeindexui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTTYPEINDEXUI_H
#define CONTACTTYPEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/contacttype.h"
#include "../../Model/contacttype.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ContactTypeIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactTypeIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactTypeIndexUI* GetUI();
QTableView *tabel; 
 ContactType *model; 
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
