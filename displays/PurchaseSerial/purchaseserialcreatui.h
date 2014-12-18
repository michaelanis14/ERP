/**************************************************************************
**   File: purchaseserialcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESERIALUI_H
#define PURCHASESERIALUI_H
#include "../../erpdisplay.h"
#include "purchaseserialui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchaseserial.h"
#include "../../Model/erpmodel.h"
#include "../../Model/purchaseserial.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class PurchaseSerialCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseSerialCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseSerialCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*title;
	QLineEdit*serial;
	void fill(PurchaseSerial* purchaseserial);
PurchaseSerial* purchaseserial;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectPurchaseSerial();
	void cancel();
	void clear();
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
