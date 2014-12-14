/**************************************************************************
**   File: currency.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "currency.h"
#include "erpmodel.h"

Currency::Currency()
 : QSqlRelationalTableModel(){

this->CurrencyID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Currency");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Currency::Currency(int CurrencyID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->CurrencyID = CurrencyID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Currency::Currency(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->CurrencyID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Currency::Init()
{

QString table = "Currency";
QString query =
"(CurrencyID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (CurrencyID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("CurrencyID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Currency* Currency::p_instance = 0;
Currency* Currency::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Currency();
		Currency::GetAll();
	}
return p_instance;
}
bool Currency::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(CurrencyID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Currency (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Currency SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE CurrencyID ='"+QString::number(this->CurrencyID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  CurrencyID FROM Currency WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->CurrencyID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Currency::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Currency::remove() {
if(CurrencyID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Currency WHERE CurrencyID ="+QString::number(this->CurrencyID)+""));
return true;
 }
return false;
}

Currency* Currency::get() {
if(CurrencyID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Currency"
"WHERE CurrencyID ='"+QString::number(this->CurrencyID)+"'"));
while (query.next()) {
return new Currency(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new Currency();
 }

QList<Currency*> Currency::GetAll() {
	QList<Currency*> currencys =   QList<Currency*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency ORDER BY CurrencyID ASC"));
	while (query.next()) {
currencys.append(new Currency(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return currencys;
}

Currency* Currency::Get(int id) {
Currency* currency = new Currency();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Currency WHERE CurrencyID = '"+QString::number(id)+"' ORDER BY CurrencyID ASC "));
while (query.next()) {
currency = new Currency(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return currency;
}

Currency* Currency::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Currency();
}

Currency* Currency::Get(QString name) {
Currency* currency = new Currency();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency WHERE Description = '"+name+"'"));
while (query.next()) {
currency = new Currency(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return currency;
 }

QList<Currency*> Currency::Search(QString keyword) {
QList<Currency*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Currency(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> Currency::GetStringList() {
	QList<QString> list;
	QList<Currency*> currencys =   QList<Currency*>();
currencys = GetAll();
	for(int i = 0; i <currencys.count(); i++){
		list.append(currencys[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > Currency::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Currency*> currencys =   QList<Currency*>();
currencys = GetAll();
	for(int i = 0; i <currencys.count(); i++){
		list.append(qMakePair(currencys[i]->CurrencyID,currencys[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > Currency::GetPairList(QList<Currency*> currencys) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <currencys.count(); i++){
		list.append(qMakePair(currencys[i]->CurrencyID,currencys[i]->Description));
	}
	return list;
}

int Currency::GetIndex(QString name) {
	QList<Currency*> currencys =   QList<Currency*>();
currencys = GetAll();
	for(int i = 0; i <currencys.count(); i++){
		if(currencys[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<Currency*> Currency::QuerySelect(QString select) {
QList<Currency*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency WHERE "+select+"" ));
while (query.next()) {
list.append(new Currency(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags Currency::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Currency::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setDescription(id, value.toString());
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Currency::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->CurrencyID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Currency::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Currency!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Currency::setDescription(int CurrencyID, const QString &Description) {
QSqlQuery query;
query.prepare("update Currency set Description = ? where CurrencyID = ?");
query.addBindValue(Description);
query.addBindValue(CurrencyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Currency::setCreatedOn(int CurrencyID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Currency set CreatedOn = ? where CurrencyID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(CurrencyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Currency::setEditedOn(int CurrencyID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Currency set EditedOn = ? where CurrencyID = ?");
query.addBindValue(EditedOn);
query.addBindValue(CurrencyID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

