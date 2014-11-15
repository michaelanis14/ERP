/*************************************
**   Created on:  9/11/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpmodel.h"
#include "user.h"
#include "contacttype.h"
#include "contactclass.h"
#include "contactstatus.h"
#include "employee.h"
#include "contact.h"
#include "country.h"
#include "currency.h"

#include <QSql>
#include <QSqlDatabase>

#include <QSqlError>
#include <QDebug>

ErpModel::ErpModel()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("testqt");
	db.setUserName("root");
	//       db.setPassword("root");


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
			qDebug() << query.lastError().text();
		else
			qDebug() << q +"Exec: " +QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch() - startTime.toMSecsSinceEpoch()) +"ms";
		db.close();
		return query;
	}
	else    {
		qDebug() << "Something went Wrong:" << db.lastError().text();
		QSqlQuery query;
		return query;
	}
}

bool ErpModel::createTable(QString table,QString query){

	if(db.open())   {
		QStringList tableList = ErpModel::GetInstance()->db.tables();;


		db.close();
		bool tableExists = false;

		for(int i=0; i<tableList.count(); i++)
		{
			if(table == tableList.at(i)){
				tableExists=true;
				break;
			}
		}
		if(tableExists == false)
		{
			ErpModel::GetInstance()->qeryExec("CREATE TABLE " + table + query);
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
			Country* country = new Country(countries.at(i),"","");
			country->save();
		}
	}
	Employee::Init();
	if(Employee::GetAll().count() < 2){
		Employee* employee = new Employee("Mwzaf"+QString::number(Employee::GetAll().count()),"","");
		employee->save();
	}
	User::Init();
	if(User::GetAll().count() < 2){
		User* user = new User("User"+QString::number(User::GetAll().count()),"username","password","5/5/5",1,1,"192.168.1.1","","");
		user->save();
	}
	Contact::Init();
	if(Contact::GetAll().count() < 5){
	Contact* cont = new Contact("7abibi","Mr.","Abaaas"+QString::number(Contact::GetAll().count()),"AbnAbaas","5/5/5",1,1,1,"AA","na"
									,"na",1,1,1,1,"na","na","na","na","na","na","na","na"
									"na","na","nnna");
		cont->save();

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
	BankAccount::Init();


	return true;
}
