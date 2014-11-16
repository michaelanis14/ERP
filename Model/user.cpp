/**************************************************************************
**   File: user.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "user.h"
#include "erpmodel.h"

User::User()
 : QSqlRelationalTableModel(){

this->UserID = 0 ;
this->Name = " ";
this->Username = " ";
this->Password = " ";
this->LastLogin = " ";
this->EmployeeID = 0 ;
this->active = 0 ;
this->lastIP = " ";
this->CreatedOn = " ";
this->EditedOn = " ";
this->setTable("User");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(5, QSqlRelation("Employee", "EmployeeID", "Name"));
}
User::User(int UserID,QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->UserID = UserID ;
this->Name = Name ;
this->Username = Username ;
this->Password = Password ;
this->LastLogin = LastLogin ;
this->EmployeeID = EmployeeID ;
this->active = active ;
this->lastIP = lastIP ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

User::User(QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->UserID = 0 ;
this->Name = Name ;
this->Username = Username ;
this->Password = Password ;
this->LastLogin = LastLogin ;
this->EmployeeID = EmployeeID ;
this->active = active ;
this->lastIP = lastIP ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool User::Init()
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
"lastIP VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
User* User::p_instance = 0;
User* User::GetInstance() {
	if (p_instance == 0) {
		p_instance = new User();
		User::GetAll();
	}
return p_instance;
}
bool User::save() {
if(UserID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString(); 
	this->EditedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO User (Name,Username,Password,LastLogin,EmployeeID,active,lastIP,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->Username)+"','"+QString(this->Password)+"','"+QString(this->LastLogin)+"','"+QString::number(this->EmployeeID)+"','"+QString::number(this->active)+"','"+QString(this->lastIP)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE User SET ""Name = '"+QString(this->Name)+"','"+"Username = '"+QString(this->Username)+"','"+"Password = '"+QString(this->Password)+"','"+"LastLogin = '"+QString(this->LastLogin)+"','"+"EmployeeID = '"+QString::number(this->EmployeeID)+"','"+"active = '"+QString::number(this->active)+"','"+"lastIP = '"+QString(this->lastIP)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE UserID ='"+QString::number(this->UserID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  UserID FROM User WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->UserID = query.value(0).toInt();	
 } 
 }
return true;
}

bool User::remove() {
if(UserID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM User WHERE UserID ="+QString::number(this->UserID)+""));
return true;
 }
return false;
}

User* User::get() {
if(UserID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM User"
"WHERE UserID ='"+QString::number(this->UserID)+"'"));
while (query.next()) {
return new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());
 }

}
return new User();
 }

QList<User*> User::GetAll() {
	User::GetInstance()->users.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User"));
	while (query.next()) {
		User::GetInstance()->users.append(new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
	}
	return User::GetInstance()->users;
}

User* User::Get(int id) {
User* user = new User();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM User WHERE UserID = '"+QString::number(id)+"'"));
while (query.next()) {
user = new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());
 }

}
return user;
}

User* User::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new User();
}

User* User::Get(QString name) {
User* user = new User();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User WHERE Name = '"+name+"'"));
while (query.next()) {
user = new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());

 }

}
return user;
 }

QList<User*> User::Search(QString keyword) {
QList<User*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR Username LIKE '%"+keyword+"%'"
"OR Password LIKE '%"+keyword+"%'"
"OR LastLogin LIKE '%"+keyword+"%'"
"OR lastIP LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

QList<QString> User::GetStringList() {
	QList<QString> list;
	int count =User::GetInstance()->users.count();
	if( count < 2){
		User::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.append(User::GetInstance()->users[i]->Name);
	}
	return list;
}

QHash<int,QString> User::GetHashList() {
	QHash<int,QString> list;
	int count =User::GetInstance()->users.count();
	if( count < 2){
		User::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(User::GetInstance()->users[i]->UserID,User::GetInstance()->users[i]->Name);
	}
	return list;
}

int User::GetIndex(QString name) {
	int count =User::GetInstance()->users.count();
	if( count < 2){
		User::GetAll();
	}
	for(int i = 0; i < count; i++){
		if(User::GetInstance()->users[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<User*> User::QuerySelect(QString select) {
QList<User*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM User WHERE "+select+"" ));
while (query.next()) {
list.append(new User(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

Qt::ItemFlags User::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9)
flags |= Qt::ItemIsEditable;
return flags;
}

bool User::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setUsername(id, value.toString());
else if (index.column() == 3)
ok = setPassword(id, value.toString());
else if (index.column() == 4)
ok = setLastLogin(id, value.toString());
else if (index.column() == 5)
ok = setEmployeeID(id, value.toString());
else if (index.column() == 6)
ok = setactive(id, value.toString());
else if (index.column() == 7)
ok = setlastIP(id, value.toString());
else if (index.column() == 8)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 9)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool User::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->UserID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void User::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() User!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Username"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Password"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Last Login"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Employee"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("active"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("lastI P"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool User::setName(int UserID, const QString &Name) {
QSqlQuery query;
query.prepare("update User set Name = ? where UserID = ?");
query.addBindValue(Name);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setUsername(int UserID, const QString &Username) {
QSqlQuery query;
query.prepare("update User set Username = ? where UserID = ?");
query.addBindValue(Username);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setPassword(int UserID, const QString &Password) {
QSqlQuery query;
query.prepare("update User set Password = ? where UserID = ?");
query.addBindValue(Password);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setLastLogin(int UserID, const QString &LastLogin) {
QSqlQuery query;
query.prepare("update User set LastLogin = ? where UserID = ?");
query.addBindValue(LastLogin);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setEmployeeID(int UserID, const QString &EmployeeID) {
QSqlQuery query;
query.prepare("update User set EmployeeID = ? where UserID = ?");
query.addBindValue(EmployeeID);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setactive(int UserID, const QString &active) {
QSqlQuery query;
query.prepare("update User set active = ? where UserID = ?");
query.addBindValue(active);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setlastIP(int UserID, const QString &lastIP) {
QSqlQuery query;
query.prepare("update User set lastIP = ? where UserID = ?");
query.addBindValue(lastIP);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setCreatedOn(int UserID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update User set CreatedOn = ? where UserID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool User::setEditedOn(int UserID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update User set EditedOn = ? where UserID = ?");
query.addBindValue(EditedOn);
query.addBindValue(UserID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

