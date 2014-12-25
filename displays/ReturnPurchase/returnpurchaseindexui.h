/**************************************************************************
**   File: returnpurchaseindexui.h
**   Created on: Thu Dec 18 23:40:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNPURCHASEINDEXUI_H
#define RETURNPURCHASEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/returnpurchase.h"
#include "../../Model/purchase.h"

#include "../ReturnPurchaseStoreProduct/returnpurchasestoreproductui.h"
#include "../ReturnPurchaseFreeLine/returnpurchasefreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ReturnPurchaseIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnPurchaseIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnPurchaseIndexUI* GetUI();
ERPTableView *tabel; 
 ReturnPurchase *model; 
 QPushButton* add; 
 QPushButton* remove; 
 QPushButton* edit;
private:
	static ERPDisplay* p_instance;
private slots:
	void addRow(); 
 void removeRow(); 
 void editRow(); 
 void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
