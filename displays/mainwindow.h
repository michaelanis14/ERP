#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QtGui>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QDateTime>

#include "erpdisplay.h"
#include "CommonUI/navigationButtons.h"
#include "CommonUI/HNavigationButtons.h"

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
	class NavigationButtons* navigation;
	class HNavigationButtons* innerNavigation;
	class QToolButton* btnHome;
	class QToolButton* btnContacts;
	class QToolButton* btnProducts;
	class QToolButton* btnAccounting;
	class QToolButton* btnReports;

//Contacts
	class QPushButton* inNavContacts;
	class QPushButton* inNavcontactPersones;
	class QPushButton* inNavcontactType;
//Products
	class QPushButton* inNavProducts;
	class QPushButton* inNavService;
	class QPushButton* inNavStoreHouse;
	class QPushButton* inNavPurchase;
	class QPushButton* inNavDeliveryOrder;
private:
	static mainwindow* p_instance;
	class ERPDisplay* currentDisplay;
	class QVBoxLayout* boxLayout;
protected:
	void mousePressEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent * event);

protected slots:
	void btnHomeClicked();
	void btnContactsClicked();
	void btnProductsClicked();
	void btnAccountingClicked();
	void btnReportsClicked();
	void innerNavClicked();
};

#endif // MAINWINDOW_H
