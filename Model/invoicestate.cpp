/**************************************************************************
**   File: invoicestate.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoicestate.h"
#include "erpmodel.h"

InvoiceState::InvoiceState()
 : QSqlRelationalTableModel(){

this->InvoiceStateID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceState");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
InvoiceState::InvoiceState(int InvoiceStateID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceStateID = InvoiceStateID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceState::InvoiceState(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceStateID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceState::Init()
{

QString table = "InvoiceState";
QString query =
"(InvoiceStateID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceStateID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceStateID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
InvoiceState* InvoiceState::p_instance = 0;
InvoiceState* InvoiceState::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceState();
		InvoiceState::GetAll();
	}
return p_instance;
}
bool InvoiceState::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(InvoiceStateID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceState (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceState SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceStateID ='"+QString::number(this->InvoiceStateID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceStateID FROM InvoiceState WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceStateID = query.value(0).toInt();	
 } 
 }
return true;
}
bool InvoiceState::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool InvoiceState::remove() {
if(InvoiceStateID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceState WHERE InvoiceStateID ="+QString::number(this->InvoiceStateID)+""));
return true;
 }
return false;
}

InvoiceState* InvoiceState::get() {
if(InvoiceStateID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceState"
"WHERE InvoiceStateID ='"+QString::number(this->InvoiceStateID)+"'"));
while (query.next()) {
return new InvoiceState(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new InvoiceState();
 }

QList<InvoiceState*> InvoiceState::GetAll() {
	QList<InvoiceState*> invoicestates =   QList<InvoiceState*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceState ORDER BY InvoiceStateID ASC"));
	while (query.next()) {
invoicestates.append(new InvoiceState(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return invoicestates;
}

InvoiceState* InvoiceState::Get(int id) {
InvoiceState* invoicestate = new InvoiceState();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceState WHERE InvoiceStateID = '"+QString::number(id)+"' ORDER BY InvoiceStateID ASC "));
while (query.next()) {
invoicestate = new InvoiceState(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return invoicestate;
}

InvoiceState* InvoiceState::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceState();
}

InvoiceState* InvoiceState::Get(QString name) {
InvoiceState* invoicestate = new InvoiceState();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceState WHERE Description = '"+name+"'"));
while (query.next()) {
invoicestate = new InvoiceState(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return invoicestate;
 }

QList<InvoiceState*> InvoiceState::Search(QString keyword) {
QList<InvoiceState*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceState"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceState(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> InvoiceState::GetStringList() {
	QList<QString> list;
	QList<InvoiceState*> invoicestates =   QList<InvoiceState*>();
invoicestates = GetAll();
	for(int i = 0; i <invoicestates.count(); i++){
		list.append(invoicestates[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > InvoiceState::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<InvoiceState*> invoicestates =   QList<InvoiceState*>();
invoicestates = GetAll();
	for(int i = 0; i <invoicestates.count(); i++){
		list.append(qMakePair(invoicestates[i]->InvoiceStateID,invoicestates[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > InvoiceState::GetPairList(QList<InvoiceState*> invoicestates) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoicestates.count(); i++){
		list.append(qMakePair(invoicestates[i]->InvoiceStateID,invoicestates[i]->Description));
	}
	return list;
}

int InvoiceState::GetIndex(QString name) {
	QList<InvoiceState*> invoicestates =   QList<InvoiceState*>();
invoicestates = GetAll();
	for(int i = 0; i <invoicestates.count(); i++){
		if(invoicestates[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<InvoiceState*> InvoiceState::QuerySelect(QString select) {
QList<InvoiceState*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceState WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceState(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceState::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceState::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool InvoiceState::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceStateID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceState::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceState!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoiceState::setDescription(int InvoiceStateID, const QString &Description) {
QSqlQuery query;
query.prepare("update InvoiceState set Description = ? where InvoiceStateID = ?");
query.addBindValue(Description);
query.addBindValue(InvoiceStateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceState::setCreatedOn(int InvoiceStateID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceState set CreatedOn = ? where InvoiceStateID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceStateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceState::setEditedOn(int InvoiceStateID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceState set EditedOn = ? where InvoiceStateID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceStateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

