



#include "mainwindow.h"
#include "erpdisplay.h"
#include "displays/Contact/contactui.h"
#include "displays/ContactPerson/contactpersonindexui.h"
#include "displays/ContactType/contacttypeindexui.h"
#include "displays/Contact/contactindexui.h"
#include "displays/BankAccount/bankaccountui.h"
#include "displays/Product/productindexui.h"
#include "displays/Product/ProductStoreStateUI.h"
#include "displays/Store/storeindexui.h"
#include "displays/Purchase/purchaseindexui.h"
#include "displays/DeliveryOrder/deliveryorderindexui.h"
#include "displays/Service/serviceindexui.h"
#include "displays/Project/projectindexui.h"
#include "displays/TimeBooking/timebookingindexui.h"
#include "displays/Access/accessindexui.h"

/**
* A class.
* The Main Window class it holds the application default styling setup,
* the setup menu sliding settings and exchanging displays functions
*/

/**
* A constructor.
* Constructs the main window where it holds the displays, connects to the Gestures module to the setup menu slider.
* setting the default styling for the application window.
*/
mainwindow::mainwindow()
{

#ifdef Q_OS_WIN32
	this->setCursor(Qt::BlankCursor);
	this->setWindowFlags(Qt::FramelessWindowHint);
#endif

#ifdef Q_OS_WIN32
	// set a predefined style on windows so that application has an unique impression (not windows-like impression)
	// unfortunately, this style causes performance-issues on embedded linux and therefore is not set on this system.
	// Fortunately, the default linux-style looks prettier than the default windows-style :-)
	//QApplication::setStyle(new QCleanlooksStyle);
#endif


	this->setStyleSheet(
				// make background white
				"MainWindow { background-color: white; } "
				"formPanel { background-color: white; } "
				"QWidget { outline: 0; }"  // removing dotted-border in all controls
				"QWidget:focus { outline: 0; }"  // removing dotted-border in all controls

				"QMessageBox {font-size:16px; }"

				//"QWidget#formPanel { background-color: white; } "
				"QScrollArea { background-color: white; } "

				"QPushButton:checked {	background-color: rgb(200,200,200) }"  // checked style ist wichtig für gedrückte Menü-Buttons

				"QLabel#NrName { color: darkblue; } "
				"QLabel#errorMessage { color: darkred; font-size:16px } "

				// make QCheckBox bigger
				//"QCheckBox { width: 26px; height: 26px; } "
				//"QCheckBox::indicator { width: 38px; height: 38px; } "
				//"QCheckBox::indicator:unchecked { image: url(:/icons/checkbox/checkbox_unchecked.png); } "
				//"QCheckBox::indicator:checked { image: url(:/icons/checkbox/checkbox_checked.png); } "
				//"QCheckBox::indicator:focus { background-image: url(:/icons/checkbox/checkbox_unchecked_focus.png); } "
				//"QCheckBox::indicator:disabled { background-image: url(:/icons/checkbox/checkbox_disabled.png); } "
				""
				"QLineEdit {"
				//"background-color: gray;"
				"border-style: outset;"
				"border-width: 0.5px;"
				"border-radius: 5px;"
				"border-color: black;"
				"font: 14px;"
				//"min-width: 10em;"
				//"padding: 6px;"
				"}"

				"QLineEdit:focus {"
				//"background-color: rgb(76, 200, 98);"
				"border-style: inset;"
				"}"
				"QLineEdit#error { border-style: outset; border-width: 0.5px; border-radius: 5px; border-color: red;}"


				"QWidget#baseWidget {"
				"border-radius: 5px; "
				"border: 1px solid black;"
				"border: 2px groove gray;"
				"}"
				);
	this->setMinimumSize(800,600);

	this->setContentsMargins(0, 0, 0, 0);


	currentDisplay = 0;

	QIcon icon1(":/new/Mainscreen/Resources/Mainscreen/ContactsInactive.png");

	navigation = new NavigationButtons(this);
	navigation->setGeometry(0,0,120,this->height());


	btnHome = new QToolButton(navigation);
	btnHome->setIcon(icon1);
	btnHome->setText(QObject::tr("Home"));
	navigation->addButton(btnHome);
	connect(this->btnHome, SIGNAL(clicked()), this, SLOT(btnHomeClicked()));

	btnContacts = new QToolButton(navigation);
	btnContacts->setIcon(icon1);
	btnContacts->setText(QObject::tr("Contacts"));
	navigation->addButton(btnContacts);
	connect(this->btnContacts, SIGNAL(clicked()), this, SLOT(btnContactsClicked()));

	btnProjects = new QToolButton(navigation);
	btnProjects->setIcon(icon1);
	btnProjects->setText(QObject::tr("Projects"));
	navigation->addButton(btnProjects);
	connect(this->btnProjects, SIGNAL(clicked()), this, SLOT(btnProjectsClicked()));

	btnProducts = new QToolButton(navigation);
	btnProducts->setIcon(icon1);
	btnProducts->setText(QObject::tr("Products"));
	navigation->addButton(btnProducts);
	connect(this->btnProducts, SIGNAL(clicked()), this, SLOT(btnProductsClicked()));

	btnAccounting = new QToolButton(navigation);
	btnAccounting->setIcon(icon1);
	btnAccounting->setText(QObject::tr("Accounting"));
	navigation->addButton(btnAccounting);
	connect(this->btnAccounting, SIGNAL(clicked()), this, SLOT(btnAccountingClicked()));

	btnReports = new QToolButton(navigation);
	btnReports->setIcon(icon1);
	btnReports->setText(QObject::tr("Reports"));
	navigation->addButton(btnReports);
	connect(this->btnReports, SIGNAL(clicked()), this, SLOT(btnReportsClicked()));

	innerNavigation = new HNavigationButtons(this);
	innerNavigation->setGeometry(this->navigation->width(),0,this->width()-this->navigation->width(),40);



	boxLayout = new QVBoxLayout(this);
	boxLayout->setContentsMargins(this->navigation->width(), this->innerNavigation->height(), 0, 0);

//Home
	inNavAccess = new QPushButton(icon1,QObject::tr("Access"));
	inNavAccess->setObjectName("inNavAccess");
	connect(this->inNavAccess, SIGNAL(clicked()), this, SLOT(innerNavClicked()));



//Contacts
	inNavContacts = new QPushButton(icon1,QObject::tr("Contacts"));
	inNavContacts->setObjectName("inNavContacts");
	connect(this->inNavContacts, SIGNAL(clicked()), this, SLOT(innerNavClicked()));
	inNavcontactPersones = new QPushButton(icon1,"ContactPersone");
	inNavcontactPersones->setObjectName("inNavcontactPersones");
	connect(this->inNavcontactPersones, SIGNAL(clicked()), this, SLOT(innerNavClicked()));
//Projects
	inNavProjects =	 new QPushButton(icon1,QObject::tr("Projects"));
	inNavProjects->setObjectName("inNavProjects");
	connect(this->inNavProjects, SIGNAL(clicked()), this, SLOT(innerNavClicked()));

	inNavTimeBookings = new QPushButton(icon1,QObject::tr("TimeBookings"));
	inNavTimeBookings->setObjectName("inNavTimeBookings");
	connect(this->inNavTimeBookings, SIGNAL(clicked()), this, SLOT(innerNavClicked()));

	inNavServices = new QPushButton(icon1,QObject::tr("Service"));
	inNavServices->setObjectName("inNavService");
	connect(this->inNavServices, SIGNAL(clicked()), this, SLOT(innerNavClicked()));


//Products
	inNavProducts = new QPushButton(icon1,QObject::tr("Products"));
	inNavProducts->setObjectName("inNavProducts");
	connect(this->inNavProducts, SIGNAL(clicked()), this, SLOT(innerNavClicked()));
		inNavStoreHouse = new QPushButton(icon1,QObject::tr("Store House"));
	inNavStoreHouse->setObjectName("inNavStoreHouse");
	connect(this->inNavStoreHouse, SIGNAL(clicked()), this, SLOT(innerNavClicked()));
	inNavPurchase = new QPushButton(icon1,QObject::tr("Purchase"));
	inNavPurchase->setObjectName("inNavPurchase");
	connect(this->inNavPurchase, SIGNAL(clicked()), this, SLOT(innerNavClicked()));
	inNavDeliveryOrder = new QPushButton(icon1,QObject::tr("Delivery Order"));
	inNavDeliveryOrder->setObjectName("inNavDeliveryOrder");
	connect(this->inNavDeliveryOrder, SIGNAL(clicked()), this, SLOT(innerNavClicked()));
	inNavStoreStatus = new QPushButton(icon1,QObject::tr("StoreStatus"));
	inNavStoreStatus->setObjectName("inNavStoreStatus");
	connect(this->inNavStoreStatus, SIGNAL(clicked()), this, SLOT(innerNavClicked()));



}
// initialize static singleton pointer
mainwindow* mainwindow::p_instance = 0;

// initialization of static singleton lastEvent for the last event on the the application
QDateTime mainwindow::lastEvent = QDateTime::currentDateTime();

/**
* A function.
* receives display and add it the main window to be the current display
* @param display pointer the the display that will be shown on the main window
*/
void mainwindow::ShowDisplay(ERPDisplay * display) {
	if (p_instance==0) {
		p_instance = new mainwindow();
		p_instance->show();
	}

	if (p_instance->currentDisplay != 0) {
		//	p_instance->currentDisplay->blockSignals(true);
		p_instance->currentDisplay->hide();
	}
	//
	//	display->setAutoFillBackground(true);
	//	p_instance->mainLayout->removeItem(p_instance->boxLayout);
	//delete p_instance->boxLayout;
	//p_instance->boxLayout = new QVBoxLayout(this);
	//p_instance->boxLayout->setContentsMargins(0, 0, 0, 0);
	//p_instance->mainLayout->addWidget((QWidget*)display,1,0,1,1);
	p_instance->boxLayout->addWidget((QWidget*)display);
	//p_instance->mainLayout->addLayout(p_instance->boxLayout,1,1,-1,-1);
	p_instance->setLayout(p_instance->boxLayout);

	//p_instance->mainLayout->addLayout(p_instance->boxLayout,1,1,-1,-1);

	p_instance->currentDisplay = display;

	//p_instance->currentDisplay->blockSignals(false);
	display->show();
	display->setFocus();
}
/**
* A function.
* returns the current display object
*/
ERPDisplay* mainwindow::GetCurrentDisplay() {
	return p_instance->currentDisplay;
}
/**
* A function.
* returns the main window object
*/
mainwindow* mainwindow::GetMainDisplay() {

	return p_instance;
}

/**
* A function.
* receives Mouse press events and according to label pressed handles the action
*/
void mainwindow::mousePressEvent(QMouseEvent *event)
{
	QLabel * child = static_cast<QLabel*>(childAt(event->pos()));
	if(!child)
		return;
	else {
		//qDebug() << child->objectName();
		if(child->objectName() == "lblContacts"){
			//		if(!contactIndexUI::GetUI()->isVisible()){
			//	qDebug() << child->objectName();
			//	lblContacts->setPixmap(QPixmap(":/new/Mainscreen/Resources/Mainscreen/ContactsActive.png"));
			//ContactUI::ShowUI();
			//BankAccountUI::ShowUI();
			ContactIndexUI::ShowUI();
			//		}
		}
		else{
			//		qDebug() << "Visb";
			//ContactUI::GetUI()->setHidden(true);
			//lblContacts->setPixmap(QPixmap(":/new/Mainscreen/Resources/Mainscreen/ContactsInactive.png"));

		}

	}

}


void mainwindow::btnHomeClicked() {
	innerNavigation->removeAll();
	innerNavigation->addButton(inNavAccess);
	inNavAccess->click();


}
void mainwindow::btnContactsClicked(){
	innerNavigation->removeAll();
	innerNavigation->addButton(inNavContacts);
	innerNavigation->addButton(inNavcontactPersones);
	inNavContacts->click();
}

void mainwindow::btnProductsClicked(){
	innerNavigation->removeAll();
	innerNavigation->addButton(inNavProducts);
	innerNavigation->addButton(inNavStoreHouse);
	innerNavigation->addButton(inNavPurchase);
	innerNavigation->addButton(inNavDeliveryOrder);
	innerNavigation->addButton(inNavStoreStatus);
	inNavProducts->click();
}
void mainwindow::btnAccountingClicked(){;}
void mainwindow::btnReportsClicked(){;}
void mainwindow::innerNavClicked(){
	QPushButton* sender = (QPushButton*) this->sender();
	if(!sender)
		return;
	if(sender->objectName() == "inNavContacts")
		ContactIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavcontactPersones")
		ContactPersonIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavcontactType")
		ContactTypeIndexUI::ShowUI();
	//Product
	else  if(sender->objectName() == "inNavProducts")
		ProductIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavService")
		ServiceIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavStoreHouse")
		StoreIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavPurchase")
		PurchaseIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavDeliveryOrder")
		DeliveryOrderIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavStoreStatus")
		ProductStoreStateUI::ShowUI();
	else  if(sender->objectName() == "inNavProjects")
		ProjectIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavTimeBookings")
		TimeBookingIndexUI::ShowUI();
	else  if(sender->objectName() == "inNavAccess")
		AccessIndexUI::ShowUI();


}

void mainwindow::btnProjectsClicked(){
	innerNavigation->removeAll();
	innerNavigation->addButton(inNavProjects);
	innerNavigation->addButton(inNavTimeBookings);
	innerNavigation->addButton(inNavServices);

	inNavProjects->click();

}
void mainwindow::resizeEvent(QResizeEvent * event){

//qDebug() << "Res";
	if(this->currentDisplay != 0)
		if(currentDisplay->objectName().contains("Index")){
			QList<QTableView *> tabel = currentDisplay->findChildren<QTableView *>();
			foreach(QTableView * child, tabel)
			{
				if(child != 0){
					child->setMinimumWidth(event->size().width() - this->navigation->width() - 50);
					child->setMinimumHeight(event->size().height() - inNavContacts->height() - 100);
				}
			}

		}
	navigation->resizeEvent(event);
	event->accept();
}
