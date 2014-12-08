/**************************************************************************
**   File: contactpersonfield.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactpersonfield.h"
#include "erpmodel.h"

ContactPersonField::ContactPersonField()
 : QSqlRelationalTableModel(){

this->ContactPersonFieldID = 0 ;
this->Description = "";
this->FieldTypeID = 0 ;
this->Defaults = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactPersonField");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("FieldType", "FieldTypeID", "Description"));
}
ContactPersonField::ContactPersonField(int ContactPersonFieldID,QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonFieldID = ContactPersonFieldID ;
this->Description = Description ;
this->FieldTypeID = FieldTypeID ;
this->Defaults = Defaults ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPersonField::ContactPersonField(QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonFieldID = 0 ;
this->Description = Description ;
this->FieldTypeID = FieldTypeID ;
this->Defaults = Defaults ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactPersonField::Init()
{

QString table = "ContactPersonField";
QString query =
"(ContactPersonFieldID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactPersonFieldID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"FieldTypeID INT NOT NULL, "
"FOREIGN KEY (FieldTypeID) REFERENCES FieldType(FieldTypeID)  ON DELETE CASCADE,"
"Defaults VARCHAR(1) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
ContactPersonField* ContactPersonField::p_instance = 0;
ContactPersonField* ContactPersonField::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactPersonField();
		ContactPersonField::GetAll();
	}
return p_instance;
}
bool ContactPersonField::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactPersonFieldID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPersonField (Description,FieldTypeID,Defaults,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString::number(this->FieldTypeID)+"','"+QString::number(this->Defaults)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPersonField SET "	"Description = '"+QString(this->Description)+"',"+"FieldTypeID = '"+QString::number(this->FieldTypeID)+"',"+"Defaults = '"+QString::number(this->Defaults)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonFieldID ='"+QString::number(this->ContactPersonFieldID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactPersonFieldID FROM ContactPersonField WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactPersonFieldID = query.value(0).toInt();	
 } 
 }
return true;
}

bool ContactPersonField::remove() {
if(ContactPersonFieldID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactPersonField WHERE ContactPersonFieldID ="+QString::number(this->ContactPersonFieldID)+""));
return true;
 }
return false;
}

ContactPersonField* ContactPersonField::get() {
if(ContactPersonFieldID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonField"
"WHERE ContactPersonFieldID ='"+QString::number(this->ContactPersonFieldID)+"'"));
while (query.next()) {
return new ContactPersonField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ContactPersonField();
 }

QList<ContactPersonField*> ContactPersonField::GetAll() {
	QList<ContactPersonField*> contactpersonfields =   QList<ContactPersonField*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonField"));
	while (query.next()) {
contactpersonfields.append(new ContactPersonField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
qStableSort(contactpersonfields.begin(),contactpersonfields.end());
	return contactpersonfields;
}

ContactPersonField* ContactPersonField::Get(int id) {
ContactPersonField* contactpersonfield = new ContactPersonField();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonField WHERE ContactPersonFieldID = '"+QString::number(id)+"'"));
while (query.next()) {
contactpersonfield = new ContactPersonField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return contactpersonfield;
}

ContactPersonField* ContactPersonField::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactPersonField();
}

ContactPersonField* ContactPersonField::Get(QString name) {
ContactPersonField* contactpersonfield = new ContactPersonField();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonField WHERE Description = '"+name+"'"));
while (query.next()) {
contactpersonfield = new ContactPersonField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return contactpersonfield;
 }

QList<ContactPersonField*> ContactPersonField::Search(QString keyword) {
QList<ContactPersonField*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonField"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPersonField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ContactPersonField::GetStringList() {
	QList<QString> list;
	QList<ContactPersonField*> contactpersonfields =   QList<ContactPersonField*>();
contactpersonfields = GetAll();
	for(int i = 0; i <contactpersonfields.count(); i++){
		list.append(contactpersonfields[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> ContactPersonField::GetHashList() {
	QHash<int,QString> list;
	QList<ContactPersonField*> contactpersonfields =   QList<ContactPersonField*>();
contactpersonfields = GetAll();
	for(int i = 0; i <contactpersonfields.count(); i++){
		list.insert(contactpersonfields[i]->ContactPersonFieldID,contactpersonfields[i]->Description);
	}
	return list;
}

int ContactPersonField::GetIndex(QString name) {
	QList<ContactPersonField*> contactpersonfields =   QList<ContactPersonField*>();
contactpersonfields = GetAll();
	for(int i = 0; i <contactpersonfields.count(); i++){
		if(contactpersonfields[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ContactPersonField*> ContactPersonField::QuerySelect(QString select) {
QList<ContactPersonField*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonField WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactPersonField(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactPersonField::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactPersonField::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setFieldTypeID(id, value.toString());
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

bool ContactPersonField::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactPersonFieldID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactPersonField::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactPersonField!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Field Type"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Defaults"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactPersonField::setDescription(int ContactPersonFieldID, const QString &Description) {
QSqlQuery query;
query.prepare("update ContactPersonField set Description = ? where ContactPersonFieldID = ?");
query.addBindValue(Description);
query.addBindValue(ContactPersonFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonField::setFieldTypeID(int ContactPersonFieldID, const QString &FieldTypeID) {
QSqlQuery query;
query.prepare("update ContactPersonField set FieldTypeID = ? where ContactPersonFieldID = ?");
query.addBindValue(FieldTypeID);
query.addBindValue(ContactPersonFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonField::setDefaults(int ContactPersonFieldID, const QString &Defaults) {
QSqlQuery query;
query.prepare("update ContactPersonField set Defaults = ? where ContactPersonFieldID = ?");
query.addBindValue(Defaults);
query.addBindValue(ContactPersonFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonField::setCreatedOn(int ContactPersonFieldID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactPersonField set CreatedOn = ? where ContactPersonFieldID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactPersonFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonField::setEditedOn(int ContactPersonFieldID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactPersonField set EditedOn = ? where ContactPersonFieldID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactPersonFieldID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

