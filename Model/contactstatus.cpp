/**************************************************************************
**   File: contactstatus.cpp
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactstatus.h"
#include "erpmodel.h"

ContactStatus::ContactStatus()
 : QSqlRelationalTableModel(){

this->ContactStatusID = 0 ;
this->Description = " ";
this->setTable("ContactStatus");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ContactStatus::ContactStatus(int ContactStatusID,QString Description) : QSqlRelationalTableModel(){
this->ContactStatusID = ContactStatusID ;
this->Description = Description ;
}

ContactStatus::ContactStatus(QString Description) : QSqlRelationalTableModel(){
this->ContactStatusID = 0 ;
this->Description = Description ;
}

bool ContactStatus::init()
{

QString table = "ContactStatus";
QString query =
"(ContactStatusID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactStatusID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactStatus* ContactStatus::p_instance = 0;
ContactStatus* ContactStatus::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactStatus();
		ContactStatus::getAll();
	}
return p_instance;
}
bool ContactStatus::save() {
if(ContactStatusID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactStatus (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactStatus SET ""Description = '"+QString(this->Description)+"' WHERE ContactStatusID ='"+QString::number(this->ContactStatusID)+"'");
 }
return true;
}

bool ContactStatus::remove() {
if(ContactStatusID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactStatus WHERE ContactStatusID ="+QString::number(this->ContactStatusID)+""));
return true;
 }
return false;
}

ContactStatus* ContactStatus::get() {
if(ContactStatusID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactStatus"
"WHERE ContactStatusID ='"+QString::number(this->ContactStatusID)+"'"));
while (query.next()) {
return new ContactStatus(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactStatus();
 }

QList<ContactStatus*> ContactStatus::getAll() {
	ContactStatus::GetInstance()->contactstatuss.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"));
	while (query.next()) {
		ContactStatus::GetInstance()->contactstatuss.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString()));
	}
	return ContactStatus::GetInstance()->contactstatuss;
}

ContactStatus* ContactStatus::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactStatus"
"WHERE ContactStatusID = '"+QString::number(id)+"'"));
while (query.next()) {
return new ContactStatus(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactStatus();
 }

ContactStatus* ContactStatus::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus WHERE Description = '"+name+"'"));
while (query.next()) {
return new ContactStatus(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactStatus();
 }

QList<ContactStatus*> ContactStatus::search(QString keyword) {
QList<ContactStatus*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<QString> ContactStatus::GetStringList() {
	QList<QString> list;
	int count =ContactStatus::GetInstance()->contactstatuss.count();
	if( count < 2){
		ContactStatus::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(ContactStatus::GetInstance()->contactstatuss[i]->Description);
	}
	return list;
}

QHash<int,QString> ContactStatus::GetHashList() {
	QHash<int,QString> list;
	int count =ContactStatus::GetInstance()->contactstatuss.count();
	if( count < 2){
		ContactStatus::getAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(ContactStatus::GetInstance()->contactstatuss[i]->ContactStatusID,ContactStatus::GetInstance()->contactstatuss[i]->Description);
	}
	return list;
}

int ContactStatus::GetIndex(QString name) {
	int count =ContactStatus::GetInstance()->contactstatuss.count();
	if( count < 2){
		ContactStatus::getAll();
	}
	for(int i = 0; i < count; i++){
		if(ContactStatus::GetInstance()->contactstatuss[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactStatus*> ContactStatus::querySelect(QString select) {
QList<ContactStatus*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactStatus::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactStatus::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
refresh();
}
return ok;
}

bool ContactStatus::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactStatusID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactStatus::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactStatus!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactStatus::setDescription(int ContactStatusID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactStatus set Description = ? where ContactStatusID = ?");
query.addBindValue(Description);
query.addBindValue(ContactStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

