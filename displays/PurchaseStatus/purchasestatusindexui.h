/**************************************************************************
**   File: purchasestatusindexui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASESTATUSINDEXUI_H
#define PURCHASESTATUSINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/purchasestatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class PurchaseStatusIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseStatusIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseStatusIndexUI* GetUI();
QTableView *tabel; 
 PurchaseStatus *model; 
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
