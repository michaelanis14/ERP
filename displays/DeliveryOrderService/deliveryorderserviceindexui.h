/**************************************************************************
**   File: deliveryorderserviceindexui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSERVICEINDEXUI_H
#define DELIVERYORDERSERVICEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/deliveryorderservice.h"
#include "../../Model/deliveryorder.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
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
QTableView *tabel; 
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
