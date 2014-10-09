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
}
