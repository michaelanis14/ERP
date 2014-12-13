/**************************************************************************
**   File: projectcontactpersonvariables.cpp
**   Created on: Wed Dec 10 20:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "projectcontactpersonvariables.h"
#include "erpmodel.h"

projectcontactpersonvariables::projectcontactpersonvariables()
 : QSqlRelationalTableModel(){

this->ProjectContactPersonID = 0 ;
this->ProjectID = 0 ;
this->ContactPersonID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("projectcontactpersonvariables");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(2, QSqlRelation("ContactPerson", "ContactPersonID", "Title"));
this->setRelation(2, QSqlRelation("ContactPerson", "ContactPersonID", "TitleName"));
}
projectcontactpersonvariables::projectcontactpersonvariables(int ProjectContactPersonID,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectContactPersonID = ProjectContactPersonID ;
this->ProjectID = ProjectID ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

projectcontactpersonvariables::projectcontactpersonvariables(int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectContactPersonID = 0 ;
this->ProjectID = ProjectID ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool projectcontactpersonvariables::Init()
{

QString table = "projectcontactpersonvariables";
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

ErpModel::GetInstance()->createTable(table,query);
return true;
}
projectcontactpersonvariables* projectcontactpersonvariables::p_instance = 0;
projectcontactpersonvariables* projectcontactpersonvariables::GetInstance() {
	if (p_instance == 0) {
		p_instance = new projectcontactpersonvariables();
		projectcontactpersonvariables::GetAll();
	}
return p_instance;
}
bool projectcontactpersonvariables::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProjectContactPersonID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO projectcontactpersonvariables (ProjectID,ContactPersonID,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ProjectID)+"','"+QString::number(this->ContactPersonID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE projectcontactpersonvariables SET "	"ProjectID = '"+QString::number(this->ProjectID)+"',"+"ContactPersonID = '"+QString::number(this->ContactPersonID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectContactPersonID ='"+QString::number(this->ProjectContactPersonID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectContactPersonID FROM projectcontactpersonvariables WHERE ProjectID = "+QString::number(ProjectID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectContactPersonID = query.value(0).toInt();	
 } 
 }
return true;
}
bool projectcontactpersonvariables::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool projectcontactpersonvariables::remove() {
if(ProjectContactPersonID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM projectcontactpersonvariables WHERE ProjectContactPersonID ="+QString::number(this->ProjectContactPersonID)+""));
return true;
 }
return false;
}

projectcontactpersonvariables* projectcontactpersonvariables::get() {
if(ProjectContactPersonID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM projectcontactpersonvariables"
"WHERE ProjectContactPersonID ='"+QString::number(this->ProjectContactPersonID)+"'"));
while (query.next()) {
return new projectcontactpersonvariables(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new projectcontactpersonvariables();
 }

QList<projectcontactpersonvariables*> projectcontactpersonvariables::GetAll() {
	QList<projectcontactpersonvariables*> projectcontactpersonvariabless =   QList<projectcontactpersonvariables*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM projectcontactpersonvariables ORDER BY ProjectContactPersonID ASC"));
	while (query.next()) {
projectcontactpersonvariabless.append(new projectcontactpersonvariables(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return projectcontactpersonvariabless;
}

projectcontactpersonvariables* projectcontactpersonvariables::Get(int id) {
projectcontactpersonvariables* projectcontactpersonvariables = new projectcontactpersonvariables();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM projectcontactpersonvariables WHERE ProjectContactPersonID = '"+QString::number(id)+"' ORDER BY ProjectContactPersonID ASC "));
while (query.next()) {
projectcontactpersonvariables = new projectcontactpersonvariables(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return projectcontactpersonvariables;
}

projectcontactpersonvariables* projectcontactpersonvariables::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new projectcontactpersonvariables();
}

projectcontactpersonvariables* projectcontactpersonvariables::Get(QString name) {
projectcontactpersonvariables* projectcontactpersonvariables = new projectcontactpersonvariables();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM projectcontactpersonvariables WHERE ProjectID = QString::number("+name+")"));
while (query.next()) {
projectcontactpersonvariables = new projectcontactpersonvariables(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return projectcontactpersonvariables;
 }

QList<projectcontactpersonvariables*> projectcontactpersonvariables::Search(QString keyword) {
QList<projectcontactpersonvariables*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM projectcontactpersonvariables"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new projectcontactpersonvariables(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> projectcontactpersonvariables::GetStringList() {
	QList<QString> list;
	QList<projectcontactpersonvariables*> projectcontactpersonvariabless =   QList<projectcontactpersonvariables*>();
projectcontactpersonvariabless = GetAll();
	for(int i = 0; i <projectcontactpersonvariabless.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > projectcontactpersonvariables::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<projectcontactpersonvariables*> projectcontactpersonvariabless =   QList<projectcontactpersonvariables*>();
projectcontactpersonvariabless = GetAll();
	for(int i = 0; i <projectcontactpersonvariabless.count(); i++){
		list.append(qMakePair(projectcontactpersonvariabless[i]->ProjectContactPersonID,QString::number(projectcontactpersonvariabless[i]->ProjectID)));
	}
	return list;
}

QList<QPair< int,QString > > projectcontactpersonvariables::GetPairList(QList<projectcontactpersonvariables*> projectcontactpersonvariabless) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projectcontactpersonvariabless.count(); i++){
		list.append(qMakePair(projectcontactpersonvariabless[i]->ProjectContactPersonID,QString::number(projectcontactpersonvariabless[i]->ProjectID)));
	}
	return list;
}

int projectcontactpersonvariables::GetIndex(QString name) {
	QList<projectcontactpersonvariables*> projectcontactpersonvariabless =   QList<projectcontactpersonvariables*>();
projectcontactpersonvariabless = GetAll();
	for(int i = 0; i <projectcontactpersonvariabless.count(); i++){
		if(projectcontactpersonvariabless[i]->ProjectID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<projectcontactpersonvariables*> projectcontactpersonvariables::QuerySelect(QString select) {
QList<projectcontactpersonvariables*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM projectcontactpersonvariables WHERE "+select+"" ));
while (query.next()) {
list.append(new projectcontactpersonvariables(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags projectcontactpersonvariables::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool projectcontactpersonvariables::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
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

bool projectcontactpersonvariables::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectContactPersonID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void projectcontactpersonvariables::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() projectcontactpersonvariables!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Contact Person"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool projectcontactpersonvariables::setProjectID(int ProjectContactPersonID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update projectcontactpersonvariables set ProjectID = ? where ProjectContactPersonID = ?");
query.addBindValue(ProjectID);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool projectcontactpersonvariables::setContactPersonID(int ProjectContactPersonID, const QString &ContactPersonID) {
QSqlQuery query;
query.prepare("update projectcontactpersonvariables set ContactPersonID = ? where ProjectContactPersonID = ?");
query.addBindValue(ContactPersonID);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool projectcontactpersonvariables::setCreatedOn(int ProjectContactPersonID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update projectcontactpersonvariables set CreatedOn = ? where ProjectContactPersonID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool projectcontactpersonvariables::setEditedOn(int ProjectContactPersonID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update projectcontactpersonvariables set EditedOn = ? where ProjectContactPersonID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectContactPersonID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

