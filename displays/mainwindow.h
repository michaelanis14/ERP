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
	class QToolButton* btnProjects;
	class QToolButton* btnProducts;
	class QToolButton* btnAccounting;
	class QToolButton* btnInvoices;
//Home
		class QPushButton* inNavAccess;
		class QPushButton* inNavLogin;

//Contacts
	class QPushButton* inNavContacts;
	class QPushButton* inNavcontactPersones;
	class QPushButton* inNavTask;

//Project
		class QPushButton* inNavProjects;
		class QPushButton* inNavTimeBookings;
		class QPushButton* inNavServices;
//Products
	class QPushButton* inNavProducts;
	class QPushButton* inNavStoreHouse;
	class QPushButton* inNavPurchase;
	class QPushButton* inNavReturnPurchase;
	class QPushButton* inNavDeliveryOrder;
	class QPushButton* inNavReturnDeliveryOrder;
	class QPushButton* inNavStoreStatus;

//Invoices
		class QPushButton* inNavInvoices;
		class QPushButton* inNavPayments;
//Accounting
		class QPushButton* inNavCustomer;
		class QPushButton* inNavSupplier;
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
	void btnProjectsClicked();
	void btnProductsClicked();
	void btnAccountingClicked();
	void btnInvoicesClicked();
	void innerNavClicked();
};

#endif // MAINWINDOW_H
