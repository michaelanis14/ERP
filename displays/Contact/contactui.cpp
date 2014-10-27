/**************************************************************************
**   File: contactui.h
**   Created on: Mon Oct 27 11:26:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactui.h"
#include "../MainWindow.h"
#include "../../Model/Contact.h"

ContactUI::ContactUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
ERPFormBlock* block0Layout = new ERPFormBlock;
QLineEdit*personalsalutation = new QLineEdit();
block0Layout->addRow("Personal Salutation",personalsalutation);
QLineEdit*salutation = new QLineEdit();
block0Layout->addRow("Salutation",salutation);
QLineEdit*name = new QLineEdit();
block0Layout->addRow("Name",name);
QLineEdit*lastname = new QLineEdit();
block0Layout->addRow("Last Name",lastname);
QLineEdit*birthdateordateoffoundation = new QLineEdit();
block0Layout->addRow("Birthdate Or Date Of Foundation",birthdateordateoffoundation);
flowLayout->addWidget(block0Layout);

ERPFormBlock* block1Layout = new ERPFormBlock;
ERPComboBox* contacttype = new ERPComboBox();
contacttype->addItems(ContactType::GetStringList());
block1Layout->addRow("Contact Type",contacttype);
ERPComboBox* contactclass = new ERPComboBox();
contactclass->addItems(ContactClass::GetStringList());
block1Layout->addRow("Contact Class",contactclass);
QLineEdit*contactnumber = new QLineEdit();
contactnumber->setValidator( intValidator );
block1Layout->addRow("Contact Number",contactnumber);
flowLayout->addWidget(block1Layout);

ERPFormBlock* block2Layout = new ERPFormBlock;
QLineEdit*address = new QLineEdit();
block2Layout->addRow("Address",address);
QLineEdit*postalcode = new QLineEdit();
block2Layout->addRow("Postal Code",postalcode);
QLineEdit*city = new QLineEdit();
block2Layout->addRow("City",city);
ERPComboBox* country = new ERPComboBox();
country->addItems(Country::GetStringList());
block2Layout->addRow("Country",country);
flowLayout->addWidget(block2Layout);

ERPFormBlock* block3Layout = new ERPFormBlock;
ERPComboBox* contactstatus = new ERPComboBox();
contactstatus->addItems(ContactStatus::GetStringList());
block3Layout->addRow("Contact Status",contactstatus);
QCheckBox* active = new QCheckBox();
block3Layout->addRow("Active",active);
ERPComboBox* employee = new ERPComboBox();
employee->addItems(Employee::GetStringList());
block3Layout->addRow("Employee",employee);
flowLayout->addWidget(block3Layout);

ERPFormBlock* block4Layout = new ERPFormBlock;
QLineEdit*phonenum = new QLineEdit();
block4Layout->addRow("Phone Num",phonenum);
QLineEdit*phonenum2 = new QLineEdit();
block4Layout->addRow("Phone Num2",phonenum2);
QLineEdit*fax = new QLineEdit();
block4Layout->addRow("Fax",fax);
QLineEdit*mobile = new QLineEdit();
block4Layout->addRow("Mobile",mobile);
QLineEdit*email = new QLineEdit();
block4Layout->addRow("Email",email);
QLineEdit*email2 = new QLineEdit();
block4Layout->addRow("Email2",email2);
QLineEdit*website = new QLineEdit();
block4Layout->addRow("webSite",website);
QLineEdit*taxnumber = new QLineEdit();
block4Layout->addRow("Tax Number",taxnumber);

//BankAccounts =  QList<BankAccount*>();
BankAccountUI* bankui = new BankAccountUI();
BankAccounts.append(bankui);
//block4Layout->addRow("Created On",createdon);
//QHbox lay out
// labels with
AddRemoveButtons* addrem = new AddRemoveButtons();
block4Layout->addWidget(addrem);
block4Layout->addWidget(bankui);
QObject::connect(addrem, SIGNAL(addPressed()), this, SLOT(addBankAccount()));
QObject::connect(addrem, SIGNAL(removePressed()), this, SLOT(removeBankAccount()));
flowLayout->addWidget(block4Layout);

block5Layout = new ERPFormBlock;
AddRemoveButtons* addremoveButtons = new AddRemoveButtons();
block5Layout->addWidget(addremoveButtons);
block5Layout->addRow("Tax Number",taxnumber);
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
BankAccounts.append(bankaccountui);
block5Layout->addWidget(bankaccountui);
mainwindow::GetMainDisplay()->updateSize();
}
void ContactUI::removeBankAccount(){
if(BankAccounts.count()  > 0){
BankAccountUI* bankaccountui = BankAccounts.takeLast();
BankAccounts.append(bankaccountui);
block5Layout->boxLayout->removeWidget(bankaccountui);
delete bankaccountui;
mainwindow::GetMainDisplay()->updateSize();
}
}
