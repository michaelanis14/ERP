/**************************************************************************
**   File: deliveryorderserviceindexui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSERVICEINDEXUI_H
#define DELIVERYORDERSERVICEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/deliveryorderservice.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class DeliveryOrderServiceIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderServiceIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderServiceIndexUI* GetUI();
ERPTableView *tabel; 
 DeliveryOrderService *model; 
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
