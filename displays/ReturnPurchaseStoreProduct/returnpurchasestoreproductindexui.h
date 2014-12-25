/**************************************************************************
**   File: returnpurchasestoreproductindexui.h
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNPURCHASESTOREPRODUCTINDEXUI_H
#define RETURNPURCHASESTOREPRODUCTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/returnpurchasestoreproduct.h"
#include "../../Model/store.h"
#include "../../Model/returnpurchase.h"
#include "../../Model/contact.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ReturnPurchaseStoreProductIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnPurchaseStoreProductIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnPurchaseStoreProductIndexUI* GetUI();
ERPTableView *tabel; 
 ReturnPurchaseStoreProduct *model; 
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
