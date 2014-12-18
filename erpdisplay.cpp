#include "erpdisplay.h"
#include "displays/MainWindow.h"


/**
* A class.
* the parent display for the application, other displays inherit all its properties
*/

/**
* A constructor.
* Constructs the display widget inheriting from QWidget,
* setting all default parameters for displays.
*/
ERPDisplay::ERPDisplay(QWidget *parent) : QWidget(parent) {

	this->setContentsMargins(0,0,0,0);
	setMouseTracking( true );


	scrollAreaFormPanel = new QScrollArea(this);
	scrollAreaFormPanel->setObjectName("scrollAreaFormPanel");
	scrollAreaFormPanel->setContentsMargins(0,0,0,0);
	scrollAreaFormPanel->setFrameStyle(QFrame::NoFrame);
	//scrollAreaFormPanel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//scrollAreaFormPanel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//scrollAreaFormPanel->setGeometry(0,0,800,530);

	//formPanel = new QWidget(scrollAreaFormPanel);
	formPanel = new QWidget();
	//	formPanel->setFixedWidth();
	formPanel->setContentsMargins(0,0,0,0);
	formPanel->setObjectName("formPanel");

	//	formPanel->setFont(font3);
	scrollAreaFormPanel->setWidget(this->formPanel);
	scrollAreaFormPanel->setWidgetResizable(true);
	controllers = new HNavigationButtons(this);
	controllers->setGeometry(0,this->scrollAreaFormPanel->height(),this->width(),40);

}
void ERPDisplay::updateSize(){

}
void ERPDisplay::resizeEvent(QResizeEvent * event){

	if((event->size().height() - this->controllers->height()) > 50 && event->size().width() > 50){
		this->formPanel->setFixedWidth(event->size().width());
		this->scrollAreaFormPanel->setFixedHeight(event->size().height() - this->controllers->height());
		this->scrollAreaFormPanel->setFixedWidth(event->size().width());
		this->controllers->setGeometry(0,this->scrollAreaFormPanel->height(),this->width(),40);
	}

	QWidget::resizeEvent(event);

}

void ERPDisplay::showEvent(QShowEvent * event){
	if(false){
		this->formPanel->setFixedWidth(mainwindow::GetMainDisplay()->width());
		this->scrollAreaFormPanel->setFixedHeight(mainwindow::GetMainDisplay()->height() - this->controllers->height());
		this->scrollAreaFormPanel->setFixedWidth(mainwindow::GetMainDisplay()->width());
		this->controllers->setGeometry(0,this->scrollAreaFormPanel->height(),this->width(),40);
	}

	event->accept();


}


