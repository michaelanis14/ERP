/**************************************************************************
**   File: invoiceservice.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoiceservice.h"
#include "erpmodel.h"

InvoiceService::InvoiceService()
 : QSqlRelationalTableModel(){

this->InvoiceServiceID = 0 ;
this->InvoiceID = 0 ;
this->ServiceID = 0 ;
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceService");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Service", "ServiceID", "Name"));
}
InvoiceService::InvoiceService(int InvoiceServiceID,int InvoiceID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceServiceID = InvoiceServiceID ;
this->InvoiceID = InvoiceID ;
this->ServiceID = ServiceID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceService::InvoiceService(int InvoiceID,int ServiceID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceServiceID = 0 ;
this->InvoiceID = InvoiceID ;
this->ServiceID = ServiceID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceService::Init()
{

QString table = "InvoiceService";
QString query =
"(InvoiceServiceID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceServiceID),"
"InvoiceID INT NOT NULL, "
" KEY(InvoiceID),"
"FOREIGN KEY (InvoiceID) REFERENCES Invoice(InvoiceID)  ON DELETE CASCADE,"
"ServiceID INT NOT NULL, "
"FOREIGN KEY (ServiceID) REFERENCES Service(ServiceID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceServiceID")));variables.append(qMakePair(QString(" INT"),QString("InvoiceID")));variables.append(qMakePair(QString(" INT"),QString("ServiceID")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
InvoiceService* InvoiceService::p_instance = 0;
InvoiceService* InvoiceService::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceService();
		InvoiceService::GetAll();
	}
return p_instance;
}
bool InvoiceService::save() {
this->EditedOn = QDate::currentDate().toString();
if(InvoiceServiceID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceService (InvoiceID,ServiceID,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->InvoiceID)+"','"+QString::number(this->ServiceID)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceService SET "	"InvoiceID = '"+QString::number(this->InvoiceID)+"',"+"ServiceID = '"+QString::number(this->ServiceID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceServiceID ='"+QString::number(this->InvoiceServiceID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceServiceID FROM InvoiceService WHERE InvoiceID = "+QString::number(InvoiceID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceServiceID = query.value(0).toInt();	
 } 
 }
return true;
}
bool InvoiceService::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool InvoiceService::remove() {
if(InvoiceServiceID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceService WHERE InvoiceServiceID ="+QString::number(this->InvoiceServiceID)+""));
return true;
 }
return false;
}

InvoiceService* InvoiceService::get() {
if(InvoiceServiceID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceService"
"WHERE InvoiceServiceID ='"+QString::number(this->InvoiceServiceID)+"'"));
while (query.next()) {
return new InvoiceService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new InvoiceService();
 }

QList<InvoiceService*> InvoiceService::GetAll() {
	QList<InvoiceService*> invoiceservices =   QList<InvoiceService*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceService ORDER BY InvoiceServiceID ASC"));
	while (query.next()) {
invoiceservices.append(new InvoiceService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
	return invoiceservices;
}

InvoiceService* InvoiceService::Get(int id) {
InvoiceService* invoiceservice = new InvoiceService();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceService WHERE InvoiceServiceID = '"+QString::number(id)+"' ORDER BY InvoiceServiceID ASC "));
while (query.next()) {
invoiceservice = new InvoiceService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return invoiceservice;
}

InvoiceService* InvoiceService::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceService();
}

InvoiceService* InvoiceService::Get(QString name) {
InvoiceService* invoiceservice = new InvoiceService();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceService WHERE InvoiceID = QString::number("+name+")"));
while (query.next()) {
invoiceservice = new InvoiceService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return invoiceservice;
 }

QList<InvoiceService*> InvoiceService::Search(QString keyword) {
QList<InvoiceService*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceService"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> InvoiceService::GetStringList() {
	QList<QString> list;
	QList<InvoiceService*> invoiceservices =   QList<InvoiceService*>();
invoiceservices = GetAll();
	for(int i = 0; i <invoiceservices.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > InvoiceService::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<InvoiceService*> invoiceservices =   QList<InvoiceService*>();
invoiceservices = GetAll();
	for(int i = 0; i <invoiceservices.count(); i++){
		list.append(qMakePair(invoiceservices[i]->InvoiceServiceID,QString::number(invoiceservices[i]->InvoiceID)));
	}
	return list;
}

QList<QPair< int,QString > > InvoiceService::GetPairList(QList<InvoiceService*> invoiceservices) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoiceservices.count(); i++){
		list.append(qMakePair(invoiceservices[i]->InvoiceServiceID,QString::number(invoiceservices[i]->InvoiceID)));
	}
	return list;
}

int InvoiceService::GetIndex(QString name) {
	QList<InvoiceService*> invoiceservices =   QList<InvoiceService*>();
invoiceservices = GetAll();
	for(int i = 0; i <invoiceservices.count(); i++){
		if(invoiceservices[i]->InvoiceID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<InvoiceService*> InvoiceService::QuerySelect(QString select) {
QList<InvoiceService*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceService WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceService::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceService::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setInvoiceID(id, value.toString());
else if (index.column() == 2)
ok = setServiceID(id, value.toString());
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

bool InvoiceService::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceServiceID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceService::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceService!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Invoice"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Service"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoiceService::setInvoiceID(int InvoiceServiceID, const QString &InvoiceID) {
QSqlQuery query;
query.prepare("update InvoiceService set InvoiceID = ? where InvoiceServiceID = ?");
query.addBindValue(InvoiceID);
query.addBindValue(InvoiceServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceService::setServiceID(int InvoiceServiceID, const QString &ServiceID) {
QSqlQuery query;
query.prepare("update InvoiceService set ServiceID = ? where InvoiceServiceID = ?");
query.addBindValue(ServiceID);
query.addBindValue(InvoiceServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceService::setAmount(int InvoiceServiceID, const QString &Amount) {
QSqlQuery query;
query.prepare("update InvoiceService set Amount = ? where InvoiceServiceID = ?");
query.addBindValue(Amount);
query.addBindValue(InvoiceServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceService::setPrice(int InvoiceServiceID, const QString &Price) {
QSqlQuery query;
query.prepare("update InvoiceService set Price = ? where InvoiceServiceID = ?");
query.addBindValue(Price);
query.addBindValue(InvoiceServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceService::setCreatedOn(int InvoiceServiceID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceService set CreatedOn = ? where InvoiceServiceID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceService::setEditedOn(int InvoiceServiceID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceService set EditedOn = ? where InvoiceServiceID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

