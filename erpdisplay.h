#ifndef ERPDISPLAY_H
#define ERPDISPLAY_H
#include "displays/CommonUI/flowlayout.h"

#include <QtWidgets/QWidget>
#include "QScrollArea"

class ERPDisplay : public QWidget
{
	Q_OBJECT
public:
	explicit ERPDisplay(QWidget *parent = 0);
	QWidget* formPanel;
	class QScrollArea* scrollAreaFormPanel;
	FlowLayout* flowLayout;

signals:

public slots:

};

#endif // ERPDISPLAY_H
