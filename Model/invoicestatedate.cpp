/**************************************************************************
**   File: invoicestatedate.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoicestatedate.h"
#include "erpmodel.h"

InvoiceStateDate::InvoiceStateDate()
 : QSqlRelationalTableModel(){

this->InvoiceStateDateID = 0 ;
this->InvoiceID = 0 ;
this->InvoiceStateID = 0 ;
this->Date = QDate();
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceStateDate");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("InvoiceState", "InvoiceStateID", "Description"));
}
InvoiceStateDate::InvoiceStateDate(int InvoiceStateDateID,int InvoiceID,int InvoiceStateID,QDate Date,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceStateDateID = InvoiceStateDateID ;
this->InvoiceID = InvoiceID ;
this->InvoiceStateID = InvoiceStateID ;
this->Date = Date ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceStateDate::InvoiceStateDate(int InvoiceID,int InvoiceStateID,QDate Date,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceStateDateID = 0 ;
this->InvoiceID = InvoiceID ;
this->InvoiceStateID = InvoiceStateID ;
this->Date = Date ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceStateDate::Init()
{

QString table = "InvoiceStateDate";
QString query =
"(InvoiceStateDateID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceStateDateID),"
"InvoiceID INT NOT NULL, "
" KEY(InvoiceID),"
"FOREIGN KEY (InvoiceID) REFERENCES Invoice(InvoiceID)  ON DELETE CASCADE,"
"InvoiceStateID INT NOT NULL, "
"FOREIGN KEY (InvoiceStateID) REFERENCES InvoiceState(InvoiceStateID)  ON DELETE CASCADE,"
"Date DATE NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceStateDateID")));variables.append(qMakePair(QString(" INT"),QString("InvoiceID")));variables.append(qMakePair(QString(" INT"),QString("InvoiceStateID")));variables.append(qMakePair(QString(""),QString("Date")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
InvoiceStateDate* InvoiceStateDate::p_instance = 0;
InvoiceStateDate* InvoiceStateDate::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceStateDate();
		InvoiceStateDate::GetAll();
	}
return p_instance;
}
bool InvoiceStateDate::save() {
this->EditedOn = QDate::currentDate().toString();
if(InvoiceStateDateID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceStateDate (InvoiceID,InvoiceStateID,Date,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->InvoiceID)+"','"+QString::number(this->InvoiceStateID)+"','"+(this->Date.toString("yyyy-MM-dd"))+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceStateDate SET "	"InvoiceID = '"+QString::number(this->InvoiceID)+"',"+"InvoiceStateID = '"+QString::number(this->InvoiceStateID)+"',"+"Date = '"+(this->Date.toString("yyyy-MM-dd"))+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceStateDateID ='"+QString::number(this->InvoiceStateDateID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceStateDateID FROM InvoiceStateDate WHERE InvoiceID = "+QString::number(InvoiceID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceStateDateID = query.value(0).toInt();	
 } 
 }
return true;
}
bool InvoiceStateDate::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool InvoiceStateDate::remove() {
if(InvoiceStateDateID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceStateDate WHERE InvoiceStateDateID ="+QString::number(this->InvoiceStateDateID)+""));
return true;
 }
return false;
}

InvoiceStateDate* InvoiceStateDate::get() {
if(InvoiceStateDateID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceStateDate"
"WHERE InvoiceStateDateID ='"+QString::number(this->InvoiceStateDateID)+"'"));
while (query.next()) {
return new InvoiceStateDate(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString());
 }

}
return new InvoiceStateDate();
 }

QList<InvoiceStateDate*> InvoiceStateDate::GetAll() {
	QList<InvoiceStateDate*> invoicestatedates =   QList<InvoiceStateDate*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStateDate ORDER BY InvoiceStateDateID ASC"));
	while (query.next()) {
invoicestatedates.append(new InvoiceStateDate(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString()));
	}
	return invoicestatedates;
}

InvoiceStateDate* InvoiceStateDate::Get(int id) {
InvoiceStateDate* invoicestatedate = new InvoiceStateDate();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceStateDate WHERE InvoiceStateDateID = '"+QString::number(id)+"' ORDER BY InvoiceStateDateID ASC "));
while (query.next()) {
invoicestatedate = new InvoiceStateDate(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString());
 }

}
return invoicestatedate;
}

InvoiceStateDate* InvoiceStateDate::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceStateDate();
}

InvoiceStateDate* InvoiceStateDate::Get(QString name) {
InvoiceStateDate* invoicestatedate = new InvoiceStateDate();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStateDate WHERE InvoiceID = QString::number("+name+")"));
while (query.next()) {
invoicestatedate = new InvoiceStateDate(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString());

 }

}
return invoicestatedate;
 }

QList<InvoiceStateDate*> InvoiceStateDate::Search(QString keyword) {
QList<InvoiceStateDate*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStateDate"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceStateDate(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> InvoiceStateDate::GetStringList() {
	QList<QString> list;
	QList<InvoiceStateDate*> invoicestatedates =   QList<InvoiceStateDate*>();
invoicestatedates = GetAll();
	for(int i = 0; i <invoicestatedates.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > InvoiceStateDate::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<InvoiceStateDate*> invoicestatedates =   QList<InvoiceStateDate*>();
invoicestatedates = GetAll();
	for(int i = 0; i <invoicestatedates.count(); i++){
		list.append(qMakePair(invoicestatedates[i]->InvoiceStateDateID,QString::number(invoicestatedates[i]->InvoiceID)));
	}
	return list;
}

QList<QPair< int,QString > > InvoiceStateDate::GetPairList(QList<InvoiceStateDate*> invoicestatedates) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoicestatedates.count(); i++){
		list.append(qMakePair(invoicestatedates[i]->InvoiceStateDateID,QString::number(invoicestatedates[i]->InvoiceID)));
	}
	return list;
}

int InvoiceStateDate::GetIndex(QString name) {
	QList<InvoiceStateDate*> invoicestatedates =   QList<InvoiceStateDate*>();
invoicestatedates = GetAll();
	for(int i = 0; i <invoicestatedates.count(); i++){
		if(invoicestatedates[i]->InvoiceID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<InvoiceStateDate*> InvoiceStateDate::QuerySelect(QString select) {
QList<InvoiceStateDate*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceStateDate WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceStateDate(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toDate(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceStateDate::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceStateDate::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setInvoiceID(id, value.toString());
else if (index.column() == 2)
ok = setInvoiceStateID(id, value.toString());
else if (index.column() == 3)
ok = setDate(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool InvoiceStateDate::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceStateDateID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceStateDate::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceStateDate!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Invoice"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Invoice State"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoiceStateDate::setInvoiceID(int InvoiceStateDateID, const QString &InvoiceID) {
QSqlQuery query;
query.prepare("update InvoiceStateDate set InvoiceID = ? where InvoiceStateDateID = ?");
query.addBindValue(InvoiceID);
query.addBindValue(InvoiceStateDateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStateDate::setInvoiceStateID(int InvoiceStateDateID, const QString &InvoiceStateID) {
QSqlQuery query;
query.prepare("update InvoiceStateDate set InvoiceStateID = ? where InvoiceStateDateID = ?");
query.addBindValue(InvoiceStateID);
query.addBindValue(InvoiceStateDateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStateDate::setDate(int InvoiceStateDateID, const QString &Date) {
QSqlQuery query;
query.prepare("update InvoiceStateDate set Date = ? where InvoiceStateDateID = ?");
query.addBindValue(Date);
query.addBindValue(InvoiceStateDateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStateDate::setCreatedOn(int InvoiceStateDateID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceStateDate set CreatedOn = ? where InvoiceStateDateID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceStateDateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceStateDate::setEditedOn(int InvoiceStateDateID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceStateDate set EditedOn = ? where InvoiceStateDateID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceStateDateID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

