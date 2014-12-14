/**************************************************************************
**   File: project.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "project.h"
#include "erpmodel.h"

Project::Project()
 : QSqlRelationalTableModel(){

this->ProjectID = 0 ;
this->Title = "";
this->ProjectStatusID = 0 ;
this->ContactID = 0 ;
this->StartDate = "";
this->EndDate = "";
this->WillBeInvoiced = 0 ;
this->Note = "";
this->ProjectSalesID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Project");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("ProjectStatus", "ProjectStatusID", "Description"));
this->setRelation(3, QSqlRelation("Contact", "ContactID", "Name"));
}
Project::Project(int ProjectID,QString Title,int ProjectStatusID,int ContactID,QString StartDate,QString EndDate,bool WillBeInvoiced,QString Note,int ProjectSalesID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectID = ProjectID ;
this->Title = Title ;
this->ProjectStatusID = ProjectStatusID ;
this->ContactID = ContactID ;
this->StartDate = StartDate ;
this->EndDate = EndDate ;
this->WillBeInvoiced = WillBeInvoiced ;
this->Note = Note ;
this->ProjectSalesID = ProjectSalesID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Project::Project(QString Title,int ProjectStatusID,int ContactID,QString StartDate,QString EndDate,bool WillBeInvoiced,QString Note,int ProjectSalesID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectID = 0 ;
this->Title = Title ;
this->ProjectStatusID = ProjectStatusID ;
this->ContactID = ContactID ;
this->StartDate = StartDate ;
this->EndDate = EndDate ;
this->WillBeInvoiced = WillBeInvoiced ;
this->Note = Note ;
this->ProjectSalesID = ProjectSalesID ;
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
" KEY(Title),"
"ProjectStatusID INT NOT NULL, "
"FOREIGN KEY (ProjectStatusID) REFERENCES ProjectStatus(ProjectStatusID)  ON DELETE CASCADE,"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"StartDate VARCHAR(40) NOT NULL, "
"EndDate VARCHAR(40) NOT NULL, "
"WillBeInvoiced VARCHAR(1) NOT NULL, "
"Note VARCHAR(40) NOT NULL, "
"ProjectSalesID INT NOT NULL, "
"FOREIGN KEY (ProjectSalesID) REFERENCES ProjectSales(ProjectSalesID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Title")));variables.append(qMakePair(QString(" INT"),QString("ProjectStatusID")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("StartDate")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EndDate")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("WillBeInvoiced")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Note")));variables.append(qMakePair(QString(" INT"),QString("ProjectSalesID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
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
ErpModel::GetInstance()->qeryExec("INSERT INTO Project (Title,ProjectStatusID,ContactID,StartDate,EndDate,WillBeInvoiced,Note,ProjectSalesID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->ProjectStatusID)+"','"+QString::number(this->ContactID)+"','"+QString(this->StartDate)+"','"+QString(this->EndDate)+"','"+QString::number(this->WillBeInvoiced)+"','"+QString(this->Note)+"','"+QString::number(this->ProjectSalesID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Project SET "	"Title = '"+QString(this->Title)+"',"+"ProjectStatusID = '"+QString::number(this->ProjectStatusID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"StartDate = '"+QString(this->StartDate)+"',"+"EndDate = '"+QString(this->EndDate)+"',"+"WillBeInvoiced = '"+QString::number(this->WillBeInvoiced)+"',"+"Note = '"+QString(this->Note)+"',"+"ProjectSalesID = '"+QString::number(this->ProjectSalesID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectID ='"+QString::number(this->ProjectID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectID FROM Project WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Project::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
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
return new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString());
 }

}
return new Project();
 }

QList<Project*> Project::GetAll() {
	QList<Project*> projects =   QList<Project*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Project ORDER BY ProjectID ASC"));
	while (query.next()) {
projects.append(new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString()));
	}
	return projects;
}

Project* Project::Get(int id) {
Project* project = new Project();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Project WHERE ProjectID = '"+QString::number(id)+"' ORDER BY ProjectID ASC "));
while (query.next()) {
project = new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString());
 }
project->tasks = Task::QuerySelect("ProjectID = " + QString::number(id));
project->projectcontactpersons = ProjectContactPerson::QuerySelect("ProjectID = " + QString::number(id));
project->projectproducts = ProjectProduct::QuerySelect("ProjectID = " + QString::number(id));
project->projectservices = ProjectService::QuerySelect("ProjectID = " + QString::number(id));
project->projectfiles = ProjectFile::QuerySelect("ProjectID = " + QString::number(id));

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
project = new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString());

 }
project->tasks = Task::QuerySelect("ProjectID = " +QString::number(project->ProjectID));
project->projectcontactpersons = ProjectContactPerson::QuerySelect("ProjectID = " +QString::number(project->ProjectID));
project->projectproducts = ProjectProduct::QuerySelect("ProjectID = " +QString::number(project->ProjectID));
project->projectservices = ProjectService::QuerySelect("ProjectID = " +QString::number(project->ProjectID));
project->projectfiles = ProjectFile::QuerySelect("ProjectID = " +QString::number(project->ProjectID));

}
return project;
 }

QList<Project*> Project::Search(QString keyword) {
QList<Project*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Project"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR StartDate LIKE '%"+keyword+"%'"
"OR EndDate LIKE '%"+keyword+"%'"
"OR Note LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString()));
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
	return list;
}

QList<QPair< int,QString > > Project::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Project*> projects =   QList<Project*>();
projects = GetAll();
	for(int i = 0; i <projects.count(); i++){
		list.append(qMakePair(projects[i]->ProjectID,projects[i]->Title));
	}
	return list;
}

QList<QPair< int,QString > > Project::GetPairList(QList<Project*> projects) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projects.count(); i++){
		list.append(qMakePair(projects[i]->ProjectID,projects[i]->Title));
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
list.append(new Project(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toInt(),query.value(9).toString(),query.value(10).toString()));
 }

}
return list;
 }

Qt::ItemFlags Project::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 14 || index.column() == 15)
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
ok = setProjectStatusID(id, value.toString());
else if (index.column() == 3)
ok = setContactID(id, value.toString());
else if (index.column() == 4)
ok = setStartDate(id, value.toString());
else if (index.column() == 5)
ok = setEndDate(id, value.toString());
else if (index.column() == 6)
ok = setWillBeInvoiced(id, value.toString());
else if (index.column() == 7)
ok = setNote(id, value.toString());
else if (index.column() == 8)
ok = setProjectSalesID(id, value.toString());
else if (index.column() == 14)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 15)
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
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Project Status"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Start Date"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("End Date"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Will Be Invoiced"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Note"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Project Sales"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Edited On"));
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
bool Project::setProjectStatusID(int ProjectID, const QString &ProjectStatusID) {
QSqlQuery query;
query.prepare("update Project set ProjectStatusID = ? where ProjectID = ?");
query.addBindValue(ProjectStatusID);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setContactID(int ProjectID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update Project set ContactID = ? where ProjectID = ?");
query.addBindValue(ContactID);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setStartDate(int ProjectID, const QString &StartDate) {
QSqlQuery query;
query.prepare("update Project set StartDate = ? where ProjectID = ?");
query.addBindValue(StartDate);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setEndDate(int ProjectID, const QString &EndDate) {
QSqlQuery query;
query.prepare("update Project set EndDate = ? where ProjectID = ?");
query.addBindValue(EndDate);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setWillBeInvoiced(int ProjectID, const QString &WillBeInvoiced) {
QSqlQuery query;
query.prepare("update Project set WillBeInvoiced = ? where ProjectID = ?");
query.addBindValue(WillBeInvoiced);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setNote(int ProjectID, const QString &Note) {
QSqlQuery query;
query.prepare("update Project set Note = ? where ProjectID = ?");
query.addBindValue(Note);
query.addBindValue(ProjectID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Project::setProjectSalesID(int ProjectID, const QString &ProjectSalesID) {
QSqlQuery query;
query.prepare("update Project set ProjectSalesID = ? where ProjectID = ?");
query.addBindValue(ProjectSalesID);
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

