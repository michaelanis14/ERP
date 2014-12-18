/**************************************************************************
**   File: storeui.cpp
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "storeui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

StoreUI::StoreUI(QWidget *parent) :ERPDisplay(parent)
{

store = new Store();
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
QStringList* list = new QStringList(Store::GetStringList());
QCompleter *completer = new QCompleter(*list);
completer->setCaseSensitivity(Qt::CaseInsensitive);
name->setCompleter(completer);
QObject::connect(name, SIGNAL(editingFinished()), this, SLOT(selectStore()));
block0Layout->addRow(QObject::tr("Name"),name);
address = new QLineEdit();
block0Layout->addRow(QObject::tr("Address"),address);
postalcode = new QLineEdit();
block0Layout->addRow(QObject::tr("Postal Code"),postalcode);
city = new QLineEdit();
block0Layout->addRow(QObject::tr("City"),city);
country = new ERPComboBox();
country->addItems(Country::GetPairList());
block0Layout->addRow(QObject::tr("Country"),country);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* StoreUI::p_instance = 0;
void StoreUI::ShowUI() { 
 if(ErpModel::GetInstance()->LoggedUser->UserID == 0) 
 LoginUI::ShowUI(); 
 else if(ErpModel::GetInstance()->UserAccessList.length() > 0){ 
 if( !ErpModel::GetInstance()->UserAccessList.at(0)->Store) 
 QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission")); 
 else{	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new StoreUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
} 
 }else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
StoreUI*StoreUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (StoreUI*) p_instance; 
}
void StoreUI::fill(Store* store){ 
clear();
this->store = store;
name->setText(store->Name);
address->setText(store->Address);
postalcode->setText(store->PostalCode);
city->setText(store->City);
country->setIndexByKey(store->CountryID);
} 
void StoreUI::clear(){ 
delete this->store;
address->setText("");
postalcode->setText("");
city->setText("");
this->store = new Store();
} 
void StoreUI::selectStore(){ 
if(Store::GetStringList().contains(this->store->Name))
{
Store* con = Store::Get(this->store->Name);
if(this->store->StoreID != con->StoreID){
fill(con);
}
}
else if(store->StoreID != 0)
clear();
}
bool StoreUI::save(){ 
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
store->Name = name->text().trimmed();
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
store->Address = address->text().trimmed();
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
store->PostalCode = postalcode->text().trimmed();
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
store->City = city->text().trimmed();
}
if(!country->isHidden()) 
store->CountryID = country->getKey();
if(!errors) {
store->save();
if(!errors){
StoreIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("Store"),errorString.trimmed());
return false; 
 }
}
void StoreUI::cancel(){ 
StoreIndexUI::ShowUI();
}
bool StoreUI::updateModel(){ 
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
store->Name = name->text().trimmed();
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
store->Address = address->text().trimmed();
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
store->PostalCode = postalcode->text().trimmed();
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
store->City = city->text().trimmed();
}
if(store->CountryID == 0) 
store->CountryID = country->getKey();
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Store"),errorString.trimmed());
return false; 
 }
}
