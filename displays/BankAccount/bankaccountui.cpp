/**************************************************************************
**   File: bankaccountui.cpp
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "bankaccountui.h"
#include "../MainWindow.h"

BankAccountUI::BankAccountUI(QWidget *parent) :ERPDisplay(parent)
{

bankaccount = new BankAccount();
flowLayout = new FlowLayout(this);
flowLayout->setContentsMargins(0,0,0,0);

QPushButton* save = new QPushButton("Save");
 QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
 save->setObjectName("save");
 QPushButton* cancel = new QPushButton("Cancel");
 cancel->setObjectName("cancel");
 QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
 QPushButton* clear = new QPushButton("Clear");
 QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
 clear->setObjectName("clear");
 this->controllers->addControllerButton(save);
 this->controllers->addControllerButton(clear);
 this->controllers->addControllerButton(cancel);
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
clear();
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
delete this->bankaccount;
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
fill(con);
}
}
else if(bankaccount->BankAccountID != 0)
clear();
}
bool BankAccountUI::save(){
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += "Name Can't be Empty! \n";
name->setObjectName("error");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
}
else {
name->setObjectName("name");
name->style()->unpolish(name);
name->style()->polish(name);
name->update();
bankaccount->Name = name->text().trimmed();
}
if(bankaddress->text().trimmed().isEmpty()){
errors = true;
errorString += "Bank Address Can't be Empty! \n";
bankaddress->setObjectName("error");
bankaddress->style()->unpolish(bankaddress);
bankaddress->style()->polish(bankaddress);
bankaddress->update();
}
else {
bankaddress->setObjectName("bankaddress");
bankaddress->style()->unpolish(bankaddress);
bankaddress->style()->polish(bankaddress);
bankaddress->update();
bankaccount->BankAddress = bankaddress->text().trimmed();
}
if(bankcode->text().trimmed().isEmpty()){
errors = true;
errorString += "Bank Code Can't be Empty! \n";
bankcode->setObjectName("error");
bankcode->style()->unpolish(bankcode);
bankcode->style()->polish(bankcode);
bankcode->update();
}
else {
bankcode->setObjectName("bankcode");
bankcode->style()->unpolish(bankcode);
bankcode->style()->polish(bankcode);
bankcode->update();
bankaccount->BankCode = bankcode->text().trimmed();
}
if(accountname->text().trimmed().isEmpty()){
errors = true;
errorString += "Account Name Can't be Empty! \n";
accountname->setObjectName("error");
accountname->style()->unpolish(accountname);
accountname->style()->polish(accountname);
accountname->update();
}
else {
accountname->setObjectName("accountname");
accountname->style()->unpolish(accountname);
accountname->style()->polish(accountname);
accountname->update();
bankaccount->AccountName = accountname->text().trimmed();
}
if(accountnumber->text().trimmed().isEmpty()){
errors = true;
errorString += "Account Number Can't be Empty! \n";
accountnumber->setObjectName("error");
accountnumber->style()->unpolish(accountnumber);
accountnumber->style()->polish(accountnumber);
accountnumber->update();
}
else {
accountnumber->setObjectName("accountnumber");
accountnumber->style()->unpolish(accountnumber);
accountnumber->style()->polish(accountnumber);
accountnumber->update();
bankaccount->AccountNumber = accountnumber->text().trimmed();
}
if(iban->text().trimmed().isEmpty()){
errors = true;
errorString += "I B A N Can't be Empty! \n";
iban->setObjectName("error");
iban->style()->unpolish(iban);
iban->style()->polish(iban);
iban->update();
}
else {
iban->setObjectName("iban");
iban->style()->unpolish(iban);
iban->style()->polish(iban);
iban->update();
bankaccount->IBAN = iban->text().trimmed();
}
if(bic->text().trimmed().isEmpty()){
errors = true;
errorString += "B I C Can't be Empty! \n";
bic->setObjectName("error");
bic->style()->unpolish(bic);
bic->style()->polish(bic);
bic->update();
}
else {
bic->setObjectName("bic");
bic->style()->unpolish(bic);
bic->style()->polish(bic);
bic->update();
bankaccount->BIC = bic->text().trimmed();
}
if(zipcode->text().trimmed().isEmpty()){
errors = true;
errorString += "Zip Code Can't be Empty! \n";
zipcode->setObjectName("error");
zipcode->style()->unpolish(zipcode);
zipcode->style()->polish(zipcode);
zipcode->update();
}
else {
zipcode->setObjectName("zipcode");
zipcode->style()->unpolish(zipcode);
zipcode->style()->polish(zipcode);
zipcode->update();
bankaccount->ZipCode = zipcode->text().trimmed();
}
if(bankaccount->CurrencyID == 0)
bankaccount->CurrencyID = currency->getKey();
if(bankaccount->ContactID == 0)
bankaccount->ContactID = contact->getKey();
if(bankaccount->CountryID == 0)
bankaccount->CountryID = country->getKey();
if(bankcountrycode->text().trimmed().isEmpty()){
errors = true;
errorString += "Bank Country Code Can't be Empty! \n";
bankcountrycode->setObjectName("error");
bankcountrycode->style()->unpolish(bankcountrycode);
bankcountrycode->style()->polish(bankcountrycode);
bankcountrycode->update();
}
else {
bankcountrycode->setObjectName("bankcountrycode");
bankcountrycode->style()->unpolish(bankcountrycode);
bankcountrycode->style()->polish(bankcountrycode);
bankcountrycode->update();
bankaccount->BankCountryCode = bankcountrycode->text().trimmed();
}
if(!errors) {
bankaccount->save();
if(!errors){
BankAccountIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "BankAccount",errorString.trimmed());
return false;
 }
}
void BankAccountUI::cancel(){
BankAccountIndexUI::ShowUI();
}
