/**************************************************************************
**   File: contacttype.cpp
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contacttype.h"
#include "erpmodel.h"

ContactType::ContactType()
 : QSqlRelationalTableModel(){

this->ContactTypeID = 0 ;
this->Description = " ";
this->setTable("ContactType");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ContactType::ContactType(int ContactTypeID,QString Description) : QSqlRelationalTableModel(){
this->ContactTypeID = ContactTypeID ;
this->Description = Description ;
}

ContactType::ContactType(QString Description) : QSqlRelationalTableModel(){
this->ContactTypeID = 0 ;
this->Description = Description ;
}

bool ContactType::init()
{

QString table = "ContactType";
QString query =
"(ContactTypeID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactTypeID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactType* ContactType::p_instance = 0;
ContactType* ContactType::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactType();
		ContactType::getAll();
	}
return p_instance;
}
bool ContactType::save() {
if(ContactTypeID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactType (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactType SET ""Description = '"+QString(this->Description)+"' WHERE ContactTypeID ='"+QString::number(this->ContactTypeID)+"'");
 }
return true;
}

bool ContactType::remove() {
if(ContactTypeID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactType WHERE ContactTypeID ="+QString::number(this->ContactTypeID)+""));
return true;
 }
return false;
}

ContactType* ContactType::get() {
if(ContactTypeID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactType"
"WHERE ContactTypeID ='"+QString::number(this->ContactTypeID)+"'"));
while (query.next()) {
return new ContactType(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactType();
 }

QList<ContactType*> ContactType::getAll() {
	ContactType::GetInstance()->contacttypes.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"));
	while (query.next()) {
		ContactType::GetInstance()->contacttypes.append(new ContactType(query.value(0).toInt(),query.value(1).toString()));
	}
	return ContactType::GetInstance()->contacttypes;
}

ContactType* ContactType::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactType"
"WHERE ContactTypeID = '"+QString::number(id)+"'"));
while (query.next()) {
return new ContactType(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactType();
 }

ContactType* ContactType::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType WHERE Description = '"+name+"'"));
while (query.next()) {
return new ContactType(query.value(0).toInt(),query.value(1).toString());
 }

}
return new ContactType();
 }

QList<ContactType*> ContactType::search(QString keyword) {
QList<ContactType*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactType(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<QString> ContactType::GetStringList() {
	QList<QString> list;
	int count =ContactType::GetInstance()->contacttypes.count();
	if( count < 2){
		ContactType::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(ContactType::GetInstance()->contacttypes[i]->Description);
	}
	return list;
}

QHash<int,QString> ContactType::GetHashList() {
	QHash<int,QString> list;
	int count =ContactType::GetInstance()->contacttypes.count();
	if( count < 2){
		ContactType::getAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(ContactType::GetInstance()->contacttypes[i]->ContactTypeID,ContactType::GetInstance()->contacttypes[i]->Description);
	}
	return list;
}

int ContactType::GetIndex(QString name) {
	int count =ContactType::GetInstance()->contacttypes.count();
	if( count < 2){
		ContactType::getAll();
	}
	for(int i = 0; i < count; i++){
		if(ContactType::GetInstance()->contacttypes[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactType*> ContactType::querySelect(QString select) {
QList<ContactType*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new ContactType(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactType::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactType::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool ContactType::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactTypeID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactType::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactType!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactType::setDescription(int ContactTypeID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactType set Description = ? where ContactTypeID = ?");
query.addBindValue(Description);
query.addBindValue(ContactTypeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

