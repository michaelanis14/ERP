/**************************************************************************
**   File: serviceui.h
**   Created on: Sat Dec 13 13:51:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef SERVICEUI_H
#define SERVICEUI_H
#include "../../erpdisplay.h"
#include "serviceindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../CommonUI/barcode.h"
#include "../../Model/service.h"
#include "../../Model/service.h"
#include "../../Model/tax.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ServiceUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ServiceUI(QWidget *parent = 0);
	static void ShowUI();
	static ServiceUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	QLineEdit*shortdescription;
	QLineEdit*sellingprice;
	QLineEdit*netcoast;
	QLineEdit*trademarginrate;
	ERPComboBox*tax;
	QLineEdit*barcode;
	Barcode* barcodeDisplay;
	QPushButton* generatebarcode;
	void fill(Service* service);
Service* service;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectService();
	void cancel();
	void clear();
	void generateBarcode();
	void barcodeChanged(QString barcode);
public slots:
	bool save();
	bool updateModel();
};
#endif
