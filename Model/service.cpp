/**************************************************************************
**   File: service.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "service.h"
#include "erpmodel.h"

Service::Service()
 : QSqlRelationalTableModel(){

this->ServiceID = 0 ;
this->Name = "";
this->ShortDescription = "";
this->SellingPrice = 0 ;
this->NetCoast = 0 ;
this->TradeMarginRate = 0 ;
this->TaxID = 0 ;
this->Barcode = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Service");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(6, QSqlRelation("Tax", "TaxID", "Title"));
}
Service::Service(int ServiceID,QString Name,QString ShortDescription,double SellingPrice,double NetCoast,double TradeMarginRate,int TaxID,QString Barcode,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ServiceID = ServiceID ;
this->Name = Name ;
this->ShortDescription = ShortDescription ;
this->SellingPrice = SellingPrice ;
this->NetCoast = NetCoast ;
this->TradeMarginRate = TradeMarginRate ;
this->TaxID = TaxID ;
this->Barcode = Barcode ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Service::Service(QString Name,QString ShortDescription,double SellingPrice,double NetCoast,double TradeMarginRate,int TaxID,QString Barcode,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ServiceID = 0 ;
this->Name = Name ;
this->ShortDescription = ShortDescription ;
this->SellingPrice = SellingPrice ;
this->NetCoast = NetCoast ;
this->TradeMarginRate = TradeMarginRate ;
this->TaxID = TaxID ;
this->Barcode = Barcode ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Service::Init()
{

QString table = "Service";
QString query =
"(ServiceID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ServiceID),"
"Name VARCHAR(40) NOT NULL, "
" KEY(Name),"
"ShortDescription VARCHAR(40) NOT NULL, "
"SellingPrice DECIMAL(6,2) NOT NULL, "
"NetCoast DECIMAL(6,2) NOT NULL, "
"TradeMarginRate DECIMAL(6,2) NOT NULL, "
"TaxID INT NOT NULL, "
"FOREIGN KEY (TaxID) REFERENCES Tax(TaxID)  ON DELETE CASCADE,"
"Barcode VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ServiceID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("ShortDescription")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("SellingPrice")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("NetCoast")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("TradeMarginRate")));variables.append(qMakePair(QString(" INT"),QString("TaxID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Barcode")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Service* Service::p_instance = 0;
Service* Service::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Service();
		Service::GetAll();
	}
return p_instance;
}
bool Service::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ServiceID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Service (Name,ShortDescription,SellingPrice,NetCoast,TradeMarginRate,TaxID,Barcode,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+QString(this->ShortDescription)+"','"+QString::number(this->SellingPrice)+"','"+QString::number(this->NetCoast)+"','"+QString::number(this->TradeMarginRate)+"','"+QString::number(this->TaxID)+"','"+QString(this->Barcode)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Service SET "	"Name = '"+QString(this->Name)+"',"+"ShortDescription = '"+QString(this->ShortDescription)+"',"+"SellingPrice = '"+QString::number(this->SellingPrice)+"',"+"NetCoast = '"+QString::number(this->NetCoast)+"',"+"TradeMarginRate = '"+QString::number(this->TradeMarginRate)+"',"+"TaxID = '"+QString::number(this->TaxID)+"',"+"Barcode = '"+QString(this->Barcode)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ServiceID ='"+QString::number(this->ServiceID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ServiceID FROM Service WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ServiceID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Service::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Service::remove() {
if(ServiceID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Service WHERE ServiceID ="+QString::number(this->ServiceID)+""));
return true;
 }
return false;
}

Service* Service::get() {
if(ServiceID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Service"
"WHERE ServiceID ='"+QString::number(this->ServiceID)+"'"));
while (query.next()) {
return new Service(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());
 }

}
return new Service();
 }

QList<Service*> Service::GetAll() {
	QList<Service*> services =   QList<Service*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Service ORDER BY ServiceID ASC"));
	while (query.next()) {
services.append(new Service(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
	}
	return services;
}

Service* Service::Get(int id) {
Service* service = new Service();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Service WHERE ServiceID = '"+QString::number(id)+"' ORDER BY ServiceID ASC "));
while (query.next()) {
service = new Service(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());
 }

}
return service;
}

Service* Service::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Service();
}

Service* Service::Get(QString name) {
Service* service = new Service();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Service WHERE Name = '"+name+"'"));
while (query.next()) {
service = new Service(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());

 }

}
return service;
 }

QList<Service*> Service::Search(QString keyword) {
QList<Service*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Service"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR ShortDescription LIKE '%"+keyword+"%'"
"OR Barcode LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Service(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

QList<QString> Service::GetStringList() {
	QList<QString> list;
	QList<Service*> services =   QList<Service*>();
services = GetAll();
	for(int i = 0; i <services.count(); i++){
		list.append(services[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > Service::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Service*> services =   QList<Service*>();
services = GetAll();
	for(int i = 0; i <services.count(); i++){
		list.append(qMakePair(services[i]->ServiceID,services[i]->Name));
	}
	return list;
}

QList<QPair< int,QString > > Service::GetPairList(QList<Service*> services) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <services.count(); i++){
		list.append(qMakePair(services[i]->ServiceID,services[i]->Name));
	}
	return list;
}

int Service::GetIndex(QString name) {
	QList<Service*> services =   QList<Service*>();
services = GetAll();
	for(int i = 0; i <services.count(); i++){
		if(services[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Service*> Service::QuerySelect(QString select) {
QList<Service*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Service WHERE "+select+"" ));
while (query.next()) {
list.append(new Service(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

Qt::ItemFlags Service::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Service::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setShortDescription(id, value.toString());
else if (index.column() == 3)
ok = setSellingPrice(id, value.toString());
else if (index.column() == 4)
ok = setNetCoast(id, value.toString());
else if (index.column() == 5)
ok = setTradeMarginRate(id, value.toString());
else if (index.column() == 6)
ok = setTaxID(id, value.toString());
else if (index.column() == 7)
ok = setBarcode(id, value.toString());
else if (index.column() == 8)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 9)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Service::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ServiceID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Service::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Service!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Short Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Selling Price"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Net Coast"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Trade Margin Rate"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Tax"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Barcode"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Service::setName(int ServiceID, const QString &Name) {
QSqlQuery query;
query.prepare("update Service set Name = ? where ServiceID = ?");
query.addBindValue(Name);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setShortDescription(int ServiceID, const QString &ShortDescription) {
QSqlQuery query;
query.prepare("update Service set ShortDescription = ? where ServiceID = ?");
query.addBindValue(ShortDescription);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setSellingPrice(int ServiceID, const QString &SellingPrice) {
QSqlQuery query;
query.prepare("update Service set SellingPrice = ? where ServiceID = ?");
query.addBindValue(SellingPrice);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setNetCoast(int ServiceID, const QString &NetCoast) {
QSqlQuery query;
query.prepare("update Service set NetCoast = ? where ServiceID = ?");
query.addBindValue(NetCoast);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setTradeMarginRate(int ServiceID, const QString &TradeMarginRate) {
QSqlQuery query;
query.prepare("update Service set TradeMarginRate = ? where ServiceID = ?");
query.addBindValue(TradeMarginRate);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setTaxID(int ServiceID, const QString &TaxID) {
QSqlQuery query;
query.prepare("update Service set TaxID = ? where ServiceID = ?");
query.addBindValue(TaxID);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setBarcode(int ServiceID, const QString &Barcode) {
QSqlQuery query;
query.prepare("update Service set Barcode = ? where ServiceID = ?");
query.addBindValue(Barcode);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setCreatedOn(int ServiceID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Service set CreatedOn = ? where ServiceID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Service::setEditedOn(int ServiceID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Service set EditedOn = ? where ServiceID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

