/**************************************************************************
**   File: purchasestatus.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchasestatus.h"
#include "erpmodel.h"

PurchaseStatus::PurchaseStatus()
 : QSqlRelationalTableModel(){

this->PurchaseStatusID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("PurchaseStatus");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
PurchaseStatus::PurchaseStatus(int PurchaseStatusID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseStatusID = PurchaseStatusID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

PurchaseStatus::PurchaseStatus(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseStatusID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool PurchaseStatus::Init()
{

QString table = "PurchaseStatus";
QString query =
"(PurchaseStatusID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PurchaseStatusID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("PurchaseStatusID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
PurchaseStatus* PurchaseStatus::p_instance = 0;
PurchaseStatus* PurchaseStatus::GetInstance() {
	if (p_instance == 0) {
		p_instance = new PurchaseStatus();
		PurchaseStatus::GetAll();
	}
return p_instance;
}
bool PurchaseStatus::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(PurchaseStatusID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO PurchaseStatus (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE PurchaseStatus SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseStatusID ='"+QString::number(this->PurchaseStatusID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseStatusID FROM PurchaseStatus WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PurchaseStatusID = query.value(0).toInt();	
 } 
 }
return true;
}
bool PurchaseStatus::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool PurchaseStatus::remove() {
if(PurchaseStatusID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM PurchaseStatus WHERE PurchaseStatusID ="+QString::number(this->PurchaseStatusID)+""));
return true;
 }
return false;
}

PurchaseStatus* PurchaseStatus::get() {
if(PurchaseStatusID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseStatus"
"WHERE PurchaseStatusID ='"+QString::number(this->PurchaseStatusID)+"'"));
while (query.next()) {
return new PurchaseStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new PurchaseStatus();
 }

QList<PurchaseStatus*> PurchaseStatus::GetAll() {
	QList<PurchaseStatus*> purchasestatuss =   QList<PurchaseStatus*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStatus ORDER BY PurchaseStatusID ASC"));
	while (query.next()) {
purchasestatuss.append(new PurchaseStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return purchasestatuss;
}

PurchaseStatus* PurchaseStatus::Get(int id) {
PurchaseStatus* purchasestatus = new PurchaseStatus();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseStatus WHERE PurchaseStatusID = '"+QString::number(id)+"' ORDER BY PurchaseStatusID ASC "));
while (query.next()) {
purchasestatus = new PurchaseStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return purchasestatus;
}

PurchaseStatus* PurchaseStatus::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new PurchaseStatus();
}

PurchaseStatus* PurchaseStatus::Get(QString name) {
PurchaseStatus* purchasestatus = new PurchaseStatus();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStatus WHERE Description = '"+name+"'"));
while (query.next()) {
purchasestatus = new PurchaseStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return purchasestatus;
 }

QList<PurchaseStatus*> PurchaseStatus::Search(QString keyword) {
QList<PurchaseStatus*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStatus"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new PurchaseStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> PurchaseStatus::GetStringList() {
	QList<QString> list;
	QList<PurchaseStatus*> purchasestatuss =   QList<PurchaseStatus*>();
purchasestatuss = GetAll();
	for(int i = 0; i <purchasestatuss.count(); i++){
		list.append(purchasestatuss[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > PurchaseStatus::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<PurchaseStatus*> purchasestatuss =   QList<PurchaseStatus*>();
purchasestatuss = GetAll();
	for(int i = 0; i <purchasestatuss.count(); i++){
		list.append(qMakePair(purchasestatuss[i]->PurchaseStatusID,purchasestatuss[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > PurchaseStatus::GetPairList(QList<PurchaseStatus*> purchasestatuss) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <purchasestatuss.count(); i++){
		list.append(qMakePair(purchasestatuss[i]->PurchaseStatusID,purchasestatuss[i]->Description));
	}
	return list;
}

int PurchaseStatus::GetIndex(QString name) {
	QList<PurchaseStatus*> purchasestatuss =   QList<PurchaseStatus*>();
purchasestatuss = GetAll();
	for(int i = 0; i <purchasestatuss.count(); i++){
		if(purchasestatuss[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<PurchaseStatus*> PurchaseStatus::QuerySelect(QString select) {
QList<PurchaseStatus*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseStatus WHERE "+select+"" ));
while (query.next()) {
list.append(new PurchaseStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags PurchaseStatus::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool PurchaseStatus::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool PurchaseStatus::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->PurchaseStatusID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void PurchaseStatus::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() PurchaseStatus!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool PurchaseStatus::setDescription(int PurchaseStatusID, const QString &Description) {
QSqlQuery query;
query.prepare("update PurchaseStatus set Description = ? where PurchaseStatusID = ?");
query.addBindValue(Description);
query.addBindValue(PurchaseStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStatus::setCreatedOn(int PurchaseStatusID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update PurchaseStatus set CreatedOn = ? where PurchaseStatusID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(PurchaseStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseStatus::setEditedOn(int PurchaseStatusID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update PurchaseStatus set EditedOn = ? where PurchaseStatusID = ?");
query.addBindValue(EditedOn);
query.addBindValue(PurchaseStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

