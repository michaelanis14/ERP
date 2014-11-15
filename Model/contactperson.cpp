/**************************************************************************
**   File: contactperson.cpp
**   Created on: Sat Nov 15 20:33:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactperson.h"
#include "erpmodel.h"

ContactPerson::ContactPerson()
 : QSqlRelationalTableModel(){

this->ContactPersonID = 0 ;
this->PersonalSalut = " ";
this->TitlePrefix = " ";
this->Name = " ";
this->LastName = " ";
this->Position = " ";
this->Birthdate = " ";
this->ContactPersoneNumber = 0 ;
this->Email = " ";
this->PhoneNum = " ";
this->PhoneNum2 = " ";
this->Mobile = " ";
this->Fax = " ";
this->active = 0 ;
this->CreatedBy_UserID = 0 ;
this->EditedBy_UserID = 0 ;
this->ContactID = 0 ;
this->CreatedOn = " ";
this->EditedOn = " ";
this->setTable("ContactPerson");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(16, QSqlRelation("Contact", "ContactID", "Name"));
}
ContactPerson::ContactPerson(int ContactPersonID,QString PersonalSalut,QString TitlePrefix,QString Name,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int CreatedBy_UserID,int EditedBy_UserID,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonID = ContactPersonID ;
this->PersonalSalut = PersonalSalut ;
this->TitlePrefix = TitlePrefix ;
this->Name = Name ;
this->LastName = LastName ;
this->Position = Position ;
this->Birthdate = Birthdate ;
this->ContactPersoneNumber = ContactPersoneNumber ;
this->Email = Email ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Mobile = Mobile ;
this->Fax = Fax ;
this->active = active ;
this->CreatedBy_UserID = CreatedBy_UserID ;
this->EditedBy_UserID = EditedBy_UserID ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPerson::ContactPerson(QString PersonalSalut,QString TitlePrefix,QString Name,QString LastName,QString Position,QString Birthdate,int ContactPersoneNumber,QString Email,QString PhoneNum,QString PhoneNum2,QString Mobile,QString Fax,bool active,int CreatedBy_UserID,int EditedBy_UserID,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonID = 0 ;
this->PersonalSalut = PersonalSalut ;
this->TitlePrefix = TitlePrefix ;
this->Name = Name ;
this->LastName = LastName ;
this->Position = Position ;
this->Birthdate = Birthdate ;
this->ContactPersoneNumber = ContactPersoneNumber ;
this->Email = Email ;
this->PhoneNum = PhoneNum ;
this->PhoneNum2 = PhoneNum2 ;
this->Mobile = Mobile ;
this->Fax = Fax ;
this->active = active ;
this->CreatedBy_UserID = CreatedBy_UserID ;
this->EditedBy_UserID = EditedBy_UserID ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactPerson::Init()
{

QString table = "ContactPerson";
QString query =
"(ContactPersonID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactPersonID),"
"PersonalSalut VARCHAR(40) NOT NULL, "
"TitlePrefix VARCHAR(40) NOT NULL, "
"Name VARCHAR(40) NOT NULL, "
"LastName VARCHAR(40) NOT NULL, "
"Position VARCHAR(40) NOT NULL, "
"Birthdate VARCHAR(40) NOT NULL, "
"ContactPersoneNumber INT NOT NULL, "
"Email VARCHAR(40) NOT NULL, "
"PhoneNum VARCHAR(40) NOT NULL, "
"PhoneNum2 VARCHAR(40) NOT NULL, "
"Mobile VARCHAR(40) NOT NULL, "
"Fax VARCHAR(40) NOT NULL, "
"active VARCHAR(1) NOT NULL, "
"CreatedBy_UserID INT NOT NULL, "
"FOREIGN KEY (CreatedBy_UserID) REFERENCES CreatedBy_User(CreatedBy_UserID),"
"EditedBy_UserID INT NOT NULL, "
"FOREIGN KEY (EditedBy_UserID) REFERENCES EditedBy_User(EditedBy_UserID),"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

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
if(ContactPersonID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString(); 
	this->EditedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPerson (PersonalSalut,TitlePrefix,Name,LastName,Position,Birthdate,ContactPersoneNumber,Email,PhoneNum,PhoneNum2,Mobile,Fax,active,CreatedBy_UserID,EditedBy_UserID,ContactID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->PersonalSalut)+"','"+QString(this->TitlePrefix)+"','"+QString(this->Name)+"','"+QString(this->LastName)+"','"+QString(this->Position)+"','"+QString(this->Birthdate)+"','"+QString::number(this->ContactPersoneNumber)+"','"+QString(this->Email)+"','"+QString(this->PhoneNum)+"','"+QString(this->PhoneNum2)+"','"+QString(this->Mobile)+"','"+QString(this->Fax)+"','"+QString::number(this->active)+"','"+QString::number(this->CreatedBy_UserID)+"','"+QString::number(this->EditedBy_UserID)+"','"+QString::number(this->ContactID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPerson SET ""PersonalSalut = '"+QString(this->PersonalSalut)+"','"+"TitlePrefix = '"+QString(this->TitlePrefix)+"','"+"Name = '"+QString(this->Name)+"','"+"LastName = '"+QString(this->LastName)+"','"+"Position = '"+QString(this->Position)+"','"+"Birthdate = '"+QString(this->Birthdate)+"','"+"ContactPersoneNumber = '"+QString::number(this->ContactPersoneNumber)+"','"+"Email = '"+QString(this->Email)+"','"+"PhoneNum = '"+QString(this->PhoneNum)+"','"+"PhoneNum2 = '"+QString(this->PhoneNum2)+"','"+"Mobile = '"+QString(this->Mobile)+"','"+"Fax = '"+QString(this->Fax)+"','"+"active = '"+QString::number(this->active)+"','"+"CreatedBy_UserID = '"+QString::number(this->CreatedBy_UserID)+"','"+"EditedBy_UserID = '"+QString::number(this->EditedBy_UserID)+"','"+"ContactID = '"+QString::number(this->ContactID)+"','"+"CreatedOn = '"+QString(this->CreatedOn)+"','"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonID ='"+QString::number(this->ContactPersonID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactPersonID FROM ContactPerson WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
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
return new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString());
 }

}
return new ContactPerson();
 }

QList<ContactPerson*> ContactPerson::GetAll() {
	ContactPerson::GetInstance()->contactpersons.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"));
	while (query.next()) {
		ContactPerson::GetInstance()->contactpersons.append(new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString()));
	}
	return ContactPerson::GetInstance()->contactpersons;
}

ContactPerson* ContactPerson::Get(int id) {
ContactPerson* contactperson = new ContactPerson();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPerson WHERE ContactPersonID = '"+QString::number(id)+"'"));
while (query.next()) {
contactperson = new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString());
 }

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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson WHERE Name = '"+name+"'"));
while (query.next()) {
contactperson = new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString());

 }

}
return contactperson;
 }

QList<ContactPerson*> ContactPerson::Search(QString keyword) {
QList<ContactPerson*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPerson"
"WHERE" 
"PersonalSalut LIKE '%"+keyword+"%'"
"OR TitlePrefix LIKE '%"+keyword+"%'"
"OR Name LIKE '%"+keyword+"%'"
"OR LastName LIKE '%"+keyword+"%'"
"OR Position LIKE '%"+keyword+"%'"
"OR Birthdate LIKE '%"+keyword+"%'"
"OR Email LIKE '%"+keyword+"%'"
"OR PhoneNum LIKE '%"+keyword+"%'"
"OR PhoneNum2 LIKE '%"+keyword+"%'"
"OR Mobile LIKE '%"+keyword+"%'"
"OR Fax LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString()));
 }

}
return list;
 }

QList<QString> ContactPerson::GetStringList() {
	QList<QString> list;
	int count =ContactPerson::GetInstance()->contactpersons.count();
	if( count < 2){
		ContactPerson::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.append(ContactPerson::GetInstance()->contactpersons[i]->Name);
	}
	return list;
}

QHash<int,QString> ContactPerson::GetHashList() {
	QHash<int,QString> list;
	int count =ContactPerson::GetInstance()->contactpersons.count();
	if( count < 2){
		ContactPerson::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(ContactPerson::GetInstance()->contactpersons[i]->ContactPersonID,ContactPerson::GetInstance()->contactpersons[i]->Name);
	}
	return list;
}

int ContactPerson::GetIndex(QString name) {
	int count =ContactPerson::GetInstance()->contactpersons.count();
	if( count < 2){
		ContactPerson::GetAll();
	}
	for(int i = 0; i < count; i++){
		if(ContactPerson::GetInstance()->contactpersons[i]->Name == name){
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
list.append(new ContactPerson(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toString(),query.value(18).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactPerson::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 14 || index.column() == 15 || index.column() == 16 || index.column() == 17 || index.column() == 18)
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
ok = setPersonalSalut(id, value.toString());
else if (index.column() == 2)
ok = setTitlePrefix(id, value.toString());
else if (index.column() == 3)
ok = setName(id, value.toString());
else if (index.column() == 4)
ok = setLastName(id, value.toString());
else if (index.column() == 5)
ok = setPosition(id, value.toString());
else if (index.column() == 6)
ok = setBirthdate(id, value.toString());
else if (index.column() == 7)
ok = setContactPersoneNumber(id, value.toString());
else if (index.column() == 8)
ok = setEmail(id, value.toString());
else if (index.column() == 9)
ok = setPhoneNum(id, value.toString());
else if (index.column() == 10)
ok = setPhoneNum2(id, value.toString());
else if (index.column() == 11)
ok = setMobile(id, value.toString());
else if (index.column() == 12)
ok = setFax(id, value.toString());
else if (index.column() == 13)
ok = setactive(id, value.toString());
else if (index.column() == 14)
ok = setCreatedBy_UserID(id, value.toString());
else if (index.column() == 15)
ok = setEditedBy_UserID(id, value.toString());
else if (index.column() == 16)
ok = setContactID(id, value.toString());
else if (index.column() == 17)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 18)
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
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Personal Salut"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Title Prefix"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Last Name"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Position"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Birthdate"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Contact Persone Number"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Email"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Phone Num"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Phone Num2"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Mobile"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Fax"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("active"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Created By_ User"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Edited By_ User"));
this->setHeaderData(16, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(17, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(18, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactPerson::setPersonalSalut(int ContactPersonID, const QString &PersonalSalut) {
QSqlQuery query;
query.prepare("update ContactPerson set PersonalSalut = ? where ContactPersonID = ?");
query.addBindValue(PersonalSalut);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setTitlePrefix(int ContactPersonID, const QString &TitlePrefix) {
QSqlQuery query;
query.prepare("update ContactPerson set TitlePrefix = ? where ContactPersonID = ?");
query.addBindValue(TitlePrefix);
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
bool ContactPerson::setContactPersoneNumber(int ContactPersonID, const QString &ContactPersoneNumber) {
QSqlQuery query;
query.prepare("update ContactPerson set ContactPersoneNumber = ? where ContactPersonID = ?");
query.addBindValue(ContactPersoneNumber);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setEmail(int ContactPersonID, const QString &Email) {
QSqlQuery query;
query.prepare("update ContactPerson set Email = ? where ContactPersonID = ?");
query.addBindValue(Email);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setPhoneNum(int ContactPersonID, const QString &PhoneNum) {
QSqlQuery query;
query.prepare("update ContactPerson set PhoneNum = ? where ContactPersonID = ?");
query.addBindValue(PhoneNum);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setPhoneNum2(int ContactPersonID, const QString &PhoneNum2) {
QSqlQuery query;
query.prepare("update ContactPerson set PhoneNum2 = ? where ContactPersonID = ?");
query.addBindValue(PhoneNum2);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setMobile(int ContactPersonID, const QString &Mobile) {
QSqlQuery query;
query.prepare("update ContactPerson set Mobile = ? where ContactPersonID = ?");
query.addBindValue(Mobile);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setFax(int ContactPersonID, const QString &Fax) {
QSqlQuery query;
query.prepare("update ContactPerson set Fax = ? where ContactPersonID = ?");
query.addBindValue(Fax);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setactive(int ContactPersonID, const QString &active) {
QSqlQuery query;
query.prepare("update ContactPerson set active = ? where ContactPersonID = ?");
query.addBindValue(active);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setCreatedBy_UserID(int ContactPersonID, const QString &CreatedBy_UserID) {
QSqlQuery query;
query.prepare("update ContactPerson set CreatedBy_UserID = ? where ContactPersonID = ?");
query.addBindValue(CreatedBy_UserID);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPerson::setEditedBy_UserID(int ContactPersonID, const QString &EditedBy_UserID) {
QSqlQuery query;
query.prepare("update ContactPerson set EditedBy_UserID = ? where ContactPersonID = ?");
query.addBindValue(EditedBy_UserID);
query.addBindValue(ContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
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

