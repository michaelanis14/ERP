/**************************************************************************
**   File: returnpurchasefreelineindexui.h
**   Created on: Thu Dec 18 22:52:27 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNPURCHASEFREELINEINDEXUI_H
#define RETURNPURCHASEFREELINEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/returnpurchasefreeline.h"
#include "../../Model/returnpurchase.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ReturnPurchaseFreeLineIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnPurchaseFreeLineIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnPurchaseFreeLineIndexUI* GetUI();
ERPTableView *tabel; 
 ReturnPurchaseFreeLine *model; 
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
