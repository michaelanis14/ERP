/*************************************
**   Created on:  11/19/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "HNavigationButtons.h"
#include "../mainwindow.h"


HNavigationButtons::HNavigationButtons(QWidget *parent) :
	QWidget(parent)
{

	font = NULL;
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(2,2,2,0);
	this->setContentsMargins(0,0,1,0);
}

void HNavigationButtons::addButton(QPushButton* pushButton) {
	layout->addWidget(pushButton);
//	layout->addStretch(1);
		pushButton->setParent(this);
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
	this->adjustSize();
}
void HNavigationButtons::addControllerButton(QPushButton* pushButton) {

	layout->addStretch(1);
	layout->addWidget(pushButton);
	pushButton->setParent(this);
	layout->addStretch(1);

	if (this->font != NULL) {
		pushButton->setFont(*font);
	}
	navigationButtons.append(pushButton);

	connect(pushButton,SIGNAL(clicked()),this, SLOT(toggle()));
	this->adjustSize();
}
void HNavigationButtons::removeAll() {

	QList<QWidget *> Widgets = this->findChildren<QWidget *>();
		foreach(QWidget * child, Widgets)
		{
			 child->setHidden(true);
			 child->setParent(0);
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
void HNavigationButtons::resizeEvent(QResizeEvent * event){


	this->setFixedWidth(mainwindow::GetMainDisplay()->width() - mainwindow::GetMainDisplay()->navigation->width());
	this->setFixedHeight(39);
	//this->adjustSize();
	QWidget::resizeEvent(event);
//	event->accept();
}
