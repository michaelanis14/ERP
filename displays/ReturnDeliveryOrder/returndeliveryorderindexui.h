/**************************************************************************
**   File: returndeliveryorderindexui.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNDELIVERYORDERINDEXUI_H
#define RETURNDELIVERYORDERINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/returndeliveryorder.h"
#include "../../Model/deliveryorder.h"

#include "../ReturnDeliveryOrderStoreProduct/returndeliveryorderstoreproductui.h"
#include "../ReturnDeliveryOrderService/returndeliveryorderserviceui.h"
#include "../ReturnDeliveryOrderFreeline/returndeliveryorderfreelineui.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ReturnDeliveryOrderIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnDeliveryOrderIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnDeliveryOrderIndexUI* GetUI();
ERPTableView *tabel; 
 ReturnDeliveryOrder *model; 
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
