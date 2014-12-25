/**************************************************************************
**   File: login.cpp
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "login.h"
#include "erpmodel.h"

Login::Login()
 : QSqlRelationalTableModel(){

this->LoginID = 0 ;
this->UserName = "";
this->Password = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Login");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Login::Login(int LoginID,QString UserName,QString Password,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->LoginID = LoginID ;
this->UserName = UserName ;
this->Password = Password ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Login::Login(QString UserName,QString Password,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->LoginID = 0 ;
this->UserName = UserName ;
this->Password = Password ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Login::Init()
{

QString table = "Login";
QString query =
"(LoginID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (LoginID),"
"UserName VARCHAR(40) NOT NULL, "
" KEY(UserName),"
"Password VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("LoginID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("UserName")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Password")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Login* Login::p_instance = 0;
Login* Login::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Login();
		Login::GetAll();
	}
return p_instance;
}
bool Login::save() {
this->EditedOn = QDate::currentDate().toString();
if(LoginID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Login (UserName,Password,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->UserName)+"','"+QString(this->Password)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Login SET "	"UserName = '"+QString(this->UserName)+"',"+"Password = '"+QString(this->Password)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE LoginID ='"+QString::number(this->LoginID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  LoginID FROM Login WHERE UserName = '"+UserName+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->LoginID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Login::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Login::remove() {
if(LoginID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Login WHERE LoginID ="+QString::number(this->LoginID)+""));
return true;
 }
return false;
}

Login* Login::get() {
if(LoginID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Login"
"WHERE LoginID ='"+QString::number(this->LoginID)+"'"));
while (query.next()) {
return new Login(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
 }

}
return new Login();
 }

QList<Login*> Login::GetAll() {
	QList<Login*> logins =   QList<Login*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Login ORDER BY LoginID ASC"));
	while (query.next()) {
logins.append(new Login(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
	}
	return logins;
}

Login* Login::Get(int id) {
Login* login = new Login();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Login WHERE LoginID = '"+QString::number(id)+"' ORDER BY LoginID ASC "));
while (query.next()) {
login = new Login(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
 }

}
return login;
}

Login* Login::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Login();
}

Login* Login::Get(QString name) {
Login* login = new Login();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Login WHERE UserName = '"+name+"'"));
while (query.next()) {
login = new Login(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());

 }

}
return login;
 }

QList<Login*> Login::Search(QString keyword) {
QList<Login*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Login"
"WHERE" 
"UserName LIKE '%"+keyword+"%'"
"OR Password LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Login(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> Login::GetStringList() {
	QList<QString> list;
	QList<Login*> logins =   QList<Login*>();
logins = GetAll();
	for(int i = 0; i <logins.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > Login::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Login*> logins =   QList<Login*>();
logins = GetAll();
	for(int i = 0; i <logins.count(); i++){
		list.append(qMakePair(logins[i]->LoginID,logins[i]->UserName));
	}
	return list;
}

QList<QPair< int,QString > > Login::GetPairList(QList<Login*> logins) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <logins.count(); i++){
		list.append(qMakePair(logins[i]->LoginID,logins[i]->UserName));
	}
	return list;
}

int Login::GetIndex(QString name) {
	QList<Login*> logins =   QList<Login*>();
logins = GetAll();
	for(int i = 0; i <logins.count(); i++){
		if(logins[i]->UserName == name){
			return i;
		}
	}
	return 0;
}

QList<Login*> Login::QuerySelect(QString select) {
QList<Login*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Login WHERE "+select+"" ));
while (query.next()) {
list.append(new Login(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags Login::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Login::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setUserName(id, value.toString());
else if (index.column() == 2)
ok = setPassword(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Login::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->LoginID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Login::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Login!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("User Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Password"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Login::setUserName(int LoginID, const QString &UserName) {
QSqlQuery query;
query.prepare("update Login set UserName = ? where LoginID = ?");
query.addBindValue(UserName);
query.addBindValue(LoginID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Login::setPassword(int LoginID, const QString &Password) {
QSqlQuery query;
query.prepare("update Login set Password = ? where LoginID = ?");
query.addBindValue(Password);
query.addBindValue(LoginID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Login::setCreatedOn(int LoginID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Login set CreatedOn = ? where LoginID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(LoginID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Login::setEditedOn(int LoginID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Login set EditedOn = ? where LoginID = ?");
query.addBindValue(EditedOn);
query.addBindValue(LoginID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

