/**************************************************************************
**   File: contactemail.cpp
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactemail.h"
#include "erpmodel.h"

ContactEmail::ContactEmail()
 : QSqlRelationalTableModel(){

this->ContactEmailID = 0 ;
this->Description = "";
this->Email = "";
this->ContactID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactEmail");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("Contact", "ContactID", "Name"));
}
ContactEmail::ContactEmail(int ContactEmailID,QString Description,QString Email,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactEmailID = ContactEmailID ;
this->Description = Description ;
this->Email = Email ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactEmail::ContactEmail(QString Description,QString Email,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactEmailID = 0 ;
this->Description = Description ;
this->Email = Email ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactEmail::Init()
{

QString table = "ContactEmail";
QString query =
"(ContactEmailID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactEmailID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"Email VARCHAR(40) NOT NULL, "
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ContactEmailID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Email")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ContactEmail* ContactEmail::p_instance = 0;
ContactEmail* ContactEmail::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactEmail();
		ContactEmail::GetAll();
	}
return p_instance;
}
bool ContactEmail::save() {
this->EditedOn = QDate::currentDate().toString();
if(ContactEmailID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactEmail (Description,Email,ContactID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->Email)+"','"+QString::number(this->ContactID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactEmail SET "	"Description = '"+QString(this->Description)+"',"+"Email = '"+QString(this->Email)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactEmailID ='"+QString::number(this->ContactEmailID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactEmailID FROM ContactEmail WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactEmailID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ContactEmail::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ContactEmail::remove() {
if(ContactEmailID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactEmail WHERE ContactEmailID ="+QString::number(this->ContactEmailID)+""));
return true;
 }
return false;
}

ContactEmail* ContactEmail::get() {
if(ContactEmailID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactEmail"
"WHERE ContactEmailID ='"+QString::number(this->ContactEmailID)+"'"));
while (query.next()) {
return new ContactEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ContactEmail();
 }

QList<ContactEmail*> ContactEmail::GetAll() {
	QList<ContactEmail*> contactemails =   QList<ContactEmail*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactEmail ORDER BY ContactEmailID ASC"));
	while (query.next()) {
contactemails.append(new ContactEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
	return contactemails;
}

ContactEmail* ContactEmail::Get(int id) {
ContactEmail* contactemail = new ContactEmail();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactEmail WHERE ContactEmailID = '"+QString::number(id)+"' ORDER BY ContactEmailID ASC "));
while (query.next()) {
contactemail = new ContactEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return contactemail;
}

ContactEmail* ContactEmail::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactEmail();
}

ContactEmail* ContactEmail::Get(QString name) {
ContactEmail* contactemail = new ContactEmail();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactEmail WHERE Description = '"+name+"'"));
while (query.next()) {
contactemail = new ContactEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return contactemail;
 }

QList<ContactEmail*> ContactEmail::Search(QString keyword) {
QList<ContactEmail*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactEmail"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR Email LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ContactEmail::GetStringList() {
	QList<QString> list;
	QList<ContactEmail*> contactemails =   QList<ContactEmail*>();
contactemails = GetAll();
	for(int i = 0; i <contactemails.count(); i++){
		list.append(contactemails[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > ContactEmail::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ContactEmail*> contactemails =   QList<ContactEmail*>();
contactemails = GetAll();
	for(int i = 0; i <contactemails.count(); i++){
		list.append(qMakePair(contactemails[i]->ContactEmailID,contactemails[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > ContactEmail::GetPairList(QList<ContactEmail*> contactemails) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <contactemails.count(); i++){
		list.append(qMakePair(contactemails[i]->ContactEmailID,contactemails[i]->Description));
	}
	return list;
}

int ContactEmail::GetIndex(QString name) {
	QList<ContactEmail*> contactemails =   QList<ContactEmail*>();
contactemails = GetAll();
	for(int i = 0; i <contactemails.count(); i++){
		if(contactemails[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactEmail*> ContactEmail::QuerySelect(QString select) {
QList<ContactEmail*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactEmail WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactEmail::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactEmail::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setEmail(id, value.toString());
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

bool ContactEmail::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactEmailID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactEmail::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactEmail!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactEmail::setDescription(int ContactEmailID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactEmail set Description = ? where ContactEmailID = ?");
query.addBindValue(Description);
query.addBindValue(ContactEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactEmail::setEmail(int ContactEmailID, const QString &Email) {
QSqlQuery query;
query.prepare("update ContactEmail set Email = ? where ContactEmailID = ?");
query.addBindValue(Email);
query.addBindValue(ContactEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactEmail::setContactID(int ContactEmailID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update ContactEmail set ContactID = ? where ContactEmailID = ?");
query.addBindValue(ContactID);
query.addBindValue(ContactEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactEmail::setCreatedOn(int ContactEmailID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactEmail set CreatedOn = ? where ContactEmailID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactEmail::setEditedOn(int ContactEmailID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactEmail set EditedOn = ? where ContactEmailID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

