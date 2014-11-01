#ifndef ERPDISPLAY_H
#define ERPDISPLAY_H
#include "displays/CommonUI/flowlayout.h"

#include <QtWidgets/QWidget>
#include "QScrollArea"
#include "QDebug"
#include "QResizeEvent"

class ERPDisplay : public QWidget
{
	Q_OBJECT
public:
	explicit ERPDisplay(QWidget *parent = 0);
	QWidget* formPanel;
	QScrollArea* scrollAreaFormPanel;
	FlowLayout* flowLayout;
	void updateSize();
signals:

public slots:

protected:
	//void mousePressEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent * event);
	void showEvent(QShowEvent * event);

};

#endif // ERPDISPLAY_H
