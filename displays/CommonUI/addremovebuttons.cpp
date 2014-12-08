/*************************************
**   Created on:  10/23/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "addremovebuttons.h"

AddRemoveButtons::AddRemoveButtons(QWidget *parent) :
	QWidget(parent)
{
	//this->setFixedHeight(20);
	//this->setFixedWidth(120);
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(0,0,0,0);
	add = new QPushButton("Add");
	QObject::connect(add, SIGNAL(clicked()), this, SLOT(addPress()));
	add->setObjectName("add");
//	layout->addStretch(1);
	layout->addWidget(add,0,Qt::AlignCenter);
//	layout->addStretch(1);
}
void AddRemoveButtons::addPress(){
		emit addPressed();
	}




