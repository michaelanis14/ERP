#include "erpdisplay.h"


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

	// prepare this widget, where the rest of the GUI-elements reside
  //  this->setGeometry(0,0,480,272);
	this->setContentsMargins(0,0,0,0);
	setMouseTracking( true );
	// prepare ScrollArea where the form panel resides
	scrollAreaFormPanel = new QScrollArea(this);
	scrollAreaFormPanel->setObjectName("scrollAreaFormPanel");  // for debugging
	scrollAreaFormPanel->setGeometry(0,0,1024,623);
	scrollAreaFormPanel->setContentsMargins(0,0,0,0);
	//scrollAreaFormPanel->setAutoFillBackground(false);
	scrollAreaFormPanel->setFrameStyle(QFrame::NoFrame);
	//scrollAreaFormPanel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//scrollAreaFormPanel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// prepare form panel, where the rest of the GUI-elements reside
	formPanel = new QWidget(scrollAreaFormPanel);
	//formPanel->setAutoFillBackground(false);
	formPanel->setObjectName("formPanel");  // for stylesheet reference
	formPanel->setGeometry(0,0,1024,623);
	formPanel->setContentsMargins(0,0,0,0);
//	formPanel->setFont(font3);
	scrollAreaFormPanel->setWidget(this->formPanel);  // coordinates of formPanel are relative to scrollArea now

	//scrollAreaFormPanel->setGeometry(0,75,1024,1455+60);  // nimm Rücksicht auf Wizards, wo es keine Toolbar gibt
//	scrollAreaFormPanel->setBaseSize(1024,310);
	//scrollAreaFormPanel->setMinimumHeight(310);
	//crollAreaFormPanel->setMaximumHeight(910);


}
