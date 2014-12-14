/**************************************************************************
**   File: projectfile.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "projectfile.h"
#include "erpmodel.h"

ProjectFile::ProjectFile()
 : QSqlRelationalTableModel(){

this->ProjectFileID = 0 ;
this->Name = "";
this->imageData = 0 ;
this->ProjectID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProjectFile");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(3, QSqlRelation("Project", "ProjectID", "Title"));
}
ProjectFile::ProjectFile(int ProjectFileID,QString Name,QVariant imageData,int ProjectID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectFileID = ProjectFileID ;
this->Name = Name ;
this->imageData = imageData ;
this->ProjectID = ProjectID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProjectFile::ProjectFile(QString Name,QVariant imageData,int ProjectID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectFileID = 0 ;
this->Name = Name ;
this->imageData = imageData ;
this->ProjectID = ProjectID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProjectFile::Init()
{

QString table = "ProjectFile";
QString query =
"(ProjectFileID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProjectFileID),"
"Name VARCHAR(40) NOT NULL, "
" KEY(Name),"
"imageData LONGBLOB NOT NULL, "
"ProjectID INT NOT NULL, "
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProjectFileID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Name")));variables.append(qMakePair(QString(" LONGBLOB"),QString("imageData")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProjectFile* ProjectFile::p_instance = 0;
ProjectFile* ProjectFile::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProjectFile();
		ProjectFile::GetAll();
	}
return p_instance;
}
bool ProjectFile::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProjectFileID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProjectFile (Name,imageData,ProjectID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Name)+"','"+(this->imageData.toString())+"','"+QString::number(this->ProjectID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProjectFile SET "	"Name = '"+QString(this->Name)+"',"+"imageData = '"+(this->imageData.toString())+"',"+"ProjectID = '"+QString::number(this->ProjectID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectFileID ='"+QString::number(this->ProjectFileID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectFileID FROM ProjectFile WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectFileID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProjectFile::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProjectFile::remove() {
if(ProjectFileID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProjectFile WHERE ProjectFileID ="+QString::number(this->ProjectFileID)+""));
return true;
 }
return false;
}

ProjectFile* ProjectFile::get() {
if(ProjectFileID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectFile"
"WHERE ProjectFileID ='"+QString::number(this->ProjectFileID)+"'"));
while (query.next()) {
return new ProjectFile(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new ProjectFile();
 }

QList<ProjectFile*> ProjectFile::GetAll() {
	QList<ProjectFile*> projectfiles =   QList<ProjectFile*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectFile ORDER BY ProjectFileID ASC"));
	while (query.next()) {
projectfiles.append(new ProjectFile(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
	return projectfiles;
}

ProjectFile* ProjectFile::Get(int id) {
ProjectFile* projectfile = new ProjectFile();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectFile WHERE ProjectFileID = '"+QString::number(id)+"' ORDER BY ProjectFileID ASC "));
while (query.next()) {
projectfile = new ProjectFile(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return projectfile;
}

ProjectFile* ProjectFile::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProjectFile();
}

ProjectFile* ProjectFile::Get(QString name) {
ProjectFile* projectfile = new ProjectFile();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectFile WHERE Name = '"+name+"'"));
while (query.next()) {
projectfile = new ProjectFile(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return projectfile;
 }

QList<ProjectFile*> ProjectFile::Search(QString keyword) {
QList<ProjectFile*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectFile"
"WHERE" 
"Name LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProjectFile(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> ProjectFile::GetStringList() {
	QList<QString> list;
	QList<ProjectFile*> projectfiles =   QList<ProjectFile*>();
projectfiles = GetAll();
	for(int i = 0; i <projectfiles.count(); i++){
		list.append(projectfiles[i]->Name);
	}
	return list;
}

QList<QPair< int,QString > > ProjectFile::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProjectFile*> projectfiles =   QList<ProjectFile*>();
projectfiles = GetAll();
	for(int i = 0; i <projectfiles.count(); i++){
		list.append(qMakePair(projectfiles[i]->ProjectFileID,projectfiles[i]->Name));
	}
	return list;
}

QList<QPair< int,QString > > ProjectFile::GetPairList(QList<ProjectFile*> projectfiles) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projectfiles.count(); i++){
		list.append(qMakePair(projectfiles[i]->ProjectFileID,projectfiles[i]->Name));
	}
	return list;
}

int ProjectFile::GetIndex(QString name) {
	QList<ProjectFile*> projectfiles =   QList<ProjectFile*>();
projectfiles = GetAll();
	for(int i = 0; i <projectfiles.count(); i++){
		if(projectfiles[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<ProjectFile*> ProjectFile::QuerySelect(QString select) {
QList<ProjectFile*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectFile WHERE "+select+"" ));
while (query.next()) {
list.append(new ProjectFile(query.value(0).toInt(),query.value(1).toString(),query.value(2),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProjectFile::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProjectFile::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setName(id, value.toString());
else if (index.column() == 2)
ok = setimageData(id, value.toString());
else if (index.column() == 3)
ok = setProjectID(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProjectFile::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectFileID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProjectFile::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProjectFile!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("imageData"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProjectFile::setName(int ProjectFileID, const QString &Name) {
QSqlQuery query;
query.prepare("update ProjectFile set Name = ? where ProjectFileID = ?");
query.addBindValue(Name);
query.addBindValue(ProjectFileID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectFile::setimageData(int ProjectFileID, const QString &imageData) {
QSqlQuery query;
query.prepare("update ProjectFile set imageData = ? where ProjectFileID = ?");
query.addBindValue(imageData);
query.addBindValue(ProjectFileID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectFile::setProjectID(int ProjectFileID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update ProjectFile set ProjectID = ? where ProjectFileID = ?");
query.addBindValue(ProjectID);
query.addBindValue(ProjectFileID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectFile::setCreatedOn(int ProjectFileID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProjectFile set CreatedOn = ? where ProjectFileID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectFileID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectFile::setEditedOn(int ProjectFileID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProjectFile set EditedOn = ? where ProjectFileID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectFileID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

