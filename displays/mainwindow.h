#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QtGui>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QDateTime>

#include "erpdisplay.h"

class mainwindow : public QWidget
{
	Q_OBJECT
public:
	mainwindow();
	static void ShowDisplay(class ERPDisplay * display);
	static ERPDisplay* GetCurrentDisplay();
	static mainwindow* GetMainDisplay();
	static QDateTime lastEvent;
	QLabel* label;
	QLabel *lblContacts;
	void updateSize();

private:
	static mainwindow* p_instance;
	class ERPDisplay* currentDisplay;
	class QVBoxLayout* boxLayout;
	QGridLayout* mainLayout;
protected:
	void mousePressEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent * event);


};

#endif // MAINWINDOW_H
