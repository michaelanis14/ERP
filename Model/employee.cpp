/**************************************************************************
**   File: employee.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "employee.h"
#include "erpmodel.h"

Employee::Employee()
 : QSqlRelationalTableModel(){

this->EmployeeID = 0 ;
this->Name = "";
this->CreatedOn = "";
this->EditedOn = "";
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
" KEY(Name),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("EmployeeID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
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
this->EditedOn = QDateTime::currentDateTime().toString();
if(EmployeeID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Employee (Name,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Employee SET "	"Name = '"+QString(this->Name)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE EmployeeID ='"+QString::number(this->EmployeeID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  EmployeeID FROM Employee WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->EmployeeID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Employee::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
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
	QList<Employee*> employees =   QList<Employee*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Employee ORDER BY EmployeeID ASC"));
	while (query.next()) {
employees.append(new Employee(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return employees;
}

Employee* Employee::Get(int id) {
Employee* employee = new Employee();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Employee WHERE EmployeeID = '"+QString::number(id)+"' ORDER BY EmployeeID ASC "));
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
	QList<Employee*> employees =   QList<Employee*>();
employees = GetAll();
	for(int i = 0; i <employees.count(); i++){
		list.append(employees[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > Employee::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Employee*> employees =   QList<Employee*>();
employees = GetAll();
	for(int i = 0; i <employees.count(); i++){
		list.append(qMakePair(employees[i]->EmployeeID,employees[i]->Name));
	}
	return list;
}

QList<QPair< int,QString > > Employee::GetPairList(QList<Employee*> employees) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <employees.count(); i++){
		list.append(qMakePair(employees[i]->EmployeeID,employees[i]->Name));
	}
	return list;
}

int Employee::GetIndex(QString name) {
	QList<Employee*> employees =   QList<Employee*>();
employees = GetAll();
	for(int i = 0; i <employees.count(); i++){
		if(employees[i]->Name == name){
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

