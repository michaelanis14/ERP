/**************************************************************************
**   File: purchasefreeline.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "purchasefreeline.h"
#include "erpmodel.h"

PurchaseFreeLine::PurchaseFreeLine()
 : QSqlRelationalTableModel(){

this->PurchaseFreeLineID = 0 ;
this->PurchaseID = 0 ;
this->Description = "";
this->Amount = 0 ;
this->Price = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("PurchaseFreeLine");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Purchase", "PurchaseID", "Title"));
}
PurchaseFreeLine::PurchaseFreeLine(int PurchaseFreeLineID,int PurchaseID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseFreeLineID = PurchaseFreeLineID ;
this->PurchaseID = PurchaseID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

PurchaseFreeLine::PurchaseFreeLine(int PurchaseID,QString Description,double Amount,double Price,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->PurchaseFreeLineID = 0 ;
this->PurchaseID = PurchaseID ;
this->Description = Description ;
this->Amount = Amount ;
this->Price = Price ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool PurchaseFreeLine::Init()
{

QString table = "PurchaseFreeLine";
QString query =
"(PurchaseFreeLineID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (PurchaseFreeLineID),"
"PurchaseID INT NOT NULL, "
"FOREIGN KEY (PurchaseID) REFERENCES Purchase(PurchaseID)  ON DELETE CASCADE,"
"Description VARCHAR(40) NOT NULL, "
"Amount DECIMAL(6,2) NOT NULL, "
"Price DECIMAL(6,2) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
PurchaseFreeLine* PurchaseFreeLine::p_instance = 0;
PurchaseFreeLine* PurchaseFreeLine::GetInstance() {
	if (p_instance == 0) {
		p_instance = new PurchaseFreeLine();
		PurchaseFreeLine::GetAll();
	}
return p_instance;
}
bool PurchaseFreeLine::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(PurchaseFreeLineID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO PurchaseFreeLine (PurchaseID,Description,Amount,Price,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->PurchaseID)+"','"+QString(this->Description)+"','"+QString::number(this->Amount)+"','"+QString::number(this->Price)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE PurchaseFreeLine SET "	"PurchaseID = '"+QString::number(this->PurchaseID)+"',"+"Description = '"+QString(this->Description)+"',"+"Amount = '"+QString::number(this->Amount)+"',"+"Price = '"+QString::number(this->Price)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE PurchaseFreeLineID ='"+QString::number(this->PurchaseFreeLineID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  PurchaseFreeLineID FROM PurchaseFreeLine WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->PurchaseFreeLineID = query.value(0).toInt();	
 } 
 }
return true;
}

bool PurchaseFreeLine::remove() {
if(PurchaseFreeLineID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM PurchaseFreeLine WHERE PurchaseFreeLineID ="+QString::number(this->PurchaseFreeLineID)+""));
return true;
 }
return false;
}

PurchaseFreeLine* PurchaseFreeLine::get() {
if(PurchaseFreeLineID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseFreeLine"
"WHERE PurchaseFreeLineID ='"+QString::number(this->PurchaseFreeLineID)+"'"));
while (query.next()) {
return new PurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return new PurchaseFreeLine();
 }

QList<PurchaseFreeLine*> PurchaseFreeLine::GetAll() {
	QList<PurchaseFreeLine*> purchasefreelines =   QList<PurchaseFreeLine*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseFreeLine"));
	while (query.next()) {
purchasefreelines.append(new PurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
	}
qStableSort(purchasefreelines.begin(),purchasefreelines.end());
	return purchasefreelines;
}

PurchaseFreeLine* PurchaseFreeLine::Get(int id) {
PurchaseFreeLine* purchasefreeline = new PurchaseFreeLine();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM PurchaseFreeLine WHERE PurchaseFreeLineID = '"+QString::number(id)+"'"));
while (query.next()) {
purchasefreeline = new PurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());
 }

}
return purchasefreeline;
}

PurchaseFreeLine* PurchaseFreeLine::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new PurchaseFreeLine();
}

PurchaseFreeLine* PurchaseFreeLine::Get(QString name) {
PurchaseFreeLine* purchasefreeline = new PurchaseFreeLine();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseFreeLine WHERE Description = '"+name+"'"));
while (query.next()) {
purchasefreeline = new PurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString());

 }

}
return purchasefreeline;
 }

QList<PurchaseFreeLine*> PurchaseFreeLine::Search(QString keyword) {
QList<PurchaseFreeLine*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseFreeLine"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new PurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

QList<QString> PurchaseFreeLine::GetStringList() {
	QList<QString> list;
	QList<PurchaseFreeLine*> purchasefreelines =   QList<PurchaseFreeLine*>();
purchasefreelines = GetAll();
	for(int i = 0; i <purchasefreelines.count(); i++){
		list.append(purchasefreelines[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> PurchaseFreeLine::GetHashList() {
	QHash<int,QString> list;
	QList<PurchaseFreeLine*> purchasefreelines =   QList<PurchaseFreeLine*>();
purchasefreelines = GetAll();
	for(int i = 0; i <purchasefreelines.count(); i++){
		list.insert(purchasefreelines[i]->PurchaseFreeLineID,purchasefreelines[i]->Description);
	}
	return list;
}

int PurchaseFreeLine::GetIndex(QString name) {
	QList<PurchaseFreeLine*> purchasefreelines =   QList<PurchaseFreeLine*>();
purchasefreelines = GetAll();
	for(int i = 0; i <purchasefreelines.count(); i++){
		if(purchasefreelines[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<PurchaseFreeLine*> PurchaseFreeLine::QuerySelect(QString select) {
QList<PurchaseFreeLine*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM PurchaseFreeLine WHERE "+select+"" ));
while (query.next()) {
list.append(new PurchaseFreeLine(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toString(),query.value(6).toString()));
 }

}
return list;
 }

Qt::ItemFlags PurchaseFreeLine::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6)
flags |= Qt::ItemIsEditable;
return flags;
}

bool PurchaseFreeLine::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setPurchaseID(id, value.toString());
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

bool PurchaseFreeLine::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->PurchaseFreeLineID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void PurchaseFreeLine::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() PurchaseFreeLine!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Purchase"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool PurchaseFreeLine::setPurchaseID(int PurchaseFreeLineID, const QString &PurchaseID) {
QSqlQuery query;
query.prepare("update PurchaseFreeLine set PurchaseID = ? where PurchaseFreeLineID = ?");
query.addBindValue(PurchaseID);
query.addBindValue(PurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseFreeLine::setDescription(int PurchaseFreeLineID, const QString &Description) {
QSqlQuery query;
query.prepare("update PurchaseFreeLine set Description = ? where PurchaseFreeLineID = ?");
query.addBindValue(Description);
query.addBindValue(PurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseFreeLine::setAmount(int PurchaseFreeLineID, const QString &Amount) {
QSqlQuery query;
query.prepare("update PurchaseFreeLine set Amount = ? where PurchaseFreeLineID = ?");
query.addBindValue(Amount);
query.addBindValue(PurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseFreeLine::setPrice(int PurchaseFreeLineID, const QString &Price) {
QSqlQuery query;
query.prepare("update PurchaseFreeLine set Price = ? where PurchaseFreeLineID = ?");
query.addBindValue(Price);
query.addBindValue(PurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseFreeLine::setCreatedOn(int PurchaseFreeLineID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update PurchaseFreeLine set CreatedOn = ? where PurchaseFreeLineID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(PurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool PurchaseFreeLine::setEditedOn(int PurchaseFreeLineID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update PurchaseFreeLine set EditedOn = ? where PurchaseFreeLineID = ?");
query.addBindValue(EditedOn);
query.addBindValue(PurchaseFreeLineID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

