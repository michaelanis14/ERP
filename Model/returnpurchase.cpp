/**************************************************************************
**   File: returnpurchase.cpp
**   Created on: Thu Dec 18 23:40:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "returnpurchase.h"
#include "erpmodel.h"

ReturnPurchase::ReturnPurchase()
 : QSqlRelationalTableModel(){

this->ReturnPurchaseID = 0 ;
this->PurchaseID = 0 ;
this->Date = QDate();
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ReturnPurchase");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ReturnPurchase::ReturnPurchase(int ReturnPurchaseID,int PurchaseID,QDate Date,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnPurchaseID = ReturnPurchaseID ;
this->PurchaseID = PurchaseID ;
this->Date = Date ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ReturnPurchase::ReturnPurchase(int PurchaseID,QDate Date,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnPurchaseID = 0 ;
this->PurchaseID = PurchaseID ;
this->Date = Date ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ReturnPurchase::Init()
{

QString table = "ReturnPurchase";
QString query =
"(ReturnPurchaseID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ReturnPurchaseID),"
"PurchaseID INT NOT NULL, "
" KEY(PurchaseID),"
"FOREIGN KEY (PurchaseID) REFERENCES Purchase(PurchaseID)  ON DELETE CASCADE,"
"Date DATE NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ReturnPurchaseID")));variables.append(qMakePair(QString(" INT"),QString("PurchaseID")));variables.append(qMakePair(QString(""),QString("Date")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ReturnPurchase* ReturnPurchase::p_instance = 0;
ReturnPurchase* ReturnPurchase::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ReturnPurchase();
		ReturnPurchase::GetAll();
	}
return p_instance;
}
bool ReturnPurchase::save() {
this->EditedOn = QDate::currentDate().toString();
if(ReturnPurchaseID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ReturnPurchase (PurchaseID,Date,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->PurchaseID)+"','"+(this->Date.toString("yyyy-MM-dd"))+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ReturnPurchase SET "	"PurchaseID = '"+QString::number(this->PurchaseID)+"',"+"Date = '"+(this->Date.toString("yyyy-MM-dd"))+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ReturnPurchaseID ='"+QString::number(this->ReturnPurchaseID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ReturnPurchaseID FROM ReturnPurchase WHERE PurchaseID = "+QString::number(PurchaseID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ReturnPurchaseID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ReturnPurchase::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ReturnPurchase::remove() {
if(ReturnPurchaseID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ReturnPurchase WHERE ReturnPurchaseID ="+QString::number(this->ReturnPurchaseID)+""));
return true;
 }
return false;
}

ReturnPurchase* ReturnPurchase::get() {
if(ReturnPurchaseID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnPurchase"
"WHERE ReturnPurchaseID ='"+QString::number(this->ReturnPurchaseID)+"'"));
while (query.next()) {
return new ReturnPurchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toString(),query.value(4).toString());
 }

}
return new ReturnPurchase();
 }

QList<ReturnPurchase*> ReturnPurchase::GetAll() {
	QList<ReturnPurchase*> returnpurchases =   QList<ReturnPurchase*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchase ORDER BY ReturnPurchaseID ASC"));
	while (query.next()) {
returnpurchases.append(new ReturnPurchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toString(),query.value(4).toString()));
	}
	return returnpurchases;
}

ReturnPurchase* ReturnPurchase::Get(int id) {
ReturnPurchase* returnpurchase = new ReturnPurchase();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnPurchase WHERE ReturnPurchaseID = '"+QString::number(id)+"' ORDER BY ReturnPurchaseID ASC "));
while (query.next()) {
returnpurchase = new ReturnPurchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toString(),query.value(4).toString());
 }
returnpurchase->returnpurchasestoreproducts = ReturnPurchaseStoreProduct::QuerySelect("ReturnPurchaseID = " + QString::number(id));
returnpurchase->returnpurchasefreelines = ReturnPurchaseFreeLine::QuerySelect("ReturnPurchaseID = " + QString::number(id));

}
return returnpurchase;
}

ReturnPurchase* ReturnPurchase::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ReturnPurchase();
}

ReturnPurchase* ReturnPurchase::Get(QString name) {
ReturnPurchase* returnpurchase = new ReturnPurchase();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchase WHERE PurchaseID = QString::number("+name+")"));
while (query.next()) {
returnpurchase = new ReturnPurchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toString(),query.value(4).toString());

 }
returnpurchase->returnpurchasestoreproducts = ReturnPurchaseStoreProduct::QuerySelect("ReturnPurchaseID = " +QString::number(returnpurchase->ReturnPurchaseID));
returnpurchase->returnpurchasefreelines = ReturnPurchaseFreeLine::QuerySelect("ReturnPurchaseID = " +QString::number(returnpurchase->ReturnPurchaseID));

}
return returnpurchase;
 }

QList<ReturnPurchase*> ReturnPurchase::Search(QString keyword) {
QList<ReturnPurchase*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchase"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ReturnPurchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> ReturnPurchase::GetStringList() {
	QList<QString> list;
	QList<ReturnPurchase*> returnpurchases =   QList<ReturnPurchase*>();
returnpurchases = GetAll();
	for(int i = 0; i <returnpurchases.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ReturnPurchase::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ReturnPurchase*> returnpurchases =   QList<ReturnPurchase*>();
returnpurchases = GetAll();
	for(int i = 0; i <returnpurchases.count(); i++){
		list.append(qMakePair(returnpurchases[i]->ReturnPurchaseID,QString::number(returnpurchases[i]->PurchaseID)));
	}
	return list;
}

QList<QPair< int,QString > > ReturnPurchase::GetPairList(QList<ReturnPurchase*> returnpurchases) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <returnpurchases.count(); i++){
		list.append(qMakePair(returnpurchases[i]->ReturnPurchaseID,QString::number(returnpurchases[i]->PurchaseID)));
	}
	return list;
}

int ReturnPurchase::GetIndex(QString name) {
	QList<ReturnPurchase*> returnpurchases =   QList<ReturnPurchase*>();
returnpurchases = GetAll();
	for(int i = 0; i <returnpurchases.count(); i++){
		if(returnpurchases[i]->PurchaseID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ReturnPurchase*> ReturnPurchase::QuerySelect(QString select) {
QList<ReturnPurchase*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchase WHERE "+select+"" ));
while (query.next()) {
list.append(new ReturnPurchase(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toDate(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags ReturnPurchase::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ReturnPurchase::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setPurchaseID(id, value.toString());
else if (index.column() == 2)
ok = setDate(id, value.toString());
else if (index.column() == 5)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 6)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ReturnPurchase::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ReturnPurchaseID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ReturnPurchase::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ReturnPurchase!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Purchase"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ReturnPurchase::setPurchaseID(int ReturnPurchaseID, const QString &PurchaseID) {
QSqlQuery query;
query.prepare("update ReturnPurchase set PurchaseID = ? where ReturnPurchaseID = ?");
query.addBindValue(PurchaseID);
query.addBindValue(ReturnPurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchase::setDate(int ReturnPurchaseID, const QString &Date) {
QSqlQuery query;
query.prepare("update ReturnPurchase set Date = ? where ReturnPurchaseID = ?");
query.addBindValue(Date);
query.addBindValue(ReturnPurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchase::setCreatedOn(int ReturnPurchaseID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ReturnPurchase set CreatedOn = ? where ReturnPurchaseID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ReturnPurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchase::setEditedOn(int ReturnPurchaseID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ReturnPurchase set EditedOn = ? where ReturnPurchaseID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ReturnPurchaseID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

