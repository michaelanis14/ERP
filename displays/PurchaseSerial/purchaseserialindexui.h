/**************************************************************************
**   File: purchaseserialindexui.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESERIALINDEXUI_H
#define PURCHASESERIALINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/purchaseserial.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class PurchaseSerialIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseSerialIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseSerialIndexUI* GetUI();
ERPTableView *tabel; 
 PurchaseSerial *model; 
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
