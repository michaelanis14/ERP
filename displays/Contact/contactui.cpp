/**************************************************************************
**   File: contactui.cpp
**   Created on: Thu Nov 06 01:32:13 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactui.h"
#include "../MainWindow.h"

ContactUI::ContactUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
block0Layout = new ERPFormBlock;

QWidget* addremove = new QWidget();
QHBoxLayout* addRemovelayout = new QHBoxLayout(addremove);
addRemovelayout->setContentsMargins(0,0,0,0);
QPushButton* save = new QPushButton("Save");
QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
save->setObjectName("save");
QPushButton* cancel = new QPushButton("Cancel");
cancel->setObjectName("cancel");
QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));

//save->setEnabled(false);


addRemovelayout->addStretch(1);
addRemovelayout->addWidget(save,0,Qt::AlignCenter);
addRemovelayout->addStretch(0);
addRemovelayout->addWidget(cancel,0,Qt::AlignCenter);
addRemovelayout->addStretch(1);
block0Layout->addRow("",addremove);

personalsalutation = new QLineEdit();
block0Layout->addRow("Personal Salutation",personalsalutation);
salutation = new QLineEdit();
block0Layout->addRow("Salutation",salutation);
name = new QLineEdit();
QStringList* list = new QStringList(Contact::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectContact()));
block0Layout->addRow("Name",name);
lastname = new QLineEdit();
block0Layout->addRow("Last Name",lastname);
birthdateordateoffoundation = new QLineEdit();
block0Layout->addRow("Birthdate Or Date Of Foundation",birthdateordateoffoundation);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
contacttype = new ERPComboBox();
contacttype->addItems(ContactType::GetStringList());
block1Layout->addRow("Contact Type",contacttype);
contactclass = new ERPComboBox();
contactclass->addItems(ContactClass::GetStringList());
block1Layout->addRow("Contact Class",contactclass);
contactnumber = new QLineEdit();
contactnumber->setValidator( intValidator );
block1Layout->addRow("Contact Number",contactnumber);
flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
address = new QLineEdit();
block2Layout->addRow("Address",address);
postalcode = new QLineEdit();
block2Layout->addRow("Postal Code",postalcode);
city = new QLineEdit();
block2Layout->addRow("City",city);
country = new ERPComboBox();
country->addItems(Country::GetStringList());
block2Layout->addRow("Country",country);
flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
contactstatus = new ERPComboBox();
contactstatus->addItems(ContactStatus::GetStringList());
block3Layout->addRow("Contact Status",contactstatus);
active = new QCheckBox();
block3Layout->addRow("Active",active);
employee = new ERPComboBox();
employee->addItems(Employee::GetStringList());
block3Layout->addRow("Employee",employee);
flowLayout->addWidget(block3Layout);

block4Layout = new ERPFormBlock;
phonenum = new QLineEdit();
block4Layout->addRow("Phone Num",phonenum);
phonenum2 = new QLineEdit();
block4Layout->addRow("Phone Num2",phonenum2);
fax = new QLineEdit();
block4Layout->addRow("Fax",fax);
mobile = new QLineEdit();
block4Layout->addRow("Mobile",mobile);
email = new QLineEdit();
block4Layout->addRow("Email",email);
email2 = new QLineEdit();
block4Layout->addRow("Email2",email2);
website = new QLineEdit();
block4Layout->addRow("webSite",website);
taxnumber = new QLineEdit();
block4Layout->addRow("Tax Number",taxnumber);
flowLayout->addWidget(block4Layout);

block5Layout = new ERPFormBlock;
AddRemoveButtons* addremoveButtons = new AddRemoveButtons();
block5Layout->addWidget(addremoveButtons);
QObject::connect(addremoveButtons, SIGNAL(addPressed()), this, SLOT(addBankAccount()));
QObject::connect(addremoveButtons, SIGNAL(removePressed()), this, SLOT(removeBankAccount()));
BankAccountUI* bankaccountui = new BankAccountUI();
BankAccounts.append(bankaccountui);
block5Layout->addWidget(bankaccountui);




flowLayout->addWidget(block5Layout);


}
ERPDisplay* ContactUI::p_instance = 0;
void ContactUI::ShowUI() {
	if (p_instance == 0) {
		p_instance = new ContactUI(mainwindow::GetMainDisplay());
	}
	mainwindow::ShowDisplay(p_instance);
}
ContactUI*ContactUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (ContactUI*) p_instance;
}
void ContactUI::addBankAccount(){
BankAccountUI* bankaccountui = new BankAccountUI();
bankaccountui->block0Layout->removeRow(bankaccountui->contact);
BankAccounts.append(bankaccountui);
block5Layout->addWidget(bankaccountui);
mainwindow::GetMainDisplay()->updateSize();
}
void ContactUI::addBankAccount(BankAccount* BankAccount){
BankAccountUI* bankaccountui = new BankAccountUI();
bankaccountui->block0Layout->removeRow(bankaccountui->contact);
bankaccountui->fill(BankAccount);
BankAccounts.append(bankaccountui);
block5Layout->addWidget(bankaccountui);
mainwindow::GetMainDisplay()->updateSize();
}
void ContactUI::removeBankAccount(){
if(BankAccounts.count()  > 0){
BankAccountUI* bankaccountui = BankAccounts.takeLast();
block5Layout->boxLayout->removeWidget(bankaccountui);
delete bankaccountui;
mainwindow::GetMainDisplay()->updateSize();
}
}
void ContactUI::fill(Contact* contact){
personalsalutation->setText(contact->PersonalSalutation);
salutation->setText(contact->Salutation);
name->setText(contact->Name);
lastname->setText(contact->LastName);
birthdateordateoffoundation->setText(contact->BirthdateOrDateOfFoundation);
contactnumber->setText(QString::number(contact->ContactNumber));
address->setText(contact->Address);
postalcode->setText(contact->PostalCode);
city->setText(contact->City);
active->setChecked(contact->Active);
phonenum->setText(contact->PhoneNum);
phonenum2->setText(contact->PhoneNum2);
fax->setText(contact->Fax);
mobile->setText(contact->Mobile);
email->setText(contact->Email);
email2->setText(contact->Email2);
website->setText(contact->webSite);
taxnumber->setText(contact->TaxNumber);
foreach(BankAccountUI* bankaccount, BankAccounts) removeBankAccount();
foreach(BankAccount* bankaccount, contact->bankaccounts) {
addBankAccount(bankaccount);
}
}
void ContactUI::clear(){
personalsalutation->setText("");
salutation->setText("");
lastname->setText("");
birthdateordateoffoundation->setText("");
contactnumber->setText("");
address->setText("");
postalcode->setText("");
city->setText("");
active->setChecked(false);
phonenum->setText("");
phonenum2->setText("");
fax->setText("");
mobile->setText("");
email->setText("");
email2->setText("");
website->setText("");
taxnumber->setText("");
foreach(BankAccountUI* bankaccount, BankAccounts) removeBankAccount();
this->contact = new Contact();
}
void ContactUI::selectContact(){
if(Contact::GetStringList().contains(name->text()))
{
Contact* con = Contact::get(name->text());
if(this->contact->ContactID != con->ContactID){
this->contact = con;
fill(this->contact);
}
}
else if(contact->ContactID != 0)
clear();
}
void ContactUI::save(){
	contact->save();
}
void ContactUI::cancel(){
	contactIndexUI::ShowUI();
}
