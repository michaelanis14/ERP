/**************************************************************************
**   File: currency.cpp
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "currency.h"
#include "erpmodel.h"

Currency::Currency()
 : QSqlRelationalTableModel(){

this->CurrencyID = 0 ;
this->Description = " ";
this->setTable("Currency");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Currency::Currency(int CurrencyID,QString Description) : QSqlRelationalTableModel(){
this->CurrencyID = CurrencyID ;
this->Description = Description ;
}

Currency::Currency(QString Description) : QSqlRelationalTableModel(){
this->CurrencyID = 0 ;
this->Description = Description ;
}

bool Currency::init()
{

QString table = "Currency";
QString query =
"(CurrencyID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (CurrencyID),"
"Description VARCHAR(40) NOT NULL )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Currency* Currency::p_instance = 0;
Currency* Currency::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Currency();
		Currency::getAll();
	}
return p_instance;
}
bool Currency::save() {
if(CurrencyID== 0) {
ErpModel::GetInstance()->qeryExec("INSERT INTO Currency (Description)"
"VALUES ('" +QString(this->Description)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Currency SET ""Description = '"+QString(this->Description)+"' WHERE CurrencyID ='"+QString::number(this->CurrencyID)+"'");
 }
return true;
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
return new Currency(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Currency();
 }

QList<Currency*> Currency::getAll() {
	Currency::GetInstance()->currencys.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"));
	while (query.next()) {
		Currency::GetInstance()->currencys.append(new Currency(query.value(0).toInt(),query.value(1).toString()));
	}
	return Currency::GetInstance()->currencys;
}

Currency* Currency::get(int id) {
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Currency"
"WHERE CurrencyID = '"+QString::number(id)+"'"));
while (query.next()) {
return new Currency(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Currency();
 }

Currency* Currency::get(QString name) {
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency WHERE Description = '"+name+"'"));
while (query.next()) {
return new Currency(query.value(0).toInt(),query.value(1).toString());
 }

}
return new Currency();
 }

QList<Currency*> Currency::search(QString keyword) {
QList<Currency*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Currency(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

QList<QString> Currency::GetStringList() {
	QList<QString> list;
	int count =Currency::GetInstance()->currencys.count();
	if( count < 2){
		Currency::getAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Currency::GetInstance()->currencys[i]->Description);
	}
	return list;
}

QHash<int,QString> Currency::GetHashList() {
	QHash<int,QString> list;
	int count =Currency::GetInstance()->currencys.count();
	if( count < 2){
		Currency::getAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(Currency::GetInstance()->currencys[i]->CurrencyID,Currency::GetInstance()->currencys[i]->Description);
	}
	return list;
}

int Currency::GetIndex(QString name) {
	int count =Currency::GetInstance()->currencys.count();
	if( count < 2){
		Currency::getAll();
	}
	for(int i = 0; i < count; i++){
		if(Currency::GetInstance()->currencys[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<Currency*> Currency::querySelect(QString select) {
QList<Currency*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Currency"
"WHERE '"+select+"'" ));
while (query.next()) {
list.append(new Currency(query.value(0).toInt(),query.value(1).toString()));
 }

}
return list;
 }

Qt::ItemFlags Currency::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1)
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

