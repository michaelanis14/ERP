/**************************************************************************
**   File: contactpersonemail.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactpersonemail.h"
#include "erpmodel.h"

ContactPersonEmail::ContactPersonEmail()
 : QSqlRelationalTableModel(){

this->ContactPersonEmailID = 0 ;
this->Description = "";
this->Email = "";
this->ContactPersonID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactPersonEmail");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("ContactPerson", "ContactPersonID", "Title"));
this->setRelation(3, QSqlRelation("ContactPerson", "ContactPersonID", "TitleName"));
}
ContactPersonEmail::ContactPersonEmail(int ContactPersonEmailID,QString Description,QString Email,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonEmailID = ContactPersonEmailID ;
this->Description = Description ;
this->Email = Email ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPersonEmail::ContactPersonEmail(QString Description,QString Email,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonEmailID = 0 ;
this->Description = Description ;
this->Email = Email ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactPersonEmail::Init()
{

QString table = "ContactPersonEmail";
QString query =
"(ContactPersonEmailID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactPersonEmailID),"
"Description VARCHAR(40) NOT NULL, "
"Email VARCHAR(40) NOT NULL, "
"ContactPersonID INT NOT NULL, "
"FOREIGN KEY (ContactPersonID) REFERENCES ContactPerson(ContactPersonID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactPersonEmail* ContactPersonEmail::p_instance = 0;
ContactPersonEmail* ContactPersonEmail::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactPersonEmail();
		ContactPersonEmail::GetAll();
	}
return p_instance;
}
bool ContactPersonEmail::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactPersonEmailID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPersonEmail (Description,Email,ContactPersonID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->Email)+"','"+QString::number(this->ContactPersonID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPersonEmail SET "	"Description = '"+QString(this->Description)+"',"+"Email = '"+QString(this->Email)+"',"+"ContactPersonID = '"+QString::number(this->ContactPersonID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonEmailID ='"+QString::number(this->ContactPersonEmailID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactPersonEmailID FROM ContactPersonEmail WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactPersonEmailID = query.value(0).toInt();	
 } 
 }
return true;
}

bool ContactPersonEmail::remove() {
if(ContactPersonEmailID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactPersonEmail WHERE ContactPersonEmailID ="+QString::number(this->ContactPersonEmailID)+""));
return true;
 }
return false;
}

ContactPersonEmail* ContactPersonEmail::get() {
if(ContactPersonEmailID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonEmail"
"WHERE ContactPersonEmailID ='"+QString::number(this->ContactPersonEmailID)+"'"));
while (query.next()) {
return new ContactPersonEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ContactPersonEmail();
 }

QList<ContactPersonEmail*> ContactPersonEmail::GetAll() {
	QList<ContactPersonEmail*> contactpersonemails =   QList<ContactPersonEmail*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonEmail"));
	while (query.next()) {
contactpersonemails.append(new ContactPersonEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
qStableSort(contactpersonemails.begin(),contactpersonemails.end());
	return contactpersonemails;
}

ContactPersonEmail* ContactPersonEmail::Get(int id) {
ContactPersonEmail* contactpersonemail = new ContactPersonEmail();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonEmail WHERE ContactPersonEmailID = '"+QString::number(id)+"'"));
while (query.next()) {
contactpersonemail = new ContactPersonEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return contactpersonemail;
}

ContactPersonEmail* ContactPersonEmail::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactPersonEmail();
}

ContactPersonEmail* ContactPersonEmail::Get(QString name) {
ContactPersonEmail* contactpersonemail = new ContactPersonEmail();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonEmail WHERE Description = '"+name+"'"));
while (query.next()) {
contactpersonemail = new ContactPersonEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return contactpersonemail;
 }

QList<ContactPersonEmail*> ContactPersonEmail::Search(QString keyword) {
QList<ContactPersonEmail*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonEmail"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR Email LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPersonEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ContactPersonEmail::GetStringList() {
	QList<QString> list;
	QList<ContactPersonEmail*> contactpersonemails =   QList<ContactPersonEmail*>();
contactpersonemails = GetAll();
	for(int i = 0; i <contactpersonemails.count(); i++){
		list.append(contactpersonemails[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> ContactPersonEmail::GetHashList() {
	QHash<int,QString> list;
	QList<ContactPersonEmail*> contactpersonemails =   QList<ContactPersonEmail*>();
contactpersonemails = GetAll();
	for(int i = 0; i <contactpersonemails.count(); i++){
		list.insert(contactpersonemails[i]->ContactPersonEmailID,contactpersonemails[i]->Description);
	}
	return list;
}

int ContactPersonEmail::GetIndex(QString name) {
	QList<ContactPersonEmail*> contactpersonemails =   QList<ContactPersonEmail*>();
contactpersonemails = GetAll();
	for(int i = 0; i <contactpersonemails.count(); i++){
		if(contactpersonemails[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactPersonEmail*> ContactPersonEmail::QuerySelect(QString select) {
QList<ContactPersonEmail*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonEmail WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactPersonEmail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactPersonEmail::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactPersonEmail::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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
ok = setContactPersonID(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ContactPersonEmail::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactPersonEmailID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactPersonEmail::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactPersonEmail!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact Person"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactPersonEmail::setDescription(int ContactPersonEmailID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactPersonEmail set Description = ? where ContactPersonEmailID = ?");
query.addBindValue(Description);
query.addBindValue(ContactPersonEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonEmail::setEmail(int ContactPersonEmailID, const QString &Email) {
QSqlQuery query;
query.prepare("update ContactPersonEmail set Email = ? where ContactPersonEmailID = ?");
query.addBindValue(Email);
query.addBindValue(ContactPersonEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonEmail::setContactPersonID(int ContactPersonEmailID, const QString &ContactPersonID) {
QSqlQuery query;
query.prepare("update ContactPersonEmail set ContactPersonID = ? where ContactPersonEmailID = ?");
query.addBindValue(ContactPersonID);
query.addBindValue(ContactPersonEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonEmail::setCreatedOn(int ContactPersonEmailID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactPersonEmail set CreatedOn = ? where ContactPersonEmailID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactPersonEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonEmail::setEditedOn(int ContactPersonEmailID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactPersonEmail set EditedOn = ? where ContactPersonEmailID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactPersonEmailID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

