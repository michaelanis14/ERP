/*************************************
**   Created on:  11/19/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/
#include "../mainwindow.h"
#include "navigationButtons.h"

NavigationButtons::NavigationButtons(QWidget *parent) :
	QWidget(parent)
{

	font = NULL;
	layout = new QVBoxLayout(this);
	layout->setContentsMargins(0,0,0,0);
}

void NavigationButtons::addButton(QToolButton* pushButton) {
	pushButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	pushButton->setFixedWidth(this->width()-5);
	pushButton->setIconSize(QSize(this->width()-30, this->width()-30));
	layout->addWidget(pushButton);
	layout->addStretch(1);

	pushButton->setCheckable(true);
	if (this->font != NULL) {
		pushButton->setFont(*font);
	}
	navigationButtons.append(pushButton);


	connect(pushButton,SIGNAL(clicked()),this, SLOT(toggle()));
this->adjustSize();
}

void NavigationButtons::toggle() {
	QToolButton* sender = (QToolButton*) this->sender();
	for (int i=0; i< this->navigationButtons.size(); i++) {
		if (this->navigationButtons.at(i) != sender) {
			this->navigationButtons.at(i)->setChecked(false);
		}
		else this->navigationButtons.at(i)->setChecked(true);
	}
}
void NavigationButtons::resizeEvent(QResizeEvent * event){


	this->setFixedHeight(mainwindow::GetMainDisplay()->height());
	this->setFixedWidth(mainwindow::GetMainDisplay()->navigation->width());
	for (int i=0; i< this->navigationButtons.size(); i++) {
		navigationButtons.at(i)->setFixedHeight(this->height()/navigationButtons.size());
			}
	this->adjustSize();

	//this->adjustSize();
	QWidget::resizeEvent(event);
//	event->accept();
}
