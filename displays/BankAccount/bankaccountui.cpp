/**************************************************************************
**   File: bankaccountui.cpp
**   Created on: Wed Nov 05 13:58:50 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "bankaccountui.h"
#include "../MainWindow.h"

BankAccountUI::BankAccountUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(this);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
block0Layout = new ERPFormBlock;
name = new QLineEdit();
block0Layout->addRow("Name",name);
bankaddress = new QLineEdit();
block0Layout->addRow("Bank Address",bankaddress);
bankcode = new QLineEdit();
block0Layout->addRow("Bank Code",bankcode);
accountname = new QLineEdit();
block0Layout->addRow("Account Name",accountname);
accountnumber = new QLineEdit();
block0Layout->addRow("Account Number",accountnumber);
iban = new QLineEdit();
block0Layout->addRow("I B A N",iban);
bic = new QLineEdit();
block0Layout->addRow("B I C",bic);
zipcode = new QLineEdit();
block0Layout->addRow("Zip Code",zipcode);
currency = new ERPComboBox();
currency->addItems(Currency::GetStringList());
block0Layout->addRow("Currency",currency);
contact = new ERPComboBox();
contact->addItems(Contact::GetStringList());
block0Layout->addRow("Contact",contact);
country = new ERPComboBox();
country->addItems(Country::GetStringList());
block0Layout->addRow("Country",country);
bankcountrycode = new QLineEdit();
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
void BankAccountUI::fill(BankAccount* bankaccount){
name->setText(bankaccount->Name);
bankaddress->setText(bankaccount->BankAddress);
bankcode->setText(bankaccount->BankCode);
accountname->setText(bankaccount->AccountName);
accountnumber->setText(bankaccount->AccountNumber);
iban->setText(bankaccount->IBAN);
bic->setText(bankaccount->BIC);
zipcode->setText(bankaccount->ZipCode);
bankcountrycode->setText(bankaccount->BankCountryCode);
}
