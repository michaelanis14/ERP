/**************************************************************************
**   File: invoiceui.cpp
**   Created on: Fri Dec 19 22:39:36 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "invoiceui.h"
#include "../Login/loginui.h"
#include "../MainWindow.h"

InvoiceUI::InvoiceUI(QWidget *parent) :ERPDisplay(parent)
{

	invoice = new Invoice();
	flowLayout = new FlowLayout(formPanel);
	flowLayout->setContentsMargins(0,0,0,0);

	//QIntValidator *intValidator = new QIntValidator ( 0, 1000000);
	QDoubleValidator* doubleValidator = new QDoubleValidator(0,99.0, 2);
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
	block0Layout->addRow(QObject::tr("Serial"),serial);
	invoiceserial = new ERPComboBox();
	invoiceserial->addItems(InvoiceSerial::GetPairList());
	QObject::connect(invoiceserial, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectionChanged(QString)));

	block0Layout->addRow(QObject::tr("Invoice Serial"),invoiceserial);
	flowLayout->addWidget(block0Layout);

	block1Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block1Layout->setMinimumWidth(330);
	contact = new ERPComboBox();
	contact->addItems(Contact::GetPairList((Contact::QuerySelect("ContactTypeID = 1 OR ContactTypeID = 3"))));
	QObject::connect(contact, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectionChanged(QString)));

	block1Layout->addRow(QObject::tr("Contact"),contact);
	project = new ERPComboBox();
	project->addItems(Project::GetPairList());
	block1Layout->addRow(QObject::tr("Project"),project);
	flowLayout->addWidget(block1Layout);

	block2Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block2Layout->setMinimumWidth(330);
	date = new QDateEdit(QDate::currentDate());
	date->setCalendarPopup(true);
	date->setDisplayFormat("ddd dd/MM/yyyy");
	block2Layout->addRow(QObject::tr("Date"),date);
	invoiceperiod = new ERPComboBox();
	invoiceperiod->addItems(InvoicePeriod::GetPairList());
	block2Layout->addRow(QObject::tr("Invoice Period"),invoiceperiod);
	invoiceyear = new ERPComboBox();
	invoiceyear->addItems(InvoiceYear::GetPairList());
	block2Layout->addRow(QObject::tr("Invoice Year"),invoiceyear);
	duedate = new QDateEdit(QDate::currentDate());
	duedate->setCalendarPopup(true);
	duedate->setDisplayFormat("ddd dd/MM/yyyy");
	block2Layout->addRow(QObject::tr("Due Date"),duedate);
	flowLayout->addWidget(block2Layout);

	block3Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block3Layout->setMinimumWidth(330);
	discount = new QLineEdit();
	discount->setValidator( doubleValidator );
	block3Layout->addRow(QObject::tr("discount"),discount);
	allowance = new QLineEdit();
	allowance->setValidator( doubleValidator );
	block3Layout->addRow(QObject::tr("Allowance"),allowance);
	flowLayout->addWidget(block3Layout);

	block4Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block4Layout->setMinimumWidth(330);
	header = new QLineEdit();
	block4Layout->addRow(QObject::tr("Header"),header);
	footer = new QLineEdit();
	block4Layout->addRow(QObject::tr("Footer"),footer);
	note = new QLineEdit();
	block4Layout->addRow(QObject::tr("Note"),note);
	flowLayout->addWidget(block4Layout);

	block5Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block5Layout->setMinimumWidth(330);
	AddRemoveButtons* addremoveInvoiceStoreProductButtons = new AddRemoveButtons();
	block5Layout->addRow("InvoiceStoreProducts",addremoveInvoiceStoreProductButtons);
	QObject::connect(addremoveInvoiceStoreProductButtons, SIGNAL(addPressed()), this, SLOT(addInvoiceStoreProduct()));

	flowLayout->addWidget(block5Layout);

	block6Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block6Layout->setMinimumWidth(330);
	AddRemoveButtons* addremoveInvoiceServiceButtons = new AddRemoveButtons();
	block6Layout->addRow("InvoiceServices",addremoveInvoiceServiceButtons);
	QObject::connect(addremoveInvoiceServiceButtons, SIGNAL(addPressed()), this, SLOT(addInvoiceService()));

	flowLayout->addWidget(block6Layout);

	block7Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block7Layout->setMinimumWidth(330);
	AddRemoveButtons* addremoveInvoiceDeliveryOrderFreelineButtons = new AddRemoveButtons();
	block7Layout->addRow("InvoiceDeliveryOrderFreelines",addremoveInvoiceDeliveryOrderFreelineButtons);
	QObject::connect(addremoveInvoiceDeliveryOrderFreelineButtons, SIGNAL(addPressed()), this, SLOT(addInvoiceDeliveryOrderFreeline()));

	flowLayout->addWidget(block7Layout);

	block8Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block8Layout->setMinimumWidth(330);
	AddRemoveButtons* addremoveInvoiceFreelineButtons = new AddRemoveButtons();
	block8Layout->addRow("InvoiceFreelines",addremoveInvoiceFreelineButtons);
	QObject::connect(addremoveInvoiceFreelineButtons, SIGNAL(addPressed()), this, SLOT(addInvoiceFreeline()));
	selectionChanged("QString");
	flowLayout->addWidget(block8Layout);

}
ERPDisplay* InvoiceUI::p_instance = 0;
void InvoiceUI::ShowUI() {
	if(ErpModel::GetInstance()->LoggedUser->UserID == 0)
		LoginUI::ShowUI();
	else if(ErpModel::GetInstance()->UserAccessList.length() > 0){
		if( !ErpModel::GetInstance()->UserAccessList.at(0)->Invoice)
			QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have Permission"));
		else{	if (p_instance != 0)
				p_instance->deleteLater();
			p_instance = new InvoiceUI(mainwindow::GetMainDisplay());
			mainwindow::ShowDisplay(p_instance);
		}
	}else	QMessageBox::warning(0, QObject::tr("Access Permission"),QObject::tr("You do not have a Permission List")); }
InvoiceUI*InvoiceUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (InvoiceUI*) p_instance;
}
void InvoiceUI::addInvoiceStoreProduct(){
	InvoiceStoreProductUI* invoicestoreproductui = new InvoiceStoreProductUI();
	invoicestoreproductui->block0Layout->hideRow(invoicestoreproductui->invoice);
	invoicestoreproductui->controllers->setFixedHeight(0);
	InvoiceStoreProducts.append(invoicestoreproductui);
	RemovebtnWidgets* rminvoicestoreproduct = new RemovebtnWidgets(0,invoicestoreproductui);
	QObject::connect(rminvoicestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceStoreProduct(QWidget*)));
	block5Layout->addRow(QObject::tr("InvoiceStoreProduct")+QString::number(InvoiceStoreProducts.count()),rminvoicestoreproduct);
}
void InvoiceUI::addInvoiceStoreProduct(InvoiceStoreProduct* invoicestoreproduct){
	InvoiceStoreProductUI* invoicestoreproductui = new InvoiceStoreProductUI();
	invoicestoreproductui->block0Layout->hideRow(invoicestoreproductui->invoice);
	invoicestoreproductui->controllers->setFixedHeight(0);
	invoicestoreproductui->fill(invoicestoreproduct);
	InvoiceStoreProducts.append(invoicestoreproductui);
	RemovebtnWidgets* rminvoicestoreproduct = new RemovebtnWidgets(0,invoicestoreproductui);
	QObject::connect(rminvoicestoreproduct, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceStoreProduct(QWidget*)));
	block5Layout->addRow(QObject::tr("InvoiceStoreProduct") +QString::number(InvoiceStoreProducts.count()),rminvoicestoreproduct);
}
void InvoiceUI::removeInvoiceStoreProduct(QWidget* widget){
	if(InvoiceStoreProducts.count()  > 0){
		InvoiceStoreProductUI* invoicestoreproductui = (InvoiceStoreProductUI*) widget;
		InvoiceStoreProducts.removeOne(invoicestoreproductui);
		RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
		block5Layout->removeRow(sender);
	}
}
void InvoiceUI::addInvoiceService(){
	InvoiceServiceUI* invoiceserviceui = new InvoiceServiceUI();
	invoiceserviceui->block0Layout->hideRow(invoiceserviceui->invoice);
	invoiceserviceui->controllers->setFixedHeight(0);
	InvoiceServices.append(invoiceserviceui);
	RemovebtnWidgets* rminvoiceservice = new RemovebtnWidgets(0,invoiceserviceui);
	QObject::connect(rminvoiceservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceService(QWidget*)));
	block6Layout->addRow(QObject::tr("InvoiceService")+QString::number(InvoiceServices.count()),rminvoiceservice);
}
void InvoiceUI::addInvoiceService(InvoiceService* invoiceservice){
	InvoiceServiceUI* invoiceserviceui = new InvoiceServiceUI();
	invoiceserviceui->block0Layout->hideRow(invoiceserviceui->invoice);
	invoiceserviceui->controllers->setFixedHeight(0);
	invoiceserviceui->fill(invoiceservice);
	InvoiceServices.append(invoiceserviceui);
	RemovebtnWidgets* rminvoiceservice = new RemovebtnWidgets(0,invoiceserviceui);
	QObject::connect(rminvoiceservice, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceService(QWidget*)));
	block6Layout->addRow(QObject::tr("InvoiceService") +QString::number(InvoiceServices.count()),rminvoiceservice);
}
void InvoiceUI::removeInvoiceService(QWidget* widget){
	if(InvoiceServices.count()  > 0){
		InvoiceServiceUI* invoiceserviceui = (InvoiceServiceUI*) widget;
		InvoiceServices.removeOne(invoiceserviceui);
		RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
		block6Layout->removeRow(sender);
	}
}
void InvoiceUI::addInvoiceDeliveryOrderFreeline(){
	InvoiceDeliveryOrderFreelineUI* invoicedeliveryorderfreelineui = new InvoiceDeliveryOrderFreelineUI();
	invoicedeliveryorderfreelineui->block0Layout->hideRow(invoicedeliveryorderfreelineui->invoice);
	invoicedeliveryorderfreelineui->controllers->setFixedHeight(0);
	InvoiceDeliveryOrderFreelines.append(invoicedeliveryorderfreelineui);
	RemovebtnWidgets* rminvoicedeliveryorderfreeline = new RemovebtnWidgets(0,invoicedeliveryorderfreelineui);
	QObject::connect(rminvoicedeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceDeliveryOrderFreeline(QWidget*)));
	block7Layout->addRow(QObject::tr("InvoiceDeliveryOrderFreeline")+QString::number(InvoiceDeliveryOrderFreelines.count()),rminvoicedeliveryorderfreeline);
}
void InvoiceUI::addInvoiceDeliveryOrderFreeline(InvoiceDeliveryOrderFreeline* invoicedeliveryorderfreeline){
	InvoiceDeliveryOrderFreelineUI* invoicedeliveryorderfreelineui = new InvoiceDeliveryOrderFreelineUI();
	invoicedeliveryorderfreelineui->block0Layout->hideRow(invoicedeliveryorderfreelineui->invoice);
	invoicedeliveryorderfreelineui->controllers->setFixedHeight(0);
	invoicedeliveryorderfreelineui->fill(invoicedeliveryorderfreeline);
	InvoiceDeliveryOrderFreelines.append(invoicedeliveryorderfreelineui);
	RemovebtnWidgets* rminvoicedeliveryorderfreeline = new RemovebtnWidgets(0,invoicedeliveryorderfreelineui);
	QObject::connect(rminvoicedeliveryorderfreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceDeliveryOrderFreeline(QWidget*)));
	block7Layout->addRow(QObject::tr("InvoiceDeliveryOrderFreeline") +QString::number(InvoiceDeliveryOrderFreelines.count()),rminvoicedeliveryorderfreeline);
}
void InvoiceUI::removeInvoiceDeliveryOrderFreeline(QWidget* widget){
	if(InvoiceDeliveryOrderFreelines.count()  > 0){
		InvoiceDeliveryOrderFreelineUI* invoicedeliveryorderfreelineui = (InvoiceDeliveryOrderFreelineUI*) widget;
		InvoiceDeliveryOrderFreelines.removeOne(invoicedeliveryorderfreelineui);
		RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
		block7Layout->removeRow(sender);
	}
}
void InvoiceUI::addInvoiceFreeline(){
	InvoiceFreelineUI* invoicefreelineui = new InvoiceFreelineUI();
	invoicefreelineui->block0Layout->hideRow(invoicefreelineui->invoice);
	invoicefreelineui->controllers->setFixedHeight(0);
	InvoiceFreelines.append(invoicefreelineui);
	RemovebtnWidgets* rminvoicefreeline = new RemovebtnWidgets(0,invoicefreelineui);
	QObject::connect(rminvoicefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceFreeline(QWidget*)));
	block8Layout->addRow(QObject::tr("InvoiceFreeline")+QString::number(InvoiceFreelines.count()),rminvoicefreeline);
}
void InvoiceUI::addInvoiceFreeline(InvoiceFreeline* invoicefreeline){
	InvoiceFreelineUI* invoicefreelineui = new InvoiceFreelineUI();
	invoicefreelineui->block0Layout->hideRow(invoicefreelineui->invoice);
	invoicefreelineui->controllers->setFixedHeight(0);
	invoicefreelineui->fill(invoicefreeline);
	InvoiceFreelines.append(invoicefreelineui);
	RemovebtnWidgets* rminvoicefreeline = new RemovebtnWidgets(0,invoicefreelineui);
	QObject::connect(rminvoicefreeline, SIGNAL(removePressed(QWidget*)), this, SLOT(removeInvoiceFreeline(QWidget*)));
	block8Layout->addRow(QObject::tr("InvoiceFreeline") +QString::number(InvoiceFreelines.count()),rminvoicefreeline);
}
void InvoiceUI::removeInvoiceFreeline(QWidget* widget){
	if(InvoiceFreelines.count()  > 0){
		InvoiceFreelineUI* invoicefreelineui = (InvoiceFreelineUI*) widget;
		InvoiceFreelines.removeOne(invoicefreelineui);
		RemovebtnWidgets* sender = (RemovebtnWidgets*) this->sender();
		block8Layout->removeRow(sender);
	}
}
void InvoiceUI::fill(Invoice* invoice){
	clear();
	this->invoice = invoice;
	serial->setText(QString::number(invoice->Serial));
	invoiceserial->setIndexByKey(invoice->InvoiceSerialID);
	contact->setIndexByKey(invoice->ContactID);
	project->setIndexByKey(invoice->ProjectID);
	date->setDate(invoice->Date);
	invoiceperiod->setIndexByKey(invoice->InvoicePeriodID);
	invoiceyear->setIndexByKey(invoice->InvoiceYearID);
	duedate->setDate(invoice->DueDate);
	discount->setText(QString::number(invoice->discount));
	allowance->setText(QString::number(invoice->Allowance));
	header->setText(invoice->Header);
	footer->setText(invoice->Footer);
	note->setText(invoice->Note);
	foreach(InvoiceStoreProduct* invoicestoreproduct, invoice->invoicestoreproducts) {
		addInvoiceStoreProduct(invoicestoreproduct);
	}
	foreach(InvoiceService* invoiceservice, invoice->invoiceservices) {
		addInvoiceService(invoiceservice);
	}
	foreach(InvoiceDeliveryOrderFreeline* invoicedeliveryorderfreeline, invoice->invoicedeliveryorderfreelines) {
		addInvoiceDeliveryOrderFreeline(invoicedeliveryorderfreeline);
	}
	foreach(InvoiceFreeline* invoicefreeline, invoice->invoicefreelines) {
		addInvoiceFreeline(invoicefreeline);
	}
}
void InvoiceUI::clear(){
	delete this->invoice;
	this->InvoiceStoreProducts.clear();
	this->InvoiceServices.clear();
	this->InvoiceDeliveryOrderFreelines.clear();
	this->InvoiceFreelines.clear();
	serial->setText("");
	date->setDate(QDate::currentDate());
	duedate->setDate(QDate::currentDate());
	discount->setText("");
	allowance->setText("");
	header->setText("");
	footer->setText("");
	note->setText("");
	QList<RemovebtnWidgets *> RWidgets = this->findChildren<RemovebtnWidgets *>();
	foreach(RemovebtnWidgets * child, RWidgets)
	{
		if(child->parent()->parent()->parent() != 0)
			((ERPFormBlock*)child->parent()->parent())->removeRow(child);
	}
	this->invoice = new Invoice();
}
void InvoiceUI::selectInvoice(){
	if(Invoice::GetStringList().contains(QString::number(this->invoice->Serial)))
	{
		Invoice* con = Invoice::Get(QString::number(this->invoice->Serial));
		if(this->invoice->InvoiceID != con->InvoiceID){
			fill(con);
		}
	}
	else if(invoice->InvoiceID != 0)
		clear();
}
bool InvoiceUI::save(){
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
		invoice->Serial = serial->text().trimmed().toInt();
	}
	if(!invoiceserial->isHidden())
		invoice->InvoiceSerialID = invoiceserial->getKey();
	if(!contact->isHidden())
		invoice->ContactID = contact->getKey();
	if(!project->isHidden())
		invoice->ProjectID = project->getKey();
	if(date->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Date Can't be Empty! \n");
		date->setObjectName("error");
		date->style()->unpolish(date);
		date->style()->polish(date);
		date->update();
	}
	else {
		date->setObjectName("date");
		date->style()->unpolish(date);
		date->style()->polish(date);
		date->update();
		invoice->Date.setDate(date->date().year(),date->date().month(),date->date().day());
	}
	if(!invoiceperiod->isHidden())
		invoice->InvoicePeriodID = invoiceperiod->getKey();
	if(!invoiceyear->isHidden())
		invoice->InvoiceYearID = invoiceyear->getKey();
	if(duedate->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Due Date Can't be Empty! \n");
		duedate->setObjectName("error");
		duedate->style()->unpolish(duedate);
		duedate->style()->polish(duedate);
		duedate->update();
	}
	else {
		duedate->setObjectName("duedate");
		duedate->style()->unpolish(duedate);
		duedate->style()->polish(duedate);
		duedate->update();
		invoice->DueDate.setDate(duedate->date().year(),duedate->date().month(),duedate->date().day());
	}
	if(discount->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("discount Can't be Empty! \n");
		discount->setObjectName("error");
		discount->style()->unpolish(discount);
		discount->style()->polish(discount);
		discount->update();
	}
	else {
		discount->setObjectName("discount");
		discount->style()->unpolish(discount);
		discount->style()->polish(discount);
		discount->update();
		invoice->discount = discount->text().trimmed().toDouble();
	}
	if(allowance->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Allowance Can't be Empty! \n");
		allowance->setObjectName("error");
		allowance->style()->unpolish(allowance);
		allowance->style()->polish(allowance);
		allowance->update();
	}
	else {
		allowance->setObjectName("allowance");
		allowance->style()->unpolish(allowance);
		allowance->style()->polish(allowance);
		allowance->update();
		invoice->Allowance = allowance->text().trimmed().toDouble();
	}
	if(header->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Header Can't be Empty! \n");
		header->setObjectName("error");
		header->style()->unpolish(header);
		header->style()->polish(header);
		header->update();
	}
	else {
		header->setObjectName("header");
		header->style()->unpolish(header);
		header->style()->polish(header);
		header->update();
		invoice->Header = header->text().trimmed();
	}
	if(footer->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Footer Can't be Empty! \n");
		footer->setObjectName("error");
		footer->style()->unpolish(footer);
		footer->style()->polish(footer);
		footer->update();
	}
	else {
		footer->setObjectName("footer");
		footer->style()->unpolish(footer);
		footer->style()->polish(footer);
		footer->update();
		invoice->Footer = footer->text().trimmed();
	}
	if(note->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Note Can't be Empty! \n");
		note->setObjectName("error");
		note->style()->unpolish(note);
		note->style()->polish(note);
		note->update();
	}
	else {
		note->setObjectName("note");
		note->style()->unpolish(note);
		note->style()->polish(note);
		note->update();
		invoice->Note = note->text().trimmed();
	}
	for(int j = 0; j < InvoiceDeliveryOrderFreelines.length(); j++){
		InvoiceDeliveryOrderFreelines.at(j)->description->setObjectName("description");
		InvoiceDeliveryOrderFreelines.at(j)->description->style()->unpolish(InvoiceDeliveryOrderFreelines.at(j)->description);
		InvoiceDeliveryOrderFreelines.at(j)->description->style()->polish(InvoiceDeliveryOrderFreelines.at(j)->description);
		InvoiceDeliveryOrderFreelines.at(j)->description->update();
		for(int w = 0; w < InvoiceDeliveryOrderFreelines.length(); w++){
			if(InvoiceDeliveryOrderFreelines.at(j) != InvoiceDeliveryOrderFreelines.at(w))
				if(InvoiceDeliveryOrderFreelines.at(j)->description->text() == InvoiceDeliveryOrderFreelines.at(w)->description->text()){
					errors = true;
					errorString += QObject::tr("InvoiceDeliveryOrderFreeline has the same description \n");
					InvoiceDeliveryOrderFreelines.at(j)->description->setObjectName("error");
					InvoiceDeliveryOrderFreelines.at(j)->description->style()->unpolish(InvoiceDeliveryOrderFreelines.at(j)->description);
					InvoiceDeliveryOrderFreelines.at(j)->description->style()->polish(InvoiceDeliveryOrderFreelines.at(j)->description);
					InvoiceDeliveryOrderFreelines.at(j)->description->update();
				}}}
	for(int j = 0; j < InvoiceFreelines.length(); j++){
		InvoiceFreelines.at(j)->description->setObjectName("description");
		InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
		InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
		InvoiceFreelines.at(j)->description->update();
		for(int w = 0; w < InvoiceFreelines.length(); w++){
			if(InvoiceFreelines.at(j) != InvoiceFreelines.at(w))
				if(InvoiceFreelines.at(j)->description->text() == InvoiceFreelines.at(w)->description->text()){
					errors = true;
					errorString += QObject::tr("InvoiceFreeline has the same description \n");
					InvoiceFreelines.at(j)->description->setObjectName("error");
					InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
					InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
					InvoiceFreelines.at(j)->description->update();
				}}}
	if(!errors) {
		invoice->save();
		for(int i = 0; i < InvoiceStoreProducts.length(); i++){
			InvoiceStoreProducts.at(i)->invoicestoreproduct->InvoiceID= invoice->InvoiceID;
			if(!InvoiceStoreProducts.at(i)->save()){
				errors = true;
				break; }
		}
		for(int i = 0; i < invoice->invoicestoreproducts.length(); i++){
			bool flag = false;
			for(int j = 0; j < InvoiceStoreProducts.length(); j++){
				if(invoice->invoicestoreproducts.at(i)->InvoiceStoreProductID == InvoiceStoreProducts.at(j)->invoicestoreproduct->InvoiceStoreProductID){
					flag = true;}}
			if(!flag){
				invoice->invoicestoreproducts.at(i)->remove();}
		}
		for(int i = 0; i < InvoiceServices.length(); i++){
			InvoiceServices.at(i)->invoiceservice->InvoiceID= invoice->InvoiceID;
			if(!InvoiceServices.at(i)->save()){
				errors = true;
				break; }
		}
		for(int i = 0; i < invoice->invoiceservices.length(); i++){
			bool flag = false;
			for(int j = 0; j < InvoiceServices.length(); j++){
				if(invoice->invoiceservices.at(i)->InvoiceServiceID == InvoiceServices.at(j)->invoiceservice->InvoiceServiceID){
					flag = true;}}
			if(!flag){
				invoice->invoiceservices.at(i)->remove();}
		}
		for(int i = 0; i < InvoiceDeliveryOrderFreelines.length(); i++){
			InvoiceDeliveryOrderFreelines.at(i)->invoicedeliveryorderfreeline->InvoiceID= invoice->InvoiceID;
			if(!InvoiceDeliveryOrderFreelines.at(i)->save()){
				errors = true;
				break; }
		}
		for(int i = 0; i < invoice->invoicedeliveryorderfreelines.length(); i++){
			bool flag = false;
			for(int j = 0; j < InvoiceDeliveryOrderFreelines.length(); j++){
				if(invoice->invoicedeliveryorderfreelines.at(i)->InvoiceDeliveryOrderFreelineID == InvoiceDeliveryOrderFreelines.at(j)->invoicedeliveryorderfreeline->InvoiceDeliveryOrderFreelineID){
					flag = true;}}
			if(!flag){
				invoice->invoicedeliveryorderfreelines.at(i)->remove();}
		}
		for(int i = 0; i < InvoiceFreelines.length(); i++){
			InvoiceFreelines.at(i)->invoicefreeline->InvoiceID= invoice->InvoiceID;
			if(!InvoiceFreelines.at(i)->save()){
				errors = true;
				break; }
		}
		for(int i = 0; i < invoice->invoicefreelines.length(); i++){
			bool flag = false;
			for(int j = 0; j < InvoiceFreelines.length(); j++){
				if(invoice->invoicefreelines.at(i)->InvoiceFreelineID == InvoiceFreelines.at(j)->invoicefreeline->InvoiceFreelineID){
					flag = true;}}
			if(!flag){
				invoice->invoicefreelines.at(i)->remove();}
		}
		if(!errors){
			InvoiceIndexUI::ShowUI();
			return true;}
		else return false;
	}
	else{ QMessageBox::warning(this, QObject::tr("Invoice"),errorString.trimmed());
		return false;
	}
}
void InvoiceUI::cancel(){
	InvoiceIndexUI::ShowUI();
}
bool InvoiceUI::updateModel(){
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
		invoice->Serial = serial->text().trimmed().toInt();
	}
	if(invoice->InvoiceSerialID == 0)
		invoice->InvoiceSerialID = invoiceserial->getKey();
	if(invoice->ContactID == 0)
		invoice->ContactID = contact->getKey();
	if(invoice->ProjectID == 0)
		invoice->ProjectID = project->getKey();
	if(date->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Date Can't be Empty! \n");
		date->setObjectName("error");
		date->style()->unpolish(date);
		date->style()->polish(date);
		date->update();
	}
	else {
		date->setObjectName("date");
		date->style()->unpolish(date);
		date->style()->polish(date);
		date->update();
		invoice->Date.fromString(date->text().trimmed());
	}
	if(invoice->InvoicePeriodID == 0)
		invoice->InvoicePeriodID = invoiceperiod->getKey();
	if(invoice->InvoiceYearID == 0)
		invoice->InvoiceYearID = invoiceyear->getKey();
	if(duedate->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Due Date Can't be Empty! \n");
		duedate->setObjectName("error");
		duedate->style()->unpolish(duedate);
		duedate->style()->polish(duedate);
		duedate->update();
	}
	else {
		duedate->setObjectName("duedate");
		duedate->style()->unpolish(duedate);
		duedate->style()->polish(duedate);
		duedate->update();
		invoice->DueDate.fromString(duedate->text().trimmed());
	}
	if(discount->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("discount Can't be Empty! \n");
		discount->setObjectName("error");
		discount->style()->unpolish(discount);
		discount->style()->polish(discount);
		discount->update();
	}
	else {
		discount->setObjectName("discount");
		discount->style()->unpolish(discount);
		discount->style()->polish(discount);
		discount->update();
		invoice->discount = discount->text().trimmed().toDouble();
	}
	if(allowance->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Allowance Can't be Empty! \n");
		allowance->setObjectName("error");
		allowance->style()->unpolish(allowance);
		allowance->style()->polish(allowance);
		allowance->update();
	}
	else {
		allowance->setObjectName("allowance");
		allowance->style()->unpolish(allowance);
		allowance->style()->polish(allowance);
		allowance->update();
		invoice->Allowance = allowance->text().trimmed().toDouble();
	}
	if(header->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Header Can't be Empty! \n");
		header->setObjectName("error");
		header->style()->unpolish(header);
		header->style()->polish(header);
		header->update();
	}
	else {
		header->setObjectName("header");
		header->style()->unpolish(header);
		header->style()->polish(header);
		header->update();
		invoice->Header = header->text().trimmed();
	}
	if(footer->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Footer Can't be Empty! \n");
		footer->setObjectName("error");
		footer->style()->unpolish(footer);
		footer->style()->polish(footer);
		footer->update();
	}
	else {
		footer->setObjectName("footer");
		footer->style()->unpolish(footer);
		footer->style()->polish(footer);
		footer->update();
		invoice->Footer = footer->text().trimmed();
	}
	if(note->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Note Can't be Empty! \n");
		note->setObjectName("error");
		note->style()->unpolish(note);
		note->style()->polish(note);
		note->update();
	}
	else {
		note->setObjectName("note");
		note->style()->unpolish(note);
		note->style()->polish(note);
		note->update();
		invoice->Note = note->text().trimmed();
	}
	for(int j = 0; j < InvoiceDeliveryOrderFreelines.length(); j++){
		InvoiceDeliveryOrderFreelines.at(j)->description->setObjectName("description");
		InvoiceDeliveryOrderFreelines.at(j)->description->style()->unpolish(InvoiceDeliveryOrderFreelines.at(j)->description);
		InvoiceDeliveryOrderFreelines.at(j)->description->style()->polish(InvoiceDeliveryOrderFreelines.at(j)->description);
		InvoiceDeliveryOrderFreelines.at(j)->description->update();
		for(int w = 0; w < InvoiceDeliveryOrderFreelines.length(); w++){
			if(InvoiceDeliveryOrderFreelines.at(j) != InvoiceDeliveryOrderFreelines.at(w))
				if(InvoiceDeliveryOrderFreelines.at(j)->description->text() == InvoiceDeliveryOrderFreelines.at(w)->description->text()){
					errors = true;
					errorString +=QObject::tr( "InvoiceDeliveryOrderFreeline has the same description \n");
					InvoiceDeliveryOrderFreelines.at(j)->description->setObjectName("error");
					InvoiceDeliveryOrderFreelines.at(j)->description->style()->unpolish(InvoiceDeliveryOrderFreelines.at(j)->description);
					InvoiceDeliveryOrderFreelines.at(j)->description->style()->polish(InvoiceDeliveryOrderFreelines.at(j)->description);
					InvoiceDeliveryOrderFreelines.at(j)->description->update();
				}}}
	for(int j = 0; j < InvoiceFreelines.length(); j++){
		InvoiceFreelines.at(j)->description->setObjectName("description");
		InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
		InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
		InvoiceFreelines.at(j)->description->update();
		for(int w = 0; w < InvoiceFreelines.length(); w++){
			if(InvoiceFreelines.at(j) != InvoiceFreelines.at(w))
				if(InvoiceFreelines.at(j)->description->text() == InvoiceFreelines.at(w)->description->text()){
					errors = true;
					errorString +=QObject::tr( "InvoiceFreeline has the same description \n");
					InvoiceFreelines.at(j)->description->setObjectName("error");
					InvoiceFreelines.at(j)->description->style()->unpolish(InvoiceFreelines.at(j)->description);
					InvoiceFreelines.at(j)->description->style()->polish(InvoiceFreelines.at(j)->description);
					InvoiceFreelines.at(j)->description->update();
				}}}
	for(int i = 0; i < InvoiceStoreProducts.length(); i++){
		InvoiceStoreProducts.at(i)->invoicestoreproduct->InvoiceID= invoice->InvoiceID;
		if(!InvoiceStoreProducts.at(i)->updateModel()){
			errors = true;
			break; }
	}
	for(int i = 0; i < InvoiceServices.length(); i++){
		InvoiceServices.at(i)->invoiceservice->InvoiceID= invoice->InvoiceID;
		if(!InvoiceServices.at(i)->updateModel()){
			errors = true;
			break; }
	}
	for(int i = 0; i < InvoiceDeliveryOrderFreelines.length(); i++){
		InvoiceDeliveryOrderFreelines.at(i)->invoicedeliveryorderfreeline->InvoiceID= invoice->InvoiceID;
		if(!InvoiceDeliveryOrderFreelines.at(i)->updateModel()){
			errors = true;
			break; }
	}
	for(int i = 0; i < InvoiceFreelines.length(); i++){
		InvoiceFreelines.at(i)->invoicefreeline->InvoiceID= invoice->InvoiceID;
		if(!InvoiceFreelines.at(i)->updateModel()){
			errors = true;
			break; }
	}
	if(!errors){
		return true;
	}
	else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("Invoice"),errorString.trimmed());
		return false;
	}
}
void InvoiceUI::selectionChanged(QString){
	project->addItems(Project::GetPairList(Project::QuerySelect("ContactID = "+QString::number(contact->getKey()))));

	QList<Invoice*> d = Invoice::QuerySelect("Serial = (SELECT MAX(Serial) from Invoice)");
	int i = 1;
	if(!d.isEmpty())
		i = d.first()->Serial +1;
	this->serial->setText(QString::number(i));
	clear();
	foreach(DeliveryOrder * delv,DeliveryOrder::QuerySelect(" ProjectID = "+ QString::number(project->getKey()))){
		foreach(DeliveryOrderStoreProduct *delvProduct,DeliveryOrderStoreProduct::QuerySelect(" DeliveryOrderID = "+ QString::number(delv->DeliveryOrderID)))
			addInvoiceStoreProduct(new InvoiceStoreProduct(0,delvProduct->StoreID,delvProduct->ProductID,delvProduct->Amount,delvProduct->Price,"",""));
		foreach(DeliveryOrderService *delvService,DeliveryOrderService::QuerySelect(" DeliveryOrderID = "+ QString::number(delv->DeliveryOrderID)))
			addInvoiceService(new InvoiceService(0,delvService->ServiceID,delvService->Amount,delvService->Price,"",""));
		foreach(DeliveryOrderFreeline *delvFreeLine,DeliveryOrderFreeline::QuerySelect(" DeliveryOrderID = "+ QString::number(delv->DeliveryOrderID)))
			addInvoiceFreeline(new InvoiceFreeline(delvFreeLine->Description,0,delvFreeLine->Price,1,delvFreeLine->Amount,"",""));
	}



}
