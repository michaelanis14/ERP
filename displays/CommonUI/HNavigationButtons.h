/*************************************
**   Created on:  11/19/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef HNAVIGATIONBUTTONS_H
#define HNAVIGATIONBUTTONS_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QHBoxLayout>

class HNavigationButtons : public QWidget
{
	Q_OBJECT
public:
	explicit HNavigationButtons(QWidget *parent = 0);
	class QFont * font;

	void addButton(class QPushButton* pushButton);
	void addControllerButton(QPushButton* pushButton) ;

	void removeAll();
protected:
	void resizeEvent(QResizeEvent * event);
private:
	QList<QPushButton*> navigationButtons;
	QHBoxLayout* layout;


signals:

protected slots:
	void toggle();

public slots:

};

#endif // HNAVIGATIONBUTTONS_H
