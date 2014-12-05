/**************************************************************************
**   File: contactperson.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactperson.h"
#include "erpmodel.h"

ContactPerson::ContactPerson()
 : QSqlRelationalTableModel(){

this->ContactPersonID = 0 ;
this->ContactID = 0 ;
this->Title = "";
this->Name = "";
this->LastName = "";
this->Position = "";
this->Birthdate = "";
this->Number = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactPerson");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Contact", "ContactID", "Name"));
}
ContactPerson::ContactPerson(int ContactPersonID,int ContactID,QString Title,QString Name,QString LastName,QString Position,QString Birthdate,int Number,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonID = ContactPersonID ;
this->ContactID = ContactID ;
this->Title = Title ;
this->Name = Name ;
this->LastName = LastName ;
this->Position = Position ;
this->Birthdate = Birthdate ;
this->Number = Number ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPerson::ContactPerson(int ContactID,QString Title,QString Name,QString LastName,QString Position,QString Birthdate,int Number,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonID = 0 ;
this->ContactID = ContactID ;
this->Title = Title ;
this->Name = Name ;
this->LastName = LastName ;
this->Position = Position ;
this->Birthdate = Birthdate ;
this->Number = Number ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactPerson::Init()
{

QString table = "ContactPerson";
QString query =
"(ContactPersonID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactPersonID),"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"Title VARCHAR(40) NOT NULL, "
"Name VARCHAR(40) NOT NULL, "
"LastName VARCHAR(40) NOT NULL, "
"Position VARCHAR(40) NOT NULL, "
"Birthdate VARCHAR(40) NOT NULL, "
"Number INT NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactPerson* ContactPerson::p_instance = 0;
ContactPerson* ContactPerson::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactPerson();
		ContactPerson::GetAll();
	}
return p_instance;
}
bool ContactPerson::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactPersonID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPerson (ContactID,Title,Name,LastName,Position,Birthdate,Number,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ContactID)+"','"+QString(this->Title)+"','"+QString(this->Name)+"','"+QString(this->LastName)+"','"+QString(this->Position)+"','"+QString(this->Birthdate)+"','"+QString::number(this->Number)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPerson SET "	"ContactID = '"+QString::number(this->ContactID)+"',"+"Title = '"+QString(this->Title)+"',"+"Name = '"+QString(this->Name)+"',"+"LastName = '"+QString(this->LastName)+"',"+"Position = '"+QString(this->Position)+"',"+"Birthdate = '"+QString(this->Birthdate)+"',"+"Number = '"+QString::number(this->Number)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonID ='"+QString::number(this->ContactPersonID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactPersonID FROM ContactPerson WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactPersonID = query.value(0).toInt();	
 } 
 }
return true;
}

bool ContactPerson::remove() {
if(ContactPersonID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactPerson WHERE ContactPersonID ="+QString::number(this->ContactPersonID)+""));
return true;
 }
return false;
}

ContactPerson* ContactPerson::get() {
if(ContactPersonID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPerson"
"WHERE ContactPersonID ='"+QString::number(this->ContactPersonID)+"'"));
while (query.next()) {
return new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString());
 }

}
return new ContactPerson();
 }

QList<ContactPerson*> ContactPerson::GetAll() {
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"));
	while (query.next()) {
contactpersons.append(new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString()));
	}
qStableSort(contactpersons.begin(),contactpersons.end());
	return contactpersons;
}

ContactPerson* ContactPerson::Get(int id) {
ContactPerson* contactperson = new ContactPerson();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPerson WHERE ContactPersonID = '"+QString::number(id)+"'"));
while (query.next()) {
contactperson = new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString());
 }
contactperson->contactpersontelephones = ContactPersonTelephone::QuerySelect("ContactPersonID = " + QString::number(id));
contactperson->contactpersonemails = ContactPersonEmail::QuerySelect("ContactPersonID = " + QString::number(id));
contactperson->contactpersonfielddatas = ContactPersonFieldData::QuerySelect("ContactPersonID = " + QString::number(id));

}
return contactperson;
}

ContactPerson* ContactPerson::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactPerson();
}

ContactPerson* ContactPerson::Get(QString name) {
ContactPerson* contactperson = new ContactPerson();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson WHERE Title = '"+name+"'"));
while (query.next()) {
contactperson = new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString());

 }
contactperson->contactpersontelephones = ContactPersonTelephone::QuerySelect("ContactPersonID = " +QString::number(contactperson->ContactPersonID));
contactperson->contactpersonemails = ContactPersonEmail::QuerySelect("ContactPersonID = " +QString::number(contactperson->ContactPersonID));
contactperson->contactpersonfielddatas = ContactPersonFieldData::QuerySelect("ContactPersonID = " +QString::number(contactperson->ContactPersonID));

}
return contactperson;
 }

QList<ContactPerson*> ContactPerson::Search(QString keyword) {
QList<ContactPerson*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR Name LIKE '%"+keyword+"%'"
"OR LastName LIKE '%"+keyword+"%'"
"OR Position LIKE '%"+keyword+"%'"
"OR Birthdate LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

QList<QString> ContactPerson::GetStringList() {
	QList<QString> list;
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
contactpersons = GetAll();
	for(int i = 0; i <contactpersons.count(); i++){
		list.append(contactpersons[i]->Title);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> ContactPerson::GetHashList() {
	QHash<int,QString> list;
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
contactpersons = GetAll();
	for(int i = 0; i <contactpersons.count(); i++){
		list.insert(contactpersons[i]->ContactPersonID,contactpersons[i]->Title);
	}
	return list;
}

int ContactPerson::GetIndex(QString name) {
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
contactpersons = GetAll();
	for(int i = 0; i <contactpersons.count(); i++){
		if(contactpersons[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<ContactPerson*> ContactPerson::QuerySelect(QString select) {
QList<ContactPerson*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactPerson::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 11 || index.column() == 12)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactPerson::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setContactID(id, value.toString());
else if (index.column() == 2)
ok = setTitle(id, value.toString());
else if (index.column() == 3)
ok = setName(id, value.toString());
else if (index.column() == 4)
ok = setLastName(id, value.toString());
else if (index.column() == 5)
ok = setPosition(id, value.toString());
else if (index.column() == 6)
ok = setBirthdate(id, value.toString());
else if (index.column() == 7)
ok = setNumber(id, value.toString());
else if (index.column() == 11)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 12)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ContactPerson::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactPersonID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactPerson::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactPerson!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Last Name"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Position"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Birthdate"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Number"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactPerson::setContactID(int ContactPersonID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update ContactPerson set ContactID = ? where ContactPersonID = ?");
query.addBindValue(ContactID);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setTitle(int ContactPersonID, const QString &Title) {
QSqlQuery query;
query.prepare("update ContactPerson set Title = ? where ContactPersonID = ?");
query.addBindValue(Title);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setName(int ContactPersonID, const QString &Name) {
QSqlQuery query;
query.prepare("update ContactPerson set Name = ? where ContactPersonID = ?");
query.addBindValue(Name);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setLastName(int ContactPersonID, const QString &LastName) {
QSqlQuery query;
query.prepare("update ContactPerson set LastName = ? where ContactPersonID = ?");
query.addBindValue(LastName);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setPosition(int ContactPersonID, const QString &Position) {
QSqlQuery query;
query.prepare("update ContactPerson set Position = ? where ContactPersonID = ?");
query.addBindValue(Position);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setBirthdate(int ContactPersonID, const QString &Birthdate) {
QSqlQuery query;
query.prepare("update ContactPerson set Birthdate = ? where ContactPersonID = ?");
query.addBindValue(Birthdate);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setNumber(int ContactPersonID, const QString &Number) {
QSqlQuery query;
query.prepare("update ContactPerson set Number = ? where ContactPersonID = ?");
query.addBindValue(Number);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setCreatedOn(int ContactPersonID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactPerson set CreatedOn = ? where ContactPersonID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setEditedOn(int ContactPersonID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactPerson set EditedOn = ? where ContactPersonID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

