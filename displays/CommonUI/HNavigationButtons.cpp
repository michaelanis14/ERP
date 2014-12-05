/*************************************
**   Created on:  11/19/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "HNavigationButtons.h"


HNavigationButtons::HNavigationButtons(QWidget *parent) :
	QWidget(parent)
{

	font = NULL;
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(2,0,2,0);
	this->setContentsMargins(0,0,1,0);
}

void HNavigationButtons::addButton(QPushButton* pushButton) {
	layout->addWidget(pushButton);
	layout->addStretch(1);
	pushButton->setFlat(true);
	pushButton->setCheckable(true);

	if (this->font != NULL) {
		pushButton->setFont(*font);
	}
	navigationButtons.append(pushButton);
	for (int i=0; i< this->navigationButtons.size(); i++) {
		navigationButtons.at(i)->setFixedWidth(this->width()/navigationButtons.size());
	}

	pushButton->setVisible(true);
	connect(pushButton,SIGNAL(clicked()),this, SLOT(toggle()));

}
void HNavigationButtons::addControllerButton(QPushButton* pushButton) {
	layout->addStretch(1);
	layout->addWidget(pushButton);
	layout->addStretch(1);

	if (this->font != NULL) {
		pushButton->setFont(*font);
	}
	navigationButtons.append(pushButton);

	connect(pushButton,SIGNAL(clicked()),this, SLOT(toggle()));

}
void HNavigationButtons::removeAll() {

	QList<QWidget *> Widgets = this->findChildren<QWidget *>();
		foreach(QWidget * child, Widgets)
		{
			 child->setHidden(true);
			 navigationButtons.clear();

		}
}


void HNavigationButtons::toggle() {
	QPushButton* sender = (QPushButton*) this->sender();
	for (int i=0; i< this->navigationButtons.size(); i++) {
		if (this->navigationButtons.at(i) != sender) {
			this->navigationButtons.at(i)->setChecked(false);
		}
		else this->navigationButtons.at(i)->setChecked(true);
	}
}
