/*************************************
**   Created on:  11/20/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/
#include <QtGui>

#include "barcode.h"
#include "ean13.h"

Barcode::Barcode(QWidget *parent,QString barcode) :
	QWidget(parent)
{
	setFixedSize(500, 90);
	this->barcode = barcode;
	}
void Barcode::draw(QPainter *painter)
{
	//painter->fillRect(painter->window(), Qt::lightGray);

	EAN13 code(barcode);

	if(barcode == "")
	EAN13 code("87654964238");
	//painter->drawText(50,40,"Arbitrary size (400x200pix)");

	//code.draw(QRectF(50, 50, 400, 200), *painter);

	//qreal scale = painter->device()->physicalDpiX() / 25.4;	// dots per mm

	qreal scale = painter->device()->physicalDpiX() / 35.4;	// dots per mm

	//painter->drawText(50,290,"Nominal size (37.29x25.93mm)");
//	painter->drawText(50,90,"Nominal size (37.29x25.93mm)");
	code.draw(QRectF(0, 0, 37.29 * scale, 25.93 * scale), *painter);
}

void Barcode::paintEvent(QPaintEvent *event)
{

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	painter.setViewport(0,0, width(), width());

	draw(&painter);
	event->accept();
}
