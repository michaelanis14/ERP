/**************************************************************************
**   File: servicecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef SERVICEUI_H
#define SERVICEUI_H
#include "../../erpdisplay.h"
#include "serviceui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../CommonUI/barcode.h"
#include "../../Model/service.h"
#include "../../Model/erpmodel.h"
#include "../../Model/service.h"
#include "../../Model/tax.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ServiceCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ServiceCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ServiceCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
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
	void refreshTabel();
private slots:
	void selectService();
	void cancel();
	void clear();
	void removeRow();
	void generateBarcode();
	void barcodeChanged(QString barcode);
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
