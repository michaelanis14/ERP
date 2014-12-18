/**************************************************************************
**   File: purchasefreelinecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASEFREELINEUI_H
#define PURCHASEFREELINEUI_H
#include "../../erpdisplay.h"
#include "purchasefreelineui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/purchasefreeline.h"
#include "../../Model/erpmodel.h"
#include "../../Model/purchasefreeline.h"
#include "../../Model/purchase.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class PurchaseFreeLineCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseFreeLineCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseFreeLineCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*purchase;
	QLineEdit*description;
	ERPComboBox*contact;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(PurchaseFreeLine* purchasefreeline);
PurchaseFreeLine* purchasefreeline;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectPurchaseFreeLine();
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
