



#include "mainwindow.h"
#include "erpdisplay.h"
#include "displays/Contact/contactui.h"
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
				"QWidget { outline: 0; }"  // removing dotted-border in all controls
				"QWidget:focus { outline: 0; }"  // removing dotted-border in all controls

				"QMessageBox {font-size:16px; }"

				"QWidget#formPanel { background-color: white; } "
				"QScrollArea { background-color: white; } "

				"QPushButton:checked {	background-color: rgb(200,200,200) }"  // checked style ist wichtig für gedrückte Menü-Buttons

				"QLabel#NrName { color: darkblue; } "
				"QLabel#errorMessage { color: darkred; font-size:16px } "

				// make QCheckBox bigger
				//"QCheckBox { width: 26px; height: 26px; } "
				"QCheckBox::indicator { width: 38px; height: 38px; } "
				"QCheckBox::indicator:unchecked { image: url(:/icons/checkbox/checkbox_unchecked.png); } "
				"QCheckBox::indicator:checked { image: url(:/icons/checkbox/checkbox_checked.png); } "
				"QCheckBox::indicator:focus { background-image: url(:/icons/checkbox/checkbox_unchecked_focus.png); } "
				"QCheckBox::indicator:disabled { background-image: url(:/icons/checkbox/checkbox_disabled.png); } "
				""
				"QLineEdit {"
				"background-color: gray;"
				"border-style: outset;"
				"border-width: 2px;"
				"border-radius: 10px;"
				"border-color: beige;"
				"font: 14px;"
				//"min-width: 10em;"
				//"padding: 6px;"
				"}"
				"QLineEdit:focus {"
				"background-color: rgb(76, 200, 98);"
				"border-style: inset;"
				"}"
		);
	//this->setSize(480,272);



	currentDisplay = 0;

	mainLayout = new QGridLayout ();
	mainLayout->setContentsMargins(0, 0, 0, 0);

	boxLayout = new QVBoxLayout();
	boxLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->addLayout(boxLayout,1,1,1,1);


	lblContacts = new QLabel();
	lblContacts->setScaledContents(true);
	//label->setWordWrap(true);
	lblContacts->setPixmap(QPixmap(":/new/Mainscreen/Resources/Mainscreen/ContactsInactive.png"));

	lblContacts->setMaximumHeight(100);
	lblContacts->setMaximumWidth(100);
	lblContacts->setObjectName("lblContacts");

	mainLayout->addWidget(lblContacts,1,0,1,1);

	for(int i = 2; i <5 ; i++){
		label = new QLabel();
		label->setScaledContents(true);
		label->setWordWrap(true);
		label->setText("This is it");
		label->setMinimumWidth(0);

		mainLayout->addWidget(label,i,0,1,1);
	}





	for(int i = 0; i <5 ; i++){
		label = new QLabel();
		label->setScaledContents(true);
		label->setWordWrap(true);
		label->setText("This is it");
		//label->setMinimumWidth(0);
		label->setMaximumHeight(30);
		//label->setAutoFillBackground(true);
		mainLayout->addWidget(label,0,i,1,1);
	}
	//	this->showFullScreen();

	this->setLayout(mainLayout);


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
	p_instance->mainLayout->removeItem(p_instance->boxLayout);
	delete p_instance->boxLayout;
	p_instance->boxLayout = new QVBoxLayout();
	p_instance->boxLayout->setContentsMargins(0, 0, 0, 0);
	//p_instance->mainLayout->addWidget((QWidget*)display,1,0,1,1);
	p_instance->boxLayout->addWidget((QWidget*)display);
	p_instance->mainLayout->addLayout(p_instance->boxLayout,1,1,-1,-1);
	p_instance->setLayout(p_instance->mainLayout);

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
			lblContacts->setPixmap(QPixmap(":/new/Mainscreen/Resources/Mainscreen/ContactsActive.png"));
			ContactUI::ShowUI();
			//		}
		}
		else{
			//		qDebug() << "Visb";
			ContactUI::GetUI()->setHidden(true);
			lblContacts->setPixmap(QPixmap(":/new/Mainscreen/Resources/Mainscreen/ContactsInactive.png"));

		}

	}

}

void mainwindow::updateSize(){
	int height = this->height();
	//int width = 0;
	if(p_instance->currentDisplay != 0){

			if(p_instance->currentDisplay->flowLayout != 0){
				for(int i = 0; i < p_instance->currentDisplay->flowLayout->itemList.count(); i++){
					height += p_instance->currentDisplay->flowLayout->itemList.at(i)->geometry().height();
		//	width += p_instance->currentDisplay->flowLayout->itemList.at(i)->geometry().width();
				}
				p_instance->currentDisplay->repaint();
			}
			this->repaint();
			p_instance->currentDisplay->formPanel->setGeometry(this->x(),this->y(),this->width(),height);

	}
}

void mainwindow::resizeEvent(QResizeEvent * event){
	this->updateSize();
	QWidget::resizeEvent(event);

}
