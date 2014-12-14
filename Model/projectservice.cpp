/**************************************************************************
**   File: projectservice.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "projectservice.h"
#include "erpmodel.h"

ProjectService::ProjectService()
 : QSqlRelationalTableModel(){

this->ProjectServiceID = 0 ;
this->ProjectID = 0 ;
this->ServiceID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProjectService");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(2, QSqlRelation("Service", "ServiceID", "Name"));
}
ProjectService::ProjectService(int ProjectServiceID,int ProjectID,int ServiceID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectServiceID = ProjectServiceID ;
this->ProjectID = ProjectID ;
this->ServiceID = ServiceID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProjectService::ProjectService(int ProjectID,int ServiceID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectServiceID = 0 ;
this->ProjectID = ProjectID ;
this->ServiceID = ServiceID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProjectService::Init()
{

QString table = "ProjectService";
QString query =
"(ProjectServiceID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProjectServiceID),"
"ProjectID INT NOT NULL, "
" KEY(ProjectID),"
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"ServiceID INT NOT NULL, "
"FOREIGN KEY (ServiceID) REFERENCES Service(ServiceID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProjectServiceID")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" INT"),QString("ServiceID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProjectService* ProjectService::p_instance = 0;
ProjectService* ProjectService::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProjectService();
		ProjectService::GetAll();
	}
return p_instance;
}
bool ProjectService::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProjectServiceID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProjectService (ProjectID,ServiceID,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ProjectID)+"','"+QString::number(this->ServiceID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProjectService SET "	"ProjectID = '"+QString::number(this->ProjectID)+"',"+"ServiceID = '"+QString::number(this->ServiceID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectServiceID ='"+QString::number(this->ProjectServiceID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectServiceID FROM ProjectService WHERE ProjectID = "+QString::number(ProjectID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectServiceID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProjectService::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProjectService::remove() {
if(ProjectServiceID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProjectService WHERE ProjectServiceID ="+QString::number(this->ProjectServiceID)+""));
return true;
 }
return false;
}

ProjectService* ProjectService::get() {
if(ProjectServiceID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectService"
"WHERE ProjectServiceID ='"+QString::number(this->ProjectServiceID)+"'"));
while (query.next()) {
return new ProjectService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new ProjectService();
 }

QList<ProjectService*> ProjectService::GetAll() {
	QList<ProjectService*> projectservices =   QList<ProjectService*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectService ORDER BY ProjectServiceID ASC"));
	while (query.next()) {
projectservices.append(new ProjectService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return projectservices;
}

ProjectService* ProjectService::Get(int id) {
ProjectService* projectservice = new ProjectService();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectService WHERE ProjectServiceID = '"+QString::number(id)+"' ORDER BY ProjectServiceID ASC "));
while (query.next()) {
projectservice = new ProjectService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return projectservice;
}

ProjectService* ProjectService::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProjectService();
}

ProjectService* ProjectService::Get(QString name) {
ProjectService* projectservice = new ProjectService();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectService WHERE ProjectID = QString::number("+name+")"));
while (query.next()) {
projectservice = new ProjectService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return projectservice;
 }

QList<ProjectService*> ProjectService::Search(QString keyword) {
QList<ProjectService*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectService"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProjectService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> ProjectService::GetStringList() {
	QList<QString> list;
	QList<ProjectService*> projectservices =   QList<ProjectService*>();
projectservices = GetAll();
	for(int i = 0; i <projectservices.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ProjectService::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProjectService*> projectservices =   QList<ProjectService*>();
projectservices = GetAll();
	for(int i = 0; i <projectservices.count(); i++){
		list.append(qMakePair(projectservices[i]->ProjectServiceID,QString::number(projectservices[i]->ProjectID)));
	}
	return list;
}

QList<QPair< int,QString > > ProjectService::GetPairList(QList<ProjectService*> projectservices) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projectservices.count(); i++){
		list.append(qMakePair(projectservices[i]->ProjectServiceID,QString::number(projectservices[i]->ProjectID)));
	}
	return list;
}

int ProjectService::GetIndex(QString name) {
	QList<ProjectService*> projectservices =   QList<ProjectService*>();
projectservices = GetAll();
	for(int i = 0; i <projectservices.count(); i++){
		if(projectservices[i]->ProjectID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ProjectService*> ProjectService::QuerySelect(QString select) {
QList<ProjectService*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectService WHERE "+select+"" ));
while (query.next()) {
list.append(new ProjectService(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProjectService::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProjectService::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setProjectID(id, value.toString());
else if (index.column() == 2)
ok = setServiceID(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProjectService::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectServiceID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProjectService::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProjectService!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Service"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProjectService::setProjectID(int ProjectServiceID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update ProjectService set ProjectID = ? where ProjectServiceID = ?");
query.addBindValue(ProjectID);
query.addBindValue(ProjectServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectService::setServiceID(int ProjectServiceID, const QString &ServiceID) {
QSqlQuery query;
query.prepare("update ProjectService set ServiceID = ? where ProjectServiceID = ?");
query.addBindValue(ServiceID);
query.addBindValue(ProjectServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectService::setCreatedOn(int ProjectServiceID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProjectService set CreatedOn = ? where ProjectServiceID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectService::setEditedOn(int ProjectServiceID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProjectService set EditedOn = ? where ProjectServiceID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectServiceID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

