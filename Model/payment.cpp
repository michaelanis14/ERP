/**************************************************************************
**   File: payment.cpp
**   Created on: Sat Dec 20 02:32:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "payment.h"
#include "erpmodel.h"

Payment::Payment()
 : QSqlRelationalTableModel(){

this->PaymentID = 0 ;
this->PaymentTypeID = 0 ;
this->ContactID = 0 ;
this->ProjectID = 0 ;
this->Date = QDate();
this->NetAmount = 0 ;
this->GrossAmount = 0 ;
this->Comment = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Payment");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("PaymentType", "PaymentTypeID", "Description"));
this->setRelation(2, QSqlRelation("Contact", "ContactID", "Name"));
this->setRelation(3, QSqlRelation("Project", "ProjectID", "Title"));
}
Payment::Payment(int PaymentID,int PaymentTypeID,int ContactID,int ProjectID,QDate Date,double NetAmount,double GrossAmount,QString Comment,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PaymentID = PaymentID ;
this->PaymentTypeID = PaymentTypeID ;
this->ContactID = ContactID ;
this->ProjectID = ProjectID ;
this->Date = Date ;
this->NetAmount = NetAmount ;
this->GrossAmount = GrossAmount ;
this->Comment = Comment ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Payment::Payment(int PaymentTypeID,int ContactID,int ProjectID,QDate Date,double NetAmount,double GrossAmount,QString Comment,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PaymentID = 0 ;
this->PaymentTypeID = PaymentTypeID ;
this->ContactID = ContactID ;
this->ProjectID = ProjectID ;
this->Date = Date ;
this->NetAmount = NetAmount ;
this->GrossAmount = GrossAmount ;
this->Comment = Comment ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Payment::Init()
{

QString table = "Payment";
QString query =
"(PaymentID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PaymentID),"
"PaymentTypeID INT NOT NULL, "
" KEY(PaymentTypeID),"
"FOREIGN KEY (PaymentTypeID) REFERENCES PaymentType(PaymentTypeID)  ON DELETE CASCADE,"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"ProjectID INT NOT NULL, "
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"Date DATE NOT NULL, "
"NetAmount DECIMAL(6,2) NOT NULL, "
"GrossAmount DECIMAL(6,2) NOT NULL, "
"Comment VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("PaymentID")));variables.append(qMakePair(QString(" INT"),QString("PaymentTypeID")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(""),QString("Date")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("NetAmount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("GrossAmount")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Comment")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Payment* Payment::p_instance = 0;
Payment* Payment::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Payment();
		Payment::GetAll();
	}
return p_instance;
}
bool Payment::save() {
this->EditedOn = QDate::currentDate().toString();
if(PaymentID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Payment (PaymentTypeID,ContactID,ProjectID,Date,NetAmount,GrossAmount,Comment,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->PaymentTypeID)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->ProjectID)+"','"+(this->Date.toString("yyyy-MM-dd"))+"','"+QString::number(this->NetAmount)+"','"+QString::number(this->GrossAmount)+"','"+QString(this->Comment)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Payment SET "	"PaymentTypeID = '"+QString::number(this->PaymentTypeID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"ProjectID = '"+QString::number(this->ProjectID)+"',"+"Date = '"+(this->Date.toString("yyyy-MM-dd"))+"',"+"NetAmount = '"+QString::number(this->NetAmount)+"',"+"GrossAmount = '"+QString::number(this->GrossAmount)+"',"+"Comment = '"+QString(this->Comment)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PaymentID ='"+QString::number(this->PaymentID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PaymentID FROM Payment WHERE PaymentTypeID = "+QString::number(PaymentTypeID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PaymentID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Payment::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Payment::remove() {
if(PaymentID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Payment WHERE PaymentID ="+QString::number(this->PaymentID)+""));
return true;
 }
return false;
}

Payment* Payment::get() {
if(PaymentID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Payment"
"WHERE PaymentID ='"+QString::number(this->PaymentID)+"'"));
while (query.next()) {
return new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toDate(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());
 }

}
return new Payment();
 }

QList<Payment*> Payment::GetAll() {
	QList<Payment*> payments =   QList<Payment*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Payment ORDER BY PaymentID ASC"));
	while (query.next()) {
payments.append(new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toDate(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
	}
	return payments;
}

Payment* Payment::Get(int id) {
Payment* payment = new Payment();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Payment WHERE PaymentID = '"+QString::number(id)+"' ORDER BY PaymentID ASC "));
while (query.next()) {
payment = new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toDate(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());
 }

}
return payment;
}

Payment* Payment::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Payment();
}

Payment* Payment::Get(QString name) {
Payment* payment = new Payment();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Payment WHERE PaymentTypeID = QString::number("+name+")"));
while (query.next()) {
payment = new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toDate(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString());

 }

}
return payment;
 }

QList<Payment*> Payment::Search(QString keyword) {
QList<Payment*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Payment"
"WHERE" 
"Comment LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toDate(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

QList<QString> Payment::GetStringList() {
	QList<QString> list;
	QList<Payment*> payments =   QList<Payment*>();
payments = GetAll();
	for(int i = 0; i <payments.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > Payment::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Payment*> payments =   QList<Payment*>();
payments = GetAll();
	for(int i = 0; i <payments.count(); i++){
		list.append(qMakePair(payments[i]->PaymentID,QString::number(payments[i]->PaymentTypeID)));
	}
	return list;
}

QList<QPair< int,QString > > Payment::GetPairList(QList<Payment*> payments) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <payments.count(); i++){
		list.append(qMakePair(payments[i]->PaymentID,QString::number(payments[i]->PaymentTypeID)));
	}
	return list;
}

int Payment::GetIndex(QString name) {
	QList<Payment*> payments =   QList<Payment*>();
payments = GetAll();
	for(int i = 0; i <payments.count(); i++){
		if(payments[i]->PaymentTypeID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<Payment*> Payment::QuerySelect(QString select) {
QList<Payment*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Payment WHERE "+select+"" ));
while (query.next()) {
list.append(new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toDate(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString()));
 }

}
return list;
 }

Qt::ItemFlags Payment::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Payment::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setPaymentTypeID(id, value.toString());
else if (index.column() == 2)
ok = setContactID(id, value.toString());
else if (index.column() == 3)
ok = setProjectID(id, value.toString());
else if (index.column() == 4)
ok = setDate(id, value.toString());
else if (index.column() == 5)
ok = setNetAmount(id, value.toString());
else if (index.column() == 6)
ok = setGrossAmount(id, value.toString());
else if (index.column() == 7)
ok = setComment(id, value.toString());
else if (index.column() == 8)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 9)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Payment::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->PaymentID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Payment::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Payment!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Payment Type"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Net Amount"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Gross Amount"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Comment"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Payment::setPaymentTypeID(int PaymentID, const QString &PaymentTypeID) {
QSqlQuery query;
query.prepare("update Payment set PaymentTypeID = ? where PaymentID = ?");
query.addBindValue(PaymentTypeID);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setContactID(int PaymentID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update Payment set ContactID = ? where PaymentID = ?");
query.addBindValue(ContactID);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setProjectID(int PaymentID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update Payment set ProjectID = ? where PaymentID = ?");
query.addBindValue(ProjectID);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setDate(int PaymentID, const QString &Date) {
QSqlQuery query;
query.prepare("update Payment set Date = ? where PaymentID = ?");
query.addBindValue(Date);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setNetAmount(int PaymentID, const QString &NetAmount) {
QSqlQuery query;
query.prepare("update Payment set NetAmount = ? where PaymentID = ?");
query.addBindValue(NetAmount);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setGrossAmount(int PaymentID, const QString &GrossAmount) {
QSqlQuery query;
query.prepare("update Payment set GrossAmount = ? where PaymentID = ?");
query.addBindValue(GrossAmount);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setComment(int PaymentID, const QString &Comment) {
QSqlQuery query;
query.prepare("update Payment set Comment = ? where PaymentID = ?");
query.addBindValue(Comment);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setCreatedOn(int PaymentID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Payment set CreatedOn = ? where PaymentID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setEditedOn(int PaymentID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Payment set EditedOn = ? where PaymentID = ?");
query.addBindValue(EditedOn);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

