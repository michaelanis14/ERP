/**************************************************************************
**   File: deliveryorder.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "deliveryorder.h"
#include "erpmodel.h"

DeliveryOrder::DeliveryOrder()
 : QSqlRelationalTableModel(){

this->DeliveryOrderID = 0 ;
this->Serial = "";
this->Barcode = "";
this->DeliveryOrderStatusID = 0 ;
this->ContactID = 0 ;
this->CreationDate = "";
this->DeliveryDate = "";
this->Note = "";
this->Header = "";
this->Footer = "";
this->DeliveryAddress = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("DeliveryOrder");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("DeliveryOrderStatus", "DeliveryOrderStatusID", "Description"));
this->setRelation(4, QSqlRelation("Contact", "ContactID", "Name"));
}
DeliveryOrder::DeliveryOrder(int DeliveryOrderID,QString Serial,QString Barcode,int DeliveryOrderStatusID,int ContactID,QString CreationDate,QString DeliveryDate,QString Note,QString Header,QString Footer,QString DeliveryAddress,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderID = DeliveryOrderID ;
this->Serial = Serial ;
this->Barcode = Barcode ;
this->DeliveryOrderStatusID = DeliveryOrderStatusID ;
this->ContactID = ContactID ;
this->CreationDate = CreationDate ;
this->DeliveryDate = DeliveryDate ;
this->Note = Note ;
this->Header = Header ;
this->Footer = Footer ;
this->DeliveryAddress = DeliveryAddress ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

DeliveryOrder::DeliveryOrder(QString Serial,QString Barcode,int DeliveryOrderStatusID,int ContactID,QString CreationDate,QString DeliveryDate,QString Note,QString Header,QString Footer,QString DeliveryAddress,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->DeliveryOrderID = 0 ;
this->Serial = Serial ;
this->Barcode = Barcode ;
this->DeliveryOrderStatusID = DeliveryOrderStatusID ;
this->ContactID = ContactID ;
this->CreationDate = CreationDate ;
this->DeliveryDate = DeliveryDate ;
this->Note = Note ;
this->Header = Header ;
this->Footer = Footer ;
this->DeliveryAddress = DeliveryAddress ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool DeliveryOrder::Init()
{

QString table = "DeliveryOrder";
QString query =
"(DeliveryOrderID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (DeliveryOrderID),"
"Serial VARCHAR(40) NOT NULL, "
" KEY(Serial),"
"Barcode VARCHAR(40) NOT NULL, "
"DeliveryOrderStatusID INT NOT NULL, "
"FOREIGN KEY (DeliveryOrderStatusID) REFERENCES DeliveryOrderStatus(DeliveryOrderStatusID)  ON DELETE CASCADE,"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"CreationDate VARCHAR(40) NOT NULL, "
"DeliveryDate VARCHAR(40) NOT NULL, "
"Note VARCHAR(40) NOT NULL, "
"Header VARCHAR(40) NOT NULL, "
"Footer VARCHAR(40) NOT NULL, "
"DeliveryAddress VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("DeliveryOrderID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Serial")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Barcode")));variables.append(qMakePair(QString(" INT"),QString("DeliveryOrderStatusID")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreationDate")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("DeliveryDate")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Note")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Header")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Footer")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("DeliveryAddress")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
DeliveryOrder* DeliveryOrder::p_instance = 0;
DeliveryOrder* DeliveryOrder::GetInstance() {
	if (p_instance == 0) {
		p_instance = new DeliveryOrder();
		DeliveryOrder::GetAll();
	}
return p_instance;
}
bool DeliveryOrder::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(DeliveryOrderID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO DeliveryOrder (Serial,Barcode,DeliveryOrderStatusID,ContactID,CreationDate,DeliveryDate,Note,Header,Footer,DeliveryAddress,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Serial)+"','"+QString(this->Barcode)+"','"+QString::number(this->DeliveryOrderStatusID)+"','"+QString::number(this->ContactID)+"','"+QString(this->CreationDate)+"','"+QString(this->DeliveryDate)+"','"+QString(this->Note)+"','"+QString(this->Header)+"','"+QString(this->Footer)+"','"+QString(this->DeliveryAddress)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE DeliveryOrder SET "	"Serial = '"+QString(this->Serial)+"',"+"Barcode = '"+QString(this->Barcode)+"',"+"DeliveryOrderStatusID = '"+QString::number(this->DeliveryOrderStatusID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"CreationDate = '"+QString(this->CreationDate)+"',"+"DeliveryDate = '"+QString(this->DeliveryDate)+"',"+"Note = '"+QString(this->Note)+"',"+"Header = '"+QString(this->Header)+"',"+"Footer = '"+QString(this->Footer)+"',"+"DeliveryAddress = '"+QString(this->DeliveryAddress)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE DeliveryOrderID ='"+QString::number(this->DeliveryOrderID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  DeliveryOrderID FROM DeliveryOrder WHERE Serial = '"+Serial+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->DeliveryOrderID = query.value(0).toInt();	
 } 
 }
return true;
}
bool DeliveryOrder::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool DeliveryOrder::remove() {
if(DeliveryOrderID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM DeliveryOrder WHERE DeliveryOrderID ="+QString::number(this->DeliveryOrderID)+""));
return true;
 }
return false;
}

DeliveryOrder* DeliveryOrder::get() {
if(DeliveryOrderID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrder"
"WHERE DeliveryOrderID ='"+QString::number(this->DeliveryOrderID)+"'"));
while (query.next()) {
return new DeliveryOrder(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());
 }

}
return new DeliveryOrder();
 }

QList<DeliveryOrder*> DeliveryOrder::GetAll() {
	QList<DeliveryOrder*> deliveryorders =   QList<DeliveryOrder*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrder ORDER BY DeliveryOrderID ASC"));
	while (query.next()) {
deliveryorders.append(new DeliveryOrder(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
	}
	return deliveryorders;
}

DeliveryOrder* DeliveryOrder::Get(int id) {
DeliveryOrder* deliveryorder = new DeliveryOrder();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM DeliveryOrder WHERE DeliveryOrderID = '"+QString::number(id)+"' ORDER BY DeliveryOrderID ASC "));
while (query.next()) {
deliveryorder = new DeliveryOrder(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());
 }
deliveryorder->deliveryorderstoreproducts = DeliveryOrderStoreProduct::QuerySelect("DeliveryOrderID = " + QString::number(id));
deliveryorder->deliveryorderservices = DeliveryOrderService::QuerySelect("DeliveryOrderID = " + QString::number(id));
deliveryorder->deliveryorderfreelines = DeliveryOrderFreeline::QuerySelect("DeliveryOrderID = " + QString::number(id));

}
return deliveryorder;
}

DeliveryOrder* DeliveryOrder::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new DeliveryOrder();
}

DeliveryOrder* DeliveryOrder::Get(QString name) {
DeliveryOrder* deliveryorder = new DeliveryOrder();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrder WHERE Serial = '"+name+"'"));
while (query.next()) {
deliveryorder = new DeliveryOrder(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());

 }
deliveryorder->deliveryorderstoreproducts = DeliveryOrderStoreProduct::QuerySelect("DeliveryOrderID = " +QString::number(deliveryorder->DeliveryOrderID));
deliveryorder->deliveryorderservices = DeliveryOrderService::QuerySelect("DeliveryOrderID = " +QString::number(deliveryorder->DeliveryOrderID));
deliveryorder->deliveryorderfreelines = DeliveryOrderFreeline::QuerySelect("DeliveryOrderID = " +QString::number(deliveryorder->DeliveryOrderID));

}
return deliveryorder;
 }

QList<DeliveryOrder*> DeliveryOrder::Search(QString keyword) {
QList<DeliveryOrder*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrder"
"WHERE" 
"Serial LIKE '%"+keyword+"%'"
"OR Barcode LIKE '%"+keyword+"%'"
"OR CreationDate LIKE '%"+keyword+"%'"
"OR DeliveryDate LIKE '%"+keyword+"%'"
"OR Note LIKE '%"+keyword+"%'"
"OR Header LIKE '%"+keyword+"%'"
"OR Footer LIKE '%"+keyword+"%'"
"OR DeliveryAddress LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new DeliveryOrder(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
 }

}
return list;
 }

QList<QString> DeliveryOrder::GetStringList() {
	QList<QString> list;
	QList<DeliveryOrder*> deliveryorders =   QList<DeliveryOrder*>();
deliveryorders = GetAll();
	for(int i = 0; i <deliveryorders.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrder::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<DeliveryOrder*> deliveryorders =   QList<DeliveryOrder*>();
deliveryorders = GetAll();
	for(int i = 0; i <deliveryorders.count(); i++){
		list.append(qMakePair(deliveryorders[i]->DeliveryOrderID,deliveryorders[i]->Serial));
	}
	return list;
}

QList<QPair< int,QString > > DeliveryOrder::GetPairList(QList<DeliveryOrder*> deliveryorders) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <deliveryorders.count(); i++){
		list.append(qMakePair(deliveryorders[i]->DeliveryOrderID,deliveryorders[i]->Serial));
	}
	return list;
}

int DeliveryOrder::GetIndex(QString name) {
	QList<DeliveryOrder*> deliveryorders =   QList<DeliveryOrder*>();
deliveryorders = GetAll();
	for(int i = 0; i <deliveryorders.count(); i++){
		if(deliveryorders[i]->Serial == name){
			return i;
		}
	}
	return 0;
}

QList<DeliveryOrder*> DeliveryOrder::QuerySelect(QString select) {
QList<DeliveryOrder*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM DeliveryOrder WHERE "+select+"" ));
while (query.next()) {
list.append(new DeliveryOrder(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
 }

}
return list;
 }

Qt::ItemFlags DeliveryOrder::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 14 || index.column() == 15)
flags |= Qt::ItemIsEditable;
return flags;
}

bool DeliveryOrder::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setSerial(id, value.toString());
else if (index.column() == 2)
ok = setBarcode(id, value.toString());
else if (index.column() == 3)
ok = setDeliveryOrderStatusID(id, value.toString());
else if (index.column() == 4)
ok = setContactID(id, value.toString());
else if (index.column() == 5)
ok = setCreationDate(id, value.toString());
else if (index.column() == 6)
ok = setDeliveryDate(id, value.toString());
else if (index.column() == 7)
ok = setNote(id, value.toString());
else if (index.column() == 8)
ok = setHeader(id, value.toString());
else if (index.column() == 9)
ok = setFooter(id, value.toString());
else if (index.column() == 10)
ok = setDeliveryAddress(id, value.toString());
else if (index.column() == 14)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 15)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool DeliveryOrder::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->DeliveryOrderID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void DeliveryOrder::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() DeliveryOrder!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Serial"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Barcode"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Delivery Order Status"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Creation Date"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Delivery Date"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Note"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Header"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Footer"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Delivery Address"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool DeliveryOrder::setSerial(int DeliveryOrderID, const QString &Serial) {
QSqlQuery query;
query.prepare("update DeliveryOrder set Serial = ? where DeliveryOrderID = ?");
query.addBindValue(Serial);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setBarcode(int DeliveryOrderID, const QString &Barcode) {
QSqlQuery query;
query.prepare("update DeliveryOrder set Barcode = ? where DeliveryOrderID = ?");
query.addBindValue(Barcode);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setDeliveryOrderStatusID(int DeliveryOrderID, const QString &DeliveryOrderStatusID) {
QSqlQuery query;
query.prepare("update DeliveryOrder set DeliveryOrderStatusID = ? where DeliveryOrderID = ?");
query.addBindValue(DeliveryOrderStatusID);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setContactID(int DeliveryOrderID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update DeliveryOrder set ContactID = ? where DeliveryOrderID = ?");
query.addBindValue(ContactID);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setCreationDate(int DeliveryOrderID, const QString &CreationDate) {
QSqlQuery query;
query.prepare("update DeliveryOrder set CreationDate = ? where DeliveryOrderID = ?");
query.addBindValue(CreationDate);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setDeliveryDate(int DeliveryOrderID, const QString &DeliveryDate) {
QSqlQuery query;
query.prepare("update DeliveryOrder set DeliveryDate = ? where DeliveryOrderID = ?");
query.addBindValue(DeliveryDate);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setNote(int DeliveryOrderID, const QString &Note) {
QSqlQuery query;
query.prepare("update DeliveryOrder set Note = ? where DeliveryOrderID = ?");
query.addBindValue(Note);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setHeader(int DeliveryOrderID, const QString &Header) {
QSqlQuery query;
query.prepare("update DeliveryOrder set Header = ? where DeliveryOrderID = ?");
query.addBindValue(Header);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setFooter(int DeliveryOrderID, const QString &Footer) {
QSqlQuery query;
query.prepare("update DeliveryOrder set Footer = ? where DeliveryOrderID = ?");
query.addBindValue(Footer);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setDeliveryAddress(int DeliveryOrderID, const QString &DeliveryAddress) {
QSqlQuery query;
query.prepare("update DeliveryOrder set DeliveryAddress = ? where DeliveryOrderID = ?");
query.addBindValue(DeliveryAddress);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setCreatedOn(int DeliveryOrderID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrder set CreatedOn = ? where DeliveryOrderID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool DeliveryOrder::setEditedOn(int DeliveryOrderID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update DeliveryOrder set EditedOn = ? where DeliveryOrderID = ?");
query.addBindValue(EditedOn);
query.addBindValue(DeliveryOrderID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

