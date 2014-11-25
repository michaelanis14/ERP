/**************************************************************************
**   File: tax.cpp
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "tax.h"
#include "erpmodel.h"

Tax::Tax()
 : QSqlRelationalTableModel(){

this->TaxID = 0 ;
this->Ratio = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Tax");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Tax::Tax(int TaxID,double Ratio,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TaxID = TaxID ;
this->Ratio = Ratio ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Tax::Tax(double Ratio,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TaxID = 0 ;
this->Ratio = Ratio ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Tax::Init()
{

QString table = "Tax";
QString query =
"(TaxID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (TaxID),"
"Ratio DECIMAL(6,2) NOT NULL, "
"Description VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL )" ;

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
ErpModel::GetInstance()->qeryExec("INSERT INTO Tax (Ratio,Description,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->Ratio)+"','"+QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Tax SET "	"Ratio = '"+QString::number(this->Ratio)+"',"+"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE TaxID ='"+QString::number(this->TaxID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  TaxID FROM Tax WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
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
return new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
 }

}
return new Tax();
 }

QList<Tax*> Tax::GetAll() {
	Tax::GetInstance()->taxs.clear();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"));
	while (query.next()) {
		Tax::GetInstance()->taxs.append(new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
	}
	return Tax::GetInstance()->taxs;
}

Tax* Tax::Get(int id) {
Tax* tax = new Tax();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Tax WHERE TaxID = '"+QString::number(id)+"'"));
while (query.next()) {
tax = new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
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
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax WHERE Description = '"+name+"'"));
while (query.next()) {
tax = new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());

 }

}
return tax;
 }

QList<Tax*> Tax::Search(QString keyword) {
QList<Tax*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Tax"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> Tax::GetStringList() {
	QList<QString> list;
	int count =Tax::GetInstance()->taxs.count();
	if( count < 2){
		Tax::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.append(Tax::GetInstance()->taxs[i]->Description);
	}
	return list;
}

QHash<int,QString> Tax::GetHashList() {
	QHash<int,QString> list;
	int count =Tax::GetInstance()->taxs.count();
	if( count < 2){
		Tax::GetAll();
	}
	for(int i = 0; i < count; i++){
		list.insert(Tax::GetInstance()->taxs[i]->TaxID,Tax::GetInstance()->taxs[i]->Description);
	}
	return list;
}

int Tax::GetIndex(QString name) {
	int count =Tax::GetInstance()->taxs.count();
	if( count < 2){
		Tax::GetAll();
	}
	for(int i = 0; i < count; i++){
		if(Tax::GetInstance()->taxs[i]->Description == name){
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
list.append(new Tax(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags Tax::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
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
ok = setRatio(id, value.toString());
else if (index.column() == 2)
ok = setDescription(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
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
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Ratio"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Tax::setRatio(int TaxID, const QString &Ratio) {
QSqlQuery query;
query.prepare("update Tax set Ratio = ? where TaxID = ?");
query.addBindValue(Ratio);
query.addBindValue(TaxID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Tax::setDescription(int TaxID, const QString &Description) {
QSqlQuery query;
query.prepare("update Tax set Description = ? where TaxID = ?");
query.addBindValue(Description);
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

