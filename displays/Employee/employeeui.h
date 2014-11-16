/**************************************************************************
**   File: employeeui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H
#include "../../erpdisplay.h"
#include "employeeindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/employee.h"
#include "../../Model/employee.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class EmployeeUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit EmployeeUI(QWidget *parent = 0);
	static void ShowUI();
	static EmployeeUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	void fill(Employee* employee);
	Employee* employee = new Employee();
private:
	static ERPDisplay* p_instance;
private slots:
	void selectEmployee();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
