/*************************************
**   Created on:  11/19/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef NAVIGATIONBUTTONS_H
#define NAVIGATIONBUTTONS_H

#include <QWidget>
#include <QToolButton>
#include <QButtonGroup>
#include <QVBoxLayout>

class NavigationButtons : public QWidget
{
	Q_OBJECT
public:
	explicit NavigationButtons(QWidget *parent = 0);

	class QFont * font;

	void addButton(class QToolButton* pushButton);
	void resizeEvent(QResizeEvent * event);
private:
	QList<QToolButton*> navigationButtons;
	QVBoxLayout* layout;


signals:

protected slots:
	void toggle();

public slots:

};

#endif // NAVIGATIONBUTTONS_H
