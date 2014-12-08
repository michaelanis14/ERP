/**************************************************************************
**   File: payment.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "payment.h"
#include "erpmodel.h"

Payment::Payment()
 : QSqlRelationalTableModel(){

this->PaymentID = 0 ;
this->InvoiceID = 0 ;
this->TotalAmount = 0 ;
this->Comment = "";
this->PaymentTypeID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Payment");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(4, QSqlRelation("PaymentType", "PaymentTypeID", "Description"));
}
Payment::Payment(int PaymentID,int InvoiceID,double TotalAmount,QString Comment,int PaymentTypeID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PaymentID = PaymentID ;
this->InvoiceID = InvoiceID ;
this->TotalAmount = TotalAmount ;
this->Comment = Comment ;
this->PaymentTypeID = PaymentTypeID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Payment::Payment(int InvoiceID,double TotalAmount,QString Comment,int PaymentTypeID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PaymentID = 0 ;
this->InvoiceID = InvoiceID ;
this->TotalAmount = TotalAmount ;
this->Comment = Comment ;
this->PaymentTypeID = PaymentTypeID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Payment::Init()
{

QString table = "Payment";
QString query =
"(PaymentID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PaymentID),"
"InvoiceID INT NOT NULL, "
" KEY(InvoiceID),"
"FOREIGN KEY (InvoiceID) REFERENCES Invoice(InvoiceID)  ON DELETE CASCADE,"
"TotalAmount DECIMAL(6,2) NOT NULL, "
"Comment VARCHAR(40) NOT NULL, "
"PaymentTypeID INT NOT NULL, "
"FOREIGN KEY (PaymentTypeID) REFERENCES PaymentType(PaymentTypeID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

ErpModel::GetInstance()->createTable(table,query);
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
this->EditedOn = QDateTime::currentDateTime().toString();
if(PaymentID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Payment (InvoiceID,TotalAmount,Comment,PaymentTypeID,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->InvoiceID)+"','"+QString::number(this->TotalAmount)+"','"+QString(this->Comment)+"','"+QString::number(this->PaymentTypeID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Payment SET "	"InvoiceID = '"+QString::number(this->InvoiceID)+"',"+"TotalAmount = '"+QString::number(this->TotalAmount)+"',"+"Comment = '"+QString(this->Comment)+"',"+"PaymentTypeID = '"+QString::number(this->PaymentTypeID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PaymentID ='"+QString::number(this->PaymentID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PaymentID FROM Payment WHERE InvoiceID = "+QString::number(InvoiceID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PaymentID = query.value(0).toInt();	
 } 
 }
return true;
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
return new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new Payment();
 }

QList<Payment*> Payment::GetAll() {
	QList<Payment*> payments =   QList<Payment*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Payment"));
	while (query.next()) {
payments.append(new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
qStableSort(payments.begin(),payments.end());
	return payments;
}

Payment* Payment::Get(int id) {
Payment* payment = new Payment();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Payment WHERE PaymentID = '"+QString::number(id)+"'"));
while (query.next()) {
payment = new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Payment WHERE InvoiceID = QString::number("+name+")"));
while (query.next()) {
payment = new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

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
list.append(new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
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
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> Payment::GetHashList() {
	QHash<int,QString> list;
	QList<Payment*> payments =   QList<Payment*>();
payments = GetAll();
	for(int i = 0; i <payments.count(); i++){
		list.insert(payments[i]->PaymentID,QString::number(payments[i]->InvoiceID));
	}
	return list;
}

int Payment::GetIndex(QString name) {
	QList<Payment*> payments =   QList<Payment*>();
payments = GetAll();
	for(int i = 0; i <payments.count(); i++){
		if(payments[i]->InvoiceID == name.toInt()){
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
list.append(new Payment(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags Payment::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
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
ok = setInvoiceID(id, value.toString());
else if (index.column() == 2)
ok = setTotalAmount(id, value.toString());
else if (index.column() == 3)
ok = setComment(id, value.toString());
else if (index.column() == 4)
ok = setPaymentTypeID(id, value.toString());
else if (index.column() == 5)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 6)
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
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Invoice"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Total Amount"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Comment"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Payment Type"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Payment::setInvoiceID(int PaymentID, const QString &InvoiceID) {
QSqlQuery query;
query.prepare("update Payment set InvoiceID = ? where PaymentID = ?");
query.addBindValue(InvoiceID);
query.addBindValue(PaymentID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Payment::setTotalAmount(int PaymentID, const QString &TotalAmount) {
QSqlQuery query;
query.prepare("update Payment set TotalAmount = ? where PaymentID = ?");
query.addBindValue(TotalAmount);
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
bool Payment::setPaymentTypeID(int PaymentID, const QString &PaymentTypeID) {
QSqlQuery query;
query.prepare("update Payment set PaymentTypeID = ? where PaymentID = ?");
query.addBindValue(PaymentTypeID);
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

