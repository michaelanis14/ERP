/**************************************************************************
**   File: employee.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Employee  : public QSqlRelationalTableModel
{
	Q_OBJECT
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
	static QList<Employee*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Employee* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Employee(int EmployeeID,QString Name);	static Employee* p_instance;
	bool setName(int EmployeeID, const QString &name);

};
#endif
