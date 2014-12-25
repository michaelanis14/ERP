/**************************************************************************
**   File: returndeliveryorderfreelineindexui.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNDELIVERYORDERFREELINEINDEXUI_H
#define RETURNDELIVERYORDERFREELINEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/returndeliveryorderfreeline.h"
#include "../../Model/returndeliveryorder.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ReturnDeliveryOrderFreelineIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnDeliveryOrderFreelineIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnDeliveryOrderFreelineIndexUI* GetUI();
ERPTableView *tabel; 
 ReturnDeliveryOrderFreeline *model; 
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
