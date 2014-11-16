/**************************************************************************
**   File: bankaccountui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "bankaccountui.h"
#include "../MainWindow.h"

BankAccountUI::BankAccountUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
ERPFormBlock * blockSaveCancel = new ERPFormBlock;
 QWidget* addremove = new QWidget();
 QHBoxLayout* addRemovelayout = new QHBoxLayout(addremove);
 addRemovelayout->setContentsMargins(0,0,0,0);
 QPushButton* save = new QPushButton("Save");
 QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
 save->setObjectName("save");
 QPushButton* cancel = new QPushButton("Cancel");
 cancel->setObjectName("cancel");
 QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
 QPushButton* clear = new QPushButton("Clear");
 QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
 clear->setObjectName("clear");
 addRemovelayout->addStretch(1);
 addRemovelayout->addWidget(save,0,Qt::AlignCenter);
 addRemovelayout->addStretch(0);
 addRemovelayout->addWidget(clear,0,Qt::AlignCenter);
 addRemovelayout->addWidget(cancel,0,Qt::AlignCenter);
 addRemovelayout->addStretch(1);
 blockSaveCancel->addRow("",addremove);
 flowLayout->addWidget(blockSaveCancel);
block0Layout = new ERPFormBlock;
name = new QLineEdit();
QStringList* list = new QStringList(BankAccount::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectBankAccount()));
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
currency->addItems(Currency::GetHashList());
block0Layout->addRow("Currency",currency);
contact = new ERPComboBox();
contact->addItems(Contact::GetHashList());
block0Layout->addRow("Contact",contact);
country = new ERPComboBox();
country->addItems(Country::GetHashList());
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
this->bankaccount = bankaccount;
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
void BankAccountUI::clear(){ 
bankaddress->setText("");
bankcode->setText("");
accountname->setText("");
accountnumber->setText("");
iban->setText("");
bic->setText("");
zipcode->setText("");
bankcountrycode->setText("");
this->bankaccount = new BankAccount();
} 
void BankAccountUI::selectBankAccount(){ 
if(BankAccount::GetStringList().contains(name->text()))
{
BankAccount* con = BankAccount::Get(name->text());
if(this->bankaccount->BankAccountID != con->BankAccountID){
this->bankaccount = con;
fill(this->bankaccount);
}
}
else if(bankaccount->BankAccountID != 0)
clear();
}
void BankAccountUI::save(){ 
bankaccount->Name = name->text();
bankaccount->BankAddress = bankaddress->text();
bankaccount->BankCode = bankcode->text();
bankaccount->AccountName = accountname->text();
bankaccount->AccountNumber = accountnumber->text();
bankaccount->IBAN = iban->text();
bankaccount->BIC = bic->text();
bankaccount->ZipCode = zipcode->text();
if(bankaccount->CurrencyID == 0) 
bankaccount->CurrencyID = currency->getKey();
if(bankaccount->ContactID == 0) 
bankaccount->ContactID = contact->getKey();
if(bankaccount->CountryID == 0) 
bankaccount->CountryID = country->getKey();
bankaccount->BankCountryCode = bankcountrycode->text();
bankaccount->save();
BankAccountIndexUI::ShowUI();
}
void BankAccountUI::cancel(){ 
BankAccountIndexUI::ShowUI();
}
