/**************************************************************************
**   File: project.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "project.h"
#include "erpmodel.h"

Project::Project()
 : QSqlRelationalTableModel(){

this->ProjectID = 0 ;
this->Title = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Project");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
Project::Project(int ProjectID,QString Title,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectID = ProjectID ;
this->Title = Title ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Project::Project(QString Title,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectID = 0 ;
this->Title = Title ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Project::Init()
{

QString table = "Project";
QString query =
"(ProjectID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProjectID),"
"Title VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Project* Project::p_instance = 0;
Project* Project::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Project();
		Project::GetAll();
	}
return p_instance;
}
bool Project::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProjectID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Project (Title,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Project SET "	"Title = '"+QString(this->Title)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectID ='"+QString::number(this->ProjectID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectID FROM Project WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Project::remove() {
if(ProjectID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Project WHERE ProjectID ="+QString::number(this->ProjectID)+""));
return true;
 }
return false;
}

Project* Project::get() {
if(ProjectID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Project"
"WHERE ProjectID ='"+QString::number(this->ProjectID)+"'"));
while (query.next()) {
return new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new Project();
 }

QList<Project*> Project::GetAll() {
	QList<Project*> projects =   QList<Project*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Project"));
	while (query.next()) {
projects.append(new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
qStableSort(projects.begin(),projects.end());
	return projects;
}

Project* Project::Get(int id) {
Project* project = new Project();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Project WHERE ProjectID = '"+QString::number(id)+"'"));
while (query.next()) {
project = new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return project;
}

Project* Project::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Project();
}

Project* Project::Get(QString name) {
Project* project = new Project();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Project WHERE Title = '"+name+"'"));
while (query.next()) {
project = new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return project;
 }

QList<Project*> Project::Search(QString keyword) {
QList<Project*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Project"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> Project::GetStringList() {
	QList<QString> list;
	QList<Project*> projects =   QList<Project*>();
projects = GetAll();
	for(int i = 0; i <projects.count(); i++){
		list.append(projects[i]->Title);
	}
qStableSort(list.begin(),list.end());
	return list;
}

QHash<int,QString> Project::GetHashList() {
	QHash<int,QString> list;
	QList<Project*> projects =   QList<Project*>();
projects = GetAll();
	for(int i = 0; i <projects.count(); i++){
		list.insert(projects[i]->ProjectID,projects[i]->Title);
	}
	return list;
}

int Project::GetIndex(QString name) {
	QList<Project*> projects =   QList<Project*>();
projects = GetAll();
	for(int i = 0; i <projects.count(); i++){
		if(projects[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<Project*> Project::QuerySelect(QString select) {
QList<Project*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Project WHERE "+select+"" ));
while (query.next()) {
list.append(new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags Project::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Project::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool Project::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Project::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Project!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Project::setTitle(int ProjectID, const QString &Title) {
QSqlQuery query;
query.prepare("update Project set Title = ? where ProjectID = ?");
query.addBindValue(Title);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setCreatedOn(int ProjectID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Project set CreatedOn = ? where ProjectID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setEditedOn(int ProjectID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Project set EditedOn = ? where ProjectID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

