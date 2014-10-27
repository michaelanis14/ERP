/**************************************************************************
**   File: bankaccountui.h
**   Created on: Mon Oct 27 11:26:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "bankaccountui.h"
#include "../MainWindow.h"
#include "../../Model/BankAccount.h"

BankAccountUI::BankAccountUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
ERPFormBlock* block0Layout = new ERPFormBlock;
QLineEdit*name = new QLineEdit();
block0Layout->addRow("Name",name);
QLineEdit*bankaddress = new QLineEdit();
block0Layout->addRow("Bank Address",bankaddress);
QLineEdit*bankcode = new QLineEdit();
block0Layout->addRow("Bank Code",bankcode);
QLineEdit*accountname = new QLineEdit();
block0Layout->addRow("Account Name",accountname);
QLineEdit*accountnumber = new QLineEdit();
block0Layout->addRow("Account Number",accountnumber);
QLineEdit*iban = new QLineEdit();
block0Layout->addRow("I B A N",iban);
QLineEdit*bic = new QLineEdit();
block0Layout->addRow("B I C",bic);
QLineEdit*zipcode = new QLineEdit();
block0Layout->addRow("Zip Code",zipcode);
ERPComboBox* currency = new ERPComboBox();
currency->addItems(Currency::GetStringList());
block0Layout->addRow("Currency",currency);
ERPComboBox* contact = new ERPComboBox();
contact->addItems(Contact::GetStringList());
block0Layout->addRow("Contact",contact);
ERPComboBox* country = new ERPComboBox();
country->addItems(Country::GetStringList());
block0Layout->addRow("Country",country);
QLineEdit*bankcountrycode = new QLineEdit();
block0Layout->addRow("Bank Country Code",bankcountrycode);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* BankAccountUI::p_instance = 0;
void BankAccountUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new BankAccountUI(mainwindow::GetMainDisplay());
	} 
	mainwindow::ShowDisplay(p_instance); 
}
BankAccountUI*BankAccountUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (BankAccountUI*) p_instance; 
}
