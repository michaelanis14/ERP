/**************************************************************************
**   File: fieldtype.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "fieldtype.h"
#include "erpmodel.h"

FieldType::FieldType()
 : QSqlRelationalTableModel(){

this->FieldTypeID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("FieldType");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
FieldType::FieldType(int FieldTypeID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->FieldTypeID = FieldTypeID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

FieldType::FieldType(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->FieldTypeID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool FieldType::Init()
{

QString table = "FieldType";
QString query =
"(FieldTypeID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (FieldTypeID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("FieldTypeID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
FieldType* FieldType::p_instance = 0;
FieldType* FieldType::GetInstance() {
	if (p_instance == 0) {
		p_instance = new FieldType();
		FieldType::GetAll();
	}
return p_instance;
}
bool FieldType::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(FieldTypeID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO FieldType (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE FieldType SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE FieldTypeID ='"+QString::number(this->FieldTypeID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  FieldTypeID FROM FieldType WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->FieldTypeID = query.value(0).toInt();	
 } 
 }
return true;
}
bool FieldType::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool FieldType::remove() {
if(FieldTypeID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM FieldType WHERE FieldTypeID ="+QString::number(this->FieldTypeID)+""));
return true;
 }
return false;
}

FieldType* FieldType::get() {
if(FieldTypeID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM FieldType"
"WHERE FieldTypeID ='"+QString::number(this->FieldTypeID)+"'"));
while (query.next()) {
return new FieldType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new FieldType();
 }

QList<FieldType*> FieldType::GetAll() {
	QList<FieldType*> fieldtypes =   QList<FieldType*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM FieldType ORDER BY FieldTypeID ASC"));
	while (query.next()) {
fieldtypes.append(new FieldType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return fieldtypes;
}

FieldType* FieldType::Get(int id) {
FieldType* fieldtype = new FieldType();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM FieldType WHERE FieldTypeID = '"+QString::number(id)+"' ORDER BY FieldTypeID ASC "));
while (query.next()) {
fieldtype = new FieldType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return fieldtype;
}

FieldType* FieldType::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new FieldType();
}

FieldType* FieldType::Get(QString name) {
FieldType* fieldtype = new FieldType();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM FieldType WHERE Description = '"+name+"'"));
while (query.next()) {
fieldtype = new FieldType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return fieldtype;
 }

QList<FieldType*> FieldType::Search(QString keyword) {
QList<FieldType*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM FieldType"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new FieldType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> FieldType::GetStringList() {
	QList<QString> list;
	QList<FieldType*> fieldtypes =   QList<FieldType*>();
fieldtypes = GetAll();
	for(int i = 0; i <fieldtypes.count(); i++){
		list.append(fieldtypes[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > FieldType::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<FieldType*> fieldtypes =   QList<FieldType*>();
fieldtypes = GetAll();
	for(int i = 0; i <fieldtypes.count(); i++){
		list.append(qMakePair(fieldtypes[i]->FieldTypeID,fieldtypes[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > FieldType::GetPairList(QList<FieldType*> fieldtypes) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <fieldtypes.count(); i++){
		list.append(qMakePair(fieldtypes[i]->FieldTypeID,fieldtypes[i]->Description));
	}
	return list;
}

int FieldType::GetIndex(QString name) {
	QList<FieldType*> fieldtypes =   QList<FieldType*>();
fieldtypes = GetAll();
	for(int i = 0; i <fieldtypes.count(); i++){
		if(fieldtypes[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<FieldType*> FieldType::QuerySelect(QString select) {
QList<FieldType*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM FieldType WHERE "+select+"" ));
while (query.next()) {
list.append(new FieldType(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags FieldType::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool FieldType::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool FieldType::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->FieldTypeID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void FieldType::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() FieldType!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool FieldType::setDescription(int FieldTypeID, const QString &Description) {
QSqlQuery query;
query.prepare("update FieldType set Description = ? where FieldTypeID = ?");
query.addBindValue(Description);
query.addBindValue(FieldTypeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool FieldType::setCreatedOn(int FieldTypeID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update FieldType set CreatedOn = ? where FieldTypeID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(FieldTypeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool FieldType::setEditedOn(int FieldTypeID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update FieldType set EditedOn = ? where FieldTypeID = ?");
query.addBindValue(EditedOn);
query.addBindValue(FieldTypeID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

