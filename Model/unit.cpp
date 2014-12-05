/**************************************************************************
**   File: unit.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "unit.h"
#include "erpmodel.h"

Unit::Unit()
 : QSqlRelationalTableModel(){

this->UnitID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Unit");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Unit::Unit(int UnitID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->UnitID = UnitID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Unit::Unit(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->UnitID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Unit::Init()
{

QString table = "Unit";
QString query =
"(UnitID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (UnitID),"
"Description VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Unit* Unit::p_instance = 0;
Unit* Unit::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Unit();
		Unit::GetAll();
	}
return p_instance;
}
bool Unit::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(UnitID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Unit (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Unit SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE UnitID ='"+QString::number(this->UnitID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  UnitID FROM Unit WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->UnitID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Unit::remove() {
if(UnitID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Unit WHERE UnitID ="+QString::number(this->UnitID)+""));
return true;
 }
return false;
}

Unit* Unit::get() {
if(UnitID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Unit"
"WHERE UnitID ='"+QString::number(this->UnitID)+"'"));
while (query.next()) {
return new Unit(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new Unit();
 }

QList<Unit*> Unit::GetAll() {
	QList<Unit*> units =   QList<Unit*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit"));
	while (query.next()) {
units.append(new Unit(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
qStableSort(units.begin(),units.end());
	return units;
}

Unit* Unit::Get(int id) {
Unit* unit = new Unit();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Unit WHERE UnitID = '"+QString::number(id)+"'"));
while (query.next()) {
unit = new Unit(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return unit;
}

Unit* Unit::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Unit();
}

Unit* Unit::Get(QString name) {
Unit* unit = new Unit();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit WHERE Description = '"+name+"'"));
while (query.next()) {
unit = new Unit(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return unit;
 }

QList<Unit*> Unit::Search(QString keyword) {
QList<Unit*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Unit(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> Unit::GetStringList() {
	QList<QString> list;
	QList<Unit*> units =   QList<Unit*>();
units = GetAll();
	for(int i = 0; i <units.count(); i++){
		list.append(units[i]->Description);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> Unit::GetHashList() {
	QHash<int,QString> list;
	QList<Unit*> units =   QList<Unit*>();
units = GetAll();
	for(int i = 0; i <units.count(); i++){
		list.insert(units[i]->UnitID,units[i]->Description);
	}
	return list;
}

int Unit::GetIndex(QString name) {
	QList<Unit*> units =   QList<Unit*>();
units = GetAll();
	for(int i = 0; i <units.count(); i++){
		if(units[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<Unit*> Unit::QuerySelect(QString select) {
QList<Unit*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Unit WHERE "+select+"" ));
while (query.next()) {
list.append(new Unit(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags Unit::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Unit::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool Unit::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->UnitID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Unit::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Unit!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Unit::setDescription(int UnitID, const QString &Description) {
QSqlQuery query;
query.prepare("update Unit set Description = ? where UnitID = ?");
query.addBindValue(Description);
query.addBindValue(UnitID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Unit::setCreatedOn(int UnitID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Unit set CreatedOn = ? where UnitID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(UnitID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Unit::setEditedOn(int UnitID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Unit set EditedOn = ? where UnitID = ?");
query.addBindValue(EditedOn);
query.addBindValue(UnitID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

