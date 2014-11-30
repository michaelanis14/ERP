/**************************************************************************
**   File: contactfield.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactfield.h"
#include "erpmodel.h"

ContactField::ContactField()
 : QSqlRelationalTableModel(){

this->ContactFieldID = 0 ;
this->FieldTypeID = 0 ;
this->Description = "";
this->Defaults = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactField");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("FieldType", "FieldTypeID", "Description"));
}
ContactField::ContactField(int ContactFieldID,int FieldTypeID,QString Description,bool Defaults,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactFieldID = ContactFieldID ;
this->FieldTypeID = FieldTypeID ;
this->Description = Description ;
this->Defaults = Defaults ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactField::ContactField(int FieldTypeID,QString Description,bool Defaults,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactFieldID = 0 ;
this->FieldTypeID = FieldTypeID ;
this->Description = Description ;
this->Defaults = Defaults ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactField::Init()
{

QString table = "ContactField";
QString query =
"(ContactFieldID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactFieldID),"
"FieldTypeID INT NOT NULL, "
"FOREIGN KEY (FieldTypeID) REFERENCES FieldType(FieldTypeID)  ON DELETE CASCADE,"
"Description VARCHAR(40) NOT NULL, "
"Defaults VARCHAR(1) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactField* ContactField::p_instance = 0;
ContactField* ContactField::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactField();
		ContactField::GetAll();
	}
return p_instance;
}
bool ContactField::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactFieldID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactField (FieldTypeID,Description,Defaults,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->FieldTypeID)+"','"+QString(this->Description)+"','"+QString::number(this->Defaults)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactField SET "	"FieldTypeID = '"+QString::number(this->FieldTypeID)+"',"+"Description = '"+QString(this->Description)+"',"+"Defaults = '"+QString::number(this->Defaults)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactFieldID ='"+QString::number(this->ContactFieldID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactFieldID FROM ContactField WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactFieldID = query.value(0).toInt();	
 } 
 }
return true;
}

bool ContactField::remove() {
if(ContactFieldID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactField WHERE ContactFieldID ="+QString::number(this->ContactFieldID)+""));
return true;
 }
return false;
}

ContactField* ContactField::get() {
if(ContactFieldID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactField"
"WHERE ContactFieldID ='"+QString::number(this->ContactFieldID)+"'"));
while (query.next()) {
return new ContactField(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ContactField();
 }

QList<ContactField*> ContactField::GetAll() {
	QList<ContactField*> contactfields =   QList<ContactField*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactField"));
	while (query.next()) {
contactfields.append(new ContactField(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
qSort(contactfields);
	return contactfields;
}

ContactField* ContactField::Get(int id) {
ContactField* contactfield = new ContactField();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactField WHERE ContactFieldID = '"+QString::number(id)+"'"));
while (query.next()) {
contactfield = new ContactField(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return contactfield;
}

ContactField* ContactField::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactField();
}

ContactField* ContactField::Get(QString name) {
ContactField* contactfield = new ContactField();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactField WHERE Description = '"+name+"'"));
while (query.next()) {
contactfield = new ContactField(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return contactfield;
 }

QList<ContactField*> ContactField::Search(QString keyword) {
QList<ContactField*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactField"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactField(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ContactField::GetStringList() {
	QList<QString> list;
	QList<ContactField*> contactfields =   QList<ContactField*>();
contactfields = GetAll();
	for(int i = 0; i <contactfields.count(); i++){
		list.append(contactfields[i]->Description);
	}
	qSort(list);
	return list;
}

QHash<int,QString> ContactField::GetHashList() {
	QHash<int,QString> list;
	QList<ContactField*> contactfields =   QList<ContactField*>();
contactfields = GetAll();
	for(int i = 0; i <contactfields.count(); i++){
		list.insert(contactfields[i]->ContactFieldID,contactfields[i]->Description);
	}
	return list;
}

int ContactField::GetIndex(QString name) {
	QList<ContactField*> contactfields =   QList<ContactField*>();
contactfields = GetAll();
	for(int i = 0; i <contactfields.count(); i++){
		if(contactfields[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactField*> ContactField::QuerySelect(QString select) {
QList<ContactField*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactField WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactField(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactField::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactField::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setFieldTypeID(id, value.toString());
else if (index.column() == 2)
ok = setDescription(id, value.toString());
else if (index.column() == 3)
ok = setDefaults(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ContactField::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactFieldID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactField::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactField!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Field Type"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Defaults"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactField::setFieldTypeID(int ContactFieldID, const QString &FieldTypeID) {
QSqlQuery query;
query.prepare("update ContactField set FieldTypeID = ? where ContactFieldID = ?");
query.addBindValue(FieldTypeID);
query.addBindValue(ContactFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactField::setDescription(int ContactFieldID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactField set Description = ? where ContactFieldID = ?");
query.addBindValue(Description);
query.addBindValue(ContactFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactField::setDefaults(int ContactFieldID, const QString &Defaults) {
QSqlQuery query;
query.prepare("update ContactField set Defaults = ? where ContactFieldID = ?");
query.addBindValue(Defaults);
query.addBindValue(ContactFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactField::setCreatedOn(int ContactFieldID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactField set CreatedOn = ? where ContactFieldID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactField::setEditedOn(int ContactFieldID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactField set EditedOn = ? where ContactFieldID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

