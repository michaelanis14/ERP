/**************************************************************************
**   File: user.cpp
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "user.h"
#include "erpmodel.h"

User::User()
{

this->UserID = 0 ;
this->Name = " ";
this->Username = " ";
this->Password = " ";
this->LastLogin = " ";
this->EmployeeID = 0 ;
this->active = 0 ;
this->lastIP = " ";
}
User::User(int UserID,QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP){
this->UserID = UserID ;
this->Name = Name ;
this->Username = Username ;
this->Password = Password ;
this->LastLogin = LastLogin ;
this->EmployeeID = EmployeeID ;
this->active = active ;
this->lastIP = lastIP ;
}

User::User(QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP){
this->Name = Name ;
this->Username = Username ;
this->Password = Password ;
this->LastLogin = LastLogin ;
this->EmployeeID = EmployeeID ;
this->active = active ;
this->lastIP = lastIP ;
}

bool User::init()
{

QString table = "User";
QString query =
"(UserID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (UserID),"
"Name VARCHAR(40) NOT NULL, "
"Username VARCHAR(40) NOT NULL, "
"Password VARCHAR(40) NOT NULL, "
"LastLogin VARCHAR(40) NOT NULL, "
"EmployeeID INT NOT NULL, "
"FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID),"
"active VARCHAR(1) NOT NULL, "
"lastIP VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
User* User::p_instance = 0;
User* User::GetInstance() {
	if (p_instance == 0) {
		p_instance = new User();
		User::getAll();
	}
return p_instance;
}
bool User::save() {
if(UserID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO User (Name,Username,Password,LastLogin,EmployeeID,active,lastIP)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->Username)+"','"+QString(this->Password)+"','"+QString(this->LastLogin)+"','"+QString::number(this->EmployeeID)+"','"+QString::number(this->active)+"','"+QString(this->lastIP)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE User SET ""Name = '"+QString(this->Name)+"','"+"Username = '"+QString(this->Username)+"','"+"Password = '"+QString(this->Password)+"','"+"LastLogin = '"+QString(this->LastLogin)+"','"+"EmployeeID = '"+QString::number(this->EmployeeID)+"','"+"active = '"+QString::number(this->active)+"','"+"lastIP = '"+QString(this->lastIP)+"' WHERE UserID ='"+QString::number(this->UserID)+"'");
 }
return true;
}

bool User::remove() {
if(UserID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM User"
"WHERE UserID ='"+QString::number(this->UserID)+"'"));
return true;
 }
return false;
}

User* User::get() {
if(UserID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM User"
"WHERE UserID ='"+QString::number(this->UserID)+"'"));
while (query.next()) {
return new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString());
 }

}
return new User();
 }

QList<User*> User::getAll() {
	User::GetInstance()->users.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User"));
	while (query.next()) {
		User::GetInstance()->users.append(new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString()));
	}
	return User::GetInstance()->users;
}

User* User::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM User"
"WHERE UserID = '"+QString::number(id)+"'"));
while (query.next()) {
return new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString());
 }

}
return new User();
 }

User* User::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User"
"WHERE Name = '"+name+"'"));
while (query.next()) {
return new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString());
 }

}
return new User();
 }

QList<User*> User::search(QString keyword) {
QList<User*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR Username LIKE '%"+keyword+"%'"
"OR Password LIKE '%"+keyword+"%'"
"OR LastLogin LIKE '%"+keyword+"%'"
"OR lastIP LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString()));
 }

}
return list;
 }

QList<QString> User::GetStringList() {
	QList<QString> list;
	int count =User::GetInstance()->users.count();
	if( count < 2){
		User::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(User::GetInstance()->users[i]->Name);
	}
	return list;
}

int User::GetIndex(QString name) {
	int count =User::GetInstance()->users.count();
	if( count < 2){
		User::getAll();
	}
	for(int i = 0; i < count; i++){
		if(User::GetInstance()->users[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<User*> User::select(QString select) {
QList<User*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString()));
 }

}
return list;
 }
