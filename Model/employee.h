/**************************************************************************
**   File: employee.h
**   Created on: Wed Nov 26 16:22:56 EET 2014
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
	Employee(QString Name,QString CreatedOn,QString EditedOn);	int EmployeeID;
	QString Name;
	QString CreatedOn;
	QString EditedOn;
	QList<Employee*> employees;
	static bool Init();
	bool save();
	bool remove();
	Employee* get();
	Employee* get(const QModelIndex &index);
	static Employee* Get(int id);
	static Employee* Get(QString name);
	static QList<Employee*> GetAll();
	static QList<Employee*> Search(QString keyword);
	static QList<Employee*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Employee* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Employee(int EmployeeID,QString Name,QString CreatedOn,QString EditedOn);	static Employee* p_instance;
	bool setName(int EmployeeID, const QString &name);
	bool setCreatedOn(int EmployeeID, const QString &createdon);
	bool setEditedOn(int EmployeeID, const QString &editedon);

};
#endif
