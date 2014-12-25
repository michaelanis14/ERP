/**************************************************************************
**   File: task.cpp
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "task.h"
#include "erpmodel.h"

Task::Task()
 : QSqlRelationalTableModel(){

this->TaskID = 0 ;
this->Note = "";
this->ProjectID = 0 ;
this->ContactPersonID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Task");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(2, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(3, QSqlRelation("ContactPerson", "ContactPersonID", "Title"));
this->setRelation(3, QSqlRelation("ContactPerson", "ContactPersonID", "TitleName"));
}
Task::Task(int TaskID,QString Note,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TaskID = TaskID ;
this->Note = Note ;
this->ProjectID = ProjectID ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Task::Task(QString Note,int ProjectID,int ContactPersonID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TaskID = 0 ;
this->Note = Note ;
this->ProjectID = ProjectID ;
this->ContactPersonID = ContactPersonID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Task::Init()
{

QString table = "Task";
QString query =
"(TaskID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (TaskID),"
"Note VARCHAR(40) NOT NULL, "
" KEY(Note),"
"ProjectID INT NOT NULL, "
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"ContactPersonID INT NOT NULL, "
"FOREIGN KEY (ContactPersonID) REFERENCES ContactPerson(ContactPersonID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("TaskID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Note")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" INT"),QString("ContactPersonID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Task* Task::p_instance = 0;
Task* Task::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Task();
		Task::GetAll();
	}
return p_instance;
}
bool Task::save() {
this->EditedOn = QDate::currentDate().toString();
if(TaskID== 0) {
this->CreatedOn = QDate::currentDate().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Task (Note,ProjectID,ContactPersonID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Note)+"','"+QString::number(this->ProjectID)+"','"+QString::number(this->ContactPersonID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Task SET "	"Note = '"+QString(this->Note)+"',"+"ProjectID = '"+QString::number(this->ProjectID)+"',"+"ContactPersonID = '"+QString::number(this->ContactPersonID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE TaskID ='"+QString::number(this->TaskID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  TaskID FROM Task WHERE Note = '"+Note+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->TaskID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Task::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Task::remove() {
if(TaskID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Task WHERE TaskID ="+QString::number(this->TaskID)+""));
return true;
 }
return false;
}

Task* Task::get() {
if(TaskID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Task"
"WHERE TaskID ='"+QString::number(this->TaskID)+"'"));
while (query.next()) {
return new Task(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return new Task();
 }

QList<Task*> Task::GetAll() {
	QList<Task*> tasks =   QList<Task*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Task ORDER BY TaskID ASC"));
	while (query.next()) {
tasks.append(new Task(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
	}
	return tasks;
}

Task* Task::Get(int id) {
Task* task = new Task();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Task WHERE TaskID = '"+QString::number(id)+"' ORDER BY TaskID ASC "));
while (query.next()) {
task = new Task(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());
 }

}
return task;
}

Task* Task::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Task();
}

Task* Task::Get(QString name) {
Task* task = new Task();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Task WHERE Note = '"+name+"'"));
while (query.next()) {
task = new Task(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString());

 }

}
return task;
 }

QList<Task*> Task::Search(QString keyword) {
QList<Task*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Task"
"WHERE" 
"Note LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Task(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

QList<QString> Task::GetStringList() {
	QList<QString> list;
	QList<Task*> tasks =   QList<Task*>();
tasks = GetAll();
	for(int i = 0; i <tasks.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > Task::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Task*> tasks =   QList<Task*>();
tasks = GetAll();
	for(int i = 0; i <tasks.count(); i++){
		list.append(qMakePair(tasks[i]->TaskID,tasks[i]->Note));
	}
	return list;
}

QList<QPair< int,QString > > Task::GetPairList(QList<Task*> tasks) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <tasks.count(); i++){
		list.append(qMakePair(tasks[i]->TaskID,tasks[i]->Note));
	}
	return list;
}

int Task::GetIndex(QString name) {
	QList<Task*> tasks =   QList<Task*>();
tasks = GetAll();
	for(int i = 0; i <tasks.count(); i++){
		if(tasks[i]->Note == name){
			return i;
		}
	}
	return 0;
}

QList<Task*> Task::QuerySelect(QString select) {
QList<Task*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Task WHERE "+select+"" ));
while (query.next()) {
list.append(new Task(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toString(),query.value(5).toString()));
 }

}
return list;
 }

Qt::ItemFlags Task::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Task::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setNote(id, value.toString());
else if (index.column() == 2)
ok = setProjectID(id, value.toString());
else if (index.column() == 3)
ok = setContactPersonID(id, value.toString());
else if (index.column() == 4)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 5)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Task::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->TaskID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Task::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Task!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Note"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact Person"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Task::setNote(int TaskID, const QString &Note) {
QSqlQuery query;
query.prepare("update Task set Note = ? where TaskID = ?");
query.addBindValue(Note);
query.addBindValue(TaskID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Task::setProjectID(int TaskID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update Task set ProjectID = ? where TaskID = ?");
query.addBindValue(ProjectID);
query.addBindValue(TaskID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Task::setContactPersonID(int TaskID, const QString &ContactPersonID) {
QSqlQuery query;
query.prepare("update Task set ContactPersonID = ? where TaskID = ?");
query.addBindValue(ContactPersonID);
query.addBindValue(TaskID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Task::setCreatedOn(int TaskID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Task set CreatedOn = ? where TaskID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(TaskID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Task::setEditedOn(int TaskID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Task set EditedOn = ? where TaskID = ?");
query.addBindValue(EditedOn);
query.addBindValue(TaskID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

