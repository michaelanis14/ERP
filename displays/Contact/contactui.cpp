/**************************************************************************
**   File: contactui.cpp
**   Created on: Wed Nov 26 16:22:56 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactui.h"
#include "../MainWindow.h"

ContactUI::ContactUI(QWidget *parent) :ERPDisplay(parent)
{

contact = new Contact();
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);

QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
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
contacttype->addItems(ContactType::GetHashList());
block1Layout->addRow("Contact Type",contacttype);
contactclass = new ERPComboBox();
contactclass->addItems(ContactClass::GetHashList());
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
country->addItems(Country::GetHashList());
block2Layout->addRow("Country",country);
flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
contactstatus = new ERPComboBox();
contactstatus->addItems(ContactStatus::GetHashList());
block3Layout->addRow("Contact Status",contactstatus);
active = new QCheckBox();
block3Layout->addRow("Active",active);
employee = new ERPComboBox();
employee->addItems(Employee::GetHashList());
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
block5Layout->addRow("BankAccounts",addremoveButtons);
QObject::connect(addremoveButtons, SIGNAL(addPressed()), this, SLOT(addBankAccount()));

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
bankaccountui->controllers->setFixedHeight(0);
BankAccounts.append(bankaccountui);
RemovebtnWidgets* rmbankaccount = new RemovebtnWidgets(0,bankaccountui);
QObject::connect(rmbankaccount, SIGNAL(removePressed(QWidget*)), this, SLOT(removeBankAccount(QWidget*)));
block5Layout->addRow("BankAccount"+QString::number(BankAccounts.count()),rmbankaccount);
//mainwindow::GetMainDisplay()->updateSize();
}
void ContactUI::addBankAccount(BankAccount* BankAccount){
BankAccountUI* bankaccountui = new BankAccountUI();
bankaccountui->block0Layout->removeRow(bankaccountui->contact);
bankaccountui->controllers->setFixedHeight(0);
bankaccountui->fill(BankAccount);
BankAccounts.append(bankaccountui);
RemovebtnWidgets* rmbankaccount = new RemovebtnWidgets(0,bankaccountui);
QObject::connect(rmbankaccount, SIGNAL(removePressed(QWidget*)), this, SLOT(removeBankAccount(QWidget*)));
block5Layout->addRow("BankAccount"+QString::number(BankAccounts.count()),rmbankaccount);
mainwindow::GetMainDisplay()->updateSize();
}
void ContactUI::removeBankAccount(QWidget* widget){
if(BankAccounts.count()  > 0){
BankAccountUI* bankaccountui = (BankAccountUI*) widget;
BankAccounts.removeOne(bankaccountui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block5Layout->removeRow(sender);
//mainwindow::GetMainDisplay()->updateSize();
}
}
void ContactUI::fill(Contact* contact){
clear();
this->contact = contact;
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
foreach(BankAccount* bankaccount, contact->bankaccounts) {
addBankAccount(bankaccount);
}
}
void ContactUI::clear(){
delete this->contact;
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
QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
foreach(RemovebtnWidgets * child, RWidgets)
{
if(child->parent()->parent()->parent() != 0)
((ERPFormBlock*)child->parent()->parent())->removeRow(child);
}
this->contact = new Contact();
}
void ContactUI::selectContact(){
if(Contact::GetStringList().contains(name->text()))
{
Contact* con = Contact::Get(name->text());
if(this->contact->ContactID != con->ContactID){
fill(con);
}
}
else if(contact->ContactID != 0)
clear();
}
bool ContactUI::save(){
bool errors = false;
QString errorString =  "";
if(personalsalutation->text().trimmed().isEmpty()){
errors = true;
errorString += "Personal Salutation Can't be Empty! \n";
personalsalutation->setObjectName("error");
personalsalutation->style()->unpolish(personalsalutation);
personalsalutation->style()->polish(personalsalutation);
personalsalutation->update();
}
else {
personalsalutation->setObjectName("personalsalutation");
personalsalutation->style()->unpolish(personalsalutation);
personalsalutation->style()->polish(personalsalutation);
personalsalutation->update();
contact->PersonalSalutation = personalsalutation->text().trimmed();
}
if(salutation->text().trimmed().isEmpty()){
errors = true;
errorString += "Salutation Can't be Empty! \n";
salutation->setObjectName("error");
salutation->style()->unpolish(salutation);
salutation->style()->polish(salutation);
salutation->update();
}
else {
salutation->setObjectName("salutation");
salutation->style()->unpolish(salutation);
salutation->style()->polish(salutation);
salutation->update();
contact->Salutation = salutation->text().trimmed();
}
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
contact->Name = name->text().trimmed();
}
if(lastname->text().trimmed().isEmpty()){
errors = true;
errorString += "Last Name Can't be Empty! \n";
lastname->setObjectName("error");
lastname->style()->unpolish(lastname);
lastname->style()->polish(lastname);
lastname->update();
}
else {
lastname->setObjectName("lastname");
lastname->style()->unpolish(lastname);
lastname->style()->polish(lastname);
lastname->update();
contact->LastName = lastname->text().trimmed();
}
if(birthdateordateoffoundation->text().trimmed().isEmpty()){
errors = true;
errorString += "Birthdate Or Date Of Foundation Can't be Empty! \n";
birthdateordateoffoundation->setObjectName("error");
birthdateordateoffoundation->style()->unpolish(birthdateordateoffoundation);
birthdateordateoffoundation->style()->polish(birthdateordateoffoundation);
birthdateordateoffoundation->update();
}
else {
birthdateordateoffoundation->setObjectName("birthdateordateoffoundation");
birthdateordateoffoundation->style()->unpolish(birthdateordateoffoundation);
birthdateordateoffoundation->style()->polish(birthdateordateoffoundation);
birthdateordateoffoundation->update();
contact->BirthdateOrDateOfFoundation = birthdateordateoffoundation->text().trimmed();
}
if(contact->ContactTypeID == 0)
contact->ContactTypeID = contacttype->getKey();
if(contact->ContactClassID == 0)
contact->ContactClassID = contactclass->getKey();
if(contactnumber->text().trimmed().isEmpty()){
errors = true;
errorString += "Contact Number Can't be Empty! \n";
contactnumber->setObjectName("error");
contactnumber->style()->unpolish(contactnumber);
contactnumber->style()->polish(contactnumber);
contactnumber->update();
}
else {
contactnumber->setObjectName("contactnumber");
contactnumber->style()->unpolish(contactnumber);
contactnumber->style()->polish(contactnumber);
contactnumber->update();
contact->ContactNumber = contactnumber->text().trimmed().toInt();
}
if(address->text().trimmed().isEmpty()){
errors = true;
errorString += "Address Can't be Empty! \n";
address->setObjectName("error");
address->style()->unpolish(address);
address->style()->polish(address);
address->update();
}
else {
address->setObjectName("address");
address->style()->unpolish(address);
address->style()->polish(address);
address->update();
contact->Address = address->text().trimmed();
}
if(postalcode->text().trimmed().isEmpty()){
errors = true;
errorString += "Postal Code Can't be Empty! \n";
postalcode->setObjectName("error");
postalcode->style()->unpolish(postalcode);
postalcode->style()->polish(postalcode);
postalcode->update();
}
else {
postalcode->setObjectName("postalcode");
postalcode->style()->unpolish(postalcode);
postalcode->style()->polish(postalcode);
postalcode->update();
contact->PostalCode = postalcode->text().trimmed();
}
if(city->text().trimmed().isEmpty()){
errors = true;
errorString += "City Can't be Empty! \n";
city->setObjectName("error");
city->style()->unpolish(city);
city->style()->polish(city);
city->update();
}
else {
city->setObjectName("city");
city->style()->unpolish(city);
city->style()->polish(city);
city->update();
contact->City = city->text().trimmed();
}
if(contact->CountryID == 0)
contact->CountryID = country->getKey();
if(contact->ContactStatusID == 0)
contact->ContactStatusID = contactstatus->getKey();
contact->Active = active->text().trimmed().toInt();
if(contact->EmployeeID == 0)
contact->EmployeeID = employee->getKey();
if(phonenum->text().trimmed().isEmpty()){
errors = true;
errorString += "Phone Num Can't be Empty! \n";
phonenum->setObjectName("error");
phonenum->style()->unpolish(phonenum);
phonenum->style()->polish(phonenum);
phonenum->update();
}
else {
phonenum->setObjectName("phonenum");
phonenum->style()->unpolish(phonenum);
phonenum->style()->polish(phonenum);
phonenum->update();
contact->PhoneNum = phonenum->text().trimmed();
}
if(phonenum2->text().trimmed().isEmpty()){
errors = true;
errorString += "Phone Num2 Can't be Empty! \n";
phonenum2->setObjectName("error");
phonenum2->style()->unpolish(phonenum2);
phonenum2->style()->polish(phonenum2);
phonenum2->update();
}
else {
phonenum2->setObjectName("phonenum2");
phonenum2->style()->unpolish(phonenum2);
phonenum2->style()->polish(phonenum2);
phonenum2->update();
contact->PhoneNum2 = phonenum2->text().trimmed();
}
if(fax->text().trimmed().isEmpty()){
errors = true;
errorString += "Fax Can't be Empty! \n";
fax->setObjectName("error");
fax->style()->unpolish(fax);
fax->style()->polish(fax);
fax->update();
}
else {
fax->setObjectName("fax");
fax->style()->unpolish(fax);
fax->style()->polish(fax);
fax->update();
contact->Fax = fax->text().trimmed();
}
if(mobile->text().trimmed().isEmpty()){
errors = true;
errorString += "Mobile Can't be Empty! \n";
mobile->setObjectName("error");
mobile->style()->unpolish(mobile);
mobile->style()->polish(mobile);
mobile->update();
}
else {
mobile->setObjectName("mobile");
mobile->style()->unpolish(mobile);
mobile->style()->polish(mobile);
mobile->update();
contact->Mobile = mobile->text().trimmed();
}
if(email->text().trimmed().isEmpty()){
errors = true;
errorString += "Email Can't be Empty! \n";
email->setObjectName("error");
email->style()->unpolish(email);
email->style()->polish(email);
email->update();
}
else {
email->setObjectName("email");
email->style()->unpolish(email);
email->style()->polish(email);
email->update();
contact->Email = email->text().trimmed();
}
if(email2->text().trimmed().isEmpty()){
errors = true;
errorString += "Email2 Can't be Empty! \n";
email2->setObjectName("error");
email2->style()->unpolish(email2);
email2->style()->polish(email2);
email2->update();
}
else {
email2->setObjectName("email2");
email2->style()->unpolish(email2);
email2->style()->polish(email2);
email2->update();
contact->Email2 = email2->text().trimmed();
}
if(website->text().trimmed().isEmpty()){
errors = true;
errorString += "webSite Can't be Empty! \n";
website->setObjectName("error");
website->style()->unpolish(website);
website->style()->polish(website);
website->update();
}
else {
website->setObjectName("website");
website->style()->unpolish(website);
website->style()->polish(website);
website->update();
contact->webSite = website->text().trimmed();
}
if(taxnumber->text().trimmed().isEmpty()){
errors = true;
errorString += "Tax Number Can't be Empty! \n";
taxnumber->setObjectName("error");
taxnumber->style()->unpolish(taxnumber);
taxnumber->style()->polish(taxnumber);
taxnumber->update();
}
else {
taxnumber->setObjectName("taxnumber");
taxnumber->style()->unpolish(taxnumber);
taxnumber->style()->polish(taxnumber);
taxnumber->update();
contact->TaxNumber = taxnumber->text().trimmed();
}
for(int j = 0; j < BankAccounts.length(); j++){
BankAccounts.at(j)->name->setObjectName("name");
BankAccounts.at(j)->name->style()->unpolish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->style()->polish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->update();
for(int w = 0; w < BankAccounts.length(); w++){
if(BankAccounts.at(j) != BankAccounts.at(w))
if(BankAccounts.at(j)->name->text() == BankAccounts.at(w)->name->text()){
errors = true;
 errorString += "BankAccount has the same name \n";
BankAccounts.at(j)->name->setObjectName("error");
BankAccounts.at(j)->name->style()->unpolish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->style()->polish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->update();
}}}
if(!errors) {
contact->save();
for(int i = 0; i < BankAccounts.length(); i++){
BankAccounts.at(i)->bankaccount->ContactID= contact->ContactID;
if(!BankAccounts.at(i)->save()){
 errors = true;
 break; }
}
for(int i = 0; i < contact->bankaccounts.length(); i++){
bool flag = false;
for(int j = 0; j < BankAccounts.length(); j++){
if(contact->bankaccounts.at(i)->BankAccountID == BankAccounts.at(j)->bankaccount->BankAccountID){
flag = true;}}
if(!flag){
contact->bankaccounts.at(i)->remove();}
}
if(!errors){
ContactIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, "Contact",errorString.trimmed());
return false;
 }
}
void ContactUI::cancel(){
ContactIndexUI::ShowUI();
}
