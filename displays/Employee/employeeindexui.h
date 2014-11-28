/**************************************************************************
**   File: employeeindexui.h
**   Created on: Wed Nov 26 16:22:56 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef EMPLOYEEINDEXUI_H
#define EMPLOYEEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/employee.h"
#include "../../Model/employee.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
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
QTableView *tabel; 
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
