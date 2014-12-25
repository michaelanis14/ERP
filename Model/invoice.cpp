/**************************************************************************
**   File: invoice.cpp
**   Created on: Fri Dec 19 22:39:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "invoice.h"
#include "erpmodel.h"

Invoice::Invoice()
 : QSqlRelationalTableModel(){

this->InvoiceID = 0 ;
this->Serial = 0 ;
this->InvoiceSerialID = 0 ;
this->ContactID = 0 ;
this->ProjectID = 0 ;
this->Date = QDate();
this->InvoicePeriodID = 0 ;
this->InvoiceYearID = 0 ;
this->DueDate = QDate();
this->discount = 0 ;
this->Allowance = 0 ;
this->Header = "";
this->Footer = "";
this->Note = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Invoice");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("InvoiceSerial", "InvoiceSerialID", "Title"));
this->setRelation(3, QSqlRelation("Contact", "ContactID", "Name"));
this->setRelation(4, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(6, QSqlRelation("InvoicePeriod", "InvoicePeriodID", "Description"));
this->setRelation(7, QSqlRelation("InvoiceYear", "InvoiceYearID", "Description"));
}
Invoice::Invoice(int InvoiceID,int Serial,int InvoiceSerialID,int ContactID,int ProjectID,QDate Date,int InvoicePeriodID,int InvoiceYearID,QDate DueDate,double discount,double Allowance,QString Header,QString Footer,QString Note,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceID = InvoiceID ;
this->Serial = Serial ;
this->InvoiceSerialID = InvoiceSerialID ;
this->ContactID = ContactID ;
this->ProjectID = ProjectID ;
this->Date = Date ;
this->InvoicePeriodID = InvoicePeriodID ;
this->InvoiceYearID = InvoiceYearID ;
this->DueDate = DueDate ;
this->discount = discount ;
this->Allowance = Allowance ;
this->Header = Header ;
this->Footer = Footer ;
this->Note = Note ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Invoice::Invoice(int Serial,int InvoiceSerialID,int ContactID,int ProjectID,QDate Date,int InvoicePeriodID,int InvoiceYearID,QDate DueDate,double discount,double Allowance,QString Header,QString Footer,QString Note,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->InvoiceID = 0 ;
this->Serial = Serial ;
this->InvoiceSerialID = InvoiceSerialID ;
this->ContactID = ContactID ;
this->ProjectID = ProjectID ;
this->Date = Date ;
this->InvoicePeriodID = InvoicePeriodID ;
this->InvoiceYearID = InvoiceYearID ;
this->DueDate = DueDate ;
this->discount = discount ;
this->Allowance = Allowance ;
this->Header = Header ;
this->Footer = Footer ;
this->Note = Note ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Invoice::Init()
{

QString table = "Invoice";
QString query =
"(InvoiceID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (InvoiceID),"
"Serial INT NOT NULL, "
" KEY(Serial),"
"InvoiceSerialID INT NOT NULL, "
"FOREIGN KEY (InvoiceSerialID) REFERENCES InvoiceSerial(InvoiceSerialID)  ON DELETE CASCADE,"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"ProjectID INT NOT NULL, "
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"Date DATE NOT NULL, "
"InvoicePeriodID INT NOT NULL, "
"FOREIGN KEY (InvoicePeriodID) REFERENCES InvoicePeriod(InvoicePeriodID)  ON DELETE CASCADE,"
"InvoiceYearID INT NOT NULL, "
"FOREIGN KEY (InvoiceYearID) REFERENCES InvoiceYear(InvoiceYearID)  ON DELETE CASCADE,"
"DueDate DATE NOT NULL, "
"discount DECIMAL(6,2) NOT NULL, "
"Allowance DECIMAL(6,2) NOT NULL, "
"Header VARCHAR(40) NOT NULL, "
"Footer VARCHAR(40) NOT NULL, "
"Note VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("InvoiceID")));variables.append(qMakePair(QString(" INT"),QString("Serial")));variables.append(qMakePair(QString(" INT"),QString("InvoiceSerialID")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(""),QString("Date")));variables.append(qMakePair(QString(" INT"),QString("InvoicePeriodID")));variables.append(qMakePair(QString(" INT"),QString("InvoiceYearID")));variables.append(qMakePair(QString(""),QString("DueDate")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("discount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Allowance")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Header")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Footer")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Note")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
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
this->EditedOn = QDate::currentDate().toString();
if(InvoiceID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Invoice (Serial,InvoiceSerialID,ContactID,ProjectID,Date,InvoicePeriodID,InvoiceYearID,DueDate,discount,Allowance,Header,Footer,Note,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->Serial)+"','"+QString::number(this->InvoiceSerialID)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->ProjectID)+"','"+(this->Date.toString("yyyy-MM-dd"))+"','"+QString::number(this->InvoicePeriodID)+"','"+QString::number(this->InvoiceYearID)+"','"+(this->DueDate.toString("yyyy-MM-dd"))+"','"+QString::number(this->discount)+"','"+QString::number(this->Allowance)+"','"+QString(this->Header)+"','"+QString(this->Footer)+"','"+QString(this->Note)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Invoice SET "	"Serial = '"+QString::number(this->Serial)+"',"+"InvoiceSerialID = '"+QString::number(this->InvoiceSerialID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"ProjectID = '"+QString::number(this->ProjectID)+"',"+"Date = '"+(this->Date.toString("yyyy-MM-dd"))+"',"+"InvoicePeriodID = '"+QString::number(this->InvoicePeriodID)+"',"+"InvoiceYearID = '"+QString::number(this->InvoiceYearID)+"',"+"DueDate = '"+(this->DueDate.toString("yyyy-MM-dd"))+"',"+"discount = '"+QString::number(this->discount)+"',"+"Allowance = '"+QString::number(this->Allowance)+"',"+"Header = '"+QString(this->Header)+"',"+"Footer = '"+QString(this->Footer)+"',"+"Note = '"+QString(this->Note)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE InvoiceID ='"+QString::number(this->InvoiceID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  InvoiceID FROM Invoice WHERE Serial = "+QString::number(Serial)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->InvoiceID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Invoice::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
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
return new Invoice(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toDate(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString());
 }

}
return new Invoice();
 }

QList<Invoice*> Invoice::GetAll() {
	QList<Invoice*> invoices =   QList<Invoice*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Invoice ORDER BY InvoiceID ASC"));
	while (query.next()) {
invoices.append(new Invoice(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toDate(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()));
	}
	return invoices;
}

Invoice* Invoice::Get(int id) {
Invoice* invoice = new Invoice();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Invoice WHERE InvoiceID = '"+QString::number(id)+"' ORDER BY InvoiceID ASC "));
while (query.next()) {
invoice = new Invoice(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toDate(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString());
 }
invoice->invoicestoreproducts = InvoiceStoreProduct::QuerySelect("InvoiceID = " + QString::number(id));
invoice->invoiceservices = InvoiceService::QuerySelect("InvoiceID = " + QString::number(id));
invoice->invoicedeliveryorderfreelines = InvoiceDeliveryOrderFreeline::QuerySelect("InvoiceID = " + QString::number(id));
invoice->invoicefreelines = InvoiceFreeline::QuerySelect("InvoiceID = " + QString::number(id));

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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Invoice WHERE Serial = QString::number("+name+")"));
while (query.next()) {
invoice = new Invoice(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toDate(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString());

 }
invoice->invoicestoreproducts = InvoiceStoreProduct::QuerySelect("InvoiceID = " +QString::number(invoice->InvoiceID));
invoice->invoiceservices = InvoiceService::QuerySelect("InvoiceID = " +QString::number(invoice->InvoiceID));
invoice->invoicedeliveryorderfreelines = InvoiceDeliveryOrderFreeline::QuerySelect("InvoiceID = " +QString::number(invoice->InvoiceID));
invoice->invoicefreelines = InvoiceFreeline::QuerySelect("InvoiceID = " +QString::number(invoice->InvoiceID));

}
return invoice;
 }

QList<Invoice*> Invoice::Search(QString keyword) {
QList<Invoice*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Invoice"
"WHERE" 
"Header LIKE '%"+keyword+"%'"
"OR Footer LIKE '%"+keyword+"%'"
"OR Note LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Invoice(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toDate(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()));
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
	return list;
}

QList<QPair< int,QString > > Invoice::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Invoice*> invoices =   QList<Invoice*>();
invoices = GetAll();
	for(int i = 0; i <invoices.count(); i++){
		list.append(qMakePair(invoices[i]->InvoiceID,QString::number(invoices[i]->Serial)));
	}
	return list;
}

QList<QPair< int,QString > > Invoice::GetPairList(QList<Invoice*> invoices) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <invoices.count(); i++){
		list.append(qMakePair(invoices[i]->InvoiceID,QString::number(invoices[i]->Serial)));
	}
	return list;
}

int Invoice::GetIndex(QString name) {
	QList<Invoice*> invoices =   QList<Invoice*>();
invoices = GetAll();
	for(int i = 0; i <invoices.count(); i++){
		if(invoices[i]->Serial == name.toInt()){
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
list.append(new Invoice(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toDate(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toDate(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toString(),query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()));
 }

}
return list;
 }

Qt::ItemFlags Invoice::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 18 || index.column() == 19)
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
ok = setSerial(id, value.toString());
else if (index.column() == 2)
ok = setInvoiceSerialID(id, value.toString());
else if (index.column() == 3)
ok = setContactID(id, value.toString());
else if (index.column() == 4)
ok = setProjectID(id, value.toString());
else if (index.column() == 5)
ok = setDate(id, value.toString());
else if (index.column() == 6)
ok = setInvoicePeriodID(id, value.toString());
else if (index.column() == 7)
ok = setInvoiceYearID(id, value.toString());
else if (index.column() == 8)
ok = setDueDate(id, value.toString());
else if (index.column() == 9)
ok = setdiscount(id, value.toString());
else if (index.column() == 10)
ok = setAllowance(id, value.toString());
else if (index.column() == 11)
ok = setHeader(id, value.toString());
else if (index.column() == 12)
ok = setFooter(id, value.toString());
else if (index.column() == 13)
ok = setNote(id, value.toString());
else if (index.column() == 18)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 19)
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
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Serial"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Invoice Serial"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Invoice Period"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Invoice Year"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Due Date"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("discount"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Allowance"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Header"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Footer"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Note"));
this->setHeaderData(18, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(19, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Invoice::setSerial(int InvoiceID, const QString &Serial) {
QSqlQuery query;
query.prepare("update Invoice set Serial = ? where InvoiceID = ?");
query.addBindValue(Serial);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setInvoiceSerialID(int InvoiceID, const QString &InvoiceSerialID) {
QSqlQuery query;
query.prepare("update Invoice set InvoiceSerialID = ? where InvoiceID = ?");
query.addBindValue(InvoiceSerialID);
query.addBindValue(InvoiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Invoice::setContactID(int InvoiceID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update Invoice set ContactID = ? where InvoiceID = ?");
query.addBindValue(ContactID);
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
bool Invoice::setDate(int InvoiceID, const QString &Date) {
QSqlQuery query;
query.prepare("update Invoice set Date = ? where InvoiceID = ?");
query.addBindValue(Date);
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
bool Invoice::setNote(int InvoiceID, const QString &Note) {
QSqlQuery query;
query.prepare("update Invoice set Note = ? where InvoiceID = ?");
query.addBindValue(Note);
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

