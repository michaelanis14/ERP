/*************************************
**   Created on:  9/11/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpmodel.h"
#include "company.h"
#include "tax.h"
#include "language.h"

#include "contact.h"
#include "contacttelephone.h"
#include "contactemail.h"
#include "bankaccount.h"
#include "contactclass.h"
#include "contacttype.h"
#include "country.h"
#include "currency.h"
#include "contactstatus.h"
#include "fieldtype.h"
#include "contactfield.h"
#include "contactfielddata.h"
#include "contactpersonfield.h"
#include "contactpersonfielddata.h"
#include "contactperson.h"
#include "contactpersontelephone.h"
#include "contactpersonemail.h"
#include "project.h"
#include "unit.h"
#include "productcategory.h"
#include "productfield.h"
#include "productfielddata.h"
#include "product.h"
#include "service.h"
#include "store.h"
#include "purchasestatus.h"
#include "purchase.h"
#include "purchaseserial.h"
#include "purchasestoreproduct.h"
#include "purchasefreeline.h"
#include "deliveryorderstatus.h"
#include "deliveryorderserial.h"
#include "deliveryorder.h"
#include "deliveryorderstoreproduct.h"
#include "deliveryorderservice.h"
#include "deliveryorderfreeline.h"
#include "invoiceperiod.h"
#include "invoiceyear.h"
#include "invoicestate.h"
#include "invoicestatedate.h"
#include "invoice.h"
#include "invoiceserial.h"
#include "invoicefreeline.h"
#include "paymenttype.h"
#include "payment.h"
#include "contactpersonfielddata.h"
#include "task.h"
#include "projectsales.h"
#include "projectcontactperson.h"
#include "projectproduct.h"
#include "projectservice.h"
#include "projectfile.h"
#include "projectstatus.h"
#include "access.h"

#include <QSql>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

ErpModel::ErpModel()
{
	LoggedUser = new User();
	UserAccessList =   QList<Access*>();


	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	//db.setDatabaseName("testqt");
	db.setUserName("root");
	//       db.setPassword("root");


	if (!db.isValid()){
		qDebug() << db.lastError().text();
		return;
	}

	db.open();
	QString query = "SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME = 'testqt'";
	QSqlQuery q = db.exec(query);

	if (q.size() == 0){
		db.exec("CREATE SCHEMA `testqt` DEFAULT CHARACTER SET utf8 ;");
		qDebug() << db.lastError().text();
		db.setDatabaseName("testqt");
	}else
		db.setDatabaseName("testqt");


}

ErpModel* ErpModel::p_instance = 0;
/**
* A function.
* returns the static object instance of the ERP Model
*/
ErpModel* ErpModel::GetInstance() {
	if (p_instance == 0) {
		p_instance = new ErpModel();
	}
	return p_instance;
}

QSqlQuery ErpModel::qeryExec(QString q){
	//qDebug() << q;
	QDateTime startTime = QDateTime::currentDateTime();
	if(db.open())   {

		QSqlQuery query(db);
		query.prepare(q);
		if( !query.exec() )
			QMessageBox::warning(0,"BataBase Issue",query.lastError().text() + query.lastQuery());
		//else
		//	qDebug() << q +"Exec: " +QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch() - startTime.toMSecsSinceEpoch()) +"ms";
		db.close();
		return query;
	}
	else    {
		if(db.lastError().text().contains("Unknown database")){
			QMessageBox::warning(0,"BataBase Issue","Create the Database:");

		}
		QMessageBox::warning(0,"BataBase Issue","Something went Wrong:" + db.lastError().text());
		QSqlQuery query;
		return query;
	}
}

bool ErpModel::createTable(QString table,QString query,QList<QPair<QString,QString> >variables){

	if(db.open())   {
		QStringList tableList = ErpModel::GetInstance()->db.tables();



		bool tableExists = false;

		for(int i=0; i<tableList.count(); i++)
		{
			if(table == tableList.at(i)){
				tableExists=true;
				QSqlRecord record = db.record(tableList.at(i));
				//qDebug() << record.field(0).name() ;
				if(variables.length()-record.count() != 0){
					if(variables.length() > record.count()){
						int k = 0;
						for(int j =0; j < variables.length();j++){

							if(record.fieldName(k)!=variables[j].second){
							QSqlQuery query(db);
							query.prepare(QString("ALTER TABLE "+table+" ADD "+variables[j].second+" "+variables[j].first+" NOT NULL AFTER "+variables[j-1].second+";"));
								qDebug() << query.lastQuery();
							if( !query.exec() )
								QMessageBox::warning(0,"BataBase Issue",query.lastError().text() + query.lastQuery());


						}
							else k++;
					}

					}else{
						int k = 0;
						for(int j =0; j < record.count();j++){
							if(record.fieldName(j)!=variables[k].second){
							QSqlQuery query(db);
							query.prepare(QString("ALTER TABLE "+table+" DROP COLUMN "+record.fieldName(j)+";"));
								qDebug() << query.lastQuery();
							if( !query.exec() )
								QMessageBox::warning(0,"BataBase Issue",query.lastError().text() + query.lastQuery());

							}
							else k++;
						}
					}
					record = db.record(tableList.at(i));
				}

				for(int j =0; j < record.count();j++){

					if(record.fieldName(j)!=variables[j].second){
						QSqlQuery query(db);
						query.prepare(QString("ALTER TABLE "+table+" CHANGE "+record.fieldName(j)+" "+variables[j].second+" "+variables[j].first+";"));
						qDebug() << query.lastQuery();
						if( !query.exec() )
							QMessageBox::warning(0,"BataBase Issue",query.lastError().text() + query.lastQuery());


					}
				}


				break;
			}
		}
		db.close();
		if(tableExists == false)
		{
			ErpModel::GetInstance()->qeryExec("CREATE TABLE " + table + query );
		}
	}
	return true;
}



bool ErpModel::init(){
	ContactType::Init();
	if(ContactType::GetAll().count() < 2){
		ContactType* contactType = new ContactType("Customer","","");
		contactType->save();
		contactType = new ContactType("Supplier","","");
		contactType->save();
		contactType = new ContactType("Customer and Supplier","","");
		contactType->save();
		contactType = new ContactType("Employee","","");
		contactType->save();
		contactType = new ContactType("Other","","");
		contactType->save();
	}
	ContactClass::Init();
	if(ContactClass::GetAll().count() < 2){
		ContactClass* contactClass = new ContactClass("Company","","");
		contactClass->save();
		contactClass = new ContactClass("Person","","");
		contactClass->save();
		contactClass = new ContactClass("Club","","");
		contactClass->save();
		contactClass = new ContactClass("Government","","");
		contactClass->save();

	}
	ContactStatus::Init();
	if(ContactStatus::GetAll().count() < 1){
		ContactStatus* contactStatus = new ContactStatus("active","","");
		contactStatus->save();
		contactStatus = new ContactStatus("inactive","","");
		contactStatus->save();
	}
	Country::Init();
	if(Country::GetAll().count() < 5){
		QList<QString> countries;
		countries <<"Afghanistan"<<"Albania"<<"Algeria"<<"American Samoa"<<"Andorra"<<"Angola"<<"Anguilla"<<"Antigua and Barbuda"<<"Argentina"<<"Armenia"<<"Aruba"<<"Australia"<<"Austria"<<"Azerbaijan"<<"Bahamas"<<"Bahrain"<<"Bangladesh"<<"Barbados"<<"Belarus"<<"Belgium"<<"Belize"<<"Benin"<<"Bermuda"<<"Bhutan"<<"Bolivia"<<"Bosnia-Herzegovina"<<"Botswana"<<"Bouvet Island"<<"Brazil"<<"Brunei"<<"Bulgaria"<<"Burkina Faso"<<"Burundi"<<"Cambodia"<<"Cameroon"<<"Canada"<<"Cape Verde"<<"Cayman Islands"<<"Central African Republic"<<"Chad"<<"Chile"<<"China"<<"Christmas Island"<<"Cocos (Keeling) Islands"<<"Colombia"<<"Comoros"<<"Congo<< Democratic Republic of the (Zaire)"<<"Congo<< Republic of"<<"Cook Islands"<<"Costa Rica"<<"Croatia"<<"Cuba"<<"Cyprus"<<"Czech Republic"<<"Denmark"<<"Djibouti"<<"Dominica"<<"Dominican Republic"<<"Ecuador"<<"Egypt"<<"El Salvador"<<"Equatorial Guinea"<<"Eritrea"<<"Estonia"<<"Ethiopia"<<"Falkland Islands"<<"Faroe Islands"<<"Fiji"<<"Finland"<<"France"<<"French Guiana"<<"Gabon"<<"Gambia"<<"Georgia"<<"Germany"<<"Ghana"<<"Gibraltar"<<"Greece"<<"Greenland"<<"Grenada"<<"Guadeloupe (French)"<<"Guam (USA)"<<"Guatemala"<<"Guinea"<<"Guinea Bissau"<<"Guyana"<<"Haiti"<<"Holy See"<<"Honduras"<<"Hong Kong"<<"Hungary"<<"Iceland"<<"India"<<"Indonesia"<<"Iran"<<"Iraq"<<"Ireland"<<"Israel"<<"Italy"<<"Ivory Coast (Cote D`Ivoire)"<<"Jamaica"<<"Japan"<<"Jordan"<<"Kazakhstan"<<"Kenya"<<"Kiribati"<<"Kuwait"<<"Kyrgyzstan"<<"Laos"<<"Latvia"<<"Lebanon"<<"Lesotho"<<"Liberia"<<"Libya"<<"Liechtenstein"<<"Lithuania"<<"Luxembourg"<<"Macau"<<"Macedonia"<<"Madagascar"<<"Malawi"<<"Malaysia"<<"Maldives"<<"Mali"<<"Malta"<<"Marshall Islands"<<"Martinique (French)"<<"Mauritania"<<"Mauritius"<<"Mayotte"<<"Mexico"<<"Micronesia"<<"Moldova"<<"Monaco"<<"Mongolia"<<"Montenegro"<<"Montserrat"<<"Morocco"<<"Mozambique"<<"Myanmar"<<"Namibia"<<"Nauru"<<"Nepal"<<"Netherlands"<<"Netherlands Antilles"<<"New Caledonia (French)"<<"New Zealand"<<"Nicaragua"<<"Niger"<<"Nigeria"<<"Niue"<<"Norfolk Island"<<"North Korea"<<"Northern Mariana Islands"<<"Norway"<<"Oman"<<"Pakistan"<<"Palau"<<"Palestine"<<"Panama"<<"Papua New Guinea"<<"Paraguay"<<"Peru"<<"Philippines"<<"Pitcairn Island"<<"Poland"<<"Polynesia (French)"<<"Portugal"<<"Puerto Rico"<<"Qatar"<<"Reunion"<<"Romania"<<"Russia"<<"Rwanda"<<"Saint Helena"<<"Saint Kitts and Nevis"<<"Saint Lucia"<<"Saint Pierre and Miquelon"<<"Saint Vincent and Grenadines"<<"Samoa"<<"San Marino"<<"Sao Tome and Principe"<<"Saudi Arabia"<<"Senegal"<<"Serbia"<<"Seychelles"<<"Sierra Leone"<<"Singapore"<<"Slovakia"<<"Slovenia"<<"Solomon Islands"<<"Somalia"<<"South Africa"<<"South Georgia and South Sandwich Islands"<<"South Korea"<<"South Sudan"<<"Spain"<<"Sri Lanka"<<"Sudan"<<"Suriname"<<"Svalbard and Jan Mayen Islands"<<"Swaziland"<<"Sweden"<<"Switzerland"<<"Syria"<<"Taiwan"<<"Tajikistan"<<"Tanzania"<<"Thailand"<<"Timor-Leste (East Timor)"<<"Togo"<<"Tokelau"<<"Tonga"<<"Trinidad and Tobago"<<"Tunisia"<<"Turkey"<<"Turkmenistan"<<"Turks and Caicos Islands"<<"Tuvalu"<<"Uganda"<<"Ukraine"<<"United Arab Emirates"<<"United Kingdom"<<"United States"<<"Uruguay"<<"Uzbekistan"<<"Vanuatu"<<"Venezuela"<<"Vietnam"<<"Virgin Islands"<<"Wallis and Futuna Islands"<<"Yemen"<<"Zambia"<<"Zimbabwe";
		for(int i = 0;i < countries.count(); i++){
			Country* country = new Country(countries.at(i).trimmed(),"","");
			country->save();
		}
	}


	Contact::Init();
	if(Contact::GetAll().count() < 1){
		Contact* contact = new Contact("Employee1","Mr."+QString::number(Contact::GetAll().count()),QDate::currentDate(),4,1,Contact::GetAll().count(),"AA","na","na",1,1,"na","na","na","na");
		contact->save();
	}

	Currency::Init();
	if(Currency::GetAll().count() < 4){
		Currency* curr = new Currency("USD","","");
		curr->save();
		curr = new Currency("EUR","","");
		curr->save();
		curr = new Currency("EGP","","");
		curr->save();
		curr = new Currency("YNN","","");
		curr->save();

	}
	Company::Init();
	Tax::Init();
	if(Tax::GetAll().count() < 4){
		Tax *tax = new Tax("0","","");
		tax->save();
		tax = new Tax("10","","");
		tax->save();
		tax = new Tax("12","","");
		tax->save();
		tax = new Tax("20","","");
		tax->save();
	}
	Language::Init();
	if(Language::GetAll().count() < 1){
		Language* language = new Language("Arabic",":/erp_ar.qm","","");
		language->save();
	}
	User::Init();
	if(User::GetAll().count() < 1){
		User* user = new User("Default User","admin","admin",1,1,"","");
		user->save();
	}
	Contact::Init();
	ContactTelephone::Init();
	ContactEmail::Init();
	BankAccount::Init();
	ContactClass::Init();
	ContactType::Init();
	Country::Init();
	Currency::Init();
	ContactStatus::Init();
	FieldType::Init();
	ContactField::Init();
	ContactFieldData::Init();
	ContactPerson::Init();
	ContactPersonField::Init();
	ContactPersonFieldData::Init();

	ContactPersonTelephone::Init();
	ContactPersonEmail::Init();


	Unit::Init();
	if(Unit::GetAll().count() < 5){
		QList<QString> units;
		units << "Allowance" <<"Piece" << "Hour" << "Kilo" << "Meter" << "Liter" << "Millimeter" << "Gram" <<"ton" <<"kilometer"<<"Rollen"<<"LFM"<<"m²"<<"m³"<<"Box"<<"Ballen"<<"Rolle"<<"Sheet"<<"Palette"<<"VE";
		for(int i = 0;i < units.count(); i++){
			Unit* un = new Unit(units.at(i),"","");
			un->save();
		}
	}

	ProductCategory::Init();
	if(ProductCategory::GetAll().count() < 1){
		ProductCategory *poriductCat = new ProductCategory("General","","");
		poriductCat->save();
	}
	Product::Init();

	ProductImage::Init();
	ProductField::Init();
	ProductFieldData::Init();

	Service::Init();
	ProjectStatus::Init();
	if(ProjectStatus::GetAll().count() < 3){
		ProjectStatus *projectStatus = new ProjectStatus("Created","","");
		projectStatus->save();
		projectStatus = new ProjectStatus("In Progress","","");
		projectStatus->save();
		projectStatus = new ProjectStatus("Finished","","");
		projectStatus->save();
	}


	Project::Init();
	ProjectSales::Init();
	ProjectFile::Init();
	ProjectProduct::Init();
	ProjectService::Init();

	Store::Init();
	if(Store::GetAll().count() < 1){
		Store *store = new Store("WareHouse","","10001","Cairo",1,"","");
		store->save();
	}
	PurchaseStatus::Init();
	PurchaseSerial::Init();
	if(PurchaseSerial::GetAll().count() < 1){
		PurchaseSerial *purchaseserial = new PurchaseSerial("PURCHASE",1,"","");
		purchaseserial->save();
	}
	Purchase::Init();
	PurchaseStoreProduct::Init();
	PurchaseFreeLine::Init();
	DeliveryOrderStatus::Init();
	if(DeliveryOrderStatus::GetAll().count() < 3){
		DeliveryOrderStatus *deliveryOrderStatus = new DeliveryOrderStatus("In progress","","");
		deliveryOrderStatus->save();
		deliveryOrderStatus = new DeliveryOrderStatus("Delivered","","");
		deliveryOrderStatus->save();
		deliveryOrderStatus = new DeliveryOrderStatus("Canceled","","");
		deliveryOrderStatus->save();
	}
	DeliveryOrderSerial::Init();
	if(DeliveryOrderSerial::GetAll().count() < 1){
		DeliveryOrderSerial *deliveryOrderSerial = new DeliveryOrderSerial("DELV",1,"","");
		deliveryOrderSerial->save();
	}
	DeliveryOrder::Init();
	DeliveryOrderStoreProduct::Init();
	DeliveryOrderService::Init();
	DeliveryOrderFreeline::Init();
	InvoicePeriod::Init();
	InvoiceYear::Init();
	InvoiceState::Init();
	InvoiceSerial::Init();
	if(InvoiceSerial::GetAll().count() < 1){
		InvoiceSerial *invoiceSerial = new InvoiceSerial("INV",1,"","");
		invoiceSerial->save();
	}
	Invoice::Init();
	InvoiceStateDate::Init();

	InvoiceFreeline::Init();
	PaymentType::Init();
	Payment::Init();
	ContactPersonFieldData::Init();
	Task::Init();
	Access::Init();
	if(Access::GetAll().count() < 1){
		Access *access = new Access("Access Control",1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,"1",1,"","");
		access->save();
	}



	for(int i = 0; i < 10; i++){
		Contact* cont = new Contact("Contact"+QString::number(Contact::GetAll().count()),"Mr.",QDate::currentDate(),1,1,Contact::GetAll().count(),"AA","na","na",1,1,"na","na","na","na");
		cont->save();
	}
	for(int i = 0; i < 10; i++){
		Product* product = new Product("Product"+QString::number(Product::GetAll().count()),"ShortDescription",1,10,8,90,1,"information","98989898009",1,0,"date","date");
		product->save();
	}

	return true;
}

QList<QString> toStringList(QList<QPair< int,QString > > pairList){

	QList<QString> list;
	for(int i = 0; i < pairList.length(); i++){
	  list.append(pairList.at(i).second);
  }
	return list;
}
