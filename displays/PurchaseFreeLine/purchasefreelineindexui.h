/**************************************************************************
**   File: purchasefreelineindexui.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PURCHASEFREELINEINDEXUI_H
#define PURCHASEFREELINEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/purchasefreeline.h"
#include "../../Model/purchase.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class PurchaseFreeLineIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit PurchaseFreeLineIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static PurchaseFreeLineIndexUI* GetUI();
ERPTableView *tabel; 
 PurchaseFreeLine *model; 
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
