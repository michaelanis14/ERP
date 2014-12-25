/**************************************************************************
**   File: returnpurchasefreeline.cpp
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "returnpurchasefreeline.h"
#include "erpmodel.h"

ReturnPurchaseFreeLine::ReturnPurchaseFreeLine()
 : QSqlRelationalTableModel(){

this->ReturnPurchaseFreeLineID = 0 ;
this->ReturnPurchaseID = 0 ;
this->Description = "";
this->ContactID = 0 ;
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ReturnPurchaseFreeLine");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("Contact", "ContactID", "Name"));
}
ReturnPurchaseFreeLine::ReturnPurchaseFreeLine(int ReturnPurchaseFreeLineID,int ReturnPurchaseID,QString Description,int ContactID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnPurchaseFreeLineID = ReturnPurchaseFreeLineID ;
this->ReturnPurchaseID = ReturnPurchaseID ;
this->Description = Description ;
this->ContactID = ContactID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ReturnPurchaseFreeLine::ReturnPurchaseFreeLine(int ReturnPurchaseID,QString Description,int ContactID,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ReturnPurchaseFreeLineID = 0 ;
this->ReturnPurchaseID = ReturnPurchaseID ;
this->Description = Description ;
this->ContactID = ContactID ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ReturnPurchaseFreeLine::Init()
{

QString table = "ReturnPurchaseFreeLine";
QString query =
"(ReturnPurchaseFreeLineID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ReturnPurchaseFreeLineID),"
"ReturnPurchaseID INT NOT NULL, "
" KEY(ReturnPurchaseID),"
"FOREIGN KEY (ReturnPurchaseID) REFERENCES ReturnPurchase(ReturnPurchaseID)  ON DELETE CASCADE,"
"Description VARCHAR(40) NOT NULL, "
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ReturnPurchaseFreeLineID")));variables.append(qMakePair(QString(" INT"),QString("ReturnPurchaseID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Amount")));variables.append(qMakePair(QString(" DECIMAL(6,2)"),QString("Price")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ReturnPurchaseFreeLine* ReturnPurchaseFreeLine::p_instance = 0;
ReturnPurchaseFreeLine* ReturnPurchaseFreeLine::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ReturnPurchaseFreeLine();
		ReturnPurchaseFreeLine::GetAll();
	}
return p_instance;
}
bool ReturnPurchaseFreeLine::save() {
this->EditedOn = QDate::currentDate().toString();
if(ReturnPurchaseFreeLineID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ReturnPurchaseFreeLine (ReturnPurchaseID,Description,ContactID,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ReturnPurchaseID)+"','"+QString(this->Description)+"','"+QString::number(this->ContactID)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ReturnPurchaseFreeLine SET "	"ReturnPurchaseID = '"+QString::number(this->ReturnPurchaseID)+"',"+"Description = '"+QString(this->Description)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ReturnPurchaseFreeLineID ='"+QString::number(this->ReturnPurchaseFreeLineID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ReturnPurchaseFreeLineID FROM ReturnPurchaseFreeLine WHERE ReturnPurchaseID = "+QString::number(ReturnPurchaseID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ReturnPurchaseFreeLineID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ReturnPurchaseFreeLine::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ReturnPurchaseFreeLine::remove() {
if(ReturnPurchaseFreeLineID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ReturnPurchaseFreeLine WHERE ReturnPurchaseFreeLineID ="+QString::number(this->ReturnPurchaseFreeLineID)+""));
return true;
 }
return false;
}

ReturnPurchaseFreeLine* ReturnPurchaseFreeLine::get() {
if(ReturnPurchaseFreeLineID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnPurchaseFreeLine"
"WHERE ReturnPurchaseFreeLineID ='"+QString::number(this->ReturnPurchaseFreeLineID)+"'"));
while (query.next()) {
return new ReturnPurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return new ReturnPurchaseFreeLine();
 }

QList<ReturnPurchaseFreeLine*> ReturnPurchaseFreeLine::GetAll() {
	QList<ReturnPurchaseFreeLine*> returnpurchasefreelines =   QList<ReturnPurchaseFreeLine*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseFreeLine ORDER BY ReturnPurchaseFreeLineID ASC"));
	while (query.next()) {
returnpurchasefreelines.append(new ReturnPurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
	}
	return returnpurchasefreelines;
}

ReturnPurchaseFreeLine* ReturnPurchaseFreeLine::Get(int id) {
ReturnPurchaseFreeLine* returnpurchasefreeline = new ReturnPurchaseFreeLine();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ReturnPurchaseFreeLine WHERE ReturnPurchaseFreeLineID = '"+QString::number(id)+"' ORDER BY ReturnPurchaseFreeLineID ASC "));
while (query.next()) {
returnpurchasefreeline = new ReturnPurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());
 }

}
return returnpurchasefreeline;
}

ReturnPurchaseFreeLine* ReturnPurchaseFreeLine::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ReturnPurchaseFreeLine();
}

ReturnPurchaseFreeLine* ReturnPurchaseFreeLine::Get(QString name) {
ReturnPurchaseFreeLine* returnpurchasefreeline = new ReturnPurchaseFreeLine();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseFreeLine WHERE ReturnPurchaseID = QString::number("+name+")"));
while (query.next()) {
returnpurchasefreeline = new ReturnPurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString());

 }

}
return returnpurchasefreeline;
 }

QList<ReturnPurchaseFreeLine*> ReturnPurchaseFreeLine::Search(QString keyword) {
QList<ReturnPurchaseFreeLine*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseFreeLine"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ReturnPurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

QList<QString> ReturnPurchaseFreeLine::GetStringList() {
	QList<QString> list;
	QList<ReturnPurchaseFreeLine*> returnpurchasefreelines =   QList<ReturnPurchaseFreeLine*>();
returnpurchasefreelines = GetAll();
	for(int i = 0; i <returnpurchasefreelines.count(); i++){
		list.append(returnpurchasefreelines[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > ReturnPurchaseFreeLine::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ReturnPurchaseFreeLine*> returnpurchasefreelines =   QList<ReturnPurchaseFreeLine*>();
returnpurchasefreelines = GetAll();
	for(int i = 0; i <returnpurchasefreelines.count(); i++){
		list.append(qMakePair(returnpurchasefreelines[i]->ReturnPurchaseFreeLineID,QString::number(returnpurchasefreelines[i]->ReturnPurchaseID)));
	}
	return list;
}

QList<QPair< int,QString > > ReturnPurchaseFreeLine::GetPairList(QList<ReturnPurchaseFreeLine*> returnpurchasefreelines) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <returnpurchasefreelines.count(); i++){
		list.append(qMakePair(returnpurchasefreelines[i]->ReturnPurchaseFreeLineID,QString::number(returnpurchasefreelines[i]->ReturnPurchaseID)));
	}
	return list;
}

int ReturnPurchaseFreeLine::GetIndex(QString name) {
	QList<ReturnPurchaseFreeLine*> returnpurchasefreelines =   QList<ReturnPurchaseFreeLine*>();
returnpurchasefreelines = GetAll();
	for(int i = 0; i <returnpurchasefreelines.count(); i++){
		if(returnpurchasefreelines[i]->ReturnPurchaseID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ReturnPurchaseFreeLine*> ReturnPurchaseFreeLine::QuerySelect(QString select) {
QList<ReturnPurchaseFreeLine*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ReturnPurchaseFreeLine WHERE "+select+"" ));
while (query.next()) {
list.append(new ReturnPurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),query.value(7).toString()));
 }

}
return list;
 }

Qt::ItemFlags ReturnPurchaseFreeLine::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ReturnPurchaseFreeLine::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setReturnPurchaseID(id, value.toString());
else if (index.column() == 2)
ok = setDescription(id, value.toString());
else if (index.column() == 3)
ok = setContactID(id, value.toString());
else if (index.column() == 4)
ok = setAmount(id, value.toString());
else if (index.column() == 5)
ok = setPrice(id, value.toString());
else if (index.column() == 6)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 7)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ReturnPurchaseFreeLine::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ReturnPurchaseFreeLineID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ReturnPurchaseFreeLine::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ReturnPurchaseFreeLine!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Return Purchase"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ReturnPurchaseFreeLine::setReturnPurchaseID(int ReturnPurchaseFreeLineID, const QString &ReturnPurchaseID) {
QSqlQuery query;
query.prepare("update ReturnPurchaseFreeLine set ReturnPurchaseID = ? where ReturnPurchaseFreeLineID = ?");
query.addBindValue(ReturnPurchaseID);
query.addBindValue(ReturnPurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseFreeLine::setDescription(int ReturnPurchaseFreeLineID, const QString &Description) {
QSqlQuery query;
query.prepare("update ReturnPurchaseFreeLine set Description = ? where ReturnPurchaseFreeLineID = ?");
query.addBindValue(Description);
query.addBindValue(ReturnPurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseFreeLine::setContactID(int ReturnPurchaseFreeLineID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update ReturnPurchaseFreeLine set ContactID = ? where ReturnPurchaseFreeLineID = ?");
query.addBindValue(ContactID);
query.addBindValue(ReturnPurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseFreeLine::setAmount(int ReturnPurchaseFreeLineID, const QString &Amount) {
QSqlQuery query;
query.prepare("update ReturnPurchaseFreeLine set Amount = ? where ReturnPurchaseFreeLineID = ?");
query.addBindValue(Amount);
query.addBindValue(ReturnPurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseFreeLine::setPrice(int ReturnPurchaseFreeLineID, const QString &Price) {
QSqlQuery query;
query.prepare("update ReturnPurchaseFreeLine set Price = ? where ReturnPurchaseFreeLineID = ?");
query.addBindValue(Price);
query.addBindValue(ReturnPurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseFreeLine::setCreatedOn(int ReturnPurchaseFreeLineID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ReturnPurchaseFreeLine set CreatedOn = ? where ReturnPurchaseFreeLineID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ReturnPurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ReturnPurchaseFreeLine::setEditedOn(int ReturnPurchaseFreeLineID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ReturnPurchaseFreeLine set EditedOn = ? where ReturnPurchaseFreeLineID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ReturnPurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

