/**************************************************************************
**   File: contactstatus.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactstatus.h"
#include "erpmodel.h"

ContactStatus::ContactStatus()
 : QSqlRelationalTableModel(){

this->ContactStatusID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactStatus");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ContactStatus::ContactStatus(int ContactStatusID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactStatusID = ContactStatusID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactStatus::ContactStatus(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactStatusID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactStatus::Init()
{

QString table = "ContactStatus";
QString query =
"(ContactStatusID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactStatusID),"
"Description VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactStatus* ContactStatus::p_instance = 0;
ContactStatus* ContactStatus::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactStatus();
		ContactStatus::GetAll();
	}
return p_instance;
}
bool ContactStatus::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactStatusID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactStatus (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactStatus SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactStatusID ='"+QString::number(this->ContactStatusID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactStatusID FROM ContactStatus WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactStatusID = query.value(0).toInt();	
 } 
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
return new ContactStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new ContactStatus();
 }

QList<ContactStatus*> ContactStatus::GetAll() {
	QList<ContactStatus*> contactstatuss =   QList<ContactStatus*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"));
	while (query.next()) {
contactstatuss.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
qStableSort(contactstatuss.begin(),contactstatuss.end());
	return contactstatuss;
}

ContactStatus* ContactStatus::Get(int id) {
ContactStatus* contactstatus = new ContactStatus();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactStatus WHERE ContactStatusID = '"+QString::number(id)+"'"));
while (query.next()) {
contactstatus = new ContactStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return contactstatus;
}

ContactStatus* ContactStatus::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactStatus();
}

ContactStatus* ContactStatus::Get(QString name) {
ContactStatus* contactstatus = new ContactStatus();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus WHERE Description = '"+name+"'"));
while (query.next()) {
contactstatus = new ContactStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return contactstatus;
 }

QList<ContactStatus*> ContactStatus::Search(QString keyword) {
QList<ContactStatus*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> ContactStatus::GetStringList() {
	QList<QString> list;
	QList<ContactStatus*> contactstatuss =   QList<ContactStatus*>();
contactstatuss = GetAll();
	for(int i = 0; i <contactstatuss.count(); i++){
		list.append(contactstatuss[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> ContactStatus::GetHashList() {
	QHash<int,QString> list;
	QList<ContactStatus*> contactstatuss =   QList<ContactStatus*>();
contactstatuss = GetAll();
	for(int i = 0; i <contactstatuss.count(); i++){
		list.insert(contactstatuss[i]->ContactStatusID,contactstatuss[i]->Description);
	}
	return list;
}

int ContactStatus::GetIndex(QString name) {
	QList<ContactStatus*> contactstatuss =   QList<ContactStatus*>();
contactstatuss = GetAll();
	for(int i = 0; i <contactstatuss.count(); i++){
		if(contactstatuss[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactStatus*> ContactStatus::QuerySelect(QString select) {
QList<ContactStatus*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactStatus WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactStatus::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
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
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
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
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
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
bool ContactStatus::setCreatedOn(int ContactStatusID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactStatus set CreatedOn = ? where ContactStatusID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactStatus::setEditedOn(int ContactStatusID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactStatus set EditedOn = ? where ContactStatusID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

