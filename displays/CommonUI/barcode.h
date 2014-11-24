/*************************************
**   Created on:  11/20/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef BARCODE_H
#define BARCODE_H

#include <QWidget>

class Barcode : public QWidget
{
	Q_OBJECT
public:
	Barcode(QWidget *parent = 0);
	void draw(QPainter *painter);

	protected:
		void paintEvent(QPaintEvent *event);

};

#endif // BARCODE_H
