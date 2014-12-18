/**************************************************************************
**   File: projectcontactperson.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "projectcontactperson.h"
#include "erpmodel.h"

ProjectContactPerson::ProjectContactPerson()
 : QSqlRelationalTableModel(){

this->ProjectContactPersonID = 0 ;
this->ProjectID = 0 ;
this->ContactPersonID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProjectContactPerson");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(2, QSqlRelation("ContactPerson", "ContactPersonID", "Title"));
this->setRelation(2, QSqlRelation("ContactPerson", "ContactPersonID", "TitleName"));
}
ProjectContactPerson::ProjectContactPerson(int ProjectContactPersonID,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectContactPersonID = ProjectContactPersonID ;
this->ProjectID = ProjectID ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProjectContactPerson::ProjectContactPerson(int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectContactPersonID = 0 ;
this->ProjectID = ProjectID ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProjectContactPerson::Init()
{

QString table = "ProjectContactPerson";
QString query =
"(ProjectContactPersonID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProjectContactPersonID),"
"ProjectID INT NOT NULL, "
" KEY(ProjectID),"
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"ContactPersonID INT NOT NULL, "
"FOREIGN KEY (ContactPersonID) REFERENCES ContactPerson(ContactPersonID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProjectContactPersonID")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" INT"),QString("ContactPersonID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProjectContactPerson* ProjectContactPerson::p_instance = 0;
ProjectContactPerson* ProjectContactPerson::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProjectContactPerson();
		ProjectContactPerson::GetAll();
	}
return p_instance;
}
bool ProjectContactPerson::save() {
this->EditedOn = QDate::currentDate().toString();
if(ProjectContactPersonID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProjectContactPerson (ProjectID,ContactPersonID,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ProjectID)+"','"+QString::number(this->ContactPersonID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProjectContactPerson SET "	"ProjectID = '"+QString::number(this->ProjectID)+"',"+"ContactPersonID = '"+QString::number(this->ContactPersonID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectContactPersonID ='"+QString::number(this->ProjectContactPersonID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectContactPersonID FROM ProjectContactPerson WHERE ProjectID = "+QString::number(ProjectID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectContactPersonID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProjectContactPerson::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProjectContactPerson::remove() {
if(ProjectContactPersonID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProjectContactPerson WHERE ProjectContactPersonID ="+QString::number(this->ProjectContactPersonID)+""));
return true;
 }
return false;
}

ProjectContactPerson* ProjectContactPerson::get() {
if(ProjectContactPersonID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectContactPerson"
"WHERE ProjectContactPersonID ='"+QString::number(this->ProjectContactPersonID)+"'"));
while (query.next()) {
return new ProjectContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new ProjectContactPerson();
 }

QList<ProjectContactPerson*> ProjectContactPerson::GetAll() {
	QList<ProjectContactPerson*> projectcontactpersons =   QList<ProjectContactPerson*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectContactPerson ORDER BY ProjectContactPersonID ASC"));
	while (query.next()) {
projectcontactpersons.append(new ProjectContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return projectcontactpersons;
}

ProjectContactPerson* ProjectContactPerson::Get(int id) {
ProjectContactPerson* projectcontactperson = new ProjectContactPerson();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectContactPerson WHERE ProjectContactPersonID = '"+QString::number(id)+"' ORDER BY ProjectContactPersonID ASC "));
while (query.next()) {
projectcontactperson = new ProjectContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return projectcontactperson;
}

ProjectContactPerson* ProjectContactPerson::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProjectContactPerson();
}

ProjectContactPerson* ProjectContactPerson::Get(QString name) {
ProjectContactPerson* projectcontactperson = new ProjectContactPerson();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectContactPerson WHERE ProjectID = QString::number("+name+")"));
while (query.next()) {
projectcontactperson = new ProjectContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return projectcontactperson;
 }

QList<ProjectContactPerson*> ProjectContactPerson::Search(QString keyword) {
QList<ProjectContactPerson*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectContactPerson"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProjectContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> ProjectContactPerson::GetStringList() {
	QList<QString> list;
	QList<ProjectContactPerson*> projectcontactpersons =   QList<ProjectContactPerson*>();
projectcontactpersons = GetAll();
	for(int i = 0; i <projectcontactpersons.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ProjectContactPerson::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProjectContactPerson*> projectcontactpersons =   QList<ProjectContactPerson*>();
projectcontactpersons = GetAll();
	for(int i = 0; i <projectcontactpersons.count(); i++){
		list.append(qMakePair(projectcontactpersons[i]->ProjectContactPersonID,QString::number(projectcontactpersons[i]->ProjectID)));
	}
	return list;
}

QList<QPair< int,QString > > ProjectContactPerson::GetPairList(QList<ProjectContactPerson*> projectcontactpersons) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projectcontactpersons.count(); i++){
		list.append(qMakePair(projectcontactpersons[i]->ProjectContactPersonID,QString::number(projectcontactpersons[i]->ProjectID)));
	}
	return list;
}

int ProjectContactPerson::GetIndex(QString name) {
	QList<ProjectContactPerson*> projectcontactpersons =   QList<ProjectContactPerson*>();
projectcontactpersons = GetAll();
	for(int i = 0; i <projectcontactpersons.count(); i++){
		if(projectcontactpersons[i]->ProjectID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ProjectContactPerson*> ProjectContactPerson::QuerySelect(QString select) {
QList<ProjectContactPerson*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectContactPerson WHERE "+select+"" ));
while (query.next()) {
list.append(new ProjectContactPerson(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProjectContactPerson::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProjectContactPerson::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setProjectID(id, value.toString());
else if (index.column() == 2)
ok = setContactPersonID(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProjectContactPerson::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectContactPersonID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProjectContactPerson::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProjectContactPerson!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Contact Person"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProjectContactPerson::setProjectID(int ProjectContactPersonID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update ProjectContactPerson set ProjectID = ? where ProjectContactPersonID = ?");
query.addBindValue(ProjectID);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectContactPerson::setContactPersonID(int ProjectContactPersonID, const QString &ContactPersonID) {
QSqlQuery query;
query.prepare("update ProjectContactPerson set ContactPersonID = ? where ProjectContactPersonID = ?");
query.addBindValue(ContactPersonID);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectContactPerson::setCreatedOn(int ProjectContactPersonID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProjectContactPerson set CreatedOn = ? where ProjectContactPersonID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectContactPerson::setEditedOn(int ProjectContactPersonID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProjectContactPerson set EditedOn = ? where ProjectContactPersonID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

