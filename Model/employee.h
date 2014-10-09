/**************************************************************************
**   File: employee.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QtGui>

class Employee
{
public:
	Employee();
	Employee(QString Name);
	static bool init();
	bool save();
	bool remove();
	Employee* get();
	static Employee* get(int id);
	static Employee* get(QString name);
	static QList<Employee*> getAll();
	static QList<Employee*> search(QString keyword);
	static QList<Employee*> select(QString select);
private:
	Employee(int EmployeeID,QString Name);
	int EmployeeID;
	QString Name;
};
#endif
