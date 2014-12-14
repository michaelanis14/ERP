/**************************************************************************
**   File: contactpersontelephone.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactpersontelephone.h"
#include "erpmodel.h"

ContactPersonTelephone::ContactPersonTelephone()
 : QSqlRelationalTableModel(){

this->ContactPersonTelephoneID = 0 ;
this->Description = "";
this->Number = 0 ;
this->ContactPersonID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactPersonTelephone");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("ContactPerson", "ContactPersonID", "Title"));
this->setRelation(3, QSqlRelation("ContactPerson", "ContactPersonID", "TitleName"));
}
ContactPersonTelephone::ContactPersonTelephone(int ContactPersonTelephoneID,QString Description,int Number,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonTelephoneID = ContactPersonTelephoneID ;
this->Description = Description ;
this->Number = Number ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPersonTelephone::ContactPersonTelephone(QString Description,int Number,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonTelephoneID = 0 ;
this->Description = Description ;
this->Number = Number ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactPersonTelephone::Init()
{

QString table = "ContactPersonTelephone";
QString query =
"(ContactPersonTelephoneID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactPersonTelephoneID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"Number INT NOT NULL, "
"ContactPersonID INT NOT NULL, "
"FOREIGN KEY (ContactPersonID) REFERENCES ContactPerson(ContactPersonID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ContactPersonTelephoneID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" INT"),QString("Number")));variables.append(qMakePair(QString(" INT"),QString("ContactPersonID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ContactPersonTelephone* ContactPersonTelephone::p_instance = 0;
ContactPersonTelephone* ContactPersonTelephone::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactPersonTelephone();
		ContactPersonTelephone::GetAll();
	}
return p_instance;
}
bool ContactPersonTelephone::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactPersonTelephoneID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPersonTelephone (Description,Number,ContactPersonID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString::number(this->Number)+"','"+QString::number(this->ContactPersonID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPersonTelephone SET "	"Description = '"+QString(this->Description)+"',"+"Number = '"+QString::number(this->Number)+"',"+"ContactPersonID = '"+QString::number(this->ContactPersonID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonTelephoneID ='"+QString::number(this->ContactPersonTelephoneID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactPersonTelephoneID FROM ContactPersonTelephone WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactPersonTelephoneID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ContactPersonTelephone::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ContactPersonTelephone::remove() {
if(ContactPersonTelephoneID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactPersonTelephone WHERE ContactPersonTelephoneID ="+QString::number(this->ContactPersonTelephoneID)+""));
return true;
 }
return false;
}

ContactPersonTelephone* ContactPersonTelephone::get() {
if(ContactPersonTelephoneID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonTelephone"
"WHERE ContactPersonTelephoneID ='"+QString::number(this->ContactPersonTelephoneID)+"'"));
while (query.next()) {
return new ContactPersonTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ContactPersonTelephone();
 }

QList<ContactPersonTelephone*> ContactPersonTelephone::GetAll() {
	QList<ContactPersonTelephone*> contactpersontelephones =   QList<ContactPersonTelephone*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonTelephone ORDER BY ContactPersonTelephoneID ASC"));
	while (query.next()) {
contactpersontelephones.append(new ContactPersonTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
	return contactpersontelephones;
}

ContactPersonTelephone* ContactPersonTelephone::Get(int id) {
ContactPersonTelephone* contactpersontelephone = new ContactPersonTelephone();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonTelephone WHERE ContactPersonTelephoneID = '"+QString::number(id)+"' ORDER BY ContactPersonTelephoneID ASC "));
while (query.next()) {
contactpersontelephone = new ContactPersonTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return contactpersontelephone;
}

ContactPersonTelephone* ContactPersonTelephone::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactPersonTelephone();
}

ContactPersonTelephone* ContactPersonTelephone::Get(QString name) {
ContactPersonTelephone* contactpersontelephone = new ContactPersonTelephone();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonTelephone WHERE Description = '"+name+"'"));
while (query.next()) {
contactpersontelephone = new ContactPersonTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return contactpersontelephone;
 }

QList<ContactPersonTelephone*> ContactPersonTelephone::Search(QString keyword) {
QList<ContactPersonTelephone*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonTelephone"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPersonTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ContactPersonTelephone::GetStringList() {
	QList<QString> list;
	QList<ContactPersonTelephone*> contactpersontelephones =   QList<ContactPersonTelephone*>();
contactpersontelephones = GetAll();
	for(int i = 0; i <contactpersontelephones.count(); i++){
		list.append(contactpersontelephones[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > ContactPersonTelephone::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ContactPersonTelephone*> contactpersontelephones =   QList<ContactPersonTelephone*>();
contactpersontelephones = GetAll();
	for(int i = 0; i <contactpersontelephones.count(); i++){
		list.append(qMakePair(contactpersontelephones[i]->ContactPersonTelephoneID,contactpersontelephones[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > ContactPersonTelephone::GetPairList(QList<ContactPersonTelephone*> contactpersontelephones) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <contactpersontelephones.count(); i++){
		list.append(qMakePair(contactpersontelephones[i]->ContactPersonTelephoneID,contactpersontelephones[i]->Description));
	}
	return list;
}

int ContactPersonTelephone::GetIndex(QString name) {
	QList<ContactPersonTelephone*> contactpersontelephones =   QList<ContactPersonTelephone*>();
contactpersontelephones = GetAll();
	for(int i = 0; i <contactpersontelephones.count(); i++){
		if(contactpersontelephones[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactPersonTelephone*> ContactPersonTelephone::QuerySelect(QString select) {
QList<ContactPersonTelephone*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonTelephone WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactPersonTelephone(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactPersonTelephone::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactPersonTelephone::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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
ok = setContactPersonID(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ContactPersonTelephone::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactPersonTelephoneID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactPersonTelephone::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactPersonTelephone!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Number"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact Person"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactPersonTelephone::setDescription(int ContactPersonTelephoneID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactPersonTelephone set Description = ? where ContactPersonTelephoneID = ?");
query.addBindValue(Description);
query.addBindValue(ContactPersonTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonTelephone::setNumber(int ContactPersonTelephoneID, const QString &Number) {
QSqlQuery query;
query.prepare("update ContactPersonTelephone set Number = ? where ContactPersonTelephoneID = ?");
query.addBindValue(Number);
query.addBindValue(ContactPersonTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonTelephone::setContactPersonID(int ContactPersonTelephoneID, const QString &ContactPersonID) {
QSqlQuery query;
query.prepare("update ContactPersonTelephone set ContactPersonID = ? where ContactPersonTelephoneID = ?");
query.addBindValue(ContactPersonID);
query.addBindValue(ContactPersonTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonTelephone::setCreatedOn(int ContactPersonTelephoneID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactPersonTelephone set CreatedOn = ? where ContactPersonTelephoneID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactPersonTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonTelephone::setEditedOn(int ContactPersonTelephoneID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactPersonTelephone set EditedOn = ? where ContactPersonTelephoneID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactPersonTelephoneID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

