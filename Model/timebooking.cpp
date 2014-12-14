/**************************************************************************
**   File: timebooking.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "timebooking.h"
#include "erpmodel.h"

TimeBooking::TimeBooking()
 : QSqlRelationalTableModel(){

this->TimeBookingID = 0 ;
this->StartDate = "";
this->EndDate = "";
this->StartTime = "";
this->EndTime = "";
this->BreakTime = "";
this->OnlyTimeBooking = 0 ;
this->ProjectID = 0 ;
this->ServiceID = 0 ;
this->EmployeeID = 0 ;
this->Note = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("TimeBooking");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(7, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(8, QSqlRelation("Service", "ServiceID", "Name"));
this->setRelation(9, QSqlRelation("Employee", "EmployeeID", "Name"));
}
TimeBooking::TimeBooking(int TimeBookingID,QString StartDate,QString EndDate,QString StartTime,QString EndTime,QString BreakTime,bool OnlyTimeBooking,int ProjectID,int ServiceID,int EmployeeID,QString Note,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TimeBookingID = TimeBookingID ;
this->StartDate = StartDate ;
this->EndDate = EndDate ;
this->StartTime = StartTime ;
this->EndTime = EndTime ;
this->BreakTime = BreakTime ;
this->OnlyTimeBooking = OnlyTimeBooking ;
this->ProjectID = ProjectID ;
this->ServiceID = ServiceID ;
this->EmployeeID = EmployeeID ;
this->Note = Note ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

TimeBooking::TimeBooking(QString StartDate,QString EndDate,QString StartTime,QString EndTime,QString BreakTime,bool OnlyTimeBooking,int ProjectID,int ServiceID,int EmployeeID,QString Note,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->TimeBookingID = 0 ;
this->StartDate = StartDate ;
this->EndDate = EndDate ;
this->StartTime = StartTime ;
this->EndTime = EndTime ;
this->BreakTime = BreakTime ;
this->OnlyTimeBooking = OnlyTimeBooking ;
this->ProjectID = ProjectID ;
this->ServiceID = ServiceID ;
this->EmployeeID = EmployeeID ;
this->Note = Note ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool TimeBooking::Init()
{

QString table = "TimeBooking";
QString query =
"(TimeBookingID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (TimeBookingID),"
"StartDate VARCHAR(40) NOT NULL, "
" KEY(StartDate),"
"EndDate VARCHAR(40) NOT NULL, "
"StartTime VARCHAR(40) NOT NULL, "
"EndTime VARCHAR(40) NOT NULL, "
"BreakTime VARCHAR(40) NOT NULL, "
"OnlyTimeBooking VARCHAR(1) NOT NULL, "
"ProjectID INT NOT NULL, "
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"ServiceID INT NOT NULL, "
"FOREIGN KEY (ServiceID) REFERENCES Service(ServiceID)  ON DELETE CASCADE,"
"EmployeeID INT NOT NULL, "
"FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID)  ON DELETE CASCADE,"
"Note VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("TimeBookingID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("StartDate")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EndDate")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("StartTime")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EndTime")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("BreakTime")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("OnlyTimeBooking")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" INT"),QString("ServiceID")));variables.append(qMakePair(QString(" INT"),QString("EmployeeID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Note")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
TimeBooking* TimeBooking::p_instance = 0;
TimeBooking* TimeBooking::GetInstance() {
	if (p_instance == 0) {
		p_instance = new TimeBooking();
		TimeBooking::GetAll();
	}
return p_instance;
}
bool TimeBooking::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(TimeBookingID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO TimeBooking (StartDate,EndDate,StartTime,EndTime,BreakTime,OnlyTimeBooking,ProjectID,ServiceID,EmployeeID,Note,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->StartDate)+"','"+QString(this->EndDate)+"','"+QString(this->StartTime)+"','"+QString(this->EndTime)+"','"+QString(this->BreakTime)+"','"+QString::number(this->OnlyTimeBooking)+"','"+QString::number(this->ProjectID)+"','"+QString::number(this->ServiceID)+"','"+QString::number(this->EmployeeID)+"','"+QString(this->Note)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE TimeBooking SET "	"StartDate = '"+QString(this->StartDate)+"',"+"EndDate = '"+QString(this->EndDate)+"',"+"StartTime = '"+QString(this->StartTime)+"',"+"EndTime = '"+QString(this->EndTime)+"',"+"BreakTime = '"+QString(this->BreakTime)+"',"+"OnlyTimeBooking = '"+QString::number(this->OnlyTimeBooking)+"',"+"ProjectID = '"+QString::number(this->ProjectID)+"',"+"ServiceID = '"+QString::number(this->ServiceID)+"',"+"EmployeeID = '"+QString::number(this->EmployeeID)+"',"+"Note = '"+QString(this->Note)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE TimeBookingID ='"+QString::number(this->TimeBookingID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  TimeBookingID FROM TimeBooking WHERE StartDate = '"+StartDate+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->TimeBookingID = query.value(0).toInt();	
 } 
 }
return true;
}
bool TimeBooking::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool TimeBooking::remove() {
if(TimeBookingID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM TimeBooking WHERE TimeBookingID ="+QString::number(this->TimeBookingID)+""));
return true;
 }
return false;
}

TimeBooking* TimeBooking::get() {
if(TimeBookingID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM TimeBooking"
"WHERE TimeBookingID ='"+QString::number(this->TimeBookingID)+"'"));
while (query.next()) {
return new TimeBooking(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());
 }

}
return new TimeBooking();
 }

QList<TimeBooking*> TimeBooking::GetAll() {
	QList<TimeBooking*> timebookings =   QList<TimeBooking*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM TimeBooking ORDER BY TimeBookingID ASC"));
	while (query.next()) {
timebookings.append(new TimeBooking(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
	}
	return timebookings;
}

TimeBooking* TimeBooking::Get(int id) {
TimeBooking* timebooking = new TimeBooking();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM TimeBooking WHERE TimeBookingID = '"+QString::number(id)+"' ORDER BY TimeBookingID ASC "));
while (query.next()) {
timebooking = new TimeBooking(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());
 }

}
return timebooking;
}

TimeBooking* TimeBooking::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new TimeBooking();
}

TimeBooking* TimeBooking::Get(QString name) {
TimeBooking* timebooking = new TimeBooking();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM TimeBooking WHERE StartDate = '"+name+"'"));
while (query.next()) {
timebooking = new TimeBooking(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString());

 }

}
return timebooking;
 }

QList<TimeBooking*> TimeBooking::Search(QString keyword) {
QList<TimeBooking*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM TimeBooking"
"WHERE" 
"StartDate LIKE '%"+keyword+"%'"
"OR EndDate LIKE '%"+keyword+"%'"
"OR StartTime LIKE '%"+keyword+"%'"
"OR EndTime LIKE '%"+keyword+"%'"
"OR BreakTime LIKE '%"+keyword+"%'"
"OR Note LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new TimeBooking(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
 }

}
return list;
 }

QList<QString> TimeBooking::GetStringList() {
	QList<QString> list;
	QList<TimeBooking*> timebookings =   QList<TimeBooking*>();
timebookings = GetAll();
	for(int i = 0; i <timebookings.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > TimeBooking::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<TimeBooking*> timebookings =   QList<TimeBooking*>();
timebookings = GetAll();
	for(int i = 0; i <timebookings.count(); i++){
		list.append(qMakePair(timebookings[i]->TimeBookingID,timebookings[i]->StartDate));
	}
	return list;
}

QList<QPair< int,QString > > TimeBooking::GetPairList(QList<TimeBooking*> timebookings) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <timebookings.count(); i++){
		list.append(qMakePair(timebookings[i]->TimeBookingID,timebookings[i]->StartDate));
	}
	return list;
}

int TimeBooking::GetIndex(QString name) {
	QList<TimeBooking*> timebookings =   QList<TimeBooking*>();
timebookings = GetAll();
	for(int i = 0; i <timebookings.count(); i++){
		if(timebookings[i]->StartDate == name){
			return i;
		}
	}
	return 0;
}

QList<TimeBooking*> TimeBooking::QuerySelect(QString select) {
QList<TimeBooking*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM TimeBooking WHERE "+select+"" ));
while (query.next()) {
list.append(new TimeBooking(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toString(),query.value(11).toString(),query.value(12).toString()));
 }

}
return list;
 }

Qt::ItemFlags TimeBooking::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12)
flags |= Qt::ItemIsEditable;
return flags;
}

bool TimeBooking::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setStartDate(id, value.toString());
else if (index.column() == 2)
ok = setEndDate(id, value.toString());
else if (index.column() == 3)
ok = setStartTime(id, value.toString());
else if (index.column() == 4)
ok = setEndTime(id, value.toString());
else if (index.column() == 5)
ok = setBreakTime(id, value.toString());
else if (index.column() == 6)
ok = setOnlyTimeBooking(id, value.toString());
else if (index.column() == 7)
ok = setProjectID(id, value.toString());
else if (index.column() == 8)
ok = setServiceID(id, value.toString());
else if (index.column() == 9)
ok = setEmployeeID(id, value.toString());
else if (index.column() == 10)
ok = setNote(id, value.toString());
else if (index.column() == 11)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 12)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool TimeBooking::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->TimeBookingID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void TimeBooking::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() TimeBooking!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Start Date"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("End Date"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Start Time"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("End Time"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Break Time"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Only Time Booking"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Service"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Employee"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Note"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool TimeBooking::setStartDate(int TimeBookingID, const QString &StartDate) {
QSqlQuery query;
query.prepare("update TimeBooking set StartDate = ? where TimeBookingID = ?");
query.addBindValue(StartDate);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setEndDate(int TimeBookingID, const QString &EndDate) {
QSqlQuery query;
query.prepare("update TimeBooking set EndDate = ? where TimeBookingID = ?");
query.addBindValue(EndDate);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setStartTime(int TimeBookingID, const QString &StartTime) {
QSqlQuery query;
query.prepare("update TimeBooking set StartTime = ? where TimeBookingID = ?");
query.addBindValue(StartTime);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setEndTime(int TimeBookingID, const QString &EndTime) {
QSqlQuery query;
query.prepare("update TimeBooking set EndTime = ? where TimeBookingID = ?");
query.addBindValue(EndTime);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setBreakTime(int TimeBookingID, const QString &BreakTime) {
QSqlQuery query;
query.prepare("update TimeBooking set BreakTime = ? where TimeBookingID = ?");
query.addBindValue(BreakTime);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setOnlyTimeBooking(int TimeBookingID, const QString &OnlyTimeBooking) {
QSqlQuery query;
query.prepare("update TimeBooking set OnlyTimeBooking = ? where TimeBookingID = ?");
query.addBindValue(OnlyTimeBooking);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setProjectID(int TimeBookingID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update TimeBooking set ProjectID = ? where TimeBookingID = ?");
query.addBindValue(ProjectID);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setServiceID(int TimeBookingID, const QString &ServiceID) {
QSqlQuery query;
query.prepare("update TimeBooking set ServiceID = ? where TimeBookingID = ?");
query.addBindValue(ServiceID);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setEmployeeID(int TimeBookingID, const QString &EmployeeID) {
QSqlQuery query;
query.prepare("update TimeBooking set EmployeeID = ? where TimeBookingID = ?");
query.addBindValue(EmployeeID);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setNote(int TimeBookingID, const QString &Note) {
QSqlQuery query;
query.prepare("update TimeBooking set Note = ? where TimeBookingID = ?");
query.addBindValue(Note);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setCreatedOn(int TimeBookingID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update TimeBooking set CreatedOn = ? where TimeBookingID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool TimeBooking::setEditedOn(int TimeBookingID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update TimeBooking set EditedOn = ? where TimeBookingID = ?");
query.addBindValue(EditedOn);
query.addBindValue(TimeBookingID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

