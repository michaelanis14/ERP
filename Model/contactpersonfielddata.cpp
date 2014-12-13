/**************************************************************************
**   File: contactpersonfielddata.cpp
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contactpersonfielddata.h"
#include "erpmodel.h"

ContactPersonFieldData::ContactPersonFieldData()
 : QSqlRelationalTableModel(){

this->ContactPersonFieldDataID = 0 ;
this->ContactPersonID = 0 ;
this->ContactPersonFieldID = 0 ;
this->Value = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ContactPersonFieldData");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("ContactPerson", "ContactPersonID", "Title"));
this->setRelation(1, QSqlRelation("ContactPerson", "ContactPersonID", "TitleName"));
this->setRelation(2, QSqlRelation("ContactPersonField", "ContactPersonFieldID", "Description"));
}
ContactPersonFieldData::ContactPersonFieldData(int ContactPersonFieldDataID,int ContactPersonID,int ContactPersonFieldID,QString Value,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonFieldDataID = ContactPersonFieldDataID ;
this->ContactPersonID = ContactPersonID ;
this->ContactPersonFieldID = ContactPersonFieldID ;
this->Value = Value ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ContactPersonFieldData::ContactPersonFieldData(int ContactPersonID,int ContactPersonFieldID,QString Value,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactPersonFieldDataID = 0 ;
this->ContactPersonID = ContactPersonID ;
this->ContactPersonFieldID = ContactPersonFieldID ;
this->Value = Value ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ContactPersonFieldData::Init()
{

QString table = "ContactPersonFieldData";
QString query =
"(ContactPersonFieldDataID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactPersonFieldDataID),"
"ContactPersonID INT NOT NULL, "
" KEY(ContactPersonID),"
"FOREIGN KEY (ContactPersonID) REFERENCES ContactPerson(ContactPersonID)  ON DELETE CASCADE,"
"ContactPersonFieldID INT NOT NULL, "
"FOREIGN KEY (ContactPersonFieldID) REFERENCES ContactPersonField(ContactPersonFieldID)  ON DELETE CASCADE,"
"Value VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ContactPersonFieldDataID")));variables.append(qMakePair(QString(" INT"),QString("ContactPersonID")));variables.append(qMakePair(QString(" INT"),QString("ContactPersonFieldID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Value")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ContactPersonFieldData* ContactPersonFieldData::p_instance = 0;
ContactPersonFieldData* ContactPersonFieldData::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ContactPersonFieldData();
		ContactPersonFieldData::GetAll();
	}
return p_instance;
}
bool ContactPersonFieldData::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactPersonFieldDataID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ContactPersonFieldData (ContactPersonID,ContactPersonFieldID,Value,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ContactPersonID)+"','"+QString::number(this->ContactPersonFieldID)+"','"+QString(this->Value)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ContactPersonFieldData SET "	"ContactPersonID = '"+QString::number(this->ContactPersonID)+"',"+"ContactPersonFieldID = '"+QString::number(this->ContactPersonFieldID)+"',"+"Value = '"+QString(this->Value)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactPersonFieldDataID ='"+QString::number(this->ContactPersonFieldDataID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactPersonFieldDataID FROM ContactPersonFieldData WHERE ContactPersonID = "+QString::number(ContactPersonID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactPersonFieldDataID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ContactPersonFieldData::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ContactPersonFieldData::remove() {
if(ContactPersonFieldDataID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ContactPersonFieldData WHERE ContactPersonFieldDataID ="+QString::number(this->ContactPersonFieldDataID)+""));
return true;
 }
return false;
}

ContactPersonFieldData* ContactPersonFieldData::get() {
if(ContactPersonFieldDataID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonFieldData"
"WHERE ContactPersonFieldDataID ='"+QString::number(this->ContactPersonFieldDataID)+"'"));
while (query.next()) {
return new ContactPersonFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ContactPersonFieldData();
 }

QList<ContactPersonFieldData*> ContactPersonFieldData::GetAll() {
	QList<ContactPersonFieldData*> contactpersonfielddatas =   QList<ContactPersonFieldData*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonFieldData ORDER BY ContactPersonFieldDataID ASC"));
	while (query.next()) {
contactpersonfielddatas.append(new ContactPersonFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
	}
	return contactpersonfielddatas;
}

ContactPersonFieldData* ContactPersonFieldData::Get(int id) {
ContactPersonFieldData* contactpersonfielddata = new ContactPersonFieldData();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ContactPersonFieldData WHERE ContactPersonFieldDataID = '"+QString::number(id)+"' ORDER BY ContactPersonFieldDataID ASC "));
while (query.next()) {
contactpersonfielddata = new ContactPersonFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
 }

}
return contactpersonfielddata;
}

ContactPersonFieldData* ContactPersonFieldData::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ContactPersonFieldData();
}

ContactPersonFieldData* ContactPersonFieldData::Get(QString name) {
ContactPersonFieldData* contactpersonfielddata = new ContactPersonFieldData();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonFieldData WHERE ContactPersonID = QString::number("+name+")"));
while (query.next()) {
contactpersonfielddata = new ContactPersonFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString());

 }

}
return contactpersonfielddata;
 }

QList<ContactPersonFieldData*> ContactPersonFieldData::Search(QString keyword) {
QList<ContactPersonFieldData*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonFieldData"
"WHERE" 
"Value LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ContactPersonFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ContactPersonFieldData::GetStringList() {
	QList<QString> list;
	QList<ContactPersonFieldData*> contactpersonfielddatas =   QList<ContactPersonFieldData*>();
contactpersonfielddatas = GetAll();
	for(int i = 0; i <contactpersonfielddatas.count(); i++){
		list.append(contactpersonfielddatas[i]->Value);
	}
	return list;
}

QList<QPair< int,QString > > ContactPersonFieldData::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ContactPersonFieldData*> contactpersonfielddatas =   QList<ContactPersonFieldData*>();
contactpersonfielddatas = GetAll();
	for(int i = 0; i <contactpersonfielddatas.count(); i++){
		list.append(qMakePair(contactpersonfielddatas[i]->ContactPersonFieldDataID,QString::number(contactpersonfielddatas[i]->ContactPersonID)));
	}
	return list;
}

QList<QPair< int,QString > > ContactPersonFieldData::GetPairList(QList<ContactPersonFieldData*> contactpersonfielddatas) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <contactpersonfielddatas.count(); i++){
		list.append(qMakePair(contactpersonfielddatas[i]->ContactPersonFieldDataID,QString::number(contactpersonfielddatas[i]->ContactPersonID)));
	}
	return list;
}

int ContactPersonFieldData::GetIndex(QString name) {
	QList<ContactPersonFieldData*> contactpersonfielddatas =   QList<ContactPersonFieldData*>();
contactpersonfielddatas = GetAll();
	for(int i = 0; i <contactpersonfielddatas.count(); i++){
		if(contactpersonfielddatas[i]->ContactPersonID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ContactPersonFieldData*> ContactPersonFieldData::QuerySelect(QString select) {
QList<ContactPersonFieldData*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ContactPersonFieldData WHERE "+select+"" ));
while (query.next()) {
list.append(new ContactPersonFieldData(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ContactPersonFieldData::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ContactPersonFieldData::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setContactPersonID(id, value.toString());
else if (index.column() == 2)
ok = setContactPersonFieldID(id, value.toString());
else if (index.column() == 3)
ok = setValue(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ContactPersonFieldData::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactPersonFieldDataID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ContactPersonFieldData::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ContactPersonFieldData!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Contact Person"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Contact Person Field"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Value"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ContactPersonFieldData::setContactPersonID(int ContactPersonFieldDataID, const QString &ContactPersonID) {
QSqlQuery query;
query.prepare("update ContactPersonFieldData set ContactPersonID = ? where ContactPersonFieldDataID = ?");
query.addBindValue(ContactPersonID);
query.addBindValue(ContactPersonFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonFieldData::setContactPersonFieldID(int ContactPersonFieldDataID, const QString &ContactPersonFieldID) {
QSqlQuery query;
query.prepare("update ContactPersonFieldData set ContactPersonFieldID = ? where ContactPersonFieldDataID = ?");
query.addBindValue(ContactPersonFieldID);
query.addBindValue(ContactPersonFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonFieldData::setValue(int ContactPersonFieldDataID, const QString &Value) {
QSqlQuery query;
query.prepare("update ContactPersonFieldData set Value = ? where ContactPersonFieldDataID = ?");
query.addBindValue(Value);
query.addBindValue(ContactPersonFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonFieldData::setCreatedOn(int ContactPersonFieldDataID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ContactPersonFieldData set CreatedOn = ? where ContactPersonFieldDataID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactPersonFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ContactPersonFieldData::setEditedOn(int ContactPersonFieldDataID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ContactPersonFieldData set EditedOn = ? where ContactPersonFieldDataID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactPersonFieldDataID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

