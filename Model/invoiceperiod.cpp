/**************************************************************************
**   File: invoiceperiod.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoiceperiod.h"
#include "erpmodel.h"

InvoicePeriod::InvoicePeriod()
 : QSqlRelationalTableModel(){

this->InvoicePeriodID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoicePeriod");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
InvoicePeriod::InvoicePeriod(int InvoicePeriodID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoicePeriodID = InvoicePeriodID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoicePeriod::InvoicePeriod(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoicePeriodID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoicePeriod::Init()
{

QString table = "InvoicePeriod";
QString query =
"(InvoicePeriodID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoicePeriodID),"
"Description VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
InvoicePeriod* InvoicePeriod::p_instance = 0;
InvoicePeriod* InvoicePeriod::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoicePeriod();
		InvoicePeriod::GetAll();
	}
return p_instance;
}
bool InvoicePeriod::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(InvoicePeriodID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoicePeriod (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoicePeriod SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoicePeriodID ='"+QString::number(this->InvoicePeriodID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoicePeriodID FROM InvoicePeriod WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoicePeriodID = query.value(0).toInt();	
 } 
 }
return true;
}

bool InvoicePeriod::remove() {
if(InvoicePeriodID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoicePeriod WHERE InvoicePeriodID ="+QString::number(this->InvoicePeriodID)+""));
return true;
 }
return false;
}

InvoicePeriod* InvoicePeriod::get() {
if(InvoicePeriodID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoicePeriod"
"WHERE InvoicePeriodID ='"+QString::number(this->InvoicePeriodID)+"'"));
while (query.next()) {
return new InvoicePeriod(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new InvoicePeriod();
 }

QList<InvoicePeriod*> InvoicePeriod::GetAll() {
	QList<InvoicePeriod*> invoiceperiods =   QList<InvoicePeriod*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoicePeriod"));
	while (query.next()) {
invoiceperiods.append(new InvoicePeriod(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
qStableSort(invoiceperiods.begin(),invoiceperiods.end());
	return invoiceperiods;
}

InvoicePeriod* InvoicePeriod::Get(int id) {
InvoicePeriod* invoiceperiod = new InvoicePeriod();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoicePeriod WHERE InvoicePeriodID = '"+QString::number(id)+"'"));
while (query.next()) {
invoiceperiod = new InvoicePeriod(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return invoiceperiod;
}

InvoicePeriod* InvoicePeriod::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoicePeriod();
}

InvoicePeriod* InvoicePeriod::Get(QString name) {
InvoicePeriod* invoiceperiod = new InvoicePeriod();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoicePeriod WHERE Description = '"+name+"'"));
while (query.next()) {
invoiceperiod = new InvoicePeriod(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return invoiceperiod;
 }

QList<InvoicePeriod*> InvoicePeriod::Search(QString keyword) {
QList<InvoicePeriod*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoicePeriod"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoicePeriod(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> InvoicePeriod::GetStringList() {
	QList<QString> list;
	QList<InvoicePeriod*> invoiceperiods =   QList<InvoicePeriod*>();
invoiceperiods = GetAll();
	for(int i = 0; i <invoiceperiods.count(); i++){
		list.append(invoiceperiods[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> InvoicePeriod::GetHashList() {
	QHash<int,QString> list;
	QList<InvoicePeriod*> invoiceperiods =   QList<InvoicePeriod*>();
invoiceperiods = GetAll();
	for(int i = 0; i <invoiceperiods.count(); i++){
		list.insert(invoiceperiods[i]->InvoicePeriodID,invoiceperiods[i]->Description);
	}
	return list;
}

int InvoicePeriod::GetIndex(QString name) {
	QList<InvoicePeriod*> invoiceperiods =   QList<InvoicePeriod*>();
invoiceperiods = GetAll();
	for(int i = 0; i <invoiceperiods.count(); i++){
		if(invoiceperiods[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<InvoicePeriod*> InvoicePeriod::QuerySelect(QString select) {
QList<InvoicePeriod*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoicePeriod WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoicePeriod(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoicePeriod::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoicePeriod::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool InvoicePeriod::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoicePeriodID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoicePeriod::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoicePeriod!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoicePeriod::setDescription(int InvoicePeriodID, const QString &Description) {
QSqlQuery query;
query.prepare("update InvoicePeriod set Description = ? where InvoicePeriodID = ?");
query.addBindValue(Description);
query.addBindValue(InvoicePeriodID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoicePeriod::setCreatedOn(int InvoicePeriodID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoicePeriod set CreatedOn = ? where InvoicePeriodID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoicePeriodID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoicePeriod::setEditedOn(int InvoicePeriodID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoicePeriod set EditedOn = ? where InvoicePeriodID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoicePeriodID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

