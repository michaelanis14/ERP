/**************************************************************************
**   File: returndeliveryorderfreeline.cpp
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "returndeliveryorderfreeline.h"
#include "erpmodel.h"

ReturnDeliveryOrderFreeline::ReturnDeliveryOrderFreeline()
 : QSqlRelationalTableModel(){

this->ReturnDeliveryOrderFreelineID = 0 ;
this->ReturnDeliveryOrderID = 0 ;
this->Description = "";
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ReturnDeliveryOrderFreeline");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ReturnDeliveryOrderFreeline::ReturnDeliveryOrderFreeline(int ReturnDeliveryOrderFreelineID,int ReturnDeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderFreelineID = ReturnDeliveryOrderFreelineID ;
this->ReturnDeliveryOrderID = ReturnDeliveryOrderID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ReturnDeliveryOrderFreeline::ReturnDeliveryOrderFreeline(int ReturnDeliveryOrderID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnDeliveryOrderFreelineID = 0 ;
this->ReturnDeliveryOrderID = ReturnDeliveryOrderID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ReturnDeliveryOrderFreeline::Init()
{

QString table = "ReturnDeliveryOrderFreeline";
QString query =
"(ReturnDeliveryOrderFreelineID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ReturnDeliveryOrderFreelineID),"
"ReturnDeliveryOrderID INT NOT NULL, "
" KEY(ReturnDeliveryOrderID),"
"FOREIGN KEY (ReturnDeliveryOrderID) REFERENCES ReturnDeliveryOrder(ReturnDeliveryOrderID)  ON DELETE CASCADE,"
"Description VARCHAR(40) NOT NULL, "
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ReturnDeliveryOrderFreelineID")));variables.append(qMakePair(QString(" INT"),QString("ReturnDeliveryOrderID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ReturnDeliveryOrderFreeline* ReturnDeliveryOrderFreeline::p_instance = 0;
ReturnDeliveryOrderFreeline* ReturnDeliveryOrderFreeline::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ReturnDeliveryOrderFreeline();
		ReturnDeliveryOrderFreeline::GetAll();
	}
return p_instance;
}
bool ReturnDeliveryOrderFreeline::save() {
this->EditedOn = QDate::currentDate().toString();
if(ReturnDeliveryOrderFreelineID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ReturnDeliveryOrderFreeline (ReturnDeliveryOrderID,Description,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ReturnDeliveryOrderID)+"','"+QString(this->Description)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ReturnDeliveryOrderFreeline SET "	"ReturnDeliveryOrderID = '"+QString::number(this->ReturnDeliveryOrderID)+"',"+"Description = '"+QString(this->Description)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ReturnDeliveryOrderFreelineID ='"+QString::number(this->ReturnDeliveryOrderFreelineID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ReturnDeliveryOrderFreelineID FROM ReturnDeliveryOrderFreeline WHERE ReturnDeliveryOrderID = "+QString::number(ReturnDeliveryOrderID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ReturnDeliveryOrderFreelineID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ReturnDeliveryOrderFreeline::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ReturnDeliveryOrderFreeline::remove() {
if(ReturnDeliveryOrderFreelineID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ReturnDeliveryOrderFreeline WHERE ReturnDeliveryOrderFreelineID ="+QString::number(this->ReturnDeliveryOrderFreelineID)+""));
return true;
 }
return false;
}

ReturnDeliveryOrderFreeline* ReturnDeliveryOrderFreeline::get() {
if(ReturnDeliveryOrderFreelineID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrderFreeline"
"WHERE ReturnDeliveryOrderFreelineID ='"+QString::number(this->ReturnDeliveryOrderFreelineID)+"'"));
while (query.next()) {
return new ReturnDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new ReturnDeliveryOrderFreeline();
 }

QList<ReturnDeliveryOrderFreeline*> ReturnDeliveryOrderFreeline::GetAll() {
	QList<ReturnDeliveryOrderFreeline*> returndeliveryorderfreelines =   QList<ReturnDeliveryOrderFreeline*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderFreeline ORDER BY ReturnDeliveryOrderFreelineID ASC"));
	while (query.next()) {
returndeliveryorderfreelines.append(new ReturnDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
	return returndeliveryorderfreelines;
}

ReturnDeliveryOrderFreeline* ReturnDeliveryOrderFreeline::Get(int id) {
ReturnDeliveryOrderFreeline* returndeliveryorderfreeline = new ReturnDeliveryOrderFreeline();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnDeliveryOrderFreeline WHERE ReturnDeliveryOrderFreelineID = '"+QString::number(id)+"' ORDER BY ReturnDeliveryOrderFreelineID ASC "));
while (query.next()) {
returndeliveryorderfreeline = new ReturnDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return returndeliveryorderfreeline;
}

ReturnDeliveryOrderFreeline* ReturnDeliveryOrderFreeline::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ReturnDeliveryOrderFreeline();
}

ReturnDeliveryOrderFreeline* ReturnDeliveryOrderFreeline::Get(QString name) {
ReturnDeliveryOrderFreeline* returndeliveryorderfreeline = new ReturnDeliveryOrderFreeline();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderFreeline WHERE ReturnDeliveryOrderID = QString::number("+name+")"));
while (query.next()) {
returndeliveryorderfreeline = new ReturnDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return returndeliveryorderfreeline;
 }

QList<ReturnDeliveryOrderFreeline*> ReturnDeliveryOrderFreeline::Search(QString keyword) {
QList<ReturnDeliveryOrderFreeline*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderFreeline"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ReturnDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> ReturnDeliveryOrderFreeline::GetStringList() {
	QList<QString> list;
	QList<ReturnDeliveryOrderFreeline*> returndeliveryorderfreelines =   QList<ReturnDeliveryOrderFreeline*>();
returndeliveryorderfreelines = GetAll();
	for(int i = 0; i <returndeliveryorderfreelines.count(); i++){
		list.append(returndeliveryorderfreelines[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrderFreeline::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ReturnDeliveryOrderFreeline*> returndeliveryorderfreelines =   QList<ReturnDeliveryOrderFreeline*>();
returndeliveryorderfreelines = GetAll();
	for(int i = 0; i <returndeliveryorderfreelines.count(); i++){
		list.append(qMakePair(returndeliveryorderfreelines[i]->ReturnDeliveryOrderFreelineID,QString::number(returndeliveryorderfreelines[i]->ReturnDeliveryOrderID)));
	}
	return list;
}

QList<QPair< int,QString > > ReturnDeliveryOrderFreeline::GetPairList(QList<ReturnDeliveryOrderFreeline*> returndeliveryorderfreelines) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <returndeliveryorderfreelines.count(); i++){
		list.append(qMakePair(returndeliveryorderfreelines[i]->ReturnDeliveryOrderFreelineID,QString::number(returndeliveryorderfreelines[i]->ReturnDeliveryOrderID)));
	}
	return list;
}

int ReturnDeliveryOrderFreeline::GetIndex(QString name) {
	QList<ReturnDeliveryOrderFreeline*> returndeliveryorderfreelines =   QList<ReturnDeliveryOrderFreeline*>();
returndeliveryorderfreelines = GetAll();
	for(int i = 0; i <returndeliveryorderfreelines.count(); i++){
		if(returndeliveryorderfreelines[i]->ReturnDeliveryOrderID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ReturnDeliveryOrderFreeline*> ReturnDeliveryOrderFreeline::QuerySelect(QString select) {
QList<ReturnDeliveryOrderFreeline*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnDeliveryOrderFreeline WHERE "+select+"" ));
while (query.next()) {
list.append(new ReturnDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags ReturnDeliveryOrderFreeline::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ReturnDeliveryOrderFreeline::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setReturnDeliveryOrderID(id, value.toString());
else if (index.column() == 2)
ok = setDescription(id, value.toString());
else if (index.column() == 3)
ok = setAmount(id, value.toString());
else if (index.column() == 4)
ok = setPrice(id, value.toString());
else if (index.column() == 5)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 6)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ReturnDeliveryOrderFreeline::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ReturnDeliveryOrderFreelineID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ReturnDeliveryOrderFreeline::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ReturnDeliveryOrderFreeline!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Return Delivery Order"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ReturnDeliveryOrderFreeline::setReturnDeliveryOrderID(int ReturnDeliveryOrderFreelineID, const QString &ReturnDeliveryOrderID) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderFreeline set ReturnDeliveryOrderID = ? where ReturnDeliveryOrderFreelineID = ?");
query.addBindValue(ReturnDeliveryOrderID);
query.addBindValue(ReturnDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderFreeline::setDescription(int ReturnDeliveryOrderFreelineID, const QString &Description) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderFreeline set Description = ? where ReturnDeliveryOrderFreelineID = ?");
query.addBindValue(Description);
query.addBindValue(ReturnDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderFreeline::setAmount(int ReturnDeliveryOrderFreelineID, const QString &Amount) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderFreeline set Amount = ? where ReturnDeliveryOrderFreelineID = ?");
query.addBindValue(Amount);
query.addBindValue(ReturnDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderFreeline::setPrice(int ReturnDeliveryOrderFreelineID, const QString &Price) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderFreeline set Price = ? where ReturnDeliveryOrderFreelineID = ?");
query.addBindValue(Price);
query.addBindValue(ReturnDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderFreeline::setCreatedOn(int ReturnDeliveryOrderFreelineID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderFreeline set CreatedOn = ? where ReturnDeliveryOrderFreelineID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ReturnDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnDeliveryOrderFreeline::setEditedOn(int ReturnDeliveryOrderFreelineID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ReturnDeliveryOrderFreeline set EditedOn = ? where ReturnDeliveryOrderFreelineID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ReturnDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

