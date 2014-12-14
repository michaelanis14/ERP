/**************************************************************************
**   File: contactui.cpp
**   Created on: Sun Dec 14 22:39:13 EET 2014
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
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block0Layout->setMinimumWidth(330);
name = new QLineEdit();
QStringList* list = new QStringList(Contact::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectContact()));
block0Layout->addRow(QObject::tr("Name"),name);
salutation = new QLineEdit();
block0Layout->addRow(QObject::tr("Salutation"),salutation);
birthdateordateoffoundation = new QDateEdit(QDate::currentDate());
birthdateordateoffoundation->setCalendarPopup(true);
birthdateordateoffoundation->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Birthdate Or Date Of Foundation"),birthdateordateoffoundation);
flowLayout->addWidget(block0Layout);

block1Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block1Layout->setMinimumWidth(330);
contacttype = new ERPComboBox();
contacttype->addItems(ContactType::GetPairList());
block1Layout->addRow(QObject::tr("Contact Type"),contacttype);
contactclass = new ERPComboBox();
contactclass->addItems(ContactClass::GetPairList());
block1Layout->addRow(QObject::tr("Contact Class"),contactclass);
serial = new QLineEdit();
serial->setValidator( intValidator );
block1Layout->addRow(QObject::tr("Serial"),serial);
flowLayout->addWidget(block1Layout);

block2Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block2Layout->setMinimumWidth(330);
address = new QLineEdit();
block2Layout->addRow(QObject::tr("Address"),address);
postalcode = new QLineEdit();
block2Layout->addRow(QObject::tr("Postal Code"),postalcode);
city = new QLineEdit();
block2Layout->addRow(QObject::tr("City"),city);
country = new ERPComboBox();
country->addItems(Country::GetPairList());
block2Layout->addRow(QObject::tr("Country"),country);
flowLayout->addWidget(block2Layout);

block3Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block3Layout->setMinimumWidth(330);
contactstatus = new ERPComboBox();
contactstatus->addItems(ContactStatus::GetPairList());
block3Layout->addRow(QObject::tr("Contact Status"),contactstatus);
website = new QLineEdit();
block3Layout->addRow(QObject::tr("Website"),website);
taxnumber = new QLineEdit();
block3Layout->addRow(QObject::tr("Tax Number"),taxnumber);
AddRemoveButtons* addremoveContactTelephoneButtons = new AddRemoveButtons();
block3Layout->addRow("ContactTelephones",addremoveContactTelephoneButtons);
QObject::connect(addremoveContactTelephoneButtons, SIGNAL(addPressed()), this, SLOT(addContactTelephone()));

flowLayout->addWidget(block3Layout);

block4Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block4Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveContactEmailButtons = new AddRemoveButtons();
block4Layout->addRow("ContactEmails",addremoveContactEmailButtons);
QObject::connect(addremoveContactEmailButtons, SIGNAL(addPressed()), this, SLOT(addContactEmail()));

flowLayout->addWidget(block4Layout);

block5Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block5Layout->setMinimumWidth(330);
AddRemoveButtons* addremoveBankAccountButtons = new AddRemoveButtons();
block5Layout->addRow("BankAccounts",addremoveBankAccountButtons);
QObject::connect(addremoveBankAccountButtons, SIGNAL(addPressed()), this, SLOT(addBankAccount()));

flowLayout->addWidget(block5Layout);

block6Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block6Layout->setMinimumWidth(330);
flowLayout->addWidget(block6Layout);

block7Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block7Layout->setMinimumWidth(330);
flowLayout->addWidget(block7Layout);

}
ERPDisplay* ContactUI::p_instance = 0;
void ContactUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
ContactUI*ContactUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactUI*) p_instance; 
}
void ContactUI::addContactTelephone(){ 
ContactTelephoneUI* contacttelephoneui = new ContactTelephoneUI();
contacttelephoneui->block0Layout->hideRow(contacttelephoneui->contact);
contacttelephoneui->controllers->setFixedHeight(0);
ContactTelephones.append(contacttelephoneui);
RemovebtnWidgets* rmcontacttelephone = new RemovebtnWidgets(0,contacttelephoneui);
QObject::connect(rmcontacttelephone, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactTelephone(QWidget*)));
block3Layout->addRow(QObject::tr("ContactTelephone")+QString::number(ContactTelephones.count()),rmcontacttelephone);
}
void ContactUI::addContactTelephone(ContactTelephone* ContactTelephone){ 
ContactTelephoneUI* contacttelephoneui = new ContactTelephoneUI();
contacttelephoneui->block0Layout->hideRow(contacttelephoneui->contact);
contacttelephoneui->controllers->setFixedHeight(0);
contacttelephoneui->fill(ContactTelephone);
ContactTelephones.append(contacttelephoneui);
RemovebtnWidgets* rmcontacttelephone = new RemovebtnWidgets(0,contacttelephoneui);
QObject::connect(rmcontacttelephone, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactTelephone(QWidget*)));
block3Layout->addRow(QObject::tr("ContactTelephone") +QString::number(ContactTelephones.count()),rmcontacttelephone);
}
void ContactUI::removeContactTelephone(QWidget* widget){ 
if(ContactTelephones.count()  > 0){
ContactTelephoneUI* contacttelephoneui = (ContactTelephoneUI*) widget;
ContactTelephones.removeOne(contacttelephoneui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block3Layout->removeRow(sender);
}
}
void ContactUI::addContactEmail(){ 
ContactEmailUI* contactemailui = new ContactEmailUI();
contactemailui->block0Layout->hideRow(contactemailui->contact);
contactemailui->controllers->setFixedHeight(0);
ContactEmails.append(contactemailui);
RemovebtnWidgets* rmcontactemail = new RemovebtnWidgets(0,contactemailui);
QObject::connect(rmcontactemail, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactEmail(QWidget*)));
block4Layout->addRow(QObject::tr("ContactEmail")+QString::number(ContactEmails.count()),rmcontactemail);
}
void ContactUI::addContactEmail(ContactEmail* ContactEmail){ 
ContactEmailUI* contactemailui = new ContactEmailUI();
contactemailui->block0Layout->hideRow(contactemailui->contact);
contactemailui->controllers->setFixedHeight(0);
contactemailui->fill(ContactEmail);
ContactEmails.append(contactemailui);
RemovebtnWidgets* rmcontactemail = new RemovebtnWidgets(0,contactemailui);
QObject::connect(rmcontactemail, SIGNAL(removePressed(QWidget*)), this, SLOT(removeContactEmail(QWidget*)));
block4Layout->addRow(QObject::tr("ContactEmail") +QString::number(ContactEmails.count()),rmcontactemail);
}
void ContactUI::removeContactEmail(QWidget* widget){ 
if(ContactEmails.count()  > 0){
ContactEmailUI* contactemailui = (ContactEmailUI*) widget;
ContactEmails.removeOne(contactemailui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block4Layout->removeRow(sender);
}
}
void ContactUI::addBankAccount(){ 
BankAccountUI* bankaccountui = new BankAccountUI();
bankaccountui->block0Layout->hideRow(bankaccountui->contact);
bankaccountui->controllers->setFixedHeight(0);
BankAccounts.append(bankaccountui);
RemovebtnWidgets* rmbankaccount = new RemovebtnWidgets(0,bankaccountui);
QObject::connect(rmbankaccount, SIGNAL(removePressed(QWidget*)), this, SLOT(removeBankAccount(QWidget*)));
block5Layout->addRow(QObject::tr("BankAccount")+QString::number(BankAccounts.count()),rmbankaccount);
}
void ContactUI::addBankAccount(BankAccount* BankAccount){ 
BankAccountUI* bankaccountui = new BankAccountUI();
bankaccountui->block0Layout->hideRow(bankaccountui->contact);
bankaccountui->controllers->setFixedHeight(0);
bankaccountui->fill(BankAccount);
BankAccounts.append(bankaccountui);
RemovebtnWidgets* rmbankaccount = new RemovebtnWidgets(0,bankaccountui);
QObject::connect(rmbankaccount, SIGNAL(removePressed(QWidget*)), this, SLOT(removeBankAccount(QWidget*)));
block5Layout->addRow(QObject::tr("BankAccount") +QString::number(BankAccounts.count()),rmbankaccount);
}
void ContactUI::removeBankAccount(QWidget* widget){ 
if(BankAccounts.count()  > 0){
BankAccountUI* bankaccountui = (BankAccountUI*) widget;
BankAccounts.removeOne(bankaccountui);
RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
block5Layout->removeRow(sender);
}
}
void ContactUI::fill(Contact* contact){ 
clear();
this->contact = contact;
name->setText(contact->Name);
salutation->setText(contact->Salutation);
birthdateordateoffoundation->setDate(QDate::fromString(contact->BirthdateOrDateOfFoundation));
contacttype->setIndexByKey(contact->ContactTypeID);
contactclass->setIndexByKey(contact->ContactClassID);
serial->setText(QString::number(contact->Serial));
address->setText(contact->Address);
postalcode->setText(contact->PostalCode);
city->setText(contact->City);
country->setIndexByKey(contact->CountryID);
contactstatus->setIndexByKey(contact->ContactStatusID);
website->setText(contact->Website);
taxnumber->setText(contact->TaxNumber);
foreach(ContactTelephone* contacttelephone, contact->contacttelephones) {
addContactTelephone(contacttelephone);
}
foreach(ContactEmail* contactemail, contact->contactemails) {
addContactEmail(contactemail);
}
foreach(BankAccount* bankaccount, contact->bankaccounts) {
addBankAccount(bankaccount);
}
} 
void ContactUI::clear(){ 
delete this->contact;
this->ContactTelephones.clear();
this->ContactEmails.clear();
this->BankAccounts.clear();
salutation->setText("");
birthdateordateoffoundation->setDate(QDate::currentDate());
serial->setText("");
address->setText("");
postalcode->setText("");
city->setText("");
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
if(Contact::GetStringList().contains(this->contact->Name))
{
Contact* con = Contact::Get(this->contact->Name);
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
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
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
if(salutation->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Salutation Can't be Empty! \n");
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
if(birthdateordateoffoundation->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Birthdate Or Date Of Foundation Can't be Empty! \n");
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
if(!contacttype->isHidden()) 
contact->ContactTypeID = contacttype->getKey();
if(!contactclass->isHidden()) 
contact->ContactClassID = contactclass->getKey();
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Serial Can't be Empty! \n");
serial->setObjectName("error");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
}
else { 
serial->setObjectName("serial");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
contact->Serial = serial->text().trimmed().toInt();
}
if(address->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Address Can't be Empty! \n");
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
errorString += QObject::tr("Postal Code Can't be Empty! \n");
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
errorString += QObject::tr("City Can't be Empty! \n");
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
if(!country->isHidden()) 
contact->CountryID = country->getKey();
if(!contactstatus->isHidden()) 
contact->ContactStatusID = contactstatus->getKey();
if(website->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Website Can't be Empty! \n");
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
contact->Website = website->text().trimmed();
}
if(taxnumber->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Tax Number Can't be Empty! \n");
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
for(int j = 0; j < ContactTelephones.length(); j++){
ContactTelephones.at(j)->description->setObjectName("description");
ContactTelephones.at(j)->description->style()->unpolish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->style()->polish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->update();
for(int w = 0; w < ContactTelephones.length(); w++){
if(ContactTelephones.at(j) != ContactTelephones.at(w))
if(ContactTelephones.at(j)->description->text() == ContactTelephones.at(w)->description->text()){
errors = true; 
 errorString += QObject::tr("ContactTelephone has the same description \n");
ContactTelephones.at(j)->description->setObjectName("error");
ContactTelephones.at(j)->description->style()->unpolish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->style()->polish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->update();
}}}
for(int j = 0; j < ContactEmails.length(); j++){
ContactEmails.at(j)->description->setObjectName("description");
ContactEmails.at(j)->description->style()->unpolish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->style()->polish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->update();
for(int w = 0; w < ContactEmails.length(); w++){
if(ContactEmails.at(j) != ContactEmails.at(w))
if(ContactEmails.at(j)->description->text() == ContactEmails.at(w)->description->text()){
errors = true; 
 errorString += QObject::tr("ContactEmail has the same description \n");
ContactEmails.at(j)->description->setObjectName("error");
ContactEmails.at(j)->description->style()->unpolish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->style()->polish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->update();
}}}
for(int j = 0; j < BankAccounts.length(); j++){
BankAccounts.at(j)->name->setObjectName("name");
BankAccounts.at(j)->name->style()->unpolish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->style()->polish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->update();
for(int w = 0; w < BankAccounts.length(); w++){
if(BankAccounts.at(j) != BankAccounts.at(w))
if(BankAccounts.at(j)->name->text() == BankAccounts.at(w)->name->text()){
errors = true; 
 errorString += QObject::tr("BankAccount has the same name \n");
BankAccounts.at(j)->name->setObjectName("error");
BankAccounts.at(j)->name->style()->unpolish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->style()->polish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->update();
}}}
if(!errors) {
contact->save();
for(int i = 0; i < ContactTelephones.length(); i++){
ContactTelephones.at(i)->contacttelephone->ContactID= contact->ContactID;
if(!ContactTelephones.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < contact->contacttelephones.length(); i++){
bool flag = false;
for(int j = 0; j < ContactTelephones.length(); j++){
if(contact->contacttelephones.at(i)->ContactTelephoneID == ContactTelephones.at(j)->contacttelephone->ContactTelephoneID){
flag = true;}}
if(!flag){
contact->contacttelephones.at(i)->remove();}
}
for(int i = 0; i < ContactEmails.length(); i++){
ContactEmails.at(i)->contactemail->ContactID= contact->ContactID;
if(!ContactEmails.at(i)->save()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < contact->contactemails.length(); i++){
bool flag = false;
for(int j = 0; j < ContactEmails.length(); j++){
if(contact->contactemails.at(i)->ContactEmailID == ContactEmails.at(j)->contactemail->ContactEmailID){
flag = true;}}
if(!flag){
contact->contactemails.at(i)->remove();}
}
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
else{ QMessageBox::warning(this, QObject::tr("Contact"),errorString.trimmed());
return false; 
 }
}
void ContactUI::cancel(){ 
ContactIndexUI::ShowUI();
}
bool ContactUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(name->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Name Can't be Empty! \n");
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
if(salutation->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Salutation Can't be Empty! \n");
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
if(birthdateordateoffoundation->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Birthdate Or Date Of Foundation Can't be Empty! \n");
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
if(serial->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Serial Can't be Empty! \n");
serial->setObjectName("error");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
}
else { 
serial->setObjectName("serial");
serial->style()->unpolish(serial);
serial->style()->polish(serial);
serial->update();
contact->Serial = serial->text().trimmed().toInt();
}
if(address->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Address Can't be Empty! \n");
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
errorString += QObject::tr("Postal Code Can't be Empty! \n");
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
errorString += QObject::tr("City Can't be Empty! \n");
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
if(website->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Website Can't be Empty! \n");
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
contact->Website = website->text().trimmed();
}
if(taxnumber->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Tax Number Can't be Empty! \n");
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
for(int j = 0; j < ContactTelephones.length(); j++){
ContactTelephones.at(j)->description->setObjectName("description");
ContactTelephones.at(j)->description->style()->unpolish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->style()->polish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->update();
for(int w = 0; w < ContactTelephones.length(); w++){
if(ContactTelephones.at(j) != ContactTelephones.at(w))
if(ContactTelephones.at(j)->description->text() == ContactTelephones.at(w)->description->text()){
errors = true; 
 errorString +=QObject::tr( "ContactTelephone has the same description \n");
ContactTelephones.at(j)->description->setObjectName("error");
ContactTelephones.at(j)->description->style()->unpolish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->style()->polish(ContactTelephones.at(j)->description);
ContactTelephones.at(j)->description->update();
}}}
for(int j = 0; j < ContactEmails.length(); j++){
ContactEmails.at(j)->description->setObjectName("description");
ContactEmails.at(j)->description->style()->unpolish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->style()->polish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->update();
for(int w = 0; w < ContactEmails.length(); w++){
if(ContactEmails.at(j) != ContactEmails.at(w))
if(ContactEmails.at(j)->description->text() == ContactEmails.at(w)->description->text()){
errors = true; 
 errorString +=QObject::tr( "ContactEmail has the same description \n");
ContactEmails.at(j)->description->setObjectName("error");
ContactEmails.at(j)->description->style()->unpolish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->style()->polish(ContactEmails.at(j)->description);
ContactEmails.at(j)->description->update();
}}}
for(int j = 0; j < BankAccounts.length(); j++){
BankAccounts.at(j)->name->setObjectName("name");
BankAccounts.at(j)->name->style()->unpolish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->style()->polish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->update();
for(int w = 0; w < BankAccounts.length(); w++){
if(BankAccounts.at(j) != BankAccounts.at(w))
if(BankAccounts.at(j)->name->text() == BankAccounts.at(w)->name->text()){
errors = true; 
 errorString +=QObject::tr( "BankAccount has the same name \n");
BankAccounts.at(j)->name->setObjectName("error");
BankAccounts.at(j)->name->style()->unpolish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->style()->polish(BankAccounts.at(j)->name);
BankAccounts.at(j)->name->update();
}}}
for(int i = 0; i < ContactTelephones.length(); i++){
ContactTelephones.at(i)->contacttelephone->ContactID= contact->ContactID;
if(!ContactTelephones.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < ContactEmails.length(); i++){
ContactEmails.at(i)->contactemail->ContactID= contact->ContactID;
if(!ContactEmails.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
for(int i = 0; i < BankAccounts.length(); i++){
BankAccounts.at(i)->bankaccount->ContactID= contact->ContactID;
if(!BankAccounts.at(i)->updateModel()){ 
 errors = true; 
 break; } 
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Contact"),errorString.trimmed());
return false; 
 }
}
