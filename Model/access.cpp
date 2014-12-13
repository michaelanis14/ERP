/**************************************************************************
**   File: access.cpp
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#include "access.h"
#include "erpmodel.h"

Access::Access()
 : QSqlRelationalTableModel(){

this->Company = 0 ;
this->Title = "";
this->Tax = 0 ;
this->Employee = 0 ;
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
this->InvoiceStateDate = 0 ;
this->InvoiceFreeline = 0 ;
this->PaymentType = 0 ;
this->Payment = 0 ;
this->Task = 0 ;
this->TimeBooking = 0 ;
this->hashKey = "";
this->EmployeeID = 0 ;
this->CreatedON = "";
this->EditedON = "";
this->setTable("Access");
this->setEditStrategy(QSqlTableModel::OnManualSubmit);
this->setRelation(57, QSqlRelation("Employee", "EmployeeID", "Name"));
}
Access::Access(bool Company,QString Title,bool Tax,bool Employee,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateDate,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool TimeBooking,QString hashKey,int EmployeeID,QString CreatedON,QString EditedON) : QSqlRelationalTableModel(){
this->Company = Company ;
this->Title = Title ;
this->Tax = Tax ;
this->Employee = Employee ;
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
this->InvoiceStateDate = InvoiceStateDate ;
this->InvoiceFreeline = InvoiceFreeline ;
this->PaymentType = PaymentType ;
this->Payment = Payment ;
this->Task = Task ;
this->TimeBooking = TimeBooking ;
this->hashKey = hashKey ;
this->EmployeeID = EmployeeID ;
this->CreatedON = CreatedON ;
this->EditedON = EditedON ;
}

Access::Access(QString Title,bool Tax,bool Employee,bool Contact,bool ContactTelephone,bool ContactEmail,bool BankAccount,bool ContactClass,bool ContactType,bool Country,bool Currency,bool ContactStatus,bool FieldType,bool ContactField,bool ContactFieldData,bool ContactPersonField,bool ContactPersonFieldData,bool ContactPerson,bool ContactPersonTelephone,bool ContactPersonEmail,bool ProjectStatus,bool Project,bool ProjectFile,bool ProjectContactPerson,bool ProjectProduct,bool ProjectService,bool Unit,bool ProductCategory,bool ProductImage,bool Product,bool ProductField,bool ProductFieldData,bool Service,bool Store,bool PurchaseStatus,bool PurchaseSerial,bool Purchase,bool PurchaseStoreProduct,bool PurchaseFreeLine,bool DeliveryOrderStatus,bool DeliveryOrder,bool DeliveryOrderStoreProduct,bool DeliveryOrderService,bool DeliveryOrderFreeline,bool InvoicePeriod,bool InvoiceYear,bool InvoiceState,bool InvoiceSerial,bool Invoice,bool InvoiceStateDate,bool InvoiceFreeline,bool PaymentType,bool Payment,bool Task,bool TimeBooking,QString hashKey,int EmployeeID,QString CreatedON,QString EditedON) : QSqlRelationalTableModel(){
this->Company = 0 ;
this->Title = Title ;
this->Tax = Tax ;
this->Employee = Employee ;
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
this->InvoiceStateDate = InvoiceStateDate ;
this->InvoiceFreeline = InvoiceFreeline ;
this->PaymentType = PaymentType ;
this->Payment = Payment ;
this->Task = Task ;
this->TimeBooking = TimeBooking ;
this->hashKey = hashKey ;
this->EmployeeID = EmployeeID ;
this->CreatedON = CreatedON ;
this->EditedON = EditedON ;
}

bool Access::Init()
{

QString table = "Access";
QString query =
"(Company VARCHAR(1) NOT NULL AUTO_INCREMENT, "
"PRIMARY KEY (Company),"
"Title VARCHAR(40) NOT NULL, "
" KEY(Title),"
"Tax VARCHAR(1) NOT NULL, "
"Employee VARCHAR(1) NOT NULL, "
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
"InvoiceStateDate VARCHAR(1) NOT NULL, "
"InvoiceFreeline VARCHAR(1) NOT NULL, "
"PaymentType VARCHAR(1) NOT NULL, "
"Payment VARCHAR(1) NOT NULL, "
"Task VARCHAR(1) NOT NULL, "
"TimeBooking VARCHAR(1) NOT NULL, "
"hashKey VARCHAR(40) NOT NULL, "
"EmployeeID INT NOT NULL, "
"FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID)  ON DELETE CASCADE,"
"CreatedON VARCHAR(40) NOT NULL, "
"EditedON VARCHAR(40) NOT NULL, KEY(EditedON) )" ;

QList<QPair<QString,QString> >variables;
variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Company")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("Title")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Tax")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Employee")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Contact")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactTelephone")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactEmail")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("BankAccount")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactClass")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactType")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Country")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Currency")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("FieldType")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactField")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactFieldData")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonField")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonFieldData")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPerson")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonTelephone")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ContactPersonEmail")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Project")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectFile")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectContactPerson")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectProduct")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProjectService")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Unit")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductCategory")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductImage")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Product")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductField")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("ProductFieldData")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Service")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Store")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseSerial")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Purchase")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseStoreProduct")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PurchaseFreeLine")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderStatus")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrder")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderStoreProduct")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderService")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("DeliveryOrderFreeline")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoicePeriod")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceYear")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceState")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceSerial")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Invoice")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceStateDate")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("InvoiceFreeline")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("PaymentType")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Payment")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("Task")));variables.append(qMakePair(QString(" VARCHAR(1)"),QString("TimeBooking")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("hashKey")));variables.append(qMakePair(QString(" INT"),QString("EmployeeID")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("CreatedON")));variables.append(qMakePair(QString(" VARCHAR(40)"),QString("EditedON")));ErpModel::GetInstance()->createTable(table,query,variables);
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
if(Company== 0) {
this->CreatedOn = QDateTime::currentDateTime().toString();
ErpModel::GetInstance()->qeryExec("INSERT INTO Access (Title,Tax,Employee,Contact,ContactTelephone,ContactEmail,BankAccount,ContactClass,ContactType,Country,Currency,ContactStatus,FieldType,ContactField,ContactFieldData,ContactPersonField,ContactPersonFieldData,ContactPerson,ContactPersonTelephone,ContactPersonEmail,ProjectStatus,Project,ProjectFile,ProjectContactPerson,ProjectProduct,ProjectService,Unit,ProductCategory,ProductImage,Product,ProductField,ProductFieldData,Service,Store,PurchaseStatus,PurchaseSerial,Purchase,PurchaseStoreProduct,PurchaseFreeLine,DeliveryOrderStatus,DeliveryOrder,DeliveryOrderStoreProduct,DeliveryOrderService,DeliveryOrderFreeline,InvoicePeriod,InvoiceYear,InvoiceState,InvoiceSerial,Invoice,InvoiceStateDate,InvoiceFreeline,PaymentType,Payment,Task,TimeBooking,hashKey,EmployeeID,CreatedON,EditedON)"
"VALUES ('" +QString(this->Title)+"','"+QString::number(this->Tax)+"','"+QString::number(this->Employee)+"','"+QString::number(this->Contact)+"','"+QString::number(this->ContactTelephone)+"','"+QString::number(this->ContactEmail)+"','"+QString::number(this->BankAccount)+"','"+QString::number(this->ContactClass)+"','"+QString::number(this->ContactType)+"','"+QString::number(this->Country)+"','"+QString::number(this->Currency)+"','"+QString::number(this->ContactStatus)+"','"+QString::number(this->FieldType)+"','"+QString::number(this->ContactField)+"','"+QString::number(this->ContactFieldData)+"','"+QString::number(this->ContactPersonField)+"','"+QString::number(this->ContactPersonFieldData)+"','"+QString::number(this->ContactPerson)+"','"+QString::number(this->ContactPersonTelephone)+"','"+QString::number(this->ContactPersonEmail)+"','"+QString::number(this->ProjectStatus)+"','"+QString::number(this->Project)+"','"+QString::number(this->ProjectFile)+"','"+QString::number(this->ProjectContactPerson)+"','"+QString::number(this->ProjectProduct)+"','"+QString::number(this->ProjectService)+"','"+QString::number(this->Unit)+"','"+QString::number(this->ProductCategory)+"','"+QString::number(this->ProductImage)+"','"+QString::number(this->Product)+"','"+QString::number(this->ProductField)+"','"+QString::number(this->ProductFieldData)+"','"+QString::number(this->Service)+"','"+QString::number(this->Store)+"','"+QString::number(this->PurchaseStatus)+"','"+QString::number(this->PurchaseSerial)+"','"+QString::number(this->Purchase)+"','"+QString::number(this->PurchaseStoreProduct)+"','"+QString::number(this->PurchaseFreeLine)+"','"+QString::number(this->DeliveryOrderStatus)+"','"+QString::number(this->DeliveryOrder)+"','"+QString::number(this->DeliveryOrderStoreProduct)+"','"+QString::number(this->DeliveryOrderService)+"','"+QString::number(this->DeliveryOrderFreeline)+"','"+QString::number(this->InvoicePeriod)+"','"+QString::number(this->InvoiceYear)+"','"+QString::number(this->InvoiceState)+"','"+QString::number(this->InvoiceSerial)+"','"+QString::number(this->Invoice)+"','"+QString::number(this->InvoiceStateDate)+"','"+QString::number(this->InvoiceFreeline)+"','"+QString::number(this->PaymentType)+"','"+QString::number(this->Payment)+"','"+QString::number(this->Task)+"','"+QString::number(this->TimeBooking)+"','"+QString(this->hashKey)+"','"+QString::number(this->EmployeeID)+"','"+QString(this->CreatedON)+"','"+QString(this->EditedON)+"')");
}else {
ErpModel::GetInstance()->qeryExec("UPDATE Access SET "	"Title = '"+QString(this->Title)+"',"+"Tax = '"+QString::number(this->Tax)+"',"+"Employee = '"+QString::number(this->Employee)+"',"+"Contact = '"+QString::number(this->Contact)+"',"+"ContactTelephone = '"+QString::number(this->ContactTelephone)+"',"+"ContactEmail = '"+QString::number(this->ContactEmail)+"',"+"BankAccount = '"+QString::number(this->BankAccount)+"',"+"ContactClass = '"+QString::number(this->ContactClass)+"',"+"ContactType = '"+QString::number(this->ContactType)+"',"+"Country = '"+QString::number(this->Country)+"',"+"Currency = '"+QString::number(this->Currency)+"',"+"ContactStatus = '"+QString::number(this->ContactStatus)+"',"+"FieldType = '"+QString::number(this->FieldType)+"',"+"ContactField = '"+QString::number(this->ContactField)+"',"+"ContactFieldData = '"+QString::number(this->ContactFieldData)+"',"+"ContactPersonField = '"+QString::number(this->ContactPersonField)+"',"+"ContactPersonFieldData = '"+QString::number(this->ContactPersonFieldData)+"',"+"ContactPerson = '"+QString::number(this->ContactPerson)+"',"+"ContactPersonTelephone = '"+QString::number(this->ContactPersonTelephone)+"',"+"ContactPersonEmail = '"+QString::number(this->ContactPersonEmail)+"',"+"ProjectStatus = '"+QString::number(this->ProjectStatus)+"',"+"Project = '"+QString::number(this->Project)+"',"+"ProjectFile = '"+QString::number(this->ProjectFile)+"',"+"ProjectContactPerson = '"+QString::number(this->ProjectContactPerson)+"',"+"ProjectProduct = '"+QString::number(this->ProjectProduct)+"',"+"ProjectService = '"+QString::number(this->ProjectService)+"',"+"Unit = '"+QString::number(this->Unit)+"',"+"ProductCategory = '"+QString::number(this->ProductCategory)+"',"+"ProductImage = '"+QString::number(this->ProductImage)+"',"+"Product = '"+QString::number(this->Product)+"',"+"ProductField = '"+QString::number(this->ProductField)+"',"+"ProductFieldData = '"+QString::number(this->ProductFieldData)+"',"+"Service = '"+QString::number(this->Service)+"',"+"Store = '"+QString::number(this->Store)+"',"+"PurchaseStatus = '"+QString::number(this->PurchaseStatus)+"',"+"PurchaseSerial = '"+QString::number(this->PurchaseSerial)+"',"+"Purchase = '"+QString::number(this->Purchase)+"',"+"PurchaseStoreProduct = '"+QString::number(this->PurchaseStoreProduct)+"',"+"PurchaseFreeLine = '"+QString::number(this->PurchaseFreeLine)+"',"+"DeliveryOrderStatus = '"+QString::number(this->DeliveryOrderStatus)+"',"+"DeliveryOrder = '"+QString::number(this->DeliveryOrder)+"',"+"DeliveryOrderStoreProduct = '"+QString::number(this->DeliveryOrderStoreProduct)+"',"+"DeliveryOrderService = '"+QString::number(this->DeliveryOrderService)+"',"+"DeliveryOrderFreeline = '"+QString::number(this->DeliveryOrderFreeline)+"',"+"InvoicePeriod = '"+QString::number(this->InvoicePeriod)+"',"+"InvoiceYear = '"+QString::number(this->InvoiceYear)+"',"+"InvoiceState = '"+QString::number(this->InvoiceState)+"',"+"InvoiceSerial = '"+QString::number(this->InvoiceSerial)+"',"+"Invoice = '"+QString::number(this->Invoice)+"',"+"InvoiceStateDate = '"+QString::number(this->InvoiceStateDate)+"',"+"InvoiceFreeline = '"+QString::number(this->InvoiceFreeline)+"',"+"PaymentType = '"+QString::number(this->PaymentType)+"',"+"Payment = '"+QString::number(this->Payment)+"',"+"Task = '"+QString::number(this->Task)+"',"+"TimeBooking = '"+QString::number(this->TimeBooking)+"',"+"hashKey = '"+QString(this->hashKey)+"',"+"EmployeeID = '"+QString::number(this->EmployeeID)+"',"+"CreatedON = '"+QString(this->CreatedON)+"',"+"EditedON = '"+QString(this->EditedON)+"' WHERE Company ='"+QString::number(this->Company)+"'");
 }QSqlQuery query = ErpModel::GetInstance()->qeryExec("SELECT  Company FROM Access WHERE Title = '"+Title+"' AND EditedOn = '"+this->EditedOn+"'"  );
while (query.next()) { 
 if(query.value(0).toInt() != 0){ 
 this->Company = query.value(0).toInt();	
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
if(Company!= 0) {
(ErpModel::GetInstance()->qeryExec("DELETE FROM Access WHERE Company ="+QString::number(this->Company)+""));
return true;
 }
return false;
}

Access* Access::get() {
if(Company!= 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Access"
"WHERE Company ='"+QString::number(this->Company)+"'"));
while (query.next()) {
return new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toString(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toString());
 }

}
return new Access();
 }

QList<Access*> Access::GetAll() {
	QList<Access*> accesss =   QList<Access*>();
	QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT *  FROM Access ORDER BY Company ASC"));
	while (query.next()) {
accesss.append(new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toString(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toString()));
	}
	return accesss;
}

Access* Access::Get(int id) {
Access* access = new Access();
if(id != 0) {
QSqlQuery query = (ErpModel::GetInstance()->qeryExec("SELECT * FROM Access WHERE Company = '"+QString::number(id)+"' ORDER BY Company ASC "));
while (query.next()) {
access = new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toString(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toString());
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
access = new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toString(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toString());

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
"OR CreatedON LIKE '%"+keyword+"%'"
"OR EditedON LIKE '%"+keyword+"%'"
));
while (query.next()) {
list.append(new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toString(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toString()));
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
		list.append(qMakePair(accesss[i]->Company,accesss[i]->Title));
	}
	return list;
}

QList<QPair< int,QString > > Access::GetPairList(QList<Access*> accesss) {
	QList<QPair<int,QString > > list;
	for(int i = 0; i <accesss.count(); i++){
		list.append(qMakePair(accesss[i]->Company,accesss[i]->Title));
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
list.append(new Access(query.value(0).toInt(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt(),query.value(11).toInt(),query.value(12).toInt(),query.value(13).toInt(),query.value(14).toInt(),query.value(15).toInt(),query.value(16).toInt(),query.value(17).toInt(),query.value(18).toInt(),query.value(19).toInt(),query.value(20).toInt(),query.value(21).toInt(),query.value(22).toInt(),query.value(23).toInt(),query.value(24).toInt(),query.value(25).toInt(),query.value(26).toInt(),query.value(27).toInt(),query.value(28).toInt(),query.value(29).toInt(),query.value(30).toInt(),query.value(31).toInt(),query.value(32).toInt(),query.value(33).toInt(),query.value(34).toInt(),query.value(35).toInt(),query.value(36).toInt(),query.value(37).toInt(),query.value(38).toInt(),query.value(39).toInt(),query.value(40).toInt(),query.value(41).toInt(),query.value(42).toInt(),query.value(43).toInt(),query.value(44).toInt(),query.value(45).toInt(),query.value(46).toInt(),query.value(47).toInt(),query.value(48).toInt(),query.value(49).toInt(),query.value(50).toInt(),query.value(51).toInt(),query.value(52).toInt(),query.value(53).toInt(),query.value(54).toInt(),query.value(55).toInt(),query.value(56).toString(),query.value(57).toInt(),query.value(58).toString(),query.value(59).toString()));
 }

}
return list;
 }

Qt::ItemFlags Access::flags(const QModelIndex &index) const {
Qt::ItemFlags flags = QSqlRelationalTableModel::flags(index);
flags ^= Qt::ItemIsEditable;
if (
index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8 || index.column() == 9 || index.column() == 10 || index.column() == 11 || index.column() == 12 || index.column() == 13 || index.column() == 14 || index.column() == 15 || index.column() == 16 || index.column() == 17 || index.column() == 18 || index.column() == 19 || index.column() == 20 || index.column() == 21 || index.column() == 22 || index.column() == 23 || index.column() == 24 || index.column() == 25 || index.column() == 26 || index.column() == 27 || index.column() == 28 || index.column() == 29 || index.column() == 30 || index.column() == 31 || index.column() == 32 || index.column() == 33 || index.column() == 34 || index.column() == 35 || index.column() == 36 || index.column() == 37 || index.column() == 38 || index.column() == 39 || index.column() == 40 || index.column() == 41 || index.column() == 42 || index.column() == 43 || index.column() == 44 || index.column() == 45 || index.column() == 46 || index.column() == 47 || index.column() == 48 || index.column() == 49 || index.column() == 50 || index.column() == 51 || index.column() == 52 || index.column() == 53 || index.column() == 54 || index.column() == 55 || index.column() == 56 || index.column() == 57 || index.column() == 58 || index.column() == 59)
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
ok = setTax(id, value.toString());
else if (index.column() == 3)
ok = setEmployee(id, value.toString());
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
ok = setUnit(id, value.toString());
else if (index.column() == 28)
ok = setProductCategory(id, value.toString());
else if (index.column() == 29)
ok = setProductImage(id, value.toString());
else if (index.column() == 30)
ok = setProduct(id, value.toString());
else if (index.column() == 31)
ok = setProductField(id, value.toString());
else if (index.column() == 32)
ok = setProductFieldData(id, value.toString());
else if (index.column() == 33)
ok = setService(id, value.toString());
else if (index.column() == 34)
ok = setStore(id, value.toString());
else if (index.column() == 35)
ok = setPurchaseStatus(id, value.toString());
else if (index.column() == 36)
ok = setPurchaseSerial(id, value.toString());
else if (index.column() == 37)
ok = setPurchase(id, value.toString());
else if (index.column() == 38)
ok = setPurchaseStoreProduct(id, value.toString());
else if (index.column() == 39)
ok = setPurchaseFreeLine(id, value.toString());
else if (index.column() == 40)
ok = setDeliveryOrderStatus(id, value.toString());
else if (index.column() == 41)
ok = setDeliveryOrder(id, value.toString());
else if (index.column() == 42)
ok = setDeliveryOrderStoreProduct(id, value.toString());
else if (index.column() == 43)
ok = setDeliveryOrderService(id, value.toString());
else if (index.column() == 44)
ok = setDeliveryOrderFreeline(id, value.toString());
else if (index.column() == 45)
ok = setInvoicePeriod(id, value.toString());
else if (index.column() == 46)
ok = setInvoiceYear(id, value.toString());
else if (index.column() == 47)
ok = setInvoiceState(id, value.toString());
else if (index.column() == 48)
ok = setInvoiceSerial(id, value.toString());
else if (index.column() == 49)
ok = setInvoice(id, value.toString());
else if (index.column() == 50)
ok = setInvoiceStateDate(id, value.toString());
else if (index.column() == 51)
ok = setInvoiceFreeline(id, value.toString());
else if (index.column() == 52)
ok = setPaymentType(id, value.toString());
else if (index.column() == 53)
ok = setPayment(id, value.toString());
else if (index.column() == 54)
ok = setTask(id, value.toString());
else if (index.column() == 55)
ok = setTimeBooking(id, value.toString());
else if (index.column() == 56)
ok = sethashKey(id, value.toString());
else if (index.column() == 57)
ok = setEmployeeID(id, value.toString());
else if (index.column() == 58)
ok = setCreatedON(id, value.toString());
else if (index.column() == 59)
ok = setEditedON(id, value.toString());
refresh();
}
return ok;
}

bool Access::remove(const QModelIndex &index) {
QModelIndex primaryKeyIndex = QSqlRelationalTableModel::index(index.row(), 0);
bool ok = true;
this->Company = data(primaryKeyIndex).toInt();
ok = this->remove();
refresh();
return ok;
}

void Access::refresh() {
if(!ErpModel::GetInstance()->db.isOpen()&&!ErpModel::GetInstance()->db.open())
qDebug() <<"Couldn't open DataBase at Refresh() Access!";
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Tax"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Employee"));
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
this->setHeaderData(27, Qt::Horizontal, QObject::tr("Unit"));
this->setHeaderData(28, Qt::Horizontal, QObject::tr("Product Category"));
this->setHeaderData(29, Qt::Horizontal, QObject::tr("Product Image"));
this->setHeaderData(30, Qt::Horizontal, QObject::tr("Product"));
this->setHeaderData(31, Qt::Horizontal, QObject::tr("Product Field"));
this->setHeaderData(32, Qt::Horizontal, QObject::tr("Product Field Data"));
this->setHeaderData(33, Qt::Horizontal, QObject::tr("Service"));
this->setHeaderData(34, Qt::Horizontal, QObject::tr("Store"));
this->setHeaderData(35, Qt::Horizontal, QObject::tr("Purchase Status"));
this->setHeaderData(36, Qt::Horizontal, QObject::tr("Purchase Serial"));
this->setHeaderData(37, Qt::Horizontal, QObject::tr("Purchase"));
this->setHeaderData(38, Qt::Horizontal, QObject::tr("Purchase Store Product"));
this->setHeaderData(39, Qt::Horizontal, QObject::tr("Purchase Free Line"));
this->setHeaderData(40, Qt::Horizontal, QObject::tr("Delivery Order Status"));
this->setHeaderData(41, Qt::Horizontal, QObject::tr("Delivery Order"));
this->setHeaderData(42, Qt::Horizontal, QObject::tr("Delivery Order Store Product"));
this->setHeaderData(43, Qt::Horizontal, QObject::tr("Delivery Order Service"));
this->setHeaderData(44, Qt::Horizontal, QObject::tr("Delivery Order Freeline"));
this->setHeaderData(45, Qt::Horizontal, QObject::tr("Invoice Period"));
this->setHeaderData(46, Qt::Horizontal, QObject::tr("Invoice Year"));
this->setHeaderData(47, Qt::Horizontal, QObject::tr("Invoice State"));
this->setHeaderData(48, Qt::Horizontal, QObject::tr("Invoice Serial"));
this->setHeaderData(49, Qt::Horizontal, QObject::tr("Invoice"));
this->setHeaderData(50, Qt::Horizontal, QObject::tr("Invoice State Date"));
this->setHeaderData(51, Qt::Horizontal, QObject::tr("Invoice Freeline"));
this->setHeaderData(52, Qt::Horizontal, QObject::tr("Payment Type"));
this->setHeaderData(53, Qt::Horizontal, QObject::tr("Payment"));
this->setHeaderData(54, Qt::Horizontal, QObject::tr("Task"));
this->setHeaderData(55, Qt::Horizontal, QObject::tr("Time Booking"));
this->setHeaderData(56, Qt::Horizontal, QObject::tr("hashKey"));
this->setHeaderData(57, Qt::Horizontal, QObject::tr("Employee"));
this->setHeaderData(58, Qt::Horizontal, QObject::tr("Created O N"));
this->setHeaderData(59, Qt::Horizontal, QObject::tr("Edited O N"));
	this->select();
//	if(ErpModel::GetInstance()->db.isOpen())
//		ErpModel::GetInstance()->db.close();
}
bool Access::setTitle(bool Company, const QString &Title) {
QSqlQuery query;
query.prepare("update Access set Title = ? where Company = ?");
query.addBindValue(Title);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setTax(bool Company, const QString &Tax) {
QSqlQuery query;
query.prepare("update Access set Tax = ? where Company = ?");
query.addBindValue(Tax);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setEmployee(bool Company, const QString &Employee) {
QSqlQuery query;
query.prepare("update Access set Employee = ? where Company = ?");
query.addBindValue(Employee);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContact(bool Company, const QString &Contact) {
QSqlQuery query;
query.prepare("update Access set Contact = ? where Company = ?");
query.addBindValue(Contact);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactTelephone(bool Company, const QString &ContactTelephone) {
QSqlQuery query;
query.prepare("update Access set ContactTelephone = ? where Company = ?");
query.addBindValue(ContactTelephone);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactEmail(bool Company, const QString &ContactEmail) {
QSqlQuery query;
query.prepare("update Access set ContactEmail = ? where Company = ?");
query.addBindValue(ContactEmail);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setBankAccount(bool Company, const QString &BankAccount) {
QSqlQuery query;
query.prepare("update Access set BankAccount = ? where Company = ?");
query.addBindValue(BankAccount);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactClass(bool Company, const QString &ContactClass) {
QSqlQuery query;
query.prepare("update Access set ContactClass = ? where Company = ?");
query.addBindValue(ContactClass);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactType(bool Company, const QString &ContactType) {
QSqlQuery query;
query.prepare("update Access set ContactType = ? where Company = ?");
query.addBindValue(ContactType);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setCountry(bool Company, const QString &Country) {
QSqlQuery query;
query.prepare("update Access set Country = ? where Company = ?");
query.addBindValue(Country);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setCurrency(bool Company, const QString &Currency) {
QSqlQuery query;
query.prepare("update Access set Currency = ? where Company = ?");
query.addBindValue(Currency);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactStatus(bool Company, const QString &ContactStatus) {
QSqlQuery query;
query.prepare("update Access set ContactStatus = ? where Company = ?");
query.addBindValue(ContactStatus);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setFieldType(bool Company, const QString &FieldType) {
QSqlQuery query;
query.prepare("update Access set FieldType = ? where Company = ?");
query.addBindValue(FieldType);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactField(bool Company, const QString &ContactField) {
QSqlQuery query;
query.prepare("update Access set ContactField = ? where Company = ?");
query.addBindValue(ContactField);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactFieldData(bool Company, const QString &ContactFieldData) {
QSqlQuery query;
query.prepare("update Access set ContactFieldData = ? where Company = ?");
query.addBindValue(ContactFieldData);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonField(bool Company, const QString &ContactPersonField) {
QSqlQuery query;
query.prepare("update Access set ContactPersonField = ? where Company = ?");
query.addBindValue(ContactPersonField);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonFieldData(bool Company, const QString &ContactPersonFieldData) {
QSqlQuery query;
query.prepare("update Access set ContactPersonFieldData = ? where Company = ?");
query.addBindValue(ContactPersonFieldData);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPerson(bool Company, const QString &ContactPerson) {
QSqlQuery query;
query.prepare("update Access set ContactPerson = ? where Company = ?");
query.addBindValue(ContactPerson);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonTelephone(bool Company, const QString &ContactPersonTelephone) {
QSqlQuery query;
query.prepare("update Access set ContactPersonTelephone = ? where Company = ?");
query.addBindValue(ContactPersonTelephone);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setContactPersonEmail(bool Company, const QString &ContactPersonEmail) {
QSqlQuery query;
query.prepare("update Access set ContactPersonEmail = ? where Company = ?");
query.addBindValue(ContactPersonEmail);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectStatus(bool Company, const QString &ProjectStatus) {
QSqlQuery query;
query.prepare("update Access set ProjectStatus = ? where Company = ?");
query.addBindValue(ProjectStatus);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProject(bool Company, const QString &Project) {
QSqlQuery query;
query.prepare("update Access set Project = ? where Company = ?");
query.addBindValue(Project);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectFile(bool Company, const QString &ProjectFile) {
QSqlQuery query;
query.prepare("update Access set ProjectFile = ? where Company = ?");
query.addBindValue(ProjectFile);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectContactPerson(bool Company, const QString &ProjectContactPerson) {
QSqlQuery query;
query.prepare("update Access set ProjectContactPerson = ? where Company = ?");
query.addBindValue(ProjectContactPerson);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectProduct(bool Company, const QString &ProjectProduct) {
QSqlQuery query;
query.prepare("update Access set ProjectProduct = ? where Company = ?");
query.addBindValue(ProjectProduct);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProjectService(bool Company, const QString &ProjectService) {
QSqlQuery query;
query.prepare("update Access set ProjectService = ? where Company = ?");
query.addBindValue(ProjectService);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setUnit(bool Company, const QString &Unit) {
QSqlQuery query;
query.prepare("update Access set Unit = ? where Company = ?");
query.addBindValue(Unit);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductCategory(bool Company, const QString &ProductCategory) {
QSqlQuery query;
query.prepare("update Access set ProductCategory = ? where Company = ?");
query.addBindValue(ProductCategory);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductImage(bool Company, const QString &ProductImage) {
QSqlQuery query;
query.prepare("update Access set ProductImage = ? where Company = ?");
query.addBindValue(ProductImage);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProduct(bool Company, const QString &Product) {
QSqlQuery query;
query.prepare("update Access set Product = ? where Company = ?");
query.addBindValue(Product);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductField(bool Company, const QString &ProductField) {
QSqlQuery query;
query.prepare("update Access set ProductField = ? where Company = ?");
query.addBindValue(ProductField);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setProductFieldData(bool Company, const QString &ProductFieldData) {
QSqlQuery query;
query.prepare("update Access set ProductFieldData = ? where Company = ?");
query.addBindValue(ProductFieldData);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setService(bool Company, const QString &Service) {
QSqlQuery query;
query.prepare("update Access set Service = ? where Company = ?");
query.addBindValue(Service);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setStore(bool Company, const QString &Store) {
QSqlQuery query;
query.prepare("update Access set Store = ? where Company = ?");
query.addBindValue(Store);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseStatus(bool Company, const QString &PurchaseStatus) {
QSqlQuery query;
query.prepare("update Access set PurchaseStatus = ? where Company = ?");
query.addBindValue(PurchaseStatus);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseSerial(bool Company, const QString &PurchaseSerial) {
QSqlQuery query;
query.prepare("update Access set PurchaseSerial = ? where Company = ?");
query.addBindValue(PurchaseSerial);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchase(bool Company, const QString &Purchase) {
QSqlQuery query;
query.prepare("update Access set Purchase = ? where Company = ?");
query.addBindValue(Purchase);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseStoreProduct(bool Company, const QString &PurchaseStoreProduct) {
QSqlQuery query;
query.prepare("update Access set PurchaseStoreProduct = ? where Company = ?");
query.addBindValue(PurchaseStoreProduct);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPurchaseFreeLine(bool Company, const QString &PurchaseFreeLine) {
QSqlQuery query;
query.prepare("update Access set PurchaseFreeLine = ? where Company = ?");
query.addBindValue(PurchaseFreeLine);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderStatus(bool Company, const QString &DeliveryOrderStatus) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderStatus = ? where Company = ?");
query.addBindValue(DeliveryOrderStatus);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrder(bool Company, const QString &DeliveryOrder) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrder = ? where Company = ?");
query.addBindValue(DeliveryOrder);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderStoreProduct(bool Company, const QString &DeliveryOrderStoreProduct) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderStoreProduct = ? where Company = ?");
query.addBindValue(DeliveryOrderStoreProduct);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderService(bool Company, const QString &DeliveryOrderService) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderService = ? where Company = ?");
query.addBindValue(DeliveryOrderService);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setDeliveryOrderFreeline(bool Company, const QString &DeliveryOrderFreeline) {
QSqlQuery query;
query.prepare("update Access set DeliveryOrderFreeline = ? where Company = ?");
query.addBindValue(DeliveryOrderFreeline);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoicePeriod(bool Company, const QString &InvoicePeriod) {
QSqlQuery query;
query.prepare("update Access set InvoicePeriod = ? where Company = ?");
query.addBindValue(InvoicePeriod);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceYear(bool Company, const QString &InvoiceYear) {
QSqlQuery query;
query.prepare("update Access set InvoiceYear = ? where Company = ?");
query.addBindValue(InvoiceYear);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceState(bool Company, const QString &InvoiceState) {
QSqlQuery query;
query.prepare("update Access set InvoiceState = ? where Company = ?");
query.addBindValue(InvoiceState);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceSerial(bool Company, const QString &InvoiceSerial) {
QSqlQuery query;
query.prepare("update Access set InvoiceSerial = ? where Company = ?");
query.addBindValue(InvoiceSerial);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoice(bool Company, const QString &Invoice) {
QSqlQuery query;
query.prepare("update Access set Invoice = ? where Company = ?");
query.addBindValue(Invoice);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceStateDate(bool Company, const QString &InvoiceStateDate) {
QSqlQuery query;
query.prepare("update Access set InvoiceStateDate = ? where Company = ?");
query.addBindValue(InvoiceStateDate);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setInvoiceFreeline(bool Company, const QString &InvoiceFreeline) {
QSqlQuery query;
query.prepare("update Access set InvoiceFreeline = ? where Company = ?");
query.addBindValue(InvoiceFreeline);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPaymentType(bool Company, const QString &PaymentType) {
QSqlQuery query;
query.prepare("update Access set PaymentType = ? where Company = ?");
query.addBindValue(PaymentType);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setPayment(bool Company, const QString &Payment) {
QSqlQuery query;
query.prepare("update Access set Payment = ? where Company = ?");
query.addBindValue(Payment);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setTask(bool Company, const QString &Task) {
QSqlQuery query;
query.prepare("update Access set Task = ? where Company = ?");
query.addBindValue(Task);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setTimeBooking(bool Company, const QString &TimeBooking) {
QSqlQuery query;
query.prepare("update Access set TimeBooking = ? where Company = ?");
query.addBindValue(TimeBooking);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::sethashKey(bool Company, const QString &hashKey) {
QSqlQuery query;
query.prepare("update Access set hashKey = ? where Company = ?");
query.addBindValue(hashKey);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setEmployeeID(bool Company, const QString &EmployeeID) {
QSqlQuery query;
query.prepare("update Access set EmployeeID = ? where Company = ?");
query.addBindValue(EmployeeID);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setCreatedON(bool Company, const QString &CreatedON) {
QSqlQuery query;
query.prepare("update Access set CreatedON = ? where Company = ?");
query.addBindValue(CreatedON);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}
bool Access::setEditedON(bool Company, const QString &EditedON) {
QSqlQuery query;
query.prepare("update Access set EditedON = ? where Company = ?");
query.addBindValue(EditedON);
query.addBindValue(Company);
if( !query.exec() )
qDebug() << query.lastError().text();
return true;
}

