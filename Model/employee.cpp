/**************************************************************************
**   File: employee.cpp
**   Created on: Fri Sep 26 22:51:30 EET 2014
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
QList<Employee*>list;
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee"));
while (query.next()) {
list.append(new Employee(query.value(0).toInt(),query.value(1).toString()));
}
return list;
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
