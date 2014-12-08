/**************************************************************************
**   File: tax.cpp
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "tax.h"
#include "erpmodel.h"

Tax::Tax()
 : QSqlRelationalTableModel(){

this->TaxID = 0 ;
this->Title = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Tax");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Tax::Tax(int TaxID,QString Title,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TaxID = TaxID ;
this->Title = Title ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Tax::Tax(QString Title,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TaxID = 0 ;
this->Title = Title ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Tax::Init()
{

QString table = "Tax";
QString query =
"(TaxID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (TaxID),"
"Title VARCHAR(40) NOT NULL, "
" KEY(Title),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Tax* Tax::p_instance = 0;
Tax* Tax::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Tax();
		Tax::GetAll();
	}
return p_instance;
}
bool Tax::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(TaxID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Tax (Title,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Tax SET "	"Title = '"+QString(this->Title)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE TaxID ='"+QString::number(this->TaxID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  TaxID FROM Tax WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->TaxID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Tax::remove() {
if(TaxID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Tax WHERE TaxID ="+QString::number(this->TaxID)+""));
return true;
 }
return false;
}

Tax* Tax::get() {
if(TaxID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Tax"
"WHERE TaxID ='"+QString::number(this->TaxID)+"'"));
while (query.next()) {
return new Tax(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new Tax();
 }

QList<Tax*> Tax::GetAll() {
	QList<Tax*> taxs =   QList<Tax*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"));
	while (query.next()) {
taxs.append(new Tax(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
qStableSort(taxs.begin(),taxs.end());
	return taxs;
}

Tax* Tax::Get(int id) {
Tax* tax = new Tax();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Tax WHERE TaxID = '"+QString::number(id)+"'"));
while (query.next()) {
tax = new Tax(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return tax;
}

Tax* Tax::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Tax();
}

Tax* Tax::Get(QString name) {
Tax* tax = new Tax();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax WHERE Title = '"+name+"'"));
while (query.next()) {
tax = new Tax(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return tax;
 }

QList<Tax*> Tax::Search(QString keyword) {
QList<Tax*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Tax(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> Tax::GetStringList() {
	QList<QString> list;
	QList<Tax*> taxs =   QList<Tax*>();
taxs = GetAll();
	for(int i = 0; i <taxs.count(); i++){
		list.append(taxs[i]->Title);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> Tax::GetHashList() {
	QHash<int,QString> list;
	QList<Tax*> taxs =   QList<Tax*>();
taxs = GetAll();
	for(int i = 0; i <taxs.count(); i++){
		list.insert(taxs[i]->TaxID,taxs[i]->Title);
	}
	return list;
}

int Tax::GetIndex(QString name) {
	QList<Tax*> taxs =   QList<Tax*>();
taxs = GetAll();
	for(int i = 0; i <taxs.count(); i++){
		if(taxs[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<Tax*> Tax::QuerySelect(QString select) {
QList<Tax*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax WHERE "+select+"" ));
while (query.next()) {
list.append(new Tax(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags Tax::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Tax::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setTitle(id, value.toString());
else if (index.column() == 2)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 3)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Tax::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->TaxID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Tax::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Tax!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Tax::setTitle(int TaxID, const QString &Title) {
QSqlQuery query;
query.prepare("update Tax set Title = ? where TaxID = ?");
query.addBindValue(Title);
query.addBindValue(TaxID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Tax::setCreatedOn(int TaxID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Tax set CreatedOn = ? where TaxID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(TaxID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Tax::setEditedOn(int TaxID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Tax set EditedOn = ? where TaxID = ?");
query.addBindValue(EditedOn);
query.addBindValue(TaxID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

