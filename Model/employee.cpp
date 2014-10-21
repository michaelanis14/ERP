/**************************************************************************
**   File: employee.cpp
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "employee.h"
#include "erpmodel.h"

Employee::Employee()
{

this->EmployeeID = 0 ;
this->Name = " ";
}
Employee::Employee(int EmployeeID,QString Name){
this->EmployeeID = EmployeeID ;
this->Name = Name ;
}

Employee::Employee(QString Name){
this->Name = Name ;
}

bool Employee::init()
{

QString table = "Employee";
QString query =
"(EmployeeID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (EmployeeID),"
"Name VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Employee* Employee::p_instance = 0;
Employee* Employee::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Employee();
		Employee::getAll();
	}
return p_instance;
}
bool Employee::save() {
if(EmployeeID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Employee (Name)"
"VALUES ('" +QString(this->Name)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Employee SET ""Name = '"+QString(this->Name)+"' WHERE EmployeeID ='"+QString::number(this->EmployeeID)+"'");
 }
return true;
}

bool Employee::remove() {
if(EmployeeID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Employee"
"WHERE EmployeeID ='"+QString::number(this->EmployeeID)+"'"));
return true;
 }
return false;
}

Employee* Employee::get() {
if(EmployeeID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Employee"
"WHERE EmployeeID ='"+QString::number(this->EmployeeID)+"'"));
while (query.next()) {
return new Employee(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Employee();
 }

QList<Employee*> Employee::getAll() {
	Employee::GetInstance()->employees.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee"));
	while (query.next()) {
		Employee::GetInstance()->employees.append(new Employee(query.value(0).toInt(),query.value(1).toString()));
	}
	return Employee::GetInstance()->employees;
}

Employee* Employee::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Employee"
"WHERE EmployeeID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Employee(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Employee();
 }

Employee* Employee::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee"
"WHERE Name = '"+name+"'"));
while (query.next()) {
return new Employee(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Employee();
 }

QList<Employee*> Employee::search(QString keyword) {
QList<Employee*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Employee(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<QString> Employee::GetStringList() {
	QList<QString> list;
	int count =Employee::GetInstance()->employees.count();
	if( count < 2){
		Employee::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Employee::GetInstance()->employees[i]->Name);
	}
	return list;
}

int Employee::GetIndex(QString name) {
	int count =Employee::GetInstance()->employees.count();
	if( count < 2){
		Employee::getAll();
	}
	for(int i = 0; i < count; i++){
		if(Employee::GetInstance()->employees[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Employee*> Employee::select(QString select) {
QList<Employee*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Employee(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }
