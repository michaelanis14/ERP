/**************************************************************************
**   File: language.cpp
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "language.h"
#include "erpmodel.h"

Language::Language()
 : QSqlRelationalTableModel(){

this->LanguageID = 0 ;
this->Title = "";
this->File = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Language");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Language::Language(int LanguageID,QString Title,QString File,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->LanguageID = LanguageID ;
this->Title = Title ;
this->File = File ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Language::Language(QString Title,QString File,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->LanguageID = 0 ;
this->Title = Title ;
this->File = File ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Language::Init()
{

QString table = "Language";
QString query =
"(LanguageID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (LanguageID),"
"Title VARCHAR(40) NOT NULL, "
" KEY(Title),"
"File VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("LanguageID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Title")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("File")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Language* Language::p_instance = 0;
Language* Language::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Language();
		Language::GetAll();
	}
return p_instance;
}
bool Language::save() {
this->EditedOn = QDate::currentDate().toString();
if(LanguageID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Language (Title,File,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString(this->File)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Language SET "	"Title = '"+QString(this->Title)+"',"+"File = '"+QString(this->File)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE LanguageID ='"+QString::number(this->LanguageID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  LanguageID FROM Language WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->LanguageID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Language::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Language::remove() {
if(LanguageID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Language WHERE LanguageID ="+QString::number(this->LanguageID)+""));
return true;
 }
return false;
}

Language* Language::get() {
if(LanguageID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Language"
"WHERE LanguageID ='"+QString::number(this->LanguageID)+"'"));
while (query.next()) {
return new Language(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
 }

}
return new Language();
 }

QList<Language*> Language::GetAll() {
	QList<Language*> languages =   QList<Language*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Language ORDER BY LanguageID ASC"));
	while (query.next()) {
languages.append(new Language(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
	}
	return languages;
}

Language* Language::Get(int id) {
Language* language = new Language();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Language WHERE LanguageID = '"+QString::number(id)+"' ORDER BY LanguageID ASC "));
while (query.next()) {
language = new Language(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());
 }

}
return language;
}

Language* Language::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Language();
}

Language* Language::Get(QString name) {
Language* language = new Language();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Language WHERE Title = '"+name+"'"));
while (query.next()) {
language = new Language(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString());

 }

}
return language;
 }

QList<Language*> Language::Search(QString keyword) {
QList<Language*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Language"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR File LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Language(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> Language::GetStringList() {
	QList<QString> list;
	QList<Language*> languages =   QList<Language*>();
languages = GetAll();
	for(int i = 0; i <languages.count(); i++){
		list.append(languages[i]->Title);
	}
	return list;
}

QList<QPair< int,QString > > Language::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Language*> languages =   QList<Language*>();
languages = GetAll();
	for(int i = 0; i <languages.count(); i++){
		list.append(qMakePair(languages[i]->LanguageID,languages[i]->Title));
	}
	return list;
}

QList<QPair< int,QString > > Language::GetPairList(QList<Language*> languages) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <languages.count(); i++){
		list.append(qMakePair(languages[i]->LanguageID,languages[i]->Title));
	}
	return list;
}

int Language::GetIndex(QString name) {
	QList<Language*> languages =   QList<Language*>();
languages = GetAll();
	for(int i = 0; i <languages.count(); i++){
		if(languages[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<Language*> Language::QuerySelect(QString select) {
QList<Language*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Language WHERE "+select+"" ));
while (query.next()) {
list.append(new Language(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags Language::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Language::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setTitle(id, value.toString());
else if (index.column() == 2)
ok = setFile(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Language::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->LanguageID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Language::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Language!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("File"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Language::setTitle(int LanguageID, const QString &Title) {
QSqlQuery query;
query.prepare("update Language set Title = ? where LanguageID = ?");
query.addBindValue(Title);
query.addBindValue(LanguageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Language::setFile(int LanguageID, const QString &File) {
QSqlQuery query;
query.prepare("update Language set File = ? where LanguageID = ?");
query.addBindValue(File);
query.addBindValue(LanguageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Language::setCreatedOn(int LanguageID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Language set CreatedOn = ? where LanguageID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(LanguageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Language::setEditedOn(int LanguageID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Language set EditedOn = ? where LanguageID = ?");
query.addBindValue(EditedOn);
query.addBindValue(LanguageID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

