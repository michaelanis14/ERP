/**************************************************************************
**   File: returndeliveryorderstoreproductindexui.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNDELIVERYORDERSTOREPRODUCTINDEXUI_H
#define RETURNDELIVERYORDERSTOREPRODUCTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/returndeliveryorderstoreproduct.h"
#include "../../Model/returndeliveryorder.h"
#include "../../Model/store.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ReturnDeliveryOrderStoreProductIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnDeliveryOrderStoreProductIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnDeliveryOrderStoreProductIndexUI* GetUI();
ERPTableView *tabel; 
 ReturnDeliveryOrderStoreProduct *model; 
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
