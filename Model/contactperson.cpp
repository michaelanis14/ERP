/**************************************************************************
**   File: contactperson.cpp
**   Created on: Thu Dec 18 20:39:34 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactperson.h"
#include "erpmodel.h"

ContactPerson::ContactPerson()
 : QSqlRelationalTableModel(){

this->ContactPersonID = 0 ;
this->ContactID = 0 ;
this->Name = "";
this->LastName = "";
this->Position = "";
this->Birthdate = QDate();
this->Number = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactPerson");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Contact", "ContactID", "Name"));
}
ContactPerson::ContactPerson(int ContactPersonID,int ContactID,QString Name,QString LastName,QString Position,QDate Birthdate,int Number,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonID = ContactPersonID ;
this->ContactID = ContactID ;
this->Name = Name ;
this->LastName = LastName ;
this->Position = Position ;
this->Birthdate = Birthdate ;
this->Number = Number ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPerson::ContactPerson(int ContactID,QString Name,QString LastName,QString Position,QDate Birthdate,int Number,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonID = 0 ;
this->ContactID = ContactID ;
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
" KEY(ContactID),"
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"Name VARCHAR(40) NOT NULL, "
"LastName VARCHAR(40) NOT NULL, "
"Position VARCHAR(40) NOT NULL, "
"Birthdate DATE NOT NULL, "
"Number INT NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ContactPersonID")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("LastName")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Position")));variables.append(qMakePair(QString(""),QString("Birthdate")));variables.append(qMakePair(QString(" INT"),QString("Number")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
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
this->EditedOn = QDate::currentDate().toString();
if(ContactPersonID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPerson (ContactID,Name,LastName,Position,Birthdate,Number,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ContactID)+"','"+QString(this->Name)+"','"+QString(this->LastName)+"','"+QString(this->Position)+"','"+(this->Birthdate.toString("yyyy-MM-dd"))+"','"+QString::number(this->Number)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPerson SET "	"ContactID = '"+QString::number(this->ContactID)+"',"+"Name = '"+QString(this->Name)+"',"+"LastName = '"+QString(this->LastName)+"',"+"Position = '"+QString(this->Position)+"',"+"Birthdate = '"+(this->Birthdate.toString("yyyy-MM-dd"))+"',"+"Number = '"+QString::number(this->Number)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonID ='"+QString::number(this->ContactPersonID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactPersonID FROM ContactPerson WHERE ContactID = "+QString::number(ContactID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactPersonID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ContactPerson::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
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
return new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());
 }

}
return new ContactPerson();
 }

QList<ContactPerson*> ContactPerson::GetAll() {
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson ORDER BY ContactPersonID ASC"));
	while (query.next()) {
contactpersons.append(new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
	}
	return contactpersons;
}

ContactPerson* ContactPerson::Get(int id) {
ContactPerson* contactperson = new ContactPerson();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPerson WHERE ContactPersonID = '"+QString::number(id)+"' ORDER BY ContactPersonID ASC "));
while (query.next()) {
contactperson = new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());
 }
contactperson->contactpersontelephones = ContactPersonTelephone::QuerySelect("ContactPersonID = " + QString::number(id));
contactperson->contactpersonemails = ContactPersonEmail::QuerySelect("ContactPersonID = " + QString::number(id));

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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson WHERE ContactID = QString::number("+name+")"));
while (query.next()) {
contactperson = new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString());

 }
contactperson->contactpersontelephones = ContactPersonTelephone::QuerySelect("ContactPersonID = " +QString::number(contactperson->ContactPersonID));
contactperson->contactpersonemails = ContactPersonEmail::QuerySelect("ContactPersonID = " +QString::number(contactperson->ContactPersonID));

}
return contactperson;
 }

QList<ContactPerson*> ContactPerson::Search(QString keyword) {
QList<ContactPerson*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR LastName LIKE '%"+keyword+"%'"
"OR Position LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
 }

}
return list;
 }

QList<QString> ContactPerson::GetStringList() {
	QList<QString> list;
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
contactpersons = GetAll();
	for(int i = 0; i <contactpersons.count(); i++){
		list.append(contactpersons[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > ContactPerson::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
contactpersons = GetAll();
	for(int i = 0; i <contactpersons.count(); i++){
		list.append(qMakePair(contactpersons[i]->ContactPersonID,QString::number(contactpersons[i]->ContactID)));
	}
	return list;
}

QList<QPair< int,QString > > ContactPerson::GetPairList(QList<ContactPerson*> contactpersons) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <contactpersons.count(); i++){
		list.append(qMakePair(contactpersons[i]->ContactPersonID,QString::number(contactpersons[i]->ContactID)));
	}
	return list;
}

int ContactPerson::GetIndex(QString name) {
	QList<ContactPerson*> contactpersons =   QList<ContactPerson*>();
contactpersons = GetAll();
	for(int i = 0; i <contactpersons.count(); i++){
		if(contactpersons[i]->ContactID == name.toInt()){
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
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactPerson::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 9 || index.column() == 10)
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
ok = setName(id, value.toString());
else if (index.column() == 3)
ok = setLastName(id, value.toString());
else if (index.column() == 4)
ok = setPosition(id, value.toString());
else if (index.column() == 5)
ok = setBirthdate(id, value.toString());
else if (index.column() == 6)
ok = setNumber(id, value.toString());
else if (index.column() == 9)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 10)
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
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Last Name"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Position"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Birthdate"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Number"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Edited On"));
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

