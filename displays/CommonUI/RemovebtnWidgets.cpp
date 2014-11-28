/*************************************
**   Created on:  11/24/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "RemovebtnWidgets.h"

RemovebtnWidgets::RemovebtnWidgets(QWidget *parent,QWidget* widget) :
	QWidget(parent)
{
	this->setObjectName("RemovebtnWidgets");
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(0,0,0,0);

	remove = new QLabel(this);
	remove->setObjectName("remove");
	remove->setPixmap(QPixmap(":/Buttons/Resources/Buttons/remove.png"));
	remove->setMaximumWidth(20);
	remove->setMaximumHeight(20);
	remove->setScaledContents(true);
	remove->setParent(this);
	layout->addWidget(remove,0,Qt::AlignTop);
	if(widget != 0){
	layout->addWidget(widget,0,Qt::AlignRight);
	this->widget = widget;
	}
}
void RemovebtnWidgets::mousePressEvent(QMouseEvent *event){

	QLabel * child = static_cast<QLabel*>(childAt(event->pos()));
	if(!child)
		return;
	else {
		if(child->objectName() == "remove"){
			remove->setPixmap(QPixmap(":/Buttons/Resources/Buttons/removeActive.png"));
			emit removePressed(this->widget);
		}
	}
	QWidget::mousePressEvent(event);

}

