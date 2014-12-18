/**************************************************************************
**   File: deliveryorderstoreproductindexui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSTOREPRODUCTINDEXUI_H
#define DELIVERYORDERSTOREPRODUCTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/deliveryorderstoreproduct.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/store.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class DeliveryOrderStoreProductIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderStoreProductIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderStoreProductIndexUI* GetUI();
ERPTableView *tabel; 
 DeliveryOrderStoreProduct *model; 
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
