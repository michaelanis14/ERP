/**************************************************************************
**   File: contact.cpp
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "contact.h"
#include "erpmodel.h"

Contact::Contact()
 : QSqlRelationalTableModel(){

this->ContactID = 0 ;
this->Salutation = "";
this->Name = "";
this->BirthdateOrDateOfFoundation = "";
this->ContactTypeID = 0 ;
this->ContactClassID = 0 ;
this->Number = 0 ;
this->Address = "";
this->PostalCode = "";
this->City = "";
this->CountryID = 0 ;
this->ContactStatusID = 0 ;
this->EmployeeID = 0 ;
this->Website = "";
this->TaxNumber = "";
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Contact");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(4, QSqlRelation("ContactType", "ContactTypeID", "Description"));
this->setRelation(5, QSqlRelation("ContactClass", "ContactClassID", "Description"));
this->setRelation(10, QSqlRelation("Country", "CountryID", "Name"));
this->setRelation(11, QSqlRelation("ContactStatus", "ContactStatusID", "Description"));
this->setRelation(12, QSqlRelation("Employee", "EmployeeID", "Name"));
}
Contact::Contact(int ContactID,QString Salutation,QString Name,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int Number,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,int EmployeeID,QString Website,QString TaxNumber,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactID = ContactID ;
this->Salutation = Salutation ;
this->Name = Name ;
this->BirthdateOrDateOfFoundation = BirthdateOrDateOfFoundation ;
this->ContactTypeID = ContactTypeID ;
this->ContactClassID = ContactClassID ;
this->Number = Number ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->ContactStatusID = ContactStatusID ;
this->EmployeeID = EmployeeID ;
this->Website = Website ;
this->TaxNumber = TaxNumber ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Contact::Contact(QString Salutation,QString Name,QString BirthdateOrDateOfFoundation,int ContactTypeID,int ContactClassID,int Number,QString Address,QString PostalCode,QString City,int CountryID,int ContactStatusID,int EmployeeID,QString Website,QString TaxNumber,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->ContactID = 0 ;
this->Salutation = Salutation ;
this->Name = Name ;
this->BirthdateOrDateOfFoundation = BirthdateOrDateOfFoundation ;
this->ContactTypeID = ContactTypeID ;
this->ContactClassID = ContactClassID ;
this->Number = Number ;
this->Address = Address ;
this->PostalCode = PostalCode ;
this->City = City ;
this->CountryID = CountryID ;
this->ContactStatusID = ContactStatusID ;
this->EmployeeID = EmployeeID ;
this->Website = Website ;
this->TaxNumber = TaxNumber ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Contact::Init()
{

QString table = "Contact";
QString query =
"(ContactID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (ContactID),"
"Salutation VARCHAR(40) NOT NULL, "
"Name VARCHAR(40) NOT NULL, "
"BirthdateOrDateOfFoundation VARCHAR(40) NOT NULL, "
"ContactTypeID INT NOT NULL, "
"FOREIGN KEY (ContactTypeID) REFERENCES ContactType(ContactTypeID)  ON DELETE CASCADE,"
"ContactClassID INT NOT NULL, "
"FOREIGN KEY (ContactClassID) REFERENCES ContactClass(ContactClassID)  ON DELETE CASCADE,"
"Number INT NOT NULL, "
"Address VARCHAR(40) NOT NULL, "
"PostalCode VARCHAR(40) NOT NULL, "
"City VARCHAR(40) NOT NULL, "
"CountryID INT NOT NULL, "
"FOREIGN KEY (CountryID) REFERENCES Country(CountryID)  ON DELETE CASCADE,"
"ContactStatusID INT NOT NULL, "
"FOREIGN KEY (ContactStatusID) REFERENCES ContactStatus(ContactStatusID)  ON DELETE CASCADE,"
"EmployeeID INT NOT NULL, "
"FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID)  ON DELETE CASCADE,"
"Website VARCHAR(40) NOT NULL, "
"TaxNumber VARCHAR(40) NOT NULL, "
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL)" ;

ErpModel::GetInstance()->createTable(table,query);
return true;
}
Contact* Contact::p_instance = 0;
Contact* Contact::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Contact();
		Contact::GetAll();
	}
return p_instance;
}
bool Contact::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(ContactID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Contact (Salutation,Name,BirthdateOrDateOfFoundation,ContactTypeID,ContactClassID,Number,Address,PostalCode,City,CountryID,ContactStatusID,EmployeeID,Website,TaxNumber,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Salutation)+"','"+QString(this->Name)+"','"+QString(this->BirthdateOrDateOfFoundation)+"','"+QString::number(this->ContactTypeID)+"','"+QString::number(this->ContactClassID)+"','"+QString::number(this->Number)+"','"+QString(this->Address)+"','"+QString(this->PostalCode)+"','"+QString(this->City)+"','"+QString::number(this->CountryID)+"','"+QString::number(this->ContactStatusID)+"','"+QString::number(this->EmployeeID)+"','"+QString(this->Website)+"','"+QString(this->TaxNumber)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Contact SET "	"Salutation = '"+QString(this->Salutation)+"',"+"Name = '"+QString(this->Name)+"',"+"BirthdateOrDateOfFoundation = '"+QString(this->BirthdateOrDateOfFoundation)+"',"+"ContactTypeID = '"+QString::number(this->ContactTypeID)+"',"+"ContactClassID = '"+QString::number(this->ContactClassID)+"',"+"Number = '"+QString::number(this->Number)+"',"+"Address = '"+QString(this->Address)+"',"+"PostalCode = '"+QString(this->PostalCode)+"',"+"City = '"+QString(this->City)+"',"+"CountryID = '"+QString::number(this->CountryID)+"',"+"ContactStatusID = '"+QString::number(this->ContactStatusID)+"',"+"EmployeeID = '"+QString::number(this->EmployeeID)+"',"+"Website = '"+QString(this->Website)+"',"+"TaxNumber = '"+QString(this->TaxNumber)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE ContactID ='"+QString::number(this->ContactID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  ContactID FROM Contact WHERE Name = '"+Name+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->ContactID = query.value(0).toInt();	
 } 
 }
return true;
}

bool Contact::remove() {
if(ContactID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Contact WHERE ContactID ="+QString::number(this->ContactID)+""));
return true;
 }
return false;
}

Contact* Contact::get() {
if(ContactID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Contact"
"WHERE ContactID ='"+QString::number(this->ContactID)+"'"));
while (query.next()) {
return new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString());
 }

}
return new Contact();
 }

QList<Contact*> Contact::GetAll() {
	QList<Contact*> contacts =   QList<Contact*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"));
	while (query.next()) {
contacts.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString()));
	}
qSort(contacts);
	return contacts;
}

Contact* Contact::Get(int id) {
Contact* contact = new Contact();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Contact WHERE ContactID = '"+QString::number(id)+"'"));
while (query.next()) {
contact = new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString());
 }
contact->contacttelephones = ContactTelephone::QuerySelect("ContactID = " + QString::number(id));
contact->contactemails = ContactEmail::QuerySelect("ContactID = " + QString::number(id));
contact->bankaccounts = BankAccount::QuerySelect("ContactID = " + QString::number(id));
contact->contactfielddatas = ContactFieldData::QuerySelect("ContactID = " + QString::number(id));

}
return contact;
}

Contact* Contact::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Contact();
}

Contact* Contact::Get(QString name) {
Contact* contact = new Contact();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact WHERE Name = '"+name+"'"));
while (query.next()) {
contact = new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString());

 }
contact->contacttelephones = ContactTelephone::QuerySelect("ContactID = " +QString::number(contact->ContactID));
contact->contactemails = ContactEmail::QuerySelect("ContactID = " +QString::number(contact->ContactID));
contact->bankaccounts = BankAccount::QuerySelect("ContactID = " +QString::number(contact->ContactID));
contact->contactfielddatas = ContactFieldData::QuerySelect("ContactID = " +QString::number(contact->ContactID));

}
return contact;
 }

QList<Contact*> Contact::Search(QString keyword) {
QList<Contact*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact"
"WHERE" 
"Salutation LIKE '%"+keyword+"%'"
"OR Name LIKE '%"+keyword+"%'"
"OR BirthdateOrDateOfFoundation LIKE '%"+keyword+"%'"
"OR Address LIKE '%"+keyword+"%'"
"OR PostalCode LIKE '%"+keyword+"%'"
"OR City LIKE '%"+keyword+"%'"
"OR Website LIKE '%"+keyword+"%'"
"OR TaxNumber LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString()));
 }

}
return list;
 }

QList<QString> Contact::GetStringList() {
	QList<QString> list;
	QList<Contact*> contacts =   QList<Contact*>();
contacts = GetAll();
	for(int i = 0; i <contacts.count(); i++){
		list.append(contacts[i]->Name);
	}
	qSort(list);
	return list;
}

QHash<int,QString> Contact::GetHashList() {
	QHash<int,QString> list;
	QList<Contact*> contacts =   QList<Contact*>();
contacts = GetAll();
	for(int i = 0; i <contacts.count(); i++){
		list.insert(contacts[i]->ContactID,contacts[i]->Name);
	}
	return list;
}

int Contact::GetIndex(QString name) {
	QList<Contact*> contacts =   QList<Contact*>();
contacts = GetAll();
	for(int i = 0; i <contacts.count(); i++){
		if(contacts[i]->Name == name){
			return i;
		}
	}
	return 0;
}

QList<Contact*> Contact::QuerySelect(QString select) {
QList<Contact*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Contact WHERE "+select+"" ));
while (query.next()) {
list.append(new Contact(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toString(),query.value(8).toString(),query.value(9).toString(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString(),query.value(16).toString()));
 }

}
return list;
 }

Qt::ItemFlags Contact::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 14 || index.column() == 19 || index.column() == 20)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Contact::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setSalutation(id, value.toString());
else if (index.column() == 2)
ok = setName(id, value.toString());
else if (index.column() == 3)
ok = setBirthdateOrDateOfFoundation(id, value.toString());
else if (index.column() == 4)
ok = setContactTypeID(id, value.toString());
else if (index.column() == 5)
ok = setContactClassID(id, value.toString());
else if (index.column() == 6)
ok = setNumber(id, value.toString());
else if (index.column() == 7)
ok = setAddress(id, value.toString());
else if (index.column() == 8)
ok = setPostalCode(id, value.toString());
else if (index.column() == 9)
ok = setCity(id, value.toString());
else if (index.column() == 10)
ok = setCountryID(id, value.toString());
else if (index.column() == 11)
ok = setContactStatusID(id, value.toString());
else if (index.column() == 12)
ok = setEmployeeID(id, value.toString());
else if (index.column() == 13)
ok = setWebsite(id, value.toString());
else if (index.column() == 14)
ok = setTaxNumber(id, value.toString());
else if (index.column() == 19)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 20)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Contact::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->ContactID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Contact::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Contact!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Salutation"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Name"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Birthdate Or Date Of Foundation"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Contact Type"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Contact Class"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Number"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Address"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Postal Code"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("City"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Country"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Contact Status"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Employee"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Website"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Tax Number"));
this->setHeaderData(19, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(20, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Contact::setSalutation(int ContactID, const QString &Salutation) {
QSqlQuery query;
query.prepare("update Contact set Salutation = ? where ContactID = ?");
query.addBindValue(Salutation);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setName(int ContactID, const QString &Name) {
QSqlQuery query;
query.prepare("update Contact set Name = ? where ContactID = ?");
query.addBindValue(Name);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setBirthdateOrDateOfFoundation(int ContactID, const QString &BirthdateOrDateOfFoundation) {
QSqlQuery query;
query.prepare("update Contact set BirthdateOrDateOfFoundation = ? where ContactID = ?");
query.addBindValue(BirthdateOrDateOfFoundation);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setContactTypeID(int ContactID, const QString &ContactTypeID) {
QSqlQuery query;
query.prepare("update Contact set ContactTypeID = ? where ContactID = ?");
query.addBindValue(ContactTypeID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setContactClassID(int ContactID, const QString &ContactClassID) {
QSqlQuery query;
query.prepare("update Contact set ContactClassID = ? where ContactID = ?");
query.addBindValue(ContactClassID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setNumber(int ContactID, const QString &Number) {
QSqlQuery query;
query.prepare("update Contact set Number = ? where ContactID = ?");
query.addBindValue(Number);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setAddress(int ContactID, const QString &Address) {
QSqlQuery query;
query.prepare("update Contact set Address = ? where ContactID = ?");
query.addBindValue(Address);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setPostalCode(int ContactID, const QString &PostalCode) {
QSqlQuery query;
query.prepare("update Contact set PostalCode = ? where ContactID = ?");
query.addBindValue(PostalCode);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setCity(int ContactID, const QString &City) {
QSqlQuery query;
query.prepare("update Contact set City = ? where ContactID = ?");
query.addBindValue(City);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setCountryID(int ContactID, const QString &CountryID) {
QSqlQuery query;
query.prepare("update Contact set CountryID = ? where ContactID = ?");
query.addBindValue(CountryID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setContactStatusID(int ContactID, const QString &ContactStatusID) {
QSqlQuery query;
query.prepare("update Contact set ContactStatusID = ? where ContactID = ?");
query.addBindValue(ContactStatusID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setEmployeeID(int ContactID, const QString &EmployeeID) {
QSqlQuery query;
query.prepare("update Contact set EmployeeID = ? where ContactID = ?");
query.addBindValue(EmployeeID);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setWebsite(int ContactID, const QString &Website) {
QSqlQuery query;
query.prepare("update Contact set Website = ? where ContactID = ?");
query.addBindValue(Website);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setTaxNumber(int ContactID, const QString &TaxNumber) {
QSqlQuery query;
query.prepare("update Contact set TaxNumber = ? where ContactID = ?");
query.addBindValue(TaxNumber);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setCreatedOn(int ContactID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Contact set CreatedOn = ? where ContactID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Contact::setEditedOn(int ContactID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Contact set EditedOn = ? where ContactID = ?");
query.addBindValue(EditedOn);
query.addBindValue(ContactID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

