/**************************************************************************
**   File: projectsales.cpp
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "projectsales.h"
#include "erpmodel.h"

ProjectSales::ProjectSales()
 : QSqlRelationalTableModel(){

this->ProjectSalesID = 0 ;
this->ProjectID = 0 ;
this->ContactID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProjectSales");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(2, QSqlRelation("Contact", "ContactID", "Name"));
}
ProjectSales::ProjectSales(int ProjectSalesID,int ProjectID,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectSalesID = ProjectSalesID ;
this->ProjectID = ProjectID ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProjectSales::ProjectSales(int ProjectID,int ContactID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectSalesID = 0 ;
this->ProjectID = ProjectID ;
this->ContactID = ContactID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProjectSales::Init()
{

QString table = "ProjectSales";
QString query =
"(ProjectSalesID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProjectSalesID),"
"ProjectID INT NOT NULL, "
" KEY(ProjectID),"
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"ContactID INT NOT NULL, "
"FOREIGN KEY (ContactID) REFERENCES Contact(ContactID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProjectSalesID")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" INT"),QString("ContactID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProjectSales* ProjectSales::p_instance = 0;
ProjectSales* ProjectSales::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProjectSales();
		ProjectSales::GetAll();
	}
return p_instance;
}
bool ProjectSales::save() {
this->EditedOn = QDate::currentDate().toString();
if(ProjectSalesID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProjectSales (ProjectID,ContactID,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ProjectID)+"','"+QString::number(this->ContactID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProjectSales SET "	"ProjectID = '"+QString::number(this->ProjectID)+"',"+"ContactID = '"+QString::number(this->ContactID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectSalesID ='"+QString::number(this->ProjectSalesID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectSalesID FROM ProjectSales WHERE ProjectID = "+QString::number(ProjectID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectSalesID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProjectSales::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProjectSales::remove() {
if(ProjectSalesID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProjectSales WHERE ProjectSalesID ="+QString::number(this->ProjectSalesID)+""));
return true;
 }
return false;
}

ProjectSales* ProjectSales::get() {
if(ProjectSalesID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectSales"
"WHERE ProjectSalesID ='"+QString::number(this->ProjectSalesID)+"'"));
while (query.next()) {
return new ProjectSales(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new ProjectSales();
 }

QList<ProjectSales*> ProjectSales::GetAll() {
	QList<ProjectSales*> projectsaless =   QList<ProjectSales*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectSales ORDER BY ProjectSalesID ASC"));
	while (query.next()) {
projectsaless.append(new ProjectSales(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return projectsaless;
}

ProjectSales* ProjectSales::Get(int id) {
ProjectSales* projectsales = new ProjectSales();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectSales WHERE ProjectSalesID = '"+QString::number(id)+"' ORDER BY ProjectSalesID ASC "));
while (query.next()) {
projectsales = new ProjectSales(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return projectsales;
}

ProjectSales* ProjectSales::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProjectSales();
}

ProjectSales* ProjectSales::Get(QString name) {
ProjectSales* projectsales = new ProjectSales();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectSales WHERE ProjectID = QString::number("+name+")"));
while (query.next()) {
projectsales = new ProjectSales(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return projectsales;
 }

QList<ProjectSales*> ProjectSales::Search(QString keyword) {
QList<ProjectSales*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectSales"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProjectSales(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> ProjectSales::GetStringList() {
	QList<QString> list;
	QList<ProjectSales*> projectsaless =   QList<ProjectSales*>();
projectsaless = GetAll();
	for(int i = 0; i <projectsaless.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ProjectSales::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProjectSales*> projectsaless =   QList<ProjectSales*>();
projectsaless = GetAll();
	for(int i = 0; i <projectsaless.count(); i++){
		list.append(qMakePair(projectsaless[i]->ProjectSalesID,QString::number(projectsaless[i]->ProjectID)));
	}
	return list;
}

QList<QPair< int,QString > > ProjectSales::GetPairList(QList<ProjectSales*> projectsaless) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projectsaless.count(); i++){
		list.append(qMakePair(projectsaless[i]->ProjectSalesID,QString::number(projectsaless[i]->ProjectID)));
	}
	return list;
}

int ProjectSales::GetIndex(QString name) {
	QList<ProjectSales*> projectsaless =   QList<ProjectSales*>();
projectsaless = GetAll();
	for(int i = 0; i <projectsaless.count(); i++){
		if(projectsaless[i]->ProjectID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ProjectSales*> ProjectSales::QuerySelect(QString select) {
QList<ProjectSales*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectSales WHERE "+select+"" ));
while (query.next()) {
list.append(new ProjectSales(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProjectSales::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProjectSales::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setProjectID(id, value.toString());
else if (index.column() == 2)
ok = setContactID(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProjectSales::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectSalesID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProjectSales::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProjectSales!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProjectSales::setProjectID(int ProjectSalesID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update ProjectSales set ProjectID = ? where ProjectSalesID = ?");
query.addBindValue(ProjectID);
query.addBindValue(ProjectSalesID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectSales::setContactID(int ProjectSalesID, const QString &ContactID) {
QSqlQuery query;
query.prepare("update ProjectSales set ContactID = ? where ProjectSalesID = ?");
query.addBindValue(ContactID);
query.addBindValue(ProjectSalesID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectSales::setCreatedOn(int ProjectSalesID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProjectSales set CreatedOn = ? where ProjectSalesID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectSalesID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectSales::setEditedOn(int ProjectSalesID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProjectSales set EditedOn = ? where ProjectSalesID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectSalesID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

