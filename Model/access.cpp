/**************************************************************************
**   File: access.cpp
**   Created on: Sun Dec 14 22:39:13 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "access.h"
#include "erpmodel.h"

Access::Access()
 : QSqlRelationalTableModel(){

this->AccessID = 0 ;
this->Title = "";
this->Company = 0 ;
this->Tax = 0 ;
this->Contact = 0 ;
this->ContactTelephone = 0 ;
this->ContactEmail = 0 ;
this->BankAccount = 0 ;
this->ContactClass = 0 ;
this->ContactType = 0 ;
this->Country = 0 ;
this->Currency = 0 ;
this->ContactStatus = 0 ;
this->FieldType = 0 ;
this->ContactField = 0 ;
this->ContactFieldData = 0 ;
this->ContactPersonField = 0 ;
this->ContactPersonFieldData = 0 ;
this->ContactPerson = 0 ;
this->ContactPersonTelephone = 0 ;
this->ContactPersonEmail = 0 ;
this->ProjectStatus = 0 ;
this->Project = 0 ;
this->ProjectFile = 0 ;
this->ProjectContactPerson = 0 ;
this->ProjectProduct = 0 ;
this->ProjectService = 0 ;
this->ProjectSales = 0 ;
this->Unit = 0 ;
this->ProductCategory = 0 ;
this->ProductImage = 0 ;
this->Product = 0 ;
this->ProductField = 0 ;
this->ProductFieldData = 0 ;
this->Service = 0 ;
this->Store = 0 ;
this->PurchaseStatus = 0 ;
this->PurchaseSerial = 0 ;
this->Purchase = 0 ;
this->PurchaseStoreProduct = 0 ;
this->PurchaseFreeLine = 0 ;
this->DeliveryOrderStatus = 0 ;
this->DeliveryOrder = 0 ;
this->DeliveryOrderStoreProduct = 0 ;
this->DeliveryOrderService = 0 ;
this->DeliveryOrderFreeline = 0 ;
this->InvoicePeriod = 0 ;
this->InvoiceYear = 0 ;
this->InvoiceState = 0 ;
this->InvoiceSerial = 0 ;
this->Invoice = 0 ;
this->InvoiceStateD = 0 ;
this->InvoiceFreeline = 0 ;
this->PaymentType = 0 ;
this->Payment = 0 ;
this->Task = 0 ;
this->Language = 0 ;
this->TimeBooking = 0 ;
this->hashKey = "";
this->UserID = 0 ;
this->CreatedOn = "";
this->EditedOn = "";
this->setTable("Access");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(59, QSqlRelation("User", "UserID", "Name"));
}
Access::Access(int AccessID,QString Title,bool Company,bool Tax,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool ProjectSales,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateD,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool Language,bool TimeBooking,QString hashKey,int UserID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->AccessID = AccessID ;
this->Title = Title ;
this->Company = Company ;
this->Tax = Tax ;
this->Contact = Contact ;
this->ContactTelephone = ContactTelephone ;
this->ContactEmail = ContactEmail ;
this->BankAccount = BankAccount ;
this->ContactClass = ContactClass ;
this->ContactType = ContactType ;
this->Country = Country ;
this->Currency = Currency ;
this->ContactStatus = ContactStatus ;
this->FieldType = FieldType ;
this->ContactField = ContactField ;
this->ContactFieldData = ContactFieldData ;
this->ContactPersonField = ContactPersonField ;
this->ContactPersonFieldData = ContactPersonFieldData ;
this->ContactPerson = ContactPerson ;
this->ContactPersonTelephone = ContactPersonTelephone ;
this->ContactPersonEmail = ContactPersonEmail ;
this->ProjectStatus = ProjectStatus ;
this->Project = Project ;
this->ProjectFile = ProjectFile ;
this->ProjectContactPerson = ProjectContactPerson ;
this->ProjectProduct = ProjectProduct ;
this->ProjectService = ProjectService ;
this->ProjectSales = ProjectSales ;
this->Unit = Unit ;
this->ProductCategory = ProductCategory ;
this->ProductImage = ProductImage ;
this->Product = Product ;
this->ProductField = ProductField ;
this->ProductFieldData = ProductFieldData ;
this->Service = Service ;
this->Store = Store ;
this->PurchaseStatus = PurchaseStatus ;
this->PurchaseSerial = PurchaseSerial ;
this->Purchase = Purchase ;
this->PurchaseStoreProduct = PurchaseStoreProduct ;
this->PurchaseFreeLine = PurchaseFreeLine ;
this->DeliveryOrderStatus = DeliveryOrderStatus ;
this->DeliveryOrder = DeliveryOrder ;
this->DeliveryOrderStoreProduct = DeliveryOrderStoreProduct ;
this->DeliveryOrderService = DeliveryOrderService ;
this->DeliveryOrderFreeline = DeliveryOrderFreeline ;
this->InvoicePeriod = InvoicePeriod ;
this->InvoiceYear = InvoiceYear ;
this->InvoiceState = InvoiceState ;
this->InvoiceSerial = InvoiceSerial ;
this->Invoice = Invoice ;
this->InvoiceStateD = InvoiceStateD ;
this->InvoiceFreeline = InvoiceFreeline ;
this->PaymentType = PaymentType ;
this->Payment = Payment ;
this->Task = Task ;
this->Language = Language ;
this->TimeBooking = TimeBooking ;
this->hashKey = hashKey ;
this->UserID = UserID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

Access::Access(QString Title,bool Company,bool Tax,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool ProjectSales,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateD,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool Language,bool TimeBooking,QString hashKey,int UserID,QString CreatedOn,QString EditedOn) : QSqlRelationalTableModel(){
this->AccessID = 0 ;
this->Title = Title ;
this->Company = Company ;
this->Tax = Tax ;
this->Contact = Contact ;
this->ContactTelephone = ContactTelephone ;
this->ContactEmail = ContactEmail ;
this->BankAccount = BankAccount ;
this->ContactClass = ContactClass ;
this->ContactType = ContactType ;
this->Country = Country ;
this->Currency = Currency ;
this->ContactStatus = ContactStatus ;
this->FieldType = FieldType ;
this->ContactField = ContactField ;
this->ContactFieldData = ContactFieldData ;
this->ContactPersonField = ContactPersonField ;
this->ContactPersonFieldData = ContactPersonFieldData ;
this->ContactPerson = ContactPerson ;
this->ContactPersonTelephone = ContactPersonTelephone ;
this->ContactPersonEmail = ContactPersonEmail ;
this->ProjectStatus = ProjectStatus ;
this->Project = Project ;
this->ProjectFile = ProjectFile ;
this->ProjectContactPerson = ProjectContactPerson ;
this->ProjectProduct = ProjectProduct ;
this->ProjectService = ProjectService ;
this->ProjectSales = ProjectSales ;
this->Unit = Unit ;
this->ProductCategory = ProductCategory ;
this->ProductImage = ProductImage ;
this->Product = Product ;
this->ProductField = ProductField ;
this->ProductFieldData = ProductFieldData ;
this->Service = Service ;
this->Store = Store ;
this->PurchaseStatus = PurchaseStatus ;
this->PurchaseSerial = PurchaseSerial ;
this->Purchase = Purchase ;
this->PurchaseStoreProduct = PurchaseStoreProduct ;
this->PurchaseFreeLine = PurchaseFreeLine ;
this->DeliveryOrderStatus = DeliveryOrderStatus ;
this->DeliveryOrder = DeliveryOrder ;
this->DeliveryOrderStoreProduct = DeliveryOrderStoreProduct ;
this->DeliveryOrderService = DeliveryOrderService ;
this->DeliveryOrderFreeline = DeliveryOrderFreeline ;
this->InvoicePeriod = InvoicePeriod ;
this->InvoiceYear = InvoiceYear ;
this->InvoiceState = InvoiceState ;
this->InvoiceSerial = InvoiceSerial ;
this->Invoice = Invoice ;
this->InvoiceStateD = InvoiceStateD ;
this->InvoiceFreeline = InvoiceFreeline ;
this->PaymentType = PaymentType ;
this->Payment = Payment ;
this->Task = Task ;
this->Language = Language ;
this->TimeBooking = TimeBooking ;
this->hashKey = hashKey ;
this->UserID = UserID ;
this->CreatedOn = CreatedOn ;
this->EditedOn = EditedOn ;
}

bool Access::Init()
{

QString table = "Access";
QString query =
"(AccessID INT NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (AccessID),"
"Title VARCHAR(40) NOT NULL, "
" KEY(Title),"
"Company VARCHAR(1) NOT NULL, "
"Tax VARCHAR(1) NOT NULL, "
"Contact VARCHAR(1) NOT NULL, "
"ContactTelephone VARCHAR(1) NOT NULL, "
"ContactEmail VARCHAR(1) NOT NULL, "
"BankAccount VARCHAR(1) NOT NULL, "
"ContactClass VARCHAR(1) NOT NULL, "
"ContactType VARCHAR(1) NOT NULL, "
"Country VARCHAR(1) NOT NULL, "
"Currency VARCHAR(1) NOT NULL, "
"ContactStatus VARCHAR(1) NOT NULL, "
"FieldType VARCHAR(1) NOT NULL, "
"ContactField VARCHAR(1) NOT NULL, "
"ContactFieldData VARCHAR(1) NOT NULL, "
"ContactPersonField VARCHAR(1) NOT NULL, "
"ContactPersonFieldData VARCHAR(1) NOT NULL, "
"ContactPerson VARCHAR(1) NOT NULL, "
"ContactPersonTelephone VARCHAR(1) NOT NULL, "
"ContactPersonEmail VARCHAR(1) NOT NULL, "
"ProjectStatus VARCHAR(1) NOT NULL, "
"Project VARCHAR(1) NOT NULL, "
"ProjectFile VARCHAR(1) NOT NULL, "
"ProjectContactPerson VARCHAR(1) NOT NULL, "
"ProjectProduct VARCHAR(1) NOT NULL, "
"ProjectService VARCHAR(1) NOT NULL, "
"ProjectSales VARCHAR(1) NOT NULL, "
"Unit VARCHAR(1) NOT NULL, "
"ProductCategory VARCHAR(1) NOT NULL, "
"ProductImage VARCHAR(1) NOT NULL, "
"Product VARCHAR(1) NOT NULL, "
"ProductField VARCHAR(1) NOT NULL, "
"ProductFieldData VARCHAR(1) NOT NULL, "
"Service VARCHAR(1) NOT NULL, "
"Store VARCHAR(1) NOT NULL, "
"PurchaseStatus VARCHAR(1) NOT NULL, "
"PurchaseSerial VARCHAR(1) NOT NULL, "
"Purchase VARCHAR(1) NOT NULL, "
"PurchaseStoreProduct VARCHAR(1) NOT NULL, "
"PurchaseFreeLine VARCHAR(1) NOT NULL, "
"DeliveryOrderStatus VARCHAR(1) NOT NULL, "
"DeliveryOrder VARCHAR(1) NOT NULL, "
"DeliveryOrderStoreProduct VARCHAR(1) NOT NULL, "
"DeliveryOrderService VARCHAR(1) NOT NULL, "
"DeliveryOrderFreeline VARCHAR(1) NOT NULL, "
"InvoicePeriod VARCHAR(1) NOT NULL, "
"InvoiceYear VARCHAR(1) NOT NULL, "
"InvoiceState VARCHAR(1) NOT NULL, "
"InvoiceSerial VARCHAR(1) NOT NULL, "
"Invoice VARCHAR(1) NOT NULL, "
"InvoiceStateD VARCHAR(1) NOT NULL, "
"InvoiceFreeline VARCHAR(1) NOT NULL, "
"PaymentType VARCHAR(1) NOT NULL, "
"Payment VARCHAR(1) NOT NULL, "
"Task VARCHAR(1) NOT NULL, "
"Language VARCHAR(1) NOT NULL, "
"TimeBooking VARCHAR(1) NOT NULL, "
"hashKey VARCHAR(40) NOT NULL, "
"UserID INT NOT NULL, "
"FOREIGN KEY (UserID) REFERENCES User(UserID)  ON DELETE CASCADE,"
"CreatedOn VARCHAR(40) NOT NULL, "
"EditedOn VARCHAR(40) NOT NULL, KEY(EditedOn) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" INT"),QString("AccessID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Title")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Company")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Tax")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Contact")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactTelephone")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactEmail")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("BankAccount")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactClass")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactType")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Country")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Currency")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("FieldType")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactField")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactFieldData")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonField")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonFieldData")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPerson")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonTelephone")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonEmail")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Project")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectFile")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectContactPerson")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectProduct")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectService")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectSales")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Unit")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductCategory")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductImage")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Product")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductField")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductFieldData")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Service")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Store")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseSerial")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Purchase")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseStoreProduct")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseFreeLine")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrder")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderStoreProduct")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderService")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderFreeline")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoicePeriod")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceYear")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceState")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceSerial")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Invoice")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceStateD")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceFreeline")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PaymentType")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Payment")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Task")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Language")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("TimeBooking")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("hashKey")));variables.append(qMakePair(QString(" INT"),QString("UserID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedOn")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedOn")));ErpModel::GetInstance()->createTable(table,query,variables);
return true;
}
Access* Access::p_instance = 0;
Access* Access::GetInstance() {
	if (p_instance == 0) {
		p_instance = new Access();
		Access::GetAll();
	}
return p_instance;
}
bool Access::save() {
this->EditedOn = QDateTime::currentDateTime().toString();
if(AccessID== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Access (Title,Company,Tax,Contact,ContactTelephone,ContactEmail,BankAccount,ContactClass,ContactType,Country,Currency,ContactStatus,FieldType,ContactField,ContactFieldData,ContactPersonField,ContactPersonFieldData,ContactPerson,ContactPersonTelephone,ContactPersonEmail,ProjectStatus,Project,ProjectFile,ProjectContactPerson,ProjectProduct,ProjectService,ProjectSales,Unit,ProductCategory,ProductImage,Product,ProductField,ProductFieldData,Service,Store,PurchaseStatus,PurchaseSerial,Purchase,PurchaseStoreProduct,PurchaseFreeLine,DeliveryOrderStatus,DeliveryOrder,DeliveryOrderStoreProduct,DeliveryOrderService,DeliveryOrderFreeline,InvoicePeriod,InvoiceYear,InvoiceState,InvoiceSerial,Invoice,InvoiceStateD,InvoiceFreeline,PaymentType,Payment,Task,Language,TimeBooking,hashKey,UserID,CreatedOn,EditedOn)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->Company)+"','"+QString::number(this->Tax)+"','"+QString::number(this->Contact)+"','"+QString::number(this->ContactTelephone)+"','"+QString::number(this->ContactEmail)+"','"+QString::number(this->BankAccount)+"','"+QString::number(this->ContactClass)+"','"+QString::number(this->ContactType)+"','"+QString::number(this->Country)+"','"+QString::number(this->Currency)+"','"+QString::number(this->ContactStatus)+"','"+QString::number(this->FieldType)+"','"+QString::number(this->ContactField)+"','"+QString::number(this->ContactFieldData)+"','"+QString::number(this->ContactPersonField)+"','"+QString::number(this->ContactPersonFieldData)+"','"+QString::number(this->ContactPerson)+"','"+QString::number(this->ContactPersonTelephone)+"','"+QString::number(this->ContactPersonEmail)+"','"+QString::number(this->ProjectStatus)+"','"+QString::number(this->Project)+"','"+QString::number(this->ProjectFile)+"','"+QString::number(this->ProjectContactPerson)+"','"+QString::number(this->ProjectProduct)+"','"+QString::number(this->ProjectService)+"','"+QString::number(this->ProjectSales)+"','"+QString::number(this->Unit)+"','"+QString::number(this->ProductCategory)+"','"+QString::number(this->ProductImage)+"','"+QString::number(this->Product)+"','"+QString::number(this->ProductField)+"','"+QString::number(this->ProductFieldData)+"','"+QString::number(this->Service)+"','"+QString::number(this->Store)+"','"+QString::number(this->PurchaseStatus)+"','"+QString::number(this->PurchaseSerial)+"','"+QString::number(this->Purchase)+"','"+QString::number(this->PurchaseStoreProduct)+"','"+QString::number(this->PurchaseFreeLine)+"','"+QString::number(this->DeliveryOrderStatus)+"','"+QString::number(this->DeliveryOrder)+"','"+QString::number(this->DeliveryOrderStoreProduct)+"','"+QString::number(this->DeliveryOrderService)+"','"+QString::number(this->DeliveryOrderFreeline)+"','"+QString::number(this->InvoicePeriod)+"','"+QString::number(this->InvoiceYear)+"','"+QString::number(this->InvoiceState)+"','"+QString::number(this->InvoiceSerial)+"','"+QString::number(this->Invoice)+"','"+QString::number(this->InvoiceStateD)+"','"+QString::number(this->InvoiceFreeline)+"','"+QString::number(this->PaymentType)+"','"+QString::number(this->Payment)+"','"+QString::number(this->Task)+"','"+QString::number(this->Language)+"','"+QString::number(this->TimeBooking)+"','"+QString(this->hashKey)+"','"+QString::number(this->UserID)+"','"+QString(this->CreatedOn)+"','"+QString(this->EditedOn)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Access SET "	"Title = '"+QString(this->Title)+"',"+"Company = '"+QString::number(this->Company)+"',"+"Tax = '"+QString::number(this->Tax)+"',"+"Contact = '"+QString::number(this->Contact)+"',"+"ContactTelephone = '"+QString::number(this->ContactTelephone)+"',"+"ContactEmail = '"+QString::number(this->ContactEmail)+"',"+"BankAccount = '"+QString::number(this->BankAccount)+"',"+"ContactClass = '"+QString::number(this->ContactClass)+"',"+"ContactType = '"+QString::number(this->ContactType)+"',"+"Country = '"+QString::number(this->Country)+"',"+"Currency = '"+QString::number(this->Currency)+"',"+"ContactStatus = '"+QString::number(this->ContactStatus)+"',"+"FieldType = '"+QString::number(this->FieldType)+"',"+"ContactField = '"+QString::number(this->ContactField)+"',"+"ContactFieldData = '"+QString::number(this->ContactFieldData)+"',"+"ContactPersonField = '"+QString::number(this->ContactPersonField)+"',"+"ContactPersonFieldData = '"+QString::number(this->ContactPersonFieldData)+"',"+"ContactPerson = '"+QString::number(this->ContactPerson)+"',"+"ContactPersonTelephone = '"+QString::number(this->ContactPersonTelephone)+"',"+"ContactPersonEmail = '"+QString::number(this->ContactPersonEmail)+"',"+"ProjectStatus = '"+QString::number(this->ProjectStatus)+"',"+"Project = '"+QString::number(this->Project)+"',"+"ProjectFile = '"+QString::number(this->ProjectFile)+"',"+"ProjectContactPerson = '"+QString::number(this->ProjectContactPerson)+"',"+"ProjectProduct = '"+QString::number(this->ProjectProduct)+"',"+"ProjectService = '"+QString::number(this->ProjectService)+"',"+"ProjectSales = '"+QString::number(this->ProjectSales)+"',"+"Unit = '"+QString::number(this->Unit)+"',"+"ProductCategory = '"+QString::number(this->ProductCategory)+"',"+"ProductImage = '"+QString::number(this->ProductImage)+"',"+"Product = '"+QString::number(this->Product)+"',"+"ProductField = '"+QString::number(this->ProductField)+"',"+"ProductFieldData = '"+QString::number(this->ProductFieldData)+"',"+"Service = '"+QString::number(this->Service)+"',"+"Store = '"+QString::number(this->Store)+"',"+"PurchaseStatus = '"+QString::number(this->PurchaseStatus)+"',"+"PurchaseSerial = '"+QString::number(this->PurchaseSerial)+"',"+"Purchase = '"+QString::number(this->Purchase)+"',"+"PurchaseStoreProduct = '"+QString::number(this->PurchaseStoreProduct)+"',"+"PurchaseFreeLine = '"+QString::number(this->PurchaseFreeLine)+"',"+"DeliveryOrderStatus = '"+QString::number(this->DeliveryOrderStatus)+"',"+"DeliveryOrder = '"+QString::number(this->DeliveryOrder)+"',"+"DeliveryOrderStoreProduct = '"+QString::number(this->DeliveryOrderStoreProduct)+"',"+"DeliveryOrderService = '"+QString::number(this->DeliveryOrderService)+"',"+"DeliveryOrderFreeline = '"+QString::number(this->DeliveryOrderFreeline)+"',"+"InvoicePeriod = '"+QString::number(this->InvoicePeriod)+"',"+"InvoiceYear = '"+QString::number(this->InvoiceYear)+"',"+"InvoiceState = '"+QString::number(this->InvoiceState)+"',"+"InvoiceSerial = '"+QString::number(this->InvoiceSerial)+"',"+"Invoice = '"+QString::number(this->Invoice)+"',"+"InvoiceStateD = '"+QString::number(this->InvoiceStateD)+"',"+"InvoiceFreeline = '"+QString::number(this->InvoiceFreeline)+"',"+"PaymentType = '"+QString::number(this->PaymentType)+"',"+"Payment = '"+QString::number(this->Payment)+"',"+"Task = '"+QString::number(this->Task)+"',"+"Language = '"+QString::number(this->Language)+"',"+"TimeBooking = '"+QString::number(this->TimeBooking)+"',"+"hashKey = '"+QString(this->hashKey)+"',"+"UserID = '"+QString::number(this->UserID)+"',"+"CreatedOn = '"+QString(this->CreatedOn)+"',"+"EditedOn = '"+QString(this->EditedOn)+"' WHERE AccessID ='"+QString::number(this->AccessID)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  AccessID FROM Access WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->AccessID = query.value(0).toInt();	
 } 
 }
return true;
}
bool Access::save(QSqlRecord &record) {
	if(ErpModel::GetInstance()->db.open()) 
 if(this->insertRowIntoTable(record)) 
 return true; 
 return false;
}

bool Access::remove() {
if(AccessID!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Access WHERE AccessID ="+QString::number(this->AccessID)+""));
return true;
 }
return false;
}

Access* Access::get() {
if(AccessID!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Access"
"WHERE AccessID ='"+QString::number(this->AccessID)+"'"));
while (query.next()) {
return new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toInt(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toInt(),query.value(60).toString(),query.value(61).toString());
 }

}
return new Access();
 }

QList<Access*> Access::GetAll() {
	QList<Access*> accesss =   QList<Access*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Access ORDER BY AccessID ASC"));
	while (query.next()) {
accesss.append(new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toInt(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toInt(),query.value(60).toString(),query.value(61).toString()));
	}
	return accesss;
}

Access* Access::Get(int id) {
Access* access = new Access();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Access WHERE AccessID = '"+QString::number(id)+"' ORDER BY AccessID ASC "));
while (query.next()) {
access = new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toInt(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toInt(),query.value(60).toString(),query.value(61).toString());
 }

}
return access;
}

Access* Access::get(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0); 
 if(data(primaryKeyIndex).toInt() != 0) 
 return Get(data(primaryKeyIndex).toInt());
else return new Access();
}

Access* Access::Get(QString name) {
Access* access = new Access();
if(name != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Access WHERE Title = '"+name+"'"));
while (query.next()) {
access = new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toInt(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toInt(),query.value(60).toString(),query.value(61).toString());

 }

}
return access;
 }

QList<Access*> Access::Search(QString keyword) {
QList<Access*>list;
if(keyword != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Access"
"WHERE" 
"Title LIKE '%"+keyword+"%'"
"OR hashKey LIKE '%"+keyword+"%'"
"OR CreatedOn LIKE '%"+keyword+"%'"
"OR EditedOn LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toInt(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toInt(),query.value(60).toString(),query.value(61).toString()));
 }

}
return list;
 }

QList<QString> Access::GetStringList() {
	QList<QString> list;
	QList<Access*> accesss =   QList<Access*>();
accesss = GetAll();
	for(int i = 0; i <accesss.count(); i++){
		list.append(accesss[i]->Title);
	}
	return list;
}

QList<QPair< int,QString > > Access::GetPairList() {
	QList<QPair<int,QString > > list;
	QList<Access*> accesss =   QList<Access*>();
accesss = GetAll();
	for(int i = 0; i <accesss.count(); i++){
		list.append(qMakePair(accesss[i]->AccessID,accesss[i]->Title));
	}
	return list;
}

QList<QPair< int,QString > > Access::GetPairList(QList<Access*> accesss) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <accesss.count(); i++){
		list.append(qMakePair(accesss[i]->AccessID,accesss[i]->Title));
	}
	return list;
}

int Access::GetIndex(QString name) {
	QList<Access*> accesss =   QList<Access*>();
accesss = GetAll();
	for(int i = 0; i <accesss.count(); i++){
		if(accesss[i]->Title == name){
			return i;
		}
	}
	return 0;
}

QList<Access*> Access::QuerySelect(QString select) {
QList<Access*>list;
if(select != NULL) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Access WHERE "+select+"" ));
while (query.next()) {
list.append(new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toInt(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toInt(),query.value(60).toString(),query.value(61).toString()));
 }

}
return list;
 }

Qt::ItemFlags Access::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 14 || index.column() == 15 || index.column() == 16 || index.column() == 17 || index.column() == 18 || index.column() == 19 || index.column() == 20 || index.column() == 21 || index.column() == 22 || index.column() == 23 || index.column() == 24 || index.column() == 25 || index.column() == 26 || index.column() == 27 || index.column() == 28 || index.column() == 29 || index.column() == 30 || index.column() == 31 || index.column() == 32 || index.column() == 33 || index.column() == 34 || index.column() == 35 || index.column() == 36 || index.column() == 37 || index.column() == 38 || index.column() == 39 || index.column() == 40 || index.column() == 41 || index.column() == 42 || index.column() == 43 || index.column() == 44 || index.column() == 45 || index.column() == 46 || index.column() == 47 || index.column() == 48 || index.column() == 49 || index.column() == 50 || index.column() == 51 || index.column() == 52 || index.column() == 53 || index.column() == 54 || index.column() == 55 || index.column() == 56 || index.column() == 57 || index.column() == 58 || index.column() == 59 || index.column() == 60 || index.column() == 61)
flags |= Qt::ItemIsEditable;
return flags;
}

bool Access::setData(const QModelIndex &index, const QVariant &value, int /* role */) {
	if (index.column() < 1)
		return false;
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();
bool ok = true;
if((data(QSqlRelationalTableModel::index(index.row(), index.column())).toString() != value.toString().toLower())){
if (index.column() == 1)
ok = setTitle(id, value.toString());
else if (index.column() == 2)
ok = setCompany(id, value.toString());
else if (index.column() == 3)
ok = setTax(id, value.toString());
else if (index.column() == 4)
ok = setContact(id, value.toString());
else if (index.column() == 5)
ok = setContactTelephone(id, value.toString());
else if (index.column() == 6)
ok = setContactEmail(id, value.toString());
else if (index.column() == 7)
ok = setBankAccount(id, value.toString());
else if (index.column() == 8)
ok = setContactClass(id, value.toString());
else if (index.column() == 9)
ok = setContactType(id, value.toString());
else if (index.column() == 10)
ok = setCountry(id, value.toString());
else if (index.column() == 11)
ok = setCurrency(id, value.toString());
else if (index.column() == 12)
ok = setContactStatus(id, value.toString());
else if (index.column() == 13)
ok = setFieldType(id, value.toString());
else if (index.column() == 14)
ok = setContactField(id, value.toString());
else if (index.column() == 15)
ok = setContactFieldData(id, value.toString());
else if (index.column() == 16)
ok = setContactPersonField(id, value.toString());
else if (index.column() == 17)
ok = setContactPersonFieldData(id, value.toString());
else if (index.column() == 18)
ok = setContactPerson(id, value.toString());
else if (index.column() == 19)
ok = setContactPersonTelephone(id, value.toString());
else if (index.column() == 20)
ok = setContactPersonEmail(id, value.toString());
else if (index.column() == 21)
ok = setProjectStatus(id, value.toString());
else if (index.column() == 22)
ok = setProject(id, value.toString());
else if (index.column() == 23)
ok = setProjectFile(id, value.toString());
else if (index.column() == 24)
ok = setProjectContactPerson(id, value.toString());
else if (index.column() == 25)
ok = setProjectProduct(id, value.toString());
else if (index.column() == 26)
ok = setProjectService(id, value.toString());
else if (index.column() == 27)
ok = setProjectSales(id, value.toString());
else if (index.column() == 28)
ok = setUnit(id, value.toString());
else if (index.column() == 29)
ok = setProductCategory(id, value.toString());
else if (index.column() == 30)
ok = setProductImage(id, value.toString());
else if (index.column() == 31)
ok = setProduct(id, value.toString());
else if (index.column() == 32)
ok = setProductField(id, value.toString());
else if (index.column() == 33)
ok = setProductFieldData(id, value.toString());
else if (index.column() == 34)
ok = setService(id, value.toString());
else if (index.column() == 35)
ok = setStore(id, value.toString());
else if (index.column() == 36)
ok = setPurchaseStatus(id, value.toString());
else if (index.column() == 37)
ok = setPurchaseSerial(id, value.toString());
else if (index.column() == 38)
ok = setPurchase(id, value.toString());
else if (index.column() == 39)
ok = setPurchaseStoreProduct(id, value.toString());
else if (index.column() == 40)
ok = setPurchaseFreeLine(id, value.toString());
else if (index.column() == 41)
ok = setDeliveryOrderStatus(id, value.toString());
else if (index.column() == 42)
ok = setDeliveryOrder(id, value.toString());
else if (index.column() == 43)
ok = setDeliveryOrderStoreProduct(id, value.toString());
else if (index.column() == 44)
ok = setDeliveryOrderService(id, value.toString());
else if (index.column() == 45)
ok = setDeliveryOrderFreeline(id, value.toString());
else if (index.column() == 46)
ok = setInvoicePeriod(id, value.toString());
else if (index.column() == 47)
ok = setInvoiceYear(id, value.toString());
else if (index.column() == 48)
ok = setInvoiceState(id, value.toString());
else if (index.column() == 49)
ok = setInvoiceSerial(id, value.toString());
else if (index.column() == 50)
ok = setInvoice(id, value.toString());
else if (index.column() == 51)
ok = setInvoiceStateD(id, value.toString());
else if (index.column() == 52)
ok = setInvoiceFreeline(id, value.toString());
else if (index.column() == 53)
ok = setPaymentType(id, value.toString());
else if (index.column() == 54)
ok = setPayment(id, value.toString());
else if (index.column() == 55)
ok = setTask(id, value.toString());
else if (index.column() == 56)
ok = setLanguage(id, value.toString());
else if (index.column() == 57)
ok = setTimeBooking(id, value.toString());
else if (index.column() == 58)
ok = sethashKey(id, value.toString());
else if (index.column() == 59)
ok = setUserID(id, value.toString());
else if (index.column() == 60)
ok = setCreatedOn(id, value.toString());
else if (index.column() == 61)
ok = setEditedOn(id, value.toString());
refresh();
}
return ok;
}

bool Access::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->AccessID = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Access::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Access!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Company"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Tax"));
this->setHeaderData(4, Qt::Horizontal, QObject::tr("Contact"));
this->setHeaderData(5, Qt::Horizontal, QObject::tr("Contact Telephone"));
this->setHeaderData(6, Qt::Horizontal, QObject::tr("Contact Email"));
this->setHeaderData(7, Qt::Horizontal, QObject::tr("Bank Account"));
this->setHeaderData(8, Qt::Horizontal, QObject::tr("Contact Class"));
this->setHeaderData(9, Qt::Horizontal, QObject::tr("Contact Type"));
this->setHeaderData(10, Qt::Horizontal, QObject::tr("Country"));
this->setHeaderData(11, Qt::Horizontal, QObject::tr("Currency"));
this->setHeaderData(12, Qt::Horizontal, QObject::tr("Contact Status"));
this->setHeaderData(13, Qt::Horizontal, QObject::tr("Field Type"));
this->setHeaderData(14, Qt::Horizontal, QObject::tr("Contact Field"));
this->setHeaderData(15, Qt::Horizontal, QObject::tr("Contact Field Data"));
this->setHeaderData(16, Qt::Horizontal, QObject::tr("Contact Person Field"));
this->setHeaderData(17, Qt::Horizontal, QObject::tr("Contact Person Field Data"));
this->setHeaderData(18, Qt::Horizontal, QObject::tr("Contact Person"));
this->setHeaderData(19, Qt::Horizontal, QObject::tr("Contact Person Telephone"));
this->setHeaderData(20, Qt::Horizontal, QObject::tr("Contact Person Email"));
this->setHeaderData(21, Qt::Horizontal, QObject::tr("Project Status"));
this->setHeaderData(22, Qt::Horizontal, QObject::tr("Project"));
this->setHeaderData(23, Qt::Horizontal, QObject::tr("Project File"));
this->setHeaderData(24, Qt::Horizontal, QObject::tr("Project Contact Person"));
this->setHeaderData(25, Qt::Horizontal, QObject::tr("Project Product"));
this->setHeaderData(26, Qt::Horizontal, QObject::tr("Project Service"));
this->setHeaderData(27, Qt::Horizontal, QObject::tr("Project Sales"));
this->setHeaderData(28, Qt::Horizontal, QObject::tr("Unit"));
this->setHeaderData(29, Qt::Horizontal, QObject::tr("Product Category"));
this->setHeaderData(30, Qt::Horizontal, QObject::tr("Product Image"));
this->setHeaderData(31, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(32, Qt::Horizontal, QObject::tr("Product Field"));
this->setHeaderData(33, Qt::Horizontal, QObject::tr("Product Field Data"));
this->setHeaderData(34, Qt::Horizontal, QObject::tr("Service"));
this->setHeaderData(35, Qt::Horizontal, QObject::tr("Store"));
this->setHeaderData(36, Qt::Horizontal, QObject::tr("Purchase Status"));
this->setHeaderData(37, Qt::Horizontal, QObject::tr("Purchase Serial"));
this->setHeaderData(38, Qt::Horizontal, QObject::tr("Purchase"));
this->setHeaderData(39, Qt::Horizontal, QObject::tr("Purchase Store Product"));
this->setHeaderData(40, Qt::Horizontal, QObject::tr("Purchase Free Line"));
this->setHeaderData(41, Qt::Horizontal, QObject::tr("Delivery Order Status"));
this->setHeaderData(42, Qt::Horizontal, QObject::tr("Delivery Order"));
this->setHeaderData(43, Qt::Horizontal, QObject::tr("Delivery Order Store Product"));
this->setHeaderData(44, Qt::Horizontal, QObject::tr("Delivery Order Service"));
this->setHeaderData(45, Qt::Horizontal, QObject::tr("Delivery Order Freeline"));
this->setHeaderData(46, Qt::Horizontal, QObject::tr("Invoice Period"));
this->setHeaderData(47, Qt::Horizontal, QObject::tr("Invoice Year"));
this->setHeaderData(48, Qt::Horizontal, QObject::tr("Invoice State"));
this->setHeaderData(49, Qt::Horizontal, QObject::tr("Invoice Serial"));
this->setHeaderData(50, Qt::Horizontal, QObject::tr("Invoice"));
this->setHeaderData(51, Qt::Horizontal, QObject::tr("Invoice State D"));
this->setHeaderData(52, Qt::Horizontal, QObject::tr("Invoice Freeline"));
this->setHeaderData(53, Qt::Horizontal, QObject::tr("Payment Type"));
this->setHeaderData(54, Qt::Horizontal, QObject::tr("Payment"));
this->setHeaderData(55, Qt::Horizontal, QObject::tr("Task"));
this->setHeaderData(56, Qt::Horizontal, QObject::tr("Language"));
this->setHeaderData(57, Qt::Horizontal, QObject::tr("Time Booking"));
this->setHeaderData(58, Qt::Horizontal, QObject::tr("hashKey"));
this->setHeaderData(59, Qt::Horizontal, QObject::tr("User"));
this->setHeaderData(60, Qt::Horizontal, QObject::tr("Created On"));
this->setHeaderData(61, Qt::Horizontal, QObject::tr("Edited On"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Access::setTitle(int AccessID, const QString &Title) {
QSqlQuery query;
query.prepare("update Access set Title = ? where AccessID = ?");
query.addBindValue(Title);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setCompany(int AccessID, const QString &Company) {
QSqlQuery query;
query.prepare("update Access set Company = ? where AccessID = ?");
query.addBindValue(Company);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setTax(int AccessID, const QString &Tax) {
QSqlQuery query;
query.prepare("update Access set Tax = ? where AccessID = ?");
query.addBindValue(Tax);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContact(int AccessID, const QString &Contact) {
QSqlQuery query;
query.prepare("update Access set Contact = ? where AccessID = ?");
query.addBindValue(Contact);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactTelephone(int AccessID, const QString &ContactTelephone) {
QSqlQuery query;
query.prepare("update Access set ContactTelephone = ? where AccessID = ?");
query.addBindValue(ContactTelephone);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactEmail(int AccessID, const QString &ContactEmail) {
QSqlQuery query;
query.prepare("update Access set ContactEmail = ? where AccessID = ?");
query.addBindValue(ContactEmail);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setBankAccount(int AccessID, const QString &BankAccount) {
QSqlQuery query;
query.prepare("update Access set BankAccount = ? where AccessID = ?");
query.addBindValue(BankAccount);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactClass(int AccessID, const QString &ContactClass) {
QSqlQuery query;
query.prepare("update Access set ContactClass = ? where AccessID = ?");
query.addBindValue(ContactClass);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactType(int AccessID, const QString &ContactType) {
QSqlQuery query;
query.prepare("update Access set ContactType = ? where AccessID = ?");
query.addBindValue(ContactType);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setCountry(int AccessID, const QString &Country) {
QSqlQuery query;
query.prepare("update Access set Country = ? where AccessID = ?");
query.addBindValue(Country);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setCurrency(int AccessID, const QString &Currency) {
QSqlQuery query;
query.prepare("update Access set Currency = ? where AccessID = ?");
query.addBindValue(Currency);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactStatus(int AccessID, const QString &ContactStatus) {
QSqlQuery query;
query.prepare("update Access set ContactStatus = ? where AccessID = ?");
query.addBindValue(ContactStatus);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setFieldType(int AccessID, const QString &FieldType) {
QSqlQuery query;
query.prepare("update Access set FieldType = ? where AccessID = ?");
query.addBindValue(FieldType);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactField(int AccessID, const QString &ContactField) {
QSqlQuery query;
query.prepare("update Access set ContactField = ? where AccessID = ?");
query.addBindValue(ContactField);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactFieldData(int AccessID, const QString &ContactFieldData) {
QSqlQuery query;
query.prepare("update Access set ContactFieldData = ? where AccessID = ?");
query.addBindValue(ContactFieldData);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonField(int AccessID, const QString &ContactPersonField) {
QSqlQuery query;
query.prepare("update Access set ContactPersonField = ? where AccessID = ?");
query.addBindValue(ContactPersonField);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonFieldData(int AccessID, const QString &ContactPersonFieldData) {
QSqlQuery query;
query.prepare("update Access set ContactPersonFieldData = ? where AccessID = ?");
query.addBindValue(ContactPersonFieldData);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPerson(int AccessID, const QString &ContactPerson) {
QSqlQuery query;
query.prepare("update Access set ContactPerson = ? where AccessID = ?");
query.addBindValue(ContactPerson);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonTelephone(int AccessID, const QString &ContactPersonTelephone) {
QSqlQuery query;
query.prepare("update Access set ContactPersonTelephone = ? where AccessID = ?");
query.addBindValue(ContactPersonTelephone);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonEmail(int AccessID, const QString &ContactPersonEmail) {
QSqlQuery query;
query.prepare("update Access set ContactPersonEmail = ? where AccessID = ?");
query.addBindValue(ContactPersonEmail);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectStatus(int AccessID, const QString &ProjectStatus) {
QSqlQuery query;
query.prepare("update Access set ProjectStatus = ? where AccessID = ?");
query.addBindValue(ProjectStatus);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProject(int AccessID, const QString &Project) {
QSqlQuery query;
query.prepare("update Access set Project = ? where AccessID = ?");
query.addBindValue(Project);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectFile(int AccessID, const QString &ProjectFile) {
QSqlQuery query;
query.prepare("update Access set ProjectFile = ? where AccessID = ?");
query.addBindValue(ProjectFile);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectContactPerson(int AccessID, const QString &ProjectContactPerson) {
QSqlQuery query;
query.prepare("update Access set ProjectContactPerson = ? where AccessID = ?");
query.addBindValue(ProjectContactPerson);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectProduct(int AccessID, const QString &ProjectProduct) {
QSqlQuery query;
query.prepare("update Access set ProjectProduct = ? where AccessID = ?");
query.addBindValue(ProjectProduct);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectService(int AccessID, const QString &ProjectService) {
QSqlQuery query;
query.prepare("update Access set ProjectService = ? where AccessID = ?");
query.addBindValue(ProjectService);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectSales(int AccessID, const QString &ProjectSales) {
QSqlQuery query;
query.prepare("update Access set ProjectSales = ? where AccessID = ?");
query.addBindValue(ProjectSales);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setUnit(int AccessID, const QString &Unit) {
QSqlQuery query;
query.prepare("update Access set Unit = ? where AccessID = ?");
query.addBindValue(Unit);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductCategory(int AccessID, const QString &ProductCategory) {
QSqlQuery query;
query.prepare("update Access set ProductCategory = ? where AccessID = ?");
query.addBindValue(ProductCategory);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductImage(int AccessID, const QString &ProductImage) {
QSqlQuery query;
query.prepare("update Access set ProductImage = ? where AccessID = ?");
query.addBindValue(ProductImage);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProduct(int AccessID, const QString &Product) {
QSqlQuery query;
query.prepare("update Access set Product = ? where AccessID = ?");
query.addBindValue(Product);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductField(int AccessID, const QString &ProductField) {
QSqlQuery query;
query.prepare("update Access set ProductField = ? where AccessID = ?");
query.addBindValue(ProductField);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductFieldData(int AccessID, const QString &ProductFieldData) {
QSqlQuery query;
query.prepare("update Access set ProductFieldData = ? where AccessID = ?");
query.addBindValue(ProductFieldData);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setService(int AccessID, const QString &Service) {
QSqlQuery query;
query.prepare("update Access set Service = ? where AccessID = ?");
query.addBindValue(Service);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setStore(int AccessID, const QString &Store) {
QSqlQuery query;
query.prepare("update Access set Store = ? where AccessID = ?");
query.addBindValue(Store);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseStatus(int AccessID, const QString &PurchaseStatus) {
QSqlQuery query;
query.prepare("update Access set PurchaseStatus = ? where AccessID = ?");
query.addBindValue(PurchaseStatus);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseSerial(int AccessID, const QString &PurchaseSerial) {
QSqlQuery query;
query.prepare("update Access set PurchaseSerial = ? where AccessID = ?");
query.addBindValue(PurchaseSerial);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchase(int AccessID, const QString &Purchase) {
QSqlQuery query;
query.prepare("update Access set Purchase = ? where AccessID = ?");
query.addBindValue(Purchase);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseStoreProduct(int AccessID, const QString &PurchaseStoreProduct) {
QSqlQuery query;
query.prepare("update Access set PurchaseStoreProduct = ? where AccessID = ?");
query.addBindValue(PurchaseStoreProduct);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseFreeLine(int AccessID, const QString &PurchaseFreeLine) {
QSqlQuery query;
query.prepare("update Access set PurchaseFreeLine = ? where AccessID = ?");
query.addBindValue(PurchaseFreeLine);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderStatus(int AccessID, const QString &DeliveryOrderStatus) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderStatus = ? where AccessID = ?");
query.addBindValue(DeliveryOrderStatus);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrder(int AccessID, const QString &DeliveryOrder) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrder = ? where AccessID = ?");
query.addBindValue(DeliveryOrder);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderStoreProduct(int AccessID, const QString &DeliveryOrderStoreProduct) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderStoreProduct = ? where AccessID = ?");
query.addBindValue(DeliveryOrderStoreProduct);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderService(int AccessID, const QString &DeliveryOrderService) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderService = ? where AccessID = ?");
query.addBindValue(DeliveryOrderService);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderFreeline(int AccessID, const QString &DeliveryOrderFreeline) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderFreeline = ? where AccessID = ?");
query.addBindValue(DeliveryOrderFreeline);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoicePeriod(int AccessID, const QString &InvoicePeriod) {
QSqlQuery query;
query.prepare("update Access set InvoicePeriod = ? where AccessID = ?");
query.addBindValue(InvoicePeriod);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceYear(int AccessID, const QString &InvoiceYear) {
QSqlQuery query;
query.prepare("update Access set InvoiceYear = ? where AccessID = ?");
query.addBindValue(InvoiceYear);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceState(int AccessID, const QString &InvoiceState) {
QSqlQuery query;
query.prepare("update Access set InvoiceState = ? where AccessID = ?");
query.addBindValue(InvoiceState);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceSerial(int AccessID, const QString &InvoiceSerial) {
QSqlQuery query;
query.prepare("update Access set InvoiceSerial = ? where AccessID = ?");
query.addBindValue(InvoiceSerial);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoice(int AccessID, const QString &Invoice) {
QSqlQuery query;
query.prepare("update Access set Invoice = ? where AccessID = ?");
query.addBindValue(Invoice);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceStateD(int AccessID, const QString &InvoiceStateD) {
QSqlQuery query;
query.prepare("update Access set InvoiceStateD = ? where AccessID = ?");
query.addBindValue(InvoiceStateD);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceFreeline(int AccessID, const QString &InvoiceFreeline) {
QSqlQuery query;
query.prepare("update Access set InvoiceFreeline = ? where AccessID = ?");
query.addBindValue(InvoiceFreeline);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPaymentType(int AccessID, const QString &PaymentType) {
QSqlQuery query;
query.prepare("update Access set PaymentType = ? where AccessID = ?");
query.addBindValue(PaymentType);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPayment(int AccessID, const QString &Payment) {
QSqlQuery query;
query.prepare("update Access set Payment = ? where AccessID = ?");
query.addBindValue(Payment);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setTask(int AccessID, const QString &Task) {
QSqlQuery query;
query.prepare("update Access set Task = ? where AccessID = ?");
query.addBindValue(Task);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setLanguage(int AccessID, const QString &Language) {
QSqlQuery query;
query.prepare("update Access set Language = ? where AccessID = ?");
query.addBindValue(Language);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setTimeBooking(int AccessID, const QString &TimeBooking) {
QSqlQuery query;
query.prepare("update Access set TimeBooking = ? where AccessID = ?");
query.addBindValue(TimeBooking);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::sethashKey(int AccessID, const QString &hashKey) {
QSqlQuery query;
query.prepare("update Access set hashKey = ? where AccessID = ?");
query.addBindValue(hashKey);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setUserID(int AccessID, const QString &UserID) {
QSqlQuery query;
query.prepare("update Access set UserID = ? where AccessID = ?");
query.addBindValue(UserID);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setCreatedOn(int AccessID, const QString &CreatedOn) {
QSqlQuery query;
query.prepare("update Access set CreatedOn = ? where AccessID = ?");
query.addBindValue(CreatedOn);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setEditedOn(int AccessID, const QString &EditedOn) {
QSqlQuery query;
query.prepare("update Access set EditedOn = ? where AccessID = ?");
query.addBindValue(EditedOn);
query.addBindValue(AccessID);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

