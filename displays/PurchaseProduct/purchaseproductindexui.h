/**************************************************************************
**   File: purchaseproductindexui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASEPRODUCTINDEXUI_H
#define PURCHASEPRODUCTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/purchaseproduct.h"
#include "../../Model/purchase.h"
#include "../../Model/contact.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class PurchaseProductIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseProductIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseProductIndexUI* GetUI();
QTableView *tabel; 
 PurchaseProduct *model; 
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
