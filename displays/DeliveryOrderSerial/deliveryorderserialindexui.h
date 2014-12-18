/**************************************************************************
**   File: deliveryorderserialindexui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERSERIALINDEXUI_H
#define DELIVERYORDERSERIALINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/deliveryorderserial.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class DeliveryOrderSerialIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderSerialIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderSerialIndexUI* GetUI();
ERPTableView *tabel; 
 DeliveryOrderSerial *model; 
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
