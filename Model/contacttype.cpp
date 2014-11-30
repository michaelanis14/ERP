/**************************************************************************
**   File: contacttype.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contacttype.h"
#include "erpmodel.h"

ContactType::ContactType()
 : QSqlRelationalTableModel(){

this->ContactTypeID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactType");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ContactType::ContactType(int ContactTypeID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactTypeID = ContactTypeID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactType::ContactType(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactTypeID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactType::Init()
{

QString table = "ContactType";
QString query =
"(ContactTypeID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactTypeID),"
"Description VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactType* ContactType::p_instance = 0;
ContactType* ContactType::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactType();
		ContactType::GetAll();
	}
return p_instance;
}
bool ContactType::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactTypeID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactType (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactType SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactTypeID ='"+QString::number(this->ContactTypeID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactTypeID FROM ContactType WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactTypeID = query.value(0).toInt();	
 } 
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
return new ContactType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new ContactType();
 }

QList<ContactType*> ContactType::GetAll() {
	QList<ContactType*> contacttypes =   QList<ContactType*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"));
	while (query.next()) {
contacttypes.append(new ContactType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
qSort(contacttypes);
	return contacttypes;
}

ContactType* ContactType::Get(int id) {
ContactType* contacttype = new ContactType();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactType WHERE ContactTypeID = '"+QString::number(id)+"'"));
while (query.next()) {
contacttype = new ContactType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return contacttype;
}

ContactType* ContactType::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactType();
}

ContactType* ContactType::Get(QString name) {
ContactType* contacttype = new ContactType();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType WHERE Description = '"+name+"'"));
while (query.next()) {
contacttype = new ContactType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return contacttype;
 }

QList<ContactType*> ContactType::Search(QString keyword) {
QList<ContactType*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> ContactType::GetStringList() {
	QList<QString> list;
	QList<ContactType*> contacttypes =   QList<ContactType*>();
contacttypes = GetAll();
	for(int i = 0; i <contacttypes.count(); i++){
		list.append(contacttypes[i]->Description);
	}
	qSort(list);
	return list;
}

QHash<int,QString> ContactType::GetHashList() {
	QHash<int,QString> list;
	QList<ContactType*> contacttypes =   QList<ContactType*>();
contacttypes = GetAll();
	for(int i = 0; i <contacttypes.count(); i++){
		list.insert(contacttypes[i]->ContactTypeID,contacttypes[i]->Description);
	}
	return list;
}

int ContactType::GetIndex(QString name) {
	QList<ContactType*> contacttypes =   QList<ContactType*>();
contacttypes = GetAll();
	for(int i = 0; i <contacttypes.count(); i++){
		if(contacttypes[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactType*> ContactType::QuerySelect(QString select) {
QList<ContactType*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactType WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactType::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
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
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
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
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
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
bool ContactType::setCreatedOn(int ContactTypeID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactType set CreatedOn = ? where ContactTypeID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactTypeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactType::setEditedOn(int ContactTypeID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactType set EditedOn = ? where ContactTypeID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactTypeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

