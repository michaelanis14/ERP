/**************************************************************************
**   File: purchasestoreproductindexui.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESTOREPRODUCTINDEXUI_H
#define PURCHASESTOREPRODUCTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/purchasestoreproduct.h"
#include "../../Model/store.h"
#include "../../Model/purchase.h"
#include "../../Model/contact.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class PurchaseStoreProductIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseStoreProductIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseStoreProductIndexUI* GetUI();
ERPTableView *tabel; 
 PurchaseStoreProduct *model; 
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
