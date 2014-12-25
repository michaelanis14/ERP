/**************************************************************************
**   File: purchaseui.cpp
**   Created on: Thu Dec 18 23:40:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchaseui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

PurchaseUI::PurchaseUI(QWidget *parent) :ERPDisplay(parent)
{

	purchase = new Purchase();
	flowLayout = new FlowLayout(formPanel);
	flowLayout->setContentsMargins(0,0,0,0);

	//QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
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
	serial = new QLineEdit();
	serial->setEnabled(false);
	//serial->setValidator( intValidator );


	block0Layout->addRow(QObject::tr("Serial"),serial);
	purchaseserial = new ERPComboBox();
	purchaseserial->addItems(PurchaseSerial::GetPairList());
	QObject::connect(purchaseserial, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectionChanged(QString)));

	block0Layout->addRow(QObject::tr("Purchase Serial"),purchaseserial);
	creationdate = new QDateEdit(QDate::currentDate());
	creationdate->setCalendarPopup(true);
	creationdate->setDisplayFormat("ddd dd/MM/yyyy");
	block0Layout->addRow(QObject::tr("Creation Date"),creationdate);
	deliverydate = new QDateEdit(QDate::currentDate());
	deliverydate->setCalendarPopup(true);
	deliverydate->setDisplayFormat("ddd dd/MM/yyyy");
	block0Layout->addRow(QObject::tr("Delivery Date"),deliverydate);
	flowLayout->addWidget(block0Layout);

	block1Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block1Layout->setMinimumWidth(330);
	AddRemoveButtons* addremovePurchaseStoreProductButtons = new AddRemoveButtons();
	block1Layout->addRow("PurchaseStoreProducts",addremovePurchaseStoreProductButtons);
	QObject::connect(addremovePurchaseStoreProductButtons, SIGNAL(addPressed()), this, SLOT(addPurchaseStoreProduct()));

	flowLayout->addWidget(block1Layout);

	block2Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block2Layout->setMinimumWidth(330);
	AddRemoveButtons* addremovePurchaseFreeLineButtons = new AddRemoveButtons();
	block2Layout->addRow("PurchaseFreeLines",addremovePurchaseFreeLineButtons);
	QObject::connect(addremovePurchaseFreeLineButtons, SIGNAL(addPressed()), this, SLOT(addPurchaseFreeLine()));
	selectionChanged("QString");
	flowLayout->addWidget(block2Layout);

}
ERPDisplay* PurchaseUI::p_instance = 0;
void PurchaseUI::ShowUI() {
	if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
		LoginUI::ShowUI();
	else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
		if( !ErpModel::GetInstance()->UserAccessList.at(0)->Purchase)
			QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
		else{	if (p_instance != 0)
				p_instance->deleteLater();
			p_instance = new PurchaseUI(mainwindow::GetMainDisplay());
			mainwindow::ShowDisplay(p_instance);
		}
	}else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
PurchaseUI*PurchaseUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (PurchaseUI*) p_instance;
}
void PurchaseUI::addPurchaseStoreProduct(){
	PurchaseStoreProductUI* purchasestoreproductui = new PurchaseStoreProductUI();
	purchasestoreproductui->block0Layout->hideRow(purchasestoreproductui->purchase);
	purchasestoreproductui->controllers->setFixedHeight(0);
	PurchaseStoreProducts.append(purchasestoreproductui);
	RemovebtnWidgets* rmpurchasestoreproduct = new RemovebtnWidgets(0,purchasestoreproductui);
	QObject::connect(rmpurchasestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseStoreProduct(QWidget*)));
	block1Layout->addRow(QObject::tr("PurchaseStoreProduct")+QString::number(PurchaseStoreProducts.count()),rmpurchasestoreproduct);
}
void PurchaseUI::addPurchaseStoreProduct(PurchaseStoreProduct* purchasestoreproduct){
	PurchaseStoreProductUI* purchasestoreproductui = new PurchaseStoreProductUI();
	purchasestoreproductui->block0Layout->hideRow(purchasestoreproductui->purchase);
	purchasestoreproductui->controllers->setFixedHeight(0);
	purchasestoreproductui->fill(purchasestoreproduct);
	PurchaseStoreProducts.append(purchasestoreproductui);
	RemovebtnWidgets* rmpurchasestoreproduct = new RemovebtnWidgets(0,purchasestoreproductui);
	QObject::connect(rmpurchasestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseStoreProduct(QWidget*)));
	block1Layout->addRow(QObject::tr("PurchaseStoreProduct") +QString::number(PurchaseStoreProducts.count()),rmpurchasestoreproduct);
}
void PurchaseUI::removePurchaseStoreProduct(QWidget* widget){
	if(PurchaseStoreProducts.count()  > 0){
		PurchaseStoreProductUI* purchasestoreproductui = (PurchaseStoreProductUI*) widget;
		PurchaseStoreProducts.removeOne(purchasestoreproductui);
		RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
		block1Layout->removeRow(sender);
	}
}
void PurchaseUI::addPurchaseFreeLine(){
	PurchaseFreeLineUI* purchasefreelineui = new PurchaseFreeLineUI();
	purchasefreelineui->block0Layout->hideRow(purchasefreelineui->purchase);
	purchasefreelineui->controllers->setFixedHeight(0);
	PurchaseFreeLines.append(purchasefreelineui);
	RemovebtnWidgets* rmpurchasefreeline = new RemovebtnWidgets(0,purchasefreelineui);
	QObject::connect(rmpurchasefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseFreeLine(QWidget*)));
	block2Layout->addRow(QObject::tr("PurchaseFreeLine")+QString::number(PurchaseFreeLines.count()),rmpurchasefreeline);
}
void PurchaseUI::addPurchaseFreeLine(PurchaseFreeLine* purchasefreeline){
	PurchaseFreeLineUI* purchasefreelineui = new PurchaseFreeLineUI();
	purchasefreelineui->block0Layout->hideRow(purchasefreelineui->purchase);
	purchasefreelineui->controllers->setFixedHeight(0);
	purchasefreelineui->fill(purchasefreeline);
	PurchaseFreeLines.append(purchasefreelineui);
	RemovebtnWidgets* rmpurchasefreeline = new RemovebtnWidgets(0,purchasefreelineui);
	QObject::connect(rmpurchasefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removePurchaseFreeLine(QWidget*)));
	block2Layout->addRow(QObject::tr("PurchaseFreeLine") +QString::number(PurchaseFreeLines.count()),rmpurchasefreeline);
}
void PurchaseUI::removePurchaseFreeLine(QWidget* widget){
	if(PurchaseFreeLines.count()  > 0){
		PurchaseFreeLineUI* purchasefreelineui = (PurchaseFreeLineUI*) widget;
		PurchaseFreeLines.removeOne(purchasefreelineui);
		RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
		block2Layout->removeRow(sender);
	}
}
void PurchaseUI::fill(Purchase* purchase){
	clear();
	this->purchase = purchase;
	serial->setText(QString::number(purchase->Serial));
	purchaseserial->setIndexByKey(purchase->PurchaseSerialID);
	creationdate->setDate(purchase->CreationDate);
	deliverydate->setDate(purchase->DeliveryDate);
	foreach(PurchaseStoreProduct* purchasestoreproduct, purchase->purchasestoreproducts) {
		addPurchaseStoreProduct(purchasestoreproduct);
	}
	foreach(PurchaseFreeLine* purchasefreeline, purchase->purchasefreelines) {
		addPurchaseFreeLine(purchasefreeline);
	}
}
void PurchaseUI::clear(){
	delete this->purchase;
	this->PurchaseStoreProducts.clear();
	this->PurchaseFreeLines.clear();
	serial->setText("");
	creationdate->setDate(QDate::currentDate());
	deliverydate->setDate(QDate::currentDate());
	QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
	foreach(RemovebtnWidgets * child, RWidgets)
	{
		if(child->parent()->parent()->parent() != 0)
			((ERPFormBlock*)child->parent()->parent())->removeRow(child);
	}
	this->purchase = new Purchase();
}
void PurchaseUI::selectPurchase(){
	if(Purchase::GetStringList().contains(QString::number(this->purchase->Serial)))
	{
		Purchase* con = Purchase::Get(QString::number(this->purchase->Serial));
		if(this->purchase->PurchaseID != con->PurchaseID){
			fill(con);
		}
	}
	else if(purchase->PurchaseID != 0)
		clear();
}
bool PurchaseUI::save(){
	bool errors = false;
	QString errorString =  "";
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
		purchase->Serial = serial->text().trimmed().toInt();
	}
	if(!purchaseserial->isHidden())
		purchase->PurchaseSerialID = purchaseserial->getKey();
	if(creationdate->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Creation Date Can't be Empty! \n");
		creationdate->setObjectName("error");
		creationdate->style()->unpolish(creationdate);
		creationdate->style()->polish(creationdate);
		creationdate->update();
	}
	else {
		creationdate->setObjectName("creationdate");
		creationdate->style()->unpolish(creationdate);
		creationdate->style()->polish(creationdate);
		creationdate->update();
		purchase->CreationDate.setDate(creationdate->date().year(),creationdate->date().month(),creationdate->date().day());
	}
	if(deliverydate->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Delivery Date Can't be Empty! \n");
		deliverydate->setObjectName("error");
		deliverydate->style()->unpolish(deliverydate);
		deliverydate->style()->polish(deliverydate);
		deliverydate->update();
	}
	else {
		deliverydate->setObjectName("deliverydate");
		deliverydate->style()->unpolish(deliverydate);
		deliverydate->style()->polish(deliverydate);
		deliverydate->update();
		purchase->DeliveryDate.setDate(deliverydate->date().year(),deliverydate->date().month(),deliverydate->date().day());
	}
	for(int j = 0; j < PurchaseFreeLines.length(); j++){
		PurchaseFreeLines.at(j)->description->setObjectName("description");
		PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
		PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
		PurchaseFreeLines.at(j)->description->update();
		for(int w = 0; w < PurchaseFreeLines.length(); w++){
			if(PurchaseFreeLines.at(j) != PurchaseFreeLines.at(w))
				if(PurchaseFreeLines.at(j)->description->text() == PurchaseFreeLines.at(w)->description->text()){
					errors = true;
					errorString += QObject::tr("PurchaseFreeLine has the same description \n");
					PurchaseFreeLines.at(j)->description->setObjectName("error");
					PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
					PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
					PurchaseFreeLines.at(j)->description->update();
				}}}
	if(!errors) {
		purchase->save();
		for(int i = 0; i < PurchaseStoreProducts.length(); i++){
			PurchaseStoreProducts.at(i)->purchasestoreproduct->PurchaseID= purchase->PurchaseID;
			if(!PurchaseStoreProducts.at(i)->save()){
				errors = true;
				break; }
		}
		for(int i = 0; i < purchase->purchasestoreproducts.length(); i++){
			bool flag = false;
			for(int j = 0; j < PurchaseStoreProducts.length(); j++){
				if(purchase->purchasestoreproducts.at(i)->PurchaseStoreProductID == PurchaseStoreProducts.at(j)->purchasestoreproduct->PurchaseStoreProductID){
					flag = true;}}
			if(!flag){
				purchase->purchasestoreproducts.at(i)->remove();}
		}
		for(int i = 0; i < PurchaseFreeLines.length(); i++){
			PurchaseFreeLines.at(i)->purchasefreeline->PurchaseID= purchase->PurchaseID;
			if(!PurchaseFreeLines.at(i)->save()){
				errors = true;
				break; }
		}
		for(int i = 0; i < purchase->purchasefreelines.length(); i++){
			bool flag = false;
			for(int j = 0; j < PurchaseFreeLines.length(); j++){
				if(purchase->purchasefreelines.at(i)->PurchaseFreeLineID == PurchaseFreeLines.at(j)->purchasefreeline->PurchaseFreeLineID){
					flag = true;}}
			if(!flag){
				purchase->purchasefreelines.at(i)->remove();}
		}
		if(!errors){
			PurchaseIndexUI::ShowUI();
			return true;}
		else return false;
	}
	else{ QMessageBox::warning(this, QObject::tr("Purchase"),errorString.trimmed());
		return false;
	}
}
void PurchaseUI::cancel(){
	PurchaseIndexUI::ShowUI();
}
bool PurchaseUI::updateModel(){
	bool errors = false;
	QString errorString =  "";
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
		purchase->Serial = serial->text().trimmed().toInt();
	}
	if(purchase->PurchaseSerialID == 0)
		purchase->PurchaseSerialID = purchaseserial->getKey();
	if(creationdate->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Creation Date Can't be Empty! \n");
		creationdate->setObjectName("error");
		creationdate->style()->unpolish(creationdate);
		creationdate->style()->polish(creationdate);
		creationdate->update();
	}
	else {
		creationdate->setObjectName("creationdate");
		creationdate->style()->unpolish(creationdate);
		creationdate->style()->polish(creationdate);
		creationdate->update();
		purchase->CreationDate.fromString(creationdate->text().trimmed());
	}
	if(deliverydate->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Delivery Date Can't be Empty! \n");
		deliverydate->setObjectName("error");
		deliverydate->style()->unpolish(deliverydate);
		deliverydate->style()->polish(deliverydate);
		deliverydate->update();
	}
	else {
		deliverydate->setObjectName("deliverydate");
		deliverydate->style()->unpolish(deliverydate);
		deliverydate->style()->polish(deliverydate);
		deliverydate->update();
		purchase->DeliveryDate.fromString(deliverydate->text().trimmed());
	}
	for(int j = 0; j < PurchaseFreeLines.length(); j++){
		PurchaseFreeLines.at(j)->description->setObjectName("description");
		PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
		PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
		PurchaseFreeLines.at(j)->description->update();
		for(int w = 0; w < PurchaseFreeLines.length(); w++){
			if(PurchaseFreeLines.at(j) != PurchaseFreeLines.at(w))
				if(PurchaseFreeLines.at(j)->description->text() == PurchaseFreeLines.at(w)->description->text()){
					errors = true;
					errorString +=QObject::tr( "PurchaseFreeLine has the same description \n");
					PurchaseFreeLines.at(j)->description->setObjectName("error");
					PurchaseFreeLines.at(j)->description->style()->unpolish(PurchaseFreeLines.at(j)->description);
					PurchaseFreeLines.at(j)->description->style()->polish(PurchaseFreeLines.at(j)->description);
					PurchaseFreeLines.at(j)->description->update();
				}}}
	for(int i = 0; i < PurchaseStoreProducts.length(); i++){
		PurchaseStoreProducts.at(i)->purchasestoreproduct->PurchaseID= purchase->PurchaseID;
		if(!PurchaseStoreProducts.at(i)->updateModel()){
			errors = true;
			break; }
	}
	for(int i = 0; i < PurchaseFreeLines.length(); i++){
		PurchaseFreeLines.at(i)->purchasefreeline->PurchaseID= purchase->PurchaseID;
		if(!PurchaseFreeLines.at(i)->updateModel()){
			errors = true;
			break; }
	}
	if(!errors){
		return true;
	}
	else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Purchase"),errorString.trimmed());
		return false;
	}
}

void PurchaseUI::selectionChanged(QString){

	QList<Purchase*> d = Purchase::QuerySelect("Serial = (SELECT MAX(Serial) from Purchase)");
	int i = 1;
	if(!d.isEmpty())
		i = d.first()->Serial +1;
	this->serial->setText(QString::number(i));

}
