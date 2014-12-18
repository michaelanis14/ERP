/**************************************************************************
**   File: invoiceyear.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoiceyear.h"
#include "erpmodel.h"

InvoiceYear::InvoiceYear()
 : QSqlRelationalTableModel(){

this->InvoiceYearID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceYear");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
InvoiceYear::InvoiceYear(int InvoiceYearID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceYearID = InvoiceYearID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceYear::InvoiceYear(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceYearID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceYear::Init()
{

QString table = "InvoiceYear";
QString query =
"(InvoiceYearID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceYearID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceYearID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
InvoiceYear* InvoiceYear::p_instance = 0;
InvoiceYear* InvoiceYear::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceYear();
		InvoiceYear::GetAll();
	}
return p_instance;
}
bool InvoiceYear::save() {
this->EditedOn = QDate::currentDate().toString();
if(InvoiceYearID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceYear (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceYear SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceYearID ='"+QString::number(this->InvoiceYearID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceYearID FROM InvoiceYear WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceYearID = query.value(0).toInt();	
 } 
 }
return true;
}
bool InvoiceYear::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool InvoiceYear::remove() {
if(InvoiceYearID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceYear WHERE InvoiceYearID ="+QString::number(this->InvoiceYearID)+""));
return true;
 }
return false;
}

InvoiceYear* InvoiceYear::get() {
if(InvoiceYearID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceYear"
"WHERE InvoiceYearID ='"+QString::number(this->InvoiceYearID)+"'"));
while (query.next()) {
return new InvoiceYear(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new InvoiceYear();
 }

QList<InvoiceYear*> InvoiceYear::GetAll() {
	QList<InvoiceYear*> invoiceyears =   QList<InvoiceYear*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceYear ORDER BY InvoiceYearID ASC"));
	while (query.next()) {
invoiceyears.append(new InvoiceYear(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return invoiceyears;
}

InvoiceYear* InvoiceYear::Get(int id) {
InvoiceYear* invoiceyear = new InvoiceYear();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceYear WHERE InvoiceYearID = '"+QString::number(id)+"' ORDER BY InvoiceYearID ASC "));
while (query.next()) {
invoiceyear = new InvoiceYear(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return invoiceyear;
}

InvoiceYear* InvoiceYear::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceYear();
}

InvoiceYear* InvoiceYear::Get(QString name) {
InvoiceYear* invoiceyear = new InvoiceYear();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceYear WHERE Description = '"+name+"'"));
while (query.next()) {
invoiceyear = new InvoiceYear(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return invoiceyear;
 }

QList<InvoiceYear*> InvoiceYear::Search(QString keyword) {
QList<InvoiceYear*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceYear"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceYear(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> InvoiceYear::GetStringList() {
	QList<QString> list;
	QList<InvoiceYear*> invoiceyears =   QList<InvoiceYear*>();
invoiceyears = GetAll();
	for(int i = 0; i <invoiceyears.count(); i++){
		list.append(invoiceyears[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > InvoiceYear::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<InvoiceYear*> invoiceyears =   QList<InvoiceYear*>();
invoiceyears = GetAll();
	for(int i = 0; i <invoiceyears.count(); i++){
		list.append(qMakePair(invoiceyears[i]->InvoiceYearID,invoiceyears[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > InvoiceYear::GetPairList(QList<InvoiceYear*> invoiceyears) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoiceyears.count(); i++){
		list.append(qMakePair(invoiceyears[i]->InvoiceYearID,invoiceyears[i]->Description));
	}
	return list;
}

int InvoiceYear::GetIndex(QString name) {
	QList<InvoiceYear*> invoiceyears =   QList<InvoiceYear*>();
invoiceyears = GetAll();
	for(int i = 0; i <invoiceyears.count(); i++){
		if(invoiceyears[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<InvoiceYear*> InvoiceYear::QuerySelect(QString select) {
QList<InvoiceYear*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceYear WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceYear(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceYear::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceYear::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool InvoiceYear::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceYearID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceYear::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceYear!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoiceYear::setDescription(int InvoiceYearID, const QString &Description) {
QSqlQuery query;
query.prepare("update InvoiceYear set Description = ? where InvoiceYearID = ?");
query.addBindValue(Description);
query.addBindValue(InvoiceYearID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceYear::setCreatedOn(int InvoiceYearID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceYear set CreatedOn = ? where InvoiceYearID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceYearID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceYear::setEditedOn(int InvoiceYearID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceYear set EditedOn = ? where InvoiceYearID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceYearID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

