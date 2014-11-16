/**************************************************************************
**   File: employee.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "employee.h"
#include "erpmodel.h"

Employee::Employee()
 : QSqlRelationalTableModel(){

this->EmployeeID = 0 ;
this->Name = " ";
this->CreatedOn = " ";
this->EditedOn = " ";
this->setTable("Employee");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Employee::Employee(int EmployeeID,QString Name,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->EmployeeID = EmployeeID ;
this->Name = Name ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Employee::Employee(QString Name,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->EmployeeID = 0 ;
this->Name = Name ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Employee::Init()
{

QString table = "Employee";
QString query =
"(EmployeeID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (EmployeeID),"
"Name VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Employee* Employee::p_instance = 0;
Employee* Employee::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Employee();
		Employee::GetAll();
	}
return p_instance;
}
bool Employee::save() {
if(EmployeeID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString(); 
	this->EditedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Employee (Name,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Employee SET ""Name = '"+QString(this->Name)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE EmployeeID ='"+QString::number(this->EmployeeID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  EmployeeID FROM Employee WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->EmployeeID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Employee::remove() {
if(EmployeeID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Employee WHERE EmployeeID ="+QString::number(this->EmployeeID)+""));
return true;
 }
return false;
}

Employee* Employee::get() {
if(EmployeeID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Employee"
"WHERE EmployeeID ='"+QString::number(this->EmployeeID)+"'"));
while (query.next()) {
return new Employee(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new Employee();
 }

QList<Employee*> Employee::GetAll() {
	Employee::GetInstance()->employees.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee"));
	while (query.next()) {
		Employee::GetInstance()->employees.append(new Employee(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return Employee::GetInstance()->employees;
}

Employee* Employee::Get(int id) {
Employee* employee = new Employee();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Employee WHERE EmployeeID = '"+QString::number(id)+"'"));
while (query.next()) {
employee = new Employee(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return employee;
}

Employee* Employee::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Employee();
}

Employee* Employee::Get(QString name) {
Employee* employee = new Employee();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee WHERE Name = '"+name+"'"));
while (query.next()) {
employee = new Employee(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return employee;
 }

QList<Employee*> Employee::Search(QString keyword) {
QList<Employee*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Employee(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> Employee::GetStringList() {
	QList<QString> list;
	int count =Employee::GetInstance()->employees.count();
	if( count < 2){
		Employee::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Employee::GetInstance()->employees[i]->Name);
	}
	return list;
}

QHash<int,QString> Employee::GetHashList() {
	QHash<int,QString> list;
	int count =Employee::GetInstance()->employees.count();
	if( count < 2){
		Employee::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(Employee::GetInstance()->employees[i]->EmployeeID,Employee::GetInstance()->employees[i]->Name);
	}
	return list;
}

int Employee::GetIndex(QString name) {
	int count =Employee::GetInstance()->employees.count();
	if( count < 2){
		Employee::GetAll();
	}
	for(int i = 0; i < count; i++){
		if(Employee::GetInstance()->employees[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Employee*> Employee::QuerySelect(QString select) {
QList<Employee*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee WHERE "+select+"" ));
while (query.next()) {
list.append(new Employee(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags Employee::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Employee::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Employee::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->EmployeeID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Employee::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Employee!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Employee::setName(int EmployeeID, const QString &Name) {
QSqlQuery query;
query.prepare("update Employee set Name = ? where EmployeeID = ?");
query.addBindValue(Name);
query.addBindValue(EmployeeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Employee::setCreatedOn(int EmployeeID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Employee set CreatedOn = ? where EmployeeID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(EmployeeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Employee::setEditedOn(int EmployeeID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Employee set EditedOn = ? where EmployeeID = ?");
query.addBindValue(EditedOn);
query.addBindValue(EmployeeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

