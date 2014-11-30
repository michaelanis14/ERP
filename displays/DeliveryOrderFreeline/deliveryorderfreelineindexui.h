/**************************************************************************
**   File: deliveryorderfreelineindexui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERFREELINEINDEXUI_H
#define DELIVERYORDERFREELINEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/deliveryorderfreeline.h"
#include "../../Model/deliveryorder.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class DeliveryOrderFreelineIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderFreelineIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderFreelineIndexUI* GetUI();
QTableView *tabel; 
 DeliveryOrderFreeline *model; 
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
