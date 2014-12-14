/**************************************************************************
**   File: projectproduct.cpp
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "projectproduct.h"
#include "erpmodel.h"

ProjectProduct::ProjectProduct()
 : QSqlRelationalTableModel(){

this->ProjectProductID = 0 ;
this->ProjectID = 0 ;
this->ProductID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("ProjectProduct");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(1, QSqlRelation("Project", "ProjectID", "Title"));
this->setRelation(2, QSqlRelation("Product", "ProductID", "Name"));
}
ProjectProduct::ProjectProduct(int ProjectProductID,int ProjectID,int ProductID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectProductID = ProjectProductID ;
this->ProjectID = ProjectID ;
this->ProductID = ProductID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

ProjectProduct::ProjectProduct(int ProjectID,int ProductID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ProjectProductID = 0 ;
this->ProjectID = ProjectID ;
this->ProductID = ProductID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool ProjectProduct::Init()
{

QString table = "ProjectProduct";
QString query =
"(ProjectProductID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ProjectProductID),"
"ProjectID INT NOT NULL, "
" KEY(ProjectID),"
"FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID)  ON DELETE CASCADE,"
"ProductID INT NOT NULL, "
"FOREIGN KEY (ProductID) REFERENCES Product(ProductID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("ProjectProductID")));variables.append(qMakePair(QString(" INT"),QString("ProjectID")));variables.append(qMakePair(QString(" INT"),QString("ProductID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
ProjectProduct* ProjectProduct::p_instance = 0;
ProjectProduct* ProjectProduct::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ProjectProduct();
		ProjectProduct::GetAll();
	}
return p_instance;
}
bool ProjectProduct::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ProjectProductID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO ProjectProduct (ProjectID,ProductID,CreatedOn,EditedOn)"
"VALUES ('" +QString::number(this->ProjectID)+"','"+QString::number(this->ProductID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE ProjectProduct SET "	"ProjectID = '"+QString::number(this->ProjectID)+"',"+"ProductID = '"+QString::number(this->ProductID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ProjectProductID ='"+QString::number(this->ProjectProductID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ProjectProductID FROM ProjectProduct WHERE ProjectID = "+QString::number(ProjectID)+" AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ProjectProductID = query.value(0).toInt();	
 } 
 }
return true;
}
bool ProjectProduct::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool ProjectProduct::remove() {
if(ProjectProductID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM ProjectProduct WHERE ProjectProductID ="+QString::number(this->ProjectProductID)+""));
return true;
 }
return false;
}

ProjectProduct* ProjectProduct::get() {
if(ProjectProductID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectProduct"
"WHERE ProjectProductID ='"+QString::number(this->ProjectProductID)+"'"));
while (query.next()) {
return new ProjectProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return new ProjectProduct();
 }

QList<ProjectProduct*> ProjectProduct::GetAll() {
	QList<ProjectProduct*> projectproducts =   QList<ProjectProduct*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectProduct ORDER BY ProjectProductID ASC"));
	while (query.next()) {
projectproducts.append(new ProjectProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
	}
	return projectproducts;
}

ProjectProduct* ProjectProduct::Get(int id) {
ProjectProduct* projectproduct = new ProjectProduct();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM ProjectProduct WHERE ProjectProductID = '"+QString::number(id)+"' ORDER BY ProjectProductID ASC "));
while (query.next()) {
projectproduct = new ProjectProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());
 }

}
return projectproduct;
}

ProjectProduct* ProjectProduct::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new ProjectProduct();
}

ProjectProduct* ProjectProduct::Get(QString name) {
ProjectProduct* projectproduct = new ProjectProduct();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectProduct WHERE ProjectID = QString::number("+name+")"));
while (query.next()) {
projectproduct = new ProjectProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString());

 }

}
return projectproduct;
 }

QList<ProjectProduct*> ProjectProduct::Search(QString keyword) {
QList<ProjectProduct*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectProduct"
"WHERE" 
"CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new ProjectProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

QList<QString> ProjectProduct::GetStringList() {
	QList<QString> list;
	QList<ProjectProduct*> projectproducts =   QList<ProjectProduct*>();
projectproducts = GetAll();
	for(int i = 0; i <projectproducts.count(); i++){
	}
	return list;
}

QList<QPair< int,QString > > ProjectProduct::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<ProjectProduct*> projectproducts =   QList<ProjectProduct*>();
projectproducts = GetAll();
	for(int i = 0; i <projectproducts.count(); i++){
		list.append(qMakePair(projectproducts[i]->ProjectProductID,QString::number(projectproducts[i]->ProjectID)));
	}
	return list;
}

QList<QPair< int,QString > > ProjectProduct::GetPairList(QList<ProjectProduct*> projectproducts) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <projectproducts.count(); i++){
		list.append(qMakePair(projectproducts[i]->ProjectProductID,QString::number(projectproducts[i]->ProjectID)));
	}
	return list;
}

int ProjectProduct::GetIndex(QString name) {
	QList<ProjectProduct*> projectproducts =   QList<ProjectProduct*>();
projectproducts = GetAll();
	for(int i = 0; i <projectproducts.count(); i++){
		if(projectproducts[i]->ProjectID == name.toInt()){
			return i;
		}
	}
	return 0;
}

QList<ProjectProduct*> ProjectProduct::QuerySelect(QString select) {
QList<ProjectProduct*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM ProjectProduct WHERE "+select+"" ));
while (query.next()) {
list.append(new ProjectProduct(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString()));
 }

}
return list;
 }

Qt::ItemFlags ProjectProduct::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4)
flags |= Qt::ItemIsEditable;
return flags;
}

bool ProjectProduct::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setProjectID(id, value.toString());
else if (index.column() == 2)
ok = setProductID(id, value.toString());
else if (index.column() == 3)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 4)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool ProjectProduct::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ProjectProductID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void ProjectProduct::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() ProjectProduct!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool ProjectProduct::setProjectID(int ProjectProductID, const QString &ProjectID) {
QSqlQuery query;
query.prepare("update ProjectProduct set ProjectID = ? where ProjectProductID = ?");
query.addBindValue(ProjectID);
query.addBindValue(ProjectProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectProduct::setProductID(int ProjectProductID, const QString &ProductID) {
QSqlQuery query;
query.prepare("update ProjectProduct set ProductID = ? where ProjectProductID = ?");
query.addBindValue(ProductID);
query.addBindValue(ProjectProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectProduct::setCreatedOn(int ProjectProductID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update ProjectProduct set CreatedOn = ? where ProjectProductID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ProjectProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool ProjectProduct::setEditedOn(int ProjectProductID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update ProjectProduct set EditedOn = ? where ProjectProductID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ProjectProductID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

