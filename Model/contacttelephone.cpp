/**************************************************************************
**   File: contacttelephone.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contacttelephone.h"
#include "erpmodel.h"

ContactTelephone::ContactTelephone()
 : QSqlRelationalTableModel(){

this->ContactTelephoneID = 0 ;
this->Description = "";
this->Number = 0 ;
this->ContactID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactTelephone");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("Contact", "ContactID", "Name"));
}
ContactTelephone::ContactTelephone(int ContactTelephoneID,QString Description,int Number,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactTelephoneID = ContactTelephoneID ;
this->Description = Description ;
this->Number = Number ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactTelephone::ContactTelephone(QString Description,int Number,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactTelephoneID = 0 ;
this->Description = Description ;
this->Number = Number ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactTelephone::Init()
{

QString table = "ContactTelephone";
QString query =
"(ContactTelephoneID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactTelephoneID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"Number INT NOT NULL, "
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactTelephone* ContactTelephone::p_instance = 0;
ContactTelephone* ContactTelephone::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactTelephone();
		ContactTelephone::GetAll();
	}
return p_instance;
}
bool ContactTelephone::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactTelephoneID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactTelephone (Description,Number,ContactID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString::number(this->Number)+"','"+QString::number(this->ContactID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactTelephone SET "	"Description = '"+QString(this->Description)+"',"+"Number = '"+QString::number(this->Number)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactTelephoneID ='"+QString::number(this->ContactTelephoneID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactTelephoneID FROM ContactTelephone WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactTelephoneID = query.value(0).toInt();	
 } 
 }
return true;
}

bool ContactTelephone::remove() {
if(ContactTelephoneID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactTelephone WHERE ContactTelephoneID ="+QString::number(this->ContactTelephoneID)+""));
return true;
 }
return false;
}

ContactTelephone* ContactTelephone::get() {
if(ContactTelephoneID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactTelephone"
"WHERE ContactTelephoneID ='"+QString::number(this->ContactTelephoneID)+"'"));
while (query.next()) {
return new ContactTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ContactTelephone();
 }

QList<ContactTelephone*> ContactTelephone::GetAll() {
	QList<ContactTelephone*> contacttelephones =   QList<ContactTelephone*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactTelephone"));
	while (query.next()) {
contacttelephones.append(new ContactTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
qStableSort(contacttelephones.begin(),contacttelephones.end());
	return contacttelephones;
}

ContactTelephone* ContactTelephone::Get(int id) {
ContactTelephone* contacttelephone = new ContactTelephone();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactTelephone WHERE ContactTelephoneID = '"+QString::number(id)+"'"));
while (query.next()) {
contacttelephone = new ContactTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return contacttelephone;
}

ContactTelephone* ContactTelephone::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactTelephone();
}

ContactTelephone* ContactTelephone::Get(QString name) {
ContactTelephone* contacttelephone = new ContactTelephone();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactTelephone WHERE Description = '"+name+"'"));
while (query.next()) {
contacttelephone = new ContactTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return contacttelephone;
 }

QList<ContactTelephone*> ContactTelephone::Search(QString keyword) {
QList<ContactTelephone*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactTelephone"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ContactTelephone::GetStringList() {
	QList<QString> list;
	QList<ContactTelephone*> contacttelephones =   QList<ContactTelephone*>();
contacttelephones = GetAll();
	for(int i = 0; i <contacttelephones.count(); i++){
		list.append(contacttelephones[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> ContactTelephone::GetHashList() {
	QHash<int,QString> list;
	QList<ContactTelephone*> contacttelephones =   QList<ContactTelephone*>();
contacttelephones = GetAll();
	for(int i = 0; i <contacttelephones.count(); i++){
		list.insert(contacttelephones[i]->ContactTelephoneID,contacttelephones[i]->Description);
	}
	return list;
}

int ContactTelephone::GetIndex(QString name) {
	QList<ContactTelephone*> contacttelephones =   QList<ContactTelephone*>();
contacttelephones = GetAll();
	for(int i = 0; i <contacttelephones.count(); i++){
		if(contacttelephones[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactTelephone*> ContactTelephone::QuerySelect(QString select) {
QList<ContactTelephone*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactTelephone WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactTelephone::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactTelephone::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setNumber(id, value.toString());
else if (index.column() == 3)
ok = setContactID(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ContactTelephone::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactTelephoneID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactTelephone::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactTelephone!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Number"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactTelephone::setDescription(int ContactTelephoneID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactTelephone set Description = ? where ContactTelephoneID = ?");
query.addBindValue(Description);
query.addBindValue(ContactTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactTelephone::setNumber(int ContactTelephoneID, const QString &Number) {
QSqlQuery query;
query.prepare("update ContactTelephone set Number = ? where ContactTelephoneID = ?");
query.addBindValue(Number);
query.addBindValue(ContactTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactTelephone::setContactID(int ContactTelephoneID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update ContactTelephone set ContactID = ? where ContactTelephoneID = ?");
query.addBindValue(ContactID);
query.addBindValue(ContactTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactTelephone::setCreatedOn(int ContactTelephoneID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactTelephone set CreatedOn = ? where ContactTelephoneID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactTelephone::setEditedOn(int ContactTelephoneID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactTelephone set EditedOn = ? where ContactTelephoneID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

