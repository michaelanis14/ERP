/**************************************************************************
**   File: employee.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
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
	Employee(QString Name);	int EmployeeID;
	QString Name;
	QList<Employee*> employees;
	static bool init();
	bool save();
	bool remove();
	Employee* get();
	static Employee* get(int id);
	static Employee* get(QString name);
	static QList<Employee*> getAll();
	static QList<Employee*> search(QString keyword);
	static QList<Employee*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Employee* GetInstance();

private:
	Employee(int EmployeeID,QString Name);
	static Employee* p_instance;

};
#endif
