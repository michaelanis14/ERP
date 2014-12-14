/**************************************************************************
**   File: employeeindexui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef EMPLOYEEINDEXUI_H
#define EMPLOYEEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/employee.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class EmployeeIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit EmployeeIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static EmployeeIndexUI* GetUI();
ERPTableView *tabel; 
 Employee *model; 
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
