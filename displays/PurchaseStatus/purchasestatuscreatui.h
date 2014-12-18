/**************************************************************************
**   File: purchasestatuscreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESTATUSUI_H
#define PURCHASESTATUSUI_H
#include "../../erpdisplay.h"
#include "purchasestatusui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchasestatus.h"
#include "../../Model/erpmodel.h"
#include "../../Model/purchasestatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class PurchaseStatusCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseStatusCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseStatusCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(PurchaseStatus* purchasestatus);
PurchaseStatus* purchasestatus;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectPurchaseStatus();
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
