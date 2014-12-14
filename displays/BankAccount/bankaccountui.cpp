/**************************************************************************
**   File: bankaccountui.cpp
**   Created on: Sat Dec 13 21:50:44 EET 2014
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
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block0Layout->setMinimumWidth(330);
name = new QLineEdit();
QStringList* list = new QStringList(BankAccount::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectBankAccount()));
block0Layout->addRow(QObject::tr("Name"),name);
country = new ERPComboBox();
country->addItems(Country::GetPairList());
block0Layout->addRow(QObject::tr("Country"),country);
bankcode = new QLineEdit();
block0Layout->addRow(QObject::tr("Bank Code"),bankcode);
bankaddress = new QLineEdit();
block0Layout->addRow(QObject::tr("Bank Address"),bankaddress);
accountnumber = new QLineEdit();
block0Layout->addRow(QObject::tr("Account Number"),accountnumber);
accountowner = new QLineEdit();
block0Layout->addRow(QObject::tr("Account Owner"),accountowner);
iban = new QLineEdit();
block0Layout->addRow(QObject::tr("I B A N"),iban);
bic = new QLineEdit();
block0Layout->addRow(QObject::tr("B I C"),bic);
currency = new ERPComboBox();
currency->addItems(Currency::GetPairList());
block0Layout->addRow(QObject::tr("Currency"),currency);
contact = new ERPComboBox();
contact->addItems(Contact::GetPairList());
block0Layout->addRow(QObject::tr("Contact"),contact);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* BankAccountUI::p_instance = 0;
void BankAccountUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new BankAccountUI(mainwindow::GetMainDisplay()); 
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
bankcode->setText(bankaccount->BankCode);
bankaddress->setText(bankaccount->BankAddress);
accountnumber->setText(bankaccount->AccountNumber);
accountowner->setText(bankaccount->AccountOwner);
iban->setText(bankaccount->IBAN);
bic->setText(bankaccount->BIC);
} 
void BankAccountUI::clear(){ 
delete this->bankaccount;
bankcode->setText("");
bankaddress->setText("");
accountnumber->setText("");
accountowner->setText("");
iban->setText("");
bic->setText("");
this->bankaccount = new BankAccount();
} 
void BankAccountUI::selectBankAccount(){ 
if(BankAccount::GetStringList().contains(this->bankaccount->Name))
{
BankAccount* con = BankAccount::Get(this->bankaccount->Name);
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
if(!country->isHidden()) 
bankaccount->CountryID = country->getKey();
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
if(accountowner->text().trimmed().isEmpty()){
errors = true;
errorString += "Account Owner Can't be Empty! \n";
accountowner->setObjectName("error");
accountowner->style()->unpolish(accountowner);
accountowner->style()->polish(accountowner);
accountowner->update();
}
else { 
accountowner->setObjectName("accountowner");
accountowner->style()->unpolish(accountowner);
accountowner->style()->polish(accountowner);
accountowner->update();
bankaccount->AccountOwner = accountowner->text().trimmed();
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
if(!currency->isHidden()) 
bankaccount->CurrencyID = currency->getKey();
if(!contact->isHidden()) 
bankaccount->ContactID = contact->getKey();
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
bool BankAccountUI::updateModel(){ 
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
if(bankaccount->CountryID == 0) 
bankaccount->CountryID = country->getKey();
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
if(accountowner->text().trimmed().isEmpty()){
errors = true;
errorString += "Account Owner Can't be Empty! \n";
accountowner->setObjectName("error");
accountowner->style()->unpolish(accountowner);
accountowner->style()->polish(accountowner);
accountowner->update();
}
else { 
accountowner->setObjectName("accountowner");
accountowner->style()->unpolish(accountowner);
accountowner->style()->polish(accountowner);
accountowner->update();
bankaccount->AccountOwner = accountowner->text().trimmed();
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
if(bankaccount->CurrencyID == 0) 
bankaccount->CurrencyID = currency->getKey();
if(bankaccount->ContactID == 0) 
bankaccount->ContactID = contact->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, "BankAccount",errorString.trimmed());
return false; 
 }
}
