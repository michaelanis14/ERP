/*************************************
**   Created on:  10/23/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "addremovebuttons.h"

AddRemoveButtons::AddRemoveButtons(QWidget *parent) :
	QWidget(parent)
{
	this->setFixedHeight(20);
	//this->setFixedWidth(120);
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(0,0,0,0);
	add = new QLabel();
	add->setObjectName("add");
	add->setPixmap(QPixmap(":/Buttons/Resources/Buttons/add.png"));
	add->setMaximumWidth(20);
	add->setMaximumHeight(20);
	add->setScaledContents(true);

	remove = new QLabel();
	remove->setObjectName("remove");
	remove->setPixmap(QPixmap(":/Buttons/Resources/Buttons/remove.png"));
	remove->setMaximumWidth(20);
	remove->setMaximumHeight(20);
	remove->setScaledContents(true);

	layout->addStretch(1);
	layout->addWidget(remove,0,Qt::AlignCenter);
	layout->addStretch(0.5);
	layout->addWidget(add,0,Qt::AlignCenter);
	layout->addStretch(1);
}

void AddRemoveButtons::mousePressEvent(QMouseEvent *event){

	QLabel * child = static_cast<QLabel*>(childAt(event->pos()));
	if(!child)
		return;
	else {
		if(child->objectName() == "add"){
			add->setPixmap(QPixmap(":/Buttons/Resources/Buttons/addActive.png"));
			emit addPressed();
		}
		else if(child->objectName() == "remove"){
			remove->setPixmap(QPixmap(":/Buttons/Resources/Buttons/removeActive.png"));
			emit removePressed();
		}
	}
	QWidget::mousePressEvent(event);

}

void AddRemoveButtons::mouseReleaseEvent(QMouseEvent *event){

	QLabel * child = static_cast<QLabel*>(childAt(event->pos()));
	if(!child)
		return;
	else {
		add->setPixmap(QPixmap(":/Buttons/Resources/Buttons/add.png"));
		remove->setPixmap(QPixmap(":/Buttons/Resources/Buttons/remove.png"));

		if(child->objectName() == "add"){
		}
		else if(child->objectName() == "remove"){

		}
	}
}
