/*************************************
**   Created on:  10/23/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef ADDREMOVEBUTTONS_H
#define ADDREMOVEBUTTONS_H

#include <QtGui/QtGui>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class AddRemoveButtons : public QWidget
{
	Q_OBJECT
public:
	AddRemoveButtons(QWidget *parent = 0);

private:
	QHBoxLayout *layout;
	QPushButton* add;
protected:


public slots:
	void addPress();

signals:
	void addPressed();
	void removePressed();

};

#endif // ADDREMOVEBUTTONS_H
