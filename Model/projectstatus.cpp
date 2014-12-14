/**************************************************************************
**   File: projectstatus.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "projectstatus.h"
#include "erpmodel.h"

ProjectStatus::ProjectStatus()
 : QSqlRelationalTableModel(){

this->ProjectStatusID = 0 ;
this->Description = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProjectStatus");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
ProjectStatus::ProjectStatus(int ProjectStatusID,QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectStatusID = ProjectStatusID ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProjectStatus::ProjectStatus(QString Description,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectStatusID = 0 ;
this->Description = Description ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProjectStatus::Init()
{

QString table = "ProjectStatus";
QString query =
"(ProjectStatusID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProjectStatusID),"
"Description VARCHAR(40) NOT NULL, "
" KEY(Description),"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProjectStatusID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Description")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProjectStatus* ProjectStatus::p_instance = 0;
ProjectStatus* ProjectStatus::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProjectStatus();
		ProjectStatus::GetAll();
	}
return p_instance;
}
bool ProjectStatus::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProjectStatusID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProjectStatus (Description,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Description)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProjectStatus SET "	"Description = '"+QString(this->Description)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectStatusID ='"+QString::number(this->ProjectStatusID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectStatusID FROM ProjectStatus WHERE Description = '"+Description+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectStatusID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProjectStatus::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProjectStatus::remove() {
if(ProjectStatusID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProjectStatus WHERE ProjectStatusID ="+QString::number(this->ProjectStatusID)+""));
return true;
 }
return false;
}

ProjectStatus* ProjectStatus::get() {
if(ProjectStatusID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectStatus"
"WHERE ProjectStatusID ='"+QString::number(this->ProjectStatusID)+"'"));
while (query.next()) {
return new ProjectStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return new ProjectStatus();
 }

QList<ProjectStatus*> ProjectStatus::GetAll() {
	QList<ProjectStatus*> projectstatuss =   QList<ProjectStatus*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectStatus ORDER BY ProjectStatusID ASC"));
	while (query.next()) {
projectstatuss.append(new ProjectStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
	}
	return projectstatuss;
}

ProjectStatus* ProjectStatus::Get(int id) {
ProjectStatus* projectstatus = new ProjectStatus();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectStatus WHERE ProjectStatusID = '"+QString::number(id)+"' ORDER BY ProjectStatusID ASC "));
while (query.next()) {
projectstatus = new ProjectStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
 }

}
return projectstatus;
}

ProjectStatus* ProjectStatus::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProjectStatus();
}

ProjectStatus* ProjectStatus::Get(QString name) {
ProjectStatus* projectstatus = new ProjectStatus();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectStatus WHERE Description = '"+name+"'"));
while (query.next()) {
projectstatus = new ProjectStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString());

 }

}
return projectstatus;
 }

QList<ProjectStatus*> ProjectStatus::Search(QString keyword) {
QList<ProjectStatus*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectStatus"
"WHERE" 
"Description LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProjectStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

QList<QString> ProjectStatus::GetStringList() {
	QList<QString> list;
	QList<ProjectStatus*> projectstatuss =   QList<ProjectStatus*>();
projectstatuss = GetAll();
	for(int i = 0; i <projectstatuss.count(); i++){
		list.append(projectstatuss[i]->Description);
	}
	return list;
}

QList<QPair< int,QString > > ProjectStatus::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProjectStatus*> projectstatuss =   QList<ProjectStatus*>();
projectstatuss = GetAll();
	for(int i = 0; i <projectstatuss.count(); i++){
		list.append(qMakePair(projectstatuss[i]->ProjectStatusID,projectstatuss[i]->Description));
	}
	return list;
}

QList<QPair< int,QString > > ProjectStatus::GetPairList(QList<ProjectStatus*> projectstatuss) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projectstatuss.count(); i++){
		list.append(qMakePair(projectstatuss[i]->ProjectStatusID,projectstatuss[i]->Description));
	}
	return list;
}

int ProjectStatus::GetIndex(QString name) {
	QList<ProjectStatus*> projectstatuss =   QList<ProjectStatus*>();
projectstatuss = GetAll();
	for(int i = 0; i <projectstatuss.count(); i++){
		if(projectstatuss[i]->Description == name){
			return i;
		}
	}
	return 0;
}

QList<ProjectStatus*> ProjectStatus::QuerySelect(QString select) {
QList<ProjectStatus*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectStatus WHERE "+select+"" ));
while (query.next()) {
list.append(new ProjectStatus(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProjectStatus::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProjectStatus::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool ProjectStatus::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectStatusID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProjectStatus::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProjectStatus!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProjectStatus::setDescription(int ProjectStatusID, const QString &Description) {
QSqlQuery query;
query.prepare("update ProjectStatus set Description = ? where ProjectStatusID = ?");
query.addBindValue(Description);
query.addBindValue(ProjectStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectStatus::setCreatedOn(int ProjectStatusID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProjectStatus set CreatedOn = ? where ProjectStatusID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectStatus::setEditedOn(int ProjectStatusID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProjectStatus set EditedOn = ? where ProjectStatusID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectStatusID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

