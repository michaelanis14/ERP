/**************************************************************************
**   File: invoicedeliveryorderfreeline.cpp
**   Created on: Fri Dec 19 21:09:57 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoicedeliveryorderfreeline.h"
#include "erpmodel.h"

InvoiceDeliveryOrderFreeline::InvoiceDeliveryOrderFreeline()
 : QSqlRelationalTableModel(){

this->InvoiceDeliveryOrderFreelineID = 0 ;
this->InvoiceID = 0 ;
this->Description = "";
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceDeliveryOrderFreeline");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
InvoiceDeliveryOrderFreeline::InvoiceDeliveryOrderFreeline(int InvoiceDeliveryOrderFreelineID,int InvoiceID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceDeliveryOrderFreelineID = InvoiceDeliveryOrderFreelineID ;
this->InvoiceID = InvoiceID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceDeliveryOrderFreeline::InvoiceDeliveryOrderFreeline(int InvoiceID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceDeliveryOrderFreelineID = 0 ;
this->InvoiceID = InvoiceID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceDeliveryOrderFreeline::Init()
{

QString table = "InvoiceDeliveryOrderFreeline";
QString query =
"(InvoiceDeliveryOrderFreelineID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceDeliveryOrderFreelineID),"
"InvoiceID INT NOT NULL, "
" KEY(InvoiceID),"
"FOREIGN KEY (InvoiceID) REFERENCES Invoice(InvoiceID)  ON DELETE CASCADE,"
"Description VARCHAR(40) NOT NULL, "
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceDeliveryOrderFreelineID")));variables.append(qMakePair(QString(" INT"),QString("InvoiceID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
InvoiceDeliveryOrderFreeline* InvoiceDeliveryOrderFreeline::p_instance = 0;
InvoiceDeliveryOrderFreeline* InvoiceDeliveryOrderFreeline::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceDeliveryOrderFreeline();
		InvoiceDeliveryOrderFreeline::GetAll();
	}
return p_instance;
}
bool InvoiceDeliveryOrderFreeline::save() {
this->EditedOn = QDate::currentDate().toString();
if(InvoiceDeliveryOrderFreelineID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceDeliveryOrderFreeline (InvoiceID,Description,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->InvoiceID)+"','"+QString(this->Description)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceDeliveryOrderFreeline SET "	"InvoiceID = '"+QString::number(this->InvoiceID)+"',"+"Description = '"+QString(this->Description)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceDeliveryOrderFreelineID ='"+QString::number(this->InvoiceDeliveryOrderFreelineID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceDeliveryOrderFreelineID FROM InvoiceDeliveryOrderFreeline WHERE InvoiceID = "+QString::number(InvoiceID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceDeliveryOrderFreelineID = query.value(0).toInt();	
 } 
 }
return true;
}
bool InvoiceDeliveryOrderFreeline::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool InvoiceDeliveryOrderFreeline::remove() {
if(InvoiceDeliveryOrderFreelineID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceDeliveryOrderFreeline WHERE InvoiceDeliveryOrderFreelineID ="+QString::number(this->InvoiceDeliveryOrderFreelineID)+""));
return true;
 }
return false;
}

InvoiceDeliveryOrderFreeline* InvoiceDeliveryOrderFreeline::get() {
if(InvoiceDeliveryOrderFreelineID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceDeliveryOrderFreeline"
"WHERE InvoiceDeliveryOrderFreelineID ='"+QString::number(this->InvoiceDeliveryOrderFreelineID)+"'"));
while (query.next()) {
return new InvoiceDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new InvoiceDeliveryOrderFreeline();
 }

QList<InvoiceDeliveryOrderFreeline*> InvoiceDeliveryOrderFreeline::GetAll() {
	QList<InvoiceDeliveryOrderFreeline*> invoicedeliveryorderfreelines =   QList<InvoiceDeliveryOrderFreeline*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceDeliveryOrderFreeline ORDER BY InvoiceDeliveryOrderFreelineID ASC"));
	while (query.next()) {
invoicedeliveryorderfreelines.append(new InvoiceDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
	return invoicedeliveryorderfreelines;
}

InvoiceDeliveryOrderFreeline* InvoiceDeliveryOrderFreeline::Get(int id) {
InvoiceDeliveryOrderFreeline* invoicedeliveryorderfreeline = new InvoiceDeliveryOrderFreeline();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceDeliveryOrderFreeline WHERE InvoiceDeliveryOrderFreelineID = '"+QString::number(id)+"' ORDER BY InvoiceDeliveryOrderFreelineID ASC "));
while (query.next()) {
invoicedeliveryorderfreeline = new InvoiceDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return invoicedeliveryorderfreeline;
}

InvoiceDeliveryOrderFreeline* InvoiceDeliveryOrderFreeline::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceDeliveryOrderFreeline();
}

InvoiceDeliveryOrderFreeline* InvoiceDeliveryOrderFreeline::Get(QString name) {
InvoiceDeliveryOrderFreeline* invoicedeliveryorderfreeline = new InvoiceDeliveryOrderFreeline();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceDeliveryOrderFreeline WHERE InvoiceID = QString::number("+name+")"));
while (query.next()) {
invoicedeliveryorderfreeline = new InvoiceDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return invoicedeliveryorderfreeline;
 }

QList<InvoiceDeliveryOrderFreeline*> InvoiceDeliveryOrderFreeline::Search(QString keyword) {
QList<InvoiceDeliveryOrderFreeline*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceDeliveryOrderFreeline"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> InvoiceDeliveryOrderFreeline::GetStringList() {
	QList<QString> list;
	QList<InvoiceDeliveryOrderFreeline*> invoicedeliveryorderfreelines =   QList<InvoiceDeliveryOrderFreeline*>();
invoicedeliveryorderfreelines = GetAll();
	for(int i = 0; i <invoicedeliveryorderfreelines.count(); i++){
		list.append(invoicedeliveryorderfreelines[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > InvoiceDeliveryOrderFreeline::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<InvoiceDeliveryOrderFreeline*> invoicedeliveryorderfreelines =   QList<InvoiceDeliveryOrderFreeline*>();
invoicedeliveryorderfreelines = GetAll();
	for(int i = 0; i <invoicedeliveryorderfreelines.count(); i++){
		list.append(qMakePair(invoicedeliveryorderfreelines[i]->InvoiceDeliveryOrderFreelineID,QString::number(invoicedeliveryorderfreelines[i]->InvoiceID)));
	}
	return list;
}

QList<QPair< int,QString > > InvoiceDeliveryOrderFreeline::GetPairList(QList<InvoiceDeliveryOrderFreeline*> invoicedeliveryorderfreelines) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoicedeliveryorderfreelines.count(); i++){
		list.append(qMakePair(invoicedeliveryorderfreelines[i]->InvoiceDeliveryOrderFreelineID,QString::number(invoicedeliveryorderfreelines[i]->InvoiceID)));
	}
	return list;
}

int InvoiceDeliveryOrderFreeline::GetIndex(QString name) {
	QList<InvoiceDeliveryOrderFreeline*> invoicedeliveryorderfreelines =   QList<InvoiceDeliveryOrderFreeline*>();
invoicedeliveryorderfreelines = GetAll();
	for(int i = 0; i <invoicedeliveryorderfreelines.count(); i++){
		if(invoicedeliveryorderfreelines[i]->InvoiceID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<InvoiceDeliveryOrderFreeline*> InvoiceDeliveryOrderFreeline::QuerySelect(QString select) {
QList<InvoiceDeliveryOrderFreeline*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceDeliveryOrderFreeline WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceDeliveryOrderFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceDeliveryOrderFreeline::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceDeliveryOrderFreeline::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setInvoiceID(id, value.toString());
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

bool InvoiceDeliveryOrderFreeline::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceDeliveryOrderFreelineID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceDeliveryOrderFreeline::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceDeliveryOrderFreeline!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Invoice"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoiceDeliveryOrderFreeline::setInvoiceID(int InvoiceDeliveryOrderFreelineID, const QString &InvoiceID) {
QSqlQuery query;
query.prepare("update InvoiceDeliveryOrderFreeline set InvoiceID = ? where InvoiceDeliveryOrderFreelineID = ?");
query.addBindValue(InvoiceID);
query.addBindValue(InvoiceDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceDeliveryOrderFreeline::setDescription(int InvoiceDeliveryOrderFreelineID, const QString &Description) {
QSqlQuery query;
query.prepare("update InvoiceDeliveryOrderFreeline set Description = ? where InvoiceDeliveryOrderFreelineID = ?");
query.addBindValue(Description);
query.addBindValue(InvoiceDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceDeliveryOrderFreeline::setAmount(int InvoiceDeliveryOrderFreelineID, const QString &Amount) {
QSqlQuery query;
query.prepare("update InvoiceDeliveryOrderFreeline set Amount = ? where InvoiceDeliveryOrderFreelineID = ?");
query.addBindValue(Amount);
query.addBindValue(InvoiceDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceDeliveryOrderFreeline::setPrice(int InvoiceDeliveryOrderFreelineID, const QString &Price) {
QSqlQuery query;
query.prepare("update InvoiceDeliveryOrderFreeline set Price = ? where InvoiceDeliveryOrderFreelineID = ?");
query.addBindValue(Price);
query.addBindValue(InvoiceDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceDeliveryOrderFreeline::setCreatedOn(int InvoiceDeliveryOrderFreelineID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceDeliveryOrderFreeline set CreatedOn = ? where InvoiceDeliveryOrderFreelineID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceDeliveryOrderFreeline::setEditedOn(int InvoiceDeliveryOrderFreelineID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceDeliveryOrderFreeline set EditedOn = ? where InvoiceDeliveryOrderFreelineID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceDeliveryOrderFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

