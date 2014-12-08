/**************************************************************************
**   File: invoice.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoice.h"
#include "erpmodel.h"

Invoice::Invoice()
 : QSqlRelationalTableModel(){

this->InvoiceID = 0 ;
this->CreationDate = "";
this->EndDate = "";
this->InvoicePeriodID = 0 ;
this->InvoiceYearID = 0 ;
this->ProjectID = 0 ;
this->DueDate = "";
this->discount = 0 ;
this->Allowance = 0 ;
this->Header = "";
this->Footer = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Invoice");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("InvoicePeriod", "InvoicePeriodID", "Description"));
this->setRelation(4, QSqlRelation("InvoiceYear", "InvoiceYearID", "Description"));
this->setRelation(5, QSqlRelation("Project", "ProjectID", "Title"));
}
Invoice::Invoice(int InvoiceID,QString CreationDate,QString EndDate,int InvoicePeriodID,int InvoiceYearID,int ProjectID,QString DueDate,double discount,double Allowance,QString Header,QString Footer,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceID = InvoiceID ;
this->CreationDate = CreationDate ;
this->EndDate = EndDate ;
this->InvoicePeriodID = InvoicePeriodID ;
this->InvoiceYearID = InvoiceYearID ;
this->ProjectID = ProjectID ;
this->DueDate = DueDate ;
this->discount = discount ;
this->Allowance = Allowance ;
this->Header = Header ;
this->Footer = Footer ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Invoice::Invoice(QString CreationDate,QString EndDate,int InvoicePeriodID,int InvoiceYearID,int ProjectID,QString DueDate,double discount,double Allowance,QString Header,QString Footer,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceID = 0 ;
this->CreationDate = CreationDate ;
this->EndDate = EndDate ;
this->InvoicePeriodID = InvoicePeriodID ;
this->InvoiceYearID = InvoiceYearID ;
this->ProjectID = ProjectID ;
this->DueDate = DueDate ;
this->discount = discount ;
this->Allowance = Allowance ;
this->Header = Header ;
this->Footer = Footer ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Invoice::Init()
{

QString table = "Invoice";
QString query =
"(InvoiceID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceID),"
"CreationDate VARCHAR(40) NOT NULL, "
" KEY(CreationDate),"
"EndDate VARCHAR(40) NOT NULL, "
"InvoicePeriodID INT NOT NULL, "
"FOREIGN KEY (InvoicePeriodID) REFERENCES InvoicePeriod(InvoicePeriodID)  ON DELETE CASCADE,"
"InvoiceYearID INT NOT NULL, "
"FOREIGN KEY (InvoiceYearID) REFERENCES InvoiceYear(InvoiceYearID)  ON DELETE CASCADE,"
"ProjectID INT NOT NULL, "
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"DueDate VARCHAR(40) NOT NULL, "
"discount DECIMAL(6,2) NOT NULL, "
"Allowance DECIMAL(6,2) NOT NULL, "
"Header VARCHAR(40) NOT NULL, "
"Footer VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Invoice* Invoice::p_instance = 0;
Invoice* Invoice::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Invoice();
		Invoice::GetAll();
	}
return p_instance;
}
bool Invoice::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(InvoiceID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Invoice (CreationDate,EndDate,InvoicePeriodID,InvoiceYearID,ProjectID,DueDate,discount,Allowance,Header,Footer,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->CreationDate)+"','"+QString(this->EndDate)+"','"+QString::number(this->InvoicePeriodID)+"','"+QString::number(this->InvoiceYearID)+"','"+QString::number(this->ProjectID)+"','"+QString(this->DueDate)+"','"+QString::number(this->discount)+"','"+QString::number(this->Allowance)+"','"+QString(this->Header)+"','"+QString(this->Footer)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Invoice SET "	"CreationDate = '"+QString(this->CreationDate)+"',"+"EndDate = '"+QString(this->EndDate)+"',"+"InvoicePeriodID = '"+QString::number(this->InvoicePeriodID)+"',"+"InvoiceYearID = '"+QString::number(this->InvoiceYearID)+"',"+"ProjectID = '"+QString::number(this->ProjectID)+"',"+"DueDate = '"+QString(this->DueDate)+"',"+"discount = '"+QString::number(this->discount)+"',"+"Allowance = '"+QString::number(this->Allowance)+"',"+"Header = '"+QString(this->Header)+"',"+"Footer = '"+QString(this->Footer)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceID ='"+QString::number(this->InvoiceID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceID FROM Invoice WHERE CreationDate = '"+CreationDate+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Invoice::remove() {
if(InvoiceID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Invoice WHERE InvoiceID ="+QString::number(this->InvoiceID)+""));
return true;
 }
return false;
}

Invoice* Invoice::get() {
if(InvoiceID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Invoice"
"WHERE InvoiceID ='"+QString::number(this->InvoiceID)+"'"));
while (query.next()) {
return new Invoice(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());
 }

}
return new Invoice();
 }

QList<Invoice*> Invoice::GetAll() {
	QList<Invoice*> invoices =   QList<Invoice*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Invoice"));
	while (query.next()) {
invoices.append(new Invoice(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
	}
qStableSort(invoices.begin(),invoices.end());
	return invoices;
}

Invoice* Invoice::Get(int id) {
Invoice* invoice = new Invoice();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Invoice WHERE InvoiceID = '"+QString::number(id)+"'"));
while (query.next()) {
invoice = new Invoice(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());
 }
invoice->invoicestatedates = InvoiceStateDate::QuerySelect("InvoiceID = " + QString::number(id));
invoice->invoicefreelines = InvoiceFreeline::QuerySelect("InvoiceID = " + QString::number(id));
invoice->payments = Payment::QuerySelect("InvoiceID = " + QString::number(id));

}
return invoice;
}

Invoice* Invoice::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Invoice();
}

Invoice* Invoice::Get(QString name) {
Invoice* invoice = new Invoice();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Invoice WHERE CreationDate = '"+name+"'"));
while (query.next()) {
invoice = new Invoice(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());

 }
invoice->invoicestatedates = InvoiceStateDate::QuerySelect("InvoiceID = " +QString::number(invoice->InvoiceID));
invoice->invoicefreelines = InvoiceFreeline::QuerySelect("InvoiceID = " +QString::number(invoice->InvoiceID));
invoice->payments = Payment::QuerySelect("InvoiceID = " +QString::number(invoice->InvoiceID));

}
return invoice;
 }

QList<Invoice*> Invoice::Search(QString keyword) {
QList<Invoice*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Invoice"
"WHERE" 
"CreationDate LIKE '%"+keyword+"%'"
"OR EndDate LIKE '%"+keyword+"%'"
"OR DueDate LIKE '%"+keyword+"%'"
"OR Header LIKE '%"+keyword+"%'"
"OR Footer LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Invoice(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
 }

}
return list;
 }

QList<QString> Invoice::GetStringList() {
	QList<QString> list;
	QList<Invoice*> invoices =   QList<Invoice*>();
invoices = GetAll();
	for(int i = 0; i <invoices.count(); i++){
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> Invoice::GetHashList() {
	QHash<int,QString> list;
	QList<Invoice*> invoices =   QList<Invoice*>();
invoices = GetAll();
	for(int i = 0; i <invoices.count(); i++){
		list.insert(invoices[i]->InvoiceID,invoices[i]->CreationDate);
	}
	return list;
}

int Invoice::GetIndex(QString name) {
	QList<Invoice*> invoices =   QList<Invoice*>();
invoices = GetAll();
	for(int i = 0; i <invoices.count(); i++){
		if(invoices[i]->CreationDate == name){
			return i;
		}
	}
	return 0;
}

QList<Invoice*> Invoice::QuerySelect(QString select) {
QList<Invoice*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Invoice WHERE "+select+"" ));
while (query.next()) {
list.append(new Invoice(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
 }

}
return list;
 }

Qt::ItemFlags Invoice::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 12 || index.column() == 13 || index.column() == 14 || index.column() == 15)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Invoice::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setCreationDate(id, value.toString());
else if (index.column() == 2)
ok = setEndDate(id, value.toString());
else if (index.column() == 3)
ok = setInvoicePeriodID(id, value.toString());
else if (index.column() == 4)
ok = setInvoiceYearID(id, value.toString());
else if (index.column() == 5)
ok = setProjectID(id, value.toString());
else if (index.column() == 6)
ok = setDueDate(id, value.toString());
else if (index.column() == 7)
ok = setdiscount(id, value.toString());
else if (index.column() == 8)
ok = setAllowance(id, value.toString());
else if (index.column() == 12)
ok = setHeader(id, value.toString());
else if (index.column() == 13)
ok = setFooter(id, value.toString());
else if (index.column() == 14)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 15)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Invoice::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->InvoiceID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Invoice::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Invoice!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Creation Date"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("End Date"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Invoice Period"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Invoice Year"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Due Date"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("discount"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Allowance"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Header"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Footer"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Invoice::setCreationDate(int InvoiceID, const QString &CreationDate) {
QSqlQuery query;
query.prepare("update Invoice set CreationDate = ? where InvoiceID = ?");
query.addBindValue(CreationDate);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setEndDate(int InvoiceID, const QString &EndDate) {
QSqlQuery query;
query.prepare("update Invoice set EndDate = ? where InvoiceID = ?");
query.addBindValue(EndDate);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setInvoicePeriodID(int InvoiceID, const QString &InvoicePeriodID) {
QSqlQuery query;
query.prepare("update Invoice set InvoicePeriodID = ? where InvoiceID = ?");
query.addBindValue(InvoicePeriodID);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setInvoiceYearID(int InvoiceID, const QString &InvoiceYearID) {
QSqlQuery query;
query.prepare("update Invoice set InvoiceYearID = ? where InvoiceID = ?");
query.addBindValue(InvoiceYearID);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setProjectID(int InvoiceID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update Invoice set ProjectID = ? where InvoiceID = ?");
query.addBindValue(ProjectID);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setDueDate(int InvoiceID, const QString &DueDate) {
QSqlQuery query;
query.prepare("update Invoice set DueDate = ? where InvoiceID = ?");
query.addBindValue(DueDate);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setdiscount(int InvoiceID, const QString &discount) {
QSqlQuery query;
query.prepare("update Invoice set discount = ? where InvoiceID = ?");
query.addBindValue(discount);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setAllowance(int InvoiceID, const QString &Allowance) {
QSqlQuery query;
query.prepare("update Invoice set Allowance = ? where InvoiceID = ?");
query.addBindValue(Allowance);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setHeader(int InvoiceID, const QString &Header) {
QSqlQuery query;
query.prepare("update Invoice set Header = ? where InvoiceID = ?");
query.addBindValue(Header);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setFooter(int InvoiceID, const QString &Footer) {
QSqlQuery query;
query.prepare("update Invoice set Footer = ? where InvoiceID = ?");
query.addBindValue(Footer);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setCreatedOn(int InvoiceID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Invoice set CreatedOn = ? where InvoiceID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setEditedOn(int InvoiceID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Invoice set EditedOn = ? where InvoiceID = ?");
query.addBindValue(EditedOn);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

