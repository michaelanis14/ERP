/*************************************
**   Created on:  11/24/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef REMOVEBTNWIDGETS_H
#define REMOVEBTNWIDGETS_H
#include <QtGui/QtGui>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class RemovebtnWidgets : public QWidget
{
	Q_OBJECT
public:
	explicit RemovebtnWidgets(QWidget *parent = 0,QWidget* widget =0);
private:
	QHBoxLayout *layout;
	QLabel* remove;
	QWidget* widget;
protected:
	void mousePressEvent(QMouseEvent *event);
signals:
	void removePressed(QWidget* widget);


};

#endif // REMOVEBTNWIDGETS_H
