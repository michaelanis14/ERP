/**************************************************************************
**   File: deliveryorderindexui.h
**   Created on: Sun Dec 14 22:39:13 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERINDEXUI_H
#define DELIVERYORDERINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/deliveryorderstatus.h"
#include "../../Model/contact.h"

#include "../DeliveryOrderStoreProduct/deliveryorderstoreproductui.h"
#include "../DeliveryOrderService/deliveryorderserviceui.h"
#include "../DeliveryOrderFreeline/deliveryorderfreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class DeliveryOrderIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderIndexUI* GetUI();
ERPTableView *tabel; 
 DeliveryOrder *model; 
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
