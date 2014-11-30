/**************************************************************************
**   File: invoicefreeline.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoicefreeline.h"
#include "erpmodel.h"

InvoiceFreeline::InvoiceFreeline()
 : QSqlRelationalTableModel(){

this->InvoiceFreelineID = 0 ;
this->InvoiceID = 0 ;
this->Description = "";
this->Price = 0 ;
this->TaxID = 0 ;
this->Amount = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("InvoiceFreeline");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Invoice", "InvoiceID", "Title"));
this->setRelation(4, QSqlRelation("Tax", "TaxID", "Title"));
}
InvoiceFreeline::InvoiceFreeline(int InvoiceFreelineID,int InvoiceID,QString Description,double Price,int TaxID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceFreelineID = InvoiceFreelineID ;
this->InvoiceID = InvoiceID ;
this->Description = Description ;
this->Price = Price ;
this->TaxID = TaxID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

InvoiceFreeline::InvoiceFreeline(int InvoiceID,QString Description,double Price,int TaxID,double Amount,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceFreelineID = 0 ;
this->InvoiceID = InvoiceID ;
this->Description = Description ;
this->Price = Price ;
this->TaxID = TaxID ;
this->Amount = Amount ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool InvoiceFreeline::Init()
{

QString table = "InvoiceFreeline";
QString query =
"(InvoiceFreelineID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceFreelineID),"
"InvoiceID INT NOT NULL, "
"FOREIGN KEY (InvoiceID) REFERENCES Invoice(InvoiceID)  ON DELETE CASCADE,"
"Description VARCHAR(40) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"TaxID INT NOT NULL, "
"FOREIGN KEY (TaxID) REFERENCES Tax(TaxID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
InvoiceFreeline* InvoiceFreeline::p_instance = 0;
InvoiceFreeline* InvoiceFreeline::GetInstance() {
	if (p_instance == 0) {
		p_instance = new InvoiceFreeline();
		InvoiceFreeline::GetAll();
	}
return p_instance;
}
bool InvoiceFreeline::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(InvoiceFreelineID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO InvoiceFreeline (InvoiceID,Description,Price,TaxID,Amount,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->InvoiceID)+"','"+QString(this->Description)+"','"+QString::number(this->Price)+"','"+QString::number(this->TaxID)+"','"+QString::number(this->Amount)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE InvoiceFreeline SET "	"InvoiceID = '"+QString::number(this->InvoiceID)+"',"+"Description = '"+QString(this->Description)+"',"+"Price = '"+QString::number(this->Price)+"',"+"TaxID = '"+QString::number(this->TaxID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceFreelineID ='"+QString::number(this->InvoiceFreelineID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceFreelineID FROM InvoiceFreeline WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceFreelineID = query.value(0).toInt();	
 } 
 }
return true;
}

bool InvoiceFreeline::remove() {
if(InvoiceFreelineID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM InvoiceFreeline WHERE InvoiceFreelineID ="+QString::number(this->InvoiceFreelineID)+""));
return true;
 }
return false;
}

InvoiceFreeline* InvoiceFreeline::get() {
if(InvoiceFreelineID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceFreeline"
"WHERE InvoiceFreelineID ='"+QString::number(this->InvoiceFreelineID)+"'"));
while (query.next()) {
return new InvoiceFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return new InvoiceFreeline();
 }

QList<InvoiceFreeline*> InvoiceFreeline::GetAll() {
	QList<InvoiceFreeline*> invoicefreelines =   QList<InvoiceFreeline*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceFreeline"));
	while (query.next()) {
invoicefreelines.append(new InvoiceFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
	}
qSort(invoicefreelines);
	return invoicefreelines;
}

InvoiceFreeline* InvoiceFreeline::Get(int id) {
InvoiceFreeline* invoicefreeline = new InvoiceFreeline();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM InvoiceFreeline WHERE InvoiceFreelineID = '"+QString::number(id)+"'"));
while (query.next()) {
invoicefreeline = new InvoiceFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return invoicefreeline;
}

InvoiceFreeline* InvoiceFreeline::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new InvoiceFreeline();
}

InvoiceFreeline* InvoiceFreeline::Get(QString name) {
InvoiceFreeline* invoicefreeline = new InvoiceFreeline();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceFreeline WHERE Description = '"+name+"'"));
while (query.next()) {
invoicefreeline = new InvoiceFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());

 }

}
return invoicefreeline;
 }

QList<InvoiceFreeline*> InvoiceFreeline::Search(QString keyword) {
QList<InvoiceFreeline*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceFreeline"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new InvoiceFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

QList<QString> InvoiceFreeline::GetStringList() {
	QList<QString> list;
	QList<InvoiceFreeline*> invoicefreelines =   QList<InvoiceFreeline*>();
invoicefreelines = GetAll();
	for(int i = 0; i <invoicefreelines.count(); i++){
		list.append(invoicefreelines[i]->Description);
	}
	qSort(list);
	return list;
}

QHash<int,QString> InvoiceFreeline::GetHashList() {
	QHash<int,QString> list;
	QList<InvoiceFreeline*> invoicefreelines =   QList<InvoiceFreeline*>();
invoicefreelines = GetAll();
	for(int i = 0; i <invoicefreelines.count(); i++){
		list.insert(invoicefreelines[i]->InvoiceFreelineID,invoicefreelines[i]->Description);
	}
	return list;
}

int InvoiceFreeline::GetIndex(QString name) {
	QList<InvoiceFreeline*> invoicefreelines =   QList<InvoiceFreeline*>();
invoicefreelines = GetAll();
	for(int i = 0; i <invoicefreelines.count(); i++){
		if(invoicefreelines[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<InvoiceFreeline*> InvoiceFreeline::QuerySelect(QString select) {
QList<InvoiceFreeline*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM InvoiceFreeline WHERE "+select+"" ));
while (query.next()) {
list.append(new InvoiceFreeline(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

Qt::ItemFlags InvoiceFreeline::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7)
flags |= Qt::ItemIsEditable;
return flags;
}

bool InvoiceFreeline::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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
ok = setPrice(id, value.toString());
else if (index.column() == 4)
ok = setTaxID(id, value.toString());
else if (index.column() == 5)
ok = setAmount(id, value.toString());
else if (index.column() == 6)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 7)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool InvoiceFreeline::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceFreelineID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void InvoiceFreeline::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() InvoiceFreeline!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Invoice"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Tax"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool InvoiceFreeline::setInvoiceID(int InvoiceFreelineID, const QString &InvoiceID) {
QSqlQuery query;
query.prepare("update InvoiceFreeline set InvoiceID = ? where InvoiceFreelineID = ?");
query.addBindValue(InvoiceID);
query.addBindValue(InvoiceFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceFreeline::setDescription(int InvoiceFreelineID, const QString &Description) {
QSqlQuery query;
query.prepare("update InvoiceFreeline set Description = ? where InvoiceFreelineID = ?");
query.addBindValue(Description);
query.addBindValue(InvoiceFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceFreeline::setPrice(int InvoiceFreelineID, const QString &Price) {
QSqlQuery query;
query.prepare("update InvoiceFreeline set Price = ? where InvoiceFreelineID = ?");
query.addBindValue(Price);
query.addBindValue(InvoiceFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceFreeline::setTaxID(int InvoiceFreelineID, const QString &TaxID) {
QSqlQuery query;
query.prepare("update InvoiceFreeline set TaxID = ? where InvoiceFreelineID = ?");
query.addBindValue(TaxID);
query.addBindValue(InvoiceFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceFreeline::setAmount(int InvoiceFreelineID, const QString &Amount) {
QSqlQuery query;
query.prepare("update InvoiceFreeline set Amount = ? where InvoiceFreelineID = ?");
query.addBindValue(Amount);
query.addBindValue(InvoiceFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceFreeline::setCreatedOn(int InvoiceFreelineID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update InvoiceFreeline set CreatedOn = ? where InvoiceFreelineID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool InvoiceFreeline::setEditedOn(int InvoiceFreelineID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update InvoiceFreeline set EditedOn = ? where InvoiceFreelineID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceFreelineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

